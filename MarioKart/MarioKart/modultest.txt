#define F_CPU 16000000

#include <avr/io.h>
#include <util/delay.h>

#include "MotorDriver/Motor.h"

void TestMotor() {
	Motor motortest;
	while(true) {
		motortest.driveForward(100);
		
		_delay_ms(1000);
		
		motortest.driveBackwards(20);
		
		_delay_ms(1000);
		
		// motortest.driveStop();
		
		_delay_ms(1000);
	}
}


#include "SoundDriver/Sound.h"

void TestSound() {
	Sound soundtest;
	const int delay = 3000;
	
	while(true) {
		soundtest.playSound(1);
	
		_delay_ms(delay);
	
		soundtest.playSound(2);
	
		_delay_ms(delay);
	
		soundtest.playSound(3);
	
		_delay_ms(delay);	
	}
}

#include "LightDriver/FrontLight.h"
#include "LightDriver/BackLight.h"

void TestLight() {
	FrontLight frontlighttest;
	BackLight backlighttest;
	
	const int delay = 2000;
	
	while (true)
	{
			frontlighttest.frontLightOn();
			backlighttest.backLightDrive();
			
			_delay_ms(delay);
			
			backlighttest.backLightBrake();
			
			_delay_ms(delay);
			
			frontlighttest.frontLightOff();
			backlighttest.backLightOff();
			
			_delay_ms(delay);
	}
}