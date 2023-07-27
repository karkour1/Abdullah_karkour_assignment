#include <stdio.h>
#include <string.h>


int Ones_digits_of_number(int number);
int main ()
{
	setbuf(stdout,NULL);

	int number , Result ;
	printf("Enter the number : ");
	scanf("%d",&number);

	Result = Ones_digits_of_number(number);
	printf("Result = %d" , Result);
}

int Ones_digits_of_number(int number)
{
	int Counter = 0 , i ;
	for (i=0 ; i< sizeof(number)*8 ; i++)
	{
		if ((number>>i) &1) Counter++;
	}

	return Counter ;
}
