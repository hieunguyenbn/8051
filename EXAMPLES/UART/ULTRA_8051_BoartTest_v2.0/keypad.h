#ifndef _KEYPAD_H
#define _KEYPAD_H

void KEYPAD_WaitForKeyRelease();
void KEYPAD_WaitForKeyPress();
unsigned char KEYPAD_ScanKey();
unsigned char KEYPAD_GetKey();
void KEYPAD_Init();

#endif