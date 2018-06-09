#include <reg52.h>
#include <stdio.h>
#include "lcd4bit.h"

sbit Mode 		= P1^0;
sbit Timer   	= P1^1;
sbit Setting	= P1^2;
sbit Up_Down	= P1^3;
sbit Start 		= P1^4;

sbit DQ  		= P2^0;

sbit Relay 		= P2^1;

//******************************************************************************
#define Run    0
#define Stop   1
char Run_Stop = Stop;
char Index =0,menu = 0;
char buff[20];
unsigned char nhiet_thuc,temp1,temp2;
unsigned char  Status_Low = 30,Status_High = 32;
// dinh nghia bien va hang so tinh do am
int i,doam;	
#define F0	7360
#define	F1	5651
unsigned long dem = 0;
unsigned int dem_tg = 0,dem_tg2 = 0;
unsigned long Fx;
unsigned char HMT_Therhold = 10;
// Dinh nghia thoi gian hen gio
#define Timer1   20
#define Timer2   40
#define Timer3   60
unsigned char timer = 0;
unsigned char timer_mode = 0;
char cnt_timer = 0;
unsigned char n=0;	
//******************************************************************************//
void delay(unsigned int i)
{
	while(i--);
}
//******************************************************************************//
void delay_18B20(unsigned int i)
{
	while(i--);
}
//******************************************************************************//
void Init_DS18B20(void) 
{
	 unsigned char x=0;
	 DQ = 1;          
	 delay_18B20(8);  	   
	 DQ = 0;          
	 delay_18B20(80); 
	 DQ = 1;          
	 delay_18B20(14);
	 x=DQ;            
	 delay_18B20(20);
}
//******************************************************************************//
unsigned char ReadOneChar(void)
{
	unsigned char i=0;
	unsigned char dat = 0;
	for (i=8;i>0;i--)
	 {
		  DQ = 0; 
		  dat>>=1;
		  DQ = 1; 
		  if(DQ)
		  dat|=0x80;
		  delay_18B20(4);
	 }
 	return(dat);
}
//******************************************************************************//
void WriteOneChar(unsigned char dat)
{
 	unsigned char i=0;
 	for (i=8; i>0; i--)
 	{
  		DQ = 0;
 		DQ = dat&0x01;
    	delay_18B20(5);
 		DQ = 1;
    	dat>>=1;
 }
}
//******************************************************************************//
unsigned char ReadTemp(void)
{
	unsigned char a=0;
	unsigned char b=0;
	unsigned char t=0;
	unsigned char kq;
	Init_DS18B20();
	WriteOneChar(0xCC);    		 // cho phep dieu khien truy nhap truc tiep den lenh nho sensor ma khong can gui chuoi ma sensor
	WriteOneChar(0x44); 		 // khoi dong qua trinh do va chuyen doi du lieu

	delay_18B20(100);    

	Init_DS18B20();
	WriteOneChar(0xCC); 
	WriteOneChar(0xBE); 	    // Cho phep thiet bi doc nd bo nho nhap

	delay_18B20(100);

	a=ReadOneChar();    
	b=ReadOneChar();   	
	kq=b<<4;
	kq+=(a&0xf0)>>4; 
	return (kq);
}
//******************************************************************************//
void Read_Actual_Temp(void)
{
	temp1= ReadTemp();
	temp2 = ReadTemp();
	if((temp2<150)&&(temp2>temp1-5)&&(temp2<temp1+5))
	{
		nhiet_thuc = temp2;
	}
}
//******************************************************************************//
void Chon_che_do(void) // Kiem tra phim nhan.
{
     if(Mode == 0 )
	 {
	 	delay(1000);
		if(Mode == 0)
		{
			while(!Mode);
			Run_Stop = Stop;
			Index ++;
			if(Index ==2) Index = 0;
			if(Index ==0) 
			{
				cnt_timer = 0;
				LCD_Clear();
				LCD_PrString("Che do Auto");
			}
			if(Index==1)
			{
				LCD_Clear();
				LCD_PrString("Che do hen gio");	
			}
	   }
	 }
}
void Cai_dat(void)
{
	 if((Timer ==0)&&(Index ==  1))		//  chinh thoi gian Manual
	 {
		delay(1000);
		if(Timer == 0)
		{ 	
			while(!Timer);
			timer_mode ++;
			if(timer_mode == 3) timer_mode = 0;
			
		}
		switch(timer_mode)
		{
			case 0: timer = Timer1;break;
			case 1: timer = Timer2;break;
			case 2: timer = Timer3;break;
		}
		LCD_Clear();
		LCD_Position(0,0);
		LCD_PrString("Che dong Timer");	
		LCD_Position(1,0);
	    LCD_PrString("Timer=");
	    LCD_PrInteger(timer);
	 }
	 if(Start == 0)
	 {
	 	delay(1000);
		if(Start == 0)
		{
			while(!Start);
			Run_Stop = Run;
			cnt_timer = 0;
		}
	 }
	 if(Setting == 0)
	 {
	 	delay(1000);
		if(Setting ==0)
		{
			while(!Setting);
			menu ++;
			if(menu == 3) menu = 0;

			if(menu == 0)
			{
	        	LCD_Clear();
				LCD_Position(0,0);
				LCD_PrString("Nhiet do thap");	
				LCD_Position(1,0);
	    		LCD_PrString("Temp_Low=");
	    		LCD_PrInteger(Status_Low);
			}
			else if(menu == 1)
			{
				LCD_Clear();
				LCD_Position(0,0);
				LCD_PrString("Nhiet do cao");	
				LCD_Position(1,0);
	    		LCD_PrString("Temp_High=");
	    		LCD_PrInteger(Status_High);
			}
			else
			{
				LCD_Clear();
				LCD_Position(0,0);
				LCD_PrString("Nguong do am");	
				LCD_Position(1,0);
	    		LCD_PrString("HMT_Therhold=");
	    		LCD_PrInteger(HMT_Therhold);
			}
		}
	 }
	 if(Up_Down == 0)
	 {
	 	delay(1000);
		if(Up_Down == 0)
		{
			while(!Up_Down);
			if(menu == 0)
			{
				if(Status_Low < 100) Status_Low ++;
				LCD_Clear();
				LCD_Position(0,0);
				LCD_PrString("Nhiet do thap");	
				LCD_Position(1,0);
	    		LCD_PrString("Temp_Low=");
	    		LCD_PrInteger(Status_Low);
			}  
			else if(menu == 1)
			{
				if(Status_High< 100) Status_High ++;
				LCD_Clear();
				LCD_Position(0,0);
				LCD_PrString("Nhiet do cao");	
				LCD_Position(1,0);
	    		LCD_PrString("Temp_High=");
	    		LCD_PrInteger(Status_High);
			}
			else if(menu == 2)
			{
				if(HMT_Therhold<100) HMT_Therhold = HMT_Therhold +10;
				LCD_Clear();
				LCD_Position(0,0);
				LCD_PrString("Nguong do am");	
				LCD_Position(1,0);
	    		LCD_PrString("HMT_Therhold=");
	    		LCD_PrInteger(HMT_Therhold);
			}
		}
	 }
	
}

