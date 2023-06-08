/* 
* Sound.cpp
*
* Created: 25-05-2023 10:42:37
* Author: madse
*/
#include "Sound.h"
#include "UART.h"

// default constructor
Sound::Sound()
{
	UART uart;
	uartDriver_ = uart;
	//Set SD Card as source
	uartDriver_.SendChar(0x7E);
	uartDriver_.SendChar(0x09);
	uartDriver_.SendChar(0x00);
	uartDriver_.SendChar(0x00);
	uartDriver_.SendChar(0x02);
	uartDriver_.SendChar(0xFF);
	uartDriver_.SendChar(0xF5);
	uartDriver_.SendChar(0xEF);
	
	//SET VOLUME 30
	uartDriver_.SendChar(0x7E);
	uartDriver_.SendChar(0x06);
	uartDriver_.SendChar(0x00);
	uartDriver_.SendChar(0x00);
	uartDriver_.SendChar(0x1E);
	uartDriver_.SendChar(0xFF);
	uartDriver_.SendChar(0xDC);
	uartDriver_.SendChar(0xEF);
} //Sound

void Sound::playSound(int sound)
{
	if (sound == 1) {
		//PLAY START SOUND
		uartDriver_.SendChar(0x7E);
		uartDriver_.SendChar(0x0F);
		uartDriver_.SendChar(0x00);
		uartDriver_.SendChar(0x01);
		uartDriver_.SendChar(0x01);
		uartDriver_.SendChar(0xFF);
		uartDriver_.SendChar(0xEF);
		uartDriver_.SendChar(0xEF);
	}
	if (sound == 2) {
		//PLAY REFLEKSBRIK SOUND
		uartDriver_.SendChar(0x7E);
		uartDriver_.SendChar(0x0F);
		uartDriver_.SendChar(0x00);
		uartDriver_.SendChar(0x01);
		uartDriver_.SendChar(0x02);
		uartDriver_.SendChar(0xFF);
		uartDriver_.SendChar(0xEE);
		uartDriver_.SendChar(0xEF);
	}
	if (sound == 3) {
		//PLAY STOP SOUND
		uartDriver_.SendChar(0x7E);
		uartDriver_.SendChar(0x0F);
		uartDriver_.SendChar(0x00);
		uartDriver_.SendChar(0x01);
		uartDriver_.SendChar(0x03);
		uartDriver_.SendChar(0xFF);
		uartDriver_.SendChar(0xED);
		uartDriver_.SendChar(0xEF);
	}
}

