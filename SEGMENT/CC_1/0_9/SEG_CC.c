#include "stm32f10x.h"                  // Device header
#define seg GPIOA->ODR
char display[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
void delay(char time)
{
	while(time--)
	{
		int value=65000;
		while(value--);
	}
}
int main()
{
	RCC->APB2ENR=1<<2;
	GPIOA->CRL=0X22222222;
	while(1)
	{
		for(int i=0;i<10;i++,delay(10))
		seg=display[i];
	}
}