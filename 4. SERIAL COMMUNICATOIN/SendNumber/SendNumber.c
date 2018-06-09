//send a number
#include <reg52.h>
#include <string.h>
void send(unsigned char x);
void sendInteger(unsigned long a);
void sendReal(float a);
main() {
	TMOD = 0x20;
	TH1 = 0xFA;
	SCON = 0x50;
	TR1 = 1;
	while (1) {
		sendInteger(91);
		send(10);
		sendReal(123.12);
		send(10);
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
		x[i] = NULL;
		for (i = strlen(x); i >= 0; i--) {
			send(x[i]);
		}
	}
	else send('0');
}
void sendReal(float a) {
	unsigned long x = a/1; //tach phan nguyen
	unsigned long y = (a - x)*100; // tach phan thap phan
	sendInteger(x);
	if (y != 0) {
		send('.');
		sendInteger(y);
	}
}
