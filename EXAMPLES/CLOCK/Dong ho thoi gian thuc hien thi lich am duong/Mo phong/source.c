#include <REG52.h>
#include<INTRINS.H>
//==========================================
//Cac chan dieu khien
#define   led_port   P0
#define   ic_counter   P2
#define   reg_sec      0x0
#define   reg_min      0x1
#define   reg_hour   0x2
#define   reg_day      0x3
#define   reg_date   0x4
#define   reg_month   0x5
#define   reg_year   0x6
sbit   scl      =   P1^0;
sbit   sda      =   P1^1;
sbit   ic_time   =   P2^4;
sbit   ic_date   =   P2^5;
sbit   menu   =   P3^0;
sbit   plus   =   P3^1;
sbit   minus   =   P3^2;
sbit   al_cancel   =   P3^3;
//==========================================
//Cac bien toan cuc dung trong chuong trinh
unsigned char led_code[13]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0xff,0xfe,0x00};
unsigned char led_buffer[15];
unsigned char scan_led,counter,var_menu;
long ngayam,thangam,ngayduong;
unsigned char sec,min,hour,day,date,month,year,date_1,month_1; //Date_1 la ngay am , month_1 thang am
bit   var_arlam;
//Quet led 7 doan dung timer 0
//Tan so quet khoang 25Hz moi led sang khoang  1000/(25*13)=3ms
void khoi_tao_timer0(void)
{   
   EA=0;//cam ngat toan cuc
   TMOD=0x2;//timer0 che do 8 bit tu dong nap lai
   TL0=0x6;//Gia tri bat dau dem = 6 (tre 250us)
   TH0=0x6;//gia tri TH   dc nap vao TL (che do 8 bit)   
   ET0=1;//cho phep ngat timer0
   EA=1;//cho phep ngat toan cuc
   TR0=1;//Bat dau chay timer0
}
//quet 15 LED Sau 12 lan Timer0 ngat thi thay doi cac led sang
void quet_led(void)interrupt 1 //dia chi vecto ngat timer0
{   
   //counter++;
   if(++counter==12)//sau 12x250us=3ms thi thay doi hien thi led
   {   
      if(scan_led<=6)//chan enb cua IC_COUNTER =>0 khong  co led nao duoc hien thi
      {               
         ic_counter=scan_led;//hien thi cac led o hang 1 (gio, phut,giay,thu)
         //chan enb cua IC_COUNTER =>0 khong  co led nao duoc hien thi
         ic_time=1;//hien thi gio phut giay      
      }else
         {                        
            ic_counter=scan_led-7;// hien thi led hang 2 (ngay thang nam)(tru di so led da hien thi o hang 1)         
            ic_date=1;//hien thi ngay thang nam 
         }    // ic_counter=scan_led-0x7+0xf0 led thu 7 la led thu 0 cua hang 2
      led_port=led_code[(led_buffer[scan_led])];
      //scan_led++;
      if(++scan_led>=15) //vuot qua 15 led thi tro ve ban dau
      {
         scan_led=0;
      }
   }
   if(counter>=13)
   {
      counter=0;//dem lai tu dau
   }      
}
//-----------***************Chuyen doi tu DEC sang BCD************-----------------
unsigned char dec_2_bcd(unsigned char value1)//chuyen doi tu he decima sang BCD
{       
   return ((value1/10)<<4)|(value1%10 ); //((value1/10)*16+value1%10); 
}
//----------**************Chuyen doi tu BCD sang DEC**********---------------------
unsigned char bcd_2_dec(unsigned char value2)//chuyen doi tu he BCD sang DECIMA
{
   return ((value2/16)*10+value2%16);
}
//--------***********tao thoi gian tre dung lenh _nop_();**********-------------
void delay(int time_delay)
{
   unsigned int temp;
   for(temp=0;temp<=time_delay;temp++)
   {
      _nop_();      
   }
}
void delay_2(int time_delay)
{   
   unsigned int temp,i;
   for(i=0;i<time_delay;i++)
   {
      for(temp=0;temp<1000;temp++)
      {
         _nop_();
      }
   }
}
//------******Khoi dong I2C******---------
void i2c_start(void)
{
   scl=1;
   sda=1;   
   _nop_();
   _nop_();
   sda=0;
   scl=0;
}
//-----******Ket thuc I2C*******---------
void i2c_stop(void)
{      
   sda=0;
   scl=1;
   _nop_();
   _nop_();
   sda=1;
   scl=0;   
}
//-------*******Gui du lieu len duong I2C******------
void write_i2c(unsigned char data_2_send)
{
   unsigned char temp;   
   for(temp=0;temp<8;temp++)
   {
      sda=(data_2_send&0x80)? 1:0;  //dua bit du lieu ra chan SDA
      scl=1;                 //
      _nop_();
      _nop_();           //
      scl=0;
      data_2_send<<=1;            //bit co trong so lon hon duoc truyen truoc
   }
   scl=1;                      //nhan bit ACK tu SLAVER
   _nop_();
   _nop_();
   scl=0;
}
//------------**********Doc di lieu tren duong I2C******---------
unsigned char read_i2c(void)
{
   unsigned char temp,i;   
   for(i=0;i<8;i++) // nhan vao 8 bit
   {
      scl=1;
      temp<<=1;
      temp=temp|sda;
      scl=0;
   }    
   sda=1;//gui bit ACK    
   scl=1;//master nhan/gui bit du lieu(sda) khi scl o muc cao
   _nop_();
   _nop_();
   scl=0;//du lieu(sda) thay doi khi scl muc thap*/
   return temp;//tra gia tri cho ham
}
//------*****Ghi du lieu len RTC qua duong I2C*****----------
void write_rtc(char value,addr)
{      
   i2c_start();//start i2c
   write_i2c(0xd0);//0xd0 la ID cua DS1307
   write_i2c(addr);
   write_i2c(value);
   i2c_stop();
}
//---------********Doc du lieu tu RTC qua duong I2C*****--------
char read_rtc(char addr)
{      
   unsigned char temp;
   i2c_start();
   write_i2c(0xd0);// 
   write_i2c(addr);   //bat dau doc du lieu tu thanh ghi co dia chi 0x0 
   i2c_start();
   write_i2c(0xd1); //0xd0 + 0x01 la ID cua ds107 va che do doc du lieu
   temp=read_i2c();//con tro dang tro toi dia chi 0x0 chua du lieu second      
   i2c_stop();//Stop I2C
   return temp;
}
//-----------***********Lay du lieu thoi gian tu cac thanh ghi trong RTC*******---------
void get_time()
{
   //sec=read_rtc(reg_sec);
   min=read_rtc(reg_min);
   hour=read_rtc(reg_hour);
   day=read_rtc(reg_day);
   date=read_rtc(reg_date);
   month=read_rtc(reg_month);
   year=read_rtc(reg_year);
}
///////---------------***********Ghi du lieu va bo dem****-----------                         
 void write_led_buffer(void)
{   
      unsigned char temp;
                  
      //*******Hien thi phut**********      
      led_buffer[0]=min&0x0f;       //Lay 4 bit thap
      led_buffer[1]=(min&0x70)>>4; //lay 3 bit cao
      //*******Hien thi gio*************
      if((temp=(hour&0x30)>>4)==0)//khong hien thi so 0 o hang chuc
      {
         led_buffer[3]=0x0a;
      }else
       {
         led_buffer[3]=temp;//Lay 2 bit cao      
       }
      led_buffer[2]=(hour&0x0f);    //Lay 4 bit thap
      //Hien thi thu trong tuan
      led_buffer[4]=(day&0x7);
      //*******Hien thi ngay AL**********
      led_buffer[5]=date_1%10;
      if((temp=(date_1/10))==0)//khong hien thi so 0 o hang chuc
      {
         led_buffer[6]=0x0a;
      }else
       {
         led_buffer[6]=temp;
       }
      //*******Hien thi Thang AL*********
      led_buffer[7]=month_1%10;
      if((temp=(month_1/10))==0)//khong hien thi so 0 o hang chuc
      {
         led_buffer[8]=0x0a;
      }else
       {
         led_buffer[8]=temp;
       }      
      //******Hien thi nam***********
      led_buffer[9]=(year&0x70)>>4;
      led_buffer[10]=year&0x0f;
      //*********Hien thi thang************
      led_buffer[11]=month&0x0f;
      if(((month&0x30)>>4)==0)//khong hien thi so 0 o hang chuc
      {
         led_buffer[12]=0x0a;      
      }else
         {
            led_buffer[12]=(month&0x30)>>4;
         }      
      //Hien thi Ngay duong lich
      led_buffer[13]=date&0x0f;
      if((temp=(date&0x30)>>4)==0)//khong hien thi so 0 o hang chuc
      {
         led_buffer[14]=0x0a;      
      }else
         {
            led_buffer[14]=temp;
         }               
      }
