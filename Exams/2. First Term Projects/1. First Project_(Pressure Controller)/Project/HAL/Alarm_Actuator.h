/*
 * Alarm_Actuator.h
 * Created on: Sep 21, 2023
 * Author: Abdullah Karkour
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include "State.h"
#include "driver.h"


// states
enum{
	Alarm_ON,
	Alarm_OFF
}Alarm_State_id;

// States prototypes
void Alarm_init();
State_define(Alarm_ON);
State_define(Alarm_OFF);

// Global pointer to the function
extern void (*Alarm_State_P)();


#endif /* ALARM_ACTUATOR_H_ */
