#include<reg52.h>
#include<intrins.h>
#include<i2c.h>
#include<ds1307.h>

sbit data_time=P2^4;
sbit data_date=P2^5;
sbit set=P1^2;
sbit up=P1^3;
sbit down=P1^4;
sbit clear=P1^5;
sbit sqw=P1^6;

unsigned char hour, minute, second,day,date,month,year,control;
unsigned char code_led[12]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xff,0x00};
unsigned char led_buffer[16];
unsigned char kt=0,a=0,d=0,scan_led,counter;
bit set0,set1,up1,up0,down0,down1;
//****************CAC CHUONG CHINH CON***********
void timer0(void)
{   
	EA=0;//cam ngat toan cuc
	TMOD=0x2;//timer0 che do 8 bit tu dong nap lai
	TL0=0x6;//Gia tri bat dau dem = 6 (tre 250us)
	TH0=0x6;//gia tri TH	dc nap vao TL (che do 8 bit)	
	ET0=1;//cho phep ngat timer0
	EA=1;//cho phep ngat toan cuc
	TR0=1;//Bat dau chay timer0
}
void quet_led(void)interrupt 1 //dia chi vecto ngat timer0
{	
	TR0=0;//dung chay Timer	
	if(++counter==3)//sau 12x250us=3ms thi thay doi hien thi led
	{	
		if(scan_led<=7)//chan enb cua P2 =>0 khong  co led nao duoc hien thi
		{	
			P2=scan_led;//hien thi cac led o hang 1 (gio, phut,giay,thu)
			P0=code_led[(led_buffer[scan_led])];
			data_time=1;//hien thi gio phut giay					
		}else{  	
				P2=scan_led-0x8;// hien thi led hang 2 (ngay thang nam)			
				P0=code_led[(led_buffer[scan_led])];
				data_date=1;//hien thi ngay thang nam				 
			}	
		scan_led++;
		if(scan_led>=16) //vuot qua 16 led thi tro ve ban dau
		{
			scan_led=0;
		}
		counter=0;
	}			
	TR0=1;//Chay TIMER0
}

void delays(int time_delay)
{	
	unsigned int temp;
	while(time_delay)
	{
		temp=1000;
		while(temp)
		{
			temp--;
		}
		time_delay--;
	}
}

void writeds(){
	rtc_write(0x00, second);
	rtc_write(0x01, minute);
	rtc_write(0x02, hour);
	rtc_write(0x03, day);
	rtc_write(0x04, date);
	rtc_write(0x05, month);
	rtc_write(0x06, year);
}

void readds()
{
	if(kt==0)
	{
		if(a==1)
		{
			writeds();
			a=0;
		}
		second = rtc_read(0x00);
		minute = rtc_read(0x01);
		hour = rtc_read(0x02);
		day = rtc_read(0x03);
		date = rtc_read(0x04);
		month = rtc_read(0x05);
		year = rtc_read(0x06);
	}
}

