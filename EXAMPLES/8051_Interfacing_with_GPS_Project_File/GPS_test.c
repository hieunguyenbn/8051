/*
    GPS Information extraction using 8051 
    http://www.electronicwings.com
*/

#include<reg52.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "LCD_20x4_H_file.h"
#include "USART_Interrupt.h"

unsigned long int get_gpstime();
float get_latitude(unsigned char);
float get_longitude(unsigned char);
float get_altitude(unsigned char);
void convert_time_to_UTC(unsigned long int);
float convert_to_degrees(float raw);

#define GGA_Buffer_Size 80
#define GGA_Pointers_Size 20

char idata GGA_Buffer[GGA_Buffer_Size];              /* to store GGA string */
char idata GGA_CODE[3];
idata unsigned char GGA_Pointers[GGA_Pointers_Size]; /* to store instances of ',' */
char CommaCounter;
idata char Data_Buffer[15];
volatile unsigned int GGA_Index;
unsigned char	IsItGGAString	= 0;

void main(void) {
	unsigned long int Time;
	float Latitude,Longitude,Altitude;
	char GPS_Buffer[15];
	LCD_Init();
	UART_Init();
	Ext_int_Init();                      /* enable interrupt */
	
  while (1){
			memset(GPS_Buffer,0,15);
			LCD_String_xy(1,0,"UTC Time: ");
		  Time = get_gpstime();            /* Extract Time */
			convert_time_to_UTC(Time);       /* convert time to UTC */
			LCD_String(Data_Buffer);
			LCD_String("  ");
		
			LCD_String_xy(2,0,"Lat: ");
			Latitude = get_latitude(GGA_Pointers[0]); /* Extract Latitude */
			Latitude = convert_to_degrees(Latitude);  /* convert raw latitude in degree decimal*/
			sprintf(GPS_Buffer,"%.05f",Latitude);			/* convert float value to string */
			LCD_String(GPS_Buffer);            				/* display latitude in degree */
			memset(GPS_Buffer,0,15);
		
			LCD_String_xy(3,0,"Long: ");
			Longitude = get_longitude(GGA_Pointers[2]);/* Extract Latitude */
			Longitude = convert_to_degrees(Longitude);/* convert raw longitude in degree decimal*/
			sprintf(GPS_Buffer,"%.05f",Longitude);		/* convert float value to string */
			LCD_String(GPS_Buffer);            				/* display latitude in degree */
			memset(GPS_Buffer,0,15);
			
			LCD_String_xy(4,0,"Alt: ");
			Altitude = get_altitude(GGA_Pointers[7]); /* Extract Latitude */
			sprintf(GPS_Buffer,"%.2f",Altitude);			/* convert float value to string */
			LCD_String(GPS_Buffer);            				/* display latitude in degree */

	
	}
}

unsigned long int get_gpstime(){
	unsigned char index;
	unsigned char Time_Buffer[15];
	unsigned long int _Time;
	
	/* parse Time in GGA string stored in buffer */
	for(index = 0;GGA_Buffer[index]!=','; index++){		
		Time_Buffer[index] = GGA_Buffer[index];
	}
	_Time= atol(Time_Buffer);        /* convert string of Time to integer */
	return _Time;                    /* return integer raw value of Time */        
}

float get_latitude(char lat_pointer){
	unsigned char lat_index = lat_pointer+1;	/* index pointing to the latitude */
	unsigned char index = 0;
	char Lat_Buffer[15];
	float _latitude;

	/* parse Latitude in GGA string stored in buffer */
	for(;GGA_Buffer[lat_index]!=',';lat_index++){
		Lat_Buffer[index]= GGA_Buffer[lat_index];
		index++;
	}
	_latitude = atof(Lat_Buffer);     /* convert string of latitude to float */
	return _latitude;                 /* return float raw value of Latitude */
}

float get_longitude(unsigned char long_pointer){
	unsigned char long_index;
	unsigned char index = long_pointer+1;		/* index pointing to the longitude */
	char Long_Buffer[15];
	float _longitude;
	long_index=0;
	
	/* parse Longitude in GGA string stored in buffer */
	for( ; GGA_Buffer[index]!=','; index++){
		Long_Buffer[long_index]= GGA_Buffer[index];
		long_index++;
	}
	_longitude = atof(Long_Buffer);    /* convert string of longitude to float */
	return _longitude;                 /* return float raw value of Longitude */
}

float get_altitude(unsigned char alt_pointer){
	unsigned char alt_index;
	unsigned char index = alt_pointer+1;	/* index pointing to the altitude */
	char Alt_Buffer[12];
	float _Altitude;
	alt_index=0;
	
	/* parse Altitude in GGA string stored in buffer */
	for( ; GGA_Buffer[index]!=','; index++){
		Alt_Buffer[alt_index]= GGA_Buffer[index];
		alt_index++;
	}
		_Altitude = atof(Alt_Buffer);   /* convert string of altitude to float */ 
	return _Altitude;                 /* return float raw value of Altitude */
}

void convert_time_to_UTC(unsigned long int UTC_Time)
{
	unsigned int hour, min, sec;
		
	hour = (UTC_Time / 10000);                  /* extract hour from integer */
	min = (UTC_Time % 10000) / 100;             /* extract minute from integer */
	sec = (UTC_Time % 10000) % 100;             /* extract second from integer*/

	sprintf(Data_Buffer, "%d:%d:%d", hour,min,sec); /* store UTC time in buffer */
	
}

float convert_to_degrees(float raw){
	
	double value;
	float decimal_value,temp;
	
	long int degrees;
	
	float position;
	value = raw;
	
	/* convert raw latitude/longitude into degree format */
	decimal_value = (value/100);
	degrees = (int)(decimal_value);
	temp = (decimal_value - (int)decimal_value)/0.6; 
	position = (float)degrees + temp;
	
	return position;	/* return float value in degrees */
}

void Serial_ISR() interrupt 4    
{
	unsigned char received_char;
	if(RI){
			EA  = 0;							/* Disable global interrupt */
			received_char = SBUF;	

		if(received_char =='$'){                                                    /* check for '$' */
			GGA_Index = 0;
			IsItGGAString = 0;
			CommaCounter = 0;
		}
		else if(IsItGGAString == 1){                                             /* if true save GGA info. into buffer */
			if(received_char == ',' ) GGA_Pointers[CommaCounter++] = GGA_Index;    /* store instances of ',' in buffer */
			GGA_Buffer[GGA_Index++] = received_char;
		}
		else if(GGA_CODE[0] == 'G' && GGA_CODE[1] == 'G' && GGA_CODE[2] == 'A'){ /* check for GGA string */
			IsItGGAString = 1;
			GGA_CODE[0] = 0; GGA_CODE[1] = 0; GGA_CODE[2] = 0;
			
		}
		else{
			GGA_CODE[0] = GGA_CODE[1];  GGA_CODE[1] = GGA_CODE[2]; GGA_CODE[2] = received_char; 
		}
		RI = 0;								/* Clear RI flag */
		EA = 1;               /* enable interrupt */
	}
}