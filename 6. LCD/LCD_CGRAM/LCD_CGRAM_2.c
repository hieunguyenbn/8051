/*  
   LCD16x2 8bit 8051 custom character
*/
#include<reg52.h>
#include "..\..\LIBRARY\delay.h"
//fr lcd_data_port=0x90;	/* P1 port asdata port */
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

void LCD_init(); //khoi tao
void WriteCommand(unsigned char cmd); // Gui lenh cho LCD
void WriteChar(char c); // Gui ky tu
void WriteString(char *s);
void LCD_Custom_Char (unsigned char loc, unsigned char *msg);
void delay(unsigned int t) {
    while(t--);
}


void main()
{
	char i;
	/* Custom char set for alphanumeric LCD Module */
	unsigned char Character1[8] = { 0x00, 0x0A, 0x15, 0x11, 0x0A, 0x04, 0x00, 0x00 };
	unsigned char Character2[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };
	unsigned char Character3[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00 };
	unsigned char Character4[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 };
	unsigned char Character5[8] = { 0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18 };
	unsigned char Character6[8] = { 0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04 };
	unsigned char Character7[8] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 };
	unsigned char Character8[8] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 };

	LCD_init();
	
	
	LCD_Custom_Char(0, Character1);  /* Build Character1 at position 0 */ 
	LCD_Custom_Char(1, Character2);  /* Build Character2 at position 1 */ 
	LCD_Custom_Char(2, Character3);  /* Build Character3 at position 2 */ 
	LCD_Custom_Char(3, Character4);  /* Build Character4 at position 3 */ 
	LCD_Custom_Char(4, Character5);  /* Build Character5 at position 4 */ 
	LCD_Custom_Char(5, Character6);  /* Build Character6 at position 5 */ 
	LCD_Custom_Char(6, Character7);  /* Build Character6 at position 6 */ 
	LCD_Custom_Char(7, Character8);  /* Build Character6 at position 7 */ 


	while (1) {
	WriteCommand(0x80);  	/* Cursor at home position */
  WriteString("Custom char LCD");			
	WriteCommand(0xC0);
	for(i=0;i<8;i++)	/* Function will send data 1 to 8 to lcd */
		{
			WriteChar(i);
			WriteChar(' ');	/* Space between each custom char */
		}
	WriteCommand(0x18);
		delay_ms(300);
	}

}
void LCD_Custom_Char (unsigned char loc, unsigned char *msg) {
	unsigned char i;
	if(loc<8)
	{
	/* Command 0x40 and onwards forces the device to point CGRAM address */
	WriteCommand (0x40 + (loc*8));
	for(i=0;i<8;i++)	/* Write 8 byte for generation of 1 character */
		WriteChar(msg[i]);      
    }   
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