#include "stm32f10x.h"

int main(void)
{
    // Enable GPIOB clock
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;        //PORT B

    // Configure PB10 as input floating
    GPIOB->CRH &= ~GPIO_CRH_CNF10;
    GPIOB->CRH &= ~GPIO_CRH_MODE10;

    // Enable Timer 2 clock
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;

    // Set the prescaler to 7200 (1 us per count)
    TIM2->PSC = 7200 - 1;

    // Set the auto-reload register to 20000 (2 seconds)
    TIM2->ARR = 20000 - 1;

    // Set the counter mode to up-counting
    TIM2->CR1 &= ~TIM_CR1_DIR;

    // Set the clock division to no division
    TIM2->CR1 &= ~TIM_CR1_CKD;

    // Configure TIM2 channel 3 for input capture on PB10
    TIM2->CCER &= ~TIM_CCER_CC3P;
    TIM2->CCER &= ~TIM_CCER_CC3NP;
    TIM2->CCER |= TIM_CCER_CC3E;
    TIM2->CCMR2 &= ~TIM_CCMR2_CC3S;  //..
    TIM2->CCMR2 |= TIM_CCMR2_CC3S_0; //..
    TIM2->CCMR2 &= ~TIM_CCMR2_IC3F;  //
    TIM2->CCMR2 &= ~TIM_CCMR2_IC3PSC;

    // Enable the update event interrupt
    TIM2->DIER |= TIM_DIER_UIE;

    // Enable TIM2
    TIM2->CR1 |= TIM_CR1_CEN;

    // Wait for 10 rising edges on PB10
    uint16_t count_value = 0;
    while(count_value < 10)
    {
        if((TIM2->SR & TIM_SR_CC3IF) != 0)
        {
            count_value++;
            TIM2->SR &= ~TIM_SR_CC3IF;
        }
    }

    // Disable TIM2
    TIM2->CR1 &= ~TIM_CR1_CEN;

    // Infinite loop
    while(1)
    {
        // Toggle LED on PB12 (connected to STM32F103C8T6 development board)
        GPIOB->ODR ^= GPIO_ODR_ODR12;
        // Delay for 2 seconds (approximately)
        for(int i = 0; i < 2000000; i++);
    }
}
