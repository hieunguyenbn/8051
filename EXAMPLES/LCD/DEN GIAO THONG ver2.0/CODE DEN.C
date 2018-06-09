#include <regx52.h>
#include <delay.h>
#include <lcd4b_new.h>
#include <stdio.h>
// Khai bao cac nut an
#define up 		P3_0
#define down 	P3_1
#define set 	P3_2
// Khai bao cac den giao thong
#define x1 		P0_0
#define v1 		P0_1
#define d1 		P0_2

#define x2 		P0_3
#define v2 		P0_4
#define d2 		P0_5

#define dulieu 	P1
#define quet1 	P3_4
#define quet2 	P3_5
#define quet3 	P3_6
#define quet4 	P3_7

// Khai bao cac bien
unsigned int t,k=0,i;
signed int demx, demd, demv;
signed int dem1, dem, demc;
unsigned int ch1,dv1,ch,dv;
unsigned int smode=0,t;
char str[16];
char chedo=0;
unsigned int maso[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f}; // ma cua am chung

// chuong trinh phuc vu ngat
void ngattimer1() interrupt 3	// ngat timer1
{
// 1khz: 1/1.000x 20/12 = 1.667s = 1667us = 1,6ms (  thach anh 20MHZ)
// ton=toff=833 nhap -833 vao may tinh duoc TH=0XFC, TL=0XBF
if(k==0)
{
    TR1=0;
	TH1=0xFC;
	TL1=0xBF;
	t++;
	if(t>1800)			// gia tri t de tinh sai so 1s, tao xung 1ms neu dung t=1000
		{
			demc++;	dem1--; dem--;	P3_3=~P3_3;					
			t=0;		   
		}	
	if(demc==0)
	{
		d1=0;x1=0;v1=0;d2=0;x2=0;v2=0;
		dem=dem1=0;
	}
	if(demc>0&&demc<=demx)	
	{
		d1=1;x1=0;v1=0;d2=0;x2=1;v2=0; 
		if(demc==1){dem1=demd;dem=demx;}
						
	}
	if(demc>demx&&demc<=demd)	
	{
		d1=1;x1=0;v1=0;d2=0;x2=0;v2=1;
	   	if(demc==demx+1){dem=demv;}
	}
	if(demc>demd&&demc<=(demx+demd)) 
	{	
		d1=0;x1=1;v1=0;d2=1;x2=0;v2=0;
		if(demc==demd+1){dem=demd;dem1=demx;}
	}
	if(demc>(demx+demd)&&demc<=(demx+demd+demv)) 
	{
		d1=0;x1=0;v1=1;d2=1;x2=0;v2=0;
		if(demc==demx+demd+1)dem1=demv;
		
	}
	if(demc>demx+demd+demv)demc=1;	
	TR1=1;
}
}
void khai_bao_ngat()
{
	EA=1;						//cho phep ngat toan cuc
	ET1=1;						// cho phep ngat timer0
	TMOD=0x10;					// che do timer0 8 bit, timer1 16 bit	
	TH1=0xFE;					// nap gia tri cho thanh ghi TH1
	TL1=0x0C;					// nap gia tri cho thanh ghi TL1	
	TR1=1;
}
void cai_giatridau()
{
	demd=15;demx=12;demv=demd-demx;	
}
void hien_thicai()
{

	dulieu=quet1=quet2=quet3=quet4=0;
	d1=d2=x1=x2=0;
	v1=v2=1;delayms(100);	
	v1=v2=0;delayms(100);	
}
void vang_chop()
{
   	dulieu=quet1=quet2=quet3=quet4=0;
	d1=d2=x1=x2=0;
	v1=v2=1;delayms(300);	
	v1=v2=0;delayms(300);
}
void hienthi_7seg()
{

	ch1=dem/10;
	dv1=dem%10; 

	ch=dem1/10;
	dv=dem1%10;   

 	dulieu=0;quet1=0;quet2=0;quet3=0;quet4=0;	  // ban dau tat het led
	delayus(1);      
	dulieu=maso[ch1];   	  // dao toan bo gia tri tu 0-->1 hoac tu 1-->0
	quet1=1;quet2=0;quet3=0;quet4=0;
	delayus(20);    

	dulieu=0;quet1=0;quet2=0;quet3=0;quet4=0;
	delayus(1);      
	dulieu=maso[dv1];   	  // dao toan bo gia tri tu 0-->1 hoac tu 1-->0
	quet1=0;quet2=1;quet3=0;quet4=0;
	delayus(20);    

	dulieu=0;quet1=0;quet2=0;quet3=0;quet4=0;
	delayus(1);      
	dulieu=maso[ch];   	  // dao toan bo gia tri tu 0-->1 hoac tu 1-->0
	quet1=0;quet2=0;quet3=1;quet4=0;
	delayus(20);
	    
	dulieu=0;quet1=0;quet2=0;quet3=0;quet4=0;
	delayus(1);      
	dulieu=maso[dv];   	  // dao toan bo gia tri tu 0-->1 hoac tu 1-->0
	quet1=0;quet2=0;quet3=0;quet4=1;
	delayus(20); 
 
}
void cai_lcd()
{
 	switch(smode)
	{
	 case 1:
	 	{
		LCD_Gotoxy(1,1);
		LCD_Puts("SET RED LIGHT    ");
		LCD_Gotoxy(2,1);
		LCD_Puts("RED:");
		LCD_Gotoxy(2,5);
		sprintf(str,"%u               ",demd);
		LCD_Puts(str); break;
		}
	case 2:
	{
		LCD_Gotoxy(1,1);
		LCD_Puts("SET GREEN LIGHT ");
		LCD_Gotoxy(2,1);
		LCD_Puts("GREEN:");
		LCD_Gotoxy(2,7); 
		sprintf(str,"%u         ",demx);
		LCD_Puts(str);break; 
	}
	case 3:
	{
			LCD_Gotoxy(1,1);
			LCD_Puts("SET TIMER: RUN    ");
			LCD_Gotoxy(2,1);
			LCD_Puts("RED:");		  
			LCD_Gotoxy(2,5);
			sprintf(str,"%u ",demd);
			LCD_Puts(str);
	
			LCD_Gotoxy(2,8);
			LCD_Puts("GRE:");
			LCD_Gotoxy(2,12);
			sprintf(str,"%u ",demx);
			LCD_Puts(str); break;
	}
	}
}
void giatri_dau_lcd()
{
	
		LCD_Gotoxy(2,1);
		LCD_Puts("RED:");
		LCD_Gotoxy(2,5);
		sprintf(str,"%u ",demd);
		LCD_Puts(str);

		LCD_Gotoxy(2,8);
		LCD_Puts("GRE:");
		LCD_Gotoxy(2,12);
		sprintf(str,"%u ",demx);
		LCD_Puts(str); 
}
void cai_giatri()
{
	if((up==0)&&(down==0)){chedo=1;}

	if(chedo==1){k=1;vang_chop();}

	if(set==0){chedo=0;while(!set);smode++;}
	if(smode>3) smode=0;
	if(smode!=0) 
		{	
			k=1;
			cai_lcd();		
			hien_thicai();
			P2_3=1;
			
		}
		 else 
		{
			 k=0;
			 hienthi_7seg();
			 P2_3=0;			 
		}

	if(smode==1)
		{
			if(up==0)	{demd++;}
			if(down==0)	{demd--;}
			if(demd>99)	demd=10;
			if(demd<10) demd=99;
	
		}
	if(smode==2)
		{
		   	if(up==0)	{demx++;}
			if(down==0)	{demx--;}
			if(demx>demd-3)		demx=7;
			if(demx<7) 	demx=demd-3;
	
		}
	if(smode==3)
		{
			demv=demd-demx;
			dem=demd;dem1=demx;
			demc=0;	 t=0;	
			delayms(1000);smode=smode+1;	
		}	  
}

void main()
{	  	
	khai_bao_ngat();
	cai_giatridau();
	LCD_Init();
	LCD_Gotoxy(1,1);
	LCD_Puts("SET TIMER: RUN  ");
	giatri_dau_lcd();
	P0=0;
	P2_3=0;
	while(1)
	{	
	  	cai_giatri();
					  
	}
}