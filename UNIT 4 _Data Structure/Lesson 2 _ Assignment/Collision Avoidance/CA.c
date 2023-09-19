/*
 *  CA.c
 *  Created on: Sep 19, 2023
 *  Author: Abdullah Karkour
 */

#include "CA.h"

void(*CA_state)();

// variables
int CA_distance =0 ;
int CA_speed = 0 ;
int CA_threshold = 50 ;

// connection function
void US_distance_set(int d)
{
	// set distance from US
	CA_distance = d ;

	// check event
	(CA_distance <= CA_threshold) ? (CA_state = State(CA_waiting)) : (CA_state = State(CA_driving)) ;

	printf("US------distance =%d----->CA\n" , CA_distance);
}

// Event definition
State_define(CA_waiting)
{
	// state event
	CA_state_id = CA_waiting ;

	// state action
	CA_speed = 0 ;
	DC_motor(CA_speed);

	printf("CA_waiting State : distance = %d	speed = %d\n" , CA_distance , CA_speed);

}
State_define(CA_driving)
{
	// state event
	CA_state_id = CA_driving ;

	// state action
	CA_speed = 30 ;
	DC_motor(CA_speed);

	printf("CA_driving State : distance = %d	speed = %d\n" , CA_distance , CA_speed);
}
