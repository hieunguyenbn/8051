#include <at89x52.h>
#include <font.c>

#define Hang P0
#define Cot  P1

//unsigned char code chuA[16]={0xFF,0x83,0xF5,0xF6,0xF5,0x83,0xFF,0xFF,
							 //0xFF,0x80,0xFD,0xF3,0xFD,0x80,0xFF,0xFF};
unsigned char code chuA[5]={"Hello"};

unsigned char code string[] = {"Day la chuong trinh Led Ma tran"};
unsigned char buffer[27];
char uart_data;

void serial_IT() interrupt 4
{
	if (RI) 
	{				               /* Khi nhan duoc du lieu */
	  RI = 0; 			           /* Xoa co RI (RI de xac dinh du lieu da duoc truyen tu PC xuong?) */
	  uart_data = SBUF;			// Nhan du lieu do PC truyen xuong
	}
}

void send(char temp) 
{ // Ham truen du lieu len may tinh
	SBUF = temp;
	while (TI==0);  //Co bao du lieu da truyen
		TI = 0;
}
void delay(){
	TH0=0xFB;
	TL0=0x00;
	TR0=1;
	while(1){
	if(TF0==1) break;
	}
	TR0=0;
	TF0=0;
}

void delay_ms(int t){
	int i;
	for(i=0;i<t;i++)
	delay();
}

void Display(unsigned char time) {
unsigned char i,j;

for(i=0;i<time;i++)
 for(j=0;j<25;j++)
  {
  if (j<8) 	Cot = j;
  else Cot = 0xFF;
	Hang = buffer[j];
	delay();
	Hang = 0xff;
  }

}

void putstr(char *s)
{
while (*s)
 {
  send(*s);
  s++;
 }

}
void main() 
{
unsigned char index;
unsigned char i,j,k;
// Khoi tao cho ngat RS232 nhan byte  ( Scon- Thanh ghi dieu khien bo UART)
	SCON = 0x50;	  /* UART che do 1 (8 bit), REN=1 */
	TMOD = 0x21;	  /* Timer 1 in mode 2, Timer 0 in mode 1 */
	TH1  = 0xFD;      /* 9600 Bds at 11.059MHz */
	TL1  = 0xFD;	  /* 9600 Bds at 11.059MHz */
	TR1 = 1; 	      /* Chay Timer1 */
	IE  = 0x90; 	  /* Cho phep ngat toan cuc va ngat UART de xu ly du lieu den*/
	TI = 0;RI = 0;
// Send String to PC
putstr(string);
	send(13);
	send(10);

for(k=0;k<26;k++)
		buffer[k] = 0xFF;

// Copy to Buffer RAM
for(i=0;i<5;++i)
{
 index = chuA[i]-32;
 for(j=0;j<5;j++)
 {
	for(k=25;k>0;--k)
		buffer[k] = buffer[k-1];
 	 	buffer[0] = font[index*5 + j];
 }
 	for(k=25;k>0;--k)
		buffer[k] = buffer[k-1];
	buffer[0] = 0xFF; 
}


while(1)
{
Display(30);
// Thuc hien dich chu
for(i=25;i>0;--i)
 {
	buffer[i] = buffer[i-1];
 }
 buffer[0] = buffer[25];
}
}