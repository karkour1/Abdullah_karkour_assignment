/*
 * Ex5.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	char c ;
	printf("Enter a character:  ") ;
	scanf("%c" , &c);

    if ( ((c >= 'A')&&(c<= 'Z')) || ((c>='a')&&(c<='z')) ) printf("%c is an alphabet.", c);
    else printf("%c is not an alphabet.", c);



}
