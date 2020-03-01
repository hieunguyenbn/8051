#ifndef _LUNARCALENDAR_H_
#define _LUNARCALENDAR_H_

struct MONTH_INFO{
	unsigned int N_AL_DT_DL		:5;
	unsigned int T_AL_DT_DL		:4;
	unsigned int SN_CT_AL		:1;
	unsigned int TN_B_THT		:1;
	unsigned int SN_CT_DL		:2;
};

union LUNAR_RECORD
{
 	unsigned int Word; 
	struct MONTH_INFO Info;
};

void Solar2Lunar(unsigned char SolarDay, unsigned char SolarMonth, unsigned int SolarYear,
	unsigned char * LunarDay, unsigned char * LunarMonth, unsigned int * LunarYear);

#endif