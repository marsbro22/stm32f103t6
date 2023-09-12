#include<stm32f10x.h>
void delay(int a)
{
	
	while(a--){int j=65000;while(j--);}
}
int main()
{
	RCC->APB2ENR = 1<<4;     // clock gpioc set enable
	GPIOC->CRL = 0X00000000;
	GPIOC->CRH = 0X08600000;
	while(1)
	{
		if(GPIOC->IDR == 1<<14)
		{
		GPIOC->ODR = 1<<13;
		delay(11);
		GPIOC->BRR = 1<<13;
		delay(11);
			while(GPIOC->IDR == 1<<14);
		}
	}
}