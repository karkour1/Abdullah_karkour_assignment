/*
 *  main.c
 *  Created on: Feb 15, 2024
 *  Author: ABDUALLAH KARKOUR
 */


#include "ATMEGA32_REG.h"
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Atmega32_USART_interface.h"
#include "DIO_interface.h"

USART_Config_t usart_cfg ;
uint16_t a , x ;


int main(void)
{
	DIO_SetPinDirection(DIO_PORTD , DIO_PIN0 , DIO_PIN_INPUT);
	DIO_SetPinDirection(DIO_PORTD , DIO_PIN1 , DIO_PIN_OUTPUT);

	usart_cfg.BaudRate = USART_BaudRate_9600;
	usart_cfg.Fosc = 8000000;
	usart_cfg.Mode = USART_Normal_Mode;
	usart_cfg.Parity_status = USART_Parity_Disable;
	usart_cfg.Stop_bits = USART_StopBit_1bit;
	usart_cfg.data_bits = USART_DataBit_8bits;
	MCAL_USART_Init(&usart_cfg);
	LCD_init();
	GI_Enable;

	LCD_Send_string("UASRT AIK");
    a = 'A' ;
    MCAL_USART_Send(&a , disable);
    a = 'I';
    MCAL_USART_Send(&a , disable);
    a = 'K';
    MCAL_USART_Send(&a , disable);
	LCD_SET_Cursor(2,0);
	while(1)
	{


	}
}
