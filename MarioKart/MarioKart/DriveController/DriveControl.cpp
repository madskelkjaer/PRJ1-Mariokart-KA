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
			motor_.driveForward(80, 10);
		case 2: // refleks 2
			motor_.driveForward(80, 10);
			break;
		case 3: // osv.
			motor_.driveForward(80, 10);
			break;
		case 4:
			motor_.driveForward(80, 10);
			break;
		case 5:
			motor_.driveForward(80, 10);
			break;	
		case 6:
			motor_.driveStop(8);
			motor_.driveBackwards(80, 10);
			break;
		case 7:
			motor_.driveForward(80, 10);
			break;
		case 8:
			motor_.driveStop(8);
			motor_.driveForward(100, 20);
			break;
		case 9:
			motor_.driveForward(80, 10);
			break;
		case 10:
			motor_.driveForward(80, 10);
			break;
		case 11:
			motor_.driveStop(8);
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
	motor_.driveForward(80, 10);
}
