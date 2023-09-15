/*
 * FIFO.h
 *
 *  Created on: Sep 11, 2023
 *      Author: Abdullah karkour
 */

#ifndef FIFO_H_
#define FIFO_H_

#include <stdio.h>
#include "Platform_Types.h"

#define DPRINTF(...)      {fflush(stdout);\
						   fflush(stdin); \
						   printf(__VA_ARGS__);\
						   fflush(stdout);\
						   fflush(stdin);}
// configuration of user

// Select data type (uint8 , uint16,unit32,uint64)
#define element_type uint8
// create the buffer from the same data type of element_type
// size of data Buffer
#define FIFO_length  5


// FIFO data type definition
typedef struct {
	uint32 length ;
	uint32 count ;
	element_type* base;
	element_type* head;
	element_type* tail;
}FIFO_Buf_t;

// FIFO Buffer status
typedef enum{
	FIFO_no_error,
	FIFO_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null
}FIFO_Buffer_status;

// FIFO APIS
FIFO_Buffer_status FIFO_init(FIFO_Buf_t* fifo , element_type* buf , uint32 length); // initialization of FIFO Buffer
FIFO_Buffer_status FIFO_enqueue (FIFO_Buf_t*  fifo , element_type item);   // Add item to FIFO
FIFO_Buffer_status FIFO_dequeue (FIFO_Buf_t*  fifo , element_type* item);  // remove item from FIFO
FIFO_Buffer_status FIFO_is_full (FIFO_Buf_t*  fifo ); // check if FIFO buffer is full
void FIFO_Print(FIFO_Buf_t*  fifo);  // show the all items of buffer
void FIFO_Circler_move( FIFO_Buf_t*  fifo , element_type** pToMove); // make circler FIFO check and move on head and tail

#endif /* FIFO_H_ */
