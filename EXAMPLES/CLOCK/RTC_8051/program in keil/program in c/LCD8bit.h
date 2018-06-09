

#ifndef __LCD8bit_H
#define __LCD8bit_H

#include "delay.h"


#define PORT P0

sbit RS = P2^7;
sbit RW = P2^6;
sbit EN = P2^5;


 


void Cmd(char a)
{

		P0 = a;
  RS=0;RW=0;EN=1;
	Delay_ms(8);
	EN=0;
}

void Data(char b)
{

	P0 = b;
	RS=1;RW=0;EN=1;
	Delay_ms(8);
	EN=0;
}

	
void Disp(const char *p)
{
while(*p!='\0')
{
Data(*p);
p++;
}}	

void setCursor(int a, int b)
{
	int i=0;
  switch(b){
	case 0:Cmd(0x80);break;
	case 1:Cmd(0xC0);break;
  case 2:Cmd(0x94);break;
  case 3:Cmd(0xd4);break;}
	for(i=0;i<a;i++)
	Cmd(0x14);
}	

void initializeLCD()
{
	

	Cmd(0x38);
	Cmd(0x01);
	Cmd(0x80);
	Cmd(0x06);
	Cmd(0x0C);	
}

void DispIntAsStr(unsigned int Integer)
{
 if((Integer/100+48)!='0')
 Data(Integer/100+48);
 Data((Integer%100)/10+48);
 Data(Integer%10+48);
}	
	
void DispTimeInMode12(unsigned int hour,unsigned int min)
{
int AM_PM=hour;
if(hour>12)AM_PM=hour-12;
DispIntAsStr(AM_PM);Data(':');DispIntAsStr(min);Data(' ');
if(hour<12) Disp("AM"); else Disp("PM");	
}


#endif
