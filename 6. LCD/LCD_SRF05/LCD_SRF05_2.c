// DO KC SU DUNG CAM BIEN SIEU AM SRF05, HIEN THI LEN LCD

#include <reg52.h>
#include "..\..\LIBRARY\delay.h"
#include <stdio.h>

sbit RS = P1^0;
sbit RW = P1^1;
sbit EN = P1^2;
sbit TRIGGER = P3^5;
sbit ECHO = P3^2;
void delay(unsigned int t) {
	while (t--);
}
void WriteCommand(unsigned char cmd);
void LCD_init();
void WriteChar(char c);
void WriteString(char *s);
void StartRange();
void SRF05_Init(void);

char chuoi[16];
unsigned int distance;
float d;

main() {
	
		LCD_init();
		SRF05_Init();
		while (1) {
			StartRange();
			sprintf(chuoi,"D = %.1f cm ",d);
			WriteString(chuoi);
		}
}
void StartRange() {
		TRIGGER = 1;
		delay_ms(12);//tao 1 xung len
		ECHO = 1;  // set chan ECHO 
		delay_us(1);
		TRIGGER = 0;// Bat dau phep do.
		while(!(ECHO));	// Doi cho den khi chan ECHO duoc keo len ca
		TR0 = IT0 = EX0 = EA = 1;	// Cho phep timer 0 hoat dong	// cho phep ngat toan cuc
}


void SRF05_Init(void) {
	TRIGGER = 0;
	TMOD = 0x01;   //timer 0 che do 1 (16bit)
	TR0 = 1; EX0 = 1; IT0 = 1;       //ngat ngoai 0 che do ngat theo suon
	EA = 1;          // cho phep ngat toan cuc
}

void ngatngoai0(void)interrupt 0 {
	distance = TH0;
	distance <<= 8;
	distance |= TL0;
	d = (float) distance/60;
	TR0 = 0; IT0 = 0; EX0 = 0;					       		// Ngung timer
	TL0 =  0; TH0 = 0; 			                  // Xoa du lieu trong thanh ghi Timer 0		             
}   

void WriteCommand(unsigned char cmd) {
		RS = 0; RW = 0;
		P2 = cmd;
		EN = 0; EN = 1;
		delay_ms(2);
}
void LCD_init() {
		P2 = 0x00;
		delay_ms(1);
		WriteCommand(0x03);
		WriteCommand(0x02);        // Initialize Lcd in 4-bit mode
    WriteCommand(0x28);        // enable 5x7 mode for chars 
    WriteCommand(0x01);        // Clear Display
		WriteCommand(0x0C);
}
		
void WriteChar(char c) {
		P2 = (c & 0xF0);
		RS = 1; // Gui/nhan du lieu
		RW = 0; // Gui
		EN = 1; delay(10); EN = 0;
		delay(100);
		P2 = ((c << 4) & 0xF0);
		RS = 1; RW = 0;
		EN = 1; delay(10); EN = 0;
		delay(100);
}
void WriteString(char *s) {
		while (*s) {
				WriteChar(*s++);
		}
}