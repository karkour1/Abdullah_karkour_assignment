/*
 * monitor_Alarm.h
 * Created on: Sep 21, 2023
 * Author: Abdullah Karkour
 */

#ifndef MONITOR_ALARM_H_
#define MONITOR_ALARM_H_

#include "State.h"
#include "driver.h"

// delay time
#define  Alarm_duration  60
// state
enum {
	MA_Alarm_OFF,
	MA_Alarm_ON
}MA_state_id;

// state function prototypes
void MA_init();
State_define(MA_Alarm_OFF);
State_define(MA_Alarm_ON);

// global pointer to function state
extern void (*MA_State_P)();



#endif /* MONITOR_ALARM_H_ */
