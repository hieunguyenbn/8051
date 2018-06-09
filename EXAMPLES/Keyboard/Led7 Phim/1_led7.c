#include <at89x52.h>

#define data_led7 P1

#define Aled1  	P3_0
#define Aled2  	P3_1
#define Aled3  	P3_2
#define Aled4  	P3_3

#define key		P3_7
unsigned char led1,led2,led3,led4;

void delay_1ms(){
	TH1=0xFB;
	TL1=0x00;
	TR1=1;
	while(1){
	if(TF1==1) break;
	}
	TR1=0;
	TF1=0;
}
void delay(unsigned char t){
	unsigned char i;
	for(i=0;i<t;i++)
	delay_1ms();
}


void main()
{
unsigned char code maled7[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,
							   0x88,0x83,0xC6,0xA1,0x86,0x8E,0xFF};
int count;

P1 = 0xff;
P3 = 0xff;
count = 0;

	while(1) 
	{
		data_led7 = maled7[count];
		delay(100);
		while (key);
		while (!key);
		count++;
		if (count == 16) count = 0;
	}
}