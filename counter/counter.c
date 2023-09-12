#include "stm32f10x.h"

int main(void)
{
    // Enable clock for timer 2
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
		RCC->APB2ENR =1<<2;
		GPIOA->CRL=0X22222228;

    // Set prescaler value to 72 - timer clock is now 1 MHz
    TIM2->PSC = 71;

    // Configure timer 2 as a counter
    TIM2->CR1 &= ~TIM_CR1_DIR; // count up   //ok
    TIM2->CR1 &= ~TIM_CR1_CKD; // clock division 1
    TIM2->CR1 &= ~TIM_CR1_CMS; //edge-aligned mode  //ok
    TIM2->ARR = 0xFFFF; // max auto-reload value

    // Enable capture/compare channel 1 as input
    TIM2->CCER &= ~TIM_CCER_CC1E; // disable channel 1
    TIM2->CCMR1 &= ~TIM_CCMR1_CC1S; // select input TI1
    TIM2->CCER |= TIM_CCER_CC1P; // capture on falling edge
    TIM2->CCER |= TIM_CCER_CC1E; // enable channel 1

    // Enable timer 2
    TIM2->CR1 |= TIM_CR1_CEN;   //bit 0

    while (1)
    {
        // Read the current counter value
        uint16_t count = TIM2->CNT;
			
			  GPIOA->ODR = 1<<count;

        // Do something with the count value

        // Reset the counter if desired
        //TIM2->CNT = 0;
    }
}