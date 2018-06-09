#include <at89x52.h>

#define data_led7 P0
#define Aled1  	P2_0
#define Aled2  	P2_1
#define Aled3  	P2_2
#define Aled4  	P2_3

#define key		P3_7
unsigned char led1,led2,led3,led4;
unsigned char code maled7[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void timer_isr (void)  interrupt 1  using 1  
{
	TH0 = 0xFE;  // reload timer 0 with 0FE0BH
        TL0 = 0x0B;
}

void delay_us(unsigned int x) {
unsigned int i;
for (i=0;i<x;i++) {}
}

void convert_bcd(unsigned int temp2)
{
	led4 	= temp2 % 10;
	temp2	= temp2 / 10;
	led3 	= temp2 % 10;
	temp2 	= temp2 / 10;
	led2 	= temp2 % 10;
	led1 	= temp2 / 10;
}

//-----------HIEN THI LED--------------
void display()
{
	data_led7 = maled7[4]; 	Aled1 = 0; delay_us(50); Aled1 = 1;
	data_led7 = maled7[3]; 	Aled2 = 0; delay_us(50); Aled2 = 1;
	data_led7 = maled7[2]; 	Aled3 = 0; delay_us(50); Aled3 = 1;
	data_led7 = maled7[1];  Aled4 = 0; delay_us(50); Aled4 = 1;
}

void main()
{
int San_pham;

// Chèn ?oa.n kho+?i ta.o cho cho Timer vào ?ây
//  EA = 1;
 // ET0 = 1;  // or IE |= 0x82;   /* set bit EA and Timer0 enable */ 
//  TMOD |= 0x01; /* timer 0 run 16 bit counter */
//  TH0 = 0xFE;TL0 = 0x0B;
//  TR0 = 1; //or TCON |= 0x10; /* run timer 0 */

////////////////////////////////
P1 = 0xff;
P2 = 0xff;
P0 = 0;
P3 = 0xff;
San_pham= 0;
convert_bcd(San_pham);
display();
	while(1) 
	{
       // San_pham = 65535 - (TH0*255+TL0);
//		convert_bcd(200);
		display();
	}
}