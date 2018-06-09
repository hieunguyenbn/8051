#include "srf05.h"
uint8_t range_ok;
uint16_t distance;
float range,temp1;
 void  StartRange()
{
	TRIGGER=1;
	delay_ms(12); 		         // Phai tao 1 xung len co do lon it nhat 10ms
	ECHO=1;                      // set chan ECHO la cong vao
	delay_us(1);
	TRIGGER=0;			         // Bat dau phep do.
	while(!(ECHO));		         // Doi cho den khi chan ECHO duoc keo len cao
	//TR0=1;		                 // Cho phep timer 0 hoat dong
	TR0=IT0=EX0=EA=1;						 // cho phep ngat toan cuc
}


void SRF05_Init(void)
{
	TRIGGER=0;
	TMOD=0x01;   //timer 0 che do 1 (16bit) cuc GATE mo
	TR0=1;
	IT0=1;       //ngat ngoai 0 che do falling
	IT1=1;
	EX0=1;          //cho phep ngat ngoai 0
	EX1=1;
	EA=1;          // cho phep ngat toan cuc
	range_ok=0;
}

//ngat ngoai 0
void ngatngoai0(void)interrupt 0
{
	distance=TH0;
	distance<<=8;
	distance|=TL0;
	range=(float)distance*12;
	temp1=((58*11.0592));
	//temp1= 641;
	range=range/(temp1);
	TR0=IT0=EX0= 0;					       		// Ngung timer
	TL0=TH0=0; 			                  // Xoa du lieu trong thanh ghi Timer 0		             
	range_ok=1;
}   
