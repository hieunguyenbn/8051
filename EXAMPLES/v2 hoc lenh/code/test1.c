/************************************************************
giai ma remote hong ngoai, hoc lenh hong ngoai phien ban v2
Code viet boi Dao Van Nguyen : www.gocdiy.com
Kenh youtube : WWW.youtube.com/gocdiy
fb can nhan: fb.com/anhmaidoicho 
thac mac cac ban co the trao doi tai group : www.facebook.com/group/gocdiy
*************************************************************/
#include <REGX52.H>
 //khai bao ket noi lcd
//#define LCD_RS  P2_0	
//#define LCD_EN  P2_1	 
//#define LCD_D4  P2_4	 
//#define LCD_D5  P2_5
//#define LCD_D6  P2_6
//#define LCD_D7  P2_7
#define bt  P0_0
/* Các lenh dinh nghia giao tiep i2c*/
#define SCL  P1_0
#define SDA  P1_1

#define tb1  P2_0
#define tb2  P2_1
#define tb3  P2_2
#define tb4  P2_3
#define tb5  P2_4
#define tb6  P2_5
#define tb7  P2_6
#define tb8  P2_7

sbit IR_pin = P3^2;

unsigned int IR_dodai,trangthaiIR;
unsigned long giatri,g;
unsigned char g1,g2,g3,g4;
unsigned char hoclenh;
unsigned char ghi=1,doc=0;

//////////////////////// Cac Ham thiet lap LCD///////////////////////////////////
//void delay_us(unsigned int t)  // Ham tre micro giay
//{
//	unsigned int i;
//	for(i=0;i<t;i++);
//}
void delay_ms(unsigned int t)	// Ham tre mini giay
{
	unsigned int i,j;
	for(i=0;i<t;i++)
		for(j=0;j<125;j++);
}
//// Ham cho phep hien thi len LCD
//void LCD_Enable(void)
//{
//	LCD_EN = 1;
//	delay_us(3);
//	LCD_EN = 0;
//	delay_us(50); 
//}
//// Ham gui 4 bit
//void LCD_Send4Bit(unsigned char Data)
//{
//	LCD_D4 = Data & 0x01;
//	LCD_D5 = (Data>>1)&1;
//	LCD_D6 = (Data>>2)&1;
//	LCD_D7 = (Data>>3)&1;
//}
//// Ham gui 1 Byte du lieu
//void LCD_Send1Byte(unsigned char byte)
//{
//	LCD_Send4Bit(byte >>4);/* Gui 4 bit cao */
//	LCD_Enable();
//	LCD_Send4Bit(byte); /* Gui 4 bit thap*/
//	LCD_Enable();
//}
//// Ham di chuyen con tro: row=0-1; col=0-15 (2 hang + 16 cot)
//void LCD_chonvitri(unsigned char row, unsigned char col)
//{
//	unsigned char address;   
//	if (row == 0) address = (0x80 + col);	 // row=0 - hang 1
//    else address = (0xC0 + col);			 // row=1 - hang 2
//    delay_us(1000);
//    LCD_Send1Byte(address);
//    delay_us(50);
//}
//// Ham hien thi ra man hinh chuoi ki tu
//void LCD_guichuoi(char *s)
//{
//	while (*s)
//	{
//		LCD_RS=1;
//		LCD_Send1Byte(*s);
//		LCD_RS=0;
//		s++;
//	}
//}
//void LCD_guikitu(int s)
//{
//		LCD_RS=1;
//		LCD_Send1Byte(s);
//		LCD_RS=0;	
//	
//}
//// Ham xoa man hinh
//void LCD_xoamanhinh()
//{
//    LCD_chonvitri(0,0);
//	LCD_guichuoi("                ");
//	LCD_chonvitri(1,0);
//	LCD_guichuoi("                ");
//	LCD_chonvitri(0,0);
//}
//// Ham khoi tao LCD
//void LCD_khoitao()
//{
//	LCD_Send4Bit(0x00);
//	delay_ms(20);
//	LCD_RS = 0;
//	LCD_Send4Bit(0x03);	 // 
//	LCD_Enable();
//	delay_ms(5);
//	LCD_Enable();
//	delay_ms(100);
//	LCD_Enable();
//	LCD_Send4Bit(0x02);	// dua con tro ve dau man hinh
//	LCD_Enable();
//	LCD_Send1Byte(0x28);
//	LCD_Send1Byte(0x0C); // Bat hien thi, bat con tro	 0x0C neu muon tat con tro	   0x0F neu muon bat con tro
//	LCD_Send1Byte(0x06);
//	LCD_xoamanhinh();
//	delay_ms(20);
//}
//void LCD_hex(unsigned long d)
//{ 
//unsigned char byte;
//(((d>>28)&0x0F)<=9)?(byte='0'+((d>>28)&0x0F)):(byte='A'+((d>>28)&0x0F)-0x0A); LCD_guikitu(byte);
//(((d>>24)&0x0F)<=9)?(byte='0'+((d>>24)&0x0F)):(byte='A'+((d>>24)&0x0F)-0x0A); LCD_guikitu(byte);
//(((d>>20)&0x0F)<=9)?(byte='0'+((d>>20)&0x0F)):(byte='A'+((d>>20)&0x0F)-0x0A); LCD_guikitu(byte);
//(((d>>16)&0x0F)<=9)?(byte='0'+((d>>16)&0x0F)):(byte='A'+((d>>16)&0x0F)-0x0A); LCD_guikitu(byte);
//(((d>>12)&0x0F)<=9)?(byte='0'+((d>>12)&0x0F)):(byte='A'+((d>>12)&0x0F)-0x0A); LCD_guikitu(byte);
//(((d>>8)&0x0F)<=9)?(byte='0'+((d>>8)&0x0F)):(byte='A'+((d>>8)&0x0F)-0x0A); LCD_guikitu(byte);
//(((d>>4)&0x0F)<=9)?(byte='0'+((d>>4)&0x0F)):(byte='A'+((d>>4)&0x0F)-0x0A); LCD_guikitu(byte);
//((d&0x0F)<=9)?(byte='0'+(d&0x0F)):(byte='A'+(d&0x0F)-0x0A); LCD_guikitu(byte); 
//} 
//////////////ket thuc cac ham thiet lap LCD/////////

