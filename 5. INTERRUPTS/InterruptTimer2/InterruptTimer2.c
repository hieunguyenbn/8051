#include <reg52.h>
#include "..\..\LIBRARY\delay.h"
sbit led = P0^0;
void delay(unsigned int t) {
	while(t--);
}
unsigned int i;
main() {
	TMOD = 0x10; // TIMER 1 CHE DO 1
	//IE = 0x88; // CHO PHEP NGAT TIMER 1;
	ET1 = 1;
	EA = 1;
	TR1 = 1;
	while(1) {
		P1 = 0;
		delay(15000);
		P1 = 0xFF;
		delay(15000);
	}
}

void ngat(void) interrupt 3 { 
	long a = 50000;
	i++;
	TH1 = 0xFC;
	TL1 = 0x18; // DEM TU 64536 => 65536
	TR1 = 1;
	if (i >= 5000) {
	i = 0;
	led = 0;
	delay_ms(5000);
	led = 1;
	}
	
}
	
	