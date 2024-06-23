/*
 * I2C_interface.h
 *
 *  Created on: May 22, 2024
 *  Author: ABDULLAH KARKOUR
 */

#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#include <stdint.h>


// Set with master or slave according which mode you want the device to be
#define Device_Mode		Slave

// Device Modes
#define Master 			0
#define Slave			1

// Address of Device in Slave Mode ,it must to be Set correct to can interface with device
#define Slave_Address			0xD0

typedef enum{
	start ,
	reapted_start
}Start_Condition_t;

typedef enum{
	stop ,
	not_stop
}Stop_Condition_t;

typedef enum{
	slave_RX ,
	slave_TX
}Slave_IRQ_State_t;

//@ref I2C_Prescaler_Define
#define I2C_Prescaler_1				0
#define I2C_Prescaler_4				1
#define I2C_Prescaler_16			2
#define I2C_Prescaler_64			3


/* Prescaler : this parameter must set from @ref I2C_Prescaler_Define
 * SCL_Freq  : up to 400KHZ
 */
void I2C_init(uint32_t SCL_Freq , uint8_t Prescaler, void (*IRQ_CallBack)(Slave_IRQ_State_t state));

void I2C_Master_TX(uint8_t* Data ,uint8_t SLA , uint32_t Data_Length );
void I2C_Master_RX(uint8_t* Data ,uint8_t SLA , uint32_t Data_Length , Start_Condition_t S , Stop_Condition_t P);

void I2C_Slave_TX(uint8_t* Data );
void I2C_Slave_RX(uint8_t* Data );

#endif /* I2C_INTERFACE_H_ */
