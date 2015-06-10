#include "stm32f10x.h"

unsigned char Usart1_Mark=0;

unsigned char Usart1_SendBuffer[100];


////////////////////////////初始化定时器1，发送和接收都用中断吧
int Usart1_Init(void)
{
	USART_InitTypeDef USART_InitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	
	NVIC_InitTypeDef NVIC_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	USART_InitStruct.USART_BaudRate=115200;
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode=USART_Mode_Rx+USART_Mode_Tx;
	USART_InitStruct.USART_Parity=USART_Parity_No;
	USART_InitStruct.USART_StopBits=USART_StopBits_1;
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStruct);
	USART_Cmd(USART1,ENABLE);
	
	USART_ITConfig(USART1,USART_IT_TXE,ENABLE);
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	NVIC_InitStruct.NVIC_IRQChannel=USART1_IRQn;    //EXIT4_IRQn
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=3;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=0;
	NVIC_Init(&NVIC_InitStruct);
	
	return 0;
}

int Usart1_SendByte(unsigned char Byte)
{
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
	USART_SendData(USART1,Byte);
	return 0;
}


