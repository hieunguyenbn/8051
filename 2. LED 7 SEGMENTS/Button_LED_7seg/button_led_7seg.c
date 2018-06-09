//LED 7 DOAN. BAM THI DUNG LAI, bam tiep thi lai chay // khong dunginterrupt
#include <reg52.h>
#include "..\..\LIBRARY\delay.h"
sbit led = P0^0;
sbit button = P2^0;
sbit k1 = P2^6;
sbit k2 = P2^7;

main() {
	unsigned char i, k, l, a[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
	unsigned int j, count;
	count = 0;

	if (button == 1) {
		while(count == 0) {
			if (button == 0 ) {
				delay_ms(20);
				if (button == 0) {
					delay_ms(100);
					count = 1;
					break;
					do {} while (button == 0);
				}
			} 
		}
	}
	while(1) {
		loop:
		for (i = 0; i < 100; i++) {
			for (j = 0 ; j < 150; j++) {
				P1 = a[i%10];
				k1 = 0; delay_ms(1); k1 = 1;
				P1 = a[i/10];
				k2 = 0; delay_ms(1); k2 = 1;
				
				if (button==0) {
					for (k = 0; k < 20; k++) {
					delay_ms(1);
					if (button==0) {
						led = 0;
						do {} while (button == 0); 
						while (1) {
							P1 = a[i%10];
							k1 = 0; delay_ms(1); k1 = 1;
							P1 = a[i/10];
							k2 = 0; delay_ms(1); k2 = 1;
						if (button == 0) {
							for (l = 0; l < 20; l++) {
								delay_ms(1);
								if (button==0) {
									led = 1;
									++i;
									do {} while (button==0);
									goto loop;
								
								}
							}
						}
						}
					}
					}
				}
			}
		}
	}
}