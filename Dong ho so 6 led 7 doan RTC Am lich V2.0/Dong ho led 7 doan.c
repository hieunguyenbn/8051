#include<at89x52.h>
#include"LunarCalendar.h"

#define SCL 		P1_0
#define SDA 		P1_1


//========= 6-14 Led 48x70 V1.2 & V1.3 =========>
#define Bao_Gio 	P2_0
#define Bao_Thuc 	P2_1
#define Loa			P1_3
#define Alarm		P1_4
#define Tang 		P1_5
#define Giam 		P1_6
#define Mode 		P1_7

#define Ds18B20		P1_2                 				//Communication port defined ds18b20 

#define led1 		P2_7
#define led2 		P2_6
#define led3 		P2_5
#define led4 		P2_4
#define led5 		P2_3
#define led6 		P2_2

#define led7 		P3_7
#define led8 		P3_6
#define led9 		P3_5
#define led10 		P3_4
#define led11 		P3_3
#define led12 		P3_2
#define led13 		P3_1 
//#define led14 	P3_0
#define dk_nhay		P3_0
//<======================


#define Diachi_1307 0xd0	
#define Giay 		0x00
#define	Phut 		0x01	
#define Gio 		0x02
#define Thu 		0x03
#define Ngay 		0x04
#define Thang 	0x05
#define Nam 		0x06
#define Tang_Giam	0x3d		// Tu dong dieu chinh Tang hay Giam
#define Chinh_Gio	0x3e		// Tu dong dieu chinh thoi gian
#define So_Alarm	1+5			// Khai bao so lan bao thuc : 1 lan bao 1 lan va 5 lan bao lap lai
#define Tre_L		300 //200
#define Tre_N		100 //30

unsigned char Ma_7doan[10] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90 }; //Ma Led 7 doan
unsigned char hien_thi,time,index,mode,Cai_Alarm,Nhay_Led,Lay_gio,loop;
unsigned char gio,phut,giay,thu,ngay,thang,nam,Gio12,Dieuchinh,chinh_gio,tang_giam;
unsigned char mode_hien,so1,so2,so3,docnhietdo;
unsigned char Ktra_DS18B20;
unsigned int t1,t2,nhietdo,nhietdo2;


