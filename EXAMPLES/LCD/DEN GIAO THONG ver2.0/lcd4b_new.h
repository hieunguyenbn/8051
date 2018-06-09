//Khai bao chan giao tiep LCD16x2 4bit
#define LCD_RS  P2_0
#define LCD_RW  P2_1
#define LCD_EN  P2_2
#define LCD_D4  P2_4
#define LCD_D5  P2_5
#define LCD_D6  P2_6
#define LCD_D7  P2_7
//Khai bao chan giao tiep DS18B20


void delay_ms(unsigned int t){
        unsigned int i,j;
        for(i=0;i<t;i++)
        for(j=0;j<125;j++);
}
 void delay_us(unsigned int t){
        unsigned int i;
        for(i=0;i<t;i++);
}
/**************Ctr giao tiep LCD 16x2 4bit**********************/
void LCD_Enable(void){
        LCD_EN =1;
        delay_us(3);
        LCD_EN=0;
        delay_us(50); 
}
//Ham Gui 4 Bit Du Lieu Ra LCD
void LCD_Send4Bit(unsigned char Data){
        LCD_D4=Data & 0x01;
        LCD_D5=(Data>>1)&1;
        LCD_D6=(Data>>2)&1;
        LCD_D7=(Data>>3)&1;
}
// Ham Gui 1 Lenh Cho LCD
void LCD_SendCommand(unsigned char command){
        LCD_Send4Bit(command >>4);/* Gui 4 bit cao */
        LCD_Enable();
        LCD_Send4Bit(command); /* Gui 4 bit thap*/
        LCD_Enable();
}
void LCD_Clear(){// Ham Xoa Man Hinh LCD
        LCD_SendCommand(0x01); 
        delay_us(10);
}
// Ham Khoi Tao LCD
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
        			
			if(x==1) LCD_SendCommand(0x80+y-1);
			if(x==2) LCD_SendCommand(0xc0+y-1);
			if(x==3) LCD_SendCommand(0x90+y-1);
			if(x==4) LCD_SendCommand(0xd0+y-1);
			delay_us(1000);	
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






