#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "State.h"
#include "Pressure_Sensor.h"
#include "Alarm_Actuator.h"
#include "monitor_Alarm.h"

volatile unsigned int P_Value = 0 ;
volatile unsigned int threshold = 20 ;

void Setup()
{
	// Drivers initiate
	PS_init();
	MA_init();
	Alarm_init();

	// initiate the global pointers
	PS_State_P = State(PS_reading);
	MA_State_P = State(MA_Alarm_OFF);
	Alarm_State_P = State(Alarm_OFF);
}

// Function to get the pressure sensor value
void Set_Pressure_Value( int PS_Value)
{
	P_Value = PS_Value ;
}

int main (){

	GPIO_INITIALIZATION();
	Setup();

	Alarm_State_P();
	while (1)
	{
		PS_State_P();
		// check the high pressure
		if(P_Value > threshold)
		{
			// high pressure
			High_Pressure_detected();
		}

	}

}
