						#include <at89x52.h>
void delay(int t)
{
	int i,j;
	{
		for(i=1;i<t;++i)
			for(j=1;j<125;++j)
				{}
	}
}
int i=0;
int dem()
{
	
	if(P3_1==1)
	{
		delay(1);
		while(P3_1==1)
		{;}
		if(P3_2==1)
		{
			delay(1);
			while(P3_2==1)
			{;}
			i=i+1;
			 	   	if(i<0)
			{
				i=0;
			}
		if (i==10)
			{
				i=9;
			}
		
	}
	}

	if(P3_2==1)
	{
		delay(1);
		while(P3_2==1)
		{;}
		if(P3_1==1)
	{
		delay(1);
			while(P3_1==1)
			{;}
			i=i-1;
			   	if(i<0)
			{
				i=0;
			}
		if (i==10)
			{
				i=9;
			}
	}
	}
	return i;
}
unsigned char code ma[10]={0xce,0x0d,0x77,0x5f,0xcd,0xdb,0xfb,0x0f,0xff,0xdf};
void main()
{ 
	int k;
	P2=255;
	k=0;
	P3_1=0;
	P3_2=0;
	while(1)
	{
		k=dem();
		delay(50);
		P2=ma[k];
		delay(5);
		
}	
 }
