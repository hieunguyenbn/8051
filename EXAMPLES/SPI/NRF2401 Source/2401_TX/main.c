#include <string.h>
#include <reg52.h>
#include <intrins.h>

#define 	INT8U		unsigned char 
#define 	INT16U		unsigned int

#define		FOSC		11059200	
#define		BAUD		9600
#define		TIMER1		0XFD	//256-(110592/(12*32*96))
#define		TIMER0H		(65535-3*FOSC/12/1000)/256
#define		TIMER0L		(65535-3*FOSC/12/1000)%256			//Timing 3MSVR
//----------------------------------------------------------------------------------------------------------
//Internal register definition
//----------------------------------------------------------------------------------------------------------
sfr	P4		=	0xc0;	
sfr 	ADC_CONTR 	= 	0xC5;
sfr 	AUXR 		= 	0x8E;
sfr 	ADC_DATA 	= 	0xC6;
sfr 	P1_ADC_EN 	= 	0x97;
//定义I/O口
sbit	POW_UP	=	P3^5;
sbit	CE	=	P3^4;
sbit	DR2	=	P3^3;
sbit	SCK2	=	P3^2;
sbit	MOSI	=	P4^3;
sbit	MISO	=	P1^7;
sbit	SCK	=	P1^6;
sbit	DOUT2	=	P1^5;
sbit	CS	=	P1^4;
sbit	DR1	=	P4^2;
sbit	LED1	=	P4^1;
sbit	LED2	=	P4^0;





/********************* I/O define end*****************************************************/


#define   	FRESELE		0x28		//Channel selection
#define 	DATANUM		4		//Valid data bits

#define time0h (65535-3000)/256
#define time0l (65535-3000)%256			//3MS time




code INT8U CofigBuf[15]=
		{
		0x00,				//Receive Channel 2 valid data length
		
		40,				//Receive channel a valid data length
		
		0x00,0x00,0x00,0x00,0x00,	//Receive Channel 2 address
		
		0x00,0xcd,0xef,0x12,0xaa,	//Receive Channel 1 address
		
		0x83,				//32-bit address, 16-bit CRC, CRC enabled
						//bit7~2:ADDR_W,Maximum 40
						
						//bit1:CRC_L
						//Logic 0: 8 bit CRC    
						//Logic 1: 16 bit CRC
						
						
						//BIT0:CRC_EN
						//Logic 0: On-chip CRC generation/checking disabled
						//Logic 1: On-chip CRC generation/checking enabled
						
						
		0x4f,				//ShockBurst mode, 250 kbps, 16M crystal, 0dBm maximum power
		
						//Bit 15:RX2_EN
						//Logic 0: One channel receive
						//Logic 1: Two channels receive
						
						//Bit 14:
						//Communication Mode:
						//Logic 0: nRF2401 operates in direct mode.
						//Logic 1: nRF2401 operates in ShockBurst. mode

						//Bit 13:
						//RF Data Rate:
						//Logic 0: 250 kbps
						//Logic 1: 1 Mbps
						
						//Bit 12-10:Selects the nRF2401 crystal frequency to be used:
						//	D12 	D11 	D10 	Crystal Frequency [MHz]
						//	0   	0 	0 		4
						//	0 	0 	1 		8
						//	0 	1 	0 		12
						//	0 	1 	1 		16
						//	1 	0 	0 		20
						
						//Bit 9-8:RF_PWR: Sets nRF2401 RF output power in transmit mode:
						//	D9 	D8 	P [dBm]
						//	0 	0 	-20
						//	0	1 	-10
						//	1 	0 	-5
						//	1 	1 	0
						
						
						
		0x50			//2400+4*1=2404MHZ=2.404G,Send Mode
		
						//Bit 7 – 1:RF_CH#: Sets the frequency channel the nRF2401 operates on.
						//Channelrf = 2400MHZ + RF_CH# * 1.0MHZ
						
						//Bit 0:Set active mode:
						//Logic 0: transmit mode
						//Logic 1: receive mode
		};
		
		
