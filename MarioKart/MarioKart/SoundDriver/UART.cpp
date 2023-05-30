/* 
* UART.cpp
*
* Created: 25-05-2023 11:30:44
* Author: madse
*/

#include <avr/io.h>
#include <stdlib.h>
#include "UART.h"


/*************************************************************************
UART 1 initialization:
Asynchronous mode.
RX and TX enabled.
No interrupts enabled.
Number of Stop Bits = 1.
No Parity.
Baud rate = 9600.
Data bits = 8.
*************************************************************************/

// default constructor
UART::UART()
{
	UBRR2 = 104;
	UCSR2B = 0b00011000;
	UCSR2C = 0b00000110;

} //UART

// default destructor
UART::~UART()
{
} //~UART

/*************************************************************************
Returns 0 (FALSE), if the UART has NOT received a new character.
Returns value <> 0 (TRUE), if the UART HAS received a new character.
*************************************************************************/

unsigned char UART::CharReady()
{
	return (UCSR2A & 0b10000000);
}

/*************************************************************************
Awaits new character received.
Then this character is returned.
*************************************************************************/

char UART::ReadChar()
{
	while (!CharReady()) {}
	char Text = UDR2;
	return Text;

}

/*************************************************************************
Awaits transmitter register ready.
Then send the character.
Parameter :
Tegn : Character for sending.
*************************************************************************/
void UART::SendChar(char Tegn)
{
	while ((UCSR2A & 0b00100000) == 0) {}
	UDR2 = Tegn;

}

/*************************************************************************
Sends 0 terminated string.
Parameter:
Streng: Pointer to the string.
*************************************************************************/

void UART::SendString(char* Streng)
{
	while (*Streng != 0) {
		SendChar(*Streng);
		Streng++;
	}
}

/*************************************************************************
Converts the integer "Tal" to an ASCII string - and then sends this string
using the USART.
Makes use of the C standard library <stdlib.h>.
Parameter:
Tal: The integer to be converted and sent.
*************************************************************************/
void UART::SendInteger(int Tal)
{
	char String[6];
	itoa(Tal, String, 10);
	SendString(String);
}
