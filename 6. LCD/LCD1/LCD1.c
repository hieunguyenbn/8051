// WritedDta/instructions to LCD
#include <reg52.h>
#include "..\..\LIBRARY\delay.h"

sbit RS = P1^5;
sbit RW = P1^6;
sbit EN = P1^7;

void delay(unsigned int t) {
	while (t--);
}
void WriteCommand(unsigned char cmd);
void WriteChar(char c);
void WriteString(char *c);

unsigned char i, a[] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x00, 0x90}; 

int main(void) {
	WriteCommand(0x0C);// bat va tat con tro 
	WriteCommand(0x01);//xoa mh
	WriteString("NGUYEN SY HIEU ");
	for (i = 0; i < 10; i++) {
		P2 = a[i];
		delay(40000);
	}
	return 0;
}
void WriteCommand(unsigned char cmd) {
	RW = 0; // Write
	RS = 0; // Write instruction
	P3 = cmd;
	EN = 0; //Enable the instruction is sent to LCD
	EN = 1;
	if (cmd <= 0x02) delay_ms(2);
	else delay_ms(1);
}
void WriteChar(char c) {
	RW = 0;
	RS = 1; // Write ata
	P3 = c;
	EN = 0;
	EN = 1;
	delay_ms(1);
}
void WriteString(char *c) {
	while (*c) {
		WriteChar(*c++);
	}
}
