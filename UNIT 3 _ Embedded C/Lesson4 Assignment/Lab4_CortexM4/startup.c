/* startup.c file 
Eng. Abdullah karkour
*/
#include"Platform_Types.h"

extern int main(void); // decleration of main function

// addresses of start and End of data and bss
extern uint32 _S_Data;
extern uint32 _E_Data;
extern uint32 _S_bss;
extern uint32 _E_bss;
extern uint32 _E_text;


//Vectors Table Functions decleration
void Rest_Handler(void);

// Default definetion of vectors Function , can overwrite it in code source
void Default_Handler()
{
	Rest_Handler();
}

// decleration with weak attribute to can overwrite it , and alias to share Default_Handler definetion
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));;
void H_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));;
void MM_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));;
void Bus_Fault(void) __attribute__((weak, alias("Default_Handler")));;
void Usage_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));;

// stack size (reach to the stack_top)
static uint32 stack_top[256];

// Vectors Table , Array of pointer to function 
void ( * g_p_fn_vectores [])() __attribute__((section(".vectors"))) = 
{
	(void (*)()) ((uint32)stack_top+ sizeof(stack_top)),
	&Rest_Handler,
	&NMI_Handler,
	&H_Fault_Handler,
	&MM_Fault_Handler,
	&Bus_Fault,
	&Usage_Fault_Handler
};

void Rest_Handler(void)
{
	// copy data from flash to sram
	uint32 Data_size = (uint8*)&_E_Data - (uint8*)&_S_Data ;
	uint8* p_src = (uint8*)&_E_text ;
	uint8* p_dst = (uint8*)&_S_Data ;
	int i ;
	for(i=0 ; i< Data_size ; i++)
	{
		*((uint8*)p_dst++) = *((uint8*)p_src++);
	}
	
	// init bss with zero in sram
	uint32 bss_size = (uint8*)&_E_bss - (uint8*)&_S_bss ;
	p_dst = (uint8*)&_S_bss ;
	for(i=0 ; i< Data_size ; i++)
	{
		*((uint8*)p_dst++) = (uint8)0;
	}
	
	// branch to the main 
	main();
}