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


#define INIT_BUTTON_PORT PORTA
#define INIT_BUTTON_PIN PINA



volatile unsigned int reflexCount = 0;
bool reflexTimeout = false;

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
	DriveControl controller;
		
	controller.startDriveControl();
}

