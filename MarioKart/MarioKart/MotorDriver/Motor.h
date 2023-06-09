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
	void driveForward(int speed, int delay);
	void driveBackwards(int speed, int delay);
	void driveStop(int delay);
private:
	int currentDirection_;
	int currentSpeed_;
}; //Motor

#endif //__MOTOR_H__
