#include <reg52.h>
void delay();
main() {

	while(1) {
		P1 = 0xAA;
		delay();
		P1 >>= 1;
		delay();
	}
}

void delay() {
	unsigned int i;
	for (i = 0; i < 35000; i++) {
	}
}