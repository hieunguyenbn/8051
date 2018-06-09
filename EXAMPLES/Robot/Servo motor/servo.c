#include	<regx52.h>
#include "..\..\LIBRARY\delay.h"
void Delayms(unsigned int t) {
	unsigned int x, y;
	for (x = 0; x < t; x++)
		for (y = 0; y < 123; y++);
}
void delay(unsigned int t) {
	while (t--);
}
void StartRange();
void SRF05_Init(void);
sbit M1=P3^7;	  //Output Pin for motor Actuation (PWM output pin)
sbit TRIGGER = P3^5;
sbit ECHO = P3^2;
sbit in1 = P2^0;
sbit in2 = P2^1;
sbit in3 = P2^2;
sbit in4 = P2^3;
sbit en1 = P1^0;
sbit en2 = P1^1;
unsigned int distance;
float d, dRight, dLeft;
main() {
	unsigned int i=0;
	SRF05_Init();
	while (1) {
		StartRange(); // bat dau do kc su dung cam bien sieu am
		if (d > 12.0) { //neu kc > 12
		for(i=0;i<30;i++){ // quay servo ve goc 90
			M1=1;//Pwm_High();
			delay(125);	
			M1=0;//Pwm_Low();	
			Delayms(18.5);
		}
		for(i=0;i<30;i++){ // quay servo ve goc 90
			M1=1;//Pwm_High();
			delay(66);	
			M1=0;//Pwm_Low();	
			Delayms(19);
		}
		in1 = 1;
		in2 = 0;  // xe di thang
		delay_ms(1000);
		
//		in4 = 0; 
//		delay_ms(1000); // xe di than
//		in3 = 1;
		}
	}
}
void StartRange() {
		TRIGGER = 1;
		delay_ms(12);//tao 1 xung len
		ECHO = 1;  // set chan ECHO 
		delay_us(1);
		TRIGGER = 0;// Bat dau phep do.
		while(!(ECHO));	// Doi cho den khi chan ECHO duoc keo len ca
		TR0 = IT0 = EX0 = EA = 1;	// Cho phep timer 0 hoat dong	// cho phep ngat toan cuc
}


void SRF05_Init(void) {
	TRIGGER = 0;
	TMOD = 0x01;   //timer 0 che do 1 (16bit)
	TR0 = 1; EX0 = 1; IT0 = 1;       //ngat ngoai 0 che do ngat theo suon
	EA = 1;          // cho phep ngat toan cuc
}

void ngatngoai0(void)interrupt 0 {
	distance = TH0;
	distance <<= 8;
	distance |= TL0;
	d = (float) distance/60;
	TR0 = 0; IT0 = 0; EX0 = 0;					       		// Ngung timer
	TL0 =  0; TH0 = 0; 			                  // Xoa du lieu trong thanh ghi Timer 0		             
}   
