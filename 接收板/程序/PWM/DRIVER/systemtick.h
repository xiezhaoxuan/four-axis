#ifndef _systemtick_
#define _systemtick_

#define SYSTEMTICKFREQUENCY 100    ////定义系统时基的产生频率，100即10ms产生一次

extern FlagStatus Time10ms_Mark;   ///10ms时基到标志

extern FlagStatus Time1S_Mark;   ///1s时基到标志

extern uint16_t SystemTick_TimeCount;    //在定时器中断中计算总共的时基数，1S清一次零

///////////////////////////////初始化系统时基
void SystemTick_Init(void);

#endif
