#ifndef _led_
#define _led_

///////////////////////////����LED������
#define Led_On() GPIO_ResetBits(GPIOA,GPIO_Pin_15)

#define Led_Off() GPIO_SetBits(GPIOA,GPIO_Pin_15)

////////////////////////LED�ĳ�ʼ��,�õ���PA15����
void Led_Init(void);


#endif
