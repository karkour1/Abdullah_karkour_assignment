/*
 * MAX7221_programme.c
 *
 *  Created on: Apr 1, 2024
 *  Author: ABDULLAH KARKOUR
 */

/****************************************
 * Includes
 ****************************************/
#include"MAX7221_interface.h"

/****************************************
 * APIS Supported By MAX7221_interface.h
 ****************************************/

void HAL_MAX7221_init(MAX7221_Confg_t* device)
{
	/* Define the SPI as master */
	MCAL_SPI_init(master);

	/* intiate the normal mode*/
	HAL_MAX7221_Excute(MAX7221_Shutdown_Register, 0x01);

	/* Intensity level */
	HAL_MAX7221_Excute(MAX7221_Intensity_Register, device->Intensity);

	/* Decode Mode */
	HAL_MAX7221_Excute(MAX7221_Decode_Mode_Register, device->Decode_Mode);

	/* Scan Limit */
	HAL_MAX7221_Excute(MAX7221_Scan_Limit_Register, device->Scan_Limit);

}
void HAL_MAX7221_Excute(uint8_t cmd , uint8_t data)
{
	/* Set SS low */
	DIO_SetPinValue(DIO_PORTB, SS, DIO_PIN_LOW);

	/* transmit the command*/
	MCAL_SPI_Transmit(&cmd, master);

	/* transmit the Data */
	MCAL_SPI_Transmit(&data, master);

	/* Set SS High */
	DIO_SetPinValue(DIO_PORTB, SS, DIO_PIN_HIGH);
}
