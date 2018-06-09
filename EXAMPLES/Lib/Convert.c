#include "convert.h"

void Byte2Str(unsigned char input, char * output)
{
 	char i;

	i = 2;
	do
	{
	 	output[i] = input%10+0x30;
		i--;
		input = input/10;
	}while(input!=0);

	// Lap khoang trang vao cac vi tri con lai
	while(i>=0)
	{
	 	output[i] = ' ';
		i--;
	}
	output[3] = 0;
}

void Short2Str(char input, char * output)
{
	char i;
	bit s;

	s = (input>=0);
	if(input<0) input = -input;

	i = 3;
	do
	{
	 	output[i] = input%10+0x30;
		i--;
		input = input/10;
	}while(input!=0);

	if(!s)
	{
	 	output[i]= '-';
		i--;
	}

	// Lap khoang trang vao cac vi tri con lai
	while(i>=0)
	{
	 	output[i] = ' ';
		i--;
	}
	output[4] = 0;
} 

void Word2Str(unsigned int input, char * output)
{
	char i;

	i = 4;
	do
	{
	 	output[i] = input%10+0x30;
		i--;
		input = input/10;
	}while(input!=0);

	// Lap khoang trang vao cac vi tri con lai
	while(i>=0)
	{
	 	output[i] = ' ';
		i--;
	}
	output[5] = 0;
}

void Int2Str(int input, char * output)
{
	char i;
	bit s;

	s = (input>=0);
	if(input<0) input = -input;

	i = 5;
	do
	{
	 	output[i] = input%10+0x30;
		i--;
		input = input/10;
	}while(input!=0);

	if(!s)
	{
	 	output[i]= '-';
		i--;
	}

	// Lap khoang trang vao cac vi tri con lai
	while(i>=0)
	{
	 	output[i] = ' ';
		i--;
	}
	output[6] = 0;
}