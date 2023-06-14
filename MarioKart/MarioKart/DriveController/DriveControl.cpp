/* 
* DriveControl.cpp
*
* Created: 25-05-2023 10:42:55
* Author: madse
*/
#define F_CPU 16000000
#include <util/delay.h>

#include "DriveControl.h"

// ## LightDrivers ##
#include "..\LightDriver\FrontLight.h"
#include "..\LightDriver\BackLight.h"

// ## SoundDriver ##
#include "..\SoundDriver\Sound.h"

// ## MotorDriver ##
#include "..\MotorDriver\Motor.h"

// default constructor
DriveControl::DriveControl()
{
	Sound sound;
	sound_ = sound;
	
	FrontLight frontLight;
	frontLight_ = frontLight;
	
	BackLight backLight;
	backLight_ = backLight;
	
	Motor motor;
	motor_ = motor;
} //DriveControl

void DriveControl::reflexController(int reflexCount)
{
	reflexCount_ = reflexCount;
	if (reflexCount_ >= 1 && 10 >= reflexCount_) {
		sound_.playSound(2);
	}
	
	if (reflexCount_ == 11) {
		sound_.playSound(3);
	}
	
	switch (reflexCount_)
	{
		case 1: // refleks 1
		case 2: // refleks 2
			motor_.driveForward(100, 8);
			break;
		case 3: // osv.
			motor_.driveForward(10, 8);
			break;
		case 4:
			motor_.driveForward(40, 10);
			break;
		case 5:
			break;	
		case 6:
			backLight_.backLightBrake();
			motor_.driveBackwards(40, 10);
			backLight_.backLightDrive();
			break;
		case 7:
			break;
		case 8:
			backLight_.backLightBrake();
			motor_.driveForward(55, 7);
			backLight_.backLightDrive();
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			backLight_.backLightBrake();
			motor_.driveStop(2);
			backLight_.backLightOff();
			frontLight_.frontLightOff();
			
			break;
	}
}

void DriveControl::startDriveControl()
{
	
	// Afspil startlyd
	sound_.playSound(1);
	// Begynd kørsel fremad i kontrolleret tempo
	_delay_ms(2500);
	
	frontLight_.frontLightOn();
	backLight_.backLightDrive();
	motor_.driveForward(70, 1);
}
