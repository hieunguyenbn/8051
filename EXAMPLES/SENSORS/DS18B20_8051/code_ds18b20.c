#include <reg52.h>
//Khai bao chan giao tiep LCD16x2 4bit
sbit LCD_RS = P2^0;
sbit LCD_RW = P2^1;
sbit LCD_EN = P2^2;
sbit LCD_D4 = P2^4;
sbit LCD_D5 = P2^5;
sbit LCD_D6 = P2^6;
sbit LCD_D7 = P2^7;
//Khai bao chan giao tiep DS18B20
sbit DQ	= P3^7;
unsigned char temp; //Bien luu gia tri nhiet do
/*****************Ham delay*********************/
 void delay_us(unsigned int t){
        unsigned int i;
        for(i=0;i<t;i++);
}
void delay_ms(unsigned int t){
        unsigned int i,j;
        for(i=0;i<t;i++)
        for(j=0;j<125;j++);
}
/****************Ctr giao tiep IC DS18B20***************************/
void delay_18B20(unsigned int ti){
    while(ti--);
}
void Init_18B20(void){
    DQ = 1;   
    delay_18B20(8);
    DQ = 0;   
    delay_18B20(65);
    DQ = 1;   
    delay_18B20(20);    
}
unsigned char ReadOneChar(void){
    unsigned char i=0;
    unsigned char dat = 0;
    for (i=8;i>0;i--){
          DQ = 0;
          dat>>=1;
          DQ = 1;
          if(DQ)
          dat |= 0x80;
          delay_18B20(4);
    }
    return(dat);
}
void WriteOneChar(unsigned char dat){
    unsigned char i=0;
    for (i=8; i>0; i--){
        DQ = 0;
        DQ = dat&0x01;
        delay_18B20(5);
        DQ = 1;
        dat>>=1;
    }
}
void ReadTemperature(void){	
    unsigned char a=0;
    unsigned char b=0;
	//EA=0;//Cam ngat tranh viec anh huong qua trinh doc nhiet do
    Init_18B20();
    WriteOneChar(0xCC);        // Bo qua ROM
    WriteOneChar(0x44);
    delay_18B20(10); 
    Init_18B20();
    WriteOneChar(0xCC);
    WriteOneChar(0xBE);    //Doc nhiet do
    delay_18B20(10);
    a=ReadOneChar();        //Read temp low value
    b=ReadOneChar();          //Read temp high value
    temp=((b*256+a)>>4);    //gia tri nhiet do luu vao bien temp
}
/**************Ctr giao tiep LCD 16x2 4bit**********************/
void LCD_Enable(void){
        LCD_EN =1;
        delay_us(3);
        LCD_EN=0;
        delay_us(50); 
}
void LCD_Send4Bit(unsigned char Data){
        LCD_D4=Data & 0x01;
        LCD_D5=(Data>>1)&1;
        LCD_D6=(Data>>2)&1;
        LCD_D7=(Data>>3)&1;
}
void LCD_SendCommand(unsigned char command){
        LCD_Send4Bit(command >>4);/* Gui 4 bit cao */
        LCD_Enable();
        LCD_Send4Bit(command); /* Gui 4 bit thap*/
        LCD_Enable();
}

void LCD_Init(){
        LCD_Send4Bit(0x00);
        delay_ms(20);
        LCD_RS=0;
        LCD_RW=0;
        LCD_Send4Bit(0x03);
        LCD_Enable();
        delay_ms(5);
        LCD_Enable();
        delay_us(100);
        LCD_Enable();
        LCD_Send4Bit(0x02);
        LCD_Enable();
        LCD_SendCommand( 0x28 );
        LCD_SendCommand( 0x0c); 
        LCD_SendCommand( 0x06 );
        LCD_SendCommand(0x01);
}
void LCD_Gotoxy(unsigned char x, unsigned char y){
        unsigned char address;
        if(!y)address=(0x80+x);
        else address=(0xc0+x);
        delay_us(1000);
        LCD_SendCommand(address);
        delay_us(50);
}
void LCD_PutChar(unsigned char Data){//Ham Gui 1 Ki Tu
        LCD_RS=1;
        LCD_SendCommand(Data);
        LCD_RS=0 ;
}
void LCD_Puts(char *s){//Ham gui 1 chuoi ky tu
        while (*s){
                LCD_PutChar(*s);
                s++;
        }
}
void TempShow(unsigned char z){ //Chuyen doi hien thi
     LCD_Puts("Nhiet do: ");
    // LCD_PutChar((z/100)+48);//Tram
     LCD_PutChar((z/10)+48);//Chuc
     LCD_PutChar((z%10)+48);//Don vi 
     LCD_Puts("^C");
}
/******************Ctr chinh**************************/

void main(){
	//init	
	LCD_Init();//Khoi tao LCD
	LCD_Gotoxy(0,1);
	LCD_Puts("VNU - HUS");
	while(1){
		  LCD_Gotoxy(0,0);
		  ReadTemperature(); //Doc nhiet do luu vao bien temp
		  TempShow(temp); //Hien thi nhiet do
		  delay_ms(200);//0.5s doc mot lan
	}
}






