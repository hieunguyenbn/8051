	
#include <main.h>

// Ham Khoi Tao LCD
 void lcd1602_enable(void)
{
	LCD_E=1;	
	delay_us(3);	 	
	LCD_E=0;
	delay_us(5); 	
}
// --------------------------------------------------
// Ham Gui 4 Bit Du Lieu Ra LCD
 void lcd1602_send_4bit_data ( unsigned char cX )
{
 LCD_D4 = cX & 0x01; 
 LCD_D5 = (cX>>1)&1;
 LCD_D6 = (cX>>2)&1;
 LCD_D7 = (cX>>3)&1;
}

// --------------------------------------------------
// Ham Gui 1 Lenh Cho LCD
 void lcd1602_send_command (unsigned char cX )
{
	lcd1602_send_4bit_data  ( cX >>4 );    	// send 4 bit high  
	lcd1602_enable() ;
	lcd1602_send_4bit_data ( cX  );		 			// send 4 bit low  
	lcd1602_enable() ;
}

// --------------------------------------------------
// Ham Khoi Tao LCD
 void lcd1602_init ( void )
{
	lcd1602_send_4bit_data ( 0x00 );
	delay_ms(200);
	
	LCD_RS=0;	
	LCD_RW=0;
	LCD_E=0;																	// che do gui lenh
	
	lcd1602_send_4bit_data ( 0x03 );          // ket noi 8 bit
	lcd1602_enable() ;
	lcd1602_enable () ;
	lcd1602_enable () ;
	lcd1602_send_4bit_data ( 0x02 );     	 		// ket noi 4 bit
	lcd1602_enable() ;
	
	lcd1602_send_command( 0x2C );     				// giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
	lcd1602_send_command( 0x80);
	lcd1602_send_command( 0x0C); 							// cho phep hien thi man hinh
	lcd1602_send_command( 0x06 );     			 	// tang ID, khong dich khung hinh
	lcd1602_send_command( CLEAR_LCD );      	// xoa toan bo khung hinh
}

// --------------------------------------------------
// Ham Thiet Lap Vi Tri Con Tro
void lcd1602_gotoxy(unsigned char x, unsigned char y)
{
  unsigned char address;
  if(!y)
  address = (LINE_1+x);
  else
  address = (LINE_2+x);
  delay_ms(3);
  lcd1602_send_command(address);
  delay_ms(1);
}

// --------------------------------------------------
// Ham Xoa Man Hinh LCD
void lcd1602_clear(void)
{
	lcd1602_send_command( CLEAR_LCD );  
  //delay_us(300);
}

// --------------------------------------------------
// Ham Gui 1 Ky Tu Len LCD
 void lcd1602_putchar ( unsigned int cX )
{
	LCD_RS=1;	
	lcd1602_send_command( cX );
  LCD_RS=0;
}

// --------------------------------------------------
// Ham Gui 1 Chuoi Ky Tu Len LCD
void lcd1602_puts(char *s)
{
   while (*s)
   {
			lcd1602_putchar(*s);
      s++;
   }
}






