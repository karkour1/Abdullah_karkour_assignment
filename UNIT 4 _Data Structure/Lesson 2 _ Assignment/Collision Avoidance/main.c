/*
 *  main.c
 *  Created on: Sep 19, 2023
 *  Author: Abdullah Karkour
 */

#include "CA.h"
#include "DC_motor.h"
#include "US_Sensor.h"

void setup()
{
	// init all drivers
	US_init();
	DC_init();

	// set pointer of states for each block
	CA_state = State(CA_waiting);
	US_state = State(US_busy);
	DC_state = State(DC_idle);
}

void main()
{
	volatile int i ;

	setup();

	while(1)
	{
		// Call state of each block
		US_state();
		CA_state();
		DC_state();
	}
	for(i =0 ; i<=1000 ; i++);
}
