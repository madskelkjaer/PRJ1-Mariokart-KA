/* 
* FrontLight.cpp
*
* Created: 25-05-2023 10:41:42
* Author: madse
*/

#include <avr/io.h>
#include "FrontLight.h"

// default constructor
FrontLight::FrontLight()
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
} //FrontLight

// default destructor
FrontLight::~FrontLight()
{
} //~FrontLight

void FrontLight::frontLightOn()
{
	//Dutycycle omkring 50% - beregning kommer senere = middelstrøm på 50mA
	OCR1A = 540;
}

void FrontLight::frontLightOff()
{
	//Duty cycle at 0% = 0mA = LightsOff
	OCR1A = 0;
}
