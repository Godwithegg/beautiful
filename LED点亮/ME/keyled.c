#include "stm32f10x.h"
#include "SysTick.h"
#define KEY_OFF 0
#define KEY_ON 1
void Key_GPIO_Config()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
}
u8 Key_Scan(GPIO_TypeDef* GPIOx,u16 GPIO_Pin)
{
	if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON)//press yes
	{
		Delay(50000);
		if(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON)
		{
			while(GPIO_ReadInputDataBit(GPIOx,GPIO_Pin)==KEY_ON);
		  return KEY_ON;
		}
		else return KEY_OFF;
	}
	else return KEY_OFF;
}