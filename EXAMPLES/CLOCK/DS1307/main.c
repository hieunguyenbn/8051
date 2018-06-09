#include "main.h"
#include "Soft_I2c.h"
#include "lcd.h"
#include "DS1307.h"
#include "port.h"

sbit K1 = P3^2;
sbit K2 = P3^3;
sbit K3 = P3^4;
sbit K4 = P3^7;
sbit BZ = P3^6;
unsigned char * code Days[] = {"SUN","MON","TUE","WED","THU","FRI","SAT"};
unsigned char Hour, Minute, Second, Mode, Day, Date, Month, Year, old_second;
unsigned char AlarmHour,AlarmMinute;
void SetAlarm()
{
	AlarmHour = Hour;
	AlarmMinute = Minute;
	while(!K1);
	while(1)
	{
		//Ds1307_Read_Time(&Hour, &Minute, &Second, &Mode);
		
		LCD_char_pos(1,5,AlarmHour/10+0x30);
		LCD_char(AlarmHour%10+0x30);
		LCD_str(":");
		LCD_char(AlarmMinute/10+0x30);
		LCD_char(AlarmMinute%10+0x30);
		LCD_str(":");
		LCD_char(Second/10+0x30);
		LCD_char(Second%10+0x30);

		//Ds1307_Read_Date(&Day, &Date, &Month, &Year);
		
		LCD_str_pos(2,2,Days[Day-1]);
		LCD_str(" ");
		LCD_char(Date/10+0x30);
		LCD_char(Date%10+0x30);
		LCD_str("/");
		LCD_char(Month/10+0x30);
		LCD_char(Month%10+0x30);
		LCD_str("/20");
		LCD_char(Year/10+0x30);
		LCD_char(Year%10+0x30);
		
		if(K2 == 0)
		{
			while(!K2);
			AlarmHour++;
			if(AlarmHour == 13) 
			{
				AlarmHour = 1;
			}
		}
		if(K3 == 0)
		{
			while(!K3);
			AlarmMinute++;
			if(AlarmMinute == 60)
			{
				AlarmMinute = 0;
			}				
		}
		if(K4 == 0) break;
	}
}

void Alarm()
{
	if(Hour == AlarmHour)
	{
		if(Minute == AlarmMinute)
		{
			BZ = 1;
		}
		else
		{
			BZ = 0;
		}
	}
	else
	{
		BZ = 0;
	}
}

void main()
{
	Soft_I2c_Init();
	Ds1307_Init();
	LCD_init();
	
	Ds1307_Write_Time(11,59,50,12,1);
	Ds1307_Write_Date(7,31,12,16);

	while(1)
	{
		Ds1307_Read_Time(&Hour, &Minute, &Second, &Mode);
		if(K1 == 0) SetAlarm();
		Alarm();
		if(old_second != Second)
		{ 
			old_second = Second;

			LCD_char_pos(1,5,Hour/10+0x30);
			LCD_char(Hour%10+0x30);
			LCD_str(":");
			LCD_char(Minute/10+0x30);
			LCD_char(Minute%10+0x30);
			LCD_str(":");
			LCD_char(Second/10+0x30);
			LCD_char(Second%10+0x30);

			Ds1307_Read_Date(&Day, &Date, &Month, &Year);
			LCD_str_pos(2,2,Days[Day-1]);
			LCD_str(" ");
			LCD_char(Date/10+0x30);
			LCD_char(Date%10+0x30);
			LCD_str("/");
			LCD_char(Month/10+0x30);
			LCD_char(Month%10+0x30);
			LCD_str("/20");
			LCD_char(Year/10+0x30);
			LCD_char(Year%10+0x30);
			
		}
	}
}