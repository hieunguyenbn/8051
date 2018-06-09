// LCD 8bit , hien thi tren ca 2 dong o vi tri bat ky (DDRAM)
#include <reg52.h>
#include "..\..\LIBRARY\delay.h"

sbit RS = P1^5;
sbit RW = P1^6;
sbit EN = P1^7;

void init(); //khoi tao
void WriteCommand(unsigned char cmd); // Gui lenh cho LCD
void WriteCharacter(char c); // Gui ky tu
void WriteCharPosition(unsigned char row, unsigned char col, char c); // xuat ky tu ra LCD tai vt hang row, cot col
void WriteString(char *s);
void WriteStringPosition(unsigned char row, unsigned char col, char *s); // xuat chuoi ra LCD tai vt hang row cot col

int main(void) {

	init();
	WriteCommand(0x84);// Di chuyen con tro den vi tri 04 (COT 5)
	WriteString("HELLO");
	WriteCharPosition(1,15,'H'); // ky tu o dong 1 cot 15
	//WriteCommand(0xC0); //DI CHUYEN CON TRO VAO DONG 2
	WriteStringPosition(2,2,"NGUYEN SY HIEU - UNIVERSITY OF SCIENCE");
	while (1) {
		WriteCommand(0x18); // Dich sang trai
		delay_ms(500);		
		//WriteCommand(0x02); // con tro tro lai vtbd
	}
	return 0;
}
void WriteCommand(unsigned char cmd) {
	RW = 0;
	RS = 0;
	P3 = cmd;
	EN = 0;
	EN = 1;
	if (cmd <= 0x02) delay_ms(2);
	else delay_ms(1);
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
void WriteCharacter(char c) {
	RW = 0;
	RS = 1;
	P3 = c;
	EN = 0;
	EN = 1;
	delay_ms(1);
}
void WriteCharPosition(unsigned char row, unsigned char col, char c) {
	unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + col - 1;
	WriteCommand(cmd);
	WriteCharacter(c);
}
void WriteString(char *s) {
	while (*s) {
		WriteCharacter(*s++);
	}
}
void WriteStringPosition(unsigned char row, unsigned char col, char *s) {
	unsigned char cmd;
	cmd = (row==1?0x80:0xC0) + col - 1;
	WriteCommand(cmd);
	WriteString(s);
}
	