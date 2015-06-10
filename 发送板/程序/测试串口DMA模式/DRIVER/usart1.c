#include "config.h"

unsigned char Usart1_Mark=0;

unsigned char Usart1_SendBuffer[100];

DMA_InitTypeDef DMA_Usart1_InitStruct;

int Usart1_Init(void)
{
	USART_InitTypeDef USART_InitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	
	USART_InitStruct.USART_BaudRate=256000;
	USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode=USART_Mode_Rx+USART_Mode_Tx;
	USART_InitStruct.USART_Parity=USART_Parity_No;
	USART_InitStruct.USART_StopBits=USART_StopBits_1;
	USART_InitStruct.USART_WordLength=USART_WordLength_8b;
	USART_Init(USART1,&USART_InitStruct);
	USART_Cmd(USART1,ENABLE);
	
	return 0;
}

int Usart1_SendByte(unsigned char Byte)
{
	while(!USART_GetFlagStatus(USART1,USART_FLAG_TXE));
	USART_SendData(USART1,Byte);
	return 0;
}

int Usart1_DmaInit(void)
{
	
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	
	USART_DMACmd(USART1,USART_DMAReq_Tx,ENABLE);
	
	DMA_Usart1_InitStruct.DMA_BufferSize=100;
	DMA_Usart1_InitStruct.DMA_DIR=DMA_DIR_PeripheralDST;
	DMA_Usart1_InitStruct.DMA_M2M=DMA_M2M_Disable;
	DMA_Usart1_InitStruct.DMA_MemoryBaseAddr=(uint32_t)&Usart1_SendBuffer;
	DMA_Usart1_InitStruct.DMA_MemoryDataSize=DMA_MemoryDataSize_Byte;
	DMA_Usart1_InitStruct.DMA_MemoryInc=DMA_MemoryInc_Enable;
	DMA_Usart1_InitStruct.DMA_Mode=DMA_Mode_Normal;
	DMA_Usart1_InitStruct.DMA_PeripheralBaseAddr=0x40013804;
	DMA_Usart1_InitStruct.DMA_PeripheralDataSize=DMA_PeripheralDataSize_Byte;
	DMA_Usart1_InitStruct.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
	DMA_Usart1_InitStruct.DMA_Priority=DMA_Priority_High;
	
	//DMA_Init(DMA1_Channel5,&DMA_Usart1_InitStruct);
	
	return 0;
}

int Usart1_DmaTransfer(unsigned int MemoryBaseAddr,unsigned char BufferSize)
{
	DMA_Usart1_InitStruct.DMA_MemoryBaseAddr=MemoryBaseAddr;
	DMA_Usart1_InitStruct.DMA_BufferSize=BufferSize;
	DMA_Cmd(DMA1_Channel4,DISABLE);
	DMA_Init(DMA1_Channel4,&DMA_Usart1_InitStruct);
	DMA_Cmd(DMA1_Channel4,ENABLE);
	
	return 0;
}

int Usart1_Process(void)
{
	if(Usart1_Mark==1)
	{
		Usart1_Mark=0;
		//Usart1_SendByte(0x85);
		Usart1_DmaTransfer((uint32_t)&Usart1_SendBuffer,100);
	}
	
	return 0;
}

