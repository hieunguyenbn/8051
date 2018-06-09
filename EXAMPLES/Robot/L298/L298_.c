#include<reg52.h>

void delay(void);

sbit motor_pin_1 = P1^0;
sbit motor_pin_2 = P1^1;

void main()
{
  do
  {
    motor_pin_1 = 1;
    motor_pin_2 = 0; //Rotates Motor Anit Clockwise
    delay();
    motor_pin_1 = 1;
    motor_pin_2 = 1; //Stops Motor
    delay();
    motor_pin_1 = 0;
    motor_pin_2 = 1; //Rotates Motor Clockwise
    delay();
    motor_pin_1 = 0;
    motor_pin_2 = 0; //Stops Motor
    delay();
  }while(1);
}

void delay()
{
  int i,j;
  for(i=0;i<1000;i++)
  {
    for(j=0;j<1000;j++)
    {
    }
  }
}