/*
 * FIFO.c
 *
 *  Created on: Sep 11, 2023
 *      Author: Abdullah karkour
 */

#include "FIFO.h"

FIFO_Buffer_status FIFO_init(FIFO_Buf_t* fifo , element_type* buf , uint32 length)
{
	if(buf && length)
	{
		fifo->length = length ;
		fifo->count = 0;
		fifo->base = buf;
		fifo->tail = fifo->base ;
		fifo->head = fifo->base ;

		return FIFO_no_error ;
	}

	return FIFO_null ;
}
FIFO_Buffer_status FIFO_enqueue (FIFO_Buf_t*  fifo , element_type item)
{
	if( FIFO_is_full(fifo) == FIFO_no_error)
	{
		*(fifo->head) = item ; // store the value of item in the head location
		fifo->count ++ ;

		// Circler FIFO move
		FIFO_Circler_move(fifo, &(fifo->head));

		DPRINTF("FIFO ENQUEUE DONE \n");
		return FIFO_no_error ;
	}
	else
	{
		DPRINTF("FIFO ENQUEUE FAILED \n");
		return FIFO_error ;
	}

}
FIFO_Buffer_status FIFO_dequeue (FIFO_Buf_t*  fifo , element_type* item)
{
	// Check if FIFO is exist
	if(!fifo->base || !fifo->tail || !fifo->head)
	{
		return FIFO_null ;
		DPRINTF("FIFO DEQUEUE FAILED ,FIFO_null\n");
	}
	// Check if FIFO is empty
	if( fifo->count == 0)
	{
		DPRINTF("FIFO is empty");
		return FIFO_empty ;
	}

	// dequeue the value
	*(item) = *(fifo->tail);
	fifo->count--;

	// Circler FIFO move
	FIFO_Circler_move(fifo, &(fifo->tail));

	return FIFO_no_error ;
}
FIFO_Buffer_status FIFO_is_full (FIFO_Buf_t*  fifo )
{
	// Check if FIFO is exist
	if(!fifo->base || !fifo->tail || !fifo->head)
	{
		DPRINTF("FIFO is NULL\n");
		return FIFO_null ;
	}
	// Check if FIFO is full
	if( fifo->length == fifo->count)
	{
		DPRINTF("FIFO is full\n");
		return FIFO_full ;
	}

	// the FIFO is not Full and can store data
	return FIFO_no_error ;

}
void FIFO_Print(FIFO_Buf_t*  fifo)
{
	// Check if FIFO is empty
	if( fifo->count == 0)
	{
		DPRINTF("FIFO is empty\n");
	}
	else
	{
		element_type* temp ; // temp pointer to show data without change it
		uint32 i ;

		// show Data of FIFO
		temp = fifo->tail ;
		DPRINTF( "\n*********FIFO print*******\n");
		for(i=0 ; i< fifo->count ; i++)
		{
			DPRINTF("\t %x \n" , *temp);
			//Circle move
			FIFO_Circler_move(fifo, &temp);
		}

		DPRINTF( "\n****************\n");
	}


}
void FIFO_Circler_move(FIFO_Buf_t*  fifo , element_type** pToMove)
{
	if ((*pToMove)== (fifo->base + (fifo->length * sizeof(element_type))))
		(*pToMove) = fifo->base ;
	else
		(*pToMove)++;
}
