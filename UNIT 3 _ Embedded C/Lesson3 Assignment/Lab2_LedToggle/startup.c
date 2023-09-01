/* startup.c file 
Eng. Abdullah karkour
*/
#include"Platform_Types.h"
#define SP   0x20001000

extern int main(void); // decleration of main function

// addresses of start and End of data and bss
extern uint32 _stack_top;
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

// Vectors Table 
uint32 Vectors[] __attribute__((section(".vectors"))) = 
{
	(uint32) &_stack_top,
	(uint32) &Rest_Handler,
	(uint32) &NMI_Handler,
	(uint32) &H_Fault_Handler,
	(uint32) &MM_Fault_Handler,
	(uint32) &Bus_Fault,
	(uint32) &Usage_Fault_Handler
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