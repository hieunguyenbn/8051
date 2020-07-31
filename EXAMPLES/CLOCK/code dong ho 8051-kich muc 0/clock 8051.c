#include <REGX51.H>

#define SEC    	0x00
#define MIN    	0x01
#define HOUR   	0x02
#define DAY    	0x03
#define DATE   	0x04
#define MONTH  	0x05
#define YEAR   	0x06
#define A_MIN  	0x08
#define A_HOUR 	0x09
char sec,hour,min,day,date,month,year,year_20,a_min,a_hour;

sbit SDA  = P1^0;
sbit SCL  = P1^1;
sbit Mode = P1^2;
sbit Up   = P1^3;
sbit Down = P1^4;
sbit Ok   = P1^5;
sbit Alarm   = P1^6;
sbit Loa   = P1^7;

sbit L01  = P2^0;
sbit L02  = P2^1;
sbit L03  = P2^2;
sbit L04  = P2^3;
sbit L05  = P2^4;
sbit L06  = P2^5;
sbit L07  = P2^6;
sbit L08  = P2^7;

sbit L09  = P3^0;
sbit L10  = P3^1;
sbit L11  = P3^2;
sbit L12  = P3^3;
sbit L13  = P3^4;
sbit L14  = P3^5;
sbit L15  = P3^6; 
sbit PM   = P3^7;

//******************************************************************************
// KHAI BAO BIEN, MANG... 
unsigned char led7_data[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90 }; //Decimal to Led7seg
unsigned char Data,Display,time,index,mode,bat_nhay,read_time,alarm,kt,on_off;

// KHAI BAO HAM, CHUONG TRINH CON
void set_main(void); 			// Chuong trinh khoi tao main
void setup_timer(void); 		// Chuong trinh cai dat timer 1 va 0
void delay(unsigned int time); 	// Delay
void Fix_time(void); 			// Kiem tra va hieu chinh gia tri cua gio,phut,giay
void Keypad(void); 				// Kiem tra xu ly phim nhan.
void T1_ISR(void); 				//ngat timer 1 phuc vu nhay led
void T0_ISR(void); 				// Dung ngat timer 0 de quet led
//******************************************************************************
void bip(void)
{
	unsigned char n;
    for(n=0;n<100;n++)
    {
		Loa=1; delay(50);
        Loa=0; delay(50);
    }    
}
//******************************************************************************
// CAC CHUONG TRINH CON CHO I2C
//******************************************************************************
void I2C_start(void)
{
	SCL = 1; SCL = 0;
	SDA = 1; SCL = 1;
	delay(2);
	SDA = 0; delay(2);
	SCL = 0; delay(2);
}
void I2C_stop(void)
{
	SCL = 1; SCL = 0;
	SDA = 0; delay(2);
	SCL = 1; delay(2);
	SDA = 1;
}
bit I2C_write(unsigned char dat)
{
	unsigned char i;
	for (i=0;i<8;i++)
	{
		SDA = (dat & 0x80) ? 1:0;
		SCL=1;SCL=0;
		dat<<=1;
	}
	SCL = 1; delay(2);
	SCL = 0;
	return dat;
}
unsigned char I2C_read(void)
{
	bit rd_bit;
	unsigned char i, dat;
	dat = 0x00;
	for(i=0;i<8;i++) 		/* For loop read data 1 byte */
	{
		delay(2);
		SCL = 1; delay(2); 	/* Set SCL */
		rd_bit = SDA; 		/* Keep for check acknowledge */
		dat = dat<<1;
		dat = dat | rd_bit; /* Keep bit data in dat */
		SCL = 0; 			/* Clear SCL */
	}
	return dat;
}
//******************************************************************************
// CAC CHUONG TRINH CON CHO DS1307
//******************************************************************************
unsigned char DS1307_read(unsigned char addr)
{
	unsigned int temp,ret;
	I2C_start(); 		/* Start i2c bus */
	I2C_write(0xD0); 	/* Connect to DS1307 */
	I2C_write(addr); 	/* Request RAM address on DS1307 */
	I2C_start(); 		/* Start i2c bus */
	I2C_write(0XD1); 	/* Connect to DS1307 for Read */
	ret = I2C_read(); 	/* Receive data */
	I2C_stop();
	//**********************************************************
	temp = ret; 							/*BCD to HEX*/
	ret = (((ret/16)*10)+ (temp & 0x0f)); 	/*for Led 7seg*/
	//**********************************************************
	return ret;
}