// Lunar Calendar Lookup Table by dangemailbox
// From 1/1/2000 to 31/12/2099
#define BEGINNING_YEAR	2000
unsigned int code LUNAR_CALENDAR_LOOKUP_TABLE[] = {
	0x1B79,0x099A,0x1A3A,0x125B,0x187B,0x109D,0x1ABE,0x18E2,0x1304,0x1924,0x1346,0x1B66,//2000
	0x1987,0x0229,0x1A47,0x1068,0x1A89,0x108A,0x1AAB,0x18CC,0x10EE,0x1B0F,0x1130,0x1B51,//01
	0x1972,0x0394,0x1A32,0x1253,0x1873,0x1295,0x18B5,0x1AD7,0x10F8,0x1919,0x133B,0x195B,//02
	0x1B7D,0x0021,0x1A3D,0x125E,0x1881,0x12A2,0x18C2,0x1AE4,0x1105,0x1926,0x1348,0x1968,//03
	0x1B8A,0x082B,0x1A4B,0x104C,0x1A6D,0x128E,0x18AE,0x1AD0,0x10F1,0x1B12,0x1133,0x1B54,//04
	0x1975,0x0397,0x1835,0x1257,0x1877,0x1299,0x18B9,0x1ADB,0x12FC,0x191C,0x133E,0x1961,//05
	0x1982,0x0224,0x1842,0x1264,0x1884,0x10A6,0x1AC7,0x1AE8,0x10E9,0x1B0A,0x132B,0x194B,
	0x1B6D,0x018E,0x1A2D,0x104E,0x1A6F,0x1090,0x18B1,0x1AD3,0x10F4,0x1B15,0x1336,0x1B56,
	0x1977,0x0B99,0x1A38,0x1059,0x187A,0x129C,0x18BC,0x18E1,0x1102,0x1B23,0x1144,0x1B65,
	0x1B86,0x0227,0x1845,0x1267,0x1887,0x12A9,0x18A9,0x18CB,0x12ED,0x190D,0x132F,0x194F,
	0x1B71,0x0392,0x1A30,0x1051,0x1A72,0x1093,0x1AB4,0x18D5,0x10F7,0x1B18,0x1139,0x1B5A,//10
	0x197B,0x039D,0x1A3B,0x105C,0x1A7D,0x129E,0x18C1,0x18E2,0x1104,0x1B25,0x1146,0x1B67,
	0x1988,0x0A2A,0x1849,0x126B,0x1A8B,0x108C,0x1AAD,0x18CE,0x12F0,0x1910,0x1332,0x1952,
	0x1B74,0x0195,0x1A34,0x1055,0x1A76,0x1097,0x1AB8,0x1AD9,0x10FA,0x1B1B,0x113C,0x1B5D,
	0x1981,0x0022,0x1841,0x1062,0x1A83,0x10A4,0x1AC5,0x18E6,0x1308,0x1B28,0x1129,0x1B4A,
	0x196B,0x038D,0x182B,0x124D,0x186D,0x108F,0x1AB0,0x18D1,0x12F3,0x1B13,0x1334,0x1954,//15
	0x1B76,0x0997,0x1A37,0x1058,0x1A79,0x109A,0x18BB,0x1ADD,0x1301,0x1B21,0x1142,0x1B63,//2016
	0x1B84,0x0025,0x1A44,0x1065,0x1A86,0x10A7,0x18C8,0x1ACA,0x10EB,0x1B0C,0x112D,0x1B4E,
	0x1B6F,0x0390,0x182E,0x1250,0x1870,0x1292,0x18B2,0x18D4,0x12F6,0x1916,0x1138,0x1B59,
	0x1B7A,0x039B,0x1839,0x125B,0x1A7B,0x109C,0x1ABD,0x18E1,0x1303,0x1923,0x1145,0x1B66,
	0x1B87,0x0828,0x1A48,0x1269,0x1A89,0x108A,0x1AAB,0x18CC,0x10EE,0x1B0F,0x1130,0x1951,//20
	0x1B73,0x0394,0x1832,0x1254,0x1A74,0x1095,0x1AB6,0x18D7,0x12F9,0x1919,0x133B,0x195B,
	0x1B7D,0x0021,0x1A3D,0x1061,0x1A81,0x12A3,0x1AC3,0x18E4,0x1306,0x1926,0x1348,0x1968,
	0x1B8A,0x002B,0x1A4A,0x104B,0x186C,0x128E,0x1AAE,0x18CF,0x12F1,0x1B11,0x1132,0x1B53,
	0x1974,0x0B96,0x1835,0x1257,0x1877,0x1099,0x1ABA,0x18DB,0x12FD,0x1B1D,0x1141,0x1B61,
	0x1982,0x0224,0x1842,0x1264,0x1884,0x10A6,0x1AC7,0x18C8,0x12EA,0x190A,0x132C,0x1B4C,//25
	0x1B6D,0x018E,0x1A2D,0x104E,0x1A6F,0x1090,0x18B1,0x1AD3,0x10F4,0x1915,0x1337,0x1B57,
	0x1B78,0x0199,0x1A38,0x1259,0x1879,0x129B,0x18BB,0x18DD,0x1301,0x1922,0x1344,0x1B64,
	0x1985,0x0A27,0x1A46,0x1267,0x1887,0x12A9,0x18A9,0x18CB,0x12ED,0x190D,0x112F,0x1B50,
	0x1B71,0x0192,0x1A31,0x1252,0x1872,0x1294,0x18B4,0x1AD6,0x10F7,0x1B18,0x1139,0x195A,
	0x1B7C,0x019D,0x1A3C,0x125D,0x187D,0x12A1,0x1AC1,0x1AE3,0x1104,0x1B25,0x1146,0x1B67,//30
	0x1988,0x002A,0x1A49,0x106A,0x1A6B,0x128C,0x18AC,0x1ACE,0x12EF,0x190F,0x1331,0x1951,
	0x1B73,0x0994,0x1834,0x1256,0x1876,0x1298,0x18B8,0x1ADA,0x12FB,0x191B,0x133D,0x1B5D,
	0x1981,0x0022,0x1841,0x1062,0x1883,0x12A5,0x18C5,0x1AE7,0x1108,0x1B29,0x134A,0x1B6A,
	0x196B,0x038D,0x182B,0x124D,0x186D,0x108F,0x1AB0,0x18D1,0x10F3,0x1B14,0x1335,0x1B55,
	0x1976,0x0398,0x1A36,0x1057,0x1A78,0x1099,0x18BA,0x1ADC,0x10FD,0x1921,0x1342,0x1962,//35
	0x1B84,0x0A25,0x1A44,0x1065,0x1A86,0x10A7,0x18C8,0x1ACA,0x10EB,0x190C,0x132E,0x194E,
	0x1B70,0x0391,0x1A2F,0x1050,0x1A71,0x1292,0x18B2,0x18D4,0x12F6,0x1916,0x1138,0x1B59,
	0x197A,0x039C,0x1A3A,0x105B,0x1A7C,0x129D,0x18BD,0x1AE1,0x1303,0x1923,0x1145,0x1B66,
	0x1987,0x0229,0x1A47,0x1068,0x1A89,0x12AA,0x18AA,0x1ACC,0x10ED,0x1B0E,0x112F,0x1950,
	0x1B72,0x0993,0x1A33,0x1054,0x1A75,0x1296,0x18B6,0x1AD8,0x10F9,0x1B1A,0x133B,0x195B,//40
	0x1B7D,0x0021,0x183D,0x1261,0x1A82,0x10A3,0x1AC4,0x18E5,0x1307,0x1B27,0x1348,0x1968,
	0x1B8A,0x002B,0x1A4A,0x104B,0x186C,0x128E,0x18AE,0x1AD0,0x10F1,0x1B12,0x1333,0x1953,
	0x1B75,0x0396,0x1834,0x1256,0x1876,0x1098,0x1AB9,0x18DA,0x10FC,0x1B1D,0x133E,0x1961,
	0x1B82,0x0A23,0x1842,0x1264,0x1884,0x10A6,0x1AC7,0x18E8,0x10EA,0x1B0B,0x112C,0x1B4D,
	0x1B6E,0x038F,0x1A2D,0x104E,0x1A6F,0x1090,0x18B1,0x1AD3,0x10F4,0x1915,0x1337,0x1957,//45
	0x1B79,0x039A,0x1A38,0x1059,0x1A7A,0x109B,0x1ABC,0x18DD,0x1301,0x1922,0x1344,0x1964,
	0x1B86,0x0227,0x1845,0x1267,0x1A87,0x10A8,0x1AA9,0x18CA,0x12EC,0x190C,0x112E,0x1B4F,
	0x1970,0x0B92,0x1831,0x1253,0x1A73,0x1094,0x1AB5,0x1AD6,0x10F7,0x1B18,0x1139,0x195A,
	0x1B7C,0x019D,0x1A3C,0x105D,0x1A7E,0x12A2,0x1AC2,0x18E3,0x1305,0x1925,0x1347,0x1B67,
	0x1988,0x002A,0x1A49,0x106A,0x1A6B,0x108C,0x1AAD,0x18CE,0x12F0,0x1B10,0x1131,0x1B52,//50
	0x1B73,0x0194,0x1833,0x1255,0x1875,0x1297,0x18B7,0x18D9,0x12FB,0x1B1B,0x113C,0x1B5D,
	0x1B7E,0x0A21,0x1841,0x1062,0x1883,0x12A5,0x18C5,0x18E7,0x1309,0x1909,0x132B,0x1B4B,
	0x1B6C,0x018D,0x1A2C,0x124D,0x186D,0x108F,0x1AB0,0x18D1,0x10F3,0x1B14,0x1135,0x1B56,
	0x1B77,0x0398,0x1836,0x1258,0x1878,0x129A,0x18BA,0x1ADC,0x10FD,0x1921,0x1142,0x1B63,
	0x1B84,0x0025,0x1A44,0x1265,0x1885,0x12A7,0x18C7,0x1AC9,0x10EA,0x190B,0x132D,0x194D,//55
	0x1B6F,0x0990,0x1A30,0x1251,0x1871,0x1293,0x1AB3,0x18D4,0x12F6,0x1916,0x1138,0x1B59,
	0x197A,0x039C,0x183A,0x125C,0x187C,0x129E,0x1ABE,0x1AE2,0x1103,0x1B24,0x1145,0x1B66,
	0x1987,0x0229,0x1847,0x1269,0x1889,0x128B,0x18AB,0x1ACD,0x12EE,0x190E,0x1330,0x1950,
	0x1B72,0x0193,0x1A32,0x1053,0x1A74,0x1095,0x1AB6,0x18D7,0x12F9,0x1919,0x133B,0x1B5B,
	0x197C,0x0B9E,0x183D,0x1261,0x1A82,0x10A3,0x18C4,0x1AE6,0x1107,0x1B28,0x1349,0x1B69,//60
	0x198A,0x022C,0x1A4A,0x106B,0x186C,0x128E,0x18AE,0x18D0,0x12F2,0x1912,0x1334,0x1B54,
	0x1B75,0x0196,0x1A35,0x1256,0x1876,0x1098,0x1AB9,0x18DA,0x10FC,0x1B1D,0x1141,0x1B61,
	0x1B83,0x0224,0x1A42,0x1063,0x1A84,0x10A5,0x1AC6,0x18E7,0x10E9,0x1B0A,0x112B,0x1B4C,
	0x196D,0x0B8F,0x1A2E,0x124F,0x186F,0x1291,0x18B1,0x1AD3,0x10F4,0x1915,0x1337,0x1957,
	0x1B79,0x019A,0x1A39,0x125A,0x187A,0x129C,0x1ABC,0x18DD,0x1302,0x1922,0x1344,0x1964,//65
	0x1B86,0x0027,0x1A46,0x1067,0x1A88,0x12A9,0x18A9,0x1ACB,0x10EC,0x1B0D,0x112E,0x1B4F,
	0x1970,0x0392,0x1830,0x1252,0x1872,0x1294,0x18B4,0x1AD6,0x12F7,0x1917,0x1339,0x1959,
	0x1B7B,0x099C,0x1A3C,0x105D,0x1A7E,0x10A2,0x1AC3,0x1AE4,0x1105,0x1B26,0x1347,0x1967,
	0x1B89,0x002A,0x1A49,0x106A,0x1A8B,0x108C,0x18AD,0x1ACF,0x10F0,0x1B11,0x1332,0x1B52,
	0x1973,0x0395,0x1833,0x1255,0x1875,0x1297,0x18B7,0x18D9,0x12FB,0x191B,0x133D,0x195D,//70
	0x1B81,0x0222,0x1A3E,0x1262,0x1882,0x12A4,0x18C4,0x18E6,0x1308,0x1908,0x132A,0x194A,
	0x1B6C,0x0B8D,0x1A2C,0x104D,0x1A6E,0x108F,0x1AB0,0x18D1,0x10F3,0x1B14,0x1135,0x1956,
	0x1B78,0x0399,0x1A37,0x1058,0x1A79,0x129A,0x18BA,0x1ADC,0x10FD,0x1921,0x1142,0x1963,
	0x1B85,0x0226,0x1844,0x1266,0x1A86,0x10A7,0x1AC8,0x18C9,0x12EB,0x190B,0x132D,0x194D,
	0x1B6F,0x0190,0x1A2F,0x1050,0x1A71,0x1092,0x1AB3,0x1AD4,0x10F5,0x1B16,0x1137,0x1B58,//75
	0x1979,0x0B9B,0x183A,0x125C,0x187C,0x129E,0x18C1,0x18E2,0x1304,0x1B24,0x1145,0x1B66,
	0x1987,0x0229,0x1847,0x1269,0x1889,0x108B,0x1AAC,0x18CD,0x12EF,0x1B0F,0x1130,0x1B51,
	0x1B72,0x0193,0x1A32,0x1053,0x1A74,0x1095,0x18B6,0x1AD8,0x10F9,0x1B1A,0x113B,0x1B5C,
	0x1B7D,0x039E,0x183C,0x125E,0x1881,0x10A2,0x18C3,0x1AE5,0x1106,0x1B27,0x1148,0x1B69,
	0x1B8A,0x0A2B,0x184A,0x126C,0x186C,0x128E,0x18AE,0x18D0,0x10F2,0x1B13,0x1134,0x1B55,//80
	0x1B76,0x0397,0x1835,0x1257,0x1A77,0x1098,0x1AB9,0x18DA,0x10FC,0x1B1D,0x1141,0x1B62,
	0x1B83,0x0024,0x1A43,0x1264,0x1884,0x12A6,0x18C6,0x1AE8,0x10E9,0x1B0A,0x112B,0x194C,
	0x1B6E,0x038F,0x182D,0x124F,0x1A6F,0x1090,0x1AB1,0x18D2,0x12F4,0x1914,0x1336,0x1956,
	0x1B78,0x0999,0x1A39,0x105A,0x1A7B,0x109C,0x1ABD,0x1ADE,0x1302,0x1922,0x1344,0x1964,
	0x1B86,0x0027,0x1846,0x1268,0x1888,0x12AA,0x1AAA,0x18CB,0x12ED,0x190D,0x132F,0x1B4F,//85
	0x1970,0x0392,0x1830,0x1052,0x1A73,0x1094,0x1AB5,0x18D6,0x12F8,0x1B18,0x1139,0x1B5A,
	0x1B7B,0x019C,0x1A3B,0x105C,0x1A7D,0x10A1,0x1AC2,0x18E3,0x1305,0x1925,0x1347,0x1B67,
	0x1B88,0x0829,0x1A49,0x106A,0x1A8B,0x108C,0x18AD,0x18CF,0x12F1,0x1911,0x1333,0x1B53,
	0x1B74,0x0195,0x1A34,0x1255,0x1875,0x1297,0x18B7,0x18D9,0x10FB,0x1B1C,0x113D,0x1B5E,
	0x1B81,0x0223,0x1A41,0x1262,0x1882,0x12A4,0x18C4,0x18E6,0x1308,0x1908,0x112A,0x1B4B,//90
	0x196C,0x038E,0x1A2C,0x124D,0x186D,0x128F,0x18AF,0x1AD1,0x10F2,0x1B13,0x1134,0x1955,
	0x1B77,0x0998,0x1A38,0x1259,0x1879,0x129B,0x1ABB,0x18DC,0x12FE,0x1921,0x1142,0x1963,
	0x1B85,0x0026,0x1A45,0x1066,0x1A87,0x12A8,0x18C8,0x1ACA,0x12EB,0x190B,0x132D,0x194D,
	0x1B6F,0x0190,0x182F,0x1251,0x1871,0x1293,0x18B3,0x1AD5,0x12F6,0x1916,0x1338,0x1B58,
	0x1979,0x039B,0x1839,0x105B,0x1A7C,0x109D,0x1ABE,0x1AE2,0x1103,0x1B24,0x1345,0x1B65,//95
	0x1986,0x0A28,0x1847,0x1269,0x1889,0x108B,0x1AAC,0x18CD,0x10EF,0x1B10,0x1331,0x1B51,
	0x1972,0x0394,0x1A32,0x1053,0x1A74,0x1095,0x18B6,0x18D8,0x12FA,0x191A,0x133C,0x1B5C,
	0x197D,0x0221,0x1A3D,0x125E,0x1881,0x10A2,0x18C3,0x18E5,0x1307,0x1927,0x1349,0x1969,
	0x1B8B,0x022C,0x1A4A,0x104B,0x1A6C,0x108D,0x1AAE,0x18CF,0x10F1,0x1B12,0x1133,0x1B54}; //2099

