#ifndef	_RTC_DS1307_
#define _RTC_DS1307_

// Allow Ds1307 Run
void Ds1307_Init();

// Write a byte into address
void Ds1307_Write(unsigned char add, unsigned char dat);

// Read a byte at address
unsigned char Ds1307_Read(unsigned char add);

// Read a Hour, Minute, Second in Decimal format
// Read mode 12/24
// return AM/PM (0 - AM, 1 - PM) 
bit Ds1307_Read_Time(unsigned char * hour, unsigned char * minute, 
	unsigned char * second, unsigned char * mode);

// Write Hour, Minute, Second in Decimal format
// Write Mode 12/24
// Write AM/PM (0 - AM, 1 - PM) 
void Ds1307_Write_Time(unsigned char hour, unsigned minute, 
	unsigned char second, unsigned char mode, bit apm);

// Read day, date, month, year from Ds1307
void Ds1307_Read_Date(unsigned char * day, unsigned char * date, 
	unsigned char * month, unsigned char * year);

// Write day, date, month, year into Ds1307
void Ds1307_Write_Date(unsigned char day, unsigned char date, 
	unsigned char month, unsigned char year);

// Write array of byte begin at address
void Ds1307_Write_Bytes(unsigned char add, unsigned char * buff,
	unsigned char len);

// Read array of byte into buff at add
void Ds1307_Read_Bytes(unsigned char add,unsigned char * buff,
	unsigned char len);

#endif
/*------------------------------------------------------------------*-
	--- Ket thuc file ---------------------
-*------------------------------------------------------------------*/
