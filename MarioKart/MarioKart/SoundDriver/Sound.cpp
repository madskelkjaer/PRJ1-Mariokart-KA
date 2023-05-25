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
	uart_driver_ = uart;
	//Set SD Card as source
	uart_driver_.SendChar(0x7E);
	uart_driver_.SendChar(0x09);
	uart_driver_.SendChar(0x00);
	uart_driver_.SendChar(0x00);
	uart_driver_.SendChar(0x02);
	uart_driver_.SendChar(0xFF);
	uart_driver_.SendChar(0xF5);
	uart_driver_.SendChar(0xEF);
	
	//SET VOLUME 30
	uart_driver_.SendChar(0x7E);
	uart_driver_.SendChar(0x06);
	uart_driver_.SendChar(0x00);
	uart_driver_.SendChar(0x00);
	uart_driver_.SendChar(0x1E);
	uart_driver_.SendChar(0xFF);
	uart_driver_.SendChar(0xDC);
	uart_driver_.SendChar(0xEF);
} //Sound

// default destructor
Sound::~Sound()
{
} //~Sound

void Sound::playSound(int sound)
{
	if (sound == 1) {
		//PLAY START SOUND
		uart_driver_.SendChar(0x7E);
		uart_driver_.SendChar(0x0F);
		uart_driver_.SendChar(0x00);
		uart_driver_.SendChar(0x01);
		uart_driver_.SendChar(0x01);
		uart_driver_.SendChar(0xFF);
		uart_driver_.SendChar(0xEF);
		uart_driver_.SendChar(0xEF);
	}
	if (sound == 2) {
		//PLAY REFLEKSBRIK SOUND
		uart_driver_.SendChar(0x7E);
		uart_driver_.SendChar(0x0F);
		uart_driver_.SendChar(0x00);
		uart_driver_.SendChar(0x01);
		uart_driver_.SendChar(0x02);
		uart_driver_.SendChar(0xFF);
		uart_driver_.SendChar(0xEE);
		uart_driver_.SendChar(0xEF);
	}
	if (sound == 3) {
		//PLAY STOP SOUND
		uart_driver_.SendChar(0x7E);
		uart_driver_.SendChar(0x0F);
		uart_driver_.SendChar(0x00);
		uart_driver_.SendChar(0x01);
		uart_driver_.SendChar(0x03);
		uart_driver_.SendChar(0xFF);
		uart_driver_.SendChar(0xED);
		uart_driver_.SendChar(0xEF);
	}
}

