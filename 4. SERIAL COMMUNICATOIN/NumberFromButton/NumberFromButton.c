// Get a number from up and down button, display on PC
#include <reg52.h>
#include <string.h>
#include "..\..\LIBRARY\delay.h"
sbit led = P0^0;
sbit up = P2^0;
sbit down = P2^1;
sbit s1 = P2^6;
sbit s2 = P2^7;
void send(unsigned char x);
void sendInteger(unsigned long a);
void main () {
	char i = 0, j, a[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
	long n = 0;
	TMOD = 0x20;
	TH1 = 0xD0; //600
	SCON = 0x50;
	TR1 = 1;
	while (1) {
		if (up == 0) {
			for (j = 0; j < 20; j++) {
				delay_ms(1);
				if (up == 0) {
					led = 0;
					n++;
					sendInteger(n);
					send(10); delay_ms(1);
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
					n--;
					if (n < 0) n++;
					sendInteger(n);
					send(10); delay_ms(1);
					i--;
					if (i < 0) i++;
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
void send(unsigned char x) {
	SBUF = x;
	while (TI == 0);
	TI = 0;
}
void sendInteger(unsigned long a) {
	if (a != 0) {
		unsigned char x[11];
		int i;
		for (i = 0; a > 0; i++) {
			x[i] = (a%10) + 48; //tach chu so thanh ky tu
			a = a/10;
		}
		x[i] = '\0';
		for (i = strlen(x); i >= 0; i--) {
			send(x[i]);
		}
	}
	else send('0');
}

