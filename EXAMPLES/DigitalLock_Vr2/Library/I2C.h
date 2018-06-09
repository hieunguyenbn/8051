#ifndef _I2C_H_
#define _I2C_H_

#define I2c_DELAY 4

sbit SCL = P2^0;
sbit SDA = P2^1;

void I2c_Delay(unsigned int time)
{
	while(time)
		time--;
}
/*
	Ham khoi tao I2c
*/
void I2c_Init()
{
	SCL = 1;
	I2c_Delay(I2c_DELAY);
	SDA = 1;
	I2c_Delay(I2c_DELAY);
}
void I2c_Start()
{
	SDA = 1; 
	SCL = 1; 
	I2c_Delay(I2c_DELAY);
	SDA = 0; 
	I2c_Delay(I2c_DELAY);
	SCL = 0;
	I2c_Delay(I2c_DELAY);
}
void I2c_Stop()
{	
	SDA = 0;
	SCL = 1;
	I2c_Delay(I2c_DELAY);
	SDA = 1;
	I2c_Delay(I2c_DELAY);
	SCL = 0;
	I2c_Delay(I2c_DELAY);
}
unsigned char I2c_CheckAck(void)
{
	unsigned char ack = 0;
	SDA = 1;
	SCL = 1;
	I2c_Delay(I2c_DELAY/2);
	ack = SDA;
	I2c_Delay(I2c_DELAY/2);
	SCL = 0;
	I2c_Delay(I2c_DELAY);
	if(ack == 1) return 0; 
	return 1;
}
void I2c_Write(unsigned char Data)
{
	unsigned char i;
	
	for(i = 0; i < 8; i++)
	{
		SDA = ((Data << i) & 0x80);
		SCL = 1;
		I2c_Delay(I2c_DELAY);
		SCL = 0;
		I2c_Delay(I2c_DELAY);
	}
}
unsigned char I2c_Read(void)
{
	unsigned char I2c_data = 0, i, temp;
	
	for(i = 0; i < 8; i++)
	{
		SDA = 1;    
		SCL = 1;    
		I2c_Delay(120);
		temp = SDA;
		I2c_Delay(120);
		SCL = 0;
		if(temp == 1)
		{
			I2c_data = I2c_data << 1;
			I2c_data = I2c_data | 0x01;
		}
		else
		I2c_data = I2c_data << 1;
	}
	return I2c_data;
}
#endif