INT8U AddrCofig[4]={0xcd, 0xef, 0x12, 0xaa};				//Address
INT8U TxBuf[8]={0x40, 0x22, 0x66, 0x88, 0x40, 0x00, 0x00, 0x00};	//Send Shou Chong District
INT8U RxBuf[8]={0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};	//Shou Chong district to receive							
INT16U timer[2];								//Time-out counter


		
/*****************************************************************************************
//Function name：void Delay100us(INT8U s)
//Input: Time
//Output: None
//Function Description: Mountain Time
/*****************************************************************************************/
void Delay100us(INT8U n)
{
	INT8U i;
	while(n--)
	{
		for(i=0; i<35; i++);
	}
}
/*****************************************************************************************
//Function name：delay(unsigned int s)
//Input: Time
//Output: None
//功能描述：普通廷时
/*****************************************************************************************/		
delay(unsigned int s)
{
	unsigned int i;
	for(i=0; i<s; i++);
	for(i=0; i<s; i++);
}
/*****************************************************************************************
//Function nameoid CpuInit(void)
//Input: None
//Output: None
//Functional Description: SPI initialization procedure
/*****************************************************************************************/
void CpuInit(void)
{
	POW_UP = 1;
	Delay100us(40);
	CE = 0;
	CS = 0;
	SCK = 0;
}


/*****************************************************************************************
//Function name:UartInit()
//Input: None
//Output: None
//Function Description: Serial initialization procedure
/*****************************************************************************************/
void UartInit(void)
{
	SCON = 0x50;		//Serial Mode 1, allows to receive
	TMOD = 0x21;		//Timer 1 works 2, Timer 0 Mode 1
	TH1 = TIMER1;	
	TL1 = TIMER1;	
	TR1 = 1;		//Start Timer 1
}


/*****************************************************************************************
//Function name:void TimerInit(void)
//Input: None
//Output: None
//Features: Timer 0 Initialization procedure
/*****************************************************************************************/
void TimerInit(void)
{
	TH0 = TIMER0H;
	TL0 = TIMER0L;
	ET0 = 1;			//Timer 0 Interrupt Enable
	TF0 = 0;
	TR0 = 1;			//Start timer 0
	EA = 1;				//Open Global Interrupt
}



	

/*****************************************************************************************
//Function name：ResetTimer(INT8U n)
//Enter: To reset the timer
//Output: None
//Function Description: Reset the timer
/*****************************************************************************************/
void ResetTimer(INT8U n)
{
	ET0 = 0;                                    // Disable Timer0 interrupt
	timer[n & 0x01] = 0;                        // Clear timer[n]
	ET0 = 1;                                    // Enable Timer0 interrupt
}


/*****************************************************************************************
//Function name：INT16U ReadTimer(INT8U n)
//Input: to read the timer
//Output: the value of reading
//Function Description: Read timer
/*****************************************************************************************/
INT16U ReadTimer(INT8U n)
{
	INT16U tmp;
	ET0 = 0;                                    // Disable Timer0 interrupt
	tmp = timer[n];                             // Clear timer[n]
	ET0 = 1;                                    // Enable Timer0 interrupt
	return tmp;
}

/*****************************************************************************************
//Function name:SendCh(ch)
//Input: None
//Output: None
//Function Description: serial port sends a character
/*****************************************************************************************/
void SendCh(INT8U ch)
{
	SBUF = ch;
	while(!TI);
	TI = 0;
}


/*****************************************************************************************
//Function name：void SendStr(INT8U *arr)
//Enter: Send a string
//Output: None
//Function Description: Send a string
/*****************************************************************************************/
void SendStr(INT8U *arr)
{
	INT8U i;
	
	i = 0;
	while(arr[i] != '\0')
	{
		SendCh(arr[i]);
		i++;
	}
}

/*****************************************************************************************
//Function name：void SpiWriteByte(INT8U dat)
//Enter: Send the data
//Output: None
//Function Description: SPI to send a byte
/*****************************************************************************************/
void SpiWriteByte(INT8U dat)
{
	INT8U i;

	SCK = 0;
	_nop_();
	_nop_();
	for(i=0; i<8; i++)
	{
		if((dat & 0x80) == 0x80)
		{
			MOSI = 1;
			MISO = 1;
		}
		else 
		{
			MOSI = 0;
			MISO = 0;
		}
		SCK = 1; 
		_nop_();
		_nop_();
		dat <<= 1;
		SCK = 0;
		_nop_();
		_nop_();
	}
}


