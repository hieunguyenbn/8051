// LCD 8bit , hien thi tren ca 2 dong o vi tri bat ky (DDRAM), DEM SO SU DUNG NGAT NGOAI
#include <reg52.h>
#include <string.h>
#include "..\..\LIBRARY\delay.h"

sbit RS = P0^5;
sbit RW = P0^6;
sbit EN = P0^7;
void delay(unsigned int t) {
	while(t--);
}

void init(); //khoi tao
void WriteCommand(unsigned char cmd); // Gui lenh cho LCD
void WriteCharacter(char c); // Gui ky tu
void WriteCharPosition(unsigned char row, unsigned char col, char c); // xuat ky tu ra LCD tai vt hang row, cot col
void WriteString(char *s);
void WriteStringPosition(unsigned char row, unsigned char col, char *s); // xuat chuoi ra LCD tai vt hang row cot col
void WriteNumber(unsigned long a);

volatile long i;

int main(void) {
	EX0 = 1;
	EX1 = 1 ;
	EA = 1;//IE = 0x85; //Ngat ngoai 
	IT0 = 1;
	IT1 = 1;
	init();
	while (1) {
		WriteCharPosition(2,1,0x2A);
		WriteStringPosition(2,3,"DEM SAN PHAM");
		WriteCharPosition(2,16,0x2A);
		WriteStringPosition(1,2,"COUNTER = ");
		WriteCommand(0x8B);
		WriteNumber(i);
	}

	return 0;
}

void UP(void) interrupt 0 {
	i++;
	delay(20);	
}
void DOWN(void) interrupt 2 {
	i--;
	delay(145);
	if (i < 1) i = 0;	
}
void WriteCommand(unsigned char cmd) {
	RW = 0;
	RS = 0;
	P2 = cmd;
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
	P2 = c;
	EN = 0;
	delay_ms(1);
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

void WriteNumber(unsigned long a) {
	if (a != 0) {
		unsigned char x[6];
		int k;
		for (k = 0; a > 0; k++) {
			x[k] = (a%10) + 48;
			a = a/10;
		}
		x[k] = '\0';
		for (k = strlen(x)-1; k >= 0; k--) {
			WriteCharacter(x[k]);
		}
		WriteCharacter(' ');
	}
	else WriteCharacter('0');
}