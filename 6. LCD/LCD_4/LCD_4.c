// INTERFACING LCD 4 BIT MODE
#include <reg52.h>
#include <string.h>
#include "..\..\LIBRARY\delay.h"

sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

void LCD_init(); //khoi tao
void WriteCommand(unsigned char cmd); // Gui lenh cho LCD
void WriteChar(char c); // Gui ky tu
void WriteString(char *s);
void ShiftLeft(char *s, char *s2);
void delay(unsigned int t) {
    while(t--);
}

char chuoi1[] = "MANCHESTER UNITED";
char chuoi2[] = "OLD TRAFFORD";

int main() {
		LCD_init();
		WriteCommand(0xC2);
		WriteString(chuoi2);
		ShiftLeft(chuoi1,chuoi2);
	
		return 0;
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
void ShiftLeft(char *s, char *s2) {
		unsigned char j, i, c, n;
		n = strlen(s)-1; j = 0; c = 15;
		while (c) {
				WriteCommand(0x80+c);
				for (i = 0; i <= j; i++) {
					WriteChar(s[i]);
				}
				WriteCommand(0xC2);
				WriteString(s2);
				delay_ms(400);
				WriteCommand(0x01);
				WriteCommand(0xC2);
				WriteString(s2);
				c--; j++;
		}
		while (c <= n) {
				WriteCommand(0x80);
				for (i = c; i <= n; i++) {
						WriteChar(s[i]);//in tu ky tu thu i den ky tu thu n
				}
				WriteCommand(0xC2);
				WriteString(s2);
				delay_ms(400);
				WriteCommand(0x01);
				WriteCommand(0xC2);
				WriteString(s2);
				c++;
		}
}