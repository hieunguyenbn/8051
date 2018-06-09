#include <REGX52.H>
#include "24xx512.h"	
#include "lcd.h"	
#include "templib.h"


unsigned char x,k;
unsigned char dat;
unsigned char x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;

void send(unsigned char a)     
{
            SBUF=a;            
            while(TI==0){}     
            TI=0;              
}

void delay(int t)
{
	int i,j;
	for (i=0; i<t;i++)
	{
		for(j=0;j<=123;j++);
	}

}

void init()
{
unsigned char inner, outer;

for (outer = 0x00; outer < 0x10; outer++) 
{
for (inner = 0x00; inner < 0xFF; inner++);
}

LCD_init();

for (inner = 0; inner < 10; inner++) 
LCD_delay(2);
}

/***************************** Main function *************************************/
void main(void)	
{
 TMOD=0x20;                       
 TH1=0xFA;                        
 SCON=0x50;                       
 TR1=1;   

 IE=0x85;// su dung ngat ngoai chan INT0
IT0=1;// ngat suon âm
IT1=1;
init();
init();
while(1)
{
//	ReadTemp();
LCD_row1(); LCD_puts("T= ");
	
//LCD_number(temp);
dat = EEPROM_get(0xffff);// doc data da luu	
LCD_row2(); LCD_command(0xc0+2);LCD_number(dat);

temp=dat;// doc lai gia tri bien khi mat dien

} 
} /* End main */

void ngat0(void) interrupt 0
{
delay(200);
ReadTemp();
delay(200);
EEPROM_set(0xffff,temp);// luu bien vao eeprom


}

void ngat1(void) interrupt 2
{
delay(100);
send('T'); send('=');
send(dat/10+48); send(dat%10+48); send(0x9BA); send(67);
send(10); 
//delay(100);
}	 		   