///*-----------------------------------------*/

/***********Hàm khoi tao i2c***************/
/* Mô ta : 
   de goi i2c start bat dau qua trinh giao tiep, chan SDA phai duoc dua xuong muc 0, trong khi SLC dang o muc 1. sau 1 thoi gian ngan
   chan SCL cung duoc dua xuong muc 0. ngay tai thoi diem chan SCL duoc dau xuong muc 0. qua trình truyen du lieu bat dau
*/
void I2C_Start(void)
{
	SDA = 1;	
	SCL = 1;	// dua SCL va SDA len muc 1
	SDA = 0;	// keo SDA xuong 0
	delay_ms(1); // delay 1 khoang thoi gian ngan
	SCL = 0;	  // keo SCL xuong 0  ( qua trinh Start ket thuc)
	SDA = 1;	  // dua SDA len muc 1 ( cau lenh nay khong can cung dc)
}
/*------------------------end Start----------------------------------/


/* Mô ta : 
   Sau khi qua trinh truyen du lieu hoan tat thi ta can Stop de ket thuc qua trinh truyen
   Muon Stop. kéo chân SDA lên muc 1 trong khi SCL dang o muc 1
*/
void I2C_STOP()
{
  SDA=0; // cho SDA xuong 0 de chuan bi dua len 1
  SCL=1; // dua SCL len muc 1 
  SDA=1; // SDA duoc dua len muc 1. Qua trinh Stop hoan tat
}
/*------------------------end Stop------------------*/


