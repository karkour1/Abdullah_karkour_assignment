/*
 *  ATMEGA32_TIMER0_Programme.c
 *  Created on: Jun 30, 2024
 *  Author: ABDULLAH KARKOUR
 */

/******************************************************************************
*                               INCLUDES			                          *
*******************************************************************************/
#include "ATMEGA32_TIMER0_Interface.h"


/******************************************************************************
*                               GLOBAL & EXTERN VARIABLES                     *
*******************************************************************************/

PTR_VoidFuncVoid_t CALLBACK_OVF;
PTR_VoidFuncVoid_t CALLBACK_CM;

/******************************************************************************
*								 APIS IMPLEMENTATION			              *
*******************************************************************************/
void TIMER0_Init(TIMER0_CONFIG_t* configuartion)
{
	if(configuartion != ((void*)0))
	{
		// Set Timer Mode
		TCCR0 |= configuartion->mode;

		// Set Compare Match Mode
		TCCR0 |= configuartion->Com_mode ;

		// Set Prescaler Of Timer Clock
		TCCR0 |= configuartion->clk;

		// Set Interrupt of OVF
		TIMSK |= configuartion->ovfInterrupt ;

		// Set Interrupt of Compare Match
		TIMSK |= configuartion->ocmInterrupt ;
	}
}
void TIMER0_Stop()
{
	// Set No Clock for timer
	TCCR0 |= NO_CLK_SRC ;

	// Disable the Compare match and OVF interrupt
	TIMSK &= ~(OCIE_ENABLE | TOIE_ENABLE);

	// Reset the Timer registers
	TCCR0 = 0 ;
	TIMSK = 0 ;
}

void TIMER0_GetCompareValue(uint8_t* TicksNumber)
{
	*TicksNumber = OCR0 ;
}
void TIMER0_SetCompareValue(uint8_t TicksNumber)
{
	OCR0 = TicksNumber ;
}

void TIMER0_GetCounterValue(uint8_t* TicksNumber)
{
	*TicksNumber = TCNT0 ;
}
void TIMER0_SetCounterValue(uint8_t TicksNumber)
{
	TCNT0 = TicksNumber ;
}


void TIMER0_CALLBACK_Overflow_INTERRUPT(PTR_VoidFuncVoid_t callback)
{
	CALLBACK_OVF = callback;
}
void TIMER0_CALLBACK_CompareMatch_INTERRUPT(PTR_VoidFuncVoid_t callback)
{
	CALLBACK_CM = callback ;
}


// ISR FUNCTION PROTOTYPE FOR TIMER0 OVF

void __vector_11 (void) __attribute__ (( signal ));

void __vector_11(void)
{
//	static U16 counter_OVR = 0 ;
//	++ counter_OVR;
//
//	if (TMR_TMR0_OverFlow_Counter == counter_OVR)
//	{
//		counter_OVR = 0;
//		// call action
//		if (TMR_timer0_ovf_CallBack != 0)
//		{
//			TMR_timer0_ovf_CallBack () ;
//		}
//
//	}

	CALLBACK_OVF();
}

void __vector_10 (void) __attribute__ (( signal ));

void __vector_10(void)
{
//	static U16 counter_CTC = 0 ;
//	++ counter_CTC;
//
//	if (TMR_TMR0_CTC_Counter == counter_CTC)
//	{
//		counter_CTC = 0;
//		// call action
//		if (TMR_timer0_CTC_CallBack != 0)
//		{
//			TMR_timer0_CTC_CallBack () ;
//		}
//
//	}

	CALLBACK_CM();

}