void Solar2Lunar(unsigned char SolarDay, unsigned char SolarMonth, unsigned int SolarYear,
								 unsigned char * LunarDay, unsigned char * LunarMonth, unsigned int * LunarYear)
{	
	unsigned char N_AL_DT_DL; 
	unsigned char T_AL_DT_DL; 
	unsigned char SN_CT_AL;
	unsigned char TN_B_THT;
	unsigned char N_AL_DT_DL_TT;
	unsigned char T_AL_DT_DL_TT;

	union LUNAR_RECORD lr;

	lr.Word = LUNAR_CALENDAR_LOOKUP_TABLE[(SolarYear-BEGINNING_YEAR)*12+SolarMonth -1]; 
	N_AL_DT_DL = lr.Info.N_AL_DT_DL;
	T_AL_DT_DL = lr.Info.T_AL_DT_DL;
	SN_CT_AL = lr.Info.SN_CT_AL + 29;
	TN_B_THT =  lr.Info.TN_B_THT;

	lr.Word = LUNAR_CALENDAR_LOOKUP_TABLE[(SolarYear-BEGINNING_YEAR)*12+SolarMonth];
	N_AL_DT_DL_TT = lr.Info.N_AL_DT_DL;
	T_AL_DT_DL_TT = lr.Info.T_AL_DT_DL;

	// Tinh ngay & thang
	if(N_AL_DT_DL == SN_CT_AL && N_AL_DT_DL_TT == 2)
	{
	 	if(SolarDay==1)
		{
		 	(*LunarDay) = N_AL_DT_DL;
			(*LunarMonth) = T_AL_DT_DL;
		}
		else if(SolarDay==31)
		{
		 	(*LunarDay) = 1;
			(*LunarMonth) = T_AL_DT_DL_TT;
		}
		else
		{
		 	(*LunarDay) = SolarDay - 1;
			if(TN_B_THT)
			{
				(*LunarMonth) = T_AL_DT_DL;
			}
			else
			{
			 	(*LunarMonth) = T_AL_DT_DL==12?1:(T_AL_DT_DL + 1);
			} 
		}
	}
	else
	{
	 	(*LunarDay) = SolarDay + N_AL_DT_DL - 1;
		if((*LunarDay)<= SN_CT_AL)
		{
		 	(*LunarMonth) = T_AL_DT_DL;
		}
		else
		{
		 	(*LunarDay) -= SN_CT_AL;

			(*LunarMonth) = T_AL_DT_DL + 1 - TN_B_THT;
			if((*LunarMonth) == 13) (*LunarMonth) = 1;
		}
	}

	// Tinh Nam
	if(SolarMonth >= (*LunarMonth))
	{
	 	(*LunarYear) = SolarYear;
	}
	else
	{
	 	(*LunarYear) = SolarYear - 1;
	}
}	

