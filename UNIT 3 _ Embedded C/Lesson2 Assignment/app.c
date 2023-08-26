#include "uart.h"

// store data to be sent
unsigned char string_buffer[100] = "learn-in-depth:<Abdullah karkour>" ;

void main (void)
{
	Uart_Send_String(string_buffer); // call Function to send data 
}

