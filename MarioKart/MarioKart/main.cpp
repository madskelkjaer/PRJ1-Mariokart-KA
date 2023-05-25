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

volatile unsigned int reflexCount = 0;

void reflex() {
	//Interrupt fra refleks
	
	
	// Slukker interrupt i 1 sekund så vi ikke registrerer dobbelt.
	cli();
	_delay_ms(100);
	sei();
}

ISR(INT2_vect) {
	// Reflekssensor 1
	reflex();
}

ISR(INT3_vect) {
	// Reflekssensor 2
	reflex();
}

int main(void)
{
    /* Replace with your application code */
    while (1)
    {
		sei();
		DriveControl controller;
		
		controller.startDriveControl();
		while (1)
		{
		}
    }
}

