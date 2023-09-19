/*
 * State.h file
 * Created on: Sep 19, 2023
 * Author: Abdullah Karkour
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

// To define the state function
#define State_define(_stateFunc_)    void ST_##_stateFunc_()
// To call state function
#define State(_stateFunc_)           ST_##_stateFunc_


// State Connection
void US_distance_set(int d);
void DC_motor(int s);


#endif /* STATE_H_ */
