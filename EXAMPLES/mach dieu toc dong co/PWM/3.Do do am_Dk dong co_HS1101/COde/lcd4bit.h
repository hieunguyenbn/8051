/****************************************************************************/
/*																			*/
/*	Function:	This module is a standard LCD (16x2) functions				*/
/*																			*/
/*			Input and Output parameters of those subroutines:				*/
/*			void LCD_Init(void);											*/
/*			void LCD_Position(unsigned char, unsigned char);				*/
/*		 	void LCD_PutCmd(unsigned char);									*/
/*			void LCD_PutChar(unsigned char);								*/
/*			void LCD_PrString(char*);										*/
/*			void LCD_Clear(void);											*/
/*			void LCD_PrInteger(int);										*/
/*																			*/
/*	Note:	Must be call LCD_Init() first at the begining of program		*/
/*																			*/	
/****************************************************************************/
/*																			*/
/*	History:																*/	
/*	Version:																*/
/*			Date			Writer			Remark							*/
/*																			*/
/*			30-07-2012		Nguyen Van Sao		Creating the first version		*/
/*																			*/	
/*																			*/		
/****************************************************************************/
/*****************************************************************************
	define Hardware address
*****************************************************************************/
#define LCD_PORT	P0		
sbit LCD_RS = LCD_PORT^0;
sbit LCD_RW	= LCD_PORT^1;
sbit LCD_EN = LCD_PORT^2;

#define ReadCommand		{LCD_RS = 0; LCD_RW = 1;}
#define WriteCommand	{LCD_RS = 0; LCD_RW = 0;}
#define WriteData		{LCD_RS = 1; LCD_RW = 0;}
#define LatchData		{LCD_EN = 1; LCD_EN = 0;}

/****************************************************************************
	define LCD command
*****************************************************************************/
#define LCD_CLEAR			0x01	// Clear display
#define LCD_HOME			0x02  	// return cursor and LCD to home position
#define LCD_OFF 			0x08	// turn off display and cursor
#define LCD_DISPLAY_ON		0x0C	// turn on display and turn off cursor
#define LCD_CURSOR_ON		0x0A 	// turn on cursor and turn off display
#define LCD_BLINK_CURSOR 	0x0E	// turn on display and blink cursor
#define LCD_FONT_8BIT		0x38	// set interace length: 8bits, 2 lines, font 5x8
#define LCD_FONT_4BIT		0x28	// set interace length: 4bits, 2 lines, font 5x8	
#define LCD_MOVE_CURSOR		0x06	// Entry mode set: set increments mode, not shift (cursor)
#define LCD_MDRIGHT			0x1C	// Move display to the right
#define LCD_MDLEFT			0x18    // Move display to the left

//=================================================================
void WaitReady()
{
	bit lcd_busy = 1;
	ReadCommand;
	LCD_PORT |= 0xF0;				// set outputlatches to '1'
	while(lcd_busy){
		LCD_EN = 1;					// read high nibble	
		lcd_busy = 1;
		lcd_busy = LCD_PORT & 0x80;	// return bit 7
		LCD_EN = 0;	
		LCD_EN = 1;					// read low nibble
		LCD_EN = 0;
	}
}

//==============================================================================
void write_char(unsigned char c)
{
	unsigned char temp;
	temp = c & 0xF0;			// Don't affect bits 0-3
	LCD_PORT &= 0x0F;			// Bits 4..7 <- 0
	LCD_PORT |= temp; 			// High nibble to display
	LatchData;

	temp = (c << 4) & 0xF0;		// Prepare to send low nibble
	LCD_PORT &= 0x0F; 			// Bits 4..7 <- 0
	LCD_PORT |= temp;		   	// Low nibble to display
	LatchData;
}			

/*****************************************************************************/
void LCD_Init_Write(unsigned char cmd)
{
	WaitReady();
	WriteCommand;
	LCD_PORT = cmd;
	LatchData;
}
 
/****************************************************************************
	LCD_PutCmd function
	Write a control byte to LCD
	Input : control byte
*****************************************************************************/
void LCD_PutCmd(unsigned char cmd)
{
	WaitReady();  		// Wait for LCD ready
	WriteCommand;		// set LCD to send mode
	write_char(cmd);	// send command
}

/****************************************************************************
	LCD_PutChar function
	Write a ASCII symbol to LCD
	Input: ASCII symbol
*****************************************************************************/
void LCD_PutChar(unsigned char ch)
{
	WaitReady();
	WriteData;
	write_char(ch);
}

/*****************************************************************************
	LCD_PrString function
	Write a string to LCD
	Input: string
******************************************************************************/
void LCD_PrString(char *str)
{
	while(*str!='\0'){
		LCD_PutChar(*str);
		++str;
	}
}

/*****************************************************************************
	LCD_Position function
	Set the position of cursor on LCD
	Input: row, column
******************************************************************************/
void LCD_Position(unsigned char row, unsigned char col)
{
	LCD_PutCmd( (1<<7)|(row<<6)|col );
}

/*****************************************************************************
	LCD_Clear function
	Clear LCD
******************************************************************************/
void LCD_Clear()
{
	LCD_PutCmd(LCD_CLEAR);	
}

/*****************************************************************************
	LCD_Init function
	Prepare for display content. Must be called at first
******************************************************************************/
void LCD_Init()
{
//	LCD_Init_Write(0x30);				// Data length setting, 8 bits
//	LCD_Init_Write(0x30);				// Data length setting, 8 bits
//	LCD_Init_Write(0x30);				// Data length setting, 8bits

	LCD_Init_Write(LCD_FONT_4BIT);  // set a 5x8 dot character font
	LCD_PutCmd(LCD_FONT_4BIT);		// and 4 bits data bus
	LCD_PutCmd(LCD_DISPLAY_ON);		// 0x0C, Display on and cursor off
	LCD_PutCmd(LCD_MOVE_CURSOR);	// 0x06
//	LCD_PutCmd(LCD_BLINK_CURSOR);	// Blink cursor
}

/****************************************************************************
	LCD_PrInteger function
	Display a integer decimal number to LCD
	Input: a integer number
*****************************************************************************/
void LCD_PrInteger(unsigned char num)
{
	int temp;
	unsigned char i = 0, c[5];
	temp = num;	
	if (temp != 0) {
		if (temp < 0){
			LCD_PutChar('-');
			temp = - temp;	
		}
		while(temp){
			c[i++] = temp%10; 
			temp /= 10;
		} 
		while(i) LCD_PutChar(c[--i] + '0');
	}
	else LCD_PutChar('0');
}
/************************* END OF FILE *******************************/



