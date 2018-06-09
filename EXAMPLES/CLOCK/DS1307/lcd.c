#include "LCD.h"
#include "main.h"
#include "port.h"

//Declare hardware connections (in port.h)
//sbit RS = P2^6;
//sbit RW = P2^5;
//sbit EN = P2^7;
//#define LCD P0
void delay(unsigned int t)
{
	int i,j;
	for(i=0;i<t;i++)
	{
		for(j=0;j<122;j++);
	}
}
 
//Ham ra lech cho LCD
void LCD_cmd(int a)
{
	RW = 0;
	RS = 0;
	LCD = a;
	EN = 0;
	EN = 1;
	if (a <= 0x01) delay(2);
	else delay(1);
}
//Ham hien thi 1 ky tu len LCD
void LCD_char(char a)
{
	RW = 0;
	RS = 1;
	LCD = a;
	EN = 0;
	EN = 1;
	delay(1);
}
//Ham hien thi 1 xau len LCD
void LCD_str(char *c)
{
	int i=0;
	while(c[i] != 0){
		LCD_char(c[i]);
		i++;
	}
}
//Ham hien thi 1 xau tai vi tri nhap vao
void LCD_str_pos(unsigned char row, unsigned char col, char *a)
{
	int cmd;
	//Di chuyen den vi tri hang row, cot col
	if (row == 1) cmd = 0x80 + col -1;
	if (row == 2) cmd = 0xc0 + col -1;
	LCD_cmd(cmd);
	LCD_str(a);
}
//Ham hien thi 1 ky tu tai vi tri nhap vao
void LCD_char_pos(unsigned char row, unsigned char col, char a)
{
	int cmd;
	//Di chuyen den vi tri hang row, cot col
	if (row == 1) cmd = 0x80 + col -1;
	if (row == 2) cmd = 0xc0 + col -1;
	LCD_cmd(cmd);
	LCD_char(a);
}
//Khoi tao LCD
void LCD_init()
{
	LCD_cmd(0x38);
	delay(5);
	LCD_cmd(0x38);
	delay(1);
	LCD_cmd(0x38);
	LCD_cmd(0x38); // hien thi 2 dong font chu la 5x7
	LCD_cmd(0x01);// xoa ma hinh
	LCD_cmd(0x0c);// bat hien thi con tro
}