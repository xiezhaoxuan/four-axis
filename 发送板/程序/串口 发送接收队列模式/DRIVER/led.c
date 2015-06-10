#include "config.h"

unsigned char Led_Mark=0;   

int Led_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_SetBits(Led_Gpio,Led_Pin);
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=Led_Pin;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_2MHz;
	GPIO_Init(Led_Gpio,&GPIO_InitStruct);
	
	return 0;
}

int Led_Process(void)
{
	if(Led_Mark==1)
		{
			Usart1_SendByte(0x55);
			Led_Mark=0;
			if(GPIO_ReadOutputDataBit(Led_Gpio,Led_Pin))
				GPIO_ResetBits(Led_Gpio,Led_Pin);
			else
				GPIO_SetBits(Led_Gpio,Led_Pin);
		}
	return 0;
}
