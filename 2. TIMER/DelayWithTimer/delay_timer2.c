#include<reg52.h>
sbit button = P3^0;

void delay(void);

main() {
	unsigned char i, j, a[8] = {0xE7,0xDB,0xBD,0x7E,0x7E,0xBD,0xDB,0xE7};
	TMOD = 0x20;//timer1, mode2-8bit
	TL1 = 0xFE;
	TH1 = 0x00;
	loop:;
	while(1) {
		
		if (button == 1) 
		for (i = 0; i < 8; i++) {
			P1 = a[i];
			delay();
			if (button == 0) break;
		}
		else
		for (j = 0; j < 10; j++){
			for (i = 0; i < 8; i++) {
				P2 = a[i];
				delay();
				if (button == 0) goto loop;
			}
		}
	}
}
void delay(void) {
	unsigned int i;

	for (i = 0; i < 800; i++) {
	TR1 = 1;
	while(!TF1){}
	TR1 = 0;
	TF1 = 0;
	}
}