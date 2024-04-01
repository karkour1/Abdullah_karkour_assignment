/*
 * MAX7221_interface.h
 *
 *  Created on: Apr 1, 2024
 *  Author: ABDULLAH KARKOUR
 */

#ifndef MAX7221_INTERFACE_H_
#define MAX7221_INTERFACE_H_
/****************************************
 * Includes
 ****************************************/
#include <stdint.h>

/* MCAL*/
#include "SPI_interface.h"

/****************************************
 * Structure definition
 ****************************************/
typedef struct{

	uint8_t Decode_Mode ; // The decode-mode register sets BCD code B (0-9, E, H,L, P, and -) or no-decode operation For each digit
						  // this paramter must set @ref Decode-Mode_define

	uint8_t Intensity	; // The MAX7219/MAX7221 allow display brightness to be controlled
						  // the value of Intensity must be (0->15)

	uint8_t Scan_Limit	; // The scan-limit register sets how many digits are displayed, from 1 to 8
						  // the value of Intensity must be (0->7)
}MAX7221_Confg_t;

/****************************************
 * Macros
 ****************************************/
#define MAX7221_Decode_Mode_Register			0x09
#define MAX7221_Shutdown_Register				0x0C
#define MAX7221_Intensity_Register				0x0A
#define MAX7221_Scan_Limit_Register				0x0B

/****************************************
 * Refernce definition
 ****************************************/
// @ref Decode_Mode_define
#define Decode_Mode_No_decode						0x00
#define Decode_Mode_B_decode_for_digit_0			0x01
#define Decode_Mode_B_decode_for_digit_0_3			0x0F
#define Decode_Mode_B_decode_for_digit_0_7			0xFF


/****************************************
 * APIS Supported By MAX7221_interface.h
 ****************************************/

void HAL_MAX7221_init(MAX7221_Confg_t* device);
void HAL_MAX7221_Excute(uint8_t cmd , uint8_t data);


#endif /* MAX7221_INTERFACE_H_ */
