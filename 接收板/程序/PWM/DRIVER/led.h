#ifndef _led_
#define _led_

///////////////////////////控制LED的亮灭
#define Led_On() GPIO_ResetBits(GPIOA,GPIO_Pin_15)

#define Led_Off() GPIO_SetBits(GPIOA,GPIO_Pin_15)

////////////////////////LED的初始化,用的是PA15引脚
void Led_Init(void);


#endif
