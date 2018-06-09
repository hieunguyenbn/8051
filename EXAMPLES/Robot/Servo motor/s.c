#include <reg52.h>

sbit L293D_A = P2^0;         //Positive of motor
sbit L293D_B = P2^1;         //Negative of motor
sbit L293D_E = P2^2;         //Enable of L293D
 
// Function Prototypes
void rotate_f(void);         //Forward run funtion
void rotate_b(void);         //Backward run function
void breaks(void);         //Motor stop function
void delay(void);           //Some delay
 
void main()
{
	while (1) {               //Infinite loop
		rotate_f();       //Run forward
		delay();             //Some delay
		breaks();           //Stop
		delay();             //Some delay
		rotate_b();       //Run Backwards
		delay();             //Some delay
		breaks();           //Stop
		delay();             //Some delay
	}                       //Do this infinitely
}
 
void rotate_f()
{
	L293D_A = 1;             //Make positive of motor 1
	L293D_B = 0;             //Make negative of motor 0
}
 
void rotate_b()
{
	L293D_A = 0;             //Make positive of motor 0
	L293D_B = 1;             //Make negative of motor 1
}
 
void breaks()
{
	L293D_A = 0;             //Make positive of motor 0
	L293D_B = 0;             //Make negative of motor 0
}
 
//Some delay...
void delay()
{
	unsigned char i,j,k;
	for(i=0;i<0x20;i++)
		for(j=0;j<255;j++)
		    for(k=0;k<255;k++);
}