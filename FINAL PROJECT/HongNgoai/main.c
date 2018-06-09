#include "main.h"

/*************
Code remote
Power 	= 0x45
Mode 		= 0x46
Mute 		= 0x47
>|| 		= 0x44
|<< 		= 0x40
>>|			= 0x43
EQ			= 0x07
VOL-		= 0x15
VOL +		= 0x09
0				= 0x16
RPT			= 0x19
U/SD		= 0x0D
1				= 0x0C
2				= 0x18
3				= 0x5E
4				= 0x08
5				= 0x1C
6				= 0x5A
7				= 0x42
8				= 0x52
9				= 0x4A
****************/
sbit IRIN=P3^2;

unsigned char IrValue[4];
unsigned char Time;

void DelayMs(unsigned int x)   
{
 unsigned char i;
  while(x--)
 {
  for (i = 0; i<13; i++);
 }
}

void main()
{
	unsigned char i,j;
	IT0=1;		//Ngat canh xuong
	EX0=1;		//Cho phep ngat ngoai INT0
	EA=1;			//Cho phep nhat toan cuc

	IRIN=1;
	while(1)
	{
		j = IrValue[2];
		if(i!=j)
		{
			i=j;
			
			if(i == 0x0C) P1_0 = !P1_0;			
			if(i == 0x18) P1_1 = !P1_1;
			if(i == 0x5E) P1_2 = !P1_2;
			if(i == 0x08) P1_3 = !P1_3;
			if(i == 0x1C) P1_4 = !P1_4;
			if(i == 0x5A) P1_5 = !P1_5;
			if(i == 0x42) P1_6 = !P1_6;
			if(i == 0x52) P1_7 = !P1_7;
			
		}
	}
}

void ReadIr() interrupt 0
{
	unsigned char j,k;
	unsigned int err;
	Time=0;					 
	DelayMs(70);

	if(IRIN==0)		
	{	 
		
		err=1000;				//1000*10us=10ms
		while((IRIN==0)&&(err>0))	  		
		{			
			DelayMs(1);
			err--;
		} 
		if(IRIN==1)			
		{
			err=500;
			while((IRIN==1)&&(err>0))		 
			{
				DelayMs(1);
				err--;
			}
			for(k=0;k<4;k++)
			{				
				for(j=0;j<8;j++)	
				{

					err=60;		
					while((IRIN==0)&&(err>0))
//					while (!IRIN)
					{
						DelayMs(1);
						err--;
					}
					err=500;
					while((IRIN==1)&&(err>0))	 
					{
						DelayMs(1);//0.14ms
						Time++;
						err--;
						if(Time>30)
						{
							EX0=1;
							return;
						}
					}
					IrValue[k]>>=1;	 
					if(Time>=8)			
					{
						IrValue[k]|=0x80;
					}
					Time=0;								
				}
			}
		}
		if(IrValue[2]!=~IrValue[3])
		{
			return;
		}
	}			
}