#include "uart.h"

// UART0 DATA REGISTER 
#define UART0DR   *((volatile unsigned int *)((unsigned int *)0x101f1000))

void Uart_Send_String( unsigned char  *P_string)
{
	while(*P_string != '\0')
	{
		UART0DR = (unsigned int)(*P_string); // convert char to int data
		P_string++; // move to next char 
	}
}