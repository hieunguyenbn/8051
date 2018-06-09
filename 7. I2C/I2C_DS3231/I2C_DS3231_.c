#include <regx52.h>
#include "..\..\LIBRARY\delay.h"

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

void DS3231_write(unsigned char a,unsigned char d);
unsigned char DS3231_read(unsigned char a);

char m;

main() {
		SCL = 1;
		delay(2);
		SDA = 1;
		LCD_init();
		WriteCommand(0x85);
		WriteString("VNU");
		DS3231_write(0x0E,0x40);
		while (1) {

		}		
}
void DS3231_write(unsigned char a,unsigned char d) {
		I2C_start();
		I2C_write(0xD0); // Dia chi cua ds3231
		I2C_write(a);
		I2C_write(d);
		I2C_stop();
}
unsigned char DS3231_read(unsigned char a) {
		unsigned int d;
		I2C_start();
		I2C_write(0xD0); // DIA CHI CUA DS3231 (WRITE)
		I2C_write(a); // GUI DIA CHI CUA THANH GHI
		I2C_start(); // KHOI DONG LAI
		I2C_write(0xD1); // READ
		d = I2C_read(0);
		I2C_stop();
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

void delay(unsigned int t) {
    while(t--);
}