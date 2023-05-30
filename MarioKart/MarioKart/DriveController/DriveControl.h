/* 
* DriveControl.h
*
* Created: 25-05-2023 10:42:55
* Author: madse
*/


#ifndef __DRIVECONTROL_H__
#define __DRIVECONTROL_H__

// ## LightDrivers ##
#include "..\LightDriver\FrontLight.h"
#include "..\LightDriver\BackLight.h"

// ## SoundDriver ##
#include "..\SoundDriver/Sound.h"

// ## MotorDriver ""
#include "..\MotorDriver\Motor.h"

class DriveControl
{
//variables
public:
	DriveControl();
	void reflexController(int reflexCount);
	void startDriveControl();

private:
	Sound sound_;
	FrontLight frontLight_;
	BackLight backLight_;
	Motor motor_;
	int reflexCount_;
}; //DriveControl

#endif //__DRIVECONTROL_H__
