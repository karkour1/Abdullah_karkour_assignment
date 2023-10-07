/*
 * Pressure_sensor.c
 * Created on: Sep 21, 2023
 * Author: Abdullah Karkour
 */

#include "Pressure_Sensor.h"
#include "driver.h"
#include "State.h"

// pointer to Function 
void (*PS_State_P)();

// Pressure value
int pv ;

// State functions defintion
void PS_init()
{
	// initiate the Sensor
}

State_define(PS_reading)
{
	// state 
	PS_state_id = PS_reading ;
	
	// state action 
	pv = getPressureVal();
	Set_Pressure_Value(pv);
	
	// State 
	PS_State_P = State(PS_Waiting);
}
	
State_define(PS_Waiting)
{
	// state 
	PS_state_id = PS_Waiting ;
	
	// state action 
	Delay(Sensor_Timer);
	
	// State 
	PS_State_P = State(PS_reading);
	PS_State_P();
}
	

