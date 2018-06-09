#ifndef _LCD16x2_H_
#define _LCD16x2_H_
/*
- Thu vien giao tiep LCD 16x2 che do 4 bit.

Khi su dung thu vien can chu y cac khai bao kiet noi phan cung cho phu hop
O che do giao tiep 4 bit, chan RW cua LCD duoc noi voi nguon 0 volt (GND)
*/
sbit LCD_RS  = P0^0;
//sbit LCD_RW	 = P0^1;
sbit LCD_EN  = P0^1;
sbit LCD_D4  = P0^2;
sbit LCD_D5  = P0^3;
sbit LCD_D6  = P0^4;
sbit LCD_D7  = P0^5;

void LCD_Delay(unsigned int time)
{
	while(time)
		time--;
}
void LCD_Enable(void)
{
	LCD_EN = 1;
	LCD_Delay(3);
	LCD_EN = 0;
	LCD_Delay(50); 
}
//Ham Gui 4 Bit Du Lieu Ra LCD
void LCD_Send4Bit(unsigned char Data)
{
	LCD_D4 = Data & 0x01;
	LCD_D5 = (Data >> 1) & 1;
	LCD_D6 = (Data >> 2) & 1;
	LCD_D7 = (Data >> 3) & 1;
}
// Ham Gui 1 Lenh Cho LCD
void LCD_SendCommand (unsigned char command)
{
	LCD_Send4Bit(command >> 4);/* Gui 4 bit cao */
	LCD_Enable() ;
	LCD_Send4Bit(command);		/* Gui 4 bit thap*/
	LCD_Enable() ;
}
// Ham Khoi Tao LCD
void LCD_Init(void)
{
	LCD_Send4Bit(0x00);
	LCD_Delay(2000);
	LCD_RS = 0;
//	LCD_RW = 0;
	LCD_Send4Bit(0x03);
	LCD_Enable();
	LCD_Delay(500);
	LCD_Enable();
	LCD_Delay(100);
	LCD_Enable();
	LCD_Send4Bit(0x02);
	LCD_Enable();
	LCD_SendCommand(0x28);      // giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
	LCD_SendCommand(0x0c); 			// cho phep hien thi man hinh
	LCD_SendCommand(0x06);      // tang ID, khong dich khung hinh
	LCD_SendCommand(0x01); 			// xoa toan bo khung hinh
}
void LCD_Cmd(unsigned char cmd)
{
	LCD_RS = 0;
	LCD_Send4Bit(cmd >> 4); 
	LCD_EN = 1;
	LCD_EN = 0;

	LCD_Send4Bit(cmd);
	LCD_EN = 1;
	LCD_EN = 0;
}

void LCD_Gotoxy(unsigned char x, unsigned char y)
{
  unsigned char address;
  if(!y)
  address = (0x80 + x);
  else
  address = (0xC0 + x);
  LCD_Delay(1000);
  LCD_SendCommand(address);
  LCD_Delay(50);
}
// Ham Xoa Man Hinh LCD
void LCD_Clear()
{
  LCD_SendCommand(0x01);  
  LCD_Delay(10);
}
// Ham Gui 1 Ki Tu Len LCD
void LCD_PutChar(unsigned char Data)
{
	LCD_RS = 1;
	LCD_SendCommand(Data);
	LCD_RS = 0 ;
}

void LCD_Puts(char *str)
{
   while(*str)
   {
      LCD_PutChar(*str);
      str++;
   }
}
void LCD_Hex(unsigned char d)
{ 
	unsigned char byte = '0'; 
	
	(((d >> 4) & 0x0F) <= 9) ? (byte = '0' + ((d >> 4) & 0x0F)):(byte = 'A' + ((d >> 4) & 0x0F) - 0x0A);
	LCD_PutChar(byte);
	((d & 0x0F) <= 9) ? (byte = '0' + (d & 0x0F)):(byte = 'A' + ( d & 0x0F) - 0x0A); 
	LCD_PutChar(byte); 
}
#endif