//Receive a character
#include <reg52.h>
unsigned char c, a[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
main()                                               
{
       TMOD=0x20;                   
       TH1=0xFD;           
       SCON=0x50;                              
       TR1=1;                
       while(1) {
            while(RI==1) {                       
                 c=SBUF;        
                 RI=0;           
            }                     
            switch(c) {           
			case '0':
				P1 = a[0];
				break;
               case '1':
                    P1 = a[1];
                    break;
               case '2':
                    P1 = a[2];
                    break;
               case '3':
                    P1 = a[3];
                    break;
               case '4':
			     P1 = a[4];
                    break;
               case '5':
				P1 = a[5];
                    break;
               case '6':
                    P1 = a[6];
                    break;
               case '7':
                    P1 = a[7];
                    break;
               case '8':
                    P1 = a[8];
                    break;
			case '9':
                    P1 = a[9];
                    break;
               default:                     
                    P1 = 0xFF;
                    break;
               }
       }
}