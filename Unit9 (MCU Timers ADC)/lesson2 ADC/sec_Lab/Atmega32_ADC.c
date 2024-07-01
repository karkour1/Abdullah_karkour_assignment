/*
 *  Atmega32_ADC.c
 *  Created on: Jul 1, 2024
 *  Author: ABDULLAH KARKOUR
 */


/******************************************************************************
 	 	 	 	 	 	 	 INCLUDES	 	 	 	 	 	 	 	 	 	  *
 * ****************************************************************************/
#include "Atmega32_ADC.h"

/******************************************************************************
 	 	 	 	 	 	 	 APIS	 	 	 	 	 	 	 	 	 	  *
 * ****************************************************************************/
void ADC_init(ADC_Mode_t mode , ADC_Vref_t vref , ADC_Prescaler_t prescaler , ADC_channel_t channel)
{
	// Set ADC Mode
	SFIOR |= (mode<<5) ;

	// Set Vref Selection
	ADMUX |= (vref<<6);

	// set Prescaler
	ADCSRA |= prescaler ;

	// Enable the ADC
	ADCSRA |= (1<<7);

}
void ADC_GET_Digital_Value(ADC_channel_t channel , uint16_t* Value)
{
	if((Value != (void*)0) && (channel <= 15))
	{
		// Select the channel
		ADMUX &= 0b11100000;
		ADMUX |= channel ;

		// Start Conversion
		ADCSRA |= (1<<6);

		// Wait the ADC Flag
		while(!((ADCSRA>>4)&1));

		// Clear the flag by writing one
		ADCSRA |= (1<<4);

		// Read the value
		*Value = ADC_U16 ;
	}
}

void ADC_GET_ACtual_Value( ADC_channel_t channel  , uint32_t Vref_value , uint32_t* Data)
{
	uint16_t ADC_Out ;
	ADC_GET_Digital_Value(channel, &ADC_Out);

	// the Input volt to the analog pin
	*Data = ((ADC_Out * Vref_value)/1024);
}

