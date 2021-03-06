/*
BAT-TAT DEN TU DONG SU DUNG CAM BIEN HONG NGOAI VA DIEU KHIEN DEN TU XA QUA SONG RF
Designed by: LUU Van Luc
Update:29/5/2016
*/

#include <REGX52.H>
//sbit PIN1 = P1^0;
sbit LED1 = P1^0;
sbit LED2 = P0^0;
sbit DEN  = P2^6; 					//DEN=0: Den BAT
														//DEN=1: Den TAT
sbit LED_MODE=P2^0;					//LED_MODE 	=1 	: Auto
														//					=0	: ByHand
int nguoi=0;

/*
Dinh nghia cac chan cua module RF315:
Chu y: Cac chan = 0 khi o trang thai cho
								= 1 khi co nut duoc bam tuong ung
*/
sbit D0_AutoPin = P3^2;					// Phim A: Set he thong lam viec o che do Auto
sbit D1_HandPin = P3^3;					// Phim B: Set he thong lam viec o che do dieu khien qua song RF
sbit D2_OnPin		= P3^4;					// Phim C: BAT den qua song RF
sbit D3_OffPin 	= P3^5;					// Phim D: TAT den qua song RF


bit AutoFlag = 1;				// AutoFlag = 1	: Che do Bat-Tat den tu dong
												// AutoFlag = 0	: Che do Bat-Tat den qua RF
bit DirectFlag = 0;   	// DirectFlag = 0 : Dang o Led 1, nguoi co xu huong di vao
												// 						= 1 : Dang o Led 2, nguoi co xu huong di ra

void delay_ms(unsigned int t)
{
	unsigned int x,y;
	for (x=0;x<t;x++)
		for (y=0;y<123;y++);
} 
//----------------------------------------------------
/*
HAM kiemtra:
1. Input: So nguoi, o dang con tro
2. Chuc nang: Ra quyet dinh bat-tat den neu nguoi>0
*/
void kiemtra( int *nguoi)
{
	if(*nguoi>0) DEN=0;
	else 
		{
			DEN = 1;
			*nguoi=0;
		}
}
//----------------------------------------------------
/*
HAM Check va Check1:
1. Input: tin hieu nhan vao 
2. Output: 	
-return1: tin hieu dieu khien
-return0: nhieu
3. Chuc nang: Kiem tra tin hieu ngoai vao la nhieu hay tin hieu dieu khien (Chong nhieu bang phan mem)
*/
bit Check(bit Signal)	// Check bit 0	
{
	if(Signal==0) 
	{
		delay_ms(50);
		if(Signal==0) return 1;
		else return 0;
	}
	else return 0;
}
bit Check1(bit Signal)// Check bit 1
{
	if(Signal==1) 
	{
		delay_ms(50);
		if(Signal==1) return 1;
		else return 0;
	}
	else return 0;
}
//------------------------------------------------------
/*
HAM OnOffLed:
1. Input: Bit huong nguoi va so nguoi
2. Chuc nang: 
- Khi chac chan co nguoi di qua, ham duoc goi ra de them-bot so nguoi va ra quyet dinh bat-tat den
- Ngoai ra, ham con doi 500ms de ra quyet dinh bat-tat den, neu trong 500ms day, kiem tra nguoi co 
doi huong ko de ra quyet dinh
*/
void OnOffLed(bit DirectFlag, int *nguoi)
	{
		int i,k=0;
		if(DirectFlag==0)
		{
		while(1)
		{
			for(i=0;i<50;i++)
			{
				delay_ms(10);
				if(Check1(LED1))
				{
					while(LED1);
					delay_ms(50);
					break;
				}
			}
			if(i==50) break;
			if(i!=50) k++;
			for(i=0;i<50;i++)
			{
				delay_ms(10);
				if(Check1(LED2))
				{
					while(LED2);
					delay_ms(50);
					break;
				}
			}
			if(i==50) break;
			if(i!=50) k++;
			
//			if(i==50)
//			{
//				(*nguoi)++;
//			//	P2=*nguoi;
//				kiemtra(nguoi);
//			}
		}
		if((k%2)==0)
			{
				(*nguoi)++;
				//	P2=*nguoi;
				kiemtra(nguoi);
			}
		}
		else
		{
		while(1)
		{
			for(i=0;i<50;i++)
			{
				delay_ms(10);
				if(Check1(LED2))
				{
					while(LED2);
					delay_ms(50);
					break;
				}
			}
			if(i==50) break;
			if(i!=50) k++;
			for(i=0;i<50;i++)
			{
				delay_ms(10);
				if(Check1(LED1))
				{
					while(LED1);
					delay_ms(50);
					break;
				}
			}
			if(i==50) break;
			if(i!=50) k++;
//			{
//				if(*nguoi!=0)
//						{
//							(*nguoi)--;
//						}
//			//	P2=*nguoi;
//				kiemtra(nguoi);
//			}
		}
		if((k%2)==0)
			{
				if(*nguoi!=0)
						{
							(*nguoi)--;
						}
			//	P2=*nguoi;
				kiemtra(nguoi);
			}			
		}
	}
