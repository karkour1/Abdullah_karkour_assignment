/*
 * LIFO.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Abdullah karkour
 */

#ifndef LIFO_H_
#define LIFO_H_

#include "Platform_Types.h"

// Type configuration of data
#define element_Type uint32

// LIFO length
#define LIFO_Length  5

// Type definitions
typedef struct {
	uint32 length ;
	uint32 count ;
	element_Type* base ; // base or start of LIFO
	element_Type* head ; // head or end of LIFO
}LIFO_Buf_t;

// status definition of LIFO Buffer
typedef enum {
	LIFO_no_error, // no error with the operation
	LIFO_full,     // buffer is full
	LIFO_empty,    // buffer is empty
	LIFO_null      // buffer does not exist
}LIFO_status;


// LIFO APIS
LIFO_status LIFO_init(LIFO_Buf_t lifo , element_Type* buf , uint32 size); // init the LIFO buffer
LIFO_status LIFO_Add_item(LIFO_Buf_t* lifo_buf , element_Type item); // Push item to the LIFO
LIFO_status LIFO_Get_item(LIFO_Buf_t* lifo_buf , element_Type* item); // Pop item from the LIFO
//LIFO_status LIFO_Buffer_Status (LIFO_Buf_t* lifo_buf); // Get LIFO Status


#endif /* LIFO_H_ */
