#include<stm32f10x.h>
void delay(char a)
{
	while(a--)
		for(int j=0;j<65000;j++);
}
void TIMER(char a)
{
	while(a--)
	{
		while(!(TIM2->SR == 1<<0));
			TIM2->SR = 0<<0;
	}
}
int main()
{
	RCC->APB1ENR = 1<<0;
	RCC->APB2ENR = 1<<2;
	GPIOA->CRL =0X80002222;
	TIM2->CR1 = 1<<0;
	TIM2->PSC=5000;
	TIM2->ARR=14400;
	volatile int a;
	while(1)
	{
		if(GPIOA->IDR&GPIO_IDR_IDR7)
		{GPIOA->ODR =1<<0;
		TIMER(2);
	 GPIOA->BRR =1<<0;
		TIMER(2);}
	}
}