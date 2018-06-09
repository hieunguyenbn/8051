#include "main.h"
#include "UARTmode1.h"
#include "stdio.h"

/*****************************************************************************
#include "stdio.h"

putchar() <=> UART_Write()
getkey() //Wait 1 symbol sent to UART Gate and read it ( similar UART_Read() )
printf() <=> UART_Write_Text()
*****************************************************************************/

void main()
{
	UART_Init();
	UART_Write_Text("Hello World!!!");			//In ra man hinh dong chu Hello World
	
	while(1)
	{
		printf("Nhap vao lan 1\n");						//In ra man hinh
		P1 = getkey();												//Doc ky tu nhap vao va truyen ma ASCII toi port 1
		printf("Nhap vao lan 2\n");						//In ra man hinh
		P1 = UART_Read();											//Doc ky tu nhap vao va truyen ma ASCII toi port 1
	}
}