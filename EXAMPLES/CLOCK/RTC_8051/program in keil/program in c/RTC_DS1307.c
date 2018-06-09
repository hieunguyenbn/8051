#include<reg52.h> 
#include "LCD8bit.h"
#include "I2C.h"
#include "delay.h"

 
int i;
unsigned char sec[2],min[2],hour[2],dow=0,dom[2],month[2],year[2];
unsigned int a[7];
typedef enum { false, true } bool; 
 

 

 
int Dec_To_BCD(int dec){
      return( (dec/10*16) + (dec%10) );
    }
    



void readAllReg()
		{
I2CStart();	
I2CSend(0xD0);	
I2CSend(0x00);	
I2CStart();	
I2CSend(0xD1);
for (i = 0; i < 8; i++) {

	a[i] = I2CRead();
 
	if(i == 7)
		I2CNak();
	else
		I2CAck();
}
I2CStop();	
			
		}
		
void setTime(int Sec, int Min, int Hour,int Dow, int Dom, int Month, int Year)
{


I2CStart();	
I2CSend(0xD0);	
I2CSend(0x00);	
I2CSend(Dec_To_BCD(Sec)&0x7f);
I2CSend(Dec_To_BCD(Min)&0x7f);
I2CSend(Dec_To_BCD(Hour)&0x3f);
I2CSend(Dec_To_BCD(Dow)&0x07);
I2CSend(Dec_To_BCD(Dom)&0x3f);
I2CSend(Dec_To_BCD(Month)&0x1f);
I2CSend(Dec_To_BCD(Year)&0xff);
I2CStop();



}	

int readSecReg()
{

I2CStart();	
I2CSend(0xD0);	
I2CSend(0x00);	
I2CStart();	
I2CSend(0xD1);
a[0] = I2CRead();
I2CNak();
I2CStop();
return(a[0]);
}	

void displayTime()
{
int SEC=0;
int	AM_PM=0;	
	
	Cmd(0x01);
	Cmd(0x80);
  readAllReg();

a[0]=(a[0]&0x0f)+(((a[0]>>4)&0x07)*10);
sec[0]=(a[0]/10)+48;sec[1]=(a[0]%10)+48;
a[1]=(a[1]&0x0f)+(((a[1]>>4)&0x07)*10);
min[0]=a[1]/10+48;min[1]=a[1]%10+48;
a[2]=((a[2]&0x0f))+(((a[2]>>4)&0x03)*10);
if(a[2]>12){
AM_PM=a[2]-12;	
hour[0]=AM_PM/10+48;hour[1]=AM_PM%10+48;}
else{
hour[0]=a[2]/10+48;hour[1]=a[2]%10+48;}
a[3]=(a[3]&0x07);dow=a[3];
a[4]=(a[4]&0x0f)+(((a[4]>>4)&0x03)*10);
dom[0]=a[4]/10+48;dom[1]=a[4]%10+48;
a[5]=(a[5]&0x0f)+(((a[5]>>4)&0x01)*10);
month[0]=a[5]/10+48;month[1]=a[5]%10+48;
a[6]=(a[6]&0x0f)+(((a[6]>>4)&0x0f)*10);
year[0]=a[6]/10+48;year[1]=a[6]%10+48;


Data(hour[0]);Data(hour[1]);Data(':');
Data(min[0]);Data(min[1]);Data(':');
Data(sec[0]);Data(sec[1]);Data(' ');
if(a[2]<12) Disp("AM"); else Disp("PM");

Cmd(0xc0);
Data(dom[0]);Data(dom[1]);Data('/');
Data(month[0]);Data(month[1]);Data('/');
Data(year[0]);Data(year[1]);Data(' ');
switch(dow)
      {
      case 1:Disp("Sunday");break;
      case 2:Disp("Monday");break;
      case 3:Disp("Tuesday");break;
      case 4:Disp("Wednesday");break;
      case 5:Disp("Thursday");break;
      case 6:Disp("Friday");break;
      case 7:Disp("Saturday");break;    
      }
		
while(a[0]<59)
{
	setCursor(6,0);
	readSecReg();
	a[0]=(a[0]&0x0f)+(((a[0]>>4)&0x07)*10);
  sec[0]=(a[0]/10)+48;sec[1]=(a[0]%10)+48;
	if(SEC!=a[0]){
	Data(sec[0]);Data(sec[1]);SEC=a[0];}
  Delay_ms(100);	
}
Delay_ms(1000);	


	
}





void main()
{
	initializeLCD();

setTime(55,59,11,3,18,7,17); 
while(1)
{
	

displayTime();


}	
	
	
}