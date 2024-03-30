/*
 *  Atmega32_USART_interface.h
 *  Created on: Feb 15, 2024
 *  Author: ABDUALLAH KARKOUR
 */

#ifndef ATMEGA32_USART_INTERFACE_H_
#define ATMEGA32_USART_INTERFACE_H_

#include <stdint.h>

/* Macros */

typedef struct
{
	uint32_t 	Fosc ; 	   // Specifies the  System Oscillator clock frequency

	uint32_t 	BaudRate ; // Specifies the  Baud rate (in bits per second, bps)
						   // This Parameter must be set based on @ref USART_BaudRate_define

	uint8_t     Mode ;	   // Specifies The Asynchronous Mode ( Asynchronous Normal Mode ,Asynchronous Double Speed Mode)
						   // This Parameter must be set based on @ref USART_Asynchronous_Mode_define

	uint8_t 	data_bits ; // the number of data bits(Character Size) in a frame
							// This Parameter must be set based on @ref USART_DataBit_define

	uint8_t 	Stop_bits ; // Specifies the number of Stop Bits to be inserted by the Transmitter
							// This Parameter must be set based on @ref USART_StopBit_define

	uint8_t 	Parity_status;  // Specifies type of parity generation and check
								// This Parameter must be set based on @ref USART_parity_define

}USART_Config_t;

// Enable and Disable Polling mechanism
enum Polling_mechism{
	enable ,
	disable
};


// USART Control and Status Register A UCSRA Bits Macros
#define MPCM		0
#define U2X			1
#define PE			2
#define DOR			3
#define FE			4
#define UDRE		5
#define TXC			6
#define RXC			7

// USART Control and Status Register B UCSRB Bits Macros
#define TXB8			0
#define RXB8			1
#define UCSZ2			2
#define TXEN			3
#define RXEN			4
#define UDRIE			5
#define TXCIE			6
#define RXCIE			7

// USART Control and Status Register C UCSRC Bits Macros
#define UCPOL			0
#define UCSZ0			1
#define UCSZ1			2
#define USBS			3
#define UPM0			4
#define UPM1			5
#define UMSEL			6
#define URSEL			7

/* Reference Macros definition */

//@ref USART_BaudRate_define
#define USART_BaudRate_2400			2400
#define USART_BaudRate_4800			4800
#define USART_BaudRate_9600 		9600
#define USART_BaudRate_14.4K		14400
#define USART_BaudRate_19.2K		19200
#define USART_BaudRate_28.8K		28800
#define USART_BaudRate_38.4K		38400
#define USART_BaudRate_57.6K		57600
#define USART_BaudRate_76.8K	    76800
#define USART_BaudRate_115.2K		115200
#define USART_BaudRate_230.4K		230400
#define USART_BaudRate_250K			250000
#define USART_BaudRate_0.5M		    500000
#define USART_BaudRate_1M			1000000

//@ref USART_Asynchronous_Mode_define
#define USART_Normal_Mode 				0
#define USART_Double_Speed_Mode			1

//@ref USART_DataBit_define
#define USART_DataBit_5bits 			0
#define USART_DataBit_6bits				1
#define USART_DataBit_7bits				2
#define USART_DataBit_8bits				3
#define USART_DataBit_9bits				7

//@ref USART_StopBit_define
#define USART_StopBit_1bit 				0
#define USART_StopBit_2bit				1

//@ref USART_parity_define
#define USART_Parity_Disable 				0
#define USART_Parity_Enable_Even			2
#define USART_Parity_Enable_Odd				3

//@ref USART_IRQ_Enable_define
/* Can Set more than one Interrupt by OR them with each other
* EX: to Enable TXE and TC
* IRQ_Enable = (USART_IRQ_Enable_TXC | USART_IRQ_Enable_RXC)
* */
#define USART_IRQ_Enable_NONE				(0)// Interrupt Disable
#define USART_IRQ_Enable_TXC				(1<<6)// TX Complete Interrupt Enable
#define USART_IRQ_Enable_RXC				(1<<7)// RX Complete Interrupt Enable
#define USART_IRQ_Enable_UDRIE				(1<<5)// USART Data Register Empty Interrupt Enable




/* APIS */
void MCAL_USART_Init(USART_Config_t* usart_cnfg);
void MCAL_USART_Send(uint16_t* data , enum Polling_mechism P_E);
void MCAL_USART_Resive(uint16_t* data , enum Polling_mechism P_E);
void MCAL_USART_SendString(uint8_t* data );
void MCAL_USART_ResiveString(uint8_t* data);



#endif /* ATMEGA32_USART_INTERFACE_H_ */