//-----------------**********Cai dat che do cho RTC****------------------
void setup_rtc(void)
{
   unsigned char temp;
   /*i2c_start();
   write_i2c(0xd0);//che do ghi du lieu vao RTC    
   write_i2c(0x08);//thanh ghi control
   write_i2c(0x10);//xung ra 1Hz muc thap khi khong dc kich hoat
   i2c_stop();*/
   write_rtc(0x10,0x07);
   temp=read_rtc(0x02);
   write_rtc(0x02,temp&0x7f);
    
}
//-----------------**************Do phim**********----------------------
void do_phim(void)
{
   if(menu==0)//phim menu duoc an
   {
       delay_2(50);
      if(var_arlam==0)//Neu khong thuc hien chuc nang hen gio
      {   
      
         if(var_menu<=7)
         {
            var_menu++;   //thuc hien menu tiep
         }else
          {
             var_menu=1;//quay tro ve menu dau tien
          }
       }else
           {
            var_arlam=0;//hen gio xong
          }
      delay_2(50);
   }
   if(al_cancel==0)
   {         
      var_menu=0;
      var_arlam=1;         
      delay(10000);
   }
}
//-----------******Chinh Giay********---------
void menu1(void)
{             
      if((plus==0)||(minus==0))
      {        
         write_rtc(0x0,reg_sec);   //Reset GIAY
         delay_2(50);
      }
}
//----------*********Chinh PHUT*********------------
void menu2(void)
{
   unsigned char temp;
   temp=bcd_2_dec(min);      
   if(plus==0)
   {            
      if(temp<59)
      {
         temp++;
      }else
         {
            temp=0;
         }
      write_rtc(dec_2_bcd(temp),reg_min);
      delay_2(50);
   }
   if(minus==0)
   {            
      if(temp>0)
      {
         temp--;
      }else
         {
            temp=59;
         }
      write_rtc(dec_2_bcd(temp),reg_min);
      delay_2(50);
   }   
}
//----------*********Chinh gio***********------------
void menu3(void)
{
   unsigned char temp;
   temp=bcd_2_dec(hour);   
   if(plus==0)
   {           
      if(temp>=23)
      {
         temp=0;
      }else
         {
            temp++;
         }
       write_rtc(dec_2_bcd(temp),reg_hour);//ghi du lieu BCD vao thanh ghi GiO cua RTC
      delay_2(50);
   }
   if(minus==0)
   {     
      if(temp<=0)
      {
         temp=23;
      }else
         {
            temp--;
         }
      write_rtc(dec_2_bcd(temp),reg_hour);//ghi du lieu BCD vao thanh ghi GiO cua RTC
      delay_2(50);
   }         
}
//----------------********Chinh Ngay Trong Tuan*******----------------------
void menu4(void)
{
   unsigned char temp;
   temp=bcd_2_dec(day);      
   if(plus==0)
   {       
      if(temp>=7)
      {
         temp=1;
      }else
         {
            temp++;
         }
      write_rtc(dec_2_bcd(temp),reg_day);//ghi du lieu BCD vao thanh ghi GiO cua RTC
      delay_2(50);
   }
   if(minus==0)
   {         
      if(temp<=1)
      {
         temp=7;
      }else
         {
            temp--;
         }
      write_rtc(dec_2_bcd(temp),reg_day);//ghi du lieu BCD vao thanh ghi GiO cua RTC
      delay_2(50);
   }         
}
//-----------********Chinh Ngay********----------------
void menu5()
{
   unsigned char temp,temp1,temp2;
   temp=bcd_2_dec(date);   
   temp1=bcd_2_dec(month);
   temp2=bcd_2_dec(year);      
   if(plus==0)       //******An PLUS***----       
   {   
      if((temp1==4)||(temp1==6)||(temp1==9)||(temp1==11))//Cac thang co 30 ngay 
      {
         if(temp>=30)
         {
            temp=1;
         }
      }else
         {
            if(temp1==2)//thang 2
            {
               if(temp2%4==0)//nam nhuan
               {
                  if(temp>=29)
                  {
                     temp=1;
                  }else
                     {
                        temp++;
                     }
               }else       //nam thuong
                  {
                     if(temp>=28)
                     {
                        temp=1;
                     }else
                     {
                        temp++;
                     }
                  }
            }else   //cac thang co 31 ngay
               {
                  if(temp>=31)
                  {
                     temp=1;
                  }else
                     {
                        temp++;
                     }   
               }   
         }
      write_rtc(dec_2_bcd(temp),reg_date);//ghi du lieu BCD vao thanh ghi GiO cua RTC
      delay_2(50);
   }
   if(minus==0)  //-********AN MINUS****--------      
   {   
      if(temp>2)
      {
         temp--;
      }else
         {
            if((temp1==4)||(temp1==6)||(temp1==9)||(temp1==11))//Cac thang co 30 ngay 
            {            
                  temp=30;               
            }else
               {
                  if(temp1==2)//thang 2
                  {
                     if(temp2%4==0)//nam nhuan
                     {
                        temp=29;
                     }else       //nam thuong
                        {
                           temp=28;
                        }
                  }else   //cac thang co 31 ngay
                     {
                        temp=31;   
                     }      
               }
          }
      write_rtc(dec_2_bcd(temp),reg_date);//ghi du lieu BCD vao thanh ghi GiO cua RTC
      delay_2(50);
   }   
}
void menu6(void)//-------*********Chinh Thang-*******---------
{   
   unsigned char temp;
   temp=bcd_2_dec(month);   
   if(plus==0)
   {        
      if(temp>=12)
      {
         temp=1;
      }else
         {
            temp++;
         }
      write_rtc(dec_2_bcd(temp),reg_month);//ghi du lieu BCD vao thanh ghi GiO cua RTC
      delay_2(50);
   }
   if(minus==0)
   {         
      if(temp==0)
      {
         temp=12;
      }else
         {
            temp--;
         }
      write_rtc(dec_2_bcd(temp),reg_month);//ghi du lieu BCD vao thanh ghi GiO cua RTC
      delay_2(50);
   }      
}
//---------**********Chinh Nam**********--------------
void menu7(void)
{   unsigned char temp;
   temp=bcd_2_dec(year);   
   if(plus==0)
   {         
      if(temp>=50)//Chinh thoi gian tu nam 2011 den Nam 2050
      {
         temp=11;
      }else
         {
            temp++;
         }
      write_rtc(dec_2_bcd(temp),reg_year);//ghi du lieu BCD vao thanh ghi GiO cua RTC
      delay_2(50);
   }
   if(minus==0)
   {    
      if(temp<=11)
      {
         temp=50;
      }else
         {
            temp--;
         }
      write_rtc(dec_2_bcd(temp),reg_year);//ghi du lieu BCD vao thanh ghi GiO cua RTC
      delay_2(50);
   }   
}
//-----------***********Thuc Hien MENU*********---------------
void xu_ly_menu(void)
{
   while(var_menu!=0)
   {
      get_time();
      write_led_buffer();
      switch(var_menu)
      {
         case   1: 
            menu1();
            break;
         case   2: 
            menu2();
            break;
         case   3: 
            menu3();
            break;
         case   4: 
            menu4();
            break;
         case   5: 
            menu5();
            break;
         case   6: 
            menu6();
            break;
         case   7: 
            menu7();
            break;
      }
      do_phim();
   }
}
//-------********Dua du lieu ra bo nho dem LED******---------
void start_system()
{      
   var_menu=0;
   //var_arlam=0;      
}
//-- chuyen ngay duong sang ngay am------
void da(int m,d)
{   
   ngayduong=(m-1)*31+d;//so ngay duong so voi 1.1
   if ((m==3)|(m==4)) ngayduong=ngayduong-3;//do thang 2 co 28 ngay
   else 
       if ((m==5)|(m==6)) ngayduong=ngayduong-4;// thang 4 co 30 ngay
       else
      if ((m==7)|(m==8)|(m==9)) ngayduong=ngayduong-5;//thang 6 co 30 ngay
      else
          if ((m==10)|(m==11)) ngayduong=ngayduong-6;//thang 9 co 30 ngay
          else 
         if (m==12) ngayduong=ngayduong-7;// thang 11 co 30 ngay
   ngayam=ngayduong+26;//mung 1.1 la ngay 27.11
   thangam=11;
   if (ngayam>=30) 
   {
       ngayam=ngayam-29;
       thangam=12;
   }
   while (ngayam>=30)
   {
       if ((thangam==2)|(thangam==5)|(thangam==8)|(thangam==7)|(thangam==10))
       {
      if (ngayam==29) break;
      ngayam=ngayam-29;      
      thangam++;
      if (thangam==13) thangam=1;
       }
       else 
      if (ngayam==30) break;
      else
      {
      ngayam=ngayam-30;
      thangam++;
      if (thangam==13) thangam=1;
      }
   }   
}
//---------------**************Chuong trinh chinh**********----------------------
void main(void)                           
{         
   khoi_tao_timer0();   
   start_system();         
   setup_rtc(); 
   while(1)
   {             
      //Dat ngay Am lich o day 
      //////////
      get_time();      
      da(bcd_2_dec(month),bcd_2_dec(date));//dau vao la thang duong ngay duong dau ra la thangam ngayam hien thi ngayam thangam
      date_1=thangam;
      month_1=ngayam;
     write_led_buffer();   
      do_phim();         
      xu_ly_menu();                     
   }                          
}
//-----------------**************Ket thuc chuong trinh********--------------------                
