/*
 *  US_Sensor.h
 *  Created on: Sep 19, 2023
 *  Author: Abdullah Karkour
 */

#ifndef US_SENSOR_H_
#define US_SENSOR_H_

#include "State.h"

// Ultrasnic Sensor state
enum{
	US_busy
}US_state_id;

void US_init();
State_define(US_busy);

// Global pointer to function of US
void (*US_state)();


#endif /* US_SENSOR_H_ */
