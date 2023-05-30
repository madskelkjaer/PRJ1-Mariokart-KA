/* 
* Motor.cpp
*
* Created: 25-05-2023 10:43:11
* Author: madse
*/
#define F_CPU 16000000
#include <util/delay.h>

#include "Motor.h"

// default constructor
Motor::Motor()
{
} //Motor

void Motor::driveForward(int speed)
{
	currentSpeed_ = speed;

}

void Motor::driveBackwards(int speed)
{
	currentSpeed_ = speed;
}

void Motor::driveStop()
{
	currentSpeed_ = 0;
}


void Motor::adjustSpeed(int toSpeed, int delayMS) {
	if (currentSpeed_ > toSpeed) {
		for (int speed = currentSpeed_; speed > toSpeed; speed--)
		{
		}
		} else {
		for (int speed = currentSpeed_; speed < toSpeed; speed++)
		{
		}
	}
	
	currentSpeed_ = toSpeed;
	
}