/*
 *  US_Sensor.c
 *  Created on: Sep 19, 2023
 *  Author: Abdullah Karkour
 */

#include "US_Sensor.h"

extern void (*US_state)();

unsigned int distance ;

// function generate random value from l to r
int Generate_random(int l , int r , int count)
{
	int i ;
	for(i=0 ; i<count ; i++)
	{
		int rand_num = (rand() % (r-l+1)) +l ;
		return rand_num ;
	}
}

void US_init()
{
	// init us sensor
	// call US drivers and functions
	printf("US_init \n");
}
State_define(US_busy)
{
	// state action
	US_state_id = US_busy ;
	// read from the US
	distance = Generate_random(45, 55, 1);

	printf("US_busy state : distance = %d \n",distance);

	US_distance_set(distance);
	US_state = State(US_busy);
}
