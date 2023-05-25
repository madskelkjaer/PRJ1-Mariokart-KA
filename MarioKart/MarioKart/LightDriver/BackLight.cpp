/* 
* BackLight.cpp
*
* Created: 25-05-2023 10:41:49
* Author: madse
*/

#include <avr/io.h>
#include "BackLight.h"

// default constructor
BackLight::BackLight()
{
	// Mode = 3 (PWM, Phase Correct, 10 bit)
	// Set OC1A on match down counting / Clear OC1A on match up counting
	// Set OC1B on match down counting / Clear OCBA on match up counting
	// Clock prescaler = 1
	TCCR1A = 0b10100011;
	TCCR1B = 0b00000001;
		
	//Configure PORTB as output
	//Clear PORTB
	DDRB=0xFF;
	PORTB=0x00;
} //BackLight

// default destructor
BackLight::~BackLight()
{
} //~BackLight

void BackLight::backLightDrive()
{
	//Giver en middelstrøm på 10mA - beregning kommer senere
	OCR1B = (1023*8)/100;
}

void BackLight::backLightBrake()
{
	//Duty cycle at 50% - beregning kommer senere = middelstrøm på 51mA
	OCR1B = 540;
}

void BackLight::backLightOff()
{
	//Duty cycle at 0% = 0mA = LightsOff
	OCR1B = 0;
}
