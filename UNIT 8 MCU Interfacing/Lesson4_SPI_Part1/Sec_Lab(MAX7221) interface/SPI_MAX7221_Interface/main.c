/*
 * main.c
 *
 *  Created on: Apr 1, 2024
 *  Author: Abdullah Karkour
 */

#include <util/delay.h>
#include"MAX7221_interface.h"

int main(void)
{
	uint8_t digit_index , Data =0 ;

	MAX7221_Confg_t device ;

	device.Decode_Mode = Decode_Mode_B_decode_for_digit_0_7;
	device.Intensity = 15;
	device.Scan_Limit = 7;

	HAL_MAX7221_init(&device);

	while(1)
	{
		for (digit_index = 1; digit_index < 9; digit_index++)
		{

			HAL_MAX7221_Excute(digit_index, Data);


		}
		Data++;
		_delay_ms(1000);
		if(Data == 9) Data = 0 ;
	}
}
