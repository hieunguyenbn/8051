

#ifndef __LCD4bit_H
#define __LCD4bit_H

#include "delay.h"






#define PORT P0
#define RS 4
#define EN 5


 


void Cmd(int a)
{

	PORT &= 0xf0;
	PORT |= (a>>4)  & 0x0f;
	PORT &= ~(1<<RS);
	PORT |= (1<<EN);
  Delay_ms(7);
  PORT &= ~(1<<EN);

	PORT &= 0xf0;
	PORT |= a & 0x0f;
	PORT &= ~(1<<RS);
	PORT |= (1<<EN);
  Delay_ms(7);
  PORT &= ~(1<<EN);
}

void Data(char b)
{

	PORT &= 0xf0;
	PORT |= (b>>4) & 0x0f;
	PORT |= (1<<RS);
	PORT |= (1<<EN);
  Delay_ms(7);
  PORT &= ~(1<<EN);

	PORT &= 0xf0;
	PORT |= b & 0x0f;
	PORT |= (1<<RS);
	PORT |= (1<<EN);
  Delay_ms(7);
  PORT &= ~(1<<EN);
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
	
	Cmd(0x20);
	Cmd(0x28);
	Cmd(0x01);
	Cmd(0x80);
	Cmd(0x06);
	Cmd(0x0C);	
}



#endif
