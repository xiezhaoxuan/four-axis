#include "stm32f10x.h"
#include "systemtick.h"

FlagStatus Time10ms_Mark=RESET;   ///10ms时基到标志

FlagStatus Time1S_Mark=RESET;   ///1s时基到标志

uint16_t SystemTick_TimeCount=0;    //在定时器中断中计算总共的时基数，1S清一次零

///////////////////////////////初始化系统时基
void SystemTick_Init(void)
{
	SysTick_Config(SystemCoreClock/SYSTEMTICKFREQUENCY);
}




