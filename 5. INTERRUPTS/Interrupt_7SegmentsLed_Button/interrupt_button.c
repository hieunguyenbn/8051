//button leg 7 segments use External interrup
#include <reg52.h>
//volatile
void delay_ms(unsigned int t);

sbit k1 = P2^6;
sbit k2 = P2^7;

unsigned char i, k, z, a[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};
volatile unsigned int j; //j = 0

void BUTTON(void) interrupt 0 {
	j++;
}
main() {
	IE = 0x81; //EA = 1;EX0 = 1; Cho phep ngat ngoai 0
	IT0 = 1;// Ngat theo suon
	while(1) {
		if(j%2) {
			while (j%2) {
			for (i = 0; i < 100; i++) {
				for (k = 0; k < 120; k++) {
					P1 = a[i%10];
					k1 = 0; delay_ms(1); k1 = 1;
					P1 = a[i/10];
					k2 = 0; delay_ms(1); k2 = 1;
				}	
				if (!(j%2)) {
					for (z = 0; z < 20; z++) {
						delay_ms(1);
						while(!(j%2)) {
							P1 = a[i%10];
							k1 = 0; delay_ms(1); k1 = 1;
							P1 = a[i/10];
							k2 = 0; delay_ms(1); k2 = 1;
						}
						do {} while (!(j%2));
					}
				}
			}
			}	
		}
	}
}
void delay_ms(unsigned int t) {
	unsigned int x, y;
	for (x = 0; x < t; x++)
		for (y = 0; y < 123; y++);
}
