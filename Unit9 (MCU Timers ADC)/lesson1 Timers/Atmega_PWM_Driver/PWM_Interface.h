/*
 *  PWM_Interface.h
 *  Created on: Jun 30, 2024
 *  Author: ABDULLAH KARKOUR
 */

#ifndef PWM_INTERFACE_H_
#define PWM_INTERFACE_H_

/* Options of PWM Mode :
 * 2 - Phase_Correct_PWM_Mode
 * 3 - FAST_PWM_Mode
 */
//#define FAST_PWM_Mode
#define Phase_Correct_PWM_Mode
/******************************************************************************
*                               INCLUDES			                          *
*******************************************************************************/
#include "ATMEGA32_TIMER0_Interface.h"

/******************************************************************************
*									ENUMS	                				  *
*******************************************************************************/
typedef enum {

#ifdef FAST_PWM_Mode
	PWM_FRQ_31khz = NO_PRESCALING,
	PWM_FRQ_3khz  = PRESCALING_CLK8,
	PWM_FRQ_480hz = PRESCALING_CLK64,
	PWM_FRQ_122hz = PRESCALING_CLK256,
	PWM_FRQ_30hz  = PRESCALING_CLK1024,
#endif

#ifdef Phase_Correct_PWM_Mode
	PWM_FRQ_15khz = NO_PRESCALING,
	PWM_FRQ_2khz  = PRESCALING_CLK8,
	PWM_FRQ_245hz = PRESCALING_CLK64,
	PWM_FRQ_61hz = PRESCALING_CLK256,
	PWM_FRQ_15hz  = PRESCALING_CLK1024,
#endif
}PWM_Frq_t;




/******************************************************************************
*									APIS				                      *
*******************************************************************************/
// Note Duty_Cycle is must set (1---> 100);
void Generate_PWM(PWM_Frq_t frq , uint8_t  Duty_Cycle);

#endif /* PWM_INTERFACE_H_ */
