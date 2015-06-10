#include "stm32f10x.h"
#include "motor.h"

///////////////������ų�ʼ��
//////////////�ĸ�����õķֱ���PA0(��)��PA1(��)��PA2(��)��PA3(��)��
//////�涨�� ��������ʱ�������Ƶ���ߵĵ��Ϊ��Ҳ���԰�������оƬ��˵��
//////������оƬ�ϵ���ĸ���������������һ�£������෽����Ʋ⣨�ҡ��ϡ��£�
void Motor_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0+GPIO_Pin_1+GPIO_Pin_2+GPIO_Pin_3;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
}


////////////////��ĳ�����ת����ֹͣ
void Motor_Control(Motor_Which Which,Motor_Option Option)
{
	uint16_t WhichPin;
	
	if(Which==Motor_Up)
		WhichPin=GPIO_Pin_3;
	if(Which==Motor_Down)
		WhichPin=GPIO_Pin_1;
	if(Which==Motor_Left)
		WhichPin=GPIO_Pin_0;
	if(Which==Motor_Right)
		WhichPin=GPIO_Pin_2;
	if(Option==Motor_On)
		GPIO_SetBits(GPIOA,WhichPin);
	else
		GPIO_ResetBits(GPIOA,WhichPin);
}

