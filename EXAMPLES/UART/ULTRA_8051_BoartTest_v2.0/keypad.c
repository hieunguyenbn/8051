/*----------------------------------------------------------------------------------
                        8051 4x4 Keypad Library
Filename: keypad.c
Controller: P89V51RD2/89c51(8051 family)
Oscillator: 11.0592 MHz
Author: XploreLabz
website: www.xplorelabz.com

 ----------------------------------------------------------------------------------
 Note:
  1.Rows are connected to lower 4-bits of P1
  1.Cols are connected to higher 4-bits of P1
            ___________________
           |    |    |    |    |
           | 0  | 1  | 2  | 3  |--------- R0
           |____|____|____|____|
           |    |    |    |    |
		   | 4  | 5  | 6  | 7  |--------- R1
           |____|____|____|____|
           |    |    |    |    |
		   | 8  | 9  | A  | B  |--------- R2
		   |____|____|____|____|
		   |    |    |    |    |
		   | C  | D  | E  | F  |--------- R3
           |____|____|____|____|
             |    |    |    |
             |    |    |    |____________ C3
             |    |    |
             |    |    |_________________ C2
             |    |
             |    |______________________ C1
             |
             |___________________________ C0

----------------------------------------------------------------------------------*/



#include <reg51.h>
#include "keypad.h"
#include "delay.h"



#define ROW P2   //Lower four bits of P1 are used as ROWs
#define COL P2   //Higher four bits of P1 are used as COLs




/*---------------------------------------------------------------------------------
                   void KEYPAD_Init()
 ----------------------------------------------------------------------------------
 * I/P Arguments:none
 * Return value : none

 * description  : This function the rows and colums for keypad scan
        1.ROW lines are configured as Output.
        2.Column Lines are configured as Input.
-----------------------------------------------------------------------------------*/
void KEYPAD_Init()
{
       ROW=0xF0;           // Configure Row lines as O/P and Column lines as I/P
}





/*---------------------------------------------------------------------------------
                   void KEYPAD_WaitForKeyRelease()
 ----------------------------------------------------------------------------------
 * I/P Arguments:none

 * Return value	: none

 * description  : This function waits till the previous key is released.
        1.All the ROW lines are pulled low.
        2.Column Lines are read to check the key press.
        3.If all the Keys are released then Column lines will be High(0xF0)
-----------------------------------------------------------------------------------*/
void KEYPAD_WaitForKeyRelease()
{
   unsigned char key;
    do
	  {
        ROW=0xF0;           // Pull the ROW lines to low and Column lines high.
	    key=COL & 0xF0;     // Read the Columns, to check the key press
       }while(key!=0xF0);   // Wait till the Key is released,
                            // If no Key is pressed, Column lines will be High(0xF0)
}





/*---------------------------------------------------------------------------------
                   void KEYPAD_WaitForKeyPress()
 ----------------------------------------------------------------------------------
 * I/P Arguments:none

 * Return value	: none

 * description  : This function waits till a new key is pressed.
        1.All the ROW lines are pulled low.
        2.Column Lines are read to check the key press.
        3.If any Key is pressed then corresponding Column Line goes low.

        4.Wait for Some time and perform the above operation to ensure
          the True Key Press before decoding the KEY.
-----------------------------------------------------------------------------------*/
void KEYPAD_WaitForKeyPress()
{
  unsigned char key;
  do
   {
	 do
      {
	    ROW=0xF0;		  // Pull the ROW lines to low and Column lines high.
	    key=COL & 0xF0;	  // Read the Columns, to check the key press
	   }while(key==0xF0); // Wait till the Key is pressed,
						  // if a Key is pressed the corresponding Column line go low

	   DELAY_ms(1);		  // Wait for some time(debounce Time);

	   ROW=0xF0;		  // After debounce time, perform the above operation
	   key=COL & 0xF0;	  // to ensure the Key press.

	}while(key==0xF0);

 }





/*---------------------------------------------------------------------------------
                   unsigned char KEYPAD_ScanKey()
 ----------------------------------------------------------------------------------
 * I/P Arguments:none

 * Return value	: char--> Scancode of the Key Pressed

 * description  : This function scans all the rows to decode the key pressed.
        1.Each time a ROW line is pulled low to detect the KEY.
        2.Column Lines are read to check the key press.
        3.If any Key is pressed then corresponding Column Line goes low.

        4.Return the ScanCode(Combination of ROW & COL) for decoding the key.
-----------------------------------------------------------------------------------*/
unsigned char KEYPAD_ScanKey()
 {

	 unsigned char ScanKey = 0xFE,i, key;

   for(i=0;i<0x04;i++)            // Scan All the 4-Rows for key press
    {
      ROW=ScanKey;                // Select 1-Row at a time for Scanning the Key
      key=COL & 0xF0;             // Read the Column, for key press

      if(key!=0xf0)               // If the KEY press is detected for the selected
         break;                   // ROW then stop Scanning,

     ScanKey=((ScanKey<<1)+0x01); // Rotate the ScanKey to SCAN the remaining Rows
    }


    key = COL;                    // Retun the COL status to decode the key
    return(key);
}






/*---------------------------------------------------------------------------------
                   unsigned char KEYPAD_GetKey()
 ----------------------------------------------------------------------------------
 * I/P Arguments:none

 * Return value	: char--> ASCII value of the Key Pressed

 * description: This function waits till a key is pressed and retuns its ASCII Value

        1.Wait till the previous key is released..
        2.Wait for the new key press.
        3.Scan all the rows one at atime for the pressed key.
        4.Decode the key pressed depending on ROW-COL combination and retuns its
          ASCII value.
-----------------------------------------------------------------------------------*/
unsigned char KEYPAD_GetKey()
{
	unsigned char key;

      KEYPAD_WaitForKeyRelease();    // Wait for the previous key release
      DELAY_ms(1);

      KEYPAD_WaitForKeyPress();      // Wait for the new key press
      key = KEYPAD_ScanKey();        // Scan for the key pressed.

   switch(key)                       // Decode the key
     {
         case 0xe7: key='C'; break;
         case 0xeb: key='D'; break;
         case 0xed: key='E'; break;
         case 0xee: key='F'; break;
  		 case 0xd7: key='8'; break;
		 case 0xdb: key='9'; break;
	 	 case 0xdd: key='A'; break;
	 	 case 0xde: key='B'; break;
	  	 case 0xb7: key='4'; break;
		 case 0xbb: key='5'; break;
		 case 0xbd: key='6'; break;
	 	 case 0xbe: key='7'; break;
		 case 0x77: key='0'; break; 
		 case 0x7b: key='1'; break; 
		 case 0x7d: key='2'; break;  
		 case 0x7e: key='3'; break;
         default: key='z';
      }
   return(key);                      // Return the key
}
