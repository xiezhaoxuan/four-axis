#ifndef _usart_
#define _usart_

extern unsigned char Usart1_Mark;

int Usart1_Init(void);
int Usart1_SendByte(unsigned char Byte);
int Usart1_Process(void);

int Usart1_DmaInit(void);
int Usart1_DmaTransfer(unsigned int Memory_BaseAddr,unsigned char BufferSize);

#endif

