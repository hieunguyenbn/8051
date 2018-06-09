#ifndef _UARTmode1_H_
#define _UARTmode1_H_

//Ham khoi tao UART mode 1
void UART_Init();

//Ham ghi 1 ky tu
void UART_Write(unsigned char c);

//Ham ghi 1 chuoi text
void UART_Write_Text(unsigned char *str);

//Ham doc 1 ky tu
char UART_Read();

#endif