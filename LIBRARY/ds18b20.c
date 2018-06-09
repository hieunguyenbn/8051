#include "ds18b20.h"
#include "delay.h"

unsigned char DS18B20_Reset(void) {
		unsigned char presence;
		DQ = 1;
		DQ = 0; // keo xuong
		delay_us(29); // delay (480-24)/16=28.5 do thoi gian goi ham 24us, ham nay tre trong 16us
		DQ = 1; // keo len
		delay_us(3); // delay (70-24)/16 = 2.875 // cho tin hieu presence
		presence = DQ;
		delay(25); // delay (410-24)/16 = 24.125; // ket thuc timeslot
		return presence; // Neu presence = 0 thi OK chip slave tra loi, =1 thi NOT OK;
}
void DS18B20_WriteBit(char c) {
		DQ = 0; // keo xuong muc 0 de khoi dong timeslot
		if (c == 1) DQ = 1; // Neu write 1
		delay_us(5); // delay 104 us luu gia tri cua timeslot
		DQ = 1;
}
void DS18B20_WriteByte(char c) {
		unsigned char i;
		unsigned char temp;
		for (i = 0; i < 8; i++) {
				temp = c >> i; // lan luot viet tung bit
				temp &= 0x01; // luu bit thap nhat vao bien temp
				DS18B20_WriteBit(temp); // viet bit do len bus
		}
		delay_us(5);
}
unsigned char DS18B20_ReadBit(void) {
		unsigned char i;
		DQ = 0;
		DQ = 1;
		for (i = 0; i < 3; i++); // delay 15us
		return (DQ);
}
unsigned char DS18B20_ReadByte(void) {
		unsigned char i;
		unsigned char value = 0;
		for (i = 0; i < 8; i++) {
				if (DS18B20_ReadBit()) value |= 0x01 << i; // dich trai doc lan luot tung bit
				delay_us(6);
		}
		return value;
}
void ReadTemperature(void) {
		unsigned char a = 0;
		unsigned char b = 0;
		EA = 0;
		if (!DS18B20_Reset()) {
				DS18B20_WriteByte(0xCC);// Skip rom
				DS18B20_WriteByte(0x44); // Lenh Convert T
				delay(10);
		}
		if (!DS18B20_Reset()) {
				DS18B20_WriteByte(0xCC);// Skip rom
				DS18B20_WriteByte(0xBE); // Lenh doc nhiet do
				delay(10);
		}
		a = DS18B20_ReadByte(); // doc nhiet do byte thap
		b = DS18B20_ReadByte(); // doc nhiet do byte cao
		nhietdo = (b*256+a)>>4; // luu gia tri nhiet do vao bien temp
}