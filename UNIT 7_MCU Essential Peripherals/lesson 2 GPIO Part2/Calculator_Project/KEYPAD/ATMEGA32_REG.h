 /*
 * ATMEGA32_REG.h
 *
 *  Created on: Mar 2, 2023
 *      Author: Hello
 */

#ifndef ATMEGA32_REG_H_
#define ATMEGA32_REG_H_

                      /* DIO REGISTER */

/* DATA DIRCTION REGISTERS */

#define DDRA  (*(volatile uint8*)0x3A)
#define DDRB  (*(volatile uint8*)0x37)
#define DDRC  (*(volatile uint8*)0x34)
#define DDRD  (*(volatile uint8*)0x31)

/* OUTPUT REGISTER */

#define PORTA  (*(volatile uint8*)0x3B)
#define PORTB  (*(volatile uint8*)0x38)
#define PORTC  (*(volatile uint8*)0x35)
#define PORTD  (*(volatile uint8*)0x32)

/* INPUT REGISTER */

#define PINA  (*(volatile uint8*)0x39)
#define PINB  (*(volatile uint8*)0x36)
#define PINC  (*(volatile uint8*)0x33)
#define PIND  (*(volatile uint8*)0x30)

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


/* ADC REGISTERS */


// ADC Multiplexer selection Register
#define  ADMUX   (*(volatile uint8* ) 0x27 )

// ADC Control and Status Register A
#define  ADCSRA   (*(volatile uint8* ) 0x26 )

// The ADC Data Registers
#define  ADCL     (*(volatile uint8* ) 0x24 )
#define  ADCH     (*(volatile uint8* ) 0x25 )
#define  ADC_uint16   (*(volatile uint16*) 0x24 )

// Special FunctionsIO  Register
#define  SFIOR    (*(volatile uint8* ) 0x50 )


/* TIMRS REGISTERS */


/* TIMER0 */

/*Timer/Counter0 Control Register*/
#define  TCCR0     (*(volatile uint8* ) 0x53 )

/*Timer/Counter Register*/
#define  TCNT0     (*(volatile uint8* ) 0x52 )

/*Timer/Counter0 Output Compare Register*/
#define  OCR0      (*(volatile uint8* ) 0x5C )

/*Timer/Counter  Interrupt Mask Register*/
#define  TIMSK     (*(volatile uint8* ) 0x59 )

/*Timer/Counter Interrupt Flag Register*/
#define  TIFR      (*(volatile uint8* ) 0x58 )

/* TIMER1 */

/*Timer/Counter1 Control Register A */
#define  TCCR1A     (*(volatile uint8* ) 0x4F )

/*Timer/Counter1 Control Register B */
#define  TCCR1B    (*(volatile uint8* ) 0x4E )

// Timer/Counter1
#define  TCNT1L     (*(volatile uint8* ) 0x4C )
#define  TCNT1H     (*(volatile uint8* ) 0x4D )
#define  TCNT1_uint16   (*(volatile uint16*) 0x4C )

// OUTPUT COMPARE REGISTER 1 A
#define  OCR1AL     (*(volatile uint8* ) 0x4A )
#define  OCR1AH     (*(volatile uint8* ) 0x4B )
#define  OCR1A_uint16   (*(volatile uint16*) 0x4A )

// OUTPUT COMPARE REGISTER 1 B
#define  OCR1BL     (*(volatile uint8* ) 0x48 )
#define  OCR1BH     (*(volatile uint8* ) 0x49 )
#define  OCR1B_uint16   (*(volatile uint16*) 0x48 )

// INPUT CAPTURE REGISTER 1
#define  ICR1L     (*(volatile uint8* ) 0x46 )
#define  ICR1H     (*(volatile uint8* ) 0x47 )
#define  ICR1_uint16   (*(volatile uint16*) 0x46 )

/* WDT */

// Watchdog Timer Control Register
#define  WDTCR     (*(volatile uint8* ) 0x41 )








#endif /* ATMEGA32_REG_H_ */
