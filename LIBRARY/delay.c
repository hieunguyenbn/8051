#include "delay.h"

void delay_ms(unsigned int t) {
	unsigned int x, y;
	for (x = 0; x < t; x++)
		for (y = 0; y < 123; y++);
}
void delay_us(unsigned int t) { // Calling the routine takes about 24us, and then
	unsigned int i; // each count takes another 16us.
	for(i = 0; i < t; i++);
}
void delay(unsigned int t) {
    while(t--);
}
//void delay_us(unsigned int t) {
//	unsigned int load_value;
//	load_value = 65536 - t;
//	TH0 = load_value >> 8;
//	TL0 = load_value & 0x00FF;
//	TR0 = 1;
//	while(!TF0);
//	TR0 = 0;
//	TF0 = 0;
//}