/* Basic program to show latitude and longitude on LCD extracted from GPGGA statement */
 
#include<reg51.h>
#define port2 P2
sbit rs = P1^0;
sbit rw = P1^1;
sbit e = P1^2;
char info[70];
char test[6]={"$GPRMC"};
char comma_position[15];
unsigned int check=0,i;
unsigned char a;

void receive_data();
void lcd_latitude();
void lcd_longitude();
 
//DELAY FUNCTION
void delay(unsigned int msec)
{
int i,j ;
for(i=0;i<msec;i++)
for(j=0;j<1275;j++); 
}
 
// LCD COMMAND SENDING FUNCTION
void lcd_cmd(unsigned char item)
{
port2 = item;
rs= 0;
rw=0;
e=1;
delay(1);
e=0;
return;
} 
 
// LCD DATA SENDING FUNCTION
void lcd_data(unsigned char item)
{
port2 = item;
rs= 1;
rw=0;
e=1;
delay(1);
e=0;     
return;
}
 
 // LCD STRING SENDING FUNCTION 
void lcd_string(unsigned char *str)
{
int i=0;
while(str[i]!='\0')
{
        lcd_data(str[i]);
        i++;
        delay(10);
   }
        return;
}
 
// SERIAL PORT SETTING
void serial()
{
TMOD=0x20;      //MODE=2
TH1=0xfd;      // 9600 BAUD
SCON=0x50  ;    // SERIAL MODE 1 ,8- BIT DATA ,1 STOP BIT ,1 START BIT , RECEIVING ON
TR1=1;          //TIMER START
}
 
void find_comma()
{
unsigned int i,count=0;
for(i=0;i<70;i++)
{ 
if(info[i]==',')
{
comma_position[count++]=i;
}
    }
}
void compare()
{  
IE=0x00;        //Interrupt disable 
find_comma();    //Function to detect position of comma in the string
lcd_latitude();   //Function to show Latitude
lcd_longitude(); //Function to show Longitude
check=0;
IE=0x90;    //Interrupt enable
}
void receive_data()      interrupt 4   
{
info[check++]=SBUF;   //Read SBUF
if(check<7)          //Condition to check the required data
    {
if(info[check-1]!=test[check-1])
check=0;
    }
RI=0;
}
void lcd_shape()       //Function to create shape of degree
{
lcd_cmd(64);
lcd_data(10);
lcd_data(17);
lcd_data(17);
lcd_data(10);
lcd_data(0);
lcd_data(0);
lcd_data(0);
lcd_data(0);
}
 
void lcd_latitude()  //Function to display Latitude
{
unsigned int c2=comma_position[2]; //Position of second comma
lcd_shape();	
lcd_cmd(0x80);          //Move cursor to position 6 of line 1
lcd_string("LAT ");  //Showing Latitude 
	
lcd_data(info[c2+1]);	
lcd_data(info[c2+2]);	
lcd_data(0);					// TO display degree symbol 
	
for(i=3;i<=9;i++)
{
	lcd_data(info[c2+i]);
}
lcd_data(0x27);	
lcd_data(info[c2+11]);
} 
 
void lcd_longitude()
{
unsigned int c4=comma_position[4];
lcd_shape();		
lcd_cmd(0xc0);
lcd_string("LON"); //Showing Longitude

lcd_data(info[c4+1]);	
lcd_data(info[c4+2]);	
lcd_data(0);					// TO display degree symbol 
for(i=3;i<=10;i++)
{
	lcd_data(info[c4+i]);
}
lcd_data(0x27);
lcd_data(info[c4+12]);
}
void main()
{
	
serial();
lcd_cmd(0x38);         //2 LINE, 5X7 MATRIX
lcd_cmd(0x0c);         //DISPLAY ON, CURSOR BLINKING
lcd_string("GPS SYSTEM");  //Showing Latitude	
IE=0x90;
while(1)
{
if(check==69)
compare();
}
}
 
 