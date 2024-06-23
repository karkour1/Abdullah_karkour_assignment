/*
 * main.c
 *
 *  Created on: May 23, 2024
 *      Author: Hello
 */
#include "I2C_interface.h"
#include "ATMEGA32_REG.h"
#include "DIO_interface.h"

// F_CPU of Device
#define F_CPU		8000000

void I2C_IRQ_CallBack(Slave_IRQ_State_t state)
{
}
int main()
{
	I2C_init(0x48, I2C_Prescaler_1, I2C_IRQ_CallBack);

	uint8_t data[5] = {1,2,3,4,5};
	while(1)
	{
		I2C_Master_TX(data, Slave_Address, 5);

	}
}
