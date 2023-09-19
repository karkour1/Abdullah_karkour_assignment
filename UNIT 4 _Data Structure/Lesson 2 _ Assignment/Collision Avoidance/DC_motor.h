/*
 *  DC_motor.h
 *  Created on: Sep 19, 2023
 *  Author: Abdullah Karkour
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "State.h"

// DC_Motor state
enum {
	DC_idle,
	DC_busy
}DC_state_id;

// state functions prototype
State_define(DC_idle);
State_define(DC_busy);
void DC_init();
// global pointer to state function
extern void (*DC_state)();


#endif /* DC_MOTOR_H_ */
