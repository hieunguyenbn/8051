#include <reg52.h>
 
void delay();

main() {            
    unsigned int i, a[8] = {0x00, 0x81, 0xC3, 0xE7, 0xFF, 0xE7, 0xC3, 0x81};
//a[8] = {0x7E, 0xBD, 0xDB, 0xE7, 0xE7, 0xDB, 0xBD, 0x7E};
    //, 0xE0, 0xC0, 0x80, 0x00,0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00};   
    while(1) {     
		for (i = 0; i < 8; i++) {
			P2 = a[i];
			delay();
		}
		delay();
    }

}
void delay() {	
    unsigned int j;
    for( j=0; j<32000; j++);
} 
