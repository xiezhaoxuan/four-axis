#include "config.h"

unsigned int Global=0;   //ȫ��ʱ������

/////////////////////////����ϵͳʱ��
int SysTick_Init(void)   
{
	SysTick_Config(SysClock/(1000/SysTick_Time));
	return 0;
}