/* Mô ta : 
   Ghi du lieu trong chuan I2C 
   Nhiem vu : VDK truyen du lieu vao slaver ( o day la DS1307)  
   Tham bien truyen vao : dat
   Tra ve : 0 hoac 1 ( khong nhat thiet phai tra ve, muc dich la lay bit ack de kiem tra qua trinh truyen du lieu da ok chua)
   bang cach goi ham va nhap vao 1 byte du lieu can truyen. ta se truyen duoc duoc du lieu do vao slaver
*/
bit I2C_Write(unsigned char dat) // khai bao ham truyen du lieu va bien dat  
{
	unsigned char i;  // khai bao bien i
	bit outbit;		  // khai bao bit 
	
	for (i = 1; i <= 8; i++)	//vong lap for lap 8 lan tuong duong 8 bit ( 1 byte)
	{
		outbit=dat&0x80;	    // gán bien outbit cho byte can truen & 0x80 ; 
		SDA = outbit;			 // cho SDA bang voi gia tri cua outbit ( 1 hoac 0)
		dat = dat << 1;			 // dich trai 1 lan
		SCL = 1;
		SCL = 0;				 // tao 1 xung clock tren chan SCL de dich gia tri 1 hoac 0 tren chan SDA vao slaver
    }	
	SDA = 1;	
	SCL = 1;	  // dua SDA va SCL len muc 1 chuan bi doc bit ack
	outbit = SDA;	// lay bit ack tu chan SDA
	SCL = 0;		// cho SCL ve 0	 
	return(outbit);	// lay gia tri ve
}
/* giai thich dong 87 ---> 94
 De co the truyen 1 byte ( vi du 0xBA) vao slaver. ta tien hanh tach 1 byte do ra thành 8 bit. do do can co vong lap for 8 lan ( moi lan truyen 1 bit)
 Dau tien i=1 
               truyen bit thu nhat : ta co 0xBA = 1 0 1 1 1 0 1 0 . Bit dau tien la bit so 1 ( ben tay trai, truyen tu trai sang phai)
                                                 TA có : 0xBA & 0x80 = 10111010 & 10000000 = 10000000 
												 Do ket qua nhan dc la 10000000 khac 0. ma outbit chi nhan 2 gia tri 1 hoac 0 , Cho nen outbit = 1
												 Nhu vay, ta da truyen dc bit dau tien la 1 vao I2C
												 Sau do dich 0xBA sang 1 : 0xBA <<1 = 01110100
Vong lap thu 2, i = 2 : 
             tiep tuc nhu vay . nhung lan nay 01110100 & 0x80 se = 0 . outbit se = 0
			 Cu nhu vay 8 lan. byte 0xBA se duoc truyen sang slaver

/*------------------------end I2C write------------------*/



/* Mô ta : 
  Doc du lieu tu i2C gui ra vdk
*/
unsigned char I2C_Read(bit ack)
{
	unsigned char i, dat;
	bit inbit;	
	dat = 0;
	for(i=1;i<=8;i++)	// moi lan doc 1 bit. 8 lan doc = 1 byte
	 {
		SCL = 1;	   // cho SCL len =1 , slaver se gui 1 bit vao chan SDA
		inbit = SDA;	// lay gia tri cua chan SDA gán vao inbit
		dat = dat << 1;	 // dich byte data sang trái  1 lan
		dat = dat | inbit;	// muc dich la gán giá tri cua bit inbit vao byte dat
		SCL = 0;		// cho SLC xuong muc 0 san sang cho lan doc bit tiep thep
	 }
	if (ack) SDA = 0;	 // cac cau lenh  nay dung de doc bit ack ( co the k can quan tam)
	else SDA = 1;
	SCL = 1;	
	SCL = 0;	
	SDA = 1;							 
	return(dat);
}
 /*------------------------end I2C read------------------*/

 //--------------cac ham phuc vu giao tiep I2c------------
 // Ham doc du lieu thoi gian trong ds
unsigned char EEP_docdulieu(unsigned char diachi)
{
	unsigned char dat;
	
	I2C_Start();   // bat dau doc
	
	I2C_Write(0xa0); 	// dau tien gui lenh ghi du lieu(ghi dia EEP)
	I2C_Write(diachi); // Dia chi ma ta muon doc ( vi du, muon doc giay thi ta ghi dia chi 0x00)
	I2C_Start(); 	 // bat dau doc du lieu
	I2C_Write(0xa1);  	// gui ma lenh doc du lieu tu dia chi(add)
	dat = I2C_Read(0);	  // doc xong thi luu gia tri da doc dc vao dat
	I2C_STOP();			// ket thuc qua trinh doc du lieu			  
	return (dat);  // tra ve gia tri da doc duoc
}

