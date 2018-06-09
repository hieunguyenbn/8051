#include <regx52.h>
#include <stdio.h>
#include <string.h>
#include "..\..\LIBRARY\delay.h"

sbit tang = P3^6;
sbit giam = P3^7;
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

sbit SCL = P3^0;
sbit SDA = P3^1;

void LCD_init(); //khoi tao
void WriteCommand(unsigned char cmd); // Gui lenh cho LCD
void WriteChar(char c); // Gui ky tu
void WriteString(char *s); //GUI CHUOI
void delay(unsigned int t);

void I2C_start();
void I2C_stop();
void I2C_write(unsigned char d);
unsigned char I2C_read(bit ack);

unsigned char DS3231_read(unsigned char a);
void DS3231_write(unsigned char a,unsigned char d);

unsigned char Time[15], D[15];
volatile char c = 0;
char sec, min, hour, date, month, year, i, j, k;

main() {
		
		SCL = 1;
		delay(2);
		SDA = 1;
		LCD_init();
		EX0 = 1; EA = 1; //NGAT NGOAI 
		IT0 = 1; // NGAT THEO SUON
	//	DS3231_write(0x0E,0x04);
		while (1) {
			if (c == 1) {
				while (c == 1) {
					if (!(tang)) {
					delay_ms(20);
					while (!(tang)) {
							i++;
							WriteCommand(0x01);
							do {} while (!(tang));
					}
					}
					if (!(giam)) {
					delay_ms(20);
					while (!(giam)) {
							i--;
							WriteCommand(0x01);
							do {} while (!(giam));
					}
					}
					if (i == 24) i = 0;
					if (i == -1) i = 23;
					DS3231_write(0x02,i);
					hour = DS3231_read(0x02);
					WriteCommand(0x80);
					sprintf(Time,"Time %bu", hour);
					WriteString(Time);
					date = DS3231_read(0x04);
					month = DS3231_read(0x05);
					year = DS3231_read(0x06);
					WriteCommand(0xC0);
					sprintf(D,"Date %bu/%bu/20%bu", date, month, year);
					WriteString(D);
			}	
			}
			if (c == 2) {
				while (c == 2) {
					if (!(tang)) {
					delay_ms(20);
					while (!(tang)) {
							j++;
							WriteCommand(0x01);
							do {} while (!(tang));
					}
					}
					if (!(giam)) {
					delay_ms(20);
					while (!(giam)) {
							j--;
							WriteCommand(0x01);
							do {} while (!(giam));
					}
					}
					if (j == 60) j = 0;
					if (j == -1) j = 59;
					DS3231_write(0x01,j);
					hour = DS3231_read(0x02);
					min = DS3231_read(0x01);
					WriteCommand(0x80);
					sprintf(Time,"Time %bu:%bu ", hour, min);
					WriteString(Time);
					date = DS3231_read(0x04);
					month = DS3231_read(0x05);
					year = DS3231_read(0x06);
					WriteCommand(0xC0);
					sprintf(D,"Date %bu/%bu/20%bu ", date, month, year);
					WriteString(D);
			}
			}
			if (c == 3) {
				while (c == 3) {
					if (!(tang)) {
					delay_ms(20);
					while (!(tang)) {
							k++;
							WriteCommand(0x01);
							do {} while (!(tang));
					}
					}
					if (!(giam)) {
					delay_ms(20);
					while (!(giam)) {
							k--;
							WriteCommand(0x01);
							do {} while (!(giam));
					}
					}
					if (k == 60) k = 0;
					if (k == -1) k = 59;
					DS3231_write(0x00,k);
					hour = DS3231_read(0x02);
					min = DS3231_read(0x01);
					sec = DS3231_read(0x00);
					WriteCommand(0x80);
					sprintf(Time,"Time %bu:%bu:%bu", hour, min, sec);
					WriteString(Time);
					date = DS3231_read(0x04);
					month = DS3231_read(0x05);
					year = DS3231_read(0x06);
					WriteCommand(0xC0);
					sprintf(D,"Date %bu/%bu/20%bu", date, month, year);
					WriteString(D);
			}	
			}
			
			if (c == 4) c = 0;
			while (c==0) {
					hour = DS3231_read(0x02);
					min = DS3231_read(0x01);
					sec = DS3231_read(0x00);
					WriteCommand(0x80);
					sprintf(Time,"Time %bu:%bu:%bu", hour, min, sec);
					WriteString(Time);
					date = DS3231_read(0x04);
					month = DS3231_read(0x05);
					year = DS3231_read(0x06);
					WriteCommand(0xC0);
					sprintf(D,"Date %bu/%bu/20%bu", date, month, year);
					WriteString(D);	
			}
		}
}
void mode(void) interrupt 0 {
		c++;
}

void DS3231_write(unsigned char a,unsigned char d) {
		d = ((d/10)<<4 | (d%10)); //  dec to BCD 
		I2C_start();
		I2C_write(0xD0); // Dia chi cua ds3231
		I2C_write(a);
		I2C_write(d);
		I2C_stop();
}
unsigned char DS3231_read(unsigned char a) {
		unsigned int d;
		I2C_start();
		I2C_write(0xD0); // DIA CHI CUA DS3231 la 0x68, dich trai 1 bit de gui bit R/W (0) => OxDO
		I2C_write(a); // GUI DIA CHI CUA THANH GHI
		I2C_start(); // KHOI DONG LAI
		I2C_write(0xD1); // READ (R/W = 1)
		d = I2C_read(0);
		I2C_stop();
		d = ((d>>4)*10 + (d&0x0F)); // Chuyen doi ma BCD sang dec
		return d;
}
void I2C_start() {
		SDA = 1;
		SCL = 1;
		delay(2);
		SDA = 0;
		delay(2);
		SCL = 0;
		delay(2);
}
void I2C_stop() {
		SDA = 0;
		SCL = 1;
		delay(2);
		SDA = 1;
		delay(2);
		SCL = 0;
		delay(2);
}
void I2C_write(unsigned char d) {
		unsigned char i;
		for (i = 0; i < 8; i++) {
				SDA =  (d & 0x80)?1:0;
				SCL = 1;
				delay(2);
				SCL = 0;
				d <<= 1;
		}
		SCL = 1; // clock cho ACK
		SCL = 0;
}
unsigned char I2C_read(bit ack) {
		unsigned char i, d = 0;
		SDA = 1;
		for (i = 0; i < 8; i++) {
				SCL = 1;
				d <<= 1;
				d |= SDA;
				SCL = 0;
				delay(2);
		}
		SDA = (ack)?0:1;
		SCL = 1; // clock cho ack;
		delay(2);
		SCL = 0;
		return d;
}

void WriteCommand(unsigned char cmd) {
		P2 = (cmd & 0xF0); // gui 4 bit cao truoc
		RS = 0; // Gui/nhan lenh
		RW = 0; // Gui
		EN = 1; delay(20); EN = 0;
		delay(150);
		P2 = ((cmd << 4) & 0xF0); // gui 4 bit thap
		RS = 0; RW = 0;
		EN = 1; delay(20); EN = 0;
		delay(150);
}

void LCD_init() {
		P2 = 0x00;
		delay_ms(1);
		WriteCommand(0x03);
		WriteCommand(0x02);        // Initialize Lcd in 4-bit mode
    WriteCommand(0x28);        
    WriteCommand(0x01);        // Clear 
		WriteCommand(0x0E);
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

void delay(unsigned int t) {
    while(t--);
}