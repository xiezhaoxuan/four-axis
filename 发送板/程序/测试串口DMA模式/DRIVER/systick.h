#ifndef _systick_
#define _systick_

#define SysClock   72000000  ///����ϵͳʱ��
#define SysTick_Time 10     //ϵͳʱ����ʱ���С����λms

extern unsigned int Global;  //ȫ��ʱ������

int SysTick_Init(void);

#endif
