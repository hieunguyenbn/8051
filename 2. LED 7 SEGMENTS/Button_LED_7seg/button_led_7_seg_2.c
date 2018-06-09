//MOI LAN NHAN NUT TANG 1 DON VI, HIEN THI SO DEM RA LED.
#include <reg52.h>
#include "..\..\LIBRARY\delay.h"
sbit led = P0^0;
sbit button = P2^0;
sbit k1 = P3^0;
sbit k2 = P3^1;

main() {
	
	unsigned char i, j, a[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
	i = 0;
	P1 = a[i];
	while (1) {	
		led = 1;
		if (button == 0) {
			for (j = 0; j < 20; j++) {
				delay_ms(1);
			if (button==0) {
				led = 0;
				i = i + 1;
				if (i == 100) i = 0;
				do {} while (button==0);
			}
			}
		}
		P1 = a[i%10];
		k1 = 0; delay_ms(1); k1 = 1;
		P1 = a[i/10];
		k2 = 0; delay_ms(1); k2 = 1;
		
	}
}