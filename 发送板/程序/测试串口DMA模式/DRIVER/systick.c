#include "config.h"

unsigned int Global=0;   //全局时基变量

/////////////////////////设置系统时基
int SysTick_Init(void)   
{
	SysTick_Config(SysClock/(1000/SysTick_Time));
	return 0;
}

