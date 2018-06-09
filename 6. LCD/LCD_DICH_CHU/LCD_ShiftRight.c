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
void ShiftRight(char *s, char *s2);

char chuoi1[] = "VNU - HANOI UNIVERSITY OF SCIENCE";
char chuoi2[] = "PHYSICS FACULTY";

int main() {
	
		init();

		WriteCommand(0xC1);
		WriteString(chuoi2);
	//while(1)
		ShiftRight(chuoi1,chuoi2);
	
		return 0;
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
	//	WriteCommand(0x06);
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
void ShiftRight(char *s, char *s2) {
		unsigned char j, i, c, n;
		n = strlen(s)-1; j = n; c = 0;
		while (c <= 15) {
				WriteCommand(0x80);
				for (i = j; i <= n; i++) {
					WriteChar(s[i]);
				}
				WriteCommand(0xC1);
				WriteString(s2);
				delay_ms(600);
				WriteCommand(0x01);
				WriteCommand(0xC1);
				WriteString(s2);
				c++; j--;
		}
		while (j > 0) {
				WriteCommand(0x80);
				for (i = j; i <= j+15; i++) {
						WriteChar(s[i]);
				}
				WriteCommand(0xC1);
				WriteString(s2);
				delay_ms(600);
				WriteCommand(0x01);
				WriteCommand(0xC1);
				WriteString(s2);
				j--;
		}
		c = 0; j = 15;
		while (c <= 15) {
			WriteCommand(0x80+c);
			for (i = 0; i <= j; i++) {
					WriteChar(s[i]);
			}
			WriteCommand(0xC1);
			WriteString(s2);
			delay_ms(600);
			WriteCommand(0x01);
			WriteCommand(0xC1);
			WriteString(s2);
			j--; c++;
		}
		WriteCommand(0xC1);
		WriteString(s2);
}
void delay_ms(unsigned int t) {
	unsigned int x, y;
	for (x = 0; x < t; x++)
		for (y = 0; y < 123; y++);
}