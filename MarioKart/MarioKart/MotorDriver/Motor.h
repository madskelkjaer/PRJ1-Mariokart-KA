/* 
* Motor.h
*
* Created: 25-05-2023 10:43:11
* Author: madse
*/


#ifndef __MOTOR_H__
#define __MOTOR_H__


class Motor
{
public:
	Motor();
	void driveForward(int speed);
	void driveBackwards(int speed);
	void driveStop();
	void adjustSpeed(int toSpeed, int delayMS);
private:
	int currentSpeed_;
}; //Motor

#endif //__MOTOR_H__
