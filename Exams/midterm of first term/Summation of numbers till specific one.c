#include <stdio.h>
#include <string.h>


int Summation(int number);
int main ()
{
	setbuf(stdout,NULL);

	int number , Result ;
	printf("Enter the number : ");
	scanf("%d",&number);

	Result = Summation(number);
	printf("Result = %d" , Result);
}

int Summation(int number)
{
	static int Result = 0 ;

	if (number>0)
		{
		Result += number;
		Summation(--number);
		}


	return Result ;
}
