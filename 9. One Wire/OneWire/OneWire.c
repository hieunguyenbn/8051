//Do nhiet do su dung cam bien DS18B20
#include <reg52.h>
#include <stdio.h>
#include "..\..\LIBRARY\delay.h"
#include "..\..\LIBRARY\lcd.h"
#include "..\..\LIBRARY\ds18b20.h"
#include "..\..\LIBRARY\port.h"

static unsigned char nhietdo;

int main() {
		LCD_init();
		while(1) {
				WriteCommand(0x83);
				WriteString("DO NHIET DO");
				WriteCommand(0xC4);
				ReadTemperature();
				WriteString("Temp = ");
				WriteChar((nhietdo/10)+48);
				WriteChar((nhietdo%10)+48);
		}
	
		return 0;
}
