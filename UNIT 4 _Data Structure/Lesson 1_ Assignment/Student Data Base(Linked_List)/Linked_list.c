/*
 * Linked_list.c : Drive contain Linked List APIS definition
 * Created on: Sep 13, 2023
 * Author: Abdullah karkour
 */

#include "Linked_List.h"

// Head of Linked List pointer to the first element in list
extern struct SNode* PFirstNode = NULL ;

void Linked_List_Get_Node_data(struct SNode* new_student)
{
	uint8 temp_text[40]; // to get data in it

	DPRINTF("\nEnter the ID : ");
	gets(temp_text);
	new_student->Node.ID = atoi(temp_text);

	DPRINTF("Enter the Name : ");
	gets(new_student->Node.Name);

	DPRINTF("Enter the Height : ");
	gets(temp_text);
	new_student->Node.height = atof(temp_text);

}
void Linked_List_Add_Node()
{
	struct SNode* PNewNode ;

	//check if list is empty
	if(PFirstNode == NULL)
	{
		// create the New node
		PNewNode = (struct SNode*)malloc(sizeof(struct SNode));

		// assign the head to it
		PFirstNode = PNewNode ;
	}
	else
	{
		struct SNode* PLastNode ;

		// loop till the last node in the list
		PLastNode = PFirstNode ;
		while(PLastNode->PNextSdudent)
			PLastNode = PLastNode->PNextSdudent;

		// create the New node
		PNewNode = (struct SNode*)malloc(sizeof(struct SNode));

		// assign the Pointer of next node in Last node to it
		PLastNode->PNextSdudent = PNewNode;
	}

	// Get Node Data
	Linked_List_Get_Node_data(PNewNode);

	// assign NULL to the next of new Node
	PNewNode->PNextSdudent =NULL ;
}
void Linked_List_Delete_Node()
{
	uint8 temp_text[40];
	uint32 selected_id ;

	// Get ID of STudent to be deleted
	DPRINTF("\nEnter the ID : " );
	gets(temp_text);
	selected_id = atoi(temp_text);

	if(PFirstNode)
	{
		struct SNode* pPreviousNode = NULL ;
		struct SNode* pSelectedNode = PFirstNode;

		// Loop till the Selected Student to delete it
		while(pSelectedNode)
		{
			if(pSelectedNode->Node.ID == selected_id)
			{
				// check if selected student is the first student or not
				if(pPreviousNode)
					pPreviousNode->PNextSdudent = pSelectedNode->PNextSdudent;
				else
					PFirstNode = pSelectedNode->PNextSdudent ;

				// free the memory
				free(pSelectedNode);
				DPRINTF("\nthe item is deleted !");
			}
			else
			{
				//store previous Node and move to next Node
				pPreviousNode = pSelectedNode;
				pSelectedNode = pSelectedNode->PNextSdudent;
			}
		}
	}
	else
		DPRINTF("\nCan not find the student ID ");
}
void Linked_List_View_list()
{
	uint32 count =0 ;

	// Temp Pointer to the nodes
	struct SNode* pCurrentNode = PFirstNode ;

	// if the List is empty
	if(!pCurrentNode)
	{
		DPRINTF("\nEmpty List !");
	}
	else
	{
		// loop till the end of list
		while(pCurrentNode)
		{
			DPRINTF("\nRecord Number %d : " , count+1);
			DPRINTF("\nID : %d", pCurrentNode->Node.ID);
			DPRINTF("\nName : %s", pCurrentNode->Node.Name);
			DPRINTF("\nHeight : %.2f", pCurrentNode->Node.height);

			pCurrentNode  = pCurrentNode->PNextSdudent;
			count++;
		}
	}
}
void Linked_List_Delete_all_Nodes()
{
	if (PFirstNode ==NULL)
	{
		DPRINTF("\nEmpty List");
	}
	else
	{
		// Temp Pointer to the nodes
		struct SNode* pCurrentNode = PFirstNode ;

		// loop till the end of list
		while(pCurrentNode)
		{
			struct SNode* ptemp = pCurrentNode;
			pCurrentNode  = pCurrentNode->PNextSdudent;
			free(ptemp);
		}

		// assign Null to the head
		PFirstNode=NULL;
		DPRINTF("\nAll items has been deleted !");
	}



}
void Linked_List_Get_Node_with_index(uint32 index)
{
	uint32 count = 0;
	// Temp Pointer to the nodes
	struct SNode* pCurrentNode = PFirstNode ;

	// if the List is empty
	if(!pCurrentNode)
	{
		DPRINTF("\nEmpty List !");
	}
	else
	{
		// loop till the index number
		while(pCurrentNode && (count <= index))
		{
			if(count == index)
			{
				DPRINTF("\nThe Node at index %d : " , index);
				DPRINTF("\nID : %d", pCurrentNode->Node.ID);
				DPRINTF("\nName : %s", pCurrentNode->Node.Name);
				DPRINTF("\nHeight : %.2f", pCurrentNode->Node.height);
				break;
			}
			else
			{
				pCurrentNode  = pCurrentNode->PNextSdudent;
				count++;
			}
		}
		// if index is not exist
		if((count < index) || ((index == count && !pCurrentNode)))
			DPRINTF("\nThe index is not valid");
	}
}
int  Linked_List_Length(struct SNode* PHead)
{
	// use recursive function to loop and count the length
	if (!PHead)
		return 0;
	return 1+ Linked_List_Length(PHead->PNextSdudent);
}
void Linked_List_Nth_Node_From_End(struct SNode* PHead ,uint32 Number)
{
	// Get the index of Node by (Length - Number )
	Linked_List_Get_Node_with_index(Linked_List_Length(PHead) - Number) ;
}
void Linked_List_Middle_of_list(struct SNode* PHead)
{

	if(Linked_List_Length(PHead) %2)
	{
		// Get the index of Node in the middle if Length is odd
		Linked_List_Get_Node_with_index(Linked_List_Length(PHead) /2) ;
	}
	else
	{
		// Get the index of Node in the middle if Length is even (two nodes in middle)
		Linked_List_Get_Node_with_index((Linked_List_Length(PHead) /2)-1) ;
		Linked_List_Get_Node_with_index(Linked_List_Length(PHead) /2) ;
	}


}
