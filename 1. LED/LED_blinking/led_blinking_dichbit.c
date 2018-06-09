#include <reg52.h>

void delay_ms(unsigned char time)
{
	unsigned char i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<123;j++);
	}
}

main()
{	
	unsigned char i;
	unsigned char b;
	
	while(1) {
		
		b = 0xFF;
		P0 = b;
		for (i = 0; i < 8; i++) {
			
			delay_ms(1000);
			P0 >>= 1 + 0x80;
			//P0 = b;
		//	delay_ms(2000);
	
		}
		/*P1 = 0xFE;
		for (i = 0; i < 8; i++) {
			
			delay_ms(1000);
			P1 >>= 1;
	
		}*/
		
	}
	
}