void dislay()
{  		
		unsigned char temp;
			
		//*******Hien thi gio*************
		if((temp=(hour&0x30)>>4)==0)//khong hien thi so 0 o hang chuc
		{
			led_buffer[0]=0x0a;
		}else
		 {
			led_buffer[0]=temp;//Lay 2 bit cao		
		 }
		led_buffer[1]=(hour&0x0f);	 //Lay 4 bit thap		
		//*******Hien thi phut**********
		led_buffer[2]=(minute&0x70)>>4; //lay 3 bit cao
		led_buffer[3]=minute&0x0f;		 //Lay 4 bit thap
		//*******Hien thi giay*********
		led_buffer[4]=(second&0x70)>>4;
		led_buffer[5]=second&0x0f;
		led_buffer[6]=0x0a;
		led_buffer[7]=(day&0x7);
		//*******Hien thi ngay**********
		if((temp=(date&0x70)>>4)==0)//khong hien thi so 0 o hang chuc
		{
			led_buffer[8]=0x0a;
		}else
		 {
			led_buffer[8]=temp;
		 }
		led_buffer[9]=date&0x0f;
		//*********Hien thi thang************
		if(((month&0x30)>>4)==0)//khong hien thi so 0 o hang chuc
		{
			led_buffer[10]=0x0a;		
		}else
			{
				led_buffer[10]=(month&0x30)>>4;
			}
		led_buffer[11]=month&0x0f;
		//******Hien thi nam***********
		led_buffer[12]=2;
		led_buffer[13]=0;
		led_buffer[14]=(year&0x70)>>4;
		led_buffer[15]=year&0x0f;
	 
}
void setup_rtc(void)
{
				second=0x0;
				minute=0x0;
				hour=0x0;
				day=0x4;
				date=0x8;
				month=0x6;
				year=0x11;
				control=0x10;
	rtc_write(0x7, control);
	rtc_write(0x0, second);
	rtc_write(0x1, minute);
	rtc_write(0x2, hour);
	rtc_write(0x3, day);
	rtc_write(0x4, date);
	rtc_write(0x5, month);
	rtc_write(0x6, year);			   		 
}				 
void ktphim()
{
set0=set1;set1=set;
if((set0==1)&&(set1==0))
  {
   	if(set==0)
	{
		delays(50);
		if((set==0)&&(clear==0))
		{
			delays(50);
			setup_rtc();
		}
   	}
   kt++;
   if(kt==8)kt=0; 
  }
if(clear==0)kt=0;
switch(kt)
 {
  case 0:break;
  case 1:
    {
      up0=up1;up1=up; a=1;d=1;
      if((up0==1)&&(up1==0))
       {
         hour++;
		  if(hour==24)hour=0;
       }
       down0=down1;down1=down;
       if((down0==1)&&(down1==0))
        {
          hour--;
		   if(hour==-1)hour=23;
        }
     break;
   }
  case 2:
    {
     up0=up1;up1=up; a=1;d=1;
     if((up0==1)&&(up1==0))
       {
         minute++;
		 if(minute==60)
		 minute=0;
       }
     down0=down1;down1=down;
     if((down0==1)&&(down1==0))
       {
         minute--;
		 if(minute==-1)
		 minute=59;
       }
      break;
    }

 case 3:
    {
     up0=up1;up1=up;a=1;d=1;
     if((up0==1)&&(up1==0))
      {
       second++;
		 if(second==60)
		 second=0;
      }
      down0=down1;down1=down;
     if((down0==1)&&(down1==0))
      {
      second--;
	  if(second==-1)
	  second=0;
      }
     break;
    }
case 4:
    {
      up0=up1;up1=up; a=1;d=1;
      if((up0==1)&&(up1==0))
       {
         day++;
		  if(day==8)day=1;
       }
       down0=down1;down1=down;
       if((down0==1)&&(down1==0))
        {
          day--;
		   if(day==0)
		   day=7;
        }
     break;
   }
case 5:
    {
      
	  up0=up1;up1=up; a=1;d=1;
      if((up0==1)&&(up1==0))
       {
	   	  date++;
         	if((month==4)||(month==6)||(month==9)||(month==11)){if(date==31)date=1;}
			if((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12)){if(date==32)date=1;}
			if((month==2)&&(year%4==0)){if(date==29)date=1;}
			if((month==2)&&(year%4!=0)){if(date==30)date=1;}		 		  
       }
       down0=down1;down1=down;
       if((down0==1)&&(down1==0))
        {
        date--;
			if((month==4)||(month==6)||(month==9)||(month==11)){if(date==0)date=30;}
			if((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12)){if(date==0)date=31;}
			if((month==2)&&(year%4==0)){if(date==0)date=28;}
			if((month==2)&&(year%4!=0)){if(date==0)date=29;}
		 }
     break;
   }
case 6:
    {
      up0=up1;up1=up; a=1;d=1;
      if((up0==1)&&(up1==0))
       {
         month++;
		  if(month==13)month=1;
       }
       down0=down1;down1=down;
       if((down0==1)&&(down1==0))
        {
          month--;
		   if(month==0)month=12;
        }
     break;
   }
case 7:
    {
      up0=up1;up1=up; a=1;d=1;
      if((up0==1)&&(up1==0))
       {
         year++;
		  if(year==100)year=0;
       }
       down0=down1;down1=down;
       if((down0==1)&&(down1==0))
        {
          	year--;
		   	if(year==-1)year=99;
        }
     break;
   }
   }
}
void chinhgio(void)					  
{
		if(kt==1)
		{
			if(sqw==1)
			{
				led_buffer[0]=hour/10;
				led_buffer[1]=hour%10;
			}else if(sqw==0)		
				{
					led_buffer[0]=10;
					led_buffer[1]=10;
				}
		 }

		if(kt==2)
		{
			if(sqw==1)
			{
				led_buffer[2]=minute/10;
				led_buffer[3]=minute%10;
			}else if(sqw==0)		
				{
					led_buffer[2]=10;
					led_buffer[3]=10;
				}
 		}
		if(kt==3)
		{
			if(sqw==1)
			{
				led_buffer[4]=second/10;
				led_buffer[5]=second%10;
			}else if(sqw==0)		
				{
					led_buffer[4]=10;
					led_buffer[5]=10;
				}
		}													   
		if(kt==4)
		{	
			if(sqw==1)
			{
				led_buffer[6]=10;
				led_buffer[7]=day%10;
			}else if(sqw==0)		
				{
					led_buffer[6]=10;
					led_buffer[7]=10;
				}
		}
		if(kt==5)
		{
			if(sqw==1)
			{
				led_buffer[8]=date/10;
				led_buffer[9]=date%10;
			}else if(sqw==0)		
				{
					led_buffer[8]=10;
					led_buffer[9]=10;
				}
 		}
		if(kt==6)
		{
			if(sqw==1)
			{
				led_buffer[10]=month/10;
				led_buffer[11]=month%10;
			}else if(sqw==0)		
				{
					led_buffer[10]=10;
					led_buffer[11]=10;
				}
		}
		if(kt==7)
		{		
			if(sqw==1)
			{
				led_buffer[12]=2;
				led_buffer[13]=0;
				led_buffer[14]=year/10;
				led_buffer[15]=year%10;
			}else if(sqw==0)		
				{
					led_buffer[12]=10;
					led_buffer[13]=10;
					led_buffer[14]=10;
					led_buffer[15]=10;
				}	
		}
}
void khoi_chay()
{	
	P0=0x00;
	delays(100);
	led_buffer[0]=0xa;delays(5);
	led_buffer[1]=0xa;delays(5);
	led_buffer[2]=0xa;delays(5);
	led_buffer[3]=0xa;delays(5);
	led_buffer[4]=0xa;delays(5);
	led_buffer[5]=0xa;delays(5);
	led_buffer[6]=0xa;delays(5);
	led_buffer[7]=0xa;delays(5);
	led_buffer[8]=0xa;delays(5);
	led_buffer[9]=0xa;delays(5);
	led_buffer[10]=0xa;delays(5);
	led_buffer[11]=0xa;delays(5);
	led_buffer[12]=0xa;delays(5);
	led_buffer[13]=0xa;delays(5);
	led_buffer[14]=0xa;delays(5);
	led_buffer[15]=0xa;delays(5);		
} 																		 
void main()
{	
	timer0();
	khoi_chay();
	while(1)
  	{
   		ktphim();
   		readds();
		if(d==0)
   		{
			dislay();
   		}
   		if(d==1)
   		{
			chinhgio();
			d=0;			
   		}
  	}
}