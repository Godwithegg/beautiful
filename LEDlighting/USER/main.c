#include "stm32f10x.h"
#include "led.h"
#include "SysTick.h"
int main()
{
	SysTick_Init();
	LED_GPIO_Config();
	LED1(0);
  while(1)
	{
		LED1(1);
		Delay(0x0FFFEF);
		LED1(0);
		Delay(0x0FFFEF);
	}
	
	
}
