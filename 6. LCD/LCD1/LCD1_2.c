
#include <reg52.h>
#include <string.h>
#include "..\..\LIBRARY\delay.h"

sbit RS = P1^5;
sbit RW = P1^6;
sbit EN = P1^7;
void init();
void WriteCommand(unsigned char cmd);
void WriteChar(char c);
void WriteString(char *c);

int main(void) {

	init();
	WriteChar("H");
	WriteCommand(0xC0); // xuong dong thu 2
	WriteString("HIEU");
	return 0;
}

void init() {
	WriteCommand(0x30);
	delay_ms(5);
	WriteCommand(0x30);
	delay_ms(1);
	WriteCommand(0x30); 
	WriteCommand(0x38); //Hien thi 2 line
	WriteCommand(0x01); //delete LCD
	WriteCommand(0x0C);//Display and delete cursor  
	WriteCommand(0x06); //AUTO increment cursor
}
void WriteCommand(unsigned char cmd) {
	RW = 0; // Write
	RS = 0; // Write instruction
	P2 = cmd;
	EN = 0; //Enable the instruction is sent to LCD
	EN = 1;
	if (cmd <= 0x02) delay_ms(2);
	else delay_ms(1);
}
void WriteChar(char c) {
	RW = 0;
	RS = 1; // Write ata
	P2 = c;
	EN = 0;
	EN = 1;
	delay_ms(1);
}
void WriteString(char *c) {
	while (*c) {
		WriteChar(*c++);
	}
}

		