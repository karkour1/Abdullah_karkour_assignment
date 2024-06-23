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


uint8_t ch ;
void I2C_IRQ_CallBack(Slave_IRQ_State_t state)
{
	if(state == slave_RX)
	{
		I2C_Slave_RX(&ch);
		DIO_SetPortValue(DIO_PORTA, ch);
	}
	else if(state == slave_TX)
		I2C_Slave_TX(&ch);
}
int main()
{
	// Global interrupt
	GI_Enable;

	DIO_SetPortDirection(DIO_PORTA, DIO_Port_OUTPUT);
	I2C_init(0x48, I2C_Prescaler_1, I2C_IRQ_CallBack);


	while(1)
	{

	}
}
