/***************************************
code dieu khien thiet bi dien trong gd = bluetooth 
youtube.com/gocdiy
Nguoi viet : Dao Van Nguyen
SDT lien he : 0169 473 3311
****************************************/

#include <REGX52.H>
 unsigned char c;
 #define sw1 P2_0
 #define sw2 P2_1
 #define sw3 P2_2
 #define sw4 P2_3

 #define tb1 P1_4
 #define tb2 P1_5
 #define tb3 P1_6
 #define tb4 P1_7

//ham delay
void delay_ms(int time)
{
 unsigned int i,j;
 for(i=0;i<time;i++)
 {
   for(j=0;j<123;j++);
 }
}
void batdau()
{
  TMOD=0x20;
  SCON=0x50;
  TH1=0xfd;
  TR1=1;
  TI=1;
  RI=0;
  EA=ES=1;
}

void UART_ngat() interrupt 4
{
  if(RI==1)
  {
   	  c=SBUF;	  // lay gia tri trong thanh ghi SBUF
	  RI=0;		  // xoa co RI
	       if(c=='A')
      {
        tb1=0;
      }
      else if(c=='a')
      {
        tb1=1;
      }
	  else if(c=='B')
      {
        tb2=0;
      }
	  else if(c=='b')
      {
      	tb2=1;
      }
	  else if(c=='C')
      {         
	   tb3=0;
      }
	  else if(c=='c')
      {         
	   tb3=1;
      }
	  else if(c=='D')
      {
	   tb4=0;         
	  }
	  else if(c=='d')
      {
	   tb4=1;         
	  }
	  c=0;

  }
} 

void main()
{
  batdau();
  delay_ms(100);
  while(1)
  {
	 if(sw1==0)
	 {
	  delay_ms(20);while(sw1==0);
	  tb1=!tb1;
	 }
	 if(sw2==0)
	 {
	  delay_ms(20);while(sw1==0);
	  tb2=!tb2;
	 }
	 if(sw3==0)
	 {
	  delay_ms(20);while(sw1==0);
	  tb3=!tb3;
	 }
	 if(sw4==0)
	 {
	  delay_ms(20);while(sw1==0);
	  tb4=!tb4;
	 }
  }
}
