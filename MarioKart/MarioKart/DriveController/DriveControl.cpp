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

void DriveControl::startDriveControl()
{
	// Vent p� at bruger initialiserer k�rsel med knap.
	// Derefter kan vi lave noget sejt med lysene i nogle sekunder, ellers k�rer bilen jo ind i ens h�nd n�r man trykker p� knappen.
	
	
	// Afspil startlyd
	sound_.playSound(1);
	// Begynd k�rsel fremad i kontrolleret tempo
	
	_delay_ms(2000);
	
	sound_.playSound(2);
	// Begynd k�rsel fremad i kontrolleret tempo
	
	_delay_ms(2000);
	
	sound_.playSound(3);
	// motor_.driveForward(100);
	
	
	
	// Afvent interrupt fra refleks detektor
	// S�t antalreflekser +1
	// afspil reflekslyd
	// S�t en timeout p� n�ste refleks detektering
	
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
