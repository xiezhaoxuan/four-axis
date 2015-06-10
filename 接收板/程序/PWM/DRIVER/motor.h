#ifndef _motor_
#define _motor_

typedef enum {
	Motor_Up=0,
	Motor_Down,
	Motor_Left,
	Motor_Right
}Motor_Which;

typedef enum {
	Motor_Off=0,
	Motor_On
}Motor_Option;

///////////////������ų�ʼ��
//////////////�ĸ�����õķֱ���PA0��PA1��PA2��PA3��
//////�涨�� ��������ʱ�������Ƶ���ߵĵ��Ϊ��Ҳ���԰�������оƬ��˵��
//////������оƬ�ϵ���ĸ���������������һ�£������෽����Ʋ⣨�ҡ��ϡ��£�
void Motor_Init(void);

////////////////��ĳ�����ת����ֹͣ
void Motor_Control(Motor_Which Which,Motor_Option Option);

#endif
