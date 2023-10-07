/*
 * Alarm_Actuator.c
 * Created on: Sep 21, 2023
 * Author: Abdullah Karkour
 */

#include "Alarm_Actuator.h"

// pointer to state Function
void (*Alarm_State_P)();


void Alarm_init()
{
	// init the Alarm
	// init the Alarm drivers
}
State_define(Alarm_ON)
{
	// Alarm on
	Set_Alarm_actuator(Alarm_ON);
}
State_define(Alarm_OFF)
{
	// Alarm off
	Set_Alarm_actuator(Alarm_OFF);
}

// State Connection
void Start_Alarm()
{
	//state
	Alarm_State_P = State(Alarm_ON);

	// state action
	Alarm_State_P();
}
void Stop_Alarm()
{
	//state
	Alarm_State_P = State(Alarm_OFF);

	// state action
	Alarm_State_P();
}



