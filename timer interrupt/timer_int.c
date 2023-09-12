#include "stm32f10x.h"

void TIMER2_IRQHandler(void)
{
    // your interrupt handler code here
    // for example, toggle an LED on GPIOC pin 13
    GPIOC->ODR ^= GPIO_ODR_ODR13;
    
    // clear interrupt flag
    TIM2->SR &= ~TIM_SR_UIF;
}

int main(void)
{
    // enable clock for GPIOC and alternate function
    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN | RCC_APB2ENR_AFIOEN;
    
    // enable clock for TIM2
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    
    // configure GPIOC pin 13 as output push-pull
    GPIOC->CRH &= ~GPIO_CRH_MODE13; // clear mode bits
    GPIOC->CRH |= GPIO_CRH_MODE13_0; // output mode, max speed 10 MHz
    GPIOC->CRH &= ~GPIO_CRH_CNF13; // clear configuration bits
    GPIOC->CRH |= GPIO_CRH_CNF13_0; // general purpose output push-pull
    
    // configure TIM2 for 1 second period and interrupt
    TIM2->PSC = 7199; // prescaler value for 1 kHz frequency
    TIM2->ARR = 999; // auto-reload value for 1 second period
    TIM2->DIER |= TIM_DIER_UIE; // enable update interrupt
    TIM2->CR1 |= TIM_CR1_CEN; // enable counter
    
    // enable TIM2 interrupt in NVIC
    NVIC_EnableIRQ(TIM2_IRQn);
    
    // main loop
    while (1)
    {
    GPIOC->ODR ^= GPIO_ODR_ODR13;    // your main code here
    }
}
