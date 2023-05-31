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

// Definerer konstanter til startknappen (Knap 7)
#define INIT_BUTTON_DDR DDRA
#define INIT_BUTTON_PIN PINA
#define INIT_BUTTON_MASK 0b10000000

// Definerer konstanter til reflekssensore
#define REFLEKS_ENABLE_MASK 0b00001100
#define REFLEKS_TRIGGER_MASK 0b11110000
#define REFLEKS1 INT2_vect
#define REFLEKS2 INT3_vect
#define REFLEKS_TIMEOUT 400

// Prototyper. skal de i en seperat header fil?
void ledfun();
void awaitStartButton();
void startReflexSensors();
void stopReflexSensors();
void reflex();

// Refleks tæller. Global variabel.
volatile unsigned int reflexCount = 0;

ISR(REFLEKS1) { // Com pin 21
	// Reflekssensor 1
	reflex();
}

ISR(REFLEKS2) {
	// Reflekssensor 2
	reflex();
}


DriveControl controller;



int main(void)
{
	DDRB = 0xFF;
	PORTB = 0;
	
	awaitStartButton();
	
	EIMSK = EIMSK | 0b00000100;
	EICRA |= 0b00110000;
	sei();
	
	controller.startDriveControl();
	while(true) {};
}

void reflex() {
	//Interrupt fra refleks
	stopReflexSensors();
	
	reflexCount++;
	controller.reflexController(reflexCount);
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


void awaitStartButton()
{
	INIT_BUTTON_DDR = 0x00;
	while((~INIT_BUTTON_PIN & INIT_BUTTON_MASK) == 0) {}
	ledfun();
}

void ledfun() {
	int led = 1;

	for (int i = 1; i < 100; i++)
	{
		PORTB = led;
		
		led = led << 1;

		if (led > 128) {
			led = 1;
		}

		_delay_ms(20);
	}

	PORTB = 0;
}


