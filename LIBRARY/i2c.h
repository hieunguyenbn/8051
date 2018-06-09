#ifndef _I2C_H_
#define _I2C_H_

void I2C_start();
void I2C_stop();
void I2C_write(unsigned char d);
unsigned char I2C_read(bit ack);

#endif