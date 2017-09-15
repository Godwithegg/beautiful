#include "stm32f10x.h"
#include "led.h"
#include "SysTick.h"
#define GPIOB_ODR_Addr (GPIOB_BASE+0x0C)
#define PBout(n) *(unsigned int *)((GPIOB_ODR_Addr & 0xF0000000)+0x02000000+((GPIOB_ODR_Addr&0x00FFFFFF)<<5)+(n<<2)) 
#define GPIOA_INR_Addr (GPIOA_BASE+0x08)
#define PAin(n)  *(unsigned int *)((GPIOA_INR_Addr & 0xF0000000)+0x02000000+((GPIOB_INR_Addr&0x00FFFFFF)<<5)+(n<<2))
int main()
{
	SysTick_Init();
	LED_GPIO_Config();
	while(1)
	{
		PBout(0)=1;
  	Delay(0x00FFFEF);
		PBout(0)=0;
		Delay(0x00FFFEF);
	}
}
