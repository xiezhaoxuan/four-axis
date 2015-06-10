#ifndef _systick_
#define _systick_

#define SysClock   72000000  ///定义系统时钟
#define SysTick_Time 10     //系统时基的时间大小，单位ms

extern unsigned int Global;  //全局时基变量

int SysTick_Init(void);

#endif
