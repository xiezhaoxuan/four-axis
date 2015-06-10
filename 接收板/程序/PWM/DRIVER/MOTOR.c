#include "stm32f10x.h"
#include "motor.h"

///////////////电机引脚初始化
//////////////四个电机用的分别是PA0(左)、PA1(下)、PA2(右)、PA3(上)口
//////规定： 俯视四轴时，最靠近射频天线的电机为左（也可以按陀螺仪芯片来说，
//////陀螺仪芯片上的字母和四轴的上下左右一致），其余方向可推测（右、上、下）
void Motor_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_0+GPIO_Pin_1+GPIO_Pin_2+GPIO_Pin_3;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_10MHz;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
}


////////////////让某个电机转动或停止
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

