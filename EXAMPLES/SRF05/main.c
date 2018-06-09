#include "main.h"
extern uint8_t range_ok;
extern float range;
unsigned char str[16];

void main(void)
{
	SRF05_Init();
	lcd1602_init ();
	lcd1602_gotoxy(1,0);
	lcd1602_puts("MINH HA GROUP");
	lcd1602_gotoxy(0,1);
	lcd1602_puts("banlinhkien.vn");
	delay_ms(2000);
	lcd1602_clear();
	lcd1602_gotoxy(1,0);
	lcd1602_puts("DO KHOANG CACH");
	lcd1602_gotoxy(14,1);
	lcd1602_puts("Cm");
	while(1)
	{
		StartRange();
		if(range_ok)
		{
			sprintf(str, "K/Cach: %.1f ", range);
			lcd1602_gotoxy(0,1);
			lcd1602_puts(str);
			delay_ms(800);
		}
	}
}