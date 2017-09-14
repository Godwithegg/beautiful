#include "SysTick.h"
#include "stm32f10x.h"
static __IO u32 TimingDelay;
void SysTick_Init()
{
	if(SysTick_Config(SystemCoreClock/100000))
	{
		while(1);
	}
	SysTick->CTRL &=~SysTick_CTRL_ENABLE_Msk;
}
void Delay(__IO u32 nCount)
{
	for(;nCount!=0;nCount--);
}
void TimingDelay_Decrement(void)
{
	if(TimingDelay!=0)
	{ 
		TimingDelay--;
	}
}