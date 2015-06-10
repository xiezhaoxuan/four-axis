#include "config.h"

int main(void)
{
	
	SysTick_Init();
	Led_Init();
	Usart1_Init();
	Usart1_DmaInit();
	
	while(1)
	{
		Led_Process();
		Usart1_Process();
	}
}
