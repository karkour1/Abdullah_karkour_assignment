/*
 * Ex4.c
 *
 *  Created on: Jul 20, 2023
 *      Author: abdullah
 */


#include <stdio.h>
#include <string.h>

struct Sstudent {
	char name[100] ;
	int  roll ;
	float marks ;
};
int main ()
{
	setbuf(stdout,NULL);

	int size , i ;
	printf("Enter number of students :");
	scanf("%d" , &size) ;

	struct Sstudent student1 [size];

	for (i = 0 ; i<size ;i++)
	{
		printf("Enter information of students %d: \n" , i+1);
		printf("Enter name : ");
		scanf("%s" ,student1[i].name);
		printf("Enter roll number : ");
		scanf("%d", &student1[i].roll);
		printf("Enter marks : ");
		scanf("%f", &student1[i].marks);
	}

	printf("\nDisplay information of students : \n\n");
	for (i = 0 ; i<size ;i++)
	{
		printf("Information of student %d : \n" , i+1);
		printf("Name : %s\n",student1[i].name);
		printf("Roll: %d\n",student1[i].roll);
		printf("Marks : %.2f\n\n" , student1[i].marks);
	}

}



