/*
 * Ex3.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	float a , b , c , max ;
	printf("Enter three numbers:  ") ;
	scanf("%f\n%f\n%f" , &a ,&b ,&c);

    max = a;
    if(b>max) max =b;
    if(c>max) max =c;

    printf("Largest number = %.2f" , max);


}
