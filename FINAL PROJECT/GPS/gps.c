#include <regx52.h>
#include <string.h>
#include "..\..\LIBRARY\delay.h"
#include "..\..\LIBRARY\port.h"

void LCD_init(); //khoi tao
void WriteCommand(unsigned char cmd); // Gui lenh cho LCD
void WriteChar(char c); // Gui ky tu
void WriteString(char *s); //GUI CHUOI
void receive(void);

char GLL[6] = "$GPGLL", latitude[15], longtitude[15], chuoi[35];
unsigned char j, k, h, dauphay = 0;
volatile char i;

main() {
		TMOD = 0x20; // Timer 1 mode 2
		TH1 = 0xFD; // 9600 
		SCON = 0x50; // Che do 1, cho phep nhan
		IE=0x90; // Cho phep ngat truyen thong noi tiep
		PS = 1; // Uu tien ngat noi tiep
		TR1 = 1;
		LCD_init();
		WriteString("LOADING...");
		while(1) {
			 	if (i==34) {
				//if(chuoi[i] == '\n') {	
				EA = 0; 
					for (j = 0; j < 34; j++) {
						if (chuoi[j] == ',') dauphay++;
						switch (dauphay) {
							case 1:
								latitude[k++] = chuoi[j+1];
								break;
							case 2:
								latitude[k] = chuoi[j];
								break;
							case 3:
								longtitude[h++] = chuoi[j+1];
								break;
							case 4:
								longtitude[h] = chuoi[j];
								break;
							default:
								break;
						}
					}	
					WriteCommand(0x01);
					WriteCommand(0x80);//vi tri dau hang 1 LCD
				  WriteString("V: ");//WriteString(latitude)
					for (k = 0; k <= 1; k++) WriteChar(latitude[k]);
					WriteChar(0xDF); WriteChar(' '); //degree
					for (k = 2; k <= 6; k++) WriteChar(latitude[k]);
					WriteString("' ");//minute
					k = strlen(latitude)-1; WriteChar(latitude[k]); // direction
					WriteCommand(0xC0); // vi tri dau hang 2 LCD
					WriteString("K: ");//WriteString(longtitude);
					for (h = 0; h <= 2; h++) WriteChar(longtitude[h]);
					WriteChar(0xDF); WriteChar(' '); //degree
					for (h = 3; h <= 7; h++) WriteChar(longtitude[h]);
					WriteString("' "); //minute
					h = strlen(longtitude)-1; WriteChar(longtitude[h]); //direction
					i = 0;//
					delay_ms(500);
			  }
				else
					EA = 1; 
		}
}
void receive(void) interrupt 4 {	
		chuoi[i++] = SBUF;
		if ((i < 6)&&(chuoi[i-1]!=GLL[i-1])) i = 0;
		RI = 0;
}
void WriteCommand(unsigned char cmd) {
		P2 = (cmd & 0xF0); // gui 4 bit cao truoc
		RS = 0; // Gui/nhan lenh
		RW = 0; // Gui
		EN = 1; delay(20); EN = 0;
		delay(150);
		P2 = ((cmd << 4) & 0xF0); // gui 4 bit thap
		RS = 0; RW = 0;
		EN = 1; delay(20); EN = 0;
		delay(150);
}

void LCD_init() {
		P2 = 0x00;
		delay_ms(1);
		WriteCommand(0x03);
		WriteCommand(0x02);        // Initialize Lcd in 4-bit mode
    WriteCommand(0x28);        
    WriteCommand(0x01);        // Clear 
		WriteCommand(0x0C);
}
		
void WriteChar(char c) {
		P2 = (c & 0xF0);
		RS = 1; // Gui/nhan du lieu
		RW = 0; // Gui
		EN = 1; delay(10); EN = 0;
		delay(100);
		P2 = ((c << 4) & 0xF0);
		RS = 1; RW = 0;
		EN = 1; delay(10); EN = 0;
		delay(100);
}
void WriteString(char *s) {
		while (*s) {
				WriteChar(*s++);
		}
}