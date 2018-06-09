// DO KC SU DUNG CAM BIEN SIEU AM SRF05, HIEN THI LEN LCD

#include <reg52.h>
#include "..\..\LIBRARY\delay.h"
#include <stdio.h>

sbit RS = P0^5;
sbit RW = P0^6;
sbit EN = P0^7;
sbit TRIGGER = P3^5;
sbit ECHO = P3^2;

void WriteCommand(unsigned char cmd);
void LCD_init();
void WriteChar(char c);
void WriteString(char *s);
void WriteStringPosition(unsigned char row, unsigned char col, char *s);
void StartRange();
void SRF05_Init(void);

char chuoi2[16];
volatile float range, temp1;
unsigned char range_ok;
unsigned int distance;

main() {
	
		LCD_init();
		SRF05_Init();
		while (1) {
			WriteStringPosition(1,2,"DO KHOANG CACH");
			StartRange();
			if(range_ok){
				sprintf(chuoi2,"DISTANCE = %f",range);
				WriteStringPosition(2,1,chuoi2);
			}
		}
}
void StartRange() {
	TRIGGER = 1;
	delay_ms(12); 		         // Phai tao 1 xung len co do lon it nhat 10ms
	ECHO = 1;                      // set chan ECHO la cong vao
	delay_us(1);
	TRIGGER = 0;			         // Bat dau phep do.
	while(!(ECHO));		         // Doi cho den khi chan ECHO duoc keo len cao
	//TR0=1;		                 // Cho phep timer 0 hoat dong
	TR0 = IT0 = EX0 = EA = 1;						 // cho phep ngat toan cuc
}


void SRF05_Init(void) {
	TRIGGER = 0;
	TMOD = 0x01;   //timer 0 che do 1 (16bit)
	TR0 = 1;
	IT0 = 1;       //ngat ngoai 0 che do ngat theo suong
	IT1 = 1;
	EX0 = 1;          //cho phep ngat ngoai 0
	EX1 = 1;
	EA = 1;          // cho phep ngat toan cuc
	range_ok = 0;
}

//ngat ngoai 0
void ngatngoai0(void)interrupt 0 {
	distance = TH0;
	distance <<= 8;
	distance |= TL0;
	range = (float)distance*12;
	temp1=((58*11.0592));//temp1= 641;
	range = range/(temp1);
	TR0 = 0; IT0 = 0; EX0 = 0;					       		// Ngung timer
	TL0 =  0; TH0 = 0; 			                  // Xoa du lieu trong thanh ghi Timer 0		             
	range_ok = 1;
}   

void WriteCommand(unsigned char cmd) {
		RS = 0; RW = 0;
		P2 = cmd;
		EN = 0; EN = 1;
		delay_ms(2);
}
void LCD_init() {
		WriteCommand(0x30);
		delay_ms(5);
		WriteCommand(0x30);
		delay_ms(1);
		WriteCommand(0x38);
		WriteCommand(0x01);
		WriteCommand(0x0C);
}
void WriteChar(char c) {
		RS = 1; RW = 0;
		P2 = c;
		EN = 0;	EN = 1;
		delay_ms(1);
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