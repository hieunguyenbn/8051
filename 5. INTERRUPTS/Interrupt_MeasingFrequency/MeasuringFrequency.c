//do tan so su dung ngat ngoai + ngat timer
#include <reg52.h>

#define on 0
#define off 1
sbit in = P3^2;
sbit led1 = P2^0;
sbit led2 = P2^1;
sbit led3 = P2^2;
sbit led4 = P2^3;
unsigned int count = 0, f, t = 0;
unsigned char a[10] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90};

void init();
void show(unsigned int dem);
void delay(unsigned int time);

main() {
	init();
	while (1) {
		show(f);
	}			
}
void delay(unsigned int time) {
	while(time--);
}
void init() {
	TMOD = 0x10; //timer 1, che do 1
	in = 1;
	EX0 = 1;
	ET1 = 1;
	IT0 = 1;
	TR1 = 1;
	EA = 1;
}
void ClockCounting(void) interrupt 0 {
	count++;
}
void timer(void) interrupt 3 {
	t++;
	TH1 = 0xFC;
	TL1 = 0x18;
	TR1 = 1;
	if (t >= 1000) {
		f = count;
		count = 0; t = 0;
	}
}
void show(unsigned int dem) {
	unsigned char nghin, tram, chuc, donVi;
	unsigned int i;
	nghin = dem/1000; tram = (dem%1000)/100; chuc = (dem%100)/10; donVi = dem%10;
	for (i = 0; i < 20; i++) {
		led1 = on; P0 = a[nghin]; delay(100); led1 = off;
		led2 = on; P0 = a[tram]; delay(100); led2 = off;
		led3 = on; P0 = a[chuc]; delay(100); led3 = off;
		led4 = on; P0 = a[donVi]; delay(100); led4 = off;
	}
}	