/*========= Chon Led 7 doan ==========*/

//========= 6 Led 48x70 =========>

void Led1(void)	{led1=0;led2=led3=led4=1;led5=led6=0;}
void Led2(void)	{led2=0;led1=led3=led4=1;led5=led6=0;}
void Led3(void)	{led3=0;led1=led2=led4=1;led5=led6=0;}
void Led4(void)	{led4=0;led1=led2=led3=1;led5=led6=0;}
void Led5(void)	{led5=1;led1=led2=led3=led4=1;led6=0;}
void Led6(void)	{led6=1;led1=led2=led3=led4=1;led5=0;}
//<===========


/*/========= 14 Led 48x70 V1.2 & V1.3 =========>
void Led1(void)		
	{led1=0;
	led2=led3=led4=1;
	led5=led6=led7=led8=led9=led10=led11=led12=led13=led14=0;}
void Led2(void)		
	{led2=0;
	led1=led3=led4=1;
	led5=led6=led7=led8=led9=led10=led11=led12=led13=led14=0;}
void Led3(void)		
	{led3=0;
	led1=led2=led4=1;
	led5=led6=led7=led8=led9=led10=led11=led12=led13=led14=0;}
void Led4(void)		
	{led4=0;
	led1=led2=led3=1;
	led5=led6=led7=led8=led9=led10=led11=led12=led13=led14=0;}
void Led5(void)
	{led1=led2=led3=led4=1;
	led5=1;
	led6=led7=led8=led9=led10=led11=led12=led13=led14=0;}
void Led6(void)
	{led1=led2=led3=led4=1;
	led6=1;
	led5=led7=led8=led9=led10=led11=led12=led13=led14=0;}
void Led7(void)
	{led1=led2=led3=led4=1;
	led7=1;
	led5=led6=led8=led9=led10=led11=led12=led13=led14=0;}
void Led8(void)	
	{led1=led2=led3=led4=1;
	led8=1;
	led5=led6=led7=led9=led10=led11=led12=led13=led14=0;}
void Led9(void)	
	{led1=led2=led3=led4=1;
	led9=1;
	led5=led6=led7=led8=led10=led11=led12=led13=led14=0;}
void Led10(void)
	{led1=led2=led3=led4=1;
	led10=1;
	led5=led6=led7=led8=led9=led11=led12=led13=led14=0;}
void Led11(void)
	{led1=led2=led3=led4=1;
	led11=1;
	led5=led6=led7=led8=led9=led10=led12=led13=led14=0;}
void Led12(void)
	{led1=led2=led3=led4=1;
	led12=1;
	led5=led6=led7=led8=led9=led10=led11=led13=led14=0;}
void Led13(void)
	{led1=led2=led3=led4=1;
	led13=1;
	led5=led6=led7=led8=led9=led10=led11=led12=led14=0;}
void Led14(void)
	{led1=led2=led3=led4=1;
	led14=1;
	led5=led6=led7=led8=led9=led10=led11=led12=led13=0;}
//<=============
*/

void delay(unsigned int time)
	{while(time--);}

void Beep(unsigned char solan,sotieng)	  
	{int j,k;			  
	for(j=0;j<solan;j++)
		{for(k=0;k<sotieng;k++)
			{Loa=1;delay(5000);
		  	Loa=0;delay(2000);
			}		
		delay(20000);delay(20000);
		}
	}	
//============================//
//            I2C			  //
//============================//

void Batdau_I2C(void)
	{SCL	= 1;	SCL = 0;
	SDA = 1;	SCL = 1;
	delay(2);
	SDA = 0; delay(2);
	SCL = 0; delay(2);}

void Dung_I2C(void)
	{SCL = 1;	SCL = 0;
	SDA = 0;	delay(2);
	SCL = 1;	delay(2);
	SDA = 1;}

bit Ghi_I2C(unsigned char dat)
	{unsigned char i;	
	for (i=0;i<8;i++)
		{SDA = (dat & 0x80) ? 1:0;
		SCL=1;SCL=0;
		dat<<=1;}
	SCL = 1;	delay(2);
	SCL = 0;
	return dat;}

