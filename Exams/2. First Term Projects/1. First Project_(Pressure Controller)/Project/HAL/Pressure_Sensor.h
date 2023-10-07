/*
 * Pressure_Sensor.h
 * Created on: Sep 21, 2023
 * Author: Abdullah Karkour
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "driver.h"
#include "State.h"

#define Sensor_Timer  100

// States
enum{
	PS_reading ,
	PS_Waiting
}PS_state_id;

// State functions prototypes
void PS_init();
State_define(PS_reading);
State_define(PS_Waiting);

// Global pointer to state function of PS
extern void (*PS_State_P)();


#endif /* PRESSURE_SENSOR_H_ */
