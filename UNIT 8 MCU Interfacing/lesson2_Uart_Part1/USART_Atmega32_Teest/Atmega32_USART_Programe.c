/*
 *  Atmega32_USART_Programe.c
 *  Created on: Feb 15, 2024
 *  Author: ABDUALLAH KARKOUR
 */

/* INCLUDES */
#include "ATMEGA32_REG.h"
#include "Atmega32_USART_interface.h"
#include "BIT_MATH.h"

/* Generic Variables */
USART_Config_t* G_usart_cnfg;
uint16_t Data ;

void(* P_IRQ_CallBack[3])(void) ;		//Set the C Function() which will be called once the IRQ  Happen
										// P_IRQ_CallBack[0]-> RXC , P_IRQ_CallBack[1]-> UDRIE , P_IRQ_CallBack[2]-> TXC

/* Generic Function */

/*The read access is controlled by a timed sequence. Reading the I/O location once returns the UBRRH Register contents.
 * If the register location was read in previous system clock cycle,
 *  reading the register in the current clock cycle will return the UCSRCcontents */

uint8_t USART_ReadUCSRC( void )
{
	uint8_t ucsrc;
	/* Read UCSRC */
	ucsrc = UBRRH;
	ucsrc = UCSRC;
	return ucsrc;
}
void Send_Data(uint16_t* data)
{
	if(G_usart_cnfg->data_bits == USART_DataBit_9bits)
	{
		/* Copy 9th bit to TXB8 */
		UCSRB &= ~(1<<TXB8);
		UCSRB = ( *data & 0x0100 )? UCSRB|(1<<TXB8): UCSRB&(~(1<<TXB8));

		/* Put data into buffer, sends the data */
		UDR = *data;
	}
	else
	{
		/* Put data into buffer, sends the data */
		UDR = *data;
	}
}
void RXC_CallBack(void)
{

}
void TXC_CallBack(void)
{

}
void UDRIE_CallBack(void)
{
	/* Disable  Interrupt */
	UCSRB &= ~(USART_IRQ_Enable_UDRIE);
	Send_Data(&Data);

}

/* APIS */
void MCAL_USART_Init(USART_Config_t* usart_cnfg)
{
	G_usart_cnfg = usart_cnfg;
	/* Set baud rate */
	uint16_t baud =0 ;
	if(usart_cnfg->Mode == USART_Normal_Mode)
	{
		UCSRA &= ~(1<<U2X);
		baud = (usart_cnfg->Fosc /(16*usart_cnfg->BaudRate))-1;
	}
	else if (usart_cnfg->Mode == USART_Double_Speed_Mode)
	{
		UCSRA |= (1<<U2X);
		baud = (usart_cnfg->Fosc /(8*usart_cnfg->BaudRate))-1;
	}
	UCSRC= USART_ReadUCSRC()&(~(1<<URSEL));
	UBRRH = (uint8_t)(baud>>8);
	UBRRL = (uint8_t)baud;

	/* Set frame format: Bits of data, Number of stop bit , Parity Mode */
	UCSRC= USART_ReadUCSRC()|(1<<URSEL);

	UCSRC = USART_ReadUCSRC()|((usart_cnfg->data_bits & 0x03)<<UCSZ0);
	UCSRB = (usart_cnfg->data_bits>>2)? (UCSRB|(1<<UCSZ2)): (UCSRB& (~(1<<UCSZ2)));

	UCSRC = (usart_cnfg->Stop_bits)? (USART_ReadUCSRC()|(1<<USBS)) : (USART_ReadUCSRC()& (~(1<<USBS)));

	UCSRC = USART_ReadUCSRC()|((usart_cnfg->Parity_status)<<UPM0);


	/* Enable receiver and transmitter */
	UCSRB |= (1<<RXEN)|(1<<TXEN);


}
void MCAL_USART_Send(uint16_t* data, enum Polling_mechism P_E)
{
	/* Wait  transmit to Complete */
	while(( UCSRA & (1<<TXC)));
	if (P_E == enable)
	{
		/* Wait for empty transmit buffer */
		while ( !( UCSRA & (1<<UDRE)));
		Send_Data(data);
	}
	else
	{
		Data = *data ;
		P_IRQ_CallBack[1] = UDRIE_CallBack ;
		/* Enable  Interrupt */
		UCSRB |= USART_IRQ_Enable_UDRIE;
	}

}
void MCAL_USART_Resive(uint16_t* data , enum Polling_mechism P_E)
{
	if (P_E == enable)
		/* Wait for receive Data in receive buffer */
				while ( !( UCSRA & (1<<RXC)));

	if(G_usart_cnfg->data_bits  == USART_DataBit_9bits)
	{
		/* Copy 9th bit From RXB8 */
		*data = ( UCSRB &(1<<RXB8))? *data|(1<<8): *data&(~(1<<8));

		/* Read data From buffer */
		*data |= UDR ;
	}
	else
	{
		/* Read data From buffer */
		*data = UDR ;
	}
}

void MCAL_USART_SendString(uint8_t* data)
{

}
void MCAL_USART_ResiveString(uint8_t* data)
{

}

// ISR FUNCTION PROTOTYPE FOR USART, RX Complete

void __vector_13 (void) __attribute__ (( signal ));

void __vector_13(void)
{
	P_IRQ_CallBack[0]();
}

// ISR FUNCTION PROTOTYPE FOR USART, USART Data Register Empty

void __vector_14 (void) __attribute__ (( signal ));

void __vector_14(void)
{
	P_IRQ_CallBack[1]();
}

// ISR FUNCTION PROTOTYPE FOR USART, TX Complete

void __vector_15 (void) __attribute__ (( signal ));

void __vector_15(void)
{
	P_IRQ_CallBack[2]();
}
