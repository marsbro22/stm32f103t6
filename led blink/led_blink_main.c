#include<stm32f10x.h>
void delay(int a)
{
	while(a--)
	for(int j=65000;j>0;j--);
}
int main(void)
{
	RCC->CR=0X83;
	RCC->CFGR=0X00;
	RCC->APB2ENR|= 1<<2 |1<<4 |1<<3;
	GPIOA->CRH = 0x22222222;
	GPIOA->CRL = 0x22222222;
	GPIOC->CRH = 0x22222222;
	GPIOC->CRL = 0x22222222;
	GPIOB->CRH = 0x22222222;
	GPIOB->CRL = 0x22222222;
	while(1)
	{
		GPIOC->ODR =0x0000FFFF;
		GPIOA->ODR =0x0000FFFF;     //A15 B4 B3
		GPIOB->ODR =0x0000FFFF;
		delay(10);
		GPIOA->BRR =0x0000FFFF;
		GPIOB->BRR =0x0000FFFF;
		GPIOC->BRR =0x0000FFFF;
		delay(10);
	}
}