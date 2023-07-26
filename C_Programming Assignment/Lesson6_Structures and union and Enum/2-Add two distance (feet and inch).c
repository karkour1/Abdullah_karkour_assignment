#include <stdio.h>
#include <string.h>

struct Sdistance {
	int  feet ;
	float inch ;
};
struct Sdistance Summation( struct Sdistance dis1 , struct Sdistance dis2 );
int main ()
{
	setbuf(stdout,NULL);

	struct Sdistance  dis1,dis2,sum;

	printf("Enter information of 1st distance : \nEnter feed : ");
	scanf("%d",&dis1.feet);
	printf("Enter inch : ");
	scanf("%f" , &dis1.inch);

	printf("Enter information of 2nd distance : \nEnter feed : ");
	scanf("%d",&dis2.feet);
	printf("Enter inch : ");
	scanf("%f" , &dis2.inch);

	sum = Summation(dis1, dis2);

	printf("Sum of distance = %d feet %.1f inch", sum.feet , sum.inch);

}
struct Sdistance Summation( struct Sdistance dis1 , struct Sdistance dis2 )
{
	struct Sdistance sum ;
	sum.inch = dis1.inch + dis2.inch ;
	sum.feet = dis1.feet + dis2.feet + ((int)sum.inch / 12);
	sum.inch = sum.inch - ((int)sum.inch / 12)*12 ;

	return sum ;

}


