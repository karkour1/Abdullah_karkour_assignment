/*
 * SPI_Programme.c
 *
 *  Created on: Apr 1, 2024
 *  Author: Abdullah Karkour
 */

/****************************************
 * Includes
 ****************************************/
#include"SPI_interface.h"

/****************************************
 * APIS Supported By SPI_interface.h
 ****************************************/

void MCAL_SPI_init(SPI_mode_t device)
{
	if(device == master)
	{
		/* Set MOSI and SCK output and SS output, all others input */
		DIO_SetPinDirection(DIO_PORTB, MOSI, DIO_PIN_OUTPUT);
		DIO_SetPinDirection(DIO_PORTB, SCK , DIO_PIN_OUTPUT);
		DIO_SetPinDirection(DIO_PORTB, SS  , DIO_PIN_OUTPUT);
		DIO_SetPinDirection(DIO_PORTB, MISO, DIO_PIN_INPUT );

		/* Enable SPI, Master, set clock rate fck/16 */
		SPCR |= (1<<6)|(1<<4)|(1<<0);

	}
	else if (device == slave)
	{
		/* Set MOSI , SCK and SS input, MISO output */
		DIO_SetPinDirection(DIO_PORTB, MOSI, DIO_PIN_INPUT );
		DIO_SetPinDirection(DIO_PORTB, SCK , DIO_PIN_INPUT );
		DIO_SetPinDirection(DIO_PORTB, SS  , DIO_PIN_INPUT );
		DIO_SetPinDirection(DIO_PORTB, MISO, DIO_PIN_OUTPUT);

		/* Enable SPI */
		SPCR |= (1<<6);

	}
}
void MCAL_SPI_Transmit(uint8_t *data , SPI_mode_t device)
{
	if(device == master)
	{
		/* Start transmission */
		SPDR = *data;
		/* Wait for transmission complete */
		while(!(SPSR & (1<<7)));
	}
	else if (device == slave)
	{
		/* Wait for reception complete */
		while(!(SPSR & (1<<7)))
		;
		/* Return data register */
		*data = SPDR ;

	}
}