unsigned char Doc_I2C(void)
	{bit rd_bit;	
	unsigned char i, dat;
	dat = 0x00;	
	for(i=0;i<8;i++)	 	/* For loop read data 1 byte */
		{delay(2);
		SCL = 1;	 		/* Set SCL */
		delay(2); 
		rd_bit = SDA;	 	/* Keep for check acknowledge	*/
		dat = dat<<1;	
		dat = dat | rd_bit;	/* Keep bit data in dat */
		SCL = 0;}	 		/* Clear SCL */
	return dat;}

//===============================//
//            DS1307             //
//===============================//

unsigned char Doc_DS1307(unsigned char diachi) 
	{unsigned int temp,ret;	
	Batdau_I2C(); 				/* Start i2c bus */
	Ghi_I2C(Diachi_1307); 		/* Connect to DS1307 */
	Ghi_I2C(diachi);			/* Request RAM address on DS1307 */	
	Batdau_I2C();	 			/* Start i2c bus */
	Ghi_I2C(Diachi_1307+1);		/* Connect to DS1307 for Read */
	ret = Doc_I2C();	 		/* Receive data */
	Dung_I2C();
	temp = ret;	 				
	ret = (((ret/16)*10)+ (temp & 0x0f));	 /*BCD to HEX for Led 7seg*/
	return ret;}

void Ghi_DS1307(unsigned char diachi,unsigned char dat)
	{unsigned int temp;
	temp = dat ;	 			
	dat = (((dat/10)*16)|(temp %10));	/*HEX to BCD for Led 7seg*/
	Batdau_I2C(); 						/* Start i2c bus */
	Ghi_I2C(Diachi_1307); 				/* Connect to DS1307 */
	Ghi_I2C(diachi);	 				/* Request RAM diachiess on DS1307 */	
	Ghi_I2C(dat);						/* Connect to DS1307 for Read */
	Dung_I2C();}

//=============================================== ===================/				

void Xuat_1Hz_DS1307()
	{Batdau_I2C(); 			/* Start i2c bus */
	Ghi_I2C(Diachi_1307); 	/* Connect to DS1307 */
	Ghi_I2C(0x07);   		//vi tri con tro RTC
	Ghi_I2C(0x10);
	Dung_I2C();}

void Caidat_Timer(void)		// Setup timer 0 va timer 1 
	{TMOD=0x11; 			// timer0 & timer1 set che do 1
	TH0=-1000/256; TL0=-1000%256;
	TH1=0x3C; TL1=0xAF;
	ET1=1;ET0=1;	
	EA=1;
	TF0=0;TF1=0;
	TR0=1;TR1=1;}

//======Functions ds18b20 delay (12MHz crystal oscillator £©=======/ 

void delay_18B20(unsigned int i)
	{
	while(i--);
	}

//============ds18b20 initialization function ================/

void Init_DS18B20(void) 
	{
	 Ds18B20 = 1;     //Ds18B20 reset
	 delay_18B20(8);	//Slight delay
	 Ds18B20 = 0;     //SCM will be pulled down Ds18B20
	 delay_18B20(80); //Accurate delay Greater than 480us
	 Ds18B20 = 1;     //Pulled the bus
	 delay_18B20(14);
	 Ktra_DS18B20=Ds18B20;       //After slight delay is initialized if x = 0 x = 1 is initialized successfully defeat
	 delay_18B20(20);
	}

//============ds18b20 read a byte============/  

unsigned char ReadOneChar(void)
	{
	unsigned i=0;
	unsigned dat = 0;
	for (i=8;i>0;i--)
	 	{
		Ds18B20 = 0; // To the pulse signal
		dat>>=1;
		Ds18B20 = 1; // To the pulse signal
		if(Ds18B20)
		dat|=0x80;
		delay_18B20(4);
	 	}
 	return(dat);
	}

//*************ds18b20 write a byte****************=/  

void WriteOneChar(unsigned dat)
	{
 	unsigned char i=0;
 	for (i=8; i>0; i--)
 		{
  		Ds18B20 = 0;
 		Ds18B20 = dat&0x01;
    	delay_18B20(5);
 		Ds18B20 = 1;
    	dat>>=1;
 		}
	}

//**************The current temperature reading ds18b20************=/

void ReadTemperature(void)
	{
	unsigned int a=0;
	unsigned int b=0;
	EA=0;
	Init_DS18B20();
if (Ktra_DS18B20==0)
	{
	WriteOneChar(0xCC);    	// Skip read serial number column number of operations
	WriteOneChar(0x44); 	// Start temperature conversion
	delay_18B20(80);       // this message is wery important

	Init_DS18B20();
	WriteOneChar(0xCC); 	//Skip read serial number column number of operations
	WriteOneChar(0xBE); 	//Read the temperature register, etc. (a total of 9 registers readable) is the temperature of the first two
	delay_18B20(80);

	a=ReadOneChar();    	//Read the low temperature
	b=ReadOneChar();   		//Read the high temperature

   	nhietdo=((b*256+a)>>4);    //In addition to the current collection temperature of 16 was the actual temperature
	nhietdo2=(a&0x0f)*100/16;   	
	}
else
	{
   	nhietdo=nhietdo2=99;   	
	}
	EA=1;
	}
//**********************************************************************//

