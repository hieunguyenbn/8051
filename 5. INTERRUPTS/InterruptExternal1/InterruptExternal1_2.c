// NGAT THEO SUON
#include <reg52.h>
#include "..\..\LIBRARY\delay.h"

sbit button = P2^0;
sbit led = P0^0;
void delay(unsigned int t) {
	while (t--) {
		TH0 = 0xFC;
		TL0 = 0x18;
		TR0 = 1;
		while(TF0 = 0);
		TF0 = 0;
		TR0 = 0;
	}
}
	
main() {
	EX0 = 1; //NGAT NGOAI 0
	IT0 = 1; // NGAT THEO SUON
	EA = 1; //CHO NGAT TOAN BO
	while (1) {
		P1 = 0;
		delay(100000);
		P1 = 0xFF;
		delay(100000);
	}
}

void ExternalInterrupt(void) interrupt 0 {
	led = 0;
	delay_ms(5000); //delay 5s
	led = 1;
}