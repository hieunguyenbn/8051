/*
   UART_C_file.c
   http://www.electronicwings.com
 */

#include<USART_Interrupt.h>

void Ext_int_Init()				
{
	EA  = 1;							/* Enable global interrupt */
	ES = 1;      					/* Enable Ext. interrupt0 */			
}

void UART_Init()
{
	TMOD = 0x20;					/* Timer 1, 8-bit auto reload mode */
	TH1 = 0xFD;						/* Load value for 9600 baud rate */
	SCON = 0x50;					/* Mode 1, reception enable */
	TR1 = 1;							/* Start timer 1 */
}