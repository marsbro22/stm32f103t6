#include "stm32f10x.h"                  // Device header
int main()
{
	RCC->APB2ENR=1<<2;
	GPIOA->CRL=0x80000002;
	while(1)
	{
		if(GPIOA->IDR&1<<7)
		{
			GPIOA->ODR=1<<0;
		}
		if(!(GPIOA->IDR&1<<7))
		{
			GPIOA->BRR=1<<0;
		}
	}
}