//=========Kiem tra phim nhan.===============
void Ktra_phim(void)	 	

	{if(!Mode)
		{while(!Mode);
		mode++;
		if(Cai_Alarm==0 && mode>9) mode=0; 			// Cai dat gio
		if(Cai_Alarm>0 && mode>2) mode=1;			// Cai dat Alarm
		}

// Gio - Phut - Giay
	if(mode==1)
		{if (Cai_Alarm==0) so1=gio;
		if(!Tang) {while(!Tang);so1++;if(so1>=24) so1=0;}
		if(!Giam) {while(!Giam);if(so1>0) so1--;else so1=23;}
		if(Cai_Alarm==0)Ghi_DS1307(Gio,so1);			// Ghi gio
		if(Cai_Alarm>0)Ghi_DS1307(Cai_Alarm*2+9,so1);}	// Ghi gio alarm
	if(mode==2)
		{if(!Tang) {while(!Tang);so2++;if(so2>=60) so2=0;}
		if(!Giam) {while(!Giam);if(so2>0) so2--;else so2=59;}
		if(Cai_Alarm==0)Ghi_DS1307(Phut,so2);				// Ghi phut
		if(Cai_Alarm>0)Ghi_DS1307(Cai_Alarm*2+10,so2);}	// Ghi phut alarm
	if(mode==3)
		{if(!Tang) {while(!Tang);so3++;if(so3>=60) so3=0;}
		if(!Giam) {while(!Giam);if(so3>0) so3--;else so3=59;}
		Ghi_DS1307(Giay,so3);}
// Ngay - Thang - Nam
	if(mode==4)		
		{if(!Tang) {while(!Tang);ngay++;if(ngay>=32) ngay=1;}
		if(!Giam) {while(!Giam);ngay--;if(ngay==0) ngay=31;}
		Ghi_DS1307(Ngay,ngay);}
	if(mode==5)
		{if(!Tang) {while(!Tang);thang++;if(thang>=13) thang=1;}
		if(!Giam) {while(!Giam);thang--;if(thang==0) thang=12;}
		Ghi_DS1307(Thang,thang);}
 	if(mode==6)
		{if(!Tang) {while(!Tang);nam++;if(nam>=100) nam=0;}
		if(!Giam) {while(!Giam);if(nam>0) nam--;else nam=99;}
		Ghi_DS1307(Nam,nam);}
// Thu
	if(mode==7)
		{if(!Tang){while(!Tang);thu++;if(thu>7) thu=1;}
		if(!Giam){while(!Giam);thu--;if(thu==0) thu=7;}
		Ghi_DS1307(Thu,thu);}
// Tu dieu chinh gio
 	if(mode==8)	   // Chon che do : =0 khong thay doi; =1 Tang ,=2 Giam  
		{if(!Tang){while(!Tang);tang_giam++;if(tang_giam>2) tang_giam=0;}
		if(!Giam) {while(!Giam);if(tang_giam>0) tang_giam--;else tang_giam=2;}		
		Ghi_DS1307(Tang_Giam,tang_giam);}
 	if(mode==9)	  //So giay can chinh = 0 -> 59s
		{if(!Tang){while(!Tang);chinh_gio++;if(chinh_gio>59) chinh_gio=0;}
		if(!Giam) {while(!Giam);if(chinh_gio>0) chinh_gio--;else chinh_gio=59;}		
		Ghi_DS1307(Chinh_Gio,chinh_gio);}
	}

//*** Cai dat Alarm ********************************************************************
void Caidat_Baothuc(void)
	{if(!Alarm)
		{while(!Alarm);
		if(mode>0 && Cai_Alarm==0) mode=0;		   // Dang chinh gio nhan Alarm => thoat
		else
			{Cai_Alarm++;
			if(Cai_Alarm>So_Alarm) 	 	
				{while(!Alarm);
				Cai_Alarm=0;
				mode=0;}			// Tro ve hien thi dong ho va tat nhay			
			}
		}
	}

void Ktra_Baothuc(void)
	{unsigned char gio_Alarm,phut_Alarm;								
	for(loop=13;loop<=10+So_Alarm*2;loop++)		
		{gio_Alarm=Doc_DS1307(loop);
		phut_Alarm=Doc_DS1307(loop+1);
		if(gio_Alarm==0 && phut_Alarm==0);
		else if(gio_Alarm==gio && phut_Alarm==phut && giay==0)Beep(10,5);			
		loop++;}
	}

void Baothuc_1_lan(void)
	{unsigned char gio_Alarm,phut_Alarm;								
	gio_Alarm=Doc_DS1307(11);
	phut_Alarm=Doc_DS1307(12);
	if(gio_Alarm==0 && phut_Alarm==0);
	else	
		{if(gio_Alarm==gio && phut_Alarm==phut && giay==0)
			{Ghi_DS1307(11,0x00);Ghi_DS1307(12,0x00);
			Beep(10,5);			
			}
		}
	}
//========= Hien thi ra Led 7 thanh ====================
//***********************************************************************

void Ngat_3_T1(void) interrupt 3 //ngat timer 1 chay dong ho
	{TR1=0;
	TF1=0;
	TH1=0x3C; 		// nap lai gia tri cho thanh ghi 
	TL1=0xAF;
	time++;	
	if(time==5)
		{time=0;
		Lay_gio=1;
		Nhay_Led++; 
		if(Nhay_Led==2)	Nhay_Led=0;
		}
	TR1=1;}	

