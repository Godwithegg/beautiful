#ifndef __LED_H
#define __LED_H
#include "stm32f10x.h"
#define ON 0
#define OFF 1
#define LED1(a) if(a)\
	GPIO_SetBits(GPIOB,GPIO_Pin_0);\
else\
  GPIO_ResetBits(GPIOB,GPIO_Pin_0);
void LED_GPIO_Config();
#endif
