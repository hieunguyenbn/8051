// Yeu cau: Khai bao ket noi voi ADC0808 trong file Port.h
//#define ADC0808_DATA P3
//sbit ADC0808_ADDA = P2^0;
//sbit ADC0808_ADDB = P2^1;
//sbit ADC0808_ADDC = P2^2;
//sbit ADC0808_ALE  = P2^3;
//sbit ADC0808_START = P2^4;
//sbit ADC0808_EOC  = P2^5;
//sbit ADC0808_OE   = P2^6;

#include "main.h"
#include "port.h"

void ADC0808_Init()
{
 	ADC0808_START = 0;
	ADC0808_ALE = 0;
	ADC0808_OE = 0;	
}

unsigned char ADC0808_Read(unsigned char channel)
{
	unsigned char kq;

 	ADC0808_ADDA = channel & 0x01;
	ADC0808_ADDB = channel & 0x02;
	ADC0808_ADDC = channel & 0x04;

	ADC0808_ALE = 1;
	ADC0808_START = 1;
	ADC0808_ALE = 0;
	ADC0808_START = 0;

	while(ADC0808_EOC);
	while(!ADC0808_EOC);

	ADC0808_OE = 1;
	kq = ADC0808_DATA;
	ADC0808_OE = 0;

	return kq;
}