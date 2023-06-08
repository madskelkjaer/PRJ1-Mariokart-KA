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
} //Motor

void Motor::driveForward(int speed)
{
	OCR4B = speed * 10;
	PORTH &= (0 << PH3);
}

void Motor::driveBackwards(int speed)
{
	OCR4B = speed * 10;
	PORTH |= (1 << PH3);
	
}

void Motor::driveStop()
{
	OCR4B = 0 * 10;
}
