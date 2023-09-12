#include<stm32f10x.h>
void delay(char);
int keypad();
int main()
{
	RCC->APB2ENR = 1<<2 |1<<3 |1<<4;
	GPIOA->CRL = 0X22222222;
	GPIOA->CRH = 0X22222222;
	GPIOB->CRL = 0X22222222;
	GPIOC->CRH = 0X88888888;
	int j;
	while(1)
	{
		
		keypad();
	}
}
void delay(char a)
{
	while(a--)
	for(int j;j<65000;j++);
}
int keypad()
{
	while(1)
	{
		GPIOB->ODR=1<<0;
		if(GPIOC->IDR==1<<13)
			GPIOA->ODR = 1<<3;
		if(GPIOC->IDR==1<<14)
			GPIOA->ODR = 1<<4;
		if(GPIOC->IDR==1<<15)
			GPIOA->ODR = 1<<5;
		while((GPIOC->IDR==1<<13)||(GPIOC->IDR==1<<14)||(GPIOC->IDR==1<<15));
		delay(1);
		
		GPIOB->ODR=1<<1;
		if(GPIOC->IDR==1<<13)
			GPIOA->ODR = 1<<6;
		if(GPIOC->IDR==1<<14)
			GPIOA->ODR = 1<<7;
		if(GPIOC->IDR==1<<15)
			GPIOA->ODR = 1<<8;
		while((GPIOC->IDR==1<<13)||(GPIOC->IDR==1<<14)||(GPIOC->IDR==1<<15));
		delay(1);
		
		GPIOB->ODR=1<<2;
		if(GPIOC->IDR==1<<13)
			GPIOB->ODR = 1<<9;
		if(GPIOC->IDR==1<<14)
			GPIOB->ODR = 1<<10;
		if(GPIOC->IDR==1<<15)
			GPIOB->ODR = 1<<11;
		delay(1);
		
		GPIOB->ODR=1<<3;
		if(GPIOC->IDR==1<<13)
			GPIOA->ODR = 1<<12;
		if(GPIOC->IDR==1<<14)
			GPIOA->ODR = 1<<13;
		if(GPIOC->IDR==1<<15)
			break;
		while((GPIOC->IDR==1<<13)||(GPIOC->IDR==1<<14)||(GPIOC->IDR==1<<15));
		//			GPIOA->ODR = 1<<14;
	}
	return 0;
}