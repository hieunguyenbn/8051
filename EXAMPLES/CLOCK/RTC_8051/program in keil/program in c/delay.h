
#ifndef __DELAY_H
#define __DELAY_H







void Delay_ms(long int k)
{
		int i;
	TMOD=0X02;
	TH0=0x00;
	while(k!=0)
	{
		for(i=0;i<4;i++){
		TR0=1;
		while(!TF0);
		TF0=0;}
		k--;
	}
}  

void Delay_us(long int k)
{
	int i;
	TMOD=0X02;
	TH0=256-k;
	TR0=1;
	while(!TF0);
	TF0=0;
}  





#endif