void EEP_ghidulieu(unsigned char add, unsigned long Data)
{
	I2C_Start(); // bat dau ghi	
	I2C_Write(0xa0); //0xao la dia chi EEP C24
	I2C_Write(add);	// gia tri can ghi
	I2C_Write(Data); 	 // ghi du lieu vao
	I2C_STOP();	 // ket thuc qua trinh truyen du lieu
	delay_ms(100);
}
////--------------Ket thuc cac ham giao tiep voi EEPROM----------


void IR_khoitao()
{
 TMOD=0x01; //Timer 0 Mode 1
 EX0=1;  // ngat theo suon am
 IT0 = 1; // cho phep ngat ngoai
 ET0  = 1;  // cho ngat timer
 EA = 1;        //cho phep ngat
}
void tach_dulieu()
{
	g1=giatri>>24;
	g2=giatri>>16;
	g3=giatri>>8;
	g4=giatri;
/*
Tai sao phai tach du lieu ??? 
Li do nhu sau: De co the luu duoc gia tri remote ma ta da giai ma duoc. Ta phai luu gia tri do vao EEPROM. TUy nhien,
1 thanh ghi cua EEPROM C24 chi co do dai toi da la 1byte. Trong khi gia tri ta giai ma duoc len den 4byte.
Do do phai tach gia tri do ra lam 4 gia tri nho. Moi gia tri kick thuoc bang 1byte va duoc luu vao 4 bien g1 g2 g3 g4
*/
}
void ghep_dulieu()
{
	g = g1*16777216 + g2*65536 + g3*256 + g4; // giatri= g1 * 2^24 + g2 * 2^16 + g3 * 2 ^ 8 + g4 *	2^0  
/*
Tai sao phai ghep du lieu ??? 
Li do nhu sau: Do truoc do ta da tach ra roi thi gio duong nhien phai ghep lai hihi
*/
}
void ghi_dulieu()
{
 if(ghi==8)
 {
  EEP_ghidulieu(0x81,g1);  EEP_ghidulieu(0x82,g2); EEP_ghidulieu(0x83,g3);  EEP_ghidulieu(0x84,g4);	ghi=1; hoclenh=0; tb8=1;
 }
 else if(ghi==7)
 {
  EEP_ghidulieu(0x71,g1);  EEP_ghidulieu(0x72,g2); EEP_ghidulieu(0x73,g3);  EEP_ghidulieu(0x74,g4);	ghi=8;tb7=1;tb8=0;
 }
  else if(ghi==6)
 {
  EEP_ghidulieu(0x61,g1);  EEP_ghidulieu(0x62,g2); EEP_ghidulieu(0x63,g3);  EEP_ghidulieu(0x64,g4);	ghi=7;tb6=1;tb7=0;
 }
  else if(ghi==5)
 {
  EEP_ghidulieu(0x51,g1);  EEP_ghidulieu(0x52,g2); EEP_ghidulieu(0x53,g3);  EEP_ghidulieu(0x54,g4);	ghi=6;tb5=1;tb6=0;
 }
  else if(ghi==4)
 {
  EEP_ghidulieu(0x41,g1);  EEP_ghidulieu(0x42,g2); EEP_ghidulieu(0x43,g3);  EEP_ghidulieu(0x44,g4);	ghi=5;tb4=1;tb5=0;
 }
 else if(ghi==3)
 {
  EEP_ghidulieu(0x31,g1);  EEP_ghidulieu(0x32,g2); EEP_ghidulieu(0x33,g3);  EEP_ghidulieu(0x34,g4);	ghi=4;tb3=1;tb4=0;
 }
  else if(ghi==2)
 {
  EEP_ghidulieu(0x21,g1);  EEP_ghidulieu(0x22,g2); EEP_ghidulieu(0x23,g3);  EEP_ghidulieu(0x24,g4); ghi=3;tb2=1;tb3=0;
 }
 else if(ghi==1)
 {
  EEP_ghidulieu(0x11,g1);  EEP_ghidulieu(0x12,g2); EEP_ghidulieu(0x13,g3);  EEP_ghidulieu(0x14,g4);	ghi=2;tb2=0;tb1=1;
 }
 
}
void docdulieu(unsigned char tb)
{
      if(tb==1){g1=EEP_docdulieu(0x11);g2=EEP_docdulieu(0x12);g3=EEP_docdulieu(0x13);g4=EEP_docdulieu(0x14);}
 else if(tb==2){g1=EEP_docdulieu(0x21);g2=EEP_docdulieu(0x22);g3=EEP_docdulieu(0x23);g4=EEP_docdulieu(0x24);}
 else if(tb==3){g1=EEP_docdulieu(0x31);g2=EEP_docdulieu(0x32);g3=EEP_docdulieu(0x33);g4=EEP_docdulieu(0x34);}
 else if(tb==4){g1=EEP_docdulieu(0x41);g2=EEP_docdulieu(0x42);g3=EEP_docdulieu(0x43);g4=EEP_docdulieu(0x44);}
 else if(tb==5){g1=EEP_docdulieu(0x51);g2=EEP_docdulieu(0x52);g3=EEP_docdulieu(0x53);g4=EEP_docdulieu(0x54);}
 else if(tb==6){g1=EEP_docdulieu(0x61);g2=EEP_docdulieu(0x62);g3=EEP_docdulieu(0x63);g4=EEP_docdulieu(0x64);}
 else if(tb==7){g1=EEP_docdulieu(0x71);g2=EEP_docdulieu(0x72);g3=EEP_docdulieu(0x73);g4=EEP_docdulieu(0x74);}
 else if(tb==8){g1=EEP_docdulieu(0x81);g2=EEP_docdulieu(0x82);g3=EEP_docdulieu(0x83);g4=EEP_docdulieu(0x84);}
 ghep_dulieu();
}

