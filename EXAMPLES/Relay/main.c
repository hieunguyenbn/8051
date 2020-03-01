//Khoa hoc giao tiep 8051 voi Kit 8051 V2
//Huong dan lap trinh vi dieu khien AT89S52 giao tiep relay

#include <main.h>

//Nhan nut K1 dong relay
//Nhan nut K2 ngat relay

void main()
{
	relay = 0;
	while(1)
	{
		if(K1 == 0)
		{
			relay = 1;
		}
		if(K2 == 0)
		{
			relay = 0;
		}
	}
}