// CHUYEN DOI KY TU THUONG NHAP TU BAN PHIM SANG KY TU HOA
#include <reg52.h>
#include <stdio.h>
void SendCharacter(unsigned char x);
void SendString(unsigned char *s);
unsigned char Receiver();
unsigned char c;
main() {
	unsigned char i;
	TMOD = 0x20; //timer 1 che do 2
	TH1 = 0xFD; // 9600
	SCON = 0x50; // UART Che do 1, REN = 1
	TR1 = 1;
//	putchar('A');
//	printf("HELLO WORLD");
	SendString("HELLO");
	SendString("\r\n");
	while (1) {
		SendString("Nhap vao ky tu thuong: ");
		i = Receiver(); //_getkey()
		i = i - 32;
		SendString("->");
		SendCharacter(i);
		SendCharacter(10);
//		SendString("\r\n");
	}
}

void SendCharacter(unsigned char x) {
	SBUF = x;
	while (TI == 0);
	TI = 0;
}
void SendString(unsigned char *s) {
	while (*s != 0) {
		SendCharacter(*s++);
	}
}
unsigned char Receiver() {
	while (RI == 0);
	c = SBUF;
	RI = 0;
	return c;
}