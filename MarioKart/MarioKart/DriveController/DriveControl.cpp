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
	
	Motor motor;
	motor_ = motor;
} //DriveControl

void DriveControl::reflexController(int reflexCount)
{
	reflexCount_ = reflexCount;
	if (reflexCount_ >= 1 && 10 >= reflexCount_) {
		sound_.playSound(2);
	}
}

void DriveControl::startDriveControl()
{
	// Afspil startlyd
	sound_.playSound(1);
	// Begynd k�rsel fremad i kontrolleret tempo
	_delay_ms(2500);
	
	motor_.driveForward(100);
	
	
	
	
	// Hvis reflekscount er 2
	// Vi k�rer op af bakken. S� det skal g� lidt langsommere
	// S�t antalreflekser +1
	// afspil reflekslyd
	// S�t en timeout p� n�ste refleks detektering
	
	// Hvis reflekscount er 3, er vi p� toppen af bakken
	// Samme
	
	// Hvis rc er 4, s� er vi forbi bakken.
	// Samme
	
	// Ved rc 5 k�rer vi videre
	// Samme
	
	// ved rc 6 bremser vi og p�begynder bak
	// Samme
	
	// ved rc 7 bakker vi forbi (6).
	// Samme
	
	// Rc 8 skal vi bremse og k�re fremad igen.
	// Samme
	
	// rc 9 k�rer vi forbi igen.
	// Samme
	
	// rc 10 k�rer vi forbi
	// Samme
	
	// rc 11 er vi forbi m�lstregen, og vi bremser.
	
	// afspil slutlyd	
}
