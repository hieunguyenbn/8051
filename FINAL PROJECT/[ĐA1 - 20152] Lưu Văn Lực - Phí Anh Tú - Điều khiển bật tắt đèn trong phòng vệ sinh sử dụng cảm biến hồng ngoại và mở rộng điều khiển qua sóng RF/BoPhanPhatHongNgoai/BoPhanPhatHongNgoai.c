/*BAT-TAT DEN TU DONG SU DUNG CAM BIEN HONG NGOAI VA DIEU KHIEN DEN TU XA QUA SONG RF
BO PHAN PHAT HONG NGOAI
Designed by: LUU Van Luc
Update:29/5/2016
*/
#include <REGX52.H>
// Toa xung 38kHz tai chan P1.0 o che do Clock-out cua Timer 2
void main()
{
	int nguoi=0;
	T2CON = 0x00;					
	T2MOD = 0x02;
	RCAP2H = 0xFF;
	RCAP2L = 0xB1;
	TH2 = 0xFF;
	TL2 = 0xB1;
	TR2 = 1;
	while(1)
	{}
}