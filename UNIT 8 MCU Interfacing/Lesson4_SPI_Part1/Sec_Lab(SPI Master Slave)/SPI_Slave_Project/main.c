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

	// init master
	MCAL_SPI_init(slave);

	while(1)
	{
			MCAL_SPI_Transmit(&ch, slave);
			DIO_SetPortValue(DIO_PORTA, ch);
	}
}
