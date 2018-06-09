#include< reg52.h>
void ms1();
void ms1P5();
sbit Pwm_M1=P3^0;  //Input Pin for motor Actuation


sbit M1=P3^0;	  //Output Pin for motor Actuation (PWM output pin)



void Pwm_Low()	  //Generating 18ms delay
{

TH0=0xBF;
TL0=0x32;
TR0=1;       //Run Timer-0
while(!TF0); //Wait for T0 Interrupt Flag
TF0=0;       //Clear Interrupt Flag
TR0=0;       //Stop Timer-0
}


void Pwm_High()		 //Generating 2ms delay
{
TH0=0xF8;
TL0=0xCC;
TR0=1;       //Run Timer-0
while(!TF0); //Wait for T0 Interrupt Flag
TF0=0;       //Clear Interrupt Flag
TR0=0;       //Stop Timer-0
}

void ms1(){             //Generating 1ms delay
TH0=0xFC;
TL0=0x65;
TR0=1;       //Run Timer-0
while(!TF0); //Wait for T0 Interrupt Flag
TF0=0;       //Clear Interrupt Flag
TR0=0;       //Stop Timer-0
}

void ms1P5(){				//Generating 1.5ms delay
TH0=0xFA;
TL0=0x99;
TR0=1;       //Run Timer-0
while(!TF0); //Wait for T0 Interrupt Flag
TF0=0;       //Clear Interrupt Flag
TR0=0;       //Stop Timer-0
}

void main() {
unsigned int i=0;

P3=0x00;  //**** Port-3 Declared Output

TMOD=0x01; //Timer-0, As 16-bit Timer.

while(1){
	
		for(i=0;i<100;i++){	
			M1=1;
			ms1();	
			M1=0;
			Pwm_Low(); 	 }
			
		for(i=0;i<100;i++){	
			M1=1;
			ms1P5();
			M1=0;
			Pwm_Low(); 	 }

		for(i=0;i<100;i++){	
			M1=1;
			Pwm_High();		 		
			M1=0;
			Pwm_Low();	  }

		for(i=0;i<100;i++){	
			M1=1;
			ms1();	
			M1=0;
			Pwm_Low(); 	 }	  
		}

}