/*
 * MarioKart.cpp
 *
 * Created: 25-05-2023 10:34:41
 * Author : madse
 */ 

#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "DriveController\DriveControl.h"

#include "SoundDriver/Sound.h"


#define INIT_BUTTON_DDR DDRA
#define INIT_BUTTON_PIN PINA
#define INIT_BUTTON_MASK 0b10000000

#define REFLEKS_ENABLE_MASK 0b00001100
#define REFLEKS_TRIGGER_MASK 0b11110000
#define REFLEKS1 INT2_vect
#define REFLEKS2 INT3_vect
#define REFLEKS_TIMEOUT 400

void awaitStartButton();
void startReflexSensors();
void stopReflexSensors();
void reflex();

volatile unsigned int reflexCount = 0;

void reflex() {
	//Interrupt fra refleks
	stopReflexSensors();
	
	reflexCount++;
	PORTB = reflexCount;
	_delay_ms(REFLEKS_TIMEOUT);
	
	startReflexSensors();
}

void startReflexSensors() {
	EIMSK |= REFLEKS_ENABLE_MASK;
	EICRA |= REFLEKS_TRIGGER_MASK;
}

void stopReflexSensors() {
	EIMSK &= ~REFLEKS_ENABLE_MASK;
	EICRA &= ~REFLEKS_TRIGGER_MASK;
}

ISR(REFLEKS1) { // Com pin 21
	// Reflekssensor 1
	reflex();
}

ISR(REFLEKS2) {
	// Reflekssensor 2
	reflex();
}

int main(void)
{
	DDRB = 0xFF;
	PORTB = 0;
	
	EIMSK = EIMSK | 0b00000100;
	EICRA |= 0b00110000;
	sei();
	// INIT_BUTTON_DDR = 0xFF;
	
	// while ((INIT_BUTTON_PIN & 0b10000000) != 0) {}
	
	

	DriveControl controller;
	controller.startDriveControl();
	while(true) {};
}

