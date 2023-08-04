#include <stdio.h>
#include <string.h>


int Reverse_digits_of_number(int number);
int main ()
{
	setbuf(stdout,NULL);

	int number , Result ;
	printf("Enter the number : ");
	scanf("%d",&number);

	Result = Reverse_digits_of_number(number);
	printf("Result = %d" , Result);
}

int Reverse_digits_of_number(int number)
{
	int Result = 0 , rem ;
	while(number != 0 )
	{
		rem = number %10 ;
		Result = Result * 10 + rem ;
		number /= 10;
	}

	return Result ;
}