void DS1307_Write(unsigned char addr,unsigned char dat)
{
	unsigned int temp;
	//********************************************** 
	temp = dat ; 						/*HEX to BCD*/
	dat = (((dat/10)*16)|(temp %10)); 	/*for Led 7seg*/
	//**********************************************
	I2C_start(); 		/* Start i2c bus */
	I2C_write(0XD0); 	/* Connect to DS1307 */
	I2C_write(addr); 	/* Request RAM address on DS1307 */
	I2C_write(dat); 	/* Connect to DS1307 for Read */
	I2C_stop();
}

void Out_1Hz()
{
	I2C_start(); /* Start i2c bus */
	I2C_write(0xD0); /* Connect to DS1307 */
	I2C_write(0x07);   //vi tri con tro RTC
	I2C_write(0x10);
	I2C_stop();
}

void Read_DS1307()
{
	sec   = DS1307_read(SEC);
	min   = DS1307_read(MIN);
	hour  = DS1307_read(HOUR);
	day   = DS1307_read(DAY);
	date  = DS1307_read(DATE);
	month = DS1307_read(MONTH);
	year  = DS1307_read(YEAR);
}

void Write_DS1307()
{
	DS1307_Write(SEC,sec);
	DS1307_Write(MIN,min);
	DS1307_Write(HOUR,hour);
	DS1307_Write(DAY,day);
	DS1307_Write(DATE,date);
	DS1307_Write(MONTH,month);
	DS1307_Write(YEAR,year); 
}