//******************************************************************************//
void doc_cam_bien_HandMode()
{	 
	
	if(dem_tg>=400)
	{ 	
		n++;
		if(n== 10)
		{
			if((cnt_timer <timer)&&(doam>HMT_Therhold))
			{
				cnt_timer ++;
				Relay = 1;
			}
			else
			{
				Relay = 0;
			}
			n = 0;
		}
	    	Read_Actual_Temp();

			LCD_Clear();
			LCD_Position(0,0);
			LCD_PrString("%=");
			LCD_PrInteger(doam);
			LCD_PrString(" >< ");
	
			LCD_PrString("oC=");
			LCD_PrInteger(nhiet_thuc);


			LCD_Position(1,0);
			LCD_PrString("Timer =");
			LCD_PrInteger(timer - cnt_timer);
			
		dem_tg = 0;
     }
}
void doc_cam_bien_AutoMode()
{	 
	
	if(dem_tg>=400) // cho khoang thoi gian 0.1s
	{ 	
		Read_Actual_Temp();
		if(nhiet_thuc < Status_Low)
		{
			Relay = 1;
		}
		if(nhiet_thuc > Status_High)
		{
			Relay = 0;
		}

			LCD_Clear();
			LCD_Position(0,0);
			LCD_PrString(" Che do tu dong");
			LCD_Position(1,0);
			LCD_PrString("%=");
			LCD_PrInteger(doam);
			LCD_PrString(" >< ");
	
			LCD_PrString("oC=");
			LCD_PrInteger(nhiet_thuc);

		dem_tg = 0;
     }
}
void main()
{

	Init_DS18B20();
	LCD_Init();
	LCD_Clear();
	LCD_PrString("Dang khoi dong...");
	delay(1000);
	IE = 0x83; 
	IT0 = 1;
	IP=0x01; 
	TMOD = 0x02; 
	TH0=TL0=-250;
	TR0 = 1;
	nhiet_thuc = ReadTemp();

	LCD_Clear();
	LCD_PrString(" Auto/Manual ?");
Index = 0;
while(1)
{
	Chon_che_do();
	if(Run_Stop == Run)
	{
		
		if(Index == 0)
		{
		   
		   doc_cam_bien_AutoMode();	   
		}
		else if (Index == 1)
		{
			doc_cam_bien_HandMode();
		}
	}
	else
	{
		cai_dat();
		cnt_timer = 0;
		Relay = 0;
	}
}

}

void interrupt_EX0(void) interrupt 0
{
	dem++;
}
void interrupt_Timer0(void) interrupt 1
{
	dem_tg ++;	
	dem_tg2++;
	if(dem_tg2>=4000) // cho khoang thoi gian 1s
	{ 	
	
		Fx=dem;
	    doam=(((F0-Fx)*100.0)/(F0-F1));
		dem_tg2 = 0;
		dem = 0;
	}
		
}