//==================================/
// Dung ngat quet de hien thi so
void Ngat_1_T0(void) interrupt 1	 // Dung ngat timer 0 de quet led
	{TR0=0;
	TF0=0;
	TH0=0xFC; 	//	TH0=-1000/256; // Nap lai gia tri cho thanh ghi 
	TL0=0x18;	//	TL0=-1000%256;
	index++;
// ===== Hien thi Gio Phut Giay ===============
	if(mode<=3)
		{
	//Hien gio	- Ngay - Nhiet do
		if(index==1)
			if(mode==1 && Nhay_Led==1){index++;index++;}
		else	
			{hien_thi=so1;
			if(mode==0 && Cai_Alarm==0 && Gio12==12 && hien_thi>12 && (mode_hien==1 | (mode_hien==4 && nhietdo==99))) hien_thi=hien_thi-12;
				P0=0xff;
			Led1();			
			if(hien_thi<10) P0=0xFF;		//neu <10 thi tat khong hien
			else P0=Ma_7doan[hien_thi/10];	//xuat hang chuc		
			delay(Tre_L);
			}
		if(index==2) 
			{P0=0xff;
			Led2();			
			P0=Ma_7doan[hien_thi%10];  //xuat hang don vi
			delay(Tre_L);
			}
	//Hien phut	 - Thang - chu do C
		if(index==3)
			{if(mode==2 && Nhay_Led==1){index++;index++;}
			else
				{hien_thi=so2;
				P0=0xff;
				Led3();
				if(Cai_Alarm==0) 
					{
					if(mode_hien<=3)P0=Ma_7doan[hien_thi/10];	
					if(mode_hien==4)
						{
						if(nhietdo==99)P0=Ma_7doan[hien_thi/10];	
						else P0=0x1C;		// ky tu do C		
						}
					}
				else P0=Ma_7doan[hien_thi/10];
				delay(Tre_L);
				}
			}
		if(index==4)
			{P0=0xff;
			Led4();
			if(mode_hien<=3)P0=Ma_7doan[hien_thi%10];			
			if(mode_hien==4)
				{
				if(nhietdo==99 | Cai_Alarm>0) P0=Ma_7doan[hien_thi%10];			
				else P0=0x46;			   // chu C
				}
			delay(Tre_L);
			} 
	//Hien giay	 - Thu - So le nhiet do
		if(index==5) 
			{if(mode==3 && Nhay_Led==1)index=0;//{index++;index++;}
			else
				{hien_thi=so3; //giay;
				P0=0xff;
				Led5();
				if(Cai_Alarm==0) 
					{
					if(mode_hien==1 | mode_hien==4) P0=Ma_7doan[hien_thi/10];
					if(mode_hien==2)	
						{
						if(so3>1)P0=0x87;				  // chu t
						if(so3==1)P0=0x46;				  // chu C
						}
					if(mode_hien==3)P0=0x88;				  // chu A
					}						
				if(Cai_Alarm>1)P0=0xC7;					  // Hien chu l		
				if(Cai_Alarm==1)P0=Ma_7doan[Cai_Alarm];	  // Hien so 1
				delay(Tre_N);								  		 
				}
			}
		if(index==6)
			{P0=0xff;
			Led6();
			if(Cai_Alarm==0)
				{			
				if(mode_hien==1 | mode_hien==4) P0=Ma_7doan[hien_thi%10];
				if(mode_hien==2)
					{
					if(so3==1)P0=0xAB;					  // chu n
					if(so3>1)P0=Ma_7doan[hien_thi%10];
					}
				if(mode_hien==3)P0=0xC7;				  // chu L				
				}						 				
			if(Cai_Alarm==1)	P0=0xC7;				  	  // Hien chu l	
			if(Cai_Alarm>1)	P0=Ma_7doan[Cai_Alarm -1];	  // Hien so lan bao thuc
			delay(Tre_N);			
			index=0;
			}
		}
//==Hien thi ngay thang nam=========================
	if(mode>3 && mode<=6)
		{
	//Hien Ngay	
		if(index==7)
			if(mode==4 && Nhay_Led==1){index++;index++;}
		else	
			{hien_thi=ngay;
			P0=0xff;
			Led1();
			P0=Ma_7doan[hien_thi/10];		//lay so du sau khi chia 10
			delay(Tre_L);
			}
		if(index==8) 
			{P0=0xff;
			Led2();
			P0=Ma_7doan[hien_thi%10];  //xuat gia tri hang chuc
			delay(Tre_L);
			}
	//Hien Thang
		if(index==9)
			{if(mode==5 && Nhay_Led==1){index++;index++;}
			else
				{hien_thi=thang;
				P0=0xff;
				Led3();
				P0=Ma_7doan[hien_thi/10];		//lay so du sau khi chia 10
				delay(Tre_L);
				}
			}
		if(index==10)
			{P0=0xff;
			Led4();
			P0=Ma_7doan[hien_thi%10];  //xuat gia tri hang chuc
			delay(Tre_L);
			} 
	//Hien nam
		if(index==11) 
			{if(mode==6 && Nhay_Led==1)index=0; //{index++;index++;}
			else
				{hien_thi=nam;
				P0=0xff;
				Led5();
				P0=Ma_7doan[hien_thi/10];			
				delay(Tre_N);} 
			}
		if(index==12)
			{P0=0xff;
			Led6();
			P0=Ma_7doan[hien_thi%10];
			delay(Tre_N); 
			index=0;
			}
		}

 //=== Hien thu ==============================
	if (mode>6)
		{
		if(index==13) 
			{if(mode==7 && Nhay_Led==1){index++;index++;}
			else
				{hien_thi=thu;
				P0=0xff;
				Led1();
				if(hien_thi==1)P0=0x46;	else P0=0x87;
				delay(Tre_L);} 
			}						
		if(index==14) 
			{P0=0xff;
			Led2();
			if(hien_thi==1)P0=0xab;						
			else P0=Ma_7doan[hien_thi];			
			delay(Tre_L);
			}

//=== Hien so giay tu dong dieu chinh ==============================
		if(index==15)
			{if(mode==8 && Nhay_Led==1){index++;index++;}
			else
				{hien_thi=tang_giam;
				P0=0xff;
				Led3();
				if(tang_giam==0) P0=0x2b; // Khong dieu chinh
				if(tang_giam==1) P0=0x63; // Dieu chinh tang
				if(tang_giam==2) P0=0x21; // Dieu chinh giam
				delay(Tre_L);
				}
			}
		if(index==16)
			{P0=0xff;
			Led4();
			if(tang_giam==0) P0=0x23; // Khong dieu chinh
			if(tang_giam==1) P0=0x0c; // Dieu chinh tang
			if(tang_giam==2) P0=0x2b; // Dieu chinh giam
			delay(Tre_L);
			}

		if(index==17)
			{if(mode==9 && Nhay_Led==1){index=0;}
			else
				{hien_thi=chinh_gio;
				P0=0xff;
				Led5();
				P0=Ma_7doan[hien_thi/10];
				delay(Tre_N);
				}
			}
		if(index==18)
			{P0=0xff;
			Led6();
			P0=Ma_7doan[hien_thi%10];
			delay(Tre_N);
			index=0;
			}
	   	}
	TR0=1;
	}

//========= Khoi tao DS1307 lan dau =================
void Ktra_RTC(void)
	{
	unsigned char temp;
	temp=0;
	Batdau_I2C();
	Ghi_I2C(Diachi_1307);  // truy xuat vao dia chi cua DS1307
	Ghi_I2C(0x08);		   // doc du lieu tu thanh ghi co dia chi 0x08 (vi tri ram dau tien, 7 dia chi dau danh cho luu thoi gian)
	Batdau_I2C();
	Ghi_I2C(Diachi_1307+1);
	temp = Doc_I2C();	   //con tro dang tro toi dia chi 0x08 chua du lieu flag (co?`) xem da cai dat hay chua
	Dung_I2C();
	
	Led1();
	P0=Ma_7doan[temp/10];
	delay(20000);
 	Led2();
	P0=Ma_7doan[temp%10];
	delay(20000);

	if(temp!=0x00)
	//if(temp!='c')
		{
		//  neu gia tri thu 8 nhan duoc khac voi co bang 0 khi cai dat gio
		//  thi tuc la lan dau duoc khoi tao, ta se chon gia tri ghi vao ban dau theo y minh 
		//  Ghi thoi gian vao RTC 21:45:00 T3 21/04/2009
		Ghi_DS1307(0,0x00);Ghi_DS1307(1,0x2D);	   	// giay 00, phut 45
		Ghi_DS1307(2,0x15);Ghi_DS1307(3,0x03);		// gio 21, thu 3
		Ghi_DS1307(4,0x15);Ghi_DS1307(5,0x04);		// ngay 21, thang 04
		Ghi_DS1307(6,0x09);Ghi_DS1307(7,0x10);		// nam 09, xuat tan so 1Hz ra chan 7 cua RTC
		Ghi_DS1307(8,0x00);
//		Ghi_DS1307(8,'c');
		Ghi_DS1307(9,24);				  // Luu mode 12 / 24 gio	   
		Ghi_DS1307(10,0x00);			  // De danh chua lam gi
		// Bo nho bao thuc
		Ghi_DS1307(11,0x15);Ghi_DS1307(12,0x2d);			 // 21h45
		for(temp=13;temp<=63;temp++) Ghi_DS1307(temp,0x00);  // Xoa het cac bo nho cua DS1307
		Beep(1,12);	 // Beep tieng dai - Thoi gian tra ve mac dinh
		}
	else Beep(2,2);	// Beep 2 lan 2 tieng - Thoi gian van con luu trong RTC
	}

