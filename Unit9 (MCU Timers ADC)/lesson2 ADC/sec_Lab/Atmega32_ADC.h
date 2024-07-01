/*
 *  Atmega32_ADC.h
 *  Created on: Jul 1, 2024
 *  Author: ABDULLAH KARKOUR
 */

#ifndef ATMEGA32_ADC_H_
#define ATMEGA32_ADC_H_

/******************************************************************************
 	 	 	 	 	 	 	 INCLUDES	 	 	 	 	 	 	 	 	 	  *
 * ****************************************************************************/
#include "ATMEGA32_REG.h"
#include "BIT_MATH.h"

/******************************************************************************
 	 	 	 	 	 	 	 Enums	 	 	 	 	 	 	 	 	 	  *
 * ****************************************************************************/
typedef enum {

	AREF_Off , 		// AREF, Internal Vref turned off
	AVCC_external,  //  AVCC with external capacitor at AREF pin
	AREF_ON = 3  	// Internal 2.56V Voltage Reference with external capacitor at AREF pin

}ADC_Vref_t;

typedef enum {

	ADC_CH0,
	ADC_CH1,
	ADC_CH2,
	ADC_CH3,
	ADC_CH4,
	ADC_CH5,
	ADC_CH6,
	ADC_CH7,

}ADC_channel_t;

typedef enum {

	ADC_Prescaler_2 = 1 ,
	ADC_Prescaler_4,
	ADC_Prescaler_8,
	ADC_Prescaler_16,
	ADC_Prescaler_32,
	ADC_Prescaler_64,
	ADC_Prescaler_128,

}ADC_Prescaler_t;

typedef enum {

	ADC_Free_Running_mode ,
	ADC_Analog_Comparator ,
	ADC_External_Interrupt_Request0,
	ADC_Timer0_Compare_Match ,
	ADC_Timer0_Overflow ,
	ADC_Timer_Compare_Match_B,
	ADC_Timer1_Overflow,
	ADC_Timer1_Capture_Event

}ADC_Mode_t;


/******************************************************************************
 	 	 	 	 	 	 	 APIS	 	 	 	 	 	 	 	 	 	  *
 * ****************************************************************************/
void ADC_init(ADC_Mode_t mode , ADC_Vref_t vref , ADC_Prescaler_t prescaler , ADC_channel_t channel);
void ADC_GET_Digital_Value(ADC_channel_t channel , uint16_t* Value);

// show the value of analog input according the Vref which is the max value of input
void ADC_GET_ACtual_Value(ADC_channel_t channel  , uint32_t Vref_value , uint32_t* Data);

#endif /* ATMEGA32_ADC_H_ */
