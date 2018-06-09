// DUNG COUNTER DEM XUNG TU ben ngoai
#include <reg52.h>
#include "..\..\LIBRARY\delay.h"
sbit button = P2^0;
sbit clock = P3^4;
sbit k1 = P3^6;
sbit k2 = P3^7;
main() {
	unsigned char i=0, j=0, k, a[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
	TMOD = 0x05;
	TH0 = 0x00;
	TL0 = 0x00;
	clock = 1;
	while(1) {
		TR0 = 1;
		loop:
		do {
			loop2:
			while(button=1) {
				i = TL0 + TH0;
				if (i == 100) {TL0=0; TH0=0;}
			
				P1 = a[i%10];
				k1 = 0; delay_ms(1); k1 = 1;
			
				P1 = a[i/10];
				k2 = 0; delay_ms(1); k2 = 1;
				if (button==0) { //reset neu nhan nut
					for (k = 0; k < 20; k++) {
						delay_ms(1);
						if (button==0) {
							TL0=0; TH0=0;
							do {} while (button==0);
						}
					}
				}
			}
			j++;
			if (j==400) goto loop;
			
		} while (TF0 == 0);
		TF0=0;
		
	}
}

