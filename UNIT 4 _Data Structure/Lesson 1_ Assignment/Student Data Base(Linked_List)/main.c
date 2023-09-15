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
			// Get index of Node
			DPRINTF("\nEnter the index : " );
			gets(temp_text);
			Linked_List_Get_Node_with_index(atoi(temp_text));
			break;
		case 6 :
			DPRINTF("\nThe Length of List is : %d " , Linked_List_Length(PFirstNode));
			break;
		case 7 :
			// Get number of Node from end
			DPRINTF("\nEnter the number of Node From End : " );
			gets(temp_text);
			Linked_List_Nth_Node_From_End(PFirstNode, atoi(temp_text));
			break;
		case 8 :
			DPRINTF("\nThe Nodes in the Middle is : ");
			Linked_List_Middle_of_list(PFirstNode);
			break;
		case 9 :
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
	DPRINTF("\n 5: Get Node with it's index : ");
	DPRINTF("\n 6: Get Length of List  ");
	DPRINTF("\n 7: Get Node from the End of list : ");
	DPRINTF("\n 8: Get Node at the middle of List : ");
	DPRINTF("\n 9: Quit ");
	DPRINTF("\n Enter option Number : ")
}
