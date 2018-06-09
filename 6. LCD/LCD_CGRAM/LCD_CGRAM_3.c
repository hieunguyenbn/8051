/*  
 Example 2 Animation: Pacman chasing Dot */
#include<reg52.h>

sbit rs=P0^5;			/* Register select pin */
sbit rw=P0^6;			/* Read/Write pin */
sbit en=P0^7;			/* Enable pin */

void lcd_built(void);

unsigned char addr,i;

void delay(unsigned int count)	/* Function to provide delay Approx 1ms */
{
	int i,j;
	for(i=0;i<count;i++)
		for(j=0;j<112;j++);
}

void LCD_Command (char cmd)	/* LCD16x2 command funtion */
{
	P2=cmd;
	rs=0;			/* command reg. */
	rw=0;			/* Write operation */
	en=1; 
	delay(1);
	en=0;
	delay(5);
}

void LCD_Char (char char_data)  /* LCD data write function */
{
	P2=char_data;
	rs=1;			/*Data reg.*/
	rw=0;			/*Write operation*/
	en=1;   				
	delay(1);
	en=0;
	delay(5);
}

void LCD_String (char *str)	/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)  /* Send each char of string till the NULL */
	{
		LCD_Char (str[i]);  /* Call LCD data write */
	}
}

void LCD_Init (void)		/* LCD Initialize function */
{
	delay(20);		/* LCD Power ON Initialization time >15ms */
	
	LCD_Command (0x38);	/* Initialization of 16X2 LCD in 8bit mode */
	LCD_Command (0x0C);	/* Display ON Cursor OFF */
	LCD_Command (0x06);	/* Auto Increment cursor */
	LCD_Command (0x01);	/* Clear display */
	LCD_Command (0x80);	/* Cursor at home position */
}

void LCD_Clear()
{
	LCD_Command (0x01);	/* Clear display */
	LCD_Command (0x80);	/* Cursor at home position */
}

void LCD_Custom_Char (unsigned char loc, unsigned char *msg)
{
    unsigned char i;
    if(loc<8)
    {
     LCD_Command (0x40 + (loc*8));
       for(i=0;i<8;i++)
           LCD_Char(msg[i]);      
    }   
}

void show_set1()
{
	LCD_Char(0x0);
	LCD_Char(0x01);
}

void show_set2()
{
	LCD_Char(0x2);
	LCD_Char(0x3);
}


void show_dots(char j)
{
	LCD_Command(0x80|(addr&0x0f));
	LCD_Char(j);
}

int main(void)
{
	
	LCD_Init();
	LCD_String("Ewings");
	LCD_Command(0x0c3);
	LCD_String("Animation");
	delay(300);
	lcd_built();
	addr=0xc1;
	
	while(1)
	{
		addr=0xc1;
		i=4;
		/* showing set 1 left to right rolling */
		do{
			LCD_Command(addr++);
			show_set1();
			show_dots(i);
			if(i<7)
			i++;
			else
			i=4;
			delay(200);
			LCD_Clear();
			
			LCD_Command(addr++);
			show_set2();
			show_dots(i);
			if(i<7)
			i++;
			else
			i=7;
			delay(200);
			LCD_Clear();
		}while(addr<0xce);
		
		/* showing set 2 right to left rolling */
		do{
			LCD_Command(addr--);
			show_set1();
			show_dots(i);
			if(i<7)
			i++;
			else
			i=4;
			delay(200);
			LCD_Clear();
			
			LCD_Command(addr--);
			show_set2();
			show_dots(i);
			if(i<7)
			i++;
			else
			i=7;
			delay(200);
			LCD_Clear();
		}while(addr>0xc2);
		
		
	}
}


void lcd_built(void)
{
	unsigned char Character1[8] = { 0x01, 0x03, 0x07, 0x0D, 0x0F, 0x02, 0x05, 0x0A };
	unsigned char Character2[8] = { 0x10, 0x18, 0x1C, 0x16, 0x1E, 0x08, 0x14, 0x0A };
	unsigned char Character3[8] = { 0x01, 0x03, 0x07, 0x0D, 0x0F, 0x05, 0x08, 0x04 };
	unsigned char Character4[8] = { 0x10, 0x18, 0x1C, 0x16, 0x1E, 0x14, 0x02, 0x04 };
	unsigned char Character5[8] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18 };
	unsigned char Character6[8] = { 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00 };
	unsigned char Character7[8] = { 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00 };
	unsigned char Character8[8] = { 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00 };

	/* ---------- Build Custom Characters -----------------*/
	
	LCD_Custom_Char(0, Character1);  /* Build Character1 at position 0 */
	LCD_Custom_Char(1, Character2);  /* Build Character2 at position 1 */
	LCD_Custom_Char(2, Character3);  /* Build Character3 at position 2 */
	LCD_Custom_Char(3, Character4);  /* Build Character4 at position 3 */
	LCD_Custom_Char(4, Character5);  /* Build Character5 at position 4 */
	LCD_Custom_Char(5, Character6);  /* Build Character6 at position 5 */
	LCD_Custom_Char(6, Character7);  /* Build Character6 at position 6 */
	LCD_Custom_Char(7, Character8);  /* Build Character6 at position 7 */
}

//void LCD_String_xy (char row, char pos, char *str)  /* Send string to LCD function */
//{
//	if (row == 0)
//	LCD_Command((pos & 0x0F)|0x80);
//	else if (row == 1)
//	LCD_Command((pos & 0x0F)|0xC0);
//	LCD_String(str);	/* Call LCD string function */
//}