#include<reg52.h>
#include "..\..\LIBRARY\delay.h"
sbit button = P2^0;
sbit tran1 = P3^0;
sbit tran2 = P3^1;
main() {
	unsigned char i, a[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
	unsigned int j;
	while(1) {
		loop:
		for (i = 0; i < 100; i++) {
			for (j = 0; j < 300; j++) {
				P1 = a[i/10];
				tran2 = 0;
				delay_ms(1);
				tran2 = 1;
				P1 = a[i%10];
				tran1 = 0;
				delay_ms(1);
				tran1 = 1;
				if (button==0) {
					delay_ms(30);
					goto loop;
				}
			}	
		}
	}
}