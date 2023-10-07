/*
 * State.h file
 * Created on: Sep 19, 2023
 * Author: Abdullah Karkour
 */

#ifndef STATE_H_
#define STATE_H_


// To define the state function
#define State_define(_stateFunc_)    void ST_##_stateFunc_()
// To call state function
#define State(_stateFunc_)           ST_##_stateFunc_


// State Connection
void Set_Pressure_Value(int PS_Value);
void High_Pressure_detected();
void Start_Alarm();
void Stop_Alarm();


#endif /* STATE_H_ */
