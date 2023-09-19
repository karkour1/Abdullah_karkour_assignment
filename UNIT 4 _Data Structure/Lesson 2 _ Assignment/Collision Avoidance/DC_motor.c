/*
 *  DC_motor.c
 *  Created on: Sep 19, 2023
 *  Author: Abdullah Karkour
 */

#include "DC_motor.h"

unsigned int DC_speed = 0;
void (*DC_state)();

void DC_motor(int s)
{
	// set DC_motor speed
	DC_speed = s ;

	// state of DC
	DC_state = State(DC_busy);

	printf("CA ----Speed =%d------>DC\n" , DC_speed);
}

void DC_init()
{
	// init DC_motor
	printf("DC_init \n\n\n");
}

// state definition
State_define(DC_idle)
{
	// state event
	DC_state_id = DC_idle ;

	// state action
	DC_state = State(DC_idle);

	printf("DC_idle state : Speed = %d \n" , DC_speed);
}
State_define(DC_busy)
{
	// state event
	DC_state_id = DC_busy ;

	// state action
	DC_state = State(DC_idle);

	printf("DC_busy state : Speed = %d \n\n\n" , DC_speed);
}
