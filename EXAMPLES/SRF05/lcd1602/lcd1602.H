	
#ifndef __LCD1602_H
#define __LCD1602_H

#include <main.h>

#define LINE_1 0x80
#define LINE_2 0xC0
#define CLEAR_LCD 0x01

// PORT2 -----------------------------------------
// Cac chan dieu khien cua LCD -------------------
#define LCD_RS 				 P0_7
#define LCD_RW 				 P0_6
#define LCD_E 				 P0_5

// Cac chan du lieu cua LCD ----------------------
#define LCD_D4 P2_4
#define LCD_D5 P2_5
#define LCD_D6 P2_6
#define LCD_D7 P2_7
#define LCD_DATA P2

void lcd1602_enable(void);
void lcd1602_send_4bit_data ( unsigned char cX );
void lcd1602_send_command (unsigned char cX );
void lcd1602_init (void );
void lcd1602_gotoxy(unsigned char x, unsigned char y);
void lcd1602_clear(void);
void lcd1602_putchar ( unsigned int cX );
void lcd1602_puts (char *s);
//void lcd_putsf(char flash *s);

#endif
// ------------------END OF FILE--------------------
// -------------------------------------------------
