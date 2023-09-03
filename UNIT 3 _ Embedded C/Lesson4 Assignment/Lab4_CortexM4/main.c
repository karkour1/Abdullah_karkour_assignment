/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Abdullah karkour
 * @brief          : Main program body
 ******************************************************************************/


#include "Platform_Types.h"


                 /*********                   Macros of Register address                     *******/
#define SYSCTL_RCGC2_R              *(volatile uint32 *)(0x400FE108 ) // REGISTER Enable the GPIO port
#define GPIO_PORTF_DATA_R           *(volatile uint32 *)(0x400253FC ) // Register to SET DATA OF PORTF PINS 
#define GPIO_PORTF_DIR_R            *(volatile uint32 *)(0x40025400 ) // Register to SET DIRECTION OF PORTF PINS
#define GPIO_PORTF_DEN_R            *(volatile uint32 *)(0x4002551C ) // Register to ENABLE PORTF PINS

int main(void)
{
	volatile uint32 delay_counter ;
	SYSCTL_RCGC2_R = 0x20;     // ENABLE PORTF
	for(delay_counter = 0 ; delay_counter<200; delay_counter++);// delay to make sure that GPIO is up 
	GPIO_PORTF_DEN_R |= 1<<3 ; // set enable of pin3 PORTF
	GPIO_PORTF_DIR_R |= 1<<3 ; // Set pin3 PORTF Output

	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;             // LED OFF
		for(delay_counter = 0 ; delay_counter<20000; delay_counter++);   // delay
		GPIO_PORTF_DATA_R &= ~(1<<3);            // LED ON
		for(delay_counter = 0 ; delay_counter<20000; delay_counter++);    //delay
	}

	return 0 ;
}

