/*
 *  main.c
 *  Created on: Jun 30, 2024
 *  Author: ABDULLAH KARKOUR
 */

#include "PWM_Interface.h"


int main (void)
{
	for(int i = 0 ; i<1000 ; i++)
		Generate_PWM(PWM_FRQ_15khz, 25);
	Stop_PWM();
	while(1)
	{

	}
}
