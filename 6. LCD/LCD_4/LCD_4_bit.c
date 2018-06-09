#include<reg52.h>
/* Configure the data bus and Control bus as per the hardware connection 
   Databus is connected to P2.4:P2.7 and control bus P2.0:P2.2*/
#define LcdDataBus  P2

sbit LCD_RS = P2^0;
sbit LCD_RW = P2^1;
sbit LCD_EN = P2^2;


/* local function to generate delay */
void delay(unsigned int t)
{
    while(t--);
}



/* Function to send the command to LCD. 
   As it is 4bit mode, a byte of data is sent in two 4-bit nibbles */
void Lcd_CmdWrite(char cmd) {
    LcdDataBus = (cmd & 0xF0);     //Send higher nibble
    LCD_RS = 0;   // Send LOW pulse on RS pin for selecting Command register
    LCD_RW = 0;   // Send LOW pulse on RW pin for Write operation
    LCD_EN = 1;   // Generate a High-to-low pulse on EN pin
    delay(1000);
    LCD_EN = 0;
    delay(10000);
    LcdDataBus = ((cmd<<4) & 0xF0); //Send Lower nibble
    LCD_RS = 0;   // Send LOW pulse on RS pin for selecting Command register
    LCD_RW = 0;   // Send LOW pulse on RW pin for Write operation
    LCD_EN = 1;   // Generate a High-to-low pulse on EN pin
    delay(1000);
    LCD_EN = 0; 
    delay(10000);
}


/* Function to send the Data to LCD. 
   As it is 4bit mode, a byte of data is sent in two 4-bit nibbles */
void Lcd_DataWrite(char dat) {
    LcdDataBus = (dat & 0xF0);      //Send higher nibble
    LCD_RS = 1;   // Send HIGH pulse on RS pin for selecting data register
    LCD_RW = 0;   // Send LOW pulse on RW pin for Write operation
    LCD_EN = 1;   // Generate a High-to-low pulse on EN pin
    delay(1000);
    LCD_EN = 0;
    delay(10000);
    LcdDataBus = ((dat<<4) & 0xF0);  //Send Lower nibble
    LCD_RS = 1;    // Send HIGH pulse on RS pin for selecting data register
    LCD_RW = 0;    // Send LOW pulse on RW pin for Write operation
    LCD_EN = 1;    // Generate a High-to-low pulse on EN pin
    delay(1000);
    LCD_EN = 0; 
    delay(10000);
}



int main()
{
    char i,a[]={"Good morning!"};

    LcdDataBus = 0x00;  // Configure all the LCD pins as output


    Lcd_CmdWrite(0x02);        // Initialize Lcd in 4-bit mode
    Lcd_CmdWrite(0x28);        // enable 5x7 mode for chars 
    Lcd_CmdWrite(0x0E);        // Display OFF, Cursor ON
    Lcd_CmdWrite(0x01);        // Clear Display
    Lcd_CmdWrite(0x80);        // Move the cursor to beginning of first line


    Lcd_DataWrite('H');
    Lcd_DataWrite('e');
    Lcd_DataWrite('l');
    Lcd_DataWrite('l');
    Lcd_DataWrite('o');
    Lcd_DataWrite(' ');
    Lcd_DataWrite('H');
    Lcd_DataWrite('I');
    Lcd_DataWrite('E');
    Lcd_DataWrite('U');

    Lcd_CmdWrite(0xC0);        //Go to Next line and display Good Morning
   
		for(i=0; a[i]!=0; i++) {
        Lcd_DataWrite(a[i]);
    }

    while(1);
}