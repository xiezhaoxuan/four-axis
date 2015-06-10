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

///////////////电机引脚初始化
//////////////四个电机用的分别是PA0、PA1、PA2、PA3口
//////规定： 俯视四轴时，最靠近射频天线的电机为左（也可以按陀螺仪芯片来说，
//////陀螺仪芯片上的字母和四轴的上下左右一致），其余方向可推测（右、上、下）
void Motor_Init(void);

////////////////让某个电机转动或停止
void Motor_Control(Motor_Which Which,Motor_Option Option);

#endif
