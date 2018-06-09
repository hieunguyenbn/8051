#ifndef _DS18B20_H_
#define _DS18B20_H_

void DS18B20_Write0(void);
void DS18B20_Write1(void);
void DS18B20_WriteBit(char c);
void DS18B20_WriteByte(char c);
unsigned char DS18B20_ReadBit(void);
unsigned char DS18B20_ReadByte(void); 
unsigned char DS18B20_Reset(void);
void ReadTemperature(void);

#endif