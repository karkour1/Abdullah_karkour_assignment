/*
 *  main.c for interrupt project turn led on for one second Atmega32
 *  Created on: Nov 10, 2023
 *  Author: Abdullah karkour
 */

#include "Platform_Types.h"
#include <util/delay.h>

/* GPIO Registers */

//input data registers
#define PIND  (*(volatile uint8*)0x30)
#define PINB  (*(volatile uint8*)0x36)

// OUTPUT REGISTER
#define PORTB  (*(volatile uint8*)0x38)
#define PORTD  (*(volatile uint8*)0x32)

// DATA DIRCTION REGISTERS
#define DDRB  (*(volatile uint8*)0x37)
#define DDRD  (*(volatile uint8*)0x31)

/* EXTERNAL INTERRUPT REGISTERS */

// MCU CONTROL REGISTER
# define MCUCR   (*(volatile uint8* ) 0x55 )

// MCU CONTROL AND STATUS REGISTER
# define MCUCSR  (*(volatile uint8* ) 0x54 )

// GENERAL INTERRUPT CONTROL REGISTER
# define GICR    (*(volatile uint8* ) 0x5B )

// GENERAL INTERRUPT FLAG REGISTER
# define GIFR    (*(volatile uint8* ) 0x5A )

// STATUS REGISTER
# define SREG    (*(volatile uint8* ) 0x5F )

 /* EXTERNAL INTERRUPT Handlers */

// IRQ0 Handler
void  __vector_1 (void) __attribute__ ((signal));
void  __vector_1 (void)
{
	// turn on the Led for 1 second
	PORTD |= (1<<5);
	_delay_ms(5000);
	PORTD &= ~(1<<5);
}
// IRQ1 Handler
void  __vector_2 (void) __attribute__ ((signal));
void  __vector_2 (void)
{
	// turn on the Led for 1 second
	PORTD |= (1<<6);
	_delay_ms(5000);
	PORTD &= ~(1<<6);
}
// IRQ2 Handler
void  __vector_3 (void) __attribute__ ((signal));
void  __vector_3 (void)
{
	// turn on the Led for 1 second
	PORTD |= (1<<7);
	_delay_ms(5000);
	PORTD &= ~(1<<7);
}

void GPIO_init(void)
{
	// Set the INT0 (PD2) , INT1 (PD1) , INT2 (PB2)  as input pins
	DDRB &= ~(1<<2);
	DDRD &= ~(1<<2);
	DDRD &= ~(1<<3);

	// Set the Led pins as output
	DDRD |=(1<<5);
	DDRD |=(1<<6);
	DDRD |=(1<<7);


}
void EXTI_init(void)
{
	//Any logical change on INT0 generates an interrupt request
	MCUCR |=(1<<0);

	//The rising edge of INT1 generates an interrupt request.
	MCUCR |= ((1<<2)|(1<<3));

	// If ISC2 is written to zero, a falling edge on INT2 activates the interrupt
	MCUCSR &= ~(1<<6);

	// When the (INT0 ,INT1 ,INT2)  bit is set (one) and the I-bit in the Status Register (SREG) is set (one),the external pin interrupt is enabled
	// Enable INT0
	GICR  |=(1<<6);
	// Enable INT1
	GICR  |=(1<<7);
	// Enable INT2
	GICR  |=(1<<5);
}

void Set_Globel_interrupt(void)
{
	/* Bit 7 : Global Interrupt Enable
	 * The Global Interrupt Enable bit must be set for the interrupts to be enabled
	 */
	SREG |= (1<<7);
}
int main()
{
	GPIO_init();
	EXTI_init();
	Set_Globel_interrupt();

	while(1);
}

