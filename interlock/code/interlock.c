#include "stm32f10x.h"                  // Device header
int main()
{
	RCC->APB2ENR=1<<2;
	GPIOA->CRL=0X88800022;
	while(1)
	{
		if((GPIOA->IDR&1<<6)&&(!(GPIOA->IDR&1<<1)))
			GPIOA->ODR=1<<0;
		if((GPIOA->IDR&1<<7)&&(!(GPIOA->IDR&1<<0)))
			GPIOA->ODR=1<<1;
		if(GPIOA->IDR&1<<5)
			GPIOA->BRR=3;
	}
}