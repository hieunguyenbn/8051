#include "regx52.h"
#include "Library\RFID.h"
#include "Library\LCD16x2.h"
#include "Library\I2C.h"


//sbit BUZ	= P1^1;
sbit LCD_LED = P0^6;
sbit DOOR 	 = P0^7;

sbit KEY_COT1  = P3^0;
sbit KEY_COT2  = P3^1;
sbit KEY_COT3  = P3^2;
sbit KEY_HANG1 = P3^3;
sbit KEY_HANG2 = P3^4;
sbit KEY_HANG3 = P3^5;
sbit KEY_HANG4 = P3^6;

#define KEYTIME 80

unsigned int	DocPhim;
unsigned char Mode, Dem, Doi, Key;
unsigned char KetQua1, KetQua2;
unsigned char GioiHan = 0, SaiMK = 0;

unsigned char idata MatKhauCu[8];
unsigned char idata MatKhauMoi[8];
unsigned char idata LuuPhim[8];
unsigned char idata UID[5];
//Thay doi so ID card o day
unsigned char idata Card1[] = {0x40, 0xAC, 0x53, 0x7E, 0xC1};
unsigned char idata Card2[] = {0x57, 0xDB, 0x5D, 0x59, 0x88};
unsigned char idata Card3[] = {0x14, 0xA9, 0xDF, 0x59, 0x3B};

void Delay_ms(unsigned int time)
{
	unsigned int x, y;
	
	for(x = 0; x < time; x++)
	{
		for(y = 0; y < 124; y++)
		{
		}
	}
}//_____________________________________________________________________________________________________________________________
//		Ham giao tiep Eeprom
bit Check_Eeprom()
{
	bit AckTemp = 0;
	I2c_Start();
	I2c_Write(0xa0);
	AckTemp = I2c_CheckAck();
	if(AckTemp == 1) return 0;
	else return 1;
}
void Eeprom24C_Write(unsigned char address,unsigned char Data)
{
	bit AckTemp = 1;
	I2c_Start();
	I2c_Write(0xa0);
	AckTemp = I2c_CheckAck();
	I2c_Write(address);             
	AckTemp = I2c_CheckAck();
	I2c_Write(Data);           
	AckTemp = I2c_CheckAck();
	I2c_Stop();
	Delay_ms(100);
}

unsigned char Eeprom24C_Read(unsigned char address)
{
	bit AckTemp = 1;
	unsigned char Data;
	
	I2c_Start();
	I2c_Write(0xa0);
	AckTemp = I2c_CheckAck();
	I2c_Write(address);
	AckTemp = I2c_CheckAck();
	I2c_Start();
	I2c_Write(0xa1);
	AckTemp = I2c_CheckAck();
	Data=I2c_Read();
	AckTemp = I2c_CheckAck();
	I2c_Stop();
	return Data;
}

