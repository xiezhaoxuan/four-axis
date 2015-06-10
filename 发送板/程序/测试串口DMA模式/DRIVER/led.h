#ifndef _led_
#define _led_

#define Led_Gpio GPIOB
#define Led_Pin  GPIO_Pin_12 

extern unsigned char Led_Mark;

int Led_Init(void);
int Led_Process(void);

#endif
