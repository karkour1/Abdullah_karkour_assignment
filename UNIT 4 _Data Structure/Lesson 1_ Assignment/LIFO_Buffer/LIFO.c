/*
 *  LIFO.c file
 *  Created on: Sep 10, 2023
 *  Author: Abdullah karkour
 */

#include "LIFO.h"
#include "Platform_Types.h"


// LIFO APIS

LIFO_status LIFO_init(LIFO_Buf_t lifo , element_Type* buf , uint32 size)
{
	if (buf)       // Check that the buffer is exist and not equal null
	{
		lifo.length = size ;
		lifo.count = 0 ;
		lifo.base = buf ;
		lifo.head = buf ;

		return LIFO_no_error ;
	}

	return LIFO_null ;
}
LIFO_status LIFO_Add_item(LIFO_Buf_t* lifo_buf , element_Type item )
{
	// Check that the buffer is exist and not equal null
	if(!lifo_buf->base || !lifo_buf->head || !lifo_buf)
		return LIFO_null ;

	// Check if the buffer is full
	if( lifo_buf->length == lifo_buf->count)
		return LIFO_full ;

	// push item to LIFO Buffer
	*(lifo_buf->head) = item ; // store item in the location of the head
	lifo_buf->head++;          // increment the head
	lifo_buf->count++;         // increment the counter of elements

	return LIFO_no_error ;
}
LIFO_status LIFO_Get_item(LIFO_Buf_t* lifo_buf , element_Type* item)
{
	// Check that the buffer is exist and not equal null
	if(!lifo_buf->base || !lifo_buf->head || !lifo_buf)
		return LIFO_null ;

	// Check if the buffer is empty
	if( lifo_buf->count == 0)
		return LIFO_empty ;

	// POP item from the LIFO Buffer
	lifo_buf->head--;         // decrement the head to reach the last item
	*item = *(lifo_buf->head);// pop the value
	lifo_buf->count--;        // decrement the counter of elements

	return LIFO_no_error ;
}

