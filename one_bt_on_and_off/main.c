#include<stm32f10x.h>
void delay(int a)
{
	for(;a>0;a--);
}
int main()
{
	RCC->APB2ENR =1<<4;
	GPIOC->CRH=0X88220000;
	while(1)
	{
		if(GPIOC->IDR==0x00006000)
		{
			GPIOC->BRR=1<<13;
			while(GPIOC->IDR==1<<14);
		}
		if(GPIOC->IDR==1<<15)
		{
			GPIOC->ODR=1<<13;
			while(GPIOC->IDR==1<<15);
		}
	}
}