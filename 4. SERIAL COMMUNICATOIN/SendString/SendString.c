//Send a string to PC
#include <reg52.h>
//#include <string.h>
void sendCharacter(unsigned char a);
void sendString(unsigned char *s);

main() {
	TMOD = 0x20;
	TH1 = 0xFD;
	SCON = 0x50;
	TR1 = 1;
	while(1) {
		sendString("NGUYEN SY HIEU\r\n");
	}
}

void sendCharacter(unsigned char a) {
	SBUF = a;
	while (TI==0);
	TI = 0;	
}
void sendString(unsigned char *s) {
	while (*s != 0) {
		sendCharacter(*s++);
	}
	/* for (i = 0; i < strlen(s); i++) 
		sendCharacter(s[i]); */
}