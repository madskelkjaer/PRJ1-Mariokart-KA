/* 
* DriveControl.cpp
*
* Created: 25-05-2023 10:42:55
* Author: madse
*/

#include "DriveControl.h"

// ## LightDrivers ##
#include "..\LightDriver\FrontLight.h"
#include "..\LightDriver\BackLight.h"

// ## SoundDriver ##
#include "..\SoundDriver/Sound.h"

// default constructor
DriveControl::DriveControl()
{
	Sound sound;
	sound_ = sound;
	
	FrontLight frontLight;
	frontLight_ = frontLight;
	
	BackLight backLight;
	backLight_ = backLight;
} //DriveControl

// default destructor
DriveControl::~DriveControl()
{
} //~DriveControl

void DriveControl::startDriveControl()
{
	sound_.playSound(1);
}
