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
	// Vent på at bruger initialiserer kørsel med knap.
	// Derefter kan vi lave noget sejt med lysene i nogle sekunder, ellers kører bilen jo ind i ens hånd når man trykker på knappen.
	
	
	// Afspil startlyd
	sound_.playSound(1);
	// Begynd kørsel fremad i kontrolleret tempo
	
	_delay_ms(2000);
	
	sound_.playSound(2);
	// Begynd kørsel fremad i kontrolleret tempo
	
	_delay_ms(2000);
	
	sound_.playSound(3);
	// motor_.driveForward(100);
	
	
	
	// Afvent interrupt fra refleks detektor
	// Sæt antalreflekser +1
	// afspil reflekslyd
	// Sæt en timeout på næste refleks detektering
	
	// Hvis reflekscount er 2
	// Vi kører op af bakken. Så det skal gå lidt langsommere
	// Sæt antalreflekser +1
	// afspil reflekslyd
	// Sæt en timeout på næste refleks detektering
	
	// Hvis reflekscount er 3, er vi på toppen af bakken
	// Samme
	
	// Hvis rc er 4, så er vi forbi bakken.
	// Samme
	
	// Ved rc 5 kører vi videre
	// Samme
	
	// ved rc 6 bremser vi og påbegynder bak
	// Samme
	
	// ved rc 7 bakker vi forbi (6).
	// Samme
	
	// Rc 8 skal vi bremse og køre fremad igen.
	// Samme
	
	// rc 9 kører vi forbi igen.
	// Samme
	
	// rc 10 kører vi forbi
	// Samme
	
	// rc 11 er vi forbi målstregen, og vi bremser.
	
	// afspil slutlyd	
}