//-------------------------------------------------------
/*
	HAM DelayAndCheck:
	1. Input: Bit huong nguoi
	2. Output: 
	- return1: Chac chan co nguoi di qua
	- return0: Tin hieu gia, huy tin hieu
	3. Chuc nang:	Kiem tra tinh chac chan nguoi di qua, neu tin hieu la gia thi huy tin hieu
*/	
	int DelayAndCheck(bit DirectFlag)		
	{
		int i;
		for(i=0;i<50;i++)
		{
			delay_ms(50);
			if(DirectFlag==0)
				{
					if(Check1(LED2))
						{
								while(LED2); 
								delay_ms(50);
								break;
						}
				}
			else
				{
					if(Check1(LED1)) 
							{
								while(LED1); 
								delay_ms(50);
								break;
							}
				}
		}
		if(i!=50) return 1;
		else return 0;
	}
//---------------------------------------------------------
/*
	HAM kiemtraVao:
	1. Input: tham so nguoi
	2. Chuc nang: kiem tra co nguoi VAO hay ko, neu co thi tang nguoi va bat den
*/
	void kiemtraVao(int *nguoi)
	{
		if(Check1(LED1))
			{
				DirectFlag=0;
				while(LED1);
				if(DelayAndCheck(DirectFlag)==1)		//Chac chan co nguoi qua
					{
						OnOffLed(DirectFlag,nguoi);
					}
			}
	}
//---------------------------------------------------------
/*
	HAM kiemtraRa:
	1. Input: tham so nguoi
	2. Chuc nang: kiem tra co nguoi RA hay ko, neu co thi giam nguoi va bat-tat den
*/	
	void kiemtraRa(int *nguoi)
		{
			if(Check1(LED2))
			{
				DirectFlag=1;
				while(LED2);
				if(DelayAndCheck(DirectFlag)==1)		//Chac chan co nguoi qua
					{
						OnOffLed(DirectFlag, nguoi);
					}
			}
		}
//-----------------------------------------------------------
//-----------------------------------------------------------
/*
		NGAT NGOAI 0:
		Set che do AUTO:
		Mac dinh: 
		- Reset so nguoi=0
		- Den TAT
*/
void EX0_ISR() interrupt 0
{
	delay_ms(20);
	if(Check(D0_AutoPin))
	{
		AutoFlag=1;
		nguoi=0;
		DEN=1;
	//	P2=nguoi;
		LED_MODE=1;
		while(!D0_AutoPin);
		delay_ms(20);
	};
}
//-----------------------------------------------------------
/*
		NGAT NGOAI 1:
		Set che do HAND:
		Mac dinh: 
		- Dat so nguoi=-1 (sau nay dung truyen tin noi tiep de phan biet duoc dang o che do HAND)
*/
void EX1_ISR() interrupt 2
{
	delay_ms(20);
	if(Check(D1_HandPin))
	{
		AutoFlag=0;
		nguoi=-1;
	//	P2=nguoi;
		LED_MODE=0;
		while(!D1_HandPin);
		delay_ms(20);
	};
}
//-----------------------------------------------------------
	void main()
{
	//int nguoi=0;
//	P2=0;
	D0_AutoPin=1;
	D1_HandPin=1;
	D2_OnPin	=1;
	D3_OffPin	=1;
	// Khoi tao ngat EX1:
	IT1=1;								// Ngat suon xuong
	EX1=1;								// Cho phep ngat INT1

	//Khoi tao Ngat EX0
	IT0=1;
	EX0=1;
	EA=1;									// Cho phep ngat hoat dong
	
	
	
	LED_MODE=1;
	LED1 = 1;
	LED2 = 1;
	delay_ms(1000);
	DEN=1;
	delay_ms(1000);
//	nguoi = 0;
	while(1)
	{
		if(AutoFlag==1)
		{
			kiemtraVao(&nguoi);
			kiemtraRa(&nguoi);
		}
		else
		{
		//	nguoi=-1;
		//	P2=nguoi;
			if(Check1(D2_OnPin))
			{
				DEN=0;
				while(D2_OnPin);
			}
			if(Check1(D3_OffPin))
			{
				DEN=1;
				while(D3_OffPin);
			}
		}
	}
}