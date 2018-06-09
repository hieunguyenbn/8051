//led 7 segs with up and down buttons

#include <reg52.h>

void delay_ms(unsigned int t) {
	unsigned int x, y;
	for (x = 0; x < t; x++)
		for (y = 0; y < 123; y++);
}

sbit s1 = P2^6;
sbit s2 = P2^7;
unsigned char i, j, a[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
main() {
	IE = 0x85;// enable externainterupo 0 and 1
	IT0 = 1;
	IT1 = 1;
	while(1) {
		if(i > 99 || i < 0) i = 0;
		delay_ms(1);
			P1 = a[i%10];
			s1 = 0; delay_ms(1); s1 = 1;
			P1 = a[i/10];
			s2 = 0; delay_ms(1); s2 = 1;
	}		
}
void up(void) interrupt 0 {
	i++;
}
void down(void) interrupt 2 {
	i--;
}