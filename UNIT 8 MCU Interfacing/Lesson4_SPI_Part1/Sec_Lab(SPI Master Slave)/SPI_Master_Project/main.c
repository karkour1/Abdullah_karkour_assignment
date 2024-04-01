/*
 * main.c
 *
 *  Created on: Apr 1, 2024
 *  Author: Abdullah Karkour
 */

#include <util/delay.h>
/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL*/
#include "DIO_interface.h"
#include"SPI_interface.h"

int main(void)
{
	uint8_t ch ;
	// Set PortA Output
	DIO_SetPortDirection(DIO_PORTA, DIO_Port_OUTPUT);

	// initiate master
	MCAL_SPI_init(master);

	while(1)
	{
		for (ch = 0; ch <= 9; ch++)
		{
			_delay_ms(1000);
			MCAL_SPI_Transmit(&ch, master);
			if(ch == 9) ch = 0 ;

		}
	}
}
