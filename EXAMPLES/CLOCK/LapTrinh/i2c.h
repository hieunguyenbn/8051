sbit scl = P1^0;
sbit sda = P1^1;
void delay(int time_delay)
{  	
	while(time_delay)
	{
		time_delay--;
	}	
}
//------******Khoi dong I2C******--------- 
void i2c_start(void)
{
	sda=1;
	scl=1;
	delay(15);
	sda=0;
	scl=0;
}
//-----******Ket thuc I2C*******---------
void i2c_stop(void)
{		
	sda= 0;
	scl= 1;	
	delay(15);
	sda=1;
	scl=0;	
}
//-------*******Gui du lieu len duong I2C******------
void i2c_write(unsigned char data_2_send)
{		
	unsigned char temp;	
	for(temp=0;temp<8;temp++)
	{
		sda=(data_2_send&0x80)? 1:0;  //dua bit du lieu ra chan SDA
		scl=1;			  //
		_nop_();
		_nop_();			  //
		scl=0;
		data_2_send<<=1;			   //bit co trong so lon hon dc truyen truoc
	}	
	scl=1;;							//nhan bit ACK tu SLAVER
	_nop_();
	_nop_();	
	scl=0;
}
//------------**********Doc di lieu tren duong I2C******---------
unsigned char i2c_read(void)
{
	unsigned char temp,i;	
	for(i=0;i<8;i++) // nhan vao 8 bit
	{
		scl=1;		
		temp<<=1;
		temp=temp|sda;
		scl=0;
	} 	
	//sda=0;//gui bit NO ACK	 
	scl=1;//master nhan/gui bit du lieu(sda) khi scl o muc cao
	_nop_();
	_nop_();	
	scl=0;//du lieu(sda) thay doi khi scl muc thap*/
	return temp;//tra gia tri cho ham
}