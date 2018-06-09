// ***************************************************
// Cong dung: 
//	Chuong trinh su dung cac lenh de thuc hien viec dieu khien va hien thi cac
//	thong tin len man hinh LCD 2x16 duoc ket noi voi PIC theo kieu 4 bit
//	du lieu va 3 bit dieu khien.
//
//			Cot 0              15
//		       [----------------]
//		Hang 0 [                ]
//		Hang 1 [                ]
//			   [----------------]
//
//		Lenh lcd_init(): Khoi dong LCD. 
//		Lenh lcd_busy(): Thong bao LCD ban xu ly thong tin.
//		Lenh lcd_get_byte(rs): Doc mot byte du lieu tu LCD.
//		Lenh lcd_put_byte(rs, b): Ghi mot byte du lieu/lenh den LCD.
//		Lenh lcd_putc(c): Ghi mot ky tu den LCD.
//		Lenh lcd_gotoxy(col, row): Dinh toa do tren LCD.
//		Lenh lcd_puts(*s): Ghi mot chuoi den LCD.
//		Lenh lcd_cgram(): Luu cac ma ky tu dac biet vao vung nho CGRAM cua LCD.
//
//		Ket noi LCD:	RD<1> -> LCD_RS   		RD<4> -> LCD_DATA4.
//						RD<2> -> LCD_RW   		RD<5> -> LCD_DATA5.
//						RD<3> -> LCD_EN		  	RD<6> -> LCD_DATA6.
//												RD<7> -> LCD_DATA7.
//
//	Luu y: Cach ket noi va cac lenh dung cho LCD xem them trong file lcd.h
//
//	Hieu chinh va bo sung: PHAM QUANG TRI - Ho Chi Minh University of Industry.
//
// *************************************************** 
#include <stdlib.h>
#include <ctype.h>
#include "lcd.h"	// Cau hinh ket noi va khai bao lenh dung cho LCD.

// ***************************************************
// Ten CTC:				lcd_init().
// Thong so dau vao: 	Xem cach ket noi phan cung LCD nhu tren.	
// Thong so dau ra:	
// Cong dung:     		Khoi dong LCD theo cau hinh 4 bit du lieu.
// ***************************************************
void lcd_init()
{
// Khai bao bien.
unsigned char i;

// Dinh nghia ham.  
	LCD_EN_TRIS = 0;		// Cau hinh ngo ra cac duong dieu khien.
	LCD_RS_TRIS = 0;
	LCD_RW_TRIS = 0;

	LCD_DATA4_TRIS = 0;		// Cau hinh ngo ra cho cac duong du lieu.
	LCD_DATA5_TRIS = 0;
	LCD_DATA6_TRIS = 0;
	LCD_DATA7_TRIS = 0;

	LCD_EN = 0;		// EN = 0 - Disable.
	LCD_RS = 0;		// RS = 0 - Command.
	LCD_RW = 0;		// RW = 0 - Write.

	__delay_ms(100);	// Tao thoi gian tre khi bat nguon cho LCD.
	
	// Reset LCD.
	lcd_put_byte(0,0x30);
	__delay_ms(50);
	lcd_put_byte(0,0x30);
	__delay_ms(50);
	lcd_put_byte(0,0x32);
	__delay_ms(100);				// Tao tre de reset LCD.
	__delay_ms(100);				// 
	__delay_ms(100);				// 
	
	while(lcd_busy());
	lcd_put_byte(0,FOUR_BIT & LINES_5X7);			// Thiet lap loai LCD.
	while(lcd_busy());
	
	lcd_put_byte(0,DOFF&CURSOR_OFF&BLINK_OFF);		// Tat hien thi.
	while(lcd_busy());
	lcd_put_byte(0,DON&CURSOR_OFF&BLINK_OFF);		// Bat hien thi.
	while(lcd_busy());
	
	lcd_put_byte(0,0x01);				// Xoa hien thi va di chuyen con tro ve dau dong.
	while(lcd_busy());
	lcd_put_byte(0,SHIFT_CUR_LEFT);		// Che do dich chuyen con tro.
	while(lcd_busy());
	lcd_put_byte(0,0x01);				// Xoa hien thi va di chuyen con tro ve dau dong.
	while(lcd_busy());
}

