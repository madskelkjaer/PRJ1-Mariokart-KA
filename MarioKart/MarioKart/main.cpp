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

#define INIT_BUTTON_DDR DDRA
#define INIT_BUTTON_PIN PINA



volatile unsigned int reflexCount = 0;
volatile bool reflexTimeout = false;

void reflex() {
	//Interrupt fra refleks
	if (reflexTimeout) {
		return;
	}
	
	reflexTimeout = true;
	reflexCount++;
	_delay_ms(100);
	reflexTimeout = false;
}

ISR(INT0_vect) { // Com pin 21
	// Reflekssensor 1
	reflex();
}

ISR(INT1_vect) { // com pin 20
	// Reflekssensor 2
	reflex();
}

int main(void)
{
	INIT_BUTTON_DDR = 0xFF;
	
	while ((INIT_BUTTON_PIN & 0b10000000) != 0) {}
	
	sei();

	DriveControl controller;
	controller.startDriveControl();
}

