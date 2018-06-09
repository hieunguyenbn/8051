#include <reg52.h>
#include "..\..\LIBRARY\delay.h"
unsigned char count = 200;
sbit led = P0^0;

void delay(unsigned int t) {
	while(t--);
}
main() {

	TMOD = 0x02; // Timer 0 che do 2
	TH0 = 5;
	TL0 = 0; // Nap TH0,
	TF0 = 0; // xoa co tràn
	IE = 0x82; //cho phep ngat timer 0
	//ET0 = 1;
	//EA =1;
	TR0 = 1; // khoi dong Timer 0
	while(1) {
		PCON |= 0x01;
		led = ~ led;
		delay(300);

	}

}
void Stop() interrupt 1 { //NGAT TIMER 0
	count--;
	if (count == 0) {
		count = 200;
		P1 = ~P1;
		delay_ms(2000);
				
	}
}