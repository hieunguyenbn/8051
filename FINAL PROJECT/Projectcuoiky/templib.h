/*#include <REGX51.H> */
#include <stdio.h>
/*#define LCD_DATA P2  */

sbit DQ = P3^7;            //  Define Data PIN
/*sbit LCD_RS=P3^6;
sbit LCD_EN=P3^7;	*/

/************For Sensor********////
/***************************/

unsigned char temp,temp_hihi,temp_hihi2;
//*********************************// 
// Basic Function
void delay_18B20(unsigned int i)
{
do
	{
    TMOD=0x01;          
    TL0=0xFF;             
    TH0=0xFF;               
    TR0=1;                     
    while(!TF0){}          
    TR0=0;                     
    TF0=0;
	i--;
	}  
while(i!=0);
}
void rs_18B20(void)
{
    unsigned char x=0;
    DQ = 1; delay_18B20(10);
    DQ = 0; delay_18B20(450);
    DQ = 1; delay_18B20(10);
    x=DQ;   delay_18B20(10);
}
 

unsigned char ReadOneChar(void)
{
    unsigned char i=0, dat = 0;
    for (i=8;i>0;i--)
    {
  		DQ = 0;
 		dat>>=1;
 		DQ = 1;
 		if(DQ)
 			dat |= 0x80; delay_18B20(1);
    }
    return(dat);
}
void WriteOneChar(unsigned char dat)
{
    unsigned char i=0;
    for (i=8; i>0; i--)
    {
DQ = 0;
DQ = dat&0x01; delay_18B20(1);
 DQ = 1;
 dat>>=1;
    }
}
//*********************************//


void ReadTemp(void)
{
    unsigned char low_val=0;
    unsigned char high_val=0;
 
    rs_18B20();
    //SendCode(x);
	WriteOneChar(0xCC);	  		//skip
	WriteOneChar(0x4E);			// allow to write scracthpad : de cho phep viet vao sp
	WriteOneChar(0x00);
	WriteOneChar(0x00);
    WriteOneChar(0x1F); 		// config 9 bit
    delay_18B20(70);
	rs_18B20();      		
 
	WriteOneChar(0xCC);         // Skip
    WriteOneChar(0x44); 		// Convert T
    delay_18B20(70);      		
 
    rs_18B20();
    //SendCode(x);
	WriteOneChar(0xCC); 	    // Skip
    WriteOneChar(0xBE);    		// Read Scatchpad
    delay_18B20(100);
 
    low_val=ReadOneChar();            // temp low value
    high_val=ReadOneChar();            // temp high value
 	temp_hihi=(low_val & 0x0F)*100/16;    // 1/16 = 16^-1
//	temp_hihi2=(low_val & 0x0F)>>4*100/16;
    temp=(((high_val<<8)+low_val)>>4);        // 256 = 16^2
}



 /***********For Displaying************/
 /*******************************/

void Delay_ms(unsigned int ms)
{
	unsigned int i, j;
	for(i=0;i<ms;i++)
	{
		for(j=0;j<113;j++); 
	}
}
/*
void Lcd_Cmd(unsigned char cmd)
{
	LCD_RS=0;
	LCD_DATA=cmd;
	LCD_EN=0;
	LCD_EN=1;
	if(cmd<=0x02)
	{
		Delay_ms(2);
	}
	else
	{
		Delay_ms(1);
	}
}
void Lcd_Chr_Cp(char c)
{
	LCD_RS=1;
	LCD_DATA=c;
	LCD_EN=0;
	LCD_EN=1;
	Delay_ms(1);
}
void Lcd_Chr(unsigned char row, unsigned char col, char c)
{
	unsigned char cmd;
	cmd=(row==1?0x80:0xC0)+col-1;
	Lcd_Cmd(cmd);
	Lcd_Chr_Cp(c);
}
void Lcd_Out_Cp(char *str)
{
	unsigned char i=0;
	while(str[i]!=0)
	{
		Lcd_Chr_Cp(str[i]);
		i++;
	}
}

void Lcd_Init()
	{
	Lcd_Cmd(0x38);
	Delay_ms(1);
	Lcd_Cmd(0x01);
	Lcd_Cmd(0x0C);
	}
	*/
/**********************************/

 /*
void main(void)
{
	while(1)
		{
			ReadTemp();
			Lcd_Init();

		Lcd_Cmd(0x02);
	    Lcd_Out_Cp("Nhiet do: ");
			
		Lcd_Cmd(0xC0);
		Lcd_Chr(2,7,temp/10+48); Lcd_Chr(2,8,temp%10+48); Lcd_Chr(2,9,44);
		Lcd_Chr(2,10,temp_hihi/10+48); Lcd_Chr(2,11,temp_hihi%10+48); 
	
		Lcd_Chr(2,13,0xDF); 	// Gia tri mo ta ki tu degree( nhiet do)
		Lcd_Chr(2,14,67);  		// 67 la ma ASCII cua chu C
		Delay_ms(100);	
		}
}	*/