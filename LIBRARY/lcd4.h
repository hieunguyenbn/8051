#ifndef _LCD4_H_
#define _LCD4_H_

void LCD_init(); //khoi tao
void WriteCommand(unsigned char cmd); // Gui lenh cho LCD
void WriteChar(char c); // Gui ky tu
void WriteString(char *s);

#endif