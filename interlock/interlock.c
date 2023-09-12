#include<stm32f10x.h>
int main()
{
	RCC->APB2ENR = 1<<4|1<<2;
	GPIOC->CRH = 0X88800022;
	GPIOA->CRL = 0X00088822;
	while(1)
	{
		if(GPIOA->IDR == GPIO_IDR_IDR2)
			GPIOA->ODR = 1<<0;
		if(GPIOA->IDR == GPIO_IDR_IDR3)
			GPIOA->BRR = 1<<0;
		
//		if((GPIOC->IDR==1<<13)&&(GPIOA->ODR&0<<1))
//		{
//			GPIOC->ODR=1<<0;
//		}
//		
//		if((GPIOC->IDR==1<<14)&&(GPIOA->ODR&0<<0))
//		{
//			GPIOC->ODR=1<<1;
//		}
//		
//		if(GPIOC->IDR==1<<15)
//		{
//			GPIOA->BRR=1<<0;
//			GPIOA->BRR=1<<1;
//		}
	}
}
	