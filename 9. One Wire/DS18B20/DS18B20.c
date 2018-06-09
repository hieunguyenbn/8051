#include <regx52.h>
#include <stdio.h>
#include "..\..\LIBRARY\delay.h"
#include "..\..\LIBRARY\port.h"

void LCD_init(); //khoi tao
void WriteCommand(unsigned char cmd); // Gui lenh cho LCD
void WriteChar(char c); // Gui ky tu
void WriteString(char *s); //GUI CHUOI

void DS18B20_WriteBit(char c);
void DS18B20_WriteByte(char c);
char DS18B20_ReadBit(void);
char DS18B20_ReadByte(void); 
unsigned char DS18B20_Reset(void);
void ReadTemperature(void);

volatile unsigned int nguyen, thapphan;
unsigned char Temp[6];

main() {
		
		LCD_init();
		while (1) {
				WriteCommand(0x83);
				WriteString("DO NHIET DO");
				WriteCommand(0xC5);
				ReadTemperature();	
				thapphan = thapphan*100/16; // lay 2 chu so phan thap phan
				sprintf(Temp,"%d.%d", nguyen, thapphan); 
				WriteString(Temp);
				WriteChar(0xDF);
				WriteChar('C');
				delay_ms(2000);
				WriteCommand(0x01);
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
		delay_us(5); 
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
char DS18B20_ReadBit(void) {
		unsigned char i;
		DQ = 0;
		DQ = 1;
		for (i = 0; i < 3; i++); // delay 15us
		return (DQ);
}
char DS18B20_ReadByte(void) {
		unsigned char i;
		char value = 0;
		for (i = 0; i < 8; i++) {
				if (DS18B20_ReadBit()) value|=0x01<<i; // dich trai doc lan luot tung bit
				delay_us(5);
		}
		return value;
}
void ReadTemperature(void) {
		unsigned char a = 0;
		unsigned char b = 0;
		if (!DS18B20_Reset()) {
				DS18B20_WriteByte(0xCC);// Skip rom
				DS18B20_WriteByte(0x4E); // Write rom
				DS18B20_WriteByte(0x1F); // 9bit mode
				delay_us(5);
		}
		if (!DS18B20_Reset()) {
				DS18B20_WriteByte(0xCC);// Skip rom
				DS18B20_WriteByte(0x44); // Convert T
				delay_us(5);
		}
		if (!DS18B20_Reset()) {
				DS18B20_WriteByte(0xCC);// Skip rom
				DS18B20_WriteByte(0xBE); // Lenh doc nhiet do
				delay_us(3);
		}
		a = DS18B20_ReadByte(); // doc nhiet do byte thap
		b = DS18B20_ReadByte(); // doc nhiet do byte cao
		nguyen = (b*256+a)>>4; // phan nguyen
		thapphan = (b*256+a)&0x000F; // 4 bit thap nhat chua phan thap phan
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