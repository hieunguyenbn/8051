#include <reg52.h>

void delay();
main() {
	
	TMOD = 0x01;//che do 01-16bit, timer 0, nguon xtal, gate=0. TMOD = 0x02. che do 2-8bit timer 0. 
	P1 = 0x00;
	while(1) {
		P1 = ~P1;
		delay();
	}
}
void delay() {
	
	unsigned char i;
	for (i = 0; i < 12; i++) {
		TH0 = 0xEC;
		TL0 = 0x77; //5000 lan
		TR0 = 1;
	while (!TF0) {};
		TR0 = 0;
		TF0 = 0;
	}
	
}
	