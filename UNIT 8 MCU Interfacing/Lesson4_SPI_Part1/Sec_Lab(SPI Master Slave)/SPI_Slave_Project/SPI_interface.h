/*
 * SPI_interface.h
 *
 *  Created on: Apr 1, 2024
 *  Author: Abdullah Karkour
 */

#ifndef INC_SPI_INTERFACE_H_
#define INC_SPI_INTERFACE_H_

/****************************************
 * Includes
 ****************************************/
#include <stdint.h>

/* UTILES_LIB */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ATMEGA32_REG.h"

/* MCAL*/
#include "DIO_interface.h"

/****************************************
 * Macros
 ****************************************/
typedef enum {
	master,
	slave
}SPI_mode_t;

#define SS 		DIO_PIN4
#define MOSI 	DIO_PIN5
#define MISO 	DIO_PIN6
#define SCK 	DIO_PIN7

/****************************************
 * APIS Supported By SPI_interface.h
 ****************************************/

void MCAL_SPI_init(SPI_mode_t device);
void MCAL_SPI_Transmit(uint8_t *data , SPI_mode_t device);

#endif /* INC_SPI_INTERFACE_H_ */
