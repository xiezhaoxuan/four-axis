#include "stm32f10x.h"
#include "motor.h"
#include "SystemTick.h"
#include "led.h"

int main(void)
{
	Led_Init();
	//Motor_Init();
	SystemTick_Init();
	
	
	//Motor_Control(Motor_Up,Motor_On);
	//Motor_Control(Motor_Down,Motor_On);
	while(1)
	{
		if(Time1S_Mark==SET)
		{
			Time1S_Mark=RESET;
			if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_15))
				Led_On();
			else
				Led_Off();
		}
	}
	
	return 0;
}
