/*
 * Linked_List.h : header file of Linked_List Drive
 *Created on: Sep 13, 2023
 *Author: Hello
 */

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

// includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Platform_Types.h"

#define DPRINTF(...)      {fflush(stdout);\
						   fflush(stdin); \
						   printf(__VA_ARGS__);\
						   fflush(stdout);\
						   fflush(stdin);}

// effective Data
struct Sdata{
	uint32 ID ;
	uint8 Name[40];
	float height;
};

// Linked list Node
typedef struct SNode {
	struct Sdata Node;
	struct SNode* PNextSdudent;
};


// Linked List APIS
void Linked_List_Get_Node_data(struct SNode* new_student); // take data from user and store it in new node
void Linked_List_Add_Node(); // Add new Node to List
void Linked_List_Delete_Node(); // Delete Node from list
void Linked_List_View_list(); // show all Nodes
void Linked_List_Delete_all_Nodes(); // make list Empty















#endif /* LINKED_LIST_H_ */
