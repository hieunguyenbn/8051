/***************************************************************************************************
                                   ExploreEmbedded	
****************************************************************************************************
 * File:   adc.h
 * Version: 15.0
 * Author: ExploreEmbedded
 * Website: http://www.exploreembedded.com/wiki
 * Description: File contains the Function prototypes for the ADC routines
 
The libraries have been tested on ExploreEmbedded development boards. We strongly believe that the 
library works on any of development boards for respective controllers. However, ExploreEmbedded 
disclaims any kind of hardware failure resulting out of usage of libraries, directly or indirectly.
Files may be subject to change without prior notice. The revision history contains the information 
related to updates. 
 
 
GNU GENERAL PUBLIC LICENSE: 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
Errors and omissions should be reported to codelibraries@exploreembedded.com
 **************************************************************************************************/
 
 
 
 /***************************************************************************************************
                             Revision History
****************************************************************************************************				   
15.0: Initial version 
***************************************************************************************************/
 
#ifndef _ADC_H
#define _ADC_H

#include<reg51.h>
#include"stdutils.h"

/***************************************************************************************************
                                  ADC pin configuration
***************************************************************************************************/
//P3 0x80  P2:0X90 P3:0XA0 P4:0XBO
#define adc_databus P1
#define adc_controlbus P0
#define adc_A 0
#define adc_B 1
#define adc_C 2
#define adc_ALE 3
#define adc_Start 4
#define adc_EOC 5
#define adc_OE 6


/**************************************************************************************************/



/***************************************************************************************************
                             Function prototypes
***************************************************************************************************/
void ADC_Init();
uint16_t ADC_GetAdcValue(uint8_t var_adcChannel_u8);
/**************************************************************************************************/

#endif