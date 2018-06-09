#include<reg52.h>
#include "..\..\LIBRARY\delay.h"


sbit motor_pin_1 = P2^1;
sbit motor_pin_2 = P2^2;
sbit motor_pin_3 = P2^3;
sbit motor_pin_4 = P2^4;
sbit en1 = P1^0;
sbit en2 = P1^1;
char duty = 0, pwm = 0;
unsigned char t = 0;
bit enable = 0; rl = 0;
void left(void);
void right(void);
void init_timer() {
		TMOD = 0x22;	// timer 0 che do 8 bit tu nap lai
		THP = 0x00;
		TL0 = 0xFC;
		ET1 = 1; TR1 = 1; EA = 1; //NGAT TIMER 1;
}
void ngat(void) interrupt 3 {// ngat timer 1
		TF1 = 0;
		if (enable == 1) {
			if (duty < pwm && pwm >= 0) {
					if (rf == 0) motor_pin3 = 1;
					else motor_pin1 = 1; // quay phai
			}
			else if (duty > pwm && duty < 100) {
					motor_pin3 = 0; motor_pin1 = 0; //off
			}
			duty++;
			if (duty==100) duty = 0; 
		}
}	
void main() {
  do
  {
		motor_pin_4 = 0; //Rotates Motor Anit Clockwise
 
		delay_ms(2000);
	//	delay();
  }while(1); 
}

