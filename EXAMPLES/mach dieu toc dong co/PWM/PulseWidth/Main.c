/*---------------------------------------------------------
---------------------------------------------------------*/
#include <reg52.h>
#include <stdio.h>

/*---------------------------------------------------------
Timer 0 Overflow Interrupt
---------------------------------------------------------*/
unsigned int T0_ISR_count = 0;

void T0_ISR (void) interrupt 1
{
T0_ISR_count++;
TF0 = 0;                        // Reset the interrupt request
}


/*---------------------------------------------------------
MAIN C function
---------------------------------------------------------*/
void main (void)
{
/*--------------------------------------
Set serial port for 9600 baud at
11.0592 MHz.  Note that we use Timer 1
for the baud rate generator.
--------------------------------------*/
SCON  = 0x50;
TMOD |= 0x20;
TH1   = 0xFA;
TR1   = 1;
TI    = 1;
PCON |= 0x80;

printf ("\nPulse Width Example Program\n\n");

/*--------------------------------------
Enable interrupts for timer 0.
--------------------------------------*/
ET0 = 1;
EA = 1;

/*--------------------------------------
Set Timer0 for 16-bit interval timer
mode.
--------------------------------------*/
TMOD = (TMOD & 0xF0) | 0x09;

while (1)
  {
/*--------------------------------------
Clear the timer overflow counter and
the timer low and high registers.  Then,
start the timer.
--------------------------------------*/
  T0_ISR_count = 0;
  TH0 = 0;
  TL0 = 0;

  TR0 = 1;

  printf ("\nStart a pulse.\n");

/*--------------------------------------
Wait for the pulse to start.
Then, wait for the pulse to end.
--------------------------------------*/
  while (!INT0);
  while (INT0);

/*--------------------------------------
Compute the width of the pulse -- one
clock cycle is 1us for a standard 8051
and display it.
--------------------------------------*/
  printf ("The width pulse is: %ld uSec\n",
          (unsigned long)((TH0 << 8) | TL0 | ((unsigned long)T0_ISR_count << 16)));
  }
}

/*---------------------------------------------------------
---------------------------------------------------------*/

