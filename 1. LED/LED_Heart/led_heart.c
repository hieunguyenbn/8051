#include<reg52.h>

void delay(int time){
	while (time--);
}
void blink() {
	P0=P1=P2=P3=0;
	delay(10000);
	P0=P1=P2=P3=0xFF;
	delay(10000);
}
main() {
	while(1) {
		blink();
	}
}
