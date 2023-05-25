/* 
* Sound.h
*
* Created: 25-05-2023 10:42:37
* Author: madse
*/


#ifndef __SOUND_H__
#define __SOUND_H__

#include "UART.h"

class Sound
{
//variables
public:
protected:
private:
	UART uart_driver_;

//functions
public:
	Sound();
	~Sound();
	void playSound(int sound);
protected:
private:
}; //Sound

#endif //__SOUND_H__
