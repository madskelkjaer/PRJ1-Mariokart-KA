/* 
* UART.h
*
* Created: 25-05-2023 11:30:44
* Author: madse
*/


#ifndef __UART_H__
#define __UART_H__


class UART
{
public:
	UART();
	unsigned char CharReady();
	char ReadChar();
	void SendChar(char Tegn);
	void SendString(char* Streng);
	void SendInteger(int Tal);
protected:
private:
}; //UART

#endif //__UART_H__
