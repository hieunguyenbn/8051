#include<reg52.h>
sbit button = P3^0;

void delay();
main() {

	unsigned char i, j;
	TMOD = 0x01;
	while(1) {
		//if (button == 0) {
			P1 = 0xFF;
			for (i = 0; i < 20; i++) {
				delay();
				P1 = ~P1;
				//if (button == 0) break;
			}
			P1 = 0x55;
			for (i = 0; i < 20; i++) {
				delay();
				P1 = ~P1;
				//if (button == 0) break;
			}
			P1 = 0xF0;
			for (i = 0; i < 20; i++) {
				delay();
				P1 = ~P1;
				//if (button == 0) break;
			}
			P1 = 0xFF;
			for (j = 0; j < 8; j++) {
					P1 <<= 1;
					delay();
					//if (button == 0) break;
			}
			P1 = 0xFF;
			for (j = 0; j < 8; j++) {
					P1 >>= 1;
					delay();
					//if (button == 0) break;
			}

	
		//}	
	//	else P1 = 0;
	}	

}
void delay() {
	unsigned int i;
	for (i = 0; i < 200; i++) {
	TL0 = 0x17; TH0 = 0xFC;
	TR0 = 1;
	while (!TF0);
	TR0 = 0;	
	TF0 = 0;
	}
}