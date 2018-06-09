#include "delay.h"
void delay_ms(unsigned int x)
	{
	unsigned int i,j;
	 for(i=0;i<=x;i++)
	 	{
	   	for(j=0;j<=125;j++);
		 }

	}
/*void delay_us(unsigned int x)
{
	   unsigned int i;
	  // x=x/20;
	   //for(i=0;i<=x;i++);
		 //while(x--);//_nop_();
	   for(i=0;i<=x;i++);
}*/ 
/*
void delay_us(unsigned char x)
{
	  // x=x/20;
	   //for(i=0;i<=x;i++);
		 //while(x--);//_nop_();
	   //for(i=0;i<=x;i++);
		x=x/8;
		while(x--);
} 
*/
void delay_us(unsigned int Time)
{
	unsigned int i,j;
	for(i=0;i<Time;i++)
	{
		for(j=0;j<2;j++);
	}
} 