void Eeprom24C_WriteS(unsigned char address, unsigned char *s)
{
	while(*s)
	{
		Eeprom24C_Write(address++, *s);
		s++;
	}
}
void Eeprom24C_ReadS(unsigned char address, unsigned char lenght, unsigned char *s)
{
	unsigned char  i = 0;
	while(lenght)
	{
		s[i++] = Eeprom24C_Read(address++);
		lenght--;
	}
	s[++i] = 0;
}//__________________________________________________________________________________________________________________
void KhoiTao_Timer(void) 		// Khoi tao timer
{
	TMOD = 0x02;  // Chon che do 2 cho timer 0 ( Thanh ghi TMOD = 00000010 ) 
	EA = 1;       // cho phep ngat toan cuc 
	ET0 = 1;      // cho phep ngat T0 
  TF0 = 0;
  TR0 = 1;
}
//__________________________________________________________________________________________________________________
void Xoa_Mang()
{
	unsigned char a;

	GioiHan = 0;
	for(a = 0; a < 8; a++)
	{
		LuuPhim[a] = 'n';
	}
}//___________________________________________________________________________________________________________________
void Clear_Data()
{
	Xoa_Mang();
	Dem = 0;
	Doi = 0;
	Mode = 0;
	KetQua1 = 0;
	LCD_Clear();
}//______________________________________________________________________________________________________________________________________________
unsigned char KeyPress()
{
	unsigned char key = 0;

	KEY_COT1 = 0; // cot 1 = 0
// Kiem tra lan luot cac HANG
	if(KEY_HANG1 == 0)
	{
		Delay_ms(KEYTIME);
		if(KEY_HANG1 == 0)
		{
			key = '1';	// 1
			DocPhim = 0;
		}
	}
	if(KEY_HANG1 == KEY_HANG1 && DocPhim < 1000)
	{
		DocPhim++;
	}
	
	if(KEY_HANG2 == 0)
	{
		Delay_ms(KEYTIME);
		if(KEY_HANG2 == 0)
		{
			key = '4';	// 4
			DocPhim = 0;
		}
	}
	if(KEY_HANG2 == KEY_HANG2 && DocPhim < 1000)
	{
		DocPhim++;
	}
	
	if(KEY_HANG3 == 0)
	{
		Delay_ms(KEYTIME);
		if(KEY_HANG3 == 0)
		{
			key = '7';	// 7
			DocPhim = 0;
		}
	}
	if(KEY_HANG3 == KEY_HANG3 && DocPhim < 1000)
	{
		DocPhim++;
	}
	
//	if(KEY_HANG4 == 0)
//	{
//		Delay_ms(KEYTIME);
//		if(KEY_HANG4 == 0)
//		{
//			key = 0x2A;	// *
//			DocPhim = 0;
//		}
//	}
//	if(KEY_HANG4 == KEY_HANG4 && DocPhim < 1000)
//	{
//		DocPhim++;
//	}
	
	KEY_COT1 = 1;
//--------------------------------------------------------------------
	KEY_COT2 = 0; // Cot 2 = 0
// Kiem tra lan luot cac HANG
	if(KEY_HANG1 == 0)
	{
		Delay_ms(KEYTIME);
		if(KEY_HANG1 == 0)
		{
			key = '2';	// 2
			DocPhim = 0;
		}
	}
	if(KEY_HANG1 == KEY_HANG1 && DocPhim < 1000)
	{
		DocPhim++;
	}
	
	if(KEY_HANG2 == 0)
	{
		Delay_ms(KEYTIME);
		if(KEY_HANG2 == 0)
		{
			key = '5';	// 5
			DocPhim = 0;
		}
	}
	if(KEY_HANG2 == KEY_HANG2 && DocPhim < 1000)
	{
		DocPhim++;
	}
	
	if(KEY_HANG3 == 0)
	{
		Delay_ms(KEYTIME);
		if(KEY_HANG3 == 0)
		{
			key = '8';	// 8
			DocPhim = 0;
		}
	}
	if(KEY_HANG3 == KEY_HANG3 && DocPhim < 1000)
	{
		DocPhim++;
	}
	
	if(KEY_HANG4 == 0)
	{
		Delay_ms(KEYTIME);
		if(KEY_HANG4 == 0)
		{
			key = '0';	// 0
			DocPhim = 0;
		}
	}
	if(KEY_HANG4 == KEY_HANG4 && DocPhim < 1000)
	{
		DocPhim++;
	}
	
	KEY_COT2 = 1;
//-----------------------------------------------------------
	KEY_COT3 = 0; // Cot 3 = 0
// Kiem tra lan luot cac HANG
	if(KEY_HANG1 == 0)
	{
		Delay_ms(KEYTIME);
		if(KEY_HANG1 == 0)
		{
			key = '3';	// 3
			DocPhim = 0;
		}
	}
	if(KEY_HANG1 == KEY_HANG1 && DocPhim < 1000)
	{
		DocPhim++;
	}
	
	if(KEY_HANG2 == 0)
	{
		Delay_ms(KEYTIME);
		if(KEY_HANG2 == 0)
		{
			key = '6';	// 6
			DocPhim = 0;
		}
	}
	if(KEY_HANG2 == KEY_HANG2 && DocPhim < 1000)
	{
		DocPhim++;
	}
	
	if(KEY_HANG3 == 0)
	{
		Delay_ms(KEYTIME);
		if(KEY_HANG3 == 0)
		{
			key = '9';	// 9
			DocPhim = 0;
		}
	}
	if(KEY_HANG3 == KEY_HANG3 && DocPhim < 1000)
	{
		DocPhim++;
	}
	if(KEY_HANG4 == 0)
	{
		Delay_ms(KEYTIME);
		if(KEY_HANG4 == 0)
		{
			key = 0x23;	// #
			DocPhim = 0;
		}
	}
	if(KEY_HANG4 == KEY_HANG4 && DocPhim < 1000)
	{
		DocPhim++;
	}
	
	KEY_COT3 = 1;
	
	if(DocPhim == 1000) 
	{
		if(Dem != 0 || Doi != 0)
		{
			if(Mode <= 0)
			{
				LCD_LED = 0;
				LCD_Cmd(0x0C);
				Clear_Data();
			}
			else 
			{
				LCD_LED = 1;
				DocPhim = 0;
			}
		}
		LCD_LED = 0;
	}
	if(DocPhim < 1000)
	{
		LCD_LED = 1;
	}
	return key;
}//__________________________________________________________________________________________________________________
void Doc_Phim(void)
{
	unsigned int i;
	
	if(!KEY_HANG4)
	{
		while(!KEY_HANG4 & i < 50){i++; Delay_ms(50);}
		Delay_ms(50);
		if(Mode == 0)
		{
			if(i < 50)
			{
				Dem++;
				if(Dem == 2) 
				{
					Dem = 0;
					Doi = 0;
					Mode = 0;
				}
				if(Dem > 0 && Doi > 0)
				{
					Dem = 0;
					Doi = 0;
					Mode = 0;
				}
			}
			if(i == 50)
			{
				Dem = 0;
				Doi = 1;
				Mode = 0;
			}
			LCD_Clear();
		}
	}
	else i = 0;//-----------------------------------------------------------------------
}//________________________________________________________________________________________________________
void Key_Inputs()
{
	if(GioiHan < 8)
	{
		LCD_PutChar(Key);
		LuuPhim[GioiHan] = Key;
		GioiHan++;
		Delay_ms(50);
		LCD_Cmd(0x10);
		LCD_PutChar('*');
	}
}//____________________________________________________________________________________________________________________
void Key_Clear()
{
	if(GioiHan > 0 && Key == 0x23)
	{
		GioiHan--;
		LuuPhim[GioiHan] = 'n';
		Delay_ms(50);
		LCD_Gotoxy(GioiHan + 4, 1);
		LCD_Puts(" ");
		LCD_Cmd(0x11);
	}
}
//________________________________________________________________________________________________________________________
void Ket_Qua()
{
	unsigned char x;
	
	if(KetQua1 == 1)
	{
		LCD_Clear();
		LCD_Gotoxy(3, 0);
		LCD_Puts("Cua Da Mo");
		Delay_ms(2000);
		SaiMK = 0;
		Clear_Data();
	}
	if(KetQua1 == 2)
	{
		LCD_Clear();
		LCD_Gotoxy(2, 0);
		LCD_Puts("Sai Mat Khau");
		Delay_ms(1000);
		SaiMK++;
		Clear_Data();
		Dem = 1;
		if(SaiMK == 3)
		{
			LCD_Gotoxy(0, 0);
			LCD_Puts("Nhap sai 3 lan");
			LCD_Gotoxy(0, 1);
			LCD_Puts("Wait...");
			for(x = 60; x > 0; x--)
			{
				LCD_Gotoxy(7, 1);
				LCD_PutChar((x / 10) + 0x30);
				LCD_PutChar((x % 10) + 0x30);
				LCD_Gotoxy(10, 1);
				LCD_Puts("second");
				Delay_ms(1000);
				if(x <= 0)
				{
					Clear_Data();
					SaiMK = 0;
					break;
				}
			}
			Clear_Data();
		}
	}
}//____________________________________________________________________________________________________________________
void Background1(void)
{
	if(Dem == 0 && Doi == 0)
	{
		LCD_Gotoxy(1, 0);
		LCD_Puts("Design Tuan Anh");
		LCD_Gotoxy(0, 1);
		LCD_Puts("Phone:0964264325");
	}
	if(Dem == 1 && Doi == 0)
	{
		LCD_Gotoxy(5, 0);
		LCD_Puts("Mo Khoa");
		LCD_Gotoxy(0, 1);
		LCD_PutChar('*');
		LCD_Gotoxy(2, 1);
		LCD_PutChar(0x7F);
		LCD_Gotoxy(13, 1);
		LCD_PutChar(0x7E);
		LCD_Gotoxy(15, 1);
		LCD_PutChar('#');
		
	}
	if(Dem == 0 && Doi == 1)
	{	
		LCD_Gotoxy(2, 0);
		LCD_Puts("Doi Mat Khau");
		LCD_Gotoxy(0, 1);
		LCD_PutChar('*');
		LCD_Gotoxy(2, 1);
		LCD_PutChar(0x7F);
		LCD_Gotoxy(13, 1);
		LCD_PutChar(0x7E);
		LCD_Gotoxy(15, 1);
		LCD_PutChar('#');
	}
	if(Dem == 6 && Doi == 6)
	{
		Dem = 5;
		Doi = 5;
		Mode = 5;
		LCD_Gotoxy(0, 0);
		LCD_Puts("Thiet Lap MK Moi");
		LCD_Gotoxy(4, 1);
		LCD_Cmd(0x0F);
	}
	else if(Dem == 1 && Doi == 0)
	{
		if(Key == 0x23)
		{
			Dem = 5;
			Doi = 5;
			Mode = 1;
			LCD_Clear();
			LCD_Gotoxy(2, 0);
			LCD_Puts("Nhap Mat Khau");
			LCD_Gotoxy(4, 1);
			LCD_Cmd(0x0F);
		}
	}
	else if(Dem == 0 && Doi == 1)
	{
		if(KEY_HANG4 != 0 && Key == 0x23)
		{
			Dem = 7;
			Doi = 7;
			Mode = 2;
			LCD_Clear();
			LCD_Gotoxy(0, 0);
			LCD_Puts("Nhap Mat Khau Cu");
			LCD_Gotoxy(4, 1);
			LCD_Cmd(0x0F);		// Bat nhay con tro
		}
	}
}//__________________________________________________________________________________________________________________


