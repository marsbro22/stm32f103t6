#include "stm32f10x.h"
#include<stdio.h>
#define RS 1<<14  //PORTC
#define EN 1<<15
uint16_t ADCValue;
void ADC1_Init(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN; // Enable ADC1 clock
    ADC1->CR2 |= ADC_CR2_CAL; // Calibrate ADC1
    while((ADC1->CR2 & ADC_CR2_CAL) != 0); // Wait for calibration to complete
    ADC1->CR2 |= ADC_CR2_ADON; // Enable ADC1
}

uint16_t ADC1_Read(void)
{
    ADC1->CR2 |= ADC_CR2_ADON; // Enable ADC1
    ADC1->CR2 |= ADC_CR2_SWSTART; // Start conversion
    while((ADC1->SR & ADC_SR_EOC) == 0); // Wait for conversion to complete
    return ADC1->DR; // Return converted value
}

void LCD_Init(void)
{
    RCC->APB2ENR |= 1<<2|1<<4;
	  GPIOA->CRL=0X00002222;
	  GPIOC->CRH=0X22200000;
}


void delay(int a)	
{
	  int i,j;
		for(i=0;i<a;i++)
	  for(j=0;j<65000;j++);
}
void pulse()
{
	GPIOC->ODR |=EN;
	delay(1);
	GPIOC->BRR |=EN;
	delay(1);
}
void cmd(char a)
{
	GPIOA->BRR =0X000000FF;
	GPIOC->BRR |=RS;
	GPIOA->ODR |=(a&0xf0)>>4;
	pulse();  
	
	GPIOA->BRR =0X000000FF;
	GPIOC->BRR |=RS;
	GPIOA->ODR |=(a&0x0f);
	pulse();
}

 
void data(char a)
{
	GPIOA->BRR =0X000000FF;
	GPIOC->ODR |=RS;
	GPIOA->ODR |=(a&0xf0)>>4;
	pulse();
	
	GPIOA->BRR =0X000000FF;
	GPIOC->ODR |=RS;
	GPIOA->ODR |=(a&0x0f);
	pulse();
}

void string(char *str)
{
	while(*str)
	{
	data(*str++);
	}
}

void LCD_Print(uint16_t data)
{
    char str[16];
    sprintf(str, "%d", data); // Convert data to string
   string(str);
}

int main(void)
{
    //LCD_Init();
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN; // Enable GPIOA clock
    GPIOA->CRL &= ~GPIO_CRL_CNF7; // Set A0 to analog input
    ADC1_Init(); // Initialize ADC1
    LCD_Init(); // Initialize LCD
    
    while(1)
    {
        ADCValue = ADC1_Read(); // Read ADC value
        LCD_Print(ADCValue); // Print ADC value on LCD
    }
}