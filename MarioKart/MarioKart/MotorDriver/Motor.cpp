/*
* Motor.cpp
*
* Created: 25-05-2023 10:43:11
* Author: madse
*/
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

#include "Motor.h"

#define MOTOR_PWM OCR0A
#define MOTOR_DIRECTION OCR0B
#define MOTOR_TIMER_A TCCR0A
#define MOTOT_TIMER_B TCCR0B

void delay_ms(int duration_ms) {
	for (int i = 0; i < duration_ms; i++) {
		_delay_ms(1);
	}
}

// default constructor
Motor::Motor()
{
	// mode 3
	// 120 Hz (cirka)
	// 10 bit
	// 65 -> 64 prescaler (beregnet i cheatsheet)
	// på port b
	TCCR4A = 0b00100011; // tabel 17-4, clear OCnA on compare match.
	TCCR4B = 0b00000011; // 64 prescaling
	
	// PWM på PH4
	DDRH |= (1 << PH4);
	
	// Direction på PH3
	DDRH |= (1 << PH3);
	PORTH |= (1 << PH3);
	currentDirection_ = 1;
	currentSpeed_ = 0;
} //Motor

void Motor::driveForward(int speed, int delay)
{
	if (currentDirection_ == 0) {
		driveBackwards(0, delay);
	}
	
	PORTH &= (0 << PH3);
	currentDirection_ = 1;
	
	if (currentSpeed_ < speed) {
		for (int i = currentSpeed_; i < speed; i++)
		{
			OCR4B = i * 10;
			delay_ms(delay);
		}	
	} else {
		for (int i = currentSpeed_; i > speed; i--)
		{
			OCR4B = i * 10;
			delay_ms(delay);
		}
	}
	
	currentSpeed_ = speed;
}

void Motor::driveBackwards(int speed, int delay)
{
	if (currentDirection_ == 1) {
		driveForward(0, delay);
	}
	
	PORTH |= (1 << PH3);
	currentDirection_ = 0;
	
	if (currentSpeed_ < speed) {
		for (int i = currentSpeed_; i < speed; i++)
		{
			OCR4B = i * 10;
			delay_ms(delay);
		}
		} else {
		for (int i = currentSpeed_; i > speed; i--)
		{
			OCR4B = i * 10;
			delay_ms(delay);
		}
	}
	
	currentSpeed_ = speed;
}

void Motor::driveStop(int delay)
{
	if (currentDirection_ == 0) {
		driveBackwards(0, delay);
	} else {
		driveForward(0, delay);
	}
}