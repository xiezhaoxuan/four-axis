#include "stm32f10x.h"
#include "led.h"


////////////////////////LED的初始化,用的是PA15引脚
////////////////////////PA15本属于JTAG调试引脚，所以要先禁用JTAG
void Led_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable,ENABLE);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_15;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
}
