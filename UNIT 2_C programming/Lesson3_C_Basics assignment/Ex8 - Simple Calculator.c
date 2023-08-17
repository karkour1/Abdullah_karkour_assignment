/*
 * Ex8.c
 *
 *  Created on: Jul 16, 2023
 *      Author: abdullah
 */


#include <stdio.h>

int main ()
{
	setbuf(stdout,NULL);

	char operator ;
	float num1 , num2 ;
	printf("Enter operator either + , - , * , /:  ") ;
	scanf("%c" , &operator);
	printf("Enter two operands:  ") ;
	scanf("%f %f" , &num1,&num2);

	switch (operator) {
		case '+':
			printf("%.1f %c %.1f = %.1f" , num1 ,operator,num2, num1+num2);
			break;
		case '-':
			printf("%.1f %c %.1f = %.1f" , num1 ,operator,num2, num1-num2);
			break;
		case '*':
			printf("%.1f %c %.1f = %.1f" , num1 ,operator,num2, num1*num2);
			break;
		case '/':
			printf("%.1f %c %.1f = %.1f" , num1 ,operator,num2, num1/num2);
			break;
		default:
			break;
	}

}
