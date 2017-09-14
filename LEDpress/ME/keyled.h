#ifndef __KEY_LED_H
#define __KEY_LED_H
#include "stm32f10x.h"
#define KEY_ON 1
#define KEY_OFF 0
u8 Key_Scan(GPIO_TypeDef* GPIOx,u16 GPIO_Pin);
void Key_GPIO_Config();
#endif