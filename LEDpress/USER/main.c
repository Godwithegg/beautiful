#include "stm32f10x.h"
#include "led.h"
#include "SysTick.h"
#include "keyled.h"
#define KEY_ON 1
#define KEY_OFF 0
int main()
{
	SysTick_Init();
	LED_GPIO_Config();
  LED1(ON);
	Key_GPIO_Config();
	while(1)
	{
		if(Key_Scan(GPIOE,GPIO_Pin_5)==KEY_ON)
		{
			GPIO_WriteBit(GPIOC,GPIO_Pin_3,
			(BitAction)((1-GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_3))));
		}
	}
	
}
