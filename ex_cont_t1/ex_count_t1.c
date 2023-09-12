#include <stm32f10x.h>

int main(void)
{
    // Enable clock for GPIOB and TIM2 peripherals
    RCC->APB2ENR |= RCC_APB2ENR_IOPBEN |1<<2;
    RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
    
    // Configure PB0 as input with pull-up
    GPIOB->CRL &= ~GPIO_CRL_MODE0;  // Input mode
    GPIOB->CRL &= ~GPIO_CRL_CNF0;   // Floating input
    GPIOB->CRL |= GPIO_CRL_CNF0_1;  // Input with pull-up
    
		GPIOA->CRL = 0X22222222;
		GPIOA->CRH = 0X22222222;
	
    // Configure TIM2 for external counter mode
    TIM2->CR1 = 0;         // Clear control register 1
    TIM2->SMCR = 0;        // Clear slave mode control register
    TIM2->CCMR1 = 0;       // Clear capture/compare mode register 1
    TIM2->CCER = 0;        // Clear capture/compare enable register
    TIM2->CNT = 0;         // Clear counter register
    TIM2->PSC = 0;         // Set prescaler to 0
    TIM2->ARR = 65535;     // Set auto-reload register to maximum value (16-bit)
    TIM2->SMCR |= TIM_SMCR_SMS_0 | TIM_SMCR_SMS_1 | TIM_SMCR_SMS_2;  // Set external clock mode
    TIM2->SMCR |= TIM_SMCR_TS_0 | TIM_SMCR_TS_2;  // Set trigger input source to TI1FP1
    
    // Enable TIM2 counter
    TIM2->CR1 |= TIM_CR1_CEN;
    
    while (1) {
        // Read current count value
        uint16_t count = TIM2->CNT;
        
        // Do something with the count value, such as update an LED display
        GPIOA->ODR=1<<count;
        // Delay for a short time
//        for (int i = 0; i < 1000000; i++) {
//            // Do nothing, just wait
//        }
    }
}
