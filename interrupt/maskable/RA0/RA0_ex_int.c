#include<stm32f10x.h>
void delay(char a)
{
	while(a--)for(int i=0;i<=65000;i++);
}
int main()
{
	RCC->APB2ENR|=1<<3|1<<2;
	GPIOA->CRL = 0X22222222;
	GPIOB->CRL = 0X00888888;
	__disable_irq();
	AFIO->EXTICR[0]=AFIO_EXTICR1_EXTI0_PB|AFIO_EXTICR1_EXTI1_PB|AFIO_EXTICR1_EXTI2_PB |AFIO_EXTICR2_EXTI4_PB |AFIO_EXTICR2_EXTI5_PB;
	EXTI->IMR =0X00000037;
	EXTI->RTSR=EXTI_RTSR_TR0 | EXTI_RTSR_TR1 |EXTI_RTSR_TR2| EXTI_RTSR_TR4| EXTI_RTSR_TR5;
	NVIC_EnableIRQ(EXTI0_IRQn);
	NVIC_EnableIRQ(EXTI1_IRQn);
	NVIC_EnableIRQ(EXTI2_IRQn);
	NVIC_EnableIRQ(EXTI4_IRQn);
	NVIC_EnableIRQ(EXTI9_5_IRQn);	
	NVIC_SetPriority(EXTI0_IRQn, 0);
	NVIC_SetPriority(EXTI1_IRQn, 1);
	NVIC_SetPriority(EXTI2_IRQn, 2);
	NVIC_SetPriority(EXTI4_IRQn, 3);
	NVIC_SetPriority(EXTI9_5_IRQn, 4);	
	__enable_irq();
while(1)
{
	GPIOA->ODR = 1<<6;
	delay(20);
	GPIOA->BRR = 1<<6;
	delay(20);
}
}
void EXTI0_IRQHandler()
{
	if(EXTI->PR&EXTI_PR_PR0)
	{
		while(1)
		{
	GPIOA->ODR = 1<<0;
	delay(20);
	GPIOA->BRR = 1<<0;
	delay(20);
		EXTI->PR|=EXTI_PR_PR0;
		}
	}
}
void EXTI1_IRQHandler()
{
	if(EXTI->PR&EXTI_PR_PR1)
	{
		while(1)
		{
	GPIOA->ODR = 1<<1;
	delay(20);
	GPIOA->BRR = 1<<1;
	delay(20);
		EXTI->PR|=EXTI_PR_PR1;
	 }
 }	
}
void EXTI2_IRQHandler()
{
	if(EXTI->PR&EXTI_PR_PR2)
	{
		while(1)
		{
	GPIOA->ODR = 1<<2;
	delay(20);
	GPIOA->BRR = 1<<2;
	delay(20);
		EXTI->PR|=EXTI_PR_PR2;
		}
	}
}
void EXTI4_IRQHandler()
{
	if(EXTI->PR&EXTI_PR_PR4)
	{
		while(1)
		{
	GPIOA->ODR = 1<<3;
	delay(20);
	GPIOA->BRR = 1<<3;
	delay(20);
		EXTI->PR|=EXTI_PR_PR4;
		}
	}
}