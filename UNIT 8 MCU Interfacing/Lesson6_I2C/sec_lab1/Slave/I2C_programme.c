/*
 * I2C_programme.c
 *
 *  Created on: May 22, 2024
 *  Author: ABDULLAH KARKOUR
 */


/******************************
 * 			INCLIDES
 ******************************/
#include "I2C_interface.h"
#include "ATMEGA32_REG.h"

void (*P_IRQ_CallBack)(Slave_IRQ_State_t state);


/**================================================================
 * @Fn			-I2C_init
 * @brief 		-Initializes the I2C according to the specified parameters in I2C_Init_Cfg
 * @param [in] 	-SCL_Freq: SCL Clock Frequency up to 400KHZ
 * @param [in] 	-Prescaler: control the bit rate prescaler
 * @param [in] 	-IRQ_CallBack: Pointer to CallBack Function it must Set in Slave mode Because it works in interrupt mode .
 * @retval 		-none
 * Note			-none
 */
void I2C_init(uint32_t SCL_Freq , uint8_t Prescaler , void (*IRQ_CallBack)(Slave_IRQ_State_t state))
{
	// Set  TWI Bit Rate Register TWBR
	TWBR = (uint8_t)(((F_CPU/SCL_Freq) -16)/(1<<((2*Prescaler)+1)));

	// Set d control the bit rate prescaler.
	TWSR |= Prescaler ;


#if Device_Mode == Slave

	/* The TWAR should be loaded with the 7-bit slave address
	 * The LSB of TWAR is used to enable recognition of the general call address (Disable = 0)
	 */
	TWAR = (uint8_t)((Slave_Address<<1)|(0)) ;

	// Set CallBack Function
	P_IRQ_CallBack = IRQ_CallBack ;

	/* Bit 0 – TWIE: TWI Interrupt Enable
	 * When this bit is written to one, and the I-bit in SREG is set, the TWI interrupt request will
	   be activated for as long as the TWINT Flag is high.
	 */
	TWCR |= (1<<0);

	// Enable TWI , Bit 6  TWEA: TWI Enable Acknowledge Bit
	TWCR |= (1<<2) |(1<<6);


#endif

}

void I2C_Master_TX(uint8_t* Data ,uint8_t SLA , uint32_t Data_Length )
{
	uint8_t i ;
	for(i=0 ; i<Data_Length ; i++ )
	{
		//Send START or repeated START condition
		TWCR = (1<<7)|(1<<5)|(1<<2);

		if(i==0)
		{
			// wait  START condition has been transmitted ,
			// the TWINT Flag is set by hardware,
			// and the status code in TWSR will be $08
			while((!(TWCR &(1<<7))) && (TWSR != 0x08));
		}
		else
		{
			// A repeated START condition has been transmitted
			while((TWSR != 0x10));
		}

		//writing SLA+W to TWDR
		TWDR = ((SLA<<1)|(0));

		// TWINT bit should be cleared (by writing it to one)
		TWCR = (1<<7)|(1<<2) ;

		// SLA+W has been transmitted , ACK has been received
		while((TWSR != 0x18));


		//writing Data byte TWDR
		TWDR = Data[i];

		// TWINT bit should be cleared (by writing it to one)
		TWCR = (1<<7)|(1<<2);

		// Data byte has been transmitted , ACK has been received
		while((TWSR != 0x28));
	}

	// Set STOP Condition
	TWCR = (1<<7)|(1<<4)|(1<<2);

}

void I2C_Master_RX(uint8_t* Data ,uint8_t SLA , uint32_t Data_Length , Start_Condition_t S , Stop_Condition_t P)
{
	//Send START or repeated START condition
	TWCR = (1<<7)|(1<<5)|(1<<2)|(1<<6) ;

	if(S == start)
	{
		// wait  START condition has been transmitted ,
		// the TWINT Flag is set by hardware,
		// and the status code in TWSR will be $08
		while((!(TWCR &(1<<7))) && (TWSR != 0x08));
	}
	else if(S == reapted_start)
	{
		// A repeated START condition has been transmitted
		while((TWSR != 0x10));
	}

	//writing SLA+W to TWDR
	TWDR = ((SLA<<1)|(1));

	// TWINT bit should be cleared (by writing it to one)
	TWCR = (1<<7)|(1<<2);

	// SLA+R has been transmitted , ACK has been received
	while((TWSR != 0x40));

	uint8_t i ;
	for(i=0 ; i<Data_Length ; i++ )
	{
		//writing Data byte TWDR
		TWDR = Data[i];

		// TWINT bit should be cleared (by writing it to one)
		TWCR = (1<<7)|(1<<2)|(1<<6);

		// Data byte has been received , ACK has been returned
		while((TWSR != 0x50));
	}

	// Set STOP Condition
	if(P == stop)
	TWCR = (1<<7)|(1<<4)|(1<<2)|(1<<6) ;
}


void I2C_Slave_TX(uint8_t* Data)
{
	TWDR = *Data ;
}
void I2C_Slave_RX(uint8_t* Data )
{
	*Data = TWDR ;
}




// ISR FUNCTION PROTOTYPE  Two-wire Serial Interface

void __vector_19 (void) __attribute__ (( signal ));

void __vector_19(void)
{
	// TWINT bit should be cleared (by writing it to one)
	TWCR = ((1<<7)|(1<<2)|(1<<6)|(1<<0));
	if ((TWSR == 0X80))
		P_IRQ_CallBack(slave_RX);
	else if ((TWSR == 0XB8))
		P_IRQ_CallBack(slave_TX);
}







