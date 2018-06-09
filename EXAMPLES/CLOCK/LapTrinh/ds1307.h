//-------------------------------------------------------------
void rtc_write(unsigned char add, unsigned char dat){
i2c_start();
i2c_write(0xd0); // d?a ch? c?a 1307 //ch? d? ghi
i2c_write(add); // d?a ch? thanh ghi
i2c_write(dat); // chuy?n thành s? th?p phân
i2c_stop();
}

//---------------------------------------------------------------
// d?c d? li?u t?i thanh ghi có d?a ch? add c?a RTC
//---------------------------------------------------------------
unsigned char rtc_read(unsigned char add){
unsigned char dat;
i2c_start();
i2c_write(0xd0); // d?a ch? c?a DS1307 // ch? d? ghi
i2c_write(add); // d?a ch? thanh ghi c?n d?c
i2c_start(); // restart
i2c_write(0xd1); // d?a ch? DS1307 // ch? d? d?c
dat = i2c_read();
i2c_stop();
return (dat);
}