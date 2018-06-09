#include <reg52.h>
//#include "..\..\LIBRARY\delay.h"

sbit RS = P0^5;
sbit RW = P0^6;
sbit EN = P0^7;
void delay_ms(unsigned int 
	t) {
	unsigned int x, y;
	for (x = 0; x < t; x++)
		for (y = 0; y < 123; y++);
}
void WriteCommand(unsigned char cmd);
void init();
void WriteChar(char c);
void WriteCharPosition(unsigned char row, unsigned char col, char c);
void WriteString(char *s);
void WriteStringPosition(unsigned char row, unsigned char col, char *s);
char chuoi[] = " TRUONG DAI HOC KHOA HOC TU NHIEN";
int main() {
		delay_ms(10);
		init();
		WriteStringPosition(1,1,chuoi);
				while (1) {
						WriteCommand(0x18); // dich trai
						delay_ms(500);
				}	
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
		WriteCommand(0x06);
}
void WriteChar(char c) {
		RS = 1;
		RW = 0;
		P2 = c;
		EN = 0;
		EN = 1;
		delay_ms(1);
}
void WriteCharPosition(unsigned char row, unsigned char col, char c) {
	unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + col - 1;
	WriteCommand(cmd);
	WriteChar(c);
}
void WriteString(char *s) {
		while (*s) {
					WriteChar(*s++);
		}
}
void WriteStringPosition(unsigned char row, unsigned char col, char *s) {
	unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + col - 1;
	WriteCommand(cmd);
	WriteString(s);
}