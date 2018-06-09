#include "UARTmode1.h"
#include "main.h"

//Ham khoi tao UART mode 1
void UART_Init()
{
	//Khoi tao UART mode 1 toc do 2400 boud
	SM0 = 0; SM1 = 1;		//UART mode 1
	TMOD &= 0x0f;				//0010 xxxx - Timer 1 hoat dong o che do 8 bit tu dong nap lai
	TMOD |= 0x20;	
	TH1 = 0xf3;					//Chon toc do boud la 2400, tan so thach anh 12MHz
	TR1 = 1;						//Timer 1 bat dau chay
	TI = 1;							//San sang gui du lieu
	REN = 1;						//Cho phep nhan du lieu
}

//Ham ghi 1 ky tu
void UART_Write(unsigned char c)
{
	while(!TI);				//Doi co TI len 1
	TI = 0;						//Set lai co TI
	SBUF = c;					//Gui di ky tu i
}

//Ham ghi 1 chuoi text
void UART_Write_Text(unsigned char *str)
{
	unsigned char i = 0;
	while(str[i] != 0)			//Kiem tra ky tu Null
	{
		UART_Write(str[i]);
		i++;
	}
}

//Ham doc 1 ky tu
char UART_Read()
{
	while(!RI);				//Doi co RI len 1
	RI = 0;						//Set lai co RI
	return SBUF;
}