/*****************************************************************************************
//Function name：INT8U SpiReadByte(void)
//Input: None
//Output: read out data
//Function Description: SPI read a byte
/*****************************************************************************************/
INT8U SpiReadByte(void)
{
	INT8U i,temp;
	temp = 0;
	MOSI = 1;
	MISO = 1;	

	SCK = 0;
	_nop_();
	_nop_();
	for(i=0; i<8; i++)
	{
		temp <<= 1;
		SCK = 1;
		_nop_();
		_nop_();
		if(MISO)temp++; 
		SCK = 0;
		_nop_();
		_nop_();
	}
	return temp;
}


/*****************************************************************************************
//Function name：SetTxMode()
//Input: None
//Output: None
//Function Description: to send mode
/*****************************************************************************************/
void SetTxMode(void)
{
    	unsigned char ch;
    	CS = 1;
    	Delay100us(0);
    	ch = FRESELE<<1;
    	SpiWriteByte(ch);
    	CS = 0;
    	Delay100us(2);
}

/*****************************************************************************************
//Function name：SetRxMode()
//Input: None
//Output: None
//Function Description: to receive mode
/*****************************************************************************************/
void SetRxMode(void)
{
    	unsigned char ch;
    	CS = 1;
    	Delay100us(0);
    	ch = FRESELE<<1;
    	SpiWriteByte(ch | 0x01);
    	CS = 0;
    	Delay100us(2);				//200us
}



/*****************************************************************************************
//Function name：Nrf2401Init()
//Input: Address,Send data bits
//Output: None
//Function Description: Nrf2401Init initialization, where we configured 32-bit address.
/*****************************************************************************************/
void Nrf2401Init(void)
{
	INT8U i;

	CE = 0;
	CS = 1;
	
	Delay100us(0);
	for(i=0; i<15; i++)
	{
		SpiWriteByte(CofigBuf[i]);
	}
	CS = 0;
	
	Delay100us(30);

}


/*****************************************************************************************
//Function name：TranData()
//Input: None
//Output: None
//Features: Send to send the buffer data.
/*****************************************************************************************/
void TranData(void)

{
	INT8U i;
	
	SetTxMode();
	
	CE = 1;
	
	Delay100us(1);
	
	for(i=0; i<4; i++)
	{
		SpiWriteByte(AddrCofig[i]);	//Send address
	}
	for(i=0; i<5; i++)
	{
		SpiWriteByte(TxBuf[i]);		//Send 5
	}
	

	CE = 0;
	
	Delay100us(13);
}



/*****************************************************************************************
//Function name：void ReceiveBytes(void)
//Input: None
//Output: None
//Features: Receive data exist within the receive buffer
/*****************************************************************************************/
INT8U ReceivePacket(void)
{
	INT8U i;
	SetRxMode();
	CE = 1;    
	ResetTimer(1);
	while(DR1 == 0);
	{
		if (ReadTimer(1) > 200)
		{
			CE = 0;
			return 0;
		}
	}
	i = 0;
	while(DR1)
	{
		RxBuf[i] = SpiReadByte();
		i++;
		if (i == 4)
		break;
	}
	while(DR1)
	{
		SpiReadByte();
	}
	CE = 0;
	return 1;
}

/******************************************************************************************
*******************************************************************************************
************************************Interrupt service routine*******************************************
*******************************************************************************************
******************************************************************************************/
void Timer0ISR(void) interrupt 1
{
	EA = 0;
	TH0+=TIMER0H;
	TL0+=TIMER0L;
	timer[0]++;
	timer[1]++;
	EA = 1;
}



/******************************************************************************************
*******************************************************************************************
******************************************Main program*******************************************
*******************************************************************************************
******************************************************************************************/
main()
{
	CpuInit();
	UartInit();
	TimerInit();
	LED1=0;
	LED2=0;
	delay(20000);
	LED1=1;
	LED2=1;
	Nrf2401Init();
	delay(500);
	while(1)
	{
		TranData();			//Send the data buffer zones ribbon.
		LED2=0;
		delay(5000);
		LED2=1;
		delay(10000);
	}
}