#include <at89x52.h>

#define data_led7 P1

#define Aled1  	P3_0
#define Aled2  	P3_1
#define Aled3  	P3_2
#define Aled4  	P3_3

#define key		P3_7
unsigned char led1,led2,led3,led4;
bit flag;
int count;

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
	int i;
	for(i=0;i<t;i++)
	delay_1ms();
}

void delay_us(int x) {
int i;
for (i=0;i<x;i++) {}
}

void convert_bcd( int x)
{
int temp2;
	temp2 = x;
	led4 	= temp2 / 1000;
	temp2	= temp2 % 1000;
	led3 	= temp2 / 100;
	temp2 	= temp2 % 100;
	led2 	= temp2 / 10;
	led1 	= temp2 % 10;
}

//-----------HIEN THI LED--------------
void display()
{
unsigned char code maled7[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,
							   0x88,0x83,0xC6,0xA1,0x86,0x8E,0xFF};

	data_led7 = maled7[led1];   Aled1 = 0; delay_us(50); if(key==0) flag = 1;  Aled1 = 1;
	data_led7 = maled7[led2]; 	Aled2 = 0; delay_us(50); Aled2 = 1;
	data_led7 = maled7[led3]; 	Aled3 = 0; delay_us(50); Aled3 = 1;
	data_led7 = maled7[led4]; 	Aled4 = 0; delay_us(50); Aled4 = 1;
}

void main()
{
unsigned char dem;
P1 = 0xff;
P3 = 0xff;
count = 0;
convert_bcd(count);

	while(1) 
	{
		convert_bcd(dem);
		display();
	//	while (key);
	//	while (!key);
		if (flag == 1) {flag = 0;count++;}
		if (count == 15) {dem++;count = 0;}

	}
}