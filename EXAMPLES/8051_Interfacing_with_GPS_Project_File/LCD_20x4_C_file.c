/*
   LCD_20x4_C_file.c
   http://www.electronicwings.com
 */


#include "LCD_20x4_H_file.h"						/* Include LCD header file */


void LCD_Command (char cmd)							/* LCD command write function */
{
	LCD_Data_Port = cmd;							/* Write command data to LCD data port */
	RS = 0;			/* Make RS LOW (command reg.), RW LOW (Write) */
	RW = 0;
	EN = 1;					/* High to Low transition on EN (Enable) */
	delay(1);
	EN = 0;
	delay(5);									/* Wait little bit */
}

void LCD_Char (char char_data)/* LCD data write function */
{
	LCD_Data_Port = char_data;	/* Write data to LCD data port */
	RS = 1;			                /* Make RS LOW (command reg.), RW LOW (Write) */
	RW = 0;
	EN = 1;	             				/* High to Low transition on EN (Enable) */
	delay(1);
	EN = 0;
	delay(5);							/* Wait little bit */
}

void LCD_Init (void)								/* LCD Initialize function */
{	
	delay(30);									/* LCD power up time to get things ready, it should always >15ms */
	LCD_Command (0x38);								/* Initialize 16X2 LCD in 8bit mode */
	LCD_Command (0x0C);								/* Display ON, Cursor OFF command */
	LCD_Command (0x06);								/* Auto Increment cursor */
	LCD_Command (0x01);								/* Clear LCD command */
	delay(3);
	LCD_Command (0x80);								/* 8 is for first line and 0 is for 0th position */
}

void LCD_String (char *str)							/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)							/* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);							/* Call LCD data write */
	}
}

void LCD_String_xy (char row, char pos, char *str)	/* Send string to LCD function */
{
	if (row == 1)
		LCD_Command((pos & 0x0F)|0x80);				/* Command of first row and required position<16 */
	else if (row == 2)
		LCD_Command((pos & 0x0F)|0xC0);				/* Command of Second row and required position<16 */
	else if (row == 3)
		LCD_Command((pos & 0x0F)|0x94);				/* Command of Third row and required position<16 */
	else if (row == 4)
		LCD_Command((pos & 0x0F)|0xD4);				/* Command of Fourth row and required position<16 */
	LCD_String(str);								/* Call LCD string function */
}

void LCD_Clear (void)								/* LCD clear function */
{
	LCD_Command (0x01);								/* Clear LCD command */
	delay(5);
	LCD_Command (0x80);								/* 8 is for first line and 0 is for 0th position */
	
}
void delay(int k)
{
	int i,j;
	for (i=0;i<k;i++)
		for (j=0;j<112;j++);
}
