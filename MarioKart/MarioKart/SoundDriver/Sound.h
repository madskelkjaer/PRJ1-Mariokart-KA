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
public:
	Sound();
	void playSound(int sound);
protected:
private:
	UART uartDriver_;
}; //Sound

#endif //__SOUND_H__
