#define SDA P2_7	/* Set P2.7 = SDA */
#define SCL P2_6	/* Set P2.6 = SCL */
#define I2C_DELAY 0x0F	/* For delay i2c bus */

void I2C_delay(void)
{
unsigned char i;

for(i=0; i<I2C_DELAY; i++);
}

void I2C_clock(void)
{
I2C_delay();

SCL = 1;	/* Start clock */

I2C_delay(); 

SCL = 0;	/* Clear SCL */
}

void I2C_start(void)
{
if(SCL)
SCL = 0;	/* Clear SCL */

SDA = 1; /* Set SDA */
SCL = 1;	/* Set SCL */

I2C_delay(); 

SDA = 0; /* Clear SDA */

I2C_delay(); 

SCL = 0; /* Clear SCL */
}

void I2C_stop(void)
{
if(SCL)	
SCL = 0;	/* Clear SCL */

SDA = 0;	/* Clear SDA */
I2C_delay();

SCL = 1;	/* Set SCL */

I2C_delay();

SDA = 1;	/* Set SDA */
}

bit I2C_write(unsigned char dat)
{
bit data_bit;	
unsigned char i;	

for(i=0;i<8;i++)	/* For loop 8 time(send data 1 byte) */
{
data_bit = dat & 0x80;	/* Filter MSB bit keep to data_bit */
SDA = data_bit;	/* Send data_bit to SDA */

I2C_clock(); /* Call for send data to i2c bus */

dat = dat<<1; 
}

SDA = 1;	/* Set SDA */

I2C_delay();	

SCL = 1;	/* Set SCL */

I2C_delay();	

data_bit = SDA; /* Check acknowledge */
SCL = 0;	/* Clear SCL */

I2C_delay();

return data_bit;	/* If send_bit = 0 i2c is valid */	
}

unsigned char I2C_read(void)
{
bit rd_bit;	
unsigned char i, dat;

dat = 0x00;	

for(i=0;i<8;i++)	/* For loop read data 1 byte */
{
I2C_delay();

SCL = 1;	/* Set SCL */

I2C_delay(); 

rd_bit = SDA;	/* Keep for check acknowledge	*/
dat = dat<<1;	
dat = dat | rd_bit;	/* Keep bit data in dat */

SCL = 0;	/* Clear SCL */
}

return dat;
}

//void I2C_ack()
//{
//	SDA = 0;	/* Clear SDA */

//	I2C_delay(); 

//	I2C_clock();	/* Call for send data to i2c bus */

//	SDA = 1;	/* Set SDA */
//}

void I2C_noack()
{
SDA = 1;	/* Set SDA */

I2C_delay();

I2C_clock();	/* Call for send data to i2c bus */

SCL = 1;	/* Set SCL */
}

