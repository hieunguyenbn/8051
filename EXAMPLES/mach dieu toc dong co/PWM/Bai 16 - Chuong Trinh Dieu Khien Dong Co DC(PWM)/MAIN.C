/*TEN CHUONG TRINH
COPYRIGHT BY XUAN KIEN*/
#include"MAIN.H"//chen thu vien chinh
__CONFIG(HS & WDTDIS & PWRTEN & UNPROTECT & BORDIS & LVPDIS);
/***************************************************************/
//khai bao bien toan cuc

/***************************************************************/
//khai bao cac ham chuong trinh con 
void _Delay(char time);//ham tao thoi gian tre
void _Init_LCD(void);//ham khoi dong lcd 
/***************************************************************/
/***************************************************************/
//chuong trinh chinh
void main(void)
{
	//khai bao bien cuc bo

	_Init_LCD();
	_SetUpPWM1();
	_SetUpPWM2();

	lcd_gotoxy(0,0);
	lcd_puts("INIT PWM");

	while(1)//tao vong lap vo han
	{
	/*
		muon tinh duty = 50%
		duty=PR2/2=100/2=50
		50=00110010
		chen them 2 bit ti le timer 2 chinh la 00
		thi ta duoc 00110010.00 =200

		muon tinh duty = 25%
		duty=PR2/4=25
		25=00011001
		chen them 2 bit ti le timer 2 chinh la 00
		thi ta duoc	
		00011001.00 = 100	
	*/

		_SetDutyPWM1(100);
		_SetDutyPWM2(200);
	}
}
/***************************************************************/
/***************************************************************/
void _Delay(char time)
{
	char i;
	for(i=0;i<time;i++)
	{
		__delay_ms(100);//tao tre 0.1s
	}
}

void _Init_LCD(void)
{
	lcd_init();//ham khoi tao lcd
	lcd_putc('\f');//ham xoa trang man hinh lcd
}