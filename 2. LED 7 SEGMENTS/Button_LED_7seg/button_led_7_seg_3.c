//led 7 seg voi up and down button
#include <reg52.h>
#include "..\..\LIBRARY\delay.h"

sbit led = P0^0;
sbit up = P2^0;
sbit down = P2^1;
sbit s1 = P2^6;
sbit s2 = P2^7;

main() {
	unsigned char i = 0, j, a[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
	while (1) {	
		if (up == 0) {
			for (j = 0; j < 20; j++) {
				delay_ms(1);
				if (up == 0) {
					led = 0;
					i++;
					if (i == 100) i = 0;
					do {} while (up == 0);
				}
			}
		}
		if (down == 0) {
			for (j = 0; j < 20; j++) {
				delay_ms(1);
				if (down == 0) {
					led = 0;
					i--;
					do {} while (down == 0);
				}
			}
		}
		led = 1;
		P1 = a[i%10];
		s1 = 0; delay_ms(1); s1 = 1;
		P1 = a[i/10];
		s2 = 0; delay_ms(1); s2 = 1;
		}	
}