//send a character to PC
#include <reg52.h>

void send(unsigned char x);

main() { 

	TMOD = 0x20; // TIMER 1 CHE DO 2 8 BIT
	TH1 = 0xFA; // TOC DO BAUD = 4800
	SCON = 0x50; // UART che do 1, REN = 1
	TR1 = 1; // START TIMER 1
	while (1)	{
		send('H');
		send('I');
		send('E');
		send('U');
		send(' ');
	}
}
void send(unsigned char x) {
	SBUF = x;
	while (TI == 0) {}
	TI = 0;
}