/*
 *  main.c file for A students Data Base Project .
 *  Created on: Sep 13, 2023
 *  Author: Abdullah Karkor
 */

#include "Linked_List.h"

// Head of Linked List pointer to the first element in list
struct SNode* PFirstNode ;

void Options();

int main()
{
	uint8 temp_text[40];

	while(1)
	{
		// show options
		Options();

		// Get option
		gets(temp_text);
		DPRINTF("\n===========================");

		switch(atoi(temp_text))
		{
		case 1:
			Linked_List_Add_Node();
			break;
		case 2 :
			Linked_List_Delete_Node();
			break;
		case 3 :
			Linked_List_View_list();
			break;
		case 4:
			Linked_List_Delete_all_Nodes();
			break ;
		case 5 :
			return 0 ;
		default :
			DPRINTF("\n wrong option");
			break;
		}
	}

	return 0 ;
}



void Options()
{
	DPRINTF("\n===========================");
	DPRINTF("\n\t choose one of the following Options \n");
	DPRINTF("\n 1: Add Student ");
	DPRINTF("\n 2: Delete Student ");
	DPRINTF("\n 3: View All Student ");
	DPRINTF("\n 4: Delete All Student ");
	DPRINTF("\n 5: Quit ");
	DPRINTF("\n Enter option Number : ")
}
