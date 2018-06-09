#include<reg52.h>

sbit button = P3^0;
void Delay() {
	unsigned int i;
	for (i = 0; i < 200; i++) {
	TL0 = 0x17;
	TH0 = 0xFC;
	TR0 = 1;
	while(!TF0);
		TR0 = 0;
		TF0 = 0;
	}
}
//void delay();
main() {
	unsigned char i, j;
	TMOD = 0x01;
	
	/*TMOD = 0x02;//timer0-mode2-8bit
	TL0 = 0xFE;
	TH0 = 0x00;*/

	while(1) {
	do {
		P1 = 0xFF;
		for (j = 1; j <= 8; j++) {
				Delay();
				P1 >>= 1;
				//if (button == 0) goto loop;
			}
	}while(button==1);
	//loop:;
	P2 = 0xFF;
	for (i = 0; i < 20; i++) {
			Delay();
			P2 = ~P2;
		if (button == 0) break;
	}
	}		
}

/*void delay() {
	unsignedint i;
	for (i = 0; i < 800; i++) {
		TR0 = 1;
		while(!TF0);
		TR0 = 0;
		TF0 = 0;
	}
}*/