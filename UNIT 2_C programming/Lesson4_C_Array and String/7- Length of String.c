/*
 * Ex7.c
 *
 *  Created on: Jul 18, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	char sen[100] ;
	printf("Enter a string: ");
	gets(sen);

	int i=0;
	while(sen[i] != '\0')
	{
		i++;
	}

	printf("Length of string = %d " ,i);
}
