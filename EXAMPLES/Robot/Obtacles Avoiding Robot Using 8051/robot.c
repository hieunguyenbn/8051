#include< reg52.h>
#include "..\..\LIBRARY\delay.h"

void StartRange();
void SRF05_Init(void);
void delay(unsigned int t) {
	while (t--);
}
sbit M1=P3^7;	  //Output Pin for motor Actuation (PWM output pin)
sbit TRIGGER = P3^5;
sbit ECHO = P3^2;
sbit in1 = P0^0;
sbit in2 = P0^1;
sbit in3 = P2^3;
sbit in4 = P2^4;

unsigned int distance;
float d;

main() {
	unsigned int i=0;
	SRF05_Init();
	while (1) {
	StartRange(); 
	if (d >= 12.0) { // neu khoang cach > 12 thi xe tiep tuc di thang
		// dong co servo quay goc 90 do
			while (d >= 12) {
					M1=1;//Pwm_High();
					delay(125);	
					M1=0;//Pwm_Low();	
					delay_ms(18.5);
					in1 = 1; in3 = 1; // di thang
					in2 = 0; in4 = 0;
					delay_ms(2000);
					if (d < 12.0) {
						in1 = 0; in3 = 0;  //stop
						in2 = 0; in4 = 0;
						while (d < 12.0) {	// neu kc < 12 thi xe dung lai
							in1 = 0; in3 = 0; 
							in2 = 0; in4 = 0;
							for(i=0;i<30;i++){	
								M1=1;//Pwm_High(); // quay servo sang phai de kiem tra
								delay(50);
								M1=0;//Pwm_Low(); 
								delay_ms(19);
							}
							if (d >= 12.0) {
								in1 = 1; in3 = 0; //re phai
								in2 = 0; in4 = 0;
								delay_ms(2000);
							}
							else {
							for(i=0;i<30;i++){	
								M1=1;//Pwm_High(); //quay servo sang trai
								delay_ms(3);	
								M1=0;//Pwm_Low();	
								delay_ms(17);
							}
							if (d >= 12.0) {
								in1 = 0; in3 = 1; // re trai
								in2 = 0; in4 = 0;
								delay_ms(2000);
							}
							else {
								in2 = 1; in4 = 1; //lui
								in1 = 0; in3 = 0;
							}
						}
					}		
				}
		}
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