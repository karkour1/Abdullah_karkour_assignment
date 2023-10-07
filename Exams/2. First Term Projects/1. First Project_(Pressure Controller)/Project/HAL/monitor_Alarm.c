/*
 * monitor_Alarm.c
 * Created on: Sep 21, 2023
 * Author: Abdullah Karkour
 */

#include "monitor_Alarm.h"

// global pointer to function state
void (*MA_State_P)();


// state function definition
void MA_init()
{
	// init the monitor Alarm
	// init the Drivers
}

State_define(MA_Alarm_OFF)
{
	// state
	MA_state_id = MA_Alarm_OFF ;

	// Action
	Stop_Alarm();

}
State_define(MA_Alarm_ON)
{
	// state
	MA_state_id = MA_Alarm_ON ;

	// Action
	Start_Alarm();

}

// State Connection
void High_Pressure_detected()
{
	// state
	MA_State_P = State(MA_Alarm_ON);
	//Action
	MA_State_P();

	// delay
	Delay(Alarm_duration);

	// state
	MA_State_P = State(MA_Alarm_OFF);
	//Action
	MA_State_P();

}