// ***************************************************
// Ten CTC:				lcd_busy().
// Thong so dau vao: 		
// Thong so dau ra:		Tra ve gia tri: <0> Khong ban  -  <1> Bao ban.
// Cong dung:     		Thong bao LCD dang ban xu ly thong tin.
// ***************************************************
unsigned char lcd_busy()
{
// Khai bao bien.
unsigned char busy;

// Dinh nghia ham.
	LCD_DATA4_TRIS = 1;		// Cau hinh ngo vao cho cac duong du lieu.
	LCD_DATA5_TRIS = 1;
	LCD_DATA6_TRIS = 1;
	LCD_DATA7_TRIS = 1;
	
	LCD_RW = 1;		// RW = 1 - Read.
	LCD_RS = 0;		// RS = 0 - Command.
	__delay_us(20);
	LCD_EN = 1;		// EN = 1 - Enable.
	__delay_us(20);
	
	busy = LCD_DATA7;	// Doc gia tri co bao ban tu LCD.
	
	LCD_EN = 0;		// EN = 0 - Disable.
	__delay_us(20);
	LCD_EN = 1;		// EN = 1 - Enable. Tao xung truyen thong tin.
	__delay_us(20);
	LCD_EN = 0;		// EN = 0 - Disable.
	
	return busy;	// Tra ve gia tri bao LCD ban hay khong (1: Busy).
}

// ***************************************************
// Ten CTC:				lcd_get_byte(rs).
// Thong so dau vao: 	rs: Chon lua doc lenh (Command) hay du lieu (Data) tu LCD.
//							rs = 0: Command   -   rs = 1: Data.
//						Can xac dinh toa do du lieu can doc tu LCD truoc ham nay.
// Thong so dau ra:		Gia tri byte doc duoc tu LCD.		
// Cong dung:     		Doc 1 byte tu LCD tai toa do xac dinh tu truoc.
// ***************************************************
unsigned char lcd_get_byte(unsigned char rs)
{
// Khai bao bien.
	BYTE_VAL b;		// Bien chua gia tri doc ve tu LCD. 

// Dinh nghia ham.
	LCD_DATA4_TRIS = 1;		// Cau hinh ngo vao cho cac duong du lieu.
	LCD_DATA5_TRIS = 1;
	LCD_DATA6_TRIS = 1;
	LCD_DATA7_TRIS = 1;
	
	LCD_RW = 1;		// RW = 1 - Read.
	LCD_RS = 0;		// RS = 0 - Command. Mac dinh la doc Command.
	
	if (rs) LCD_RS = 1;		// Kiem tra yeu cau doc Data (rs = 1) hay doc Command (rs = 0).
							//		RS = 1 - Data. Neu chon lua doc Data.
	__delay_us(20);
	LCD_EN = 1;		// EN = 1 - Enable. Doc 4 bit cao cua thong tin can doc tu LCD.
	__delay_us(20);
	
	b.bits.b7 = LCD_DATA7;	// Doc 4 bit cao.
	b.bits.b6 = LCD_DATA6;
	b.bits.b5 = LCD_DATA5;
	b.bits.b4 = LCD_DATA4;
	
	LCD_EN = 0;		// EN = 0 - Disable.
	__delay_us(20);
	LCD_EN = 1;		// EN = 1 - Enable. Doc 4 bit thap cua thong tin can doc tu LCD.
	__delay_us(20);
	
	b.bits.b3 = LCD_DATA7;	// Doc 4 bit thap.
	b.bits.b2 = LCD_DATA6;
	b.bits.b1 = LCD_DATA5;
	b.bits.b0 = LCD_DATA4;
	
	LCD_EN = 0;		// EN = 0 - Disable.
	
	return b.Val;	// Tra ve gia tri doc duoc tu LCD (8 bit).
}

// ***************************************************
// Ten CTC:				lcd_put_byte(rs, b).
// Thong so dau vao: 	rs: Chon lua doc lenh (Command) hay du lieu (Data) tu LCD.
//							rs = 0: Command   -   rs = 1: Data.
//						b: Gia tri 8 bit cua thong tin can ghi vao LCD.
//						Can xac dinh toa do du lieu can doc tu LCD truoc ham nay.
// Thong so dau ra:				
// Cong dung:     		Ghi 1 byte vao LCD tai toa do xac dinh tu truoc.
// ***************************************************
void lcd_put_byte(unsigned char rs, unsigned char b)
{
// Khai bao bien.
	BYTE_VAL temp;		// Bien luu tam thong tin.

// Dinh nghia ham.
	LCD_DATA4_TRIS = 0;		// Cau hinh ngo ra cho cac duong du lieu.
	LCD_DATA5_TRIS = 0;
	LCD_DATA6_TRIS = 0;
	LCD_DATA7_TRIS = 0;
	
	LCD_RS = 0;		// RS = 0 - Command. Mac dinh la ghi Command.
	if(rs) LCD_RS = 1;		// Kiem tra yeu cau ghi Data (rs = 1) hay ghi Command (rs = 0).
							//		RS = 1 - Data. Neu chon lua ghi Data.
	__delay_us(20);
	LCD_RW = 0;		// RW = 0 - Write.
	__delay_us(20);
	LCD_EN = 0;		// EN = 0 - Disable.
	
	temp.Val = b;	// Lay gia tri thong tin can ghi vao LCD.
	
	LCD_DATA4 = temp.bits.b4;	// Gui 4 bit cao len bus.
	LCD_DATA5 = temp.bits.b5;
	LCD_DATA6 = temp.bits.b6;
	LCD_DATA7 = temp.bits.b7;

	__delay_us(20);
	LCD_EN =  1;	// EN = 1 - Enable. Ghi 4 bit cao cua thong tin vao LCD.
	__delay_us(20);
	LCD_EN = 0;		// EN = 0 - Disable.

	LCD_DATA4 = temp.bits.b0;	// Gui 4 bit thap len bus.
	LCD_DATA5 = temp.bits.b1;
	LCD_DATA6 = temp.bits.b2;
	LCD_DATA7 = temp.bits.b3;

	__delay_us(20);
	LCD_EN =  1;	// EN = 1 - Enable. Ghi 4 bit thap cua thong tin vao LCD.
	__delay_us(20);
	LCD_EN = 0;		// EN = 0 - Disable.
}

