#include "stm32f10x.h"                  // Device header
void delay(char loop){
	
	while(loop--)
	{
		int count=65000;
		while(count--);
	}
}
//void delay(int a)
//{
//	while(a--)
//	for(int j=65000;j>0;j--);
//}
int main(void)
{
	RCC->APB2ENR|=7<<2;
	GPIOA->CRL=GPIOB->CRL=GPIOC->CRL=22222222;
	GPIOA->CRH=GPIOB->CRH=GPIOC->CRH=22222222;
	while(1){
		GPIOA->ODR=GPIOB->ODR=GPIOC->ODR=0X0000FFFF;
		delay(10);
		GPIOA->BRR=GPIOB->BRR=GPIOC->BRR=0X0000FFFF;
		delay(10);
			GPIOC->ODR=1<<13;
	}
	
}