#ifndef _systemtick_
#define _systemtick_

#define SYSTEMTICKFREQUENCY 100    ////����ϵͳʱ���Ĳ���Ƶ�ʣ�100��10ms����һ��

extern FlagStatus Time10ms_Mark;   ///10msʱ������־

extern FlagStatus Time1S_Mark;   ///1sʱ������־

extern uint16_t SystemTick_TimeCount;    //�ڶ�ʱ���ж��м����ܹ���ʱ������1S��һ����

///////////////////////////////��ʼ��ϵͳʱ��
void SystemTick_Init(void);

#endif
