#include "config.h"

int main(void)
{
	
	//SysTick_Init();
	Led_Init();
	Usart1_Init();
	
	while(1)
	{
		Led_Process();
	}
}
