/*
   LCD_20x4_H_file.h
   http://www.electronicwings.com
 */

#ifndef LCD_20x4_H_H_					/* Define library H file if not defined */
#define LCD_20x4_H_H_

#include <reg52.h>
#include <intrins.h>

#define LCD_Data_Port P2
sbit EN=P1^2;							/* Define Enable signal pin */
sbit RW=P1^1;							/* Define Read/Write signal pin */
sbit RS=P1^0;							/* Define Register Select (data reg./command reg.) signal pin */

void LCD_Command (char);				/* LCD command write function */
void LCD_Char (char);					/* LCD data write function */
void LCD_Init (void);					/* LCD Initialize function */
void LCD_String (char*);				/* Send string to LCD function */
void LCD_String_xy (char,char,char*);	/* Send row, position and string to LCD function */
void LCD_Clear (void);					/* LCD clear function */
void delay(int);

#endif									/* LCD_20x4_H_FILE_H_ */