/*
 *  CA.h
 *  Created on: Sep 19, 2023
 *  Author: Abdullah Karkour
 */

#ifndef CA_H_
#define CA_H_

#include "State.h"

// CA state
enum{
	CA_waiting,
	CA_driving
}CA_state_id;

State_define(CA_waiting);
State_define(CA_driving);

// global pointer to function of states
extern void(*CA_state)();


#endif /* CA_H_ */
