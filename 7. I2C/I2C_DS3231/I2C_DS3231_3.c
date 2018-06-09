#include <regx52.h>
#include <stdio.h>
#include <string.h>
#include "..\..\LIBRARY\delay.h"

sbit mode = P3^4;
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
volatile char i;
char sec, min, hour, date, month, year, c, check;

main() {
		
		SCL = 1;
		delay(2);
		SDA = 1;
		LCD_init();
		IE = 0x85; //NGAT NGOAI 
		IT0 = 1; IT1 = 1; // NGAT THEO SUON
	//	DS3231_write(0x0E,0x04);
		
		while (1) {
				if (!(mode)) {
						delay_ms(2);
						c = 1;
						check = 1;
				}
				while (check) {
				
				if (c == 1) {
							i = hour;
							delay_ms(100);
							hour = i;
							if (hour < 0) hour = 23;
							if (hour > 23) hour = 0;
							DS3231_write(0x02,hour);
							WriteCommand(0x86);
							WriteChar(hour/10+48);
							WriteChar(hour%10+48);
							WriteCommand(0x88);
							WriteChar(':');
							WriteCommand(0x87);
				}
				else if (c == 2) {
							i = min;
							delay_ms(100);
							min = i;
							if (min < 0) min = 59;
							if (min > 59) min = 0;
							DS3231_write(0x01,min);
							WriteCommand(0x89);
							WriteChar(min/10+48);
							WriteChar(min%10+48);
							WriteCommand(0x8B);
							WriteChar(':');
							WriteCommand(0x8A);
				}
				else if (c == 3) {
							i = sec;
							delay_ms(100);
							sec = i;
							if (sec < 0) sec = 59;
							if (sec > 59) sec = 0;
							DS3231_write(0x00,sec);
							WriteCommand(0x8C);
							WriteChar(sec/10+48);
							WriteChar(sec%10+48);
							WriteCommand(0x8D);
				}
				else if (c == 4) {			
							i = date;
							delay_ms(100);
							date = i;
							if (date < 0) date = 31;
							if (date > 31) date = 0;
							DS3231_write(0x04,date);
							WriteCommand(0xC6);
							WriteChar(date/10+48);
							WriteChar(date%10+48);
							WriteCommand(0xC8);
							WriteChar('/');
							WriteCommand(0xC7);
				}
				else if (c == 5) {
							i = month;
							delay_ms(100);
							month = i;
							if (month < 0) month = 12;
							if (month > 12) month = 0;
							DS3231_write(0x05,month);
							WriteCommand(0xC9);
							WriteChar(month/10+48);
							WriteChar(month%10+48);
							WriteCommand(0xCB);
							WriteChar('/');
							WriteCommand(0xCA);
					}
				else if (c == 6) {
							i = year;
							delay_ms(100);
							year = i;
							if (year < 0) year = 99;
							if (year > 99) year = 0;
							DS3231_write(0x06,year);
							WriteCommand(0xCC);
							WriteChar(year/10+48);
							WriteChar(year%10+48);
							WriteCommand(0xCD);
					}
				else {
					check = 0;
					delay_ms(400);
					WriteCommand(0x01);
				}
				if (!(mode)) {
						delay_ms(2);
						c++;
				}
			}
					hour = DS3231_read(0x02);
					min = DS3231_read(0x01);
					sec = DS3231_read(0x00);
					WriteCommand(0x80);
					WriteString("Time");
					WriteCommand(0x86);
					sprintf(Time,"%bu:%bu:%bu ", hour, min, sec);
					WriteString(Time);
					date = DS3231_read(0x04);
					month = DS3231_read(0x05);
					year = DS3231_read(0x06);
					WriteCommand(0xC0);
					WriteString("Date");
					WriteCommand(0xC6);
					sprintf(D,"%bu/%bu/%bu ", date, month, year);
					WriteString(D);
		}	
	
}
void tang(void) interrupt 0 {
		i++;
		delay_us(1000);
}
void giam(void) interrupt 2 {
		i--;
		delay_us(1000);
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