// ***************************************************
// Ten CTC:				lcd_putc(c).
// Thong so dau vao: 	c: Lenh dieu khien va thong tin hien thi.
//							/f: Xoa hien thi.
//							/n: Bat dau dong moi.
//							/b: Lui ve 1 vi tri.
//							Mac dinh la hien thi cac ky tu co kha nang hien thi duoc.
// Thong so dau ra:				
// Cong dung:     		Hien thi ky tu va dieu khien cac chuc nang hoat dong cua LCD.
// ***************************************************
void lcd_putc(char c)
{
// Khai bao bien.

// Dinh nghia ham.
	switch(c)
		{
		case '\f':		// Chuc nang xoa hien thi.
			lcd_put_byte(0,0x01);		// Goi ham truyen thong tin (lenh) sang C.LCD.
			while(lcd_busy());			// Kiem tra LCD bao ban.
			break;						// Lenh: Xoa hien thi tren man hinh C.LCD (0x01).
		case '\n':		// Chuc nang bat dau hang thu 2.
			lcd_gotoxy(0,1);			// Goi ham truyen thong tin (du lieu) sang C.LCD.
			break;
    	case '\b': 		// Chuc nang lui ve 1 vi tri.
			lcd_put_byte(0,0x10); 		// Goi ham truyen thong tin (lenh) sang C.LCD. 
			while(lcd_busy());			// Kiem tra LCD bao ban.
			break;						// Lenh: Doi con tro sang trai (0x10).
		default:	// Hien thi tat ca ky tu mac dinh trong LCD (c: dia chi HEX cua ky tu)
			// if(isprint(c))	// Dong lenh dung khi chi muon hien thi nhung ky tu tren ban phim PC?
			//	{				
				lcd_put_byte(1,c);		// Gui thong tin sang LCD de hien thi tai toa do da xac dinh.
				while(lcd_busy());		// Kiem tra LCD bao ban.
			//	}
			break;
		}
}

// ***************************************************
// Ham duoi day duoc su dung de cho phep xuat thong tin ra LCD bang
// lenh printf().
// ***************************************************
void putch(char c)
{
	lcd_putc(c);
}

// ***************************************************
// Ten CTC:				lcd_gotoxy(col, row).
// Thong so dau vao: 	col: Toa do cot hien thi (0 - 15).
//						row: Toa do hang hien thi (0 - 1).
// Thong so dau ra:				
// Cong dung:     		Xac dinh toa do hien thi thong tin tren LCD.
// ***************************************************
void lcd_gotoxy(unsigned char col, unsigned char row)
{
// Khai bao bien.
unsigned char address;

// Dinh nghia ham.
	if(row!=0)		// Kiem tra hang hien thi de tao dia chi hien thi hang. 
		address=0x40;	// Ma dieu khien hien thi hang 2.
	else
		address=0x00;	// Ma dieu khien hien thi hang 1.
	
	address += col;		// Ket hop gia tri hang va cot de tao ra dia chi hien thi.

	lcd_put_byte(0,0x80|address);	// Gui lenh xac dinh toa do hien thi tren LCD.

	while(lcd_busy());		// Kiem tra LCD bao ban.
}

// ***************************************************
// Ten CTC:				lcd_puts(*s).
// Thong so dau vao: 	s: Chuoi thong tin can hien thi.
// Thong so dau ra:				
// Cong dung: 			Hien thi chuoi thong tin len LCD.
// ***************************************************
void lcd_puts(const char *s)
{
// Khai bao bien.

// Dinh nghia ham.
	while(*s)
		{
		lcd_putc(*s++);
		}
}