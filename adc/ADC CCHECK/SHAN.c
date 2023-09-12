//TIMER INTERRUPT WRKG..........
#include "stm32f10x.h"
void delay(unsigned int a)
{
	int i,j;
	for(i=0;i<a;i++)
	for(j=0;j<65000;j++);
}
void  TIM2_IRQHandler()
//void timer()
{
	
	if(TIM2->SR &TIM_SR_UIF)
	{
	GPIOC->ODR ^=1<<13;
	TIM2->SR &=~TIM_SR_UIF;
	}
}
void timer_init()
{
	TIM2->PSC=10000-1;              //Setting Prescalar value as 10000
	TIM2->ARR=7200-1;               //auto re-load register value
	TIM2->CNT=0;   		             // COUNTER CLEAR
	//TIM2->CR1=0X00000001;          // COUNTER ENABLE  setting in data sheet
}
int main(void)
{
	RCC->APB2ENR|=1<<2|1<<4|1<<0;   //PORTA CLK ENABLE
	RCC->APB1ENR |=1<<0; //ENABLE THE CLOCK OF TIMER

	GPIOA->CRL =0X00000222; //OUTPUT 
	GPIOC->CRH=0X00200000; //OUTPUT
	timer_init();
	__disable_irq();
	TIM2->DIER =TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);
	__enable_irq();
	TIM2->CR1=0X00000001; 
	while(1)
	{
		//timer();
//		GPIOA->ODR =1<<1;
//		delay(20);
//		GPIOA->BRR =1<<1;
//		delay(20);
	}
}