void main()
{
	unsigned char x, temp;
	
	LCD_Init();
	Delay_ms(100);
	I2c_Init();
	MFRC522_Init();
		temp = Eeprom24C_Read(0x08);
		if(temp != 0x2A)
		{
			LCD_Gotoxy(0, 0);
			LCD_Puts("Chua Tao MK !!! ");
			Delay_ms(2000);
			Dem = 6;
			Doi = 6;
		}
		if(temp == 0x2A)
		{
			LCD_Gotoxy(0, 0);
			LCD_Puts("MK Da Thiet Lap!");
			Eeprom24C_ReadS(0x00, 8, MatKhauCu);
			Delay_ms(2000);
		}
		LCD_Clear();

	while(1)
	{
		Key = KeyPress();
		Background1();
		if(!KEY_HANG4)
		{
			LCD_LED = 1;
			DocPhim = 0;
			Doc_Phim();
		}
		if(Dem == 0 && Doi == 0 && KEY_HANG4 == 1)
		{
			if(MFRC522_isCard())
			{
				if(MFRC522_ReadCardSerial(UID))
				{
					LCD_LED = 1;
					for(x = 0; x < 5; )
					{
						if(UID[x] == Card1[x] || UID[x] == Card2[x] || UID[x] == Card3[x])
						{
							x++;
							if(x == 5)
							{
								LCD_Clear();
								LCD_Gotoxy(3, 0);
								LCD_Puts("The hop le");
								DOOR = 0;
								Delay_ms(2000);
								DOOR = 1;
								LCD_Gotoxy(0, 1);
								LCD_Puts("Cua Da mo");
								Delay_ms(4000);
							}
						}
						else
						{
							LCD_Clear();
							LCD_Gotoxy(3, 0);
							LCD_Puts("Sai ma the");
							Delay_ms(3000);
							break;
						}
					}
				}
				LCD_LED = 0;
				LCD_Clear();
			}
			MFRC522_Halt();
		}
		if(Mode == 1)
		{
			if(!KEY_HANG4)
			{
				LCD_Cmd(0x0C);
				Clear_Data();
			}
			Key_Clear();
			if(Key != 0 && Key != 0x23)
			{
				Key_Inputs();
				if(GioiHan == 8)
				{
					LCD_Cmd(0x0C);		// Tat nhay con tro
					LCD_Clear();
					LCD_Gotoxy(2, 0);
					LCD_Puts("Wait...");
					Delay_ms(500);
					for(x = 0; x < 8;)
					{
						if(LuuPhim[x] == MatKhauCu[x])
						{
							x++;
							if(x == 8)
							{
								KetQua1 = 1;
								DOOR = 0;
								Delay_ms(1000);
								DOOR = 1;
								break;
							}
						}
						else if(LuuPhim[x] != MatKhauCu[x])
						{
							KetQua1 = 2;
							break;
						}
					}
					Ket_Qua();
				}
			}
		}	// Mode 1 Che do nhap mat khau mo khoa
		if(Mode == 2)
		{
			if(!KEY_HANG4)
			{
				LCD_Cmd(0x0C);
				Clear_Data();
			}
			Key_Clear();
			if(Key != 0 && Key != 0x23)
			{
				Key_Inputs();
				if(GioiHan == 8)
				{
					LCD_Cmd(0x0C);
					LCD_Clear();
					LCD_Gotoxy(2, 0);
					LCD_Puts("Wait...");
					Delay_ms(2000);
					for(x = 0; x < 8;)
					{
						if(LuuPhim[x] == MatKhauCu[x])
						{
							x++;
							if(x == 8)
							{
								KetQua1 = 3;
								Xoa_Mang();
								break;
							}
						}
						if(LuuPhim[x] != MatKhauCu[x])
						{
							KetQua1 = 4;
							Xoa_Mang();
							break;
						}
					}
				}
				if(KetQua1 == 3 || KetQua1 == 4)
				{
					LCD_Clear();
					LCD_Gotoxy(3, 0);
					LCD_Puts("Nhap MK Moi");
					LCD_Gotoxy(4, 1);
					LCD_Cmd(0x0F);
					Mode = 3;
					Key = 0;
					Xoa_Mang();
				}
			}
		}	// Mode 2 che do doi mat khau
		if(Mode == 3)
		{
			Key_Clear();
			if(Key != 0 && Key != 0x23)
			{
				Key_Inputs();
				if(GioiHan == 8)
				{
					LCD_Cmd(0x0C);
					LCD_Clear();
					LCD_Gotoxy(2, 0);
					LCD_Puts("Wait...");
					Delay_ms(2000);
					for(x = 0; x < 8; x++)
					{
						MatKhauMoi[x] = LuuPhim[x];
					}
					LCD_Clear();
					LCD_Gotoxy(0, 0);
					LCD_Puts("Nhap Lai MK Moi");
					LCD_Gotoxy(4, 1);
					LCD_Cmd(0x0F);
					GioiHan = 0;
					Mode = 4;
					Key = 0;
					Xoa_Mang();
				}
			}
		}	// Mode 3 che do mat khau moi
		if(Mode == 4)
		{
			Key_Clear();
			if(Key != 0 && Key != 0x23)
			{
				Key_Inputs();
				if(GioiHan == 8)
				{
					LCD_Cmd(0x0C);
					LCD_Clear();
					LCD_Gotoxy(2, 0);
					LCD_Puts("Wait...");
					Delay_ms(2000);
					for(x = 0; x < 8;)
					{
						if(LuuPhim[x] == MatKhauMoi[x])
						{
							x++;
							if(x == 8)
							{
								KetQua2 = 1;	
								break;
							}
						}
						if(LuuPhim[x] != MatKhauMoi[x])
						{
							LCD_Clear();
							LCD_Gotoxy(0, 0);
							LCD_Puts("Mat Khau Moi");
							LCD_Gotoxy(0, 1);
							LCD_Puts("Khong Trung Khop!");
							Delay_ms(4000);
							LCD_Gotoxy(0, 0);
							LCD_Puts("Doi Mk That Bai!");
							LCD_Gotoxy(0, 1);
							LCD_Puts("                ");
							Delay_ms(3000);
							Clear_Data();
							break;
						}
					}
					if(KetQua1 == 3 && KetQua2 == 1)
					{
						LCD_Clear();
						LCD_Gotoxy(3, 0);
						LCD_Puts("Doi Mat Khau");
						LCD_Gotoxy(0, 1);
						LCD_Puts("Thanh Cong !!!");
						Delay_ms(2000);
						for(x = 0; x < 8; x++)
						{
							MatKhauCu[x] = LuuPhim[x];
						}
						Eeprom24C_WriteS(0x00, LuuPhim);
						Eeprom24C_Write(0x08, 0x2A);
						Delay_ms(100);
						Clear_Data();
					}
					if(KetQua1 == 4 && KetQua2 == 1)
					{
						LCD_Clear();
						LCD_Gotoxy(0, 0);
						LCD_Puts("Sai Mat Khau Cu");
						LCD_Gotoxy(0, 1);
						LCD_Puts("Doi Mk That Bai!");
						Delay_ms(3000);
						Clear_Data();
					}
				}
			}
		}	// Mode 4 che do kiem tra lai mat khau moi
		if(Mode == 5)
		{
			Key_Clear();
			if(Key != 0 && Key != 0x23)
			{
				Key_Inputs();
				if(GioiHan == 8)
				{
					LCD_Cmd(0x0C);
					LCD_Clear();
					LCD_Gotoxy(2, 0);
					LCD_Puts("Wait...");
					Delay_ms(2000);
					for(x = 0; x < 8; x++)
					{
						MatKhauCu[x] = LuuPhim[x];
					}
					Eeprom24C_WriteS(0x00, LuuPhim);
					Delay_ms(100);
					Eeprom24C_Write(0x08, 0x2A);
					Delay_ms(100);
					LCD_Gotoxy(0, 0);
					LCD_Puts("Thiet Lap MK Moi");
					LCD_Gotoxy(0, 1);
					LCD_Puts("Thanh Cong...!");
					Delay_ms(2000);
					Clear_Data();
				}
			}
		}//Mode 5 che do thiet lap mat khau lan dau
	}
}