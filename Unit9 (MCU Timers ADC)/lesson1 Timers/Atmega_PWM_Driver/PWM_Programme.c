/*
 *  PWM_Programme.c
 *  Created on: Jun 30, 2024
 *  Author: ABDULLAH KARKOUR
 */

/******************************************************************************
*									INCLUDES	                			  *
*******************************************************************************/
#include "PWM_Interface.h"
#include "ATMEGA32_TIMER0_Interface.h"

/******************************************************************************
*								 APIS IMPLEMENTATION			              *
*******************************************************************************/
void Generate_PWM(PWM_Frq_t frq , uint8_t  Duty_Cycle)
{
#ifdef FAST_PWM_Mode

	// SET TIMER0 IN PWM MODE
	TIMER0_CONFIG_t confg ={Fast_PWM,Clear_OC0,OCIE_DISABLE,TOIE_DISABLE,frq};

#endif

#ifdef Phase_Correct_PWM_Mode

	// SET TIMER0 IN PWM MODE
	TIMER0_CONFIG_t confg ={ PWM_Phase_Correct ,Clear_OC0,OCIE_DISABLE,TOIE_DISABLE,frq};

#endif

	uint8_t TicksNumber;
	TicksNumber = (Duty_Cycle * 256)/100 ;
	TIMER0_SetCompareValue(TicksNumber);
	TIMER0_Init(&confg);

	// Set the OC0 Pin Output
	DDRB |= (1<<3);

}
