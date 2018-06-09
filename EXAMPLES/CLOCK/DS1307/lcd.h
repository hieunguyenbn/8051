#ifndef _LCD_H_
#define _LCD_H_

//Ham ra lech cho LCD
void LCD_cmd(int a);

//Ham hien thi 1 ky tu len LCD
void LCD_char(char a);

//Ham hien thi 1 xau len LCD
void LCD_str(char *c);

//Ham hien thi 1 xau tai vi tri nhap vao
void LCD_str_pos(unsigned char row, unsigned char col, char *a);

//Ham hien thi 1 ky tu tai vi tri nhap vao
void LCD_char_pos(unsigned char row, unsigned char col, char a);

//Khoi tao LCD
void LCD_init();

#endif