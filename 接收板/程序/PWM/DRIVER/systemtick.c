#include "stm32f10x.h"
#include "systemtick.h"

FlagStatus Time10ms_Mark=RESET;   ///10msʱ������־

FlagStatus Time1S_Mark=RESET;   ///1sʱ������־

uint16_t SystemTick_TimeCount=0;    //�ڶ�ʱ���ж��м����ܹ���ʱ������1S��һ����

///////////////////////////////��ʼ��ϵͳʱ��
void SystemTick_Init(void)
{
	SysTick_Config(SystemCoreClock/SYSTEMTICKFREQUENCY);
}




