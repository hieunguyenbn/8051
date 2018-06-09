// Yeu cau: Khai bao ket noi voi ADC0808 trong file Port.h
//#define ADC0808_DATA P3
//sbit ADC0808_ADDA = P2^0;
//sbit ADC0808_ADDB = P2^1;
//sbit ADC0808_ADDC = P2^2;
//sbit ADC0808_ALE  = P2^3;
//sbit ADC0808_START = P2^4;
//sbit ADC0808_EOC  = P2^5;
//sbit ADC0808_OE   = P2^6;

#ifndef _ADC0808_H_
#define _ADC0808_H_

void ADC0808_Init();
unsigned char ADC0808_Read(unsigned char channel);

#endif