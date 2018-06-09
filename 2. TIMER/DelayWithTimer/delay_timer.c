#include<reg52.h>
sbit button = P3^0;
void delay();

main() {
	TMOD = 0x01;//timer 0, mode 1-16bit
	while(1) {
		unsigned char i;
		P1 = 0xFF;
		P2 = 0xF0;
		if (button == 1) {
		for (i = 0; i < 8; i++) {
			delay();
			P1 <<= 1;
			delay();
		}
		}
		else {
		for (i = 0; i < 20; i++) {
			delay();
			P2 = ~P2;
			delay();
			if (button == 0) break;
		}
		}
	}
	
}

void delay() {
	unsigned int i;
	for (i = 0; i < 200; i++) {
	TL0 = 0x17;
	TH0 = 0xfc;
	TR0 = 1;
	while(!TF0) {}
	TR0 = 0;
	TF0 = 0;
	}
}
