/*
 *  ATMEGA32_TIMER0_Interface.h
 *  Created on: Jun 30, 2024
 *  Author: ABDULLAH KARKOUR
 */

#ifndef ATMEGA32_TIMER0_INTERFACE_H_
#define ATMEGA32_TIMER0_INTERFACE_H_

/******************************************************************************
*                               INCLUDES			                          *
*******************************************************************************/
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"

/******************************************************************************
*									ENUMS	                				  *
*******************************************************************************/

typedef void(*PTR_VoidFuncVoid_t)(void);
typedef enum
{
	NORMAL,
	CTC = (1<<3),
	PWM_Phase_Correct = (1<<6),
	Fast_PWM = ((1<<3)|(1<<6))

}TIMER0_MODE_t;

typedef enum {
	Normal_operation,
	Toggle_OC0 = (1<<4),
	Clear_OC0  = (1<<5),
	Set_OC0    = (3<<4)

}Compare_Mode_t;

typedef enum
{
	NO_CLK_SRC,
	NO_PRESCALING,
	PRESCALING_CLK8,
	PRESCALING_CLK64,
	PRESCALING_CLK256,
	PRESCALING_CLK1024,
	EXT_CLK_FALLING,
	EXT_CLK_RISING,
}TIMER0_CLOCK_t;

typedef enum
{
	OCIE_DISABLE = 0x00,
	OCIE_ENABLE = 0x02
}OCMIE0_t;

typedef enum
{
	TOIE_DISABLE = 0x00,
	TOIE_ENABLE  = 0x01
}TOVFIE0_t;



/******************************************************************************
*									STRUCT	                				  *
*******************************************************************************/
typedef struct
{
	TIMER0_MODE_t mode;
	Compare_Mode_t Com_mode;
	OCMIE0_t  ocmInterrupt;
	TOVFIE0_t ovfInterrupt;
	TIMER0_CLOCK_t clk;
}TIMER0_CONFIG_t;

/******************************************************************************
*									APIS				                      *
*******************************************************************************/
void TIMER0_Init(TIMER0_CONFIG_t* configuartion);
void TIMER0_Stop();

void TIMER0_GetCompareValue(uint8_t* TicksNumber);
void TIMER0_SetCompareValue(uint8_t TicksNumber);

void TIMER0_GetCounterValue(uint8_t* TicksNumber);
void TIMER0_SetCounterValue(uint8_t TicksNumber);

void TIMER0_GetOverflowValue(uint8_t* pu8_TicksNumber);
void TIMER0_SetOverflowValue(uint8_t u8_TicksNumber);

void TIMER0_CALLBACK_Overflow_INTERRUPT(PTR_VoidFuncVoid_t callback);
void TIMER0_CALLBACK_CompareMatch_INTERRUPT(PTR_VoidFuncVoid_t callback);

#endif /* ATMEGA32_TIMER0_INTERFACE_H_ */
