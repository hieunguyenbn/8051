
#include<reg52.h>
sbit BUTTON1        = P2^0;
sbit BUTTON2        = P2^1;
sbit LED    = P0^0; 
sbit L7S1   = P2^6;
sbit L7S2   = P2^7;
unsigned char LED7SEG[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
void Delay_ms(unsigned int t)
{    
unsigned int x,y;
      for(x=0;x<t;x++)
      {
         for(y=0;y<123;y++);
      }   
}
void Delay( int i ){
				L7S1 = 0;
				L7S2 = 1;
				P1 = LED7SEG[i%10];
				Delay_ms(10);
				L7S2 = 0;
				L7S1 = 1;
				P1 = LED7SEG[i/10];
				Delay_ms(10);
}
 main ()
{
	int i = 0;
	P1 = LED7SEG[0];
	LED = 0xFF;
	while(1){
		Delay(i);
		if(BUTTON1  ==  0){
			while(BUTTON1 == 0)
			{
				Delay(i);
			}
			i++;
			Delay(i);
			LED = 0x00;
			if(i > 99){
				i = 99;
			}
			}
	if(BUTTON2 ==  0){
			while(BUTTON2 == 0){
				Delay(i);
		}
			i--;
			Delay(i);
			LED = 0xFF;
			if( i < 0 ) {
				i = 0;
			}
			}
		if((i>0) && (i%5 == 0)){
				LED  = 0xFF;
				Delay_ms(10);
				LED = 0x00;
		}
	}

}