//===========CHUONG TRINH CHINH==========================================/
void main()
	{
	Beep(1,1);	// Beep 1 lan 1 tieng	
	Ktra_RTC();
	Loa=0;
	time=index=0;
	mode=Cai_Alarm=0;
	Lay_gio=0;
	Dieuchinh=1;
	Caidat_Timer();
	Xuat_1Hz_DS1307();
	mode_hien=0;
	docnhietdo=1;

//==========Cai dat gio tam de test = 00h00m00s =================
      //Ghi_DS1307(0,30);Ghi_DS1307(1,59);Ghi_DS1307(2,23);
//===============================================================
	while(1)
	
	{	Ktra_phim();
 		Caidat_Baothuc();
		if(Lay_gio == 1)
			{if(Cai_Alarm==0)	 // Che do hien thi ngay gio
				{Lay_gio = 0;
				giay 	= Doc_DS1307(Giay);	phut 	= Doc_DS1307(Phut);	
				gio 	= Doc_DS1307(Gio);	thu 	= Doc_DS1307(Thu);
				ngay	= Doc_DS1307(Ngay);	thang	= Doc_DS1307(Thang);	
				nam 	= Doc_DS1307(Nam); 	Gio12 = Doc_DS1307(9);
				tang_giam=Doc_DS1307(Tang_Giam);
				chinh_gio=Doc_DS1307(Chinh_Gio);

				if(thu==0) {Ghi_DS1307(Thu,1);thu=1;}   // Sua loi thu = 0 khong hieu vi sao

//Dieu chinh gio
//*********************************************************
// tang_giam - mode dieu chinh tang giam
//			= 1 : chay cham ghi -> cong them giay
//			= 2 : chay nhanh giam thoi gian lai
// Chay nhanh -> giam gio //	
				if(phut>=1) Dieuchinh=1;
				if (Dieuchinh==1) 		
					{if(tang_giam==2)
						{if (gio ==0 && phut==0 && giay ==chinh_gio)
								{Ghi_DS1307(Giay,0x00);
								Dieuchinh=0;}		
						}
					}
						// Chay cham-> tang gio //
				if(tang_giam==1)
					{
					if (gio ==0 && phut==0 && giay ==0)	Ghi_DS1307(Giay,chinh_gio);								
					}							
//********************************************************			

				if(mode==0)
					{
					if (gio ==0 && phut==0 && giay >0 && giay <=chinh_gio) {}
					else	
						{
		//Gio - Phut - Giay
							if(giay<=8 |( giay>=15 && giay<=23)|( giay>=30 && giay<=38)|( giay>=45 && giay<=53)) 						
								{mode_hien=1; dk_nhay=1;} // Nhay dau cham giay
		//Ngay - Thang - Nam Duong lich
							if((giay>=9 && giay<=10) | (giay>=24 && giay<=25) | (giay>=39 && giay<=40) | (giay>=54 && giay<=55) )
								{mode_hien=2;dk_nhay=0;}
		//Ngay - Thang - Nam Am lich
							if((giay>=11 && giay<=12) | (giay>=26 && giay<=27) | (giay>=41 && giay<=42) | (giay>=56 && giay<=57) )
								{mode_hien=3;dk_nhay=0;}						
		//Nhiet do 			
							if((giay>=13 && giay<=14) | (giay>=28 && giay<=29) | (giay>=43 && giay<=44) | (giay>=58 && giay<59) )
								{
								mode_hien=4; 			
								dk_nhay=0;
								if(giay==13 | giay==28 | giay==43 | giay==58) 
									{if(docnhietdo==1)
										{
										ReadTemperature();
										docnhietdo=0;
										}
									}
								if((giay>13 && giay<=14) | (giay>28 && giay<=29) | (giay>43 && giay<=44) | (giay>58 && giay<59) ) docnhietdo=1;						
								}
							}
					}
				else mode_hien=1;
					
				if(mode_hien==1)
					{
					so1=gio;					
					so2=phut;
					so3=giay;
					}
					
				if(mode_hien==2)
					{					
					so1=ngay;
					so2=thang;
					so3=thu;
					}
				if(mode_hien==3) Solar2Lunar(ngay,thang,2000+nam,&so1,&so2,&so3);
					
				if(mode_hien==4)
					{if (nhietdo==99) // khong tim thay DS18B20
						{so1=gio;
						so2=phut;
						so3=giay;
						}
					else
						{					
						so1=nhietdo;
						so3=nhietdo2;
						}
					}
				}
			else  // Che do hien thi gio bao thuc
				{Lay_gio = 1;
				so1 	= Doc_DS1307(Cai_Alarm*2+9);	//gio va phut bao thuc Luu o nho tu 11 tro di cua DS1307
				so2 	= Doc_DS1307(Cai_Alarm*2+10);	
				}
			}
//**** Nhan Giam chon mode 12/24 gio *****************
		if(!Giam && mode==0 && Cai_Alarm==0)
			{while(!Giam);
			EA=0;			
			Gio12 	= Doc_DS1307(9);
			if(Gio12==12)Gio12=24;
			else Gio12=12;
			Ghi_DS1307(9,Gio12);
			for(loop=0;loop<200;loop++)			
				{if (Gio12==12)
					{P0=0xff;Led1();
					P0=Ma_7doan[1];
					delay(300);					
					P0=0xff;Led2();
					P0=Ma_7doan[2];
					delay(300);}
				if (Gio12==24)
					{P0=0xff;Led1();
					P0=Ma_7doan[2];
					delay(300);					
					P0=0xff;Led2();
					P0=Ma_7doan[4];
					delay(300);}				
				}
			EA=1;}			

// Kiem tra bao thuc va bao gio
			if(mode==0 && Cai_Alarm==0)
			{Baothuc_1_lan();
			if (Bao_Gio==0 && gio >=5 && gio<=22 && phut==0 && giay ==0)	// Bao gio tu 5 sang gio den 22 gio							
			{if(gio<12 || gio>12) // 12 gio trua khong bao
					{if(gio>12) Beep(gio-12,2); // Beep theo so gio (12 gio)
					else Beep(gio,2);		
					}
				}										
			
			if (Bao_Thuc==0) if(thu>1 && thu<7) Ktra_Baothuc(); // Bao gio thuc tu thu 2 den thu 6
			}
		}
	}