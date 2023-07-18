/*
 * Ex8.c
 *
 *  Created on: Jul 18, 2023
 *      Author: abdullah
 */


#include <stdio.h>
#include<string.h>

int main ()
{
	setbuf(stdout,NULL);

	char sen[100] , rev[100] ;
	printf("Enter a string: ");
	gets(sen);

	int i=0;
	for(i =0 ; i< strlen(sen) ; i++)
	{
		rev[i]= sen[strlen(sen)-1-i];
	}
	rev[i]='\0';

	printf("Reverse string is : %s " ,rev);
}
