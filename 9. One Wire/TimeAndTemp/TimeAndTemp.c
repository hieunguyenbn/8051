#include <regx52.h>
#include <stdio.h>
#include <string.h>
#include "..\..\LIBRARY\delay.h"
#include "..\..\LIBRARY\port.h"

void LCD_init(); //khoi tao
void WriteCommand(unsigned char cmd); // Gui lenh cho LCD
void WriteChar(char c); // Gui ky tu
void WriteString(char *s); //GUI CHUOI

void I2C_start();
void I2C_stop();
void I2C_write(unsigned char d);
unsigned char I2C_read(bit ack);
unsigned char DS3231_read(unsigned char a);
void DS3231_write(unsigned char a,unsigned char d);
void DS18B20_WriteBit(char c);
void DS18B20_WriteByte(char c);
unsigned char DS18B20_ReadBit(void);
unsigned char DS18B20_ReadByte(void); 
unsigned char DS18B20_Reset(void);
void ReadTemperature(void);
unsigned char temperature;
unsigned char Time[15], D[15], Temp[4];
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
						EA = 1;
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
					WriteCommand(0x80);
					ReadTemperature();
//					WriteChar((temperature/10)+48);
//					WriteChar((temperature%10)+48);
					sprintf(Temp,"%bu ^C", temperature); 
					WriteString(Temp);
					hour = DS3231_read(0x02);
					min = DS3231_read(0x01);
					sec = DS3231_read(0x00);
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
unsigned char DS18B20_Reset(void) {
		unsigned char presence;
		DQ = 1;
		DQ = 0; // keo xuong
		delay_us(29); // delay (480-24)/16=28.5 do thoi gian goi ham 24us, ham nay tre trong 16us
		DQ = 1; // keo len
		delay_us(3); // delay (70-24)/16 = 2.875 // cho tin hieu presence
		presence = DQ;
		delay(25); // delay (410-24)/16 = 24.125; // ket thuc timeslot
		return presence; // Neu presence = 0 thi OK chip slave tra loi, =1 thi NOT OK;
}
void DS18B20_WriteBit(char c) {
		DQ = 0; // keo xuong muc 0 de khoi dong timeslot
		if (c == 1) DQ = 1; // Neu write 1
		delay_us(5); // delay 104 us luu gia tri cua timeslot
		DQ = 1;
}
void DS18B20_WriteByte(char c) {
		unsigned char i;
		unsigned char temp;
		for (i = 0; i < 8; i++) {
				temp = c >> i; // lan luot viet tung bit
				temp &= 0x01; // luu bit thap nhat vao bien temp
				DS18B20_WriteBit(temp); // viet bit do len bus
		}
		delay_us(5);
}
unsigned char DS18B20_ReadBit(void) {
		unsigned char i;
		DQ = 0;
		DQ = 1;
		for (i = 0; i < 3; i++); // delay 15us
		return (DQ);
}
unsigned char DS18B20_ReadByte(void) {
		unsigned char i;
		unsigned char value = 0;
		for (i = 0; i < 8; i++) {
				if (DS18B20_ReadBit()) value |= 0x01 << i; // dich trai doc lan luot tung bit
				delay_us(6);
		}
		return value;
}
void ReadTemperature(void) {
		unsigned char a = 0;
		unsigned char b = 0;
		EA = 0;
		if (!DS18B20_Reset()) {
				DS18B20_WriteByte(0xCC);// Skip rom
				DS18B20_WriteByte(0x44); // Lenh Convert T
				delay(10);
		}
		if (!DS18B20_Reset()) {
				DS18B20_WriteByte(0xCC);// Skip rom
				DS18B20_WriteByte(0xBE); // Lenh doc nhiet do
				delay(10);
		}
		a = DS18B20_ReadByte(); // doc nhiet do byte thap
		b = DS18B20_ReadByte(); // doc nhiet do byte cao
		temperature = (b*256+a)>>4; // luu gia tri nhiet do vao bien temp
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