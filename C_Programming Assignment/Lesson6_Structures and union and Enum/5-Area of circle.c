#include <stdio.h>
#include <string.h>

#define Pi 3.14

void Area(float reduis);
int main ()
{
	setbuf(stdout,NULL);
	float R ;
	printf("Enter the reduis : ");
	scanf("%f" , & R);
	Area(R);

}
void Area(float reduis)
{
	printf("Area = %.2f" , Pi*reduis*reduis);
}