/*-----------------------------------------------------------------------------
// Check START============
unsigned char kiemtra()
{
           TH0 = 0x00;  //Reset Timer 0 Value  = 0		   
           TL0 = 0x00; //Reset Timer 0 Value  = 0
           TR0 = 1; //Start Timer 0
           while(IR_pin == 0);    //Cho cho den khi het muc 0
           TR0 = 0; //Stop Timer 0
           TF0 = 0;//Clear timer 0 Flag
           IR_dodai_0 = TH0;			
	       IR_dodai_0 <<= 8;				
	       IR_dodai_0 |= TL0;
           if(IR_dodai_0>2000)		  // neu 2000 thi day dung la bit Start
            return 1;
           else  return 0;
}



void Read_IR_Key(void) interrupt 0  //External Interrupt
{
    unsigned char i=0,doc;

   if(kiemtra()== 1)
   {
      while(IR_pin == 1); //Cho cho het phan bit 1 cua START

      while(i<32)
      {
         if(IR_pin == 1) //Neu co muc cao
          {
           TH0 = 0x00; //Reset Timer 0 Value  = 0
           TL0 = 0x00; //Reset Timer 0 Value  = 0
           TR0 = 1; //Start timer 0
           while(IR_pin == 1);    //Cho cho den khi het muc 1
           TR0 = 0; //Stop Timer 0
           TF0 = 0;//Clear timer 0 Flag
           IR_dodai_0 = 0;					   
           IR_dodai_0 = TH0*256+TL0;
           giatri = giatri <<= 1;
           if(IR_dodai_0>800)
					 {giatri+=1;}
           i++;
          }
         while(IR_pin == 0);
      }
	  delay_ms(50);
    if(hoclenh==1)
	{
	  tach_dulieu();ghi_dulieu();   
	}
	else
	{
	  for(doc=1;doc<9;doc++)
	  {
	    docdulieu(doc);
		     if(doc==1 && g == giatri){tb1=~tb1;}
		else if(doc==2 && g == giatri){tb2=~tb2;}
		else if(doc==3 && g == giatri){tb3=~tb3;}
		else if(doc==4 && g == giatri){tb4=~tb4;}
		else if(doc==5 && g == giatri){tb5=~tb5;}
		else if(doc==6 && g == giatri){tb6=~tb6;}
		else if(doc==7 && g == giatri){tb7=~tb7;}
		else if(doc==8 && g == giatri){tb8=~tb8;}
	  }	
	}
   }
giatri=0x00000000;
}

--------------------------------------------------------------------------------*/
void ngat_giama(void) interrupt 0
{
 TR0=0; //dung timer
 switch(trangthaiIR)
 {
   case 0:				   // khi xay ra ngat thi case dang bang 0, ta se dung timer lai de set bien trang thai IR len bang 1 va khoi dong timer 0 cho no dem
   {
     trangthaiIR=1;
	 giatri=0;		       // xoa gia tri IR da thu dc truoc do
	 TL0=0xDF;
	 TH0=0xB1;			   // ta nap gia tri   cho THTL = 65535- 20000= B1DF. 20000 la do dai toi da de chap nhan do la bit start
	 TR0=1;				   // timer bat dau dem
	 break;
   }
   case 1:
   {
     IR_dodai=TH0-0xB1;			  // tinh toan thoi gian ma timer dem duoc. do truoc do ta da nap gia tri B1DF roi ne gio phai - di
	 IR_dodai=IR_dodai*255+(TL0-0xDF);			 // ghep gia tri cua 2 thanh TH TL
	 if(IR_dodai>2000)
	 {							   
	   trangthaiIR=2;				 // neu dung la bit star ( > 2000) thi set trang thau  =2 ( chuyen sang doc data)
	   TL0=0x47;
	   TH0=0xF4;
	   TR0=1;			   // timer bat dau dem
	 }
	 else {trangthaiIR=0;}   // nguoc lai khong phai start, quay ve lam lai
	 break;
   }
   case 2:
   {  
     IR_dodai=TH0-0xF4;			  // tinh toan thoi gian ma timer dem duoc. do truoc do ta da nap gia tri f447 roi ne gio phai - di
	 IR_dodai=IR_dodai*255+(TL0-0x47);			 // ghep gia tri cua 2 thanh TH TL
	 TL0=0x47;
	 TH0=0xF4;
	 TR0=1;			   // timer bat dau dem
	 giatri<<=1;
	 if(IR_dodai>1500)
	 {	
		giatri++;
	 }
   }
 }
}
void ngattimer0(void) interrupt 1		//ngat timer 0 de giai ma 
   { 
	 TR0 =0;				//dung timer 0
	 if (trangthaiIR==1) trangthaiIR = 0;	//  khong chap nhan do la bit start vi qua dai
	 else if (trangthaiIR==2)		// Bit stop
	 {
		 EX0 = 0; 			// cam ngat ngoai 0 de xu ly ket qua giai ma
		 trangthaiIR = 3;
	 }
   }


void main()
{	
IR_khoitao();
  while(1)
          {
		   	if(bt==0){hoclenh=1;P2=~0x01;}	
			if(trangthaiIR==3)
			{
			   if(hoclenh==1)
					{
					  tach_dulieu();ghi_dulieu();   
					}
			   else
					{
					  for(doc=1;doc<9;doc++)
					  {
					    docdulieu(doc);
						     if(doc==1 && g == giatri){tb1=~tb1;}
						else if(doc==2 && g == giatri){tb2=~tb2;}
						else if(doc==3 && g == giatri){tb3=~tb3;}
						else if(doc==4 && g == giatri){tb4=~tb4;}
						else if(doc==5 && g == giatri){tb5=~tb5;}
						else if(doc==6 && g == giatri){tb6=~tb6;}
						else if(doc==7 && g == giatri){tb7=~tb7;}
						else if(doc==8 && g == giatri){tb8=~tb8;}
					  }	
					}
			 EX0 = 1;
			 trangthaiIR=0;
			}	
		  }
}
