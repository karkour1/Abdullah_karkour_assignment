/*
 *  main.c
 *  Created on: Jun 30, 2024
 *  Author: ABDULLAH KARKOUR
 */

/******************************************************************************
*                               INCLUDES			                          *
*******************************************************************************/
#include "ATMEGA32_REG.h"
#include "ATMEGA32_TIMER0_Interface.h"


void TOIE_Callback()
{
	PORTA = ~PORTA;
}

int main(void)
{
	DDRA = 0xFF;
	GI_Enable;
	TIMER0_CALLBACK_CompareMatch_INTERRUPT(TOIE_Callback);
	TIMER0_CONFIG_t config = {CTC, Normal_operation ,OCIE_ENABLE, TOIE_DISABLE, PRESCALING_CLK8};
	TIMER0_SetCompareValue(0xF0);
    TIMER0_Init(&config);

	while(1)
	{

	}
}