void Write_Alarm()
{
	DS1307_Write(A_MIN,a_min);
	DS1307_Write(A_HOUR,a_hour);
}
//******************************************************************************
void delay(unsigned int time)
{ 
	while(time--); 
}
void set_main(void) // Chuong trinh khoi tao main
{
	P1=0xFF; 
	P0=P2=P3=0x00;
}
void setup_timer(void) // Setup timer 0 va timer 1
{
	TMOD=0x11; // timer0 & timer1 set che do 1
	ET1=1; ET0=1; EA=1;
	TF0=0; TF1=0; 
	TR0=1; TR1=1;
}
void Set_Clock(void) // Kiem tra va hieu chinh gia tri cua gio,phut,giay
{
	unsigned char y;
	y=(year%4)*100;
//Tang
	if(min>59) { min=0; }
	if(hour>23){ hour=0; }
	if(day>8) day=2;
	if((month==2)&&(date>29)&&(y==0)) { date=1; }
	else	if((month==2)&&(date>28)&&(y!=0)) { date=1; }
			else 	if(((month==4)||(month==6)||(month==9)||(month==11))&&(date>30)&&(y!=0)){ date=1; }
					else 	if(date>31) { date=1; }
	if(month>12) { month=1; }
	if(year>99) { year_20++; year=0; if(year_20>99){year_20=0;}  }
//Giam
	if(min<0) { min=59; }
	if(hour<0) { hour=23; }
	if(day<2) day=8;
	if((month==2)&&(date<1)&&(y==0)) { date=29; }
	else	if((month==2)&&(date<1)&&(y!=0)) { date=28; }
			else 	if(((month==4)||(month==6)||(month==9)||(month==11))&&(date<1)&&(y!=0)){ date=30; }
					else 	if(date<1) { date=31; }
	if(month<1) { month=12; }
	if(year<0) { year_20--; year=99; if(year_20<0){year_20=99;} }
}
void Keypad(void) // Kiem tra phim nhan.
{
	if(!Ok)
	{
		bip(); 
		if(on_off==1)
		{
			Display=mode=alarm=0;
			Write_Alarm();	
		}
		else 
		{
			Display=alarm=mode=0; 
			Write_DS1307();
		}
	}
//*********************************************************************
	if(Display==0)
	{
		if(!Mode)
		{ 
			bip(); mode++; sec=0;
			if(mode==7) 
			{		
				mode=1;
			}
		}
		if(mode==1)
		{ 
			if(!Up) 
			{
				min=min+1; delay(50000);
			}
			if(!Down) 
			{
				min=min-1; delay(50000);
			}
		}
		if(mode==2)
		{ 
			if(!Up) 
			{
				hour=hour+1; delay(50000);
			}
			if(!Down) 
			{	
				hour=hour-1; delay(50000);
			}
		}
		if(mode==3)
		{ 
			if(!Up) 
			{
				day=day+1; delay(50000);
			}
			if(!Down) 
			{	
				day=day-1; delay(50000);
			}
		}
		if(mode==4)
		{ 
			if(!Up) 
			{
				date=date+1; delay(50000);
			}
			if(!Down) 
			{	
				date=date-1; delay(50000);
			}
		}
		if(mode==5)
		{ 
			if(!Up) 
			{
				month=month+1; delay(50000);
			}
			if(!Down) 
			{	
				month=month-1; delay(50000);
			}
		}
		if(mode==6)
		{ 
			if(!Up) 
			{
				year=year+1; delay(50000);
			}
			if(!Down) 
			{	
				year=year-1; delay(50000);
			}
		}
	}
	if(!Alarm)
	{
		bip(); Display=1;
	}
	if(Display==1)
	{
		if(!Mode)
		{ 
			bip(); alarm++; 
			if(alarm==4) 
			{		
				alarm=1;
			}
		}
		if(alarm==1)
		{ 
			if(!Up) //min++; 
			{
				a_min=a_min+1; delay(50000);
			}
			if(!Down) //min--;
			{
				a_min=a_min-1; delay(50000);
			}
		}
		if(alarm==2)
		{ 
			if(!Up) //hour++;
			{
				a_hour=a_hour+1; delay(50000);
			}
			if(!Down) //hour--;
			{	
				a_hour=a_hour-1; delay(50000);
			}
		}
		if(alarm==3)
		{ 
			if(!Up) //hour++;
			{
				on_off=1; delay(50000); 
			}
			if(!Down) //hour--;
			{	
				on_off=0; delay(50000);
			}
		}
	}

//*********************************************************************
	Set_Clock(); 
	delay(1000);
}
void T0_ISR(void) interrupt 1 // Dung ngat Timer0 de doc DS1307
{
	TR0=0;
	TF0=0;
	TH0=0x3C; // Gia tri cho Timer0: 50000(us)x10=0.5(s)
	TL0=0xAF;
	time++;
	if(time==10)
	{
		time=0; bat_nhay++; read_time=1;
		if(bat_nhay==2) bat_nhay=0;
	}
	TR0=1;
}
/*************************************/
void T1_ISR(void) interrupt 3 // Dung ngat Timer1 de hien thi 15 Led_7D
{
	TR1=0;
	TF1=0;
	TH1=0xFC; // Gia tri cho Timer1: 1000(us) x 15 = 15(ms)
	TL1=0x18;
	if(Display==0)
	{
		index++;
		if(index==1)
		{
			Data=sec;
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			L01=0;
			P0=led7_data[Data%10];//xuat gia tri hang don vi
		}
		if(index==2)
		{
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			L02=0;
			P0=led7_data[Data/10]; //xuat gia tri hang truc
		}
	//******************************************************************************
		if(index==3)
		{
			if(mode==1 && bat_nhay==1){ index++; index++; }
			else
			{
				Data=min;
				P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
				P0=0xff;
				L03=0;
				P0=led7_data[Data%10];//xuat gia tri hang don vi
			}
		}
		if(index==4)
		{
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			L04=0;
			P0=led7_data[Data/10]; //xuat gia tri hang truc
		}
	//******************************************************************************
		if(index==5)
		{
			if(mode==2 && bat_nhay==1){ index++; index++; }
			else
			{ 
				Data=hour;
				P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
				P0=0xff;
				L05=0;
				P0=led7_data[Data%10];
			}
		}
		if(index==6)
		{ 	
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			L06=0;
			P0=led7_data[Data/10]; 
		} 
	//******************************************************************************
		if(index==7) 
		{
			if(mode==3 && bat_nhay==1){ index++; }
			else
			{ 	
			   	Data=day;
				P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
				P0=0xff;
				L15=0;
				P0=led7_data[Data%10]; 
			} 
		}
	//******************************************************************************
		if(index==8)
		{
			if(mode==4 && bat_nhay==1){ index++; index++; }
			else
			{
				Data=date;
				P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
				P0=0xff;
				L07=0;
				P0=led7_data[Data/10];// xuat gia tri hang truc
			}
		}
		if(index==9)
		{
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			L08=0;
			P0=led7_data[Data%10];//xuat gia tri hang don vi
		}
	//******************************************************************************
		if(index==10)
		{
			if(mode==5 && bat_nhay==1){ index++; index++; }
			else
			{
				Data=month;
				P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
				P0=0xff;
				L09=0;
				P0=led7_data[Data/10];// xuat gia tri hang truc
			}
		}
		if(index==11)
		{
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			L10=0;
			P0=led7_data[Data%10];//xuat gia tri hang don vi
		}
	//******************************************************************************
		if(index==12)
		{
			if(mode==6 && bat_nhay==1){ index++; index++; }
			else
			{
				Data=year;
				P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
				P0=0xff;
				L13=0;
				P0=led7_data[Data/10];// xuat gia tri hang truc
			}
		}
		if(index==13)
		{
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			L14=0;
			P0=led7_data[Data%10];//xuat gia tri hang don vi
		}
		if(index==14)
		{
			Data=year_20;
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			L11=0;
			P0=led7_data[Data/10];// xuat gia tri hang truc
		}
		if(index==15)
		{
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			L12=0;
			P0=led7_data[Data%10];//xuat gia tri hang don vi
			index=0;
		}
	}
	if(Display==1)
	{
		index++;
		if(index==1)
		{
			if(alarm==1 && bat_nhay==1){ index++; index++; }
			else
			{
				Data=a_min;
				P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
				P0=0xff;
				L03=0;
				P0=led7_data[Data%10];
			}
		}
		if(index==2)
		{
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			L04=0;
			P0=led7_data[Data/10];
		}
		if(index==3)
		{
			if(alarm==2 && bat_nhay==1){ index++; index++; }
			else
			{
				Data=a_hour;
				P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
				P0=0xff;
				L05=0;
				P0=led7_data[Data%10];
			}
		}
		if(index==4)
		{
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			L06=0;
			P0=led7_data[Data/10];
		}
	   	if(index==5)
		{
			if(alarm==3 && bat_nhay==1){ index++; index++; }
			else
			{
				P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
				P0=0xff;
				if(on_off==1)
				{
					L13=0;
					P0=0xC8;	
				}
				else 
				{
					L13=0;
					P0=0x8E;
				}
			}
		}
		if(index==6)
		{
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			if(on_off==1)
			{
				L14=0;
				P0=0xff;	
			}
			else 
			{
				L14=0;
				P0=0x8E;
			}
		}
		if(index==7)
		{
			P2=0xFF; L09=L10=L11=L12=L13=L14=L15=1;
			P0=0xff;
			L12=0;
			P0=led7_data[0];
			index=0;
		}
	}
//******************************************************************************
	TR1=1;
}
//************ CHUONG TRINH CHINH *************
void main()
{
	bip(); delay(10);
	Out_1Hz();

	set_main();
	year_20=20;
	time=index=mode=read_time=0;
	setup_timer();
	while(1)
	{
		Keypad();
	 	if(hour>=12) PM=1;
		else PM=0;
		if((mode==0)&&(read_time==1))
		{
				read_time = 0;
				Read_DS1307();
		}
		if(((a_min==min)&&(a_hour==hour)))
		{
			if(sec<59) { bip(); delay(10000);}
		}
	}
} 
