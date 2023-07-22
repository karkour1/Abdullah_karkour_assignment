/*
 * Ex4.c
 *
 *  Created on: Jul 20, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int Power_of_number(int num ,int power);
int main ()
{
	setbuf(stdout,NULL);

	int base , power ;
	printf("Enter base number:");
	scanf("%d" , &base);

	printf("Enter power number (positive integer):");
	scanf("%d" , &power);


	printf("%d^%d = %d " , base , power , Power_of_number(base , power));


}

int Power_of_number(int num ,int power)
{
	if (power == 0) return 1;
	else
	{
		num *= Power_of_number(num , power-1);
		return num ;
	}

	
}
