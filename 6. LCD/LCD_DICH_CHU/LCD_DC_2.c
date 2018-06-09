// 1 HANG DICH, 1 HANG DUNG IM
#include <reg52.h>
#include <string.h>

sbit RS = P0^5;
sbit RW = P0^6;
sbit EN = P0^7;

void delay_ms(unsigned int t);
void WriteCommand(unsigned char cmd);
void init();
void WriteChar(char c);
void WriteString(char *s);

volatile unsigned char i;
char s[] = "TIN VAT LY";
unsigned char k, n;

int main() {
	
		IE = 0x81; IT0 = 1;
		init();
		n = strlen(s)-1;
		while (1) {
			if (i%2 == 0) {
					delay_ms(20);
					while (i%2 == 0) {
						WriteCommand(0xC3);
						WriteString(s);
					}
					if (i%2 != 0) {
						delay_ms(20);
						WriteCommand(0x01);
						while (i%2 != 0) {
							WriteCommand(0xC3);
							for (k = 0; k <= n; k++) {
								WriteChar(s[k]);
								delay_ms(100);
							}
							delay_ms(400);
							WriteCommand(0x01);
							delay_ms(10);
						}
					}
			}
		}
		return 0;
}
void ngat(void) interrupt 0 {
			i++;
}
		
		
void WriteCommand(unsigned char cmd) {
		RS = 0;
		RW = 0;
		P2 = cmd;
		EN = 0;
		EN = 1;
		delay_ms(2);
}
void init() {
		WriteCommand(0x30);
		delay_ms(5);
		WriteCommand(0x30);
		delay_ms(1);
		WriteCommand(0x38);
		WriteCommand(0x01);
		WriteCommand(0x0C);
}
void WriteChar(char c) {
		RS = 1;
		RW = 0;
		P2 = c;
		EN = 0;
		EN = 1;
		delay_ms(1);
}
void WriteString(char *s) {
		while (*s) {
					WriteChar(*s++);
		}
}
void delay_ms(unsigned int t) {
	unsigned int x, y;
	for (x = 0; x < t; x++)
		for (y = 0; y < 123; y++);
}