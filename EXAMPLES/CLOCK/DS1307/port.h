#ifndef _PORT_H_
#define _PORT_H_

//Khai bao ket noi LCD
#define LCD P2
sbit RS = P0^7;
sbit RW = P0^6;
sbit EN = P0^5;

//Khai bao ket noi I2C
sbit SOFT_I2C_SCL	= P0^1;
sbit SOFT_I2C_SDA	= P0^0; 

#endif
