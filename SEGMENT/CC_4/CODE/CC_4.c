#include "stm32f10x.h"                  // Device header
#define seg GPIOA->ODR
#define set GPIOA->ODR
#define clear GPIOA->BRR
void delay(char time)
{
	while(time--)
	for(int value=40000;value>0;value--);
}
char display[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
int main()
{
	int i=0;
	char seg0=0,seg1=0,seg2=0,seg3=0;
	RCC->APB2ENR=1<<2;
	GPIOA->CRL=0X22222222;
	GPIOA->CRH=0X00002222;
	while(1)
	{
		i++;
		seg0=i%10;
		seg1=((i%1000)%100)/10;
		seg2=(i%1000)/100;
		seg3=i/1000;
		for(int j=0;j<10;j++)
		{

		set=1<<9|1<<10|1<<11;clear=1<<8;
		seg|=display[seg3];
		delay(1);
		set=1<<8|1<<10|1<<11;clear=1<<9;
		seg|=display[seg2];
		delay(1);
		set=1<<9|1<<8|1<<11;clear=1<<10;
		seg|=display[seg1];
		delay(1);
		set=1<<8|1<<10|1<<9;clear=1<<11;
		seg|=display[seg0];
		delay(1);
		}
	}
}