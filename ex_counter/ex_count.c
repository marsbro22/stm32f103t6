#include<stm32f10x.h>
int main()
{
	RCC->APB1ENR = 1<<0;
	RCC->APB2ENR = 1<<3|1<<2;
	GPIOB->CRH = 0X00000400;
	GPIOA->CRL = 0X22222222;
	GPIOA->CRH = 0X22222222;
	TIM2->PSC = 1;
	TIM2->ARR = 65535;
	TIM2->CR1 = 1<<0; //EN CEN & DIR(U,D) 0-U &CKD 9:8 (1:1,1:2,1:4,RES) 1:1(00)
	TIM2->DIER = 1<<0|1<<3; //ENABLE THE  Update interrupt enable
	TIM2->CCMR2 = 0X0001;  // ENABLE TI3 & SET PRESCALAR =0 AND INPUT CAPTURE FILTER =0
	TIM2->CCER = 0X0300;  // enable capture mode foe ti3 and set 00 in cc3p and cc3np for rising edge 
	uint16_t count=0;
	while(1)
	{
		while(!(TIM2->SR & 1<<3)){}
		
						GPIOA->ODR = 1<<15;
            count++;
            TIM2->SR &= ~TIM_SR_CC3IF;
    //    }
		GPIOA->ODR = 1<<count;
	}
}
