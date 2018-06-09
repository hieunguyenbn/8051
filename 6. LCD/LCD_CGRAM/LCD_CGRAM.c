//LCD WITH CGRAM
#include <reg52.h>
#include "..\..\LIBRARY\delay.h"

sbit RS = P0^5;
sbit RW = P0^6;
sbit EN = P0^7;

void init();
void WriteCommand(unsigned char cmd);
void WriteChar(char c);
void WriteCharPosition(unsigned char row, unsigned char col, char c);


int main(void) {
		init();
		while (1) {
		WriteCharPosition(2,1,0x2A);
		WriteCharPosition(2,16,0x2A);
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
		WriteCommand(0x30); // Hien thi 2 dong
		delay_ms(5);
		WriteCommand(0x30);
		delay_ms(1);
		WriteCommand(0x30);
		WriteCommand(0x38); // Hien thi 2 dong
		WriteCommand(0x01); // Clear
		WriteCommand(0x0c); // Display and delete cursor
		WriteCommand(0x06); // Auto increment cursor, shift to right
}
void WriteChar(char c) {
		RS = 0;
		RW = 1;
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
