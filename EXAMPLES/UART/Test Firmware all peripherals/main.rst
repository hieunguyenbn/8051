                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
                              4 ; This file was generated Sat Mar 14 18:59:42 2015
                              5 ;--------------------------------------------------------
                              6 	.module main
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _T2CON_7
                             14 	.globl _T2CON_6
                             15 	.globl _T2CON_5
                             16 	.globl _T2CON_4
                             17 	.globl _T2CON_3
                             18 	.globl _T2CON_2
                             19 	.globl _T2CON_1
                             20 	.globl _T2CON_0
                             21 	.globl _RI
                             22 	.globl _TI
                             23 	.globl _RB8
                             24 	.globl _TB8
                             25 	.globl _REN
                             26 	.globl _SM2
                             27 	.globl _SM1
                             28 	.globl _SM0
                             29 	.globl _P1_7
                             30 	.globl _P1_6
                             31 	.globl _P1_5
                             32 	.globl _P1_4
                             33 	.globl _P1_3
                             34 	.globl _P1_2
                             35 	.globl _P1_1
                             36 	.globl _P1_0
                             37 	.globl _RXD
                             38 	.globl _TXD
                             39 	.globl _INT0
                             40 	.globl _INT1
                             41 	.globl _T0
                             42 	.globl _T1
                             43 	.globl _WR
                             44 	.globl _RD
                             45 	.globl _PX0
                             46 	.globl _PT0
                             47 	.globl _PX1
                             48 	.globl _PT1
                             49 	.globl _PS
                             50 	.globl _EX0
                             51 	.globl _ET0
                             52 	.globl _EX1
                             53 	.globl _ET1
                             54 	.globl _ES
                             55 	.globl _EA
                             56 	.globl _IT0
                             57 	.globl _IE0
                             58 	.globl _IT1
                             59 	.globl _IE1
                             60 	.globl _TR0
                             61 	.globl _TF0
                             62 	.globl _TR1
                             63 	.globl _TF1
                             64 	.globl _P
                             65 	.globl _OV
                             66 	.globl _RS0
                             67 	.globl _RS1
                             68 	.globl _F0
                             69 	.globl _AC
                             70 	.globl _CY
                             71 	.globl _FL
                             72 	.globl _TF2
                             73 	.globl _EXF2
                             74 	.globl _RCLK
                             75 	.globl _TCLK
                             76 	.globl _EXEN2
                             77 	.globl _TR2
                             78 	.globl _C_T2
                             79 	.globl _CP_RL2
                             80 	.globl _PT2
                             81 	.globl _P3_7
                             82 	.globl _P3_6
                             83 	.globl _P3_5
                             84 	.globl _P3_4
                             85 	.globl _P3_3
                             86 	.globl _P3_2
                             87 	.globl _P3_1
                             88 	.globl _P3_0
                             89 	.globl _ET2
                             90 	.globl _P2_7
                             91 	.globl _P2_6
                             92 	.globl _P2_5
                             93 	.globl _P2_4
                             94 	.globl _P2_3
                             95 	.globl _P2_2
                             96 	.globl _P2_1
                             97 	.globl _P2_0
                             98 	.globl _T2EX
                             99 	.globl _T2
                            100 	.globl _P0_7
                            101 	.globl _P0_6
                            102 	.globl _P0_5
                            103 	.globl _P0_4
                            104 	.globl _P0_3
                            105 	.globl _P0_2
                            106 	.globl _P0_1
                            107 	.globl _P0_0
                            108 	.globl _RCAP2L
                            109 	.globl _RCAP2H
                            110 	.globl _T2CON
                            111 	.globl _SBUF
                            112 	.globl _SCON
                            113 	.globl _IP
                            114 	.globl _IE
                            115 	.globl _AUXR
                            116 	.globl _TH1
                            117 	.globl _TH0
                            118 	.globl _TL1
                            119 	.globl _TL0
                            120 	.globl _TMOD
                            121 	.globl _TCON
                            122 	.globl _PCON
                            123 	.globl _DPH
                            124 	.globl _DPL
                            125 	.globl _SP
                            126 	.globl _B
                            127 	.globl _ACC
                            128 	.globl _PSW
                            129 	.globl _P3
                            130 	.globl _P2
                            131 	.globl _P1
                            132 	.globl _P0
                            133 	.globl _A
                            134 	.globl _TH2
                            135 	.globl _TL2
                            136 	.globl _T2MOD
                            137 	.globl _mm_option
                            138 	.globl _ARR_LcdLineNumAddress_U8
                            139 	.globl _STK_LCDConfig
                            140 	.globl _VAR_LcdTrackCursorPos_U8
                            141 	.globl _VAR_LcdTrackLineNum_U8
                            142 	.globl _UART_Init
                            143 	.globl _UART_SetBaudRate
                            144 	.globl _UART_RxChar
                            145 	.globl _UART_TxChar
                            146 	.globl _UART_TxString
                            147 	.globl _UART_TxDecimalNumber
                            148 	.globl _UART_TxHexNumber
                            149 	.globl _UART_Printf
                            150 	.globl _RTC_Init
                            151 	.globl _RTC_SetTime
                            152 	.globl _RTC_SetDate
                            153 	.globl _RTC_GetTime
                            154 	.globl _RTC_GetDate
                            155 	.globl _I2C_Init
                            156 	.globl _I2C_Start
                            157 	.globl _I2C_Stop
                            158 	.globl _I2C_Write
                            159 	.globl _I2C_Read
                            160 	.globl _LCD_Init
                            161 	.globl _LCD_Clear
                            162 	.globl _LCD_GoToLine
                            163 	.globl _LCD_GoToNextLine
                            164 	.globl _LCD_CmdWrite
                            165 	.globl _LCD_DisplayChar
                            166 	.globl _LCD_DisplayString
                            167 	.globl _DELAY_us
                            168 	.globl _DELAY_ms
                            169 	.globl _DELAY_sec
                            170 	.globl _ADC_Init
                            171 	.globl _ADC_GetAdcValue
                            172 	.globl _KEYPAD_Init
                            173 	.globl _KEYPAD_WaitForKeyRelease
                            174 	.globl _KEYPAD_WaitForKeyPress
                            175 	.globl _KEYPAD_GetKey
                            176 	.globl _EEPROM_WriteByte
                            177 	.globl _EEPROM_ReadByte
                            178 	.globl _EEPROM_WriteString
                            179 	.globl _EEPROM_ReadString
                            180 	.globl _gpio_test
                            181 	.globl _LCD_test
                            182 	.globl _seg_test
                            183 	.globl _rtc_test
                            184 	.globl _eeprom_test
                            185 	.globl _adc_test
                            186 	.globl _keypad_test
                            187 ;--------------------------------------------------------
                            188 ; special function registers
                            189 ;--------------------------------------------------------
                            190 	.area RSEG    (ABS,DATA)
   0000                     191 	.org 0x0000
                    00C9    192 _T2MOD	=	0x00c9
                    00CC    193 _TL2	=	0x00cc
                    00CD    194 _TH2	=	0x00cd
                    00E0    195 _A	=	0x00e0
                    0080    196 _P0	=	0x0080
                    0090    197 _P1	=	0x0090
                    00A0    198 _P2	=	0x00a0
                    00B0    199 _P3	=	0x00b0
                    00D0    200 _PSW	=	0x00d0
                    00E0    201 _ACC	=	0x00e0
                    00F0    202 _B	=	0x00f0
                    0081    203 _SP	=	0x0081
                    0082    204 _DPL	=	0x0082
                    0083    205 _DPH	=	0x0083
                    0087    206 _PCON	=	0x0087
                    0088    207 _TCON	=	0x0088
                    0089    208 _TMOD	=	0x0089
                    008A    209 _TL0	=	0x008a
                    008B    210 _TL1	=	0x008b
                    008C    211 _TH0	=	0x008c
                    008D    212 _TH1	=	0x008d
                    008E    213 _AUXR	=	0x008e
                    00A8    214 _IE	=	0x00a8
                    00B8    215 _IP	=	0x00b8
                    0098    216 _SCON	=	0x0098
                    0099    217 _SBUF	=	0x0099
                    00C8    218 _T2CON	=	0x00c8
                    00CB    219 _RCAP2H	=	0x00cb
                    00CA    220 _RCAP2L	=	0x00ca
                            221 ;--------------------------------------------------------
                            222 ; special function bits
                            223 ;--------------------------------------------------------
                            224 	.area RSEG    (ABS,DATA)
   0000                     225 	.org 0x0000
                    0080    226 _P0_0	=	0x0080
                    0081    227 _P0_1	=	0x0081
                    0082    228 _P0_2	=	0x0082
                    0083    229 _P0_3	=	0x0083
                    0084    230 _P0_4	=	0x0084
                    0085    231 _P0_5	=	0x0085
                    0086    232 _P0_6	=	0x0086
                    0087    233 _P0_7	=	0x0087
                    0090    234 _T2	=	0x0090
                    0091    235 _T2EX	=	0x0091
                    00A0    236 _P2_0	=	0x00a0
                    00A1    237 _P2_1	=	0x00a1
                    00A2    238 _P2_2	=	0x00a2
                    00A3    239 _P2_3	=	0x00a3
                    00A4    240 _P2_4	=	0x00a4
                    00A5    241 _P2_5	=	0x00a5
                    00A6    242 _P2_6	=	0x00a6
                    00A7    243 _P2_7	=	0x00a7
                    00AD    244 _ET2	=	0x00ad
                    00B0    245 _P3_0	=	0x00b0
                    00B1    246 _P3_1	=	0x00b1
                    00B2    247 _P3_2	=	0x00b2
                    00B3    248 _P3_3	=	0x00b3
                    00B4    249 _P3_4	=	0x00b4
                    00B5    250 _P3_5	=	0x00b5
                    00B6    251 _P3_6	=	0x00b6
                    00B7    252 _P3_7	=	0x00b7
                    00BD    253 _PT2	=	0x00bd
                    00C8    254 _CP_RL2	=	0x00c8
                    00C9    255 _C_T2	=	0x00c9
                    00CA    256 _TR2	=	0x00ca
                    00CB    257 _EXEN2	=	0x00cb
                    00CC    258 _TCLK	=	0x00cc
                    00CD    259 _RCLK	=	0x00cd
                    00CE    260 _EXF2	=	0x00ce
                    00CF    261 _TF2	=	0x00cf
                    00D1    262 _FL	=	0x00d1
                    00D7    263 _CY	=	0x00d7
                    00D6    264 _AC	=	0x00d6
                    00D5    265 _F0	=	0x00d5
                    00D4    266 _RS1	=	0x00d4
                    00D3    267 _RS0	=	0x00d3
                    00D2    268 _OV	=	0x00d2
                    00D0    269 _P	=	0x00d0
                    008F    270 _TF1	=	0x008f
                    008E    271 _TR1	=	0x008e
                    008D    272 _TF0	=	0x008d
                    008C    273 _TR0	=	0x008c
                    008B    274 _IE1	=	0x008b
                    008A    275 _IT1	=	0x008a
                    0089    276 _IE0	=	0x0089
                    0088    277 _IT0	=	0x0088
                    00AF    278 _EA	=	0x00af
                    00AC    279 _ES	=	0x00ac
                    00AB    280 _ET1	=	0x00ab
                    00AA    281 _EX1	=	0x00aa
                    00A9    282 _ET0	=	0x00a9
                    00A8    283 _EX0	=	0x00a8
                    00BC    284 _PS	=	0x00bc
                    00BB    285 _PT1	=	0x00bb
                    00BA    286 _PX1	=	0x00ba
                    00B9    287 _PT0	=	0x00b9
                    00B8    288 _PX0	=	0x00b8
                    00B7    289 _RD	=	0x00b7
                    00B6    290 _WR	=	0x00b6
                    00B5    291 _T1	=	0x00b5
                    00B4    292 _T0	=	0x00b4
                    00B3    293 _INT1	=	0x00b3
                    00B2    294 _INT0	=	0x00b2
                    00B1    295 _TXD	=	0x00b1
                    00B0    296 _RXD	=	0x00b0
                    0090    297 _P1_0	=	0x0090
                    0091    298 _P1_1	=	0x0091
                    0092    299 _P1_2	=	0x0092
                    0093    300 _P1_3	=	0x0093
                    0094    301 _P1_4	=	0x0094
                    0095    302 _P1_5	=	0x0095
                    0096    303 _P1_6	=	0x0096
                    0097    304 _P1_7	=	0x0097
                    009F    305 _SM0	=	0x009f
                    009E    306 _SM1	=	0x009e
                    009D    307 _SM2	=	0x009d
                    009C    308 _REN	=	0x009c
                    009B    309 _TB8	=	0x009b
                    009A    310 _RB8	=	0x009a
                    0099    311 _TI	=	0x0099
                    0098    312 _RI	=	0x0098
                    00C8    313 _T2CON_0	=	0x00c8
                    00C9    314 _T2CON_1	=	0x00c9
                    00CA    315 _T2CON_2	=	0x00ca
                    00CB    316 _T2CON_3	=	0x00cb
                    00CC    317 _T2CON_4	=	0x00cc
                    00CD    318 _T2CON_5	=	0x00cd
                    00CE    319 _T2CON_6	=	0x00ce
                    00CF    320 _T2CON_7	=	0x00cf
                            321 ;--------------------------------------------------------
                            322 ; overlayable register banks
                            323 ;--------------------------------------------------------
                            324 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     325 	.ds 8
                            326 ;--------------------------------------------------------
                            327 ; internal ram data
                            328 ;--------------------------------------------------------
                            329 	.area DSEG    (DATA)
   0008                     330 _VAR_LcdTrackLineNum_U8::
   0008                     331 	.ds 1
   0009                     332 _VAR_LcdTrackCursorPos_U8::
   0009                     333 	.ds 1
   000A                     334 _STK_LCDConfig::
   000A                     335 	.ds 3
   000D                     336 _ARR_LcdLineNumAddress_U8::
   000D                     337 	.ds 5
   0012                     338 _mm_option::
   0012                     339 	.ds 1
                            340 ;--------------------------------------------------------
                            341 ; overlayable items in internal ram 
                            342 ;--------------------------------------------------------
                            343 	.area OSEG    (OVR,DATA)
                            344 ;--------------------------------------------------------
                            345 ; Stack segment in internal ram 
                            346 ;--------------------------------------------------------
                            347 	.area	SSEG	(DATA)
   0014                     348 __start__stack:
   0014                     349 	.ds	1
                            350 
                            351 ;--------------------------------------------------------
                            352 ; indirectly addressable internal ram data
                            353 ;--------------------------------------------------------
                            354 	.area ISEG    (DATA)
                            355 ;--------------------------------------------------------
                            356 ; absolute internal ram data
                            357 ;--------------------------------------------------------
                            358 	.area IABS    (ABS,DATA)
                            359 	.area IABS    (ABS,DATA)
                            360 ;--------------------------------------------------------
                            361 ; bit data
                            362 ;--------------------------------------------------------
                            363 	.area BSEG    (BIT)
                            364 ;--------------------------------------------------------
                            365 ; paged external ram data
                            366 ;--------------------------------------------------------
                            367 	.area PSEG    (PAG,XDATA)
                            368 ;--------------------------------------------------------
                            369 ; external ram data
                            370 ;--------------------------------------------------------
                            371 	.area XSEG    (XDATA)
                            372 ;--------------------------------------------------------
                            373 ; absolute external ram data
                            374 ;--------------------------------------------------------
                            375 	.area XABS    (ABS,XDATA)
                            376 ;--------------------------------------------------------
                            377 ; external initialized ram data
                            378 ;--------------------------------------------------------
                            379 	.area XISEG   (XDATA)
                            380 	.area HOME    (CODE)
                            381 	.area GSINIT0 (CODE)
                            382 	.area GSINIT1 (CODE)
                            383 	.area GSINIT2 (CODE)
                            384 	.area GSINIT3 (CODE)
                            385 	.area GSINIT4 (CODE)
                            386 	.area GSINIT5 (CODE)
                            387 	.area GSINIT  (CODE)
                            388 	.area GSFINAL (CODE)
                            389 	.area CSEG    (CODE)
                            390 ;--------------------------------------------------------
                            391 ; interrupt vector 
                            392 ;--------------------------------------------------------
                            393 	.area HOME    (CODE)
   0000                     394 __interrupt_vect:
   0000 02 00 08            395 	ljmp	__sdcc_gsinit_startup
                            396 ;--------------------------------------------------------
                            397 ; global & static initialisations
                            398 ;--------------------------------------------------------
                            399 	.area HOME    (CODE)
                            400 	.area GSINIT  (CODE)
                            401 	.area GSFINAL (CODE)
                            402 	.area GSINIT  (CODE)
                            403 	.globl __sdcc_gsinit_startup
                            404 	.globl __sdcc_program_startup
                            405 	.globl __start__stack
                            406 	.globl __mcs51_genXINIT
                            407 	.globl __mcs51_genXRAMCLEAR
                            408 	.globl __mcs51_genRAMCLEAR
                            409 ;	D:\Workspace\MIDE\firmware\/lcd.c:79: uint8_t ARR_LcdLineNumAddress_U8[]={0x80,0x80,0xc0,0x90,0xd0};
   0061 75 0D 80            410 	mov	_ARR_LcdLineNumAddress_U8,#0x80
   0064 75 0E 80            411 	mov	(_ARR_LcdLineNumAddress_U8 + 0x0001),#0x80
   0067 75 0F C0            412 	mov	(_ARR_LcdLineNumAddress_U8 + 0x0002),#0xC0
   006A 75 10 90            413 	mov	(_ARR_LcdLineNumAddress_U8 + 0x0003),#0x90
   006D 75 11 D0            414 	mov	(_ARR_LcdLineNumAddress_U8 + 0x0004),#0xD0
                            415 	.area GSFINAL (CODE)
   0070 02 00 03            416 	ljmp	__sdcc_program_startup
                            417 ;--------------------------------------------------------
                            418 ; Home
                            419 ;--------------------------------------------------------
                            420 	.area HOME    (CODE)
                            421 	.area HOME    (CODE)
   0003                     422 __sdcc_program_startup:
   0003 12 10 7A            423 	lcall	_main
                            424 ;	return from main will lock up
   0006 80 FE               425 	sjmp .
                            426 ;--------------------------------------------------------
                            427 ; code
                            428 ;--------------------------------------------------------
                            429 	.area CSEG    (CODE)
                            430 ;------------------------------------------------------------
                            431 ;Allocation info for local variables in function 'UART_Init'
                            432 ;------------------------------------------------------------
                            433 ;var_baudRate_u32          Allocated to registers r2 r3 r4 r5 
                            434 ;------------------------------------------------------------
                            435 ;	D:\Workspace\MIDE\firmware\/uart.c:59: void UART_Init(uint32_t var_baudRate_u32)
                            436 ;	-----------------------------------------
                            437 ;	 function UART_Init
                            438 ;	-----------------------------------------
   0073                     439 _UART_Init:
                    0002    440 	ar2 = 0x02
                    0003    441 	ar3 = 0x03
                    0004    442 	ar4 = 0x04
                    0005    443 	ar5 = 0x05
                    0006    444 	ar6 = 0x06
                    0007    445 	ar7 = 0x07
                    0000    446 	ar0 = 0x00
                    0001    447 	ar1 = 0x01
   0073 AA 82               448 	mov	r2,dpl
   0075 AB 83               449 	mov	r3,dph
   0077 AC F0               450 	mov	r4,b
   0079 FD                  451 	mov	r5,a
                            452 ;	D:\Workspace\MIDE\firmware\/uart.c:61: TMOD |= 0x20; //Timer1 in Mode2.
   007A 43 89 20            453 	orl	_TMOD,#0x20
                            454 ;	D:\Workspace\MIDE\firmware\/uart.c:62: SCON=0x50;    // Asynchronous mode, 8-bit data and 1-stop bit
   007D 75 98 50            455 	mov	_SCON,#0x50
                            456 ;	D:\Workspace\MIDE\firmware\/uart.c:63: TR1=1;        //Turn ON the timer for Baud rate generation
   0080 D2 8E               457 	setb	_TR1
                            458 ;	D:\Workspace\MIDE\firmware\/uart.c:64: UART_SetBaudRate(var_baudRate_u32);
   0082 8A 82               459 	mov	dpl,r2
   0084 8B 83               460 	mov	dph,r3
   0086 8C F0               461 	mov	b,r4
   0088 ED                  462 	mov	a,r5
   0089 02 00 8C            463 	ljmp	_UART_SetBaudRate
                            464 ;------------------------------------------------------------
                            465 ;Allocation info for local variables in function 'UART_SetBaudRate'
                            466 ;------------------------------------------------------------
                            467 ;var_baudRate_u32          Allocated to registers r2 r3 r4 r5 
                            468 ;RegValue                  Allocated to registers r2 
                            469 ;------------------------------------------------------------
                            470 ;	D:\Workspace\MIDE\firmware\/uart.c:84: void UART_SetBaudRate(uint32_t var_baudRate_u32)
                            471 ;	-----------------------------------------
                            472 ;	 function UART_SetBaudRate
                            473 ;	-----------------------------------------
   008C                     474 _UART_SetBaudRate:
   008C AA 82               475 	mov	r2,dpl
   008E AB 83               476 	mov	r3,dph
   0090 AC F0               477 	mov	r4,b
   0092 FD                  478 	mov	r5,a
                            479 ;	D:\Workspace\MIDE\firmware\/uart.c:88: if((var_baudRate_u32 >= C_MinBaudRate_U32) && (var_baudRate_u32<=C_MaxBaudRate_U32))
   0093 C3                  480 	clr	c
   0094 EA                  481 	mov	a,r2
   0095 94 60               482 	subb	a,#0x60
   0097 EB                  483 	mov	a,r3
   0098 94 09               484 	subb	a,#0x09
   009A EC                  485 	mov	a,r4
   009B 94 00               486 	subb	a,#0x00
   009D ED                  487 	mov	a,r5
   009E 94 00               488 	subb	a,#0x00
   00A0 40 4F               489 	jc	00102$
   00A2 E4                  490 	clr	a
   00A3 9A                  491 	subb	a,r2
   00A4 74 C2               492 	mov	a,#0xC2
   00A6 9B                  493 	subb	a,r3
   00A7 74 01               494 	mov	a,#0x01
   00A9 9C                  495 	subb	a,r4
   00AA E4                  496 	clr	a
   00AB 9D                  497 	subb	a,r5
   00AC 40 43               498 	jc	00102$
                            499 ;	D:\Workspace\MIDE\firmware\/uart.c:92: RegValue = M_GetBaudRateGeneratorValue(var_baudRate_u32);
   00AE C0 02               500 	push	ar2
   00B0 C0 03               501 	push	ar3
   00B2 C0 04               502 	push	ar4
   00B4 C0 05               503 	push	ar5
   00B6 90 01 80            504 	mov	dptr,#0x0180
   00B9 E4                  505 	clr	a
   00BA F5 F0               506 	mov	b,a
   00BC 12 15 DF            507 	lcall	__mullong
   00BF AA 82               508 	mov	r2,dpl
   00C1 AB 83               509 	mov	r3,dph
   00C3 AC F0               510 	mov	r4,b
   00C5 FD                  511 	mov	r5,a
   00C6 E5 81               512 	mov	a,sp
   00C8 24 FC               513 	add	a,#0xfc
   00CA F5 81               514 	mov	sp,a
   00CC C0 02               515 	push	ar2
   00CE C0 03               516 	push	ar3
   00D0 C0 04               517 	push	ar4
   00D2 C0 05               518 	push	ar5
   00D4 90 C0 00            519 	mov	dptr,#0xC000
   00D7 75 F0 A8            520 	mov	b,#0xA8
   00DA E4                  521 	clr	a
   00DB 12 15 56            522 	lcall	__divulong
   00DE AA 82               523 	mov	r2,dpl
   00E0 AB 83               524 	mov	r3,dph
   00E2 AC F0               525 	mov	r4,b
   00E4 FD                  526 	mov	r5,a
   00E5 E5 81               527 	mov	a,sp
   00E7 24 FC               528 	add	a,#0xfc
   00E9 F5 81               529 	mov	sp,a
   00EB C3                  530 	clr	c
   00EC E4                  531 	clr	a
   00ED 9A                  532 	subb	a,r2
   00EE FA                  533 	mov	r2,a
   00EF 80 02               534 	sjmp	00103$
   00F1                     535 00102$:
                            536 ;	D:\Workspace\MIDE\firmware\/uart.c:97: RegValue = M_GetBaudRateGeneratorValue(9600);
   00F1 7A 5D               537 	mov	r2,#0x5D
   00F3                     538 00103$:
                            539 ;	D:\Workspace\MIDE\firmware\/uart.c:100: TH1 = RegValue; 
   00F3 8A 8D               540 	mov	_TH1,r2
   00F5 22                  541 	ret
                            542 ;------------------------------------------------------------
                            543 ;Allocation info for local variables in function 'UART_RxChar'
                            544 ;------------------------------------------------------------
                            545 ;------------------------------------------------------------
                            546 ;	D:\Workspace\MIDE\firmware\/uart.c:116: char UART_RxChar()
                            547 ;	-----------------------------------------
                            548 ;	 function UART_RxChar
                            549 ;	-----------------------------------------
   00F6                     550 _UART_RxChar:
                            551 ;	D:\Workspace\MIDE\firmware\/uart.c:118: while(RI==0);	  // Wait till the data is received
   00F6                     552 00101$:
                            553 ;	D:\Workspace\MIDE\firmware\/uart.c:119: RI=0;             // Clear Receive Interrupt Flag for next cycle
   00F6 10 98 02            554 	jbc	_RI,00108$
   00F9 80 FB               555 	sjmp	00101$
   00FB                     556 00108$:
                            557 ;	D:\Workspace\MIDE\firmware\/uart.c:121: return(SBUF);	  // return the received char
   00FB 85 99 82            558 	mov	dpl,_SBUF
   00FE 22                  559 	ret
                            560 ;------------------------------------------------------------
                            561 ;Allocation info for local variables in function 'UART_TxChar'
                            562 ;------------------------------------------------------------
                            563 ;var_uartData_u8           Allocated to registers 
                            564 ;------------------------------------------------------------
                            565 ;	D:\Workspace\MIDE\firmware\/uart.c:139: void UART_TxChar(char var_uartData_u8)
                            566 ;	-----------------------------------------
                            567 ;	 function UART_TxChar
                            568 ;	-----------------------------------------
   00FF                     569 _UART_TxChar:
   00FF 85 82 99            570 	mov	_SBUF,dpl
                            571 ;	D:\Workspace\MIDE\firmware\/uart.c:142: while(TI==0);       // Wait till the data is trasmitted
   0102                     572 00101$:
                            573 ;	D:\Workspace\MIDE\firmware\/uart.c:143: TI=0;		        //Clear the Tx flag for next cycle.
   0102 10 99 02            574 	jbc	_TI,00108$
   0105 80 FB               575 	sjmp	00101$
   0107                     576 00108$:
   0107 22                  577 	ret
                            578 ;------------------------------------------------------------
                            579 ;Allocation info for local variables in function 'UART_TxString'
                            580 ;------------------------------------------------------------
                            581 ;ptr_stringPointer_u8      Allocated to registers r2 r3 r4 
                            582 ;------------------------------------------------------------
                            583 ;	D:\Workspace\MIDE\firmware\/uart.c:163: void UART_TxString(char *ptr_stringPointer_u8)
                            584 ;	-----------------------------------------
                            585 ;	 function UART_TxString
                            586 ;	-----------------------------------------
   0108                     587 _UART_TxString:
   0108 AA 82               588 	mov	r2,dpl
   010A AB 83               589 	mov	r3,dph
   010C AC F0               590 	mov	r4,b
                            591 ;	D:\Workspace\MIDE\firmware\/uart.c:165: while(*ptr_stringPointer_u8)
   010E                     592 00101$:
   010E 8A 82               593 	mov	dpl,r2
   0110 8B 83               594 	mov	dph,r3
   0112 8C F0               595 	mov	b,r4
   0114 12 15 C3            596 	lcall	__gptrget
   0117 FD                  597 	mov	r5,a
   0118 60 18               598 	jz	00104$
                            599 ;	D:\Workspace\MIDE\firmware\/uart.c:166: UART_TxChar(*ptr_stringPointer_u8++);// Loop through the string and transmit char by char
   011A 0A                  600 	inc	r2
   011B BA 00 01            601 	cjne	r2,#0x00,00110$
   011E 0B                  602 	inc	r3
   011F                     603 00110$:
   011F 8D 82               604 	mov	dpl,r5
   0121 C0 02               605 	push	ar2
   0123 C0 03               606 	push	ar3
   0125 C0 04               607 	push	ar4
   0127 12 00 FF            608 	lcall	_UART_TxChar
   012A D0 04               609 	pop	ar4
   012C D0 03               610 	pop	ar3
   012E D0 02               611 	pop	ar2
   0130 80 DC               612 	sjmp	00101$
   0132                     613 00104$:
   0132 22                  614 	ret
                            615 ;------------------------------------------------------------
                            616 ;Allocation info for local variables in function 'UART_TxDecimalNumber'
                            617 ;------------------------------------------------------------
                            618 ;var_numOfDigitsToTransmit_u8 Allocated to stack - offset -3
                            619 ;var_decNumber_u32         Allocated to stack - offset 1
                            620 ;i                         Allocated to registers r2 
                            621 ;a                         Allocated to stack - offset 5
                            622 ;sloc0                     Allocated to stack - offset 16
                            623 ;sloc1                     Allocated to stack - offset 17
                            624 ;sloc2                     Allocated to stack - offset 15
                            625 ;------------------------------------------------------------
                            626 ;	D:\Workspace\MIDE\firmware\/uart.c:231: void UART_TxDecimalNumber(uint32_t var_decNumber_u32, uint8_t var_numOfDigitsToTransmit_u8)
                            627 ;	-----------------------------------------
                            628 ;	 function UART_TxDecimalNumber
                            629 ;	-----------------------------------------
   0133                     630 _UART_TxDecimalNumber:
   0133 C0 13               631 	push	_bp
   0135 85 81 13            632 	mov	_bp,sp
   0138 C0 82               633 	push	dpl
   013A C0 83               634 	push	dph
   013C C0 F0               635 	push	b
   013E C0 E0               636 	push	acc
   0140 E5 81               637 	mov	a,sp
   0142 24 12               638 	add	a,#0x12
   0144 F5 81               639 	mov	sp,a
                            640 ;	D:\Workspace\MIDE\firmware\/uart.c:235: if(var_decNumber_u32==0)
   0146 A8 13               641 	mov	r0,_bp
   0148 08                  642 	inc	r0
   0149 E6                  643 	mov	a,@r0
   014A 08                  644 	inc	r0
   014B 46                  645 	orl	a,@r0
   014C 08                  646 	inc	r0
   014D 46                  647 	orl	a,@r0
   014E 08                  648 	inc	r0
   014F 46                  649 	orl	a,@r0
   0150 70 30               650 	jnz	00133$
                            651 ;	D:\Workspace\MIDE\firmware\/uart.c:238: for(i=0;((i<var_numOfDigitsToTransmit_u8) && (i<C_MaxDigitsToTransmit_U8)) ;i++)
   0152 E5 13               652 	mov	a,_bp
   0154 24 05               653 	add	a,#0x05
   0156 FE                  654 	mov	r6,a
   0157 7A 00               655 	mov	r2,#0x00
   0159                     656 00119$:
   0159 E5 13               657 	mov	a,_bp
   015B 24 FD               658 	add	a,#0xfd
   015D F8                  659 	mov	r0,a
   015E C3                  660 	clr	c
   015F EA                  661 	mov	a,r2
   0160 96                  662 	subb	a,@r0
   0161 40 03               663 	jc	00139$
   0163 02 02 5E            664 	ljmp	00136$
   0166                     665 00139$:
   0166 C0 06               666 	push	ar6
   0168 8A 06               667 	mov	ar6,r2
   016A 7F 00               668 	mov	r7,#0x00
   016C C3                  669 	clr	c
   016D EE                  670 	mov	a,r6
   016E 94 0A               671 	subb	a,#0x0A
   0170 EF                  672 	mov	a,r7
   0171 94 00               673 	subb	a,#0x00
   0173 D0 06               674 	pop	ar6
   0175 40 03               675 	jc	00140$
   0177 02 02 5E            676 	ljmp	00136$
   017A                     677 00140$:
                            678 ;	D:\Workspace\MIDE\firmware\/uart.c:239: a[i] = 0x00;
   017A EA                  679 	mov	a,r2
   017B 2E                  680 	add	a,r6
   017C F8                  681 	mov	r0,a
   017D 76 00               682 	mov	@r0,#0x00
                            683 ;	D:\Workspace\MIDE\firmware\/uart.c:238: for(i=0;((i<var_numOfDigitsToTransmit_u8) && (i<C_MaxDigitsToTransmit_U8)) ;i++)
   017F 0A                  684 	inc	r2
                            685 ;	D:\Workspace\MIDE\firmware\/uart.c:243: for(i=0;i<var_numOfDigitsToTransmit_u8;i++)
   0180 80 D7               686 	sjmp	00119$
   0182                     687 00133$:
   0182 E5 13               688 	mov	a,_bp
   0184 24 05               689 	add	a,#0x05
   0186 FC                  690 	mov	r4,a
   0187 7D 00               691 	mov	r5,#0x00
   0189                     692 00108$:
   0189 E5 13               693 	mov	a,_bp
   018B 24 FD               694 	add	a,#0xfd
   018D F8                  695 	mov	r0,a
   018E C3                  696 	clr	c
   018F ED                  697 	mov	a,r5
   0190 96                  698 	subb	a,@r0
   0191 40 03               699 	jc	00141$
   0193 02 02 60            700 	ljmp	00137$
   0196                     701 00141$:
                            702 ;	D:\Workspace\MIDE\firmware\/uart.c:247: if(var_decNumber_u32!=0)
   0196 A8 13               703 	mov	r0,_bp
   0198 08                  704 	inc	r0
   0199 E6                  705 	mov	a,@r0
   019A 08                  706 	inc	r0
   019B 46                  707 	orl	a,@r0
   019C 08                  708 	inc	r0
   019D 46                  709 	orl	a,@r0
   019E 08                  710 	inc	r0
   019F 46                  711 	orl	a,@r0
   01A0 70 03               712 	jnz	00142$
   01A2 02 02 3C            713 	ljmp	00106$
   01A5                     714 00142$:
                            715 ;	D:\Workspace\MIDE\firmware\/uart.c:253: a[i]=util_GetMod32(var_decNumber_u32,10);
   01A5 ED                  716 	mov	a,r5
   01A6 2C                  717 	add	a,r4
   01A7 F8                  718 	mov	r0,a
   01A8 C0 04               719 	push	ar4
   01AA C0 05               720 	push	ar5
   01AC C0 00               721 	push	ar0
   01AE 74 0A               722 	mov	a,#0x0A
   01B0 C0 E0               723 	push	acc
   01B2 E4                  724 	clr	a
   01B3 C0 E0               725 	push	acc
   01B5 C0 E0               726 	push	acc
   01B7 C0 E0               727 	push	acc
   01B9 A9 13               728 	mov	r1,_bp
   01BB 09                  729 	inc	r1
   01BC 87 82               730 	mov	dpl,@r1
   01BE 09                  731 	inc	r1
   01BF 87 83               732 	mov	dph,@r1
   01C1 09                  733 	inc	r1
   01C2 87 F0               734 	mov	b,@r1
   01C4 09                  735 	inc	r1
   01C5 E7                  736 	mov	a,@r1
   01C6 12 15 56            737 	lcall	__divulong
   01C9 C9                  738 	xch	a,r1
   01CA E5 13               739 	mov	a,_bp
   01CC 24 0F               740 	add	a,#0x0f
   01CE C9                  741 	xch	a,r1
   01CF A7 82               742 	mov	@r1,dpl
   01D1 09                  743 	inc	r1
   01D2 A7 83               744 	mov	@r1,dph
   01D4 09                  745 	inc	r1
   01D5 A7 F0               746 	mov	@r1,b
   01D7 09                  747 	inc	r1
   01D8 F7                  748 	mov	@r1,a
   01D9 E5 81               749 	mov	a,sp
   01DB 24 FC               750 	add	a,#0xfc
   01DD F5 81               751 	mov	sp,a
   01DF E5 13               752 	mov	a,_bp
   01E1 24 0F               753 	add	a,#0x0f
   01E3 F9                  754 	mov	r1,a
   01E4 E7                  755 	mov	a,@r1
   01E5 C0 E0               756 	push	acc
   01E7 09                  757 	inc	r1
   01E8 E7                  758 	mov	a,@r1
   01E9 C0 E0               759 	push	acc
   01EB 09                  760 	inc	r1
   01EC E7                  761 	mov	a,@r1
   01ED C0 E0               762 	push	acc
   01EF 09                  763 	inc	r1
   01F0 E7                  764 	mov	a,@r1
   01F1 C0 E0               765 	push	acc
   01F3 90 00 0A            766 	mov	dptr,#(0x0A&0x00ff)
   01F6 E4                  767 	clr	a
   01F7 F5 F0               768 	mov	b,a
   01F9 12 15 DF            769 	lcall	__mullong
   01FC AF 82               770 	mov	r7,dpl
   01FE AE 83               771 	mov	r6,dph
   0200 AA F0               772 	mov	r2,b
   0202 FB                  773 	mov	r3,a
   0203 E5 81               774 	mov	a,sp
   0205 24 FC               775 	add	a,#0xfc
   0207 F5 81               776 	mov	sp,a
   0209 D0 00               777 	pop	ar0
   020B D0 05               778 	pop	ar5
   020D D0 04               779 	pop	ar4
   020F A9 13               780 	mov	r1,_bp
   0211 09                  781 	inc	r1
   0212 E7                  782 	mov	a,@r1
   0213 C3                  783 	clr	c
   0214 9F                  784 	subb	a,r7
   0215 FF                  785 	mov	r7,a
   0216 09                  786 	inc	r1
   0217 E7                  787 	mov	a,@r1
   0218 9E                  788 	subb	a,r6
   0219 FE                  789 	mov	r6,a
   021A 09                  790 	inc	r1
   021B E7                  791 	mov	a,@r1
   021C 9A                  792 	subb	a,r2
   021D FA                  793 	mov	r2,a
   021E 09                  794 	inc	r1
   021F E7                  795 	mov	a,@r1
   0220 9B                  796 	subb	a,r3
   0221 FB                  797 	mov	r3,a
   0222 A6 07               798 	mov	@r0,ar7
                            799 ;	D:\Workspace\MIDE\firmware\/uart.c:254: var_decNumber_u32=var_decNumber_u32/10;
   0224 E5 13               800 	mov	a,_bp
   0226 24 0F               801 	add	a,#0x0f
   0228 F8                  802 	mov	r0,a
   0229 A9 13               803 	mov	r1,_bp
   022B 09                  804 	inc	r1
   022C E6                  805 	mov	a,@r0
   022D F7                  806 	mov	@r1,a
   022E 08                  807 	inc	r0
   022F 09                  808 	inc	r1
   0230 E6                  809 	mov	a,@r0
   0231 F7                  810 	mov	@r1,a
   0232 08                  811 	inc	r0
   0233 09                  812 	inc	r1
   0234 E6                  813 	mov	a,@r0
   0235 F7                  814 	mov	@r1,a
   0236 08                  815 	inc	r0
   0237 09                  816 	inc	r1
   0238 E6                  817 	mov	a,@r0
   0239 F7                  818 	mov	@r1,a
   023A 80 1E               819 	sjmp	00110$
   023C                     820 00106$:
                            821 ;	D:\Workspace\MIDE\firmware\/uart.c:256: else if( (var_numOfDigitsToTransmit_u8 == C_DefaultDigitsToTransmit_U8) ||
   023C E5 13               822 	mov	a,_bp
   023E 24 FD               823 	add	a,#0xfd
   0240 F8                  824 	mov	r0,a
   0241 86 02               825 	mov	ar2,@r0
   0243 7B 00               826 	mov	r3,#0x00
   0245 BA FF 05            827 	cjne	r2,#0xFF,00143$
   0248 BB 00 02            828 	cjne	r3,#0x00,00143$
   024B 80 13               829 	sjmp	00137$
   024D                     830 00143$:
                            831 ;	D:\Workspace\MIDE\firmware\/uart.c:257: (var_numOfDigitsToTransmit_u8 > C_MaxDigitsToTransmit_U8))
   024D C3                  832 	clr	c
   024E 74 0A               833 	mov	a,#0x0A
   0250 9A                  834 	subb	a,r2
   0251 E4                  835 	clr	a
   0252 9B                  836 	subb	a,r3
   0253 40 0B               837 	jc	00137$
                            838 ;	D:\Workspace\MIDE\firmware\/uart.c:268: a[i]=0;
   0255 ED                  839 	mov	a,r5
   0256 2C                  840 	add	a,r4
   0257 F8                  841 	mov	r0,a
   0258 76 00               842 	mov	@r0,#0x00
   025A                     843 00110$:
                            844 ;	D:\Workspace\MIDE\firmware\/uart.c:243: for(i=0;i<var_numOfDigitsToTransmit_u8;i++)
   025A 0D                  845 	inc	r5
   025B 02 01 89            846 	ljmp	00108$
                            847 ;	D:\Workspace\MIDE\firmware\/uart.c:273: while(i)
   025E                     848 00136$:
                            849 ;	D:\Workspace\MIDE\firmware\/uart.c:277: i--;
                            850 ;	D:\Workspace\MIDE\firmware\/uart.c:273: while(i)
   025E 80 02               851 	sjmp	00135$
   0260                     852 00137$:
   0260 8D 02               853 	mov	ar2,r5
   0262                     854 00135$:
   0262 E5 13               855 	mov	a,_bp
   0264 24 05               856 	add	a,#0x05
   0266 FB                  857 	mov	r3,a
   0267                     858 00115$:
   0267 EA                  859 	mov	a,r2
   0268 60 1B               860 	jz	00123$
                            861 ;	D:\Workspace\MIDE\firmware\/uart.c:276: UART_TxChar(util_Dec2Ascii(a[i-1]));
   026A EA                  862 	mov	a,r2
   026B 14                  863 	dec	a
   026C FC                  864 	mov	r4,a
   026D 2B                  865 	add	a,r3
   026E F8                  866 	mov	r0,a
   026F 86 05               867 	mov	ar5,@r0
   0271 74 30               868 	mov	a,#0x30
   0273 2D                  869 	add	a,r5
   0274 F5 82               870 	mov	dpl,a
   0276 C0 03               871 	push	ar3
   0278 C0 04               872 	push	ar4
   027A 12 00 FF            873 	lcall	_UART_TxChar
   027D D0 04               874 	pop	ar4
   027F D0 03               875 	pop	ar3
                            876 ;	D:\Workspace\MIDE\firmware\/uart.c:277: i--;
   0281 8C 02               877 	mov	ar2,r4
   0283 80 E2               878 	sjmp	00115$
   0285                     879 00123$:
   0285 85 13 81            880 	mov	sp,_bp
   0288 D0 13               881 	pop	_bp
   028A 22                  882 	ret
                            883 ;------------------------------------------------------------
                            884 ;Allocation info for local variables in function 'UART_TxHexNumber'
                            885 ;------------------------------------------------------------
                            886 ;var_numOfDigitsToTransmit_u8 Allocated to stack - offset -3
                            887 ;var_hexNumber_u32         Allocated to stack - offset 1
                            888 ;i                         Allocated to registers r2 
                            889 ;a                         Allocated to stack - offset 5
                            890 ;------------------------------------------------------------
                            891 ;	D:\Workspace\MIDE\firmware\/uart.c:303: void UART_TxHexNumber(uint32_t var_hexNumber_u32,uint8_t var_numOfDigitsToTransmit_u8)
                            892 ;	-----------------------------------------
                            893 ;	 function UART_TxHexNumber
                            894 ;	-----------------------------------------
   028B                     895 _UART_TxHexNumber:
   028B C0 13               896 	push	_bp
   028D 85 81 13            897 	mov	_bp,sp
   0290 C0 82               898 	push	dpl
   0292 C0 83               899 	push	dph
   0294 C0 F0               900 	push	b
   0296 C0 E0               901 	push	acc
   0298 E5 81               902 	mov	a,sp
   029A 24 0E               903 	add	a,#0x0e
   029C F5 81               904 	mov	sp,a
                            905 ;	D:\Workspace\MIDE\firmware\/uart.c:307: if(var_hexNumber_u32==0)
   029E A8 13               906 	mov	r0,_bp
   02A0 08                  907 	inc	r0
   02A1 E6                  908 	mov	a,@r0
   02A2 08                  909 	inc	r0
   02A3 46                  910 	orl	a,@r0
   02A4 08                  911 	inc	r0
   02A5 46                  912 	orl	a,@r0
   02A6 08                  913 	inc	r0
   02A7 46                  914 	orl	a,@r0
   02A8 70 30               915 	jnz	00135$
                            916 ;	D:\Workspace\MIDE\firmware\/uart.c:310: for(i=0;((i<var_numOfDigitsToTransmit_u8) && (i<C_MaxDigitsToTransmit_U8)) ;i++)
   02AA E5 13               917 	mov	a,_bp
   02AC 24 05               918 	add	a,#0x05
   02AE FE                  919 	mov	r6,a
   02AF 7A 00               920 	mov	r2,#0x00
   02B1                     921 00119$:
   02B1 E5 13               922 	mov	a,_bp
   02B3 24 FD               923 	add	a,#0xfd
   02B5 F8                  924 	mov	r0,a
   02B6 C3                  925 	clr	c
   02B7 EA                  926 	mov	a,r2
   02B8 96                  927 	subb	a,@r0
   02B9 40 03               928 	jc	00143$
   02BB 02 03 62            929 	ljmp	00139$
   02BE                     930 00143$:
   02BE C0 06               931 	push	ar6
   02C0 8A 06               932 	mov	ar6,r2
   02C2 7F 00               933 	mov	r7,#0x00
   02C4 C3                  934 	clr	c
   02C5 EE                  935 	mov	a,r6
   02C6 94 0A               936 	subb	a,#0x0A
   02C8 EF                  937 	mov	a,r7
   02C9 94 00               938 	subb	a,#0x00
   02CB D0 06               939 	pop	ar6
   02CD 40 03               940 	jc	00144$
   02CF 02 03 62            941 	ljmp	00139$
   02D2                     942 00144$:
                            943 ;	D:\Workspace\MIDE\firmware\/uart.c:311: a[i]=0x00;
   02D2 EA                  944 	mov	a,r2
   02D3 2E                  945 	add	a,r6
   02D4 F8                  946 	mov	r0,a
   02D5 76 00               947 	mov	@r0,#0x00
                            948 ;	D:\Workspace\MIDE\firmware\/uart.c:310: for(i=0;((i<var_numOfDigitsToTransmit_u8) && (i<C_MaxDigitsToTransmit_U8)) ;i++)
   02D7 0A                  949 	inc	r2
                            950 ;	D:\Workspace\MIDE\firmware\/uart.c:315: for(i=0;i<var_numOfDigitsToTransmit_u8;i++)
   02D8 80 D7               951 	sjmp	00119$
   02DA                     952 00135$:
   02DA E5 13               953 	mov	a,_bp
   02DC 24 05               954 	add	a,#0x05
   02DE FE                  955 	mov	r6,a
   02DF 7F 00               956 	mov	r7,#0x00
   02E1                     957 00108$:
   02E1 E5 13               958 	mov	a,_bp
   02E3 24 FD               959 	add	a,#0xfd
   02E5 F8                  960 	mov	r0,a
   02E6 C3                  961 	clr	c
   02E7 EF                  962 	mov	a,r7
   02E8 96                  963 	subb	a,@r0
   02E9 40 03               964 	jc	00145$
   02EB 02 03 64            965 	ljmp	00140$
   02EE                     966 00145$:
                            967 ;	D:\Workspace\MIDE\firmware\/uart.c:318: if(var_hexNumber_u32!=0)
   02EE A8 13               968 	mov	r0,_bp
   02F0 08                  969 	inc	r0
   02F1 E6                  970 	mov	a,@r0
   02F2 08                  971 	inc	r0
   02F3 46                  972 	orl	a,@r0
   02F4 08                  973 	inc	r0
   02F5 46                  974 	orl	a,@r0
   02F6 08                  975 	inc	r0
   02F7 46                  976 	orl	a,@r0
   02F8 60 46               977 	jz	00106$
                            978 ;	D:\Workspace\MIDE\firmware\/uart.c:324: a[i]=(uint8_t)(var_hexNumber_u32 & 0x0f);
   02FA EF                  979 	mov	a,r7
   02FB 2E                  980 	add	a,r6
   02FC F8                  981 	mov	r0,a
   02FD C0 06               982 	push	ar6
   02FF A9 13               983 	mov	r1,_bp
   0301 09                  984 	inc	r1
   0302 74 0F               985 	mov	a,#0x0F
   0304 57                  986 	anl	a,@r1
   0305 FE                  987 	mov	r6,a
   0306 7A 00               988 	mov	r2,#0x00
   0308 7B 00               989 	mov	r3,#0x00
   030A 7C 00               990 	mov	r4,#0x00
   030C A6 06               991 	mov	@r0,ar6
                            992 ;	D:\Workspace\MIDE\firmware\/uart.c:325: var_hexNumber_u32=var_hexNumber_u32 >> 4;
   030E A8 13               993 	mov	r0,_bp
   0310 08                  994 	inc	r0
   0311 08                  995 	inc	r0
   0312 E6                  996 	mov	a,@r0
   0313 18                  997 	dec	r0
   0314 C4                  998 	swap	a
   0315 C6                  999 	xch	a,@r0
   0316 C4                 1000 	swap	a
   0317 54 0F              1001 	anl	a,#0x0f
   0319 66                 1002 	xrl	a,@r0
   031A C6                 1003 	xch	a,@r0
   031B 54 0F              1004 	anl	a,#0x0f
   031D C6                 1005 	xch	a,@r0
   031E 66                 1006 	xrl	a,@r0
   031F C6                 1007 	xch	a,@r0
   0320 08                 1008 	inc	r0
   0321 F6                 1009 	mov	@r0,a
   0322 08                 1010 	inc	r0
   0323 E6                 1011 	mov	a,@r0
   0324 C4                 1012 	swap	a
   0325 54 F0              1013 	anl	a,#0xf0
   0327 18                 1014 	dec	r0
   0328 46                 1015 	orl	a,@r0
   0329 F6                 1016 	mov	@r0,a
   032A 08                 1017 	inc	r0
   032B 08                 1018 	inc	r0
   032C E6                 1019 	mov	a,@r0
   032D 18                 1020 	dec	r0
   032E C4                 1021 	swap	a
   032F C6                 1022 	xch	a,@r0
   0330 C4                 1023 	swap	a
   0331 54 0F              1024 	anl	a,#0x0f
   0333 66                 1025 	xrl	a,@r0
   0334 C6                 1026 	xch	a,@r0
   0335 54 0F              1027 	anl	a,#0x0f
   0337 C6                 1028 	xch	a,@r0
   0338 66                 1029 	xrl	a,@r0
   0339 C6                 1030 	xch	a,@r0
   033A 08                 1031 	inc	r0
   033B F6                 1032 	mov	@r0,a
   033C D0 06              1033 	pop	ar6
   033E 80 1E              1034 	sjmp	00110$
   0340                    1035 00106$:
                           1036 ;	D:\Workspace\MIDE\firmware\/uart.c:327: else if( (var_numOfDigitsToTransmit_u8 == C_DefaultDigitsToTransmit_U8) ||
   0340 E5 13              1037 	mov	a,_bp
   0342 24 FD              1038 	add	a,#0xfd
   0344 F8                 1039 	mov	r0,a
   0345 86 02              1040 	mov	ar2,@r0
   0347 7B 00              1041 	mov	r3,#0x00
   0349 BA FF 05           1042 	cjne	r2,#0xFF,00147$
   034C BB 00 02           1043 	cjne	r3,#0x00,00147$
   034F 80 13              1044 	sjmp	00140$
   0351                    1045 00147$:
                           1046 ;	D:\Workspace\MIDE\firmware\/uart.c:328: (var_numOfDigitsToTransmit_u8 > C_MaxDigitsToTransmit_U8))
   0351 C3                 1047 	clr	c
   0352 74 0A              1048 	mov	a,#0x0A
   0354 9A                 1049 	subb	a,r2
   0355 E4                 1050 	clr	a
   0356 9B                 1051 	subb	a,r3
   0357 40 0B              1052 	jc	00140$
                           1053 ;	D:\Workspace\MIDE\firmware\/uart.c:339: a[i]=0x00;
   0359 EF                 1054 	mov	a,r7
   035A 2E                 1055 	add	a,r6
   035B F8                 1056 	mov	r0,a
   035C 76 00              1057 	mov	@r0,#0x00
   035E                    1058 00110$:
                           1059 ;	D:\Workspace\MIDE\firmware\/uart.c:315: for(i=0;i<var_numOfDigitsToTransmit_u8;i++)
   035E 0F                 1060 	inc	r7
   035F 02 02 E1           1061 	ljmp	00108$
                           1062 ;	D:\Workspace\MIDE\firmware\/uart.c:344: while(i!=0)
   0362                    1063 00139$:
                           1064 ;	D:\Workspace\MIDE\firmware\/uart.c:348: i--;
                           1065 ;	D:\Workspace\MIDE\firmware\/uart.c:344: while(i!=0)
   0362 80 02              1066 	sjmp	00138$
   0364                    1067 00140$:
   0364 8F 02              1068 	mov	ar2,r7
   0366                    1069 00138$:
   0366 E5 13              1070 	mov	a,_bp
   0368 24 05              1071 	add	a,#0x05
   036A FB                 1072 	mov	r3,a
   036B                    1073 00115$:
   036B EA                 1074 	mov	a,r2
   036C 60 33              1075 	jz	00123$
                           1076 ;	D:\Workspace\MIDE\firmware\/uart.c:347: UART_TxChar(util_Hex2Ascii(a[i-1]));
   036E EA                 1077 	mov	a,r2
   036F 14                 1078 	dec	a
   0370 2B                 1079 	add	a,r3
   0371 F8                 1080 	mov	r0,a
   0372 86 04              1081 	mov	ar4,@r0
   0374 74 09              1082 	mov	a,#0x09
   0376 B5 04 00           1083 	cjne	a,ar4,00150$
   0379                    1084 00150$:
   0379 50 0C              1085 	jnc	00125$
   037B EA                 1086 	mov	a,r2
   037C 14                 1087 	dec	a
   037D 2B                 1088 	add	a,r3
   037E F8                 1089 	mov	r0,a
   037F 86 04              1090 	mov	ar4,@r0
   0381 74 37              1091 	mov	a,#0x37
   0383 2C                 1092 	add	a,r4
   0384 FC                 1093 	mov	r4,a
   0385 80 0A              1094 	sjmp	00126$
   0387                    1095 00125$:
   0387 EA                 1096 	mov	a,r2
   0388 14                 1097 	dec	a
   0389 2B                 1098 	add	a,r3
   038A F8                 1099 	mov	r0,a
   038B 86 05              1100 	mov	ar5,@r0
   038D 74 30              1101 	mov	a,#0x30
   038F 2D                 1102 	add	a,r5
   0390 FC                 1103 	mov	r4,a
   0391                    1104 00126$:
   0391 8C 82              1105 	mov	dpl,r4
   0393 C0 02              1106 	push	ar2
   0395 C0 03              1107 	push	ar3
   0397 12 00 FF           1108 	lcall	_UART_TxChar
   039A D0 03              1109 	pop	ar3
   039C D0 02              1110 	pop	ar2
                           1111 ;	D:\Workspace\MIDE\firmware\/uart.c:348: i--;
   039E 1A                 1112 	dec	r2
   039F 80 CA              1113 	sjmp	00115$
   03A1                    1114 00123$:
   03A1 85 13 81           1115 	mov	sp,_bp
   03A4 D0 13              1116 	pop	_bp
   03A6 22                 1117 	ret
                           1118 ;------------------------------------------------------------
                           1119 ;Allocation info for local variables in function 'UART_Printf'
                           1120 ;------------------------------------------------------------
                           1121 ;argList                   Allocated to stack - offset -5
                           1122 ;ptr                       Allocated to registers r3 r4 r5 
                           1123 ;var_floatNum_f32          Allocated to registers 
                           1124 ;argp                      Allocated to stack - offset 1
                           1125 ;var_num_s16               Allocated to registers r2 r6 
                           1126 ;var_num_s32               Allocated to stack - offset 2
                           1127 ;var_num_u16               Allocated to registers r2 r6 
                           1128 ;var_num_u32               Allocated to stack - offset 6
                           1129 ;str                       Allocated to registers r2 r6 r7 
                           1130 ;ch                        Allocated to stack - offset 10
                           1131 ;var_numOfDigitsToTransmit_u8 Allocated to stack - offset 11
                           1132 ;sloc0                     Allocated to stack - offset 12
                           1133 ;------------------------------------------------------------
                           1134 ;	D:\Workspace\MIDE\firmware\/uart.c:468: void UART_Printf(const char *argList, ...)
                           1135 ;	-----------------------------------------
                           1136 ;	 function UART_Printf
                           1137 ;	-----------------------------------------
   03A7                    1138 _UART_Printf:
   03A7 C0 13              1139 	push	_bp
   03A9 E5 81              1140 	mov	a,sp
   03AB F5 13              1141 	mov	_bp,a
   03AD 24 0E              1142 	add	a,#0x0e
   03AF F5 81              1143 	mov	sp,a
                           1144 ;	D:\Workspace\MIDE\firmware\/uart.c:481: va_start(argp, argList);
   03B1 E5 13              1145 	mov	a,_bp
   03B3 24 FB              1146 	add	a,#0xfb
   03B5 FA                 1147 	mov	r2,a
   03B6 A8 13              1148 	mov	r0,_bp
   03B8 08                 1149 	inc	r0
   03B9 A6 02              1150 	mov	@r0,ar2
                           1151 ;	D:\Workspace\MIDE\firmware\/uart.c:484: for(ptr = argList; *ptr != '\0'; ptr++)
   03BB E5 13              1152 	mov	a,_bp
   03BD 24 FB              1153 	add	a,#0xfb
   03BF F8                 1154 	mov	r0,a
   03C0 86 03              1155 	mov	ar3,@r0
   03C2 08                 1156 	inc	r0
   03C3 86 04              1157 	mov	ar4,@r0
   03C5 08                 1158 	inc	r0
   03C6 86 05              1159 	mov	ar5,@r0
   03C8                    1160 00132$:
   03C8 8B 82              1161 	mov	dpl,r3
   03CA 8C 83              1162 	mov	dph,r4
   03CC 8D F0              1163 	mov	b,r5
   03CE 12 15 C3           1164 	lcall	__gptrget
   03D1 FE                 1165 	mov	r6,a
   03D2 BE 00 03           1166 	cjne	r6,#0x00,00164$
   03D5 02 08 2E           1167 	ljmp	00136$
   03D8                    1168 00164$:
                           1169 ;	D:\Workspace\MIDE\firmware\/uart.c:487: ch= *ptr;
   03D8 E5 13              1170 	mov	a,_bp
   03DA 24 0A              1171 	add	a,#0x0a
   03DC F8                 1172 	mov	r0,a
   03DD A6 06              1173 	mov	@r0,ar6
                           1174 ;	D:\Workspace\MIDE\firmware\/uart.c:488: if(ch == '%')         /*Check for '%' as there will be format specifier after it */
   03DF E5 13              1175 	mov	a,_bp
   03E1 24 0A              1176 	add	a,#0x0a
   03E3 F8                 1177 	mov	r0,a
   03E4 B6 25 02           1178 	cjne	@r0,#0x25,00165$
   03E7 80 03              1179 	sjmp	00166$
   03E9                    1180 00165$:
   03E9 02 08 10           1181 	ljmp	00130$
   03EC                    1182 00166$:
                           1183 ;	D:\Workspace\MIDE\firmware\/uart.c:490: ptr++;
   03EC 0B                 1184 	inc	r3
   03ED BB 00 01           1185 	cjne	r3,#0x00,00167$
   03F0 0C                 1186 	inc	r4
   03F1                    1187 00167$:
                           1188 ;	D:\Workspace\MIDE\firmware\/uart.c:491: ch = *ptr;
   03F1 8B 82              1189 	mov	dpl,r3
   03F3 8C 83              1190 	mov	dph,r4
   03F5 8D F0              1191 	mov	b,r5
   03F7 12 15 C3           1192 	lcall	__gptrget
   03FA FF                 1193 	mov	r7,a
   03FB E5 13              1194 	mov	a,_bp
   03FD 24 0A              1195 	add	a,#0x0a
   03FF F8                 1196 	mov	r0,a
   0400 A6 07              1197 	mov	@r0,ar7
                           1198 ;	D:\Workspace\MIDE\firmware\/uart.c:492: if((ch>=0x30) && (ch<=0x39))
   0402 E5 13              1199 	mov	a,_bp
   0404 24 0A              1200 	add	a,#0x0a
   0406 F8                 1201 	mov	r0,a
   0407 C3                 1202 	clr	c
   0408 E6                 1203 	mov	a,@r0
   0409 64 80              1204 	xrl	a,#0x80
   040B 94 B0              1205 	subb	a,#0xb0
   040D 50 03              1206 	jnc	00168$
   040F 02 04 99           1207 	ljmp	00106$
   0412                    1208 00168$:
   0412 E5 13              1209 	mov	a,_bp
   0414 24 0A              1210 	add	a,#0x0a
   0416 F8                 1211 	mov	r0,a
   0417 C3                 1212 	clr	c
   0418 74 B9              1213 	mov	a,#(0x39 ^ 0x80)
   041A 86 F0              1214 	mov	b,@r0
   041C 63 F0 80           1215 	xrl	b,#0x80
   041F 95 F0              1216 	subb	a,b
   0421 50 03              1217 	jnc	00169$
   0423 02 04 99           1218 	ljmp	00106$
   0426                    1219 00169$:
                           1220 ;	D:\Workspace\MIDE\firmware\/uart.c:494: var_numOfDigitsToTransmit_u8 = 0;
   0426 E5 13              1221 	mov	a,_bp
   0428 24 0B              1222 	add	a,#0x0b
   042A F8                 1223 	mov	r0,a
   042B 76 00              1224 	mov	@r0,#0x00
                           1225 ;	D:\Workspace\MIDE\firmware\/uart.c:495: while((ch>=0x30) && (ch<=0x39))
   042D E5 13              1226 	mov	a,_bp
   042F 24 0C              1227 	add	a,#0x0c
   0431 F8                 1228 	mov	r0,a
   0432 A6 03              1229 	mov	@r0,ar3
   0434 08                 1230 	inc	r0
   0435 A6 04              1231 	mov	@r0,ar4
   0437 08                 1232 	inc	r0
   0438 A6 05              1233 	mov	@r0,ar5
   043A                    1234 00102$:
   043A E5 13              1235 	mov	a,_bp
   043C 24 0A              1236 	add	a,#0x0a
   043E F8                 1237 	mov	r0,a
   043F C3                 1238 	clr	c
   0440 E6                 1239 	mov	a,@r0
   0441 64 80              1240 	xrl	a,#0x80
   0443 94 B0              1241 	subb	a,#0xb0
   0445 40 5B              1242 	jc	00163$
   0447 E5 13              1243 	mov	a,_bp
   0449 24 0A              1244 	add	a,#0x0a
   044B F8                 1245 	mov	r0,a
   044C C3                 1246 	clr	c
   044D 74 B9              1247 	mov	a,#(0x39 ^ 0x80)
   044F 86 F0              1248 	mov	b,@r0
   0451 63 F0 80           1249 	xrl	b,#0x80
   0454 95 F0              1250 	subb	a,b
   0456 40 4A              1251 	jc	00163$
                           1252 ;	D:\Workspace\MIDE\firmware\/uart.c:497: var_numOfDigitsToTransmit_u8 = (var_numOfDigitsToTransmit_u8 * 10) + (ch-0x30);
   0458 E5 13              1253 	mov	a,_bp
   045A 24 0B              1254 	add	a,#0x0b
   045C F8                 1255 	mov	r0,a
   045D E6                 1256 	mov	a,@r0
   045E 75 F0 0A           1257 	mov	b,#0x0A
   0461 A4                 1258 	mul	ab
   0462 FA                 1259 	mov	r2,a
   0463 E5 13              1260 	mov	a,_bp
   0465 24 0A              1261 	add	a,#0x0a
   0467 F8                 1262 	mov	r0,a
   0468 E6                 1263 	mov	a,@r0
   0469 24 D0              1264 	add	a,#0xd0
   046B 2A                 1265 	add	a,r2
   046C FA                 1266 	mov	r2,a
   046D E5 13              1267 	mov	a,_bp
   046F 24 0B              1268 	add	a,#0x0b
   0471 F8                 1269 	mov	r0,a
   0472 A6 02              1270 	mov	@r0,ar2
                           1271 ;	D:\Workspace\MIDE\firmware\/uart.c:498: ptr++;
   0474 E5 13              1272 	mov	a,_bp
   0476 24 0C              1273 	add	a,#0x0c
   0478 F8                 1274 	mov	r0,a
   0479 06                 1275 	inc	@r0
   047A B6 00 02           1276 	cjne	@r0,#0x00,00172$
   047D 08                 1277 	inc	r0
   047E 06                 1278 	inc	@r0
   047F                    1279 00172$:
                           1280 ;	D:\Workspace\MIDE\firmware\/uart.c:499: ch = *ptr;
   047F E5 13              1281 	mov	a,_bp
   0481 24 0C              1282 	add	a,#0x0c
   0483 F8                 1283 	mov	r0,a
   0484 86 82              1284 	mov	dpl,@r0
   0486 08                 1285 	inc	r0
   0487 86 83              1286 	mov	dph,@r0
   0489 08                 1287 	inc	r0
   048A 86 F0              1288 	mov	b,@r0
   048C 12 15 C3           1289 	lcall	__gptrget
   048F FA                 1290 	mov	r2,a
   0490 E5 13              1291 	mov	a,_bp
   0492 24 0A              1292 	add	a,#0x0a
   0494 F8                 1293 	mov	r0,a
   0495 A6 02              1294 	mov	@r0,ar2
   0497 80 A1              1295 	sjmp	00102$
   0499                    1296 00106$:
                           1297 ;	D:\Workspace\MIDE\firmware\/uart.c:504: var_numOfDigitsToTransmit_u8 = C_MaxDigitsToTransmitUsingPrintf_U8;
   0499 E5 13              1298 	mov	a,_bp
   049B 24 0B              1299 	add	a,#0x0b
   049D F8                 1300 	mov	r0,a
   049E 76 FF              1301 	mov	@r0,#0xFF
                           1302 ;	D:\Workspace\MIDE\firmware\/uart.c:617: va_end(argp);
                           1303 ;	D:\Workspace\MIDE\firmware\/uart.c:504: var_numOfDigitsToTransmit_u8 = C_MaxDigitsToTransmitUsingPrintf_U8;
   04A0 80 0D              1304 	sjmp	00107$
   04A2                    1305 00163$:
   04A2 E5 13              1306 	mov	a,_bp
   04A4 24 0C              1307 	add	a,#0x0c
   04A6 F8                 1308 	mov	r0,a
   04A7 86 03              1309 	mov	ar3,@r0
   04A9 08                 1310 	inc	r0
   04AA 86 04              1311 	mov	ar4,@r0
   04AC 08                 1312 	inc	r0
   04AD 86 05              1313 	mov	ar5,@r0
   04AF                    1314 00107$:
                           1315 ;	D:\Workspace\MIDE\firmware\/uart.c:508: switch(ch)       /* Decode the type of the argument */
   04AF E5 13              1316 	mov	a,_bp
   04B1 24 0A              1317 	add	a,#0x0a
   04B3 F8                 1318 	mov	r0,a
   04B4 B6 25 03           1319 	cjne	@r0,#0x25,00173$
   04B7 02 07 FC           1320 	ljmp	00127$
   04BA                    1321 00173$:
   04BA E5 13              1322 	mov	a,_bp
   04BC 24 0A              1323 	add	a,#0x0a
   04BE F8                 1324 	mov	r0,a
   04BF B6 42 03           1325 	cjne	@r0,#0x42,00174$
   04C2 02 07 BD           1326 	ljmp	00122$
   04C5                    1327 00174$:
   04C5 E5 13              1328 	mov	a,_bp
   04C7 24 0A              1329 	add	a,#0x0a
   04C9 F8                 1330 	mov	r0,a
   04CA B6 43 03           1331 	cjne	@r0,#0x43,00175$
   04CD 02 05 55           1332 	ljmp	00110$
   04D0                    1333 00175$:
   04D0 E5 13              1334 	mov	a,_bp
   04D2 24 0A              1335 	add	a,#0x0a
   04D4 F8                 1336 	mov	r0,a
   04D5 B6 44 03           1337 	cjne	@r0,#0x44,00176$
   04D8 02 05 F3           1338 	ljmp	00114$
   04DB                    1339 00176$:
   04DB E5 13              1340 	mov	a,_bp
   04DD 24 0A              1341 	add	a,#0x0a
   04DF F8                 1342 	mov	r0,a
   04E0 B6 46 03           1343 	cjne	@r0,#0x46,00177$
   04E3 02 07 C6           1344 	ljmp	00124$
   04E6                    1345 00177$:
   04E6 E5 13              1346 	mov	a,_bp
   04E8 24 0A              1347 	add	a,#0x0a
   04EA F8                 1348 	mov	r0,a
   04EB B6 53 03           1349 	cjne	@r0,#0x53,00178$
   04EE 02 07 CF           1350 	ljmp	00126$
   04F1                    1351 00178$:
   04F1 E5 13              1352 	mov	a,_bp
   04F3 24 0A              1353 	add	a,#0x0a
   04F5 F8                 1354 	mov	r0,a
   04F6 B6 55 03           1355 	cjne	@r0,#0x55,00179$
   04F9 02 06 BC           1356 	ljmp	00118$
   04FC                    1357 00179$:
   04FC E5 13              1358 	mov	a,_bp
   04FE 24 0A              1359 	add	a,#0x0a
   0500 F8                 1360 	mov	r0,a
   0501 B6 58 03           1361 	cjne	@r0,#0x58,00180$
   0504 02 07 56           1362 	ljmp	00120$
   0507                    1363 00180$:
   0507 E5 13              1364 	mov	a,_bp
   0509 24 0A              1365 	add	a,#0x0a
   050B F8                 1366 	mov	r0,a
   050C B6 62 03           1367 	cjne	@r0,#0x62,00181$
   050F 02 07 B6           1368 	ljmp	00121$
   0512                    1369 00181$:
   0512 E5 13              1370 	mov	a,_bp
   0514 24 0A              1371 	add	a,#0x0a
   0516 F8                 1372 	mov	r0,a
   0517 B6 63 02           1373 	cjne	@r0,#0x63,00182$
   051A 80 39              1374 	sjmp	00110$
   051C                    1375 00182$:
   051C E5 13              1376 	mov	a,_bp
   051E 24 0A              1377 	add	a,#0x0a
   0520 F8                 1378 	mov	r0,a
   0521 B6 64 02           1379 	cjne	@r0,#0x64,00183$
   0524 80 61              1380 	sjmp	00111$
   0526                    1381 00183$:
   0526 E5 13              1382 	mov	a,_bp
   0528 24 0A              1383 	add	a,#0x0a
   052A F8                 1384 	mov	r0,a
   052B B6 66 03           1385 	cjne	@r0,#0x66,00184$
   052E 02 07 C6           1386 	ljmp	00124$
   0531                    1387 00184$:
   0531 E5 13              1388 	mov	a,_bp
   0533 24 0A              1389 	add	a,#0x0a
   0535 F8                 1390 	mov	r0,a
   0536 B6 73 03           1391 	cjne	@r0,#0x73,00185$
   0539 02 07 CF           1392 	ljmp	00126$
   053C                    1393 00185$:
   053C E5 13              1394 	mov	a,_bp
   053E 24 0A              1395 	add	a,#0x0a
   0540 F8                 1396 	mov	r0,a
   0541 B6 75 03           1397 	cjne	@r0,#0x75,00186$
   0544 02 06 73           1398 	ljmp	00117$
   0547                    1399 00186$:
   0547 E5 13              1400 	mov	a,_bp
   0549 24 0A              1401 	add	a,#0x0a
   054B F8                 1402 	mov	r0,a
   054C B6 78 03           1403 	cjne	@r0,#0x78,00187$
   054F 02 07 0D           1404 	ljmp	00119$
   0552                    1405 00187$:
   0552 02 08 26           1406 	ljmp	00134$
                           1407 ;	D:\Workspace\MIDE\firmware\/uart.c:511: case 'c':     /* Argument type is of char, hence read char data from the argp */
   0555                    1408 00110$:
                           1409 ;	D:\Workspace\MIDE\firmware\/uart.c:512: ch = va_arg(argp, uint16_t);
   0555 A9 13              1410 	mov	r1,_bp
   0557 09                 1411 	inc	r1
   0558 E7                 1412 	mov	a,@r1
   0559 24 FE              1413 	add	a,#0xfe
   055B F8                 1414 	mov	r0,a
   055C A9 13              1415 	mov	r1,_bp
   055E 09                 1416 	inc	r1
   055F A7 00              1417 	mov	@r1,ar0
   0561 86 02              1418 	mov	ar2,@r0
   0563 08                 1419 	inc	r0
   0564 86 06              1420 	mov	ar6,@r0
   0566 18                 1421 	dec	r0
   0567 E5 13              1422 	mov	a,_bp
   0569 24 0A              1423 	add	a,#0x0a
   056B F8                 1424 	mov	r0,a
   056C A6 02              1425 	mov	@r0,ar2
                           1426 ;	D:\Workspace\MIDE\firmware\/uart.c:513: UART_TxChar(ch);
   056E E5 13              1427 	mov	a,_bp
   0570 24 0A              1428 	add	a,#0x0a
   0572 F8                 1429 	mov	r0,a
   0573 86 82              1430 	mov	dpl,@r0
   0575 C0 03              1431 	push	ar3
   0577 C0 04              1432 	push	ar4
   0579 C0 05              1433 	push	ar5
   057B 12 00 FF           1434 	lcall	_UART_TxChar
   057E D0 05              1435 	pop	ar5
   0580 D0 04              1436 	pop	ar4
   0582 D0 03              1437 	pop	ar3
                           1438 ;	D:\Workspace\MIDE\firmware\/uart.c:514: break;
   0584 02 08 26           1439 	ljmp	00134$
                           1440 ;	D:\Workspace\MIDE\firmware\/uart.c:516: case 'd':    /* Argument type is of signed integer, hence read 16bit data from the argp */
   0587                    1441 00111$:
                           1442 ;	D:\Workspace\MIDE\firmware\/uart.c:517: var_num_s16 = va_arg(argp, sint16_t);
   0587 A9 13              1443 	mov	r1,_bp
   0589 09                 1444 	inc	r1
   058A E7                 1445 	mov	a,@r1
   058B 24 FE              1446 	add	a,#0xfe
   058D F8                 1447 	mov	r0,a
   058E A9 13              1448 	mov	r1,_bp
   0590 09                 1449 	inc	r1
   0591 A7 00              1450 	mov	@r1,ar0
   0593 86 02              1451 	mov	ar2,@r0
   0595 08                 1452 	inc	r0
   0596 86 06              1453 	mov	ar6,@r0
   0598 18                 1454 	dec	r0
                           1455 ;	D:\Workspace\MIDE\firmware\/uart.c:519: if(var_num_s16<0)
   0599 EE                 1456 	mov	a,r6
   059A 30 E7 21           1457 	jnb	acc.7,00113$
                           1458 ;	D:\Workspace\MIDE\firmware\/uart.c:521: var_num_s16 = -var_num_s16;
   059D C3                 1459 	clr	c
   059E E4                 1460 	clr	a
   059F 9A                 1461 	subb	a,r2
   05A0 FA                 1462 	mov	r2,a
   05A1 E4                 1463 	clr	a
   05A2 9E                 1464 	subb	a,r6
   05A3 FE                 1465 	mov	r6,a
                           1466 ;	D:\Workspace\MIDE\firmware\/uart.c:522: UART_TxChar('-');
   05A4 75 82 2D           1467 	mov	dpl,#0x2D
   05A7 C0 02              1468 	push	ar2
   05A9 C0 03              1469 	push	ar3
   05AB C0 04              1470 	push	ar4
   05AD C0 05              1471 	push	ar5
   05AF C0 06              1472 	push	ar6
   05B1 12 00 FF           1473 	lcall	_UART_TxChar
   05B4 D0 06              1474 	pop	ar6
   05B6 D0 05              1475 	pop	ar5
   05B8 D0 04              1476 	pop	ar4
   05BA D0 03              1477 	pop	ar3
   05BC D0 02              1478 	pop	ar2
   05BE                    1479 00113$:
                           1480 ;	D:\Workspace\MIDE\firmware\/uart.c:524: UART_TxDecimalNumber(var_num_s16,var_numOfDigitsToTransmit_u8);
   05BE C0 03              1481 	push	ar3
   05C0 C0 04              1482 	push	ar4
   05C2 C0 05              1483 	push	ar5
   05C4 EE                 1484 	mov	a,r6
   05C5 33                 1485 	rlc	a
   05C6 95 E0              1486 	subb	a,acc
   05C8 FF                 1487 	mov	r7,a
   05C9 FB                 1488 	mov	r3,a
   05CA C0 03              1489 	push	ar3
   05CC C0 04              1490 	push	ar4
   05CE C0 05              1491 	push	ar5
   05D0 E5 13              1492 	mov	a,_bp
   05D2 24 0B              1493 	add	a,#0x0b
   05D4 F8                 1494 	mov	r0,a
   05D5 E6                 1495 	mov	a,@r0
   05D6 C0 E0              1496 	push	acc
   05D8 8A 82              1497 	mov	dpl,r2
   05DA 8E 83              1498 	mov	dph,r6
   05DC 8F F0              1499 	mov	b,r7
   05DE EB                 1500 	mov	a,r3
   05DF 12 01 33           1501 	lcall	_UART_TxDecimalNumber
   05E2 15 81              1502 	dec	sp
   05E4 D0 05              1503 	pop	ar5
   05E6 D0 04              1504 	pop	ar4
   05E8 D0 03              1505 	pop	ar3
                           1506 ;	D:\Workspace\MIDE\firmware\/uart.c:526: break;
   05EA D0 05              1507 	pop	ar5
   05EC D0 04              1508 	pop	ar4
   05EE D0 03              1509 	pop	ar3
   05F0 02 08 26           1510 	ljmp	00134$
                           1511 ;	D:\Workspace\MIDE\firmware\/uart.c:528: case 'D':    /* Argument type is of integer, hence read 16bit data from the argp */
   05F3                    1512 00114$:
                           1513 ;	D:\Workspace\MIDE\firmware\/uart.c:529: var_num_s32 = va_arg(argp, sint32_t);
   05F3 A9 13              1514 	mov	r1,_bp
   05F5 09                 1515 	inc	r1
   05F6 E7                 1516 	mov	a,@r1
   05F7 24 FC              1517 	add	a,#0xfc
   05F9 F8                 1518 	mov	r0,a
   05FA A9 13              1519 	mov	r1,_bp
   05FC 09                 1520 	inc	r1
   05FD A7 00              1521 	mov	@r1,ar0
   05FF A9 13              1522 	mov	r1,_bp
   0601 09                 1523 	inc	r1
   0602 09                 1524 	inc	r1
   0603 E6                 1525 	mov	a,@r0
   0604 F7                 1526 	mov	@r1,a
   0605 08                 1527 	inc	r0
   0606 E6                 1528 	mov	a,@r0
   0607 09                 1529 	inc	r1
   0608 F7                 1530 	mov	@r1,a
   0609 08                 1531 	inc	r0
   060A E6                 1532 	mov	a,@r0
   060B 09                 1533 	inc	r1
   060C F7                 1534 	mov	@r1,a
   060D 08                 1535 	inc	r0
   060E E6                 1536 	mov	a,@r0
   060F 09                 1537 	inc	r1
   0610 F7                 1538 	mov	@r1,a
   0611 18                 1539 	dec	r0
   0612 18                 1540 	dec	r0
   0613 18                 1541 	dec	r0
   0614 A8 13              1542 	mov	r0,_bp
   0616 08                 1543 	inc	r0
   0617 08                 1544 	inc	r0
                           1545 ;	D:\Workspace\MIDE\firmware\/uart.c:531: if(var_num_s32<0)
   0618 A8 13              1546 	mov	r0,_bp
   061A 08                 1547 	inc	r0
   061B 08                 1548 	inc	r0
   061C 08                 1549 	inc	r0
   061D 08                 1550 	inc	r0
   061E 08                 1551 	inc	r0
   061F E6                 1552 	mov	a,@r0
   0620 30 E7 26           1553 	jnb	acc.7,00116$
                           1554 ;	D:\Workspace\MIDE\firmware\/uart.c:533: var_num_s32 = -var_num_s32;
   0623 A8 13              1555 	mov	r0,_bp
   0625 08                 1556 	inc	r0
   0626 08                 1557 	inc	r0
   0627 C3                 1558 	clr	c
   0628 E4                 1559 	clr	a
   0629 96                 1560 	subb	a,@r0
   062A F6                 1561 	mov	@r0,a
   062B 08                 1562 	inc	r0
   062C E4                 1563 	clr	a
   062D 96                 1564 	subb	a,@r0
   062E F6                 1565 	mov	@r0,a
   062F 08                 1566 	inc	r0
   0630 E4                 1567 	clr	a
   0631 96                 1568 	subb	a,@r0
   0632 F6                 1569 	mov	@r0,a
   0633 08                 1570 	inc	r0
   0634 E4                 1571 	clr	a
   0635 96                 1572 	subb	a,@r0
   0636 F6                 1573 	mov	@r0,a
                           1574 ;	D:\Workspace\MIDE\firmware\/uart.c:534: UART_TxChar('-');
   0637 75 82 2D           1575 	mov	dpl,#0x2D
   063A C0 03              1576 	push	ar3
   063C C0 04              1577 	push	ar4
   063E C0 05              1578 	push	ar5
   0640 12 00 FF           1579 	lcall	_UART_TxChar
   0643 D0 05              1580 	pop	ar5
   0645 D0 04              1581 	pop	ar4
   0647 D0 03              1582 	pop	ar3
   0649                    1583 00116$:
                           1584 ;	D:\Workspace\MIDE\firmware\/uart.c:536: UART_TxDecimalNumber(var_num_s32,var_numOfDigitsToTransmit_u8);
   0649 C0 03              1585 	push	ar3
   064B C0 04              1586 	push	ar4
   064D C0 05              1587 	push	ar5
   064F E5 13              1588 	mov	a,_bp
   0651 24 0B              1589 	add	a,#0x0b
   0653 F8                 1590 	mov	r0,a
   0654 E6                 1591 	mov	a,@r0
   0655 C0 E0              1592 	push	acc
   0657 A8 13              1593 	mov	r0,_bp
   0659 08                 1594 	inc	r0
   065A 08                 1595 	inc	r0
   065B 86 82              1596 	mov	dpl,@r0
   065D 08                 1597 	inc	r0
   065E 86 83              1598 	mov	dph,@r0
   0660 08                 1599 	inc	r0
   0661 86 F0              1600 	mov	b,@r0
   0663 08                 1601 	inc	r0
   0664 E6                 1602 	mov	a,@r0
   0665 12 01 33           1603 	lcall	_UART_TxDecimalNumber
   0668 15 81              1604 	dec	sp
   066A D0 05              1605 	pop	ar5
   066C D0 04              1606 	pop	ar4
   066E D0 03              1607 	pop	ar3
                           1608 ;	D:\Workspace\MIDE\firmware\/uart.c:538: break;	
   0670 02 08 26           1609 	ljmp	00134$
                           1610 ;	D:\Workspace\MIDE\firmware\/uart.c:540: case 'u':    /* Argument type is of unsigned integer, hence read 16bit unsigned data */
   0673                    1611 00117$:
                           1612 ;	D:\Workspace\MIDE\firmware\/uart.c:541: var_num_u16 = va_arg(argp, uint16_t);
   0673 C0 03              1613 	push	ar3
   0675 C0 04              1614 	push	ar4
   0677 C0 05              1615 	push	ar5
   0679 A9 13              1616 	mov	r1,_bp
   067B 09                 1617 	inc	r1
   067C E7                 1618 	mov	a,@r1
   067D 24 FE              1619 	add	a,#0xfe
   067F F8                 1620 	mov	r0,a
   0680 A9 13              1621 	mov	r1,_bp
   0682 09                 1622 	inc	r1
   0683 A7 00              1623 	mov	@r1,ar0
   0685 86 02              1624 	mov	ar2,@r0
   0687 08                 1625 	inc	r0
   0688 86 06              1626 	mov	ar6,@r0
   068A 18                 1627 	dec	r0
                           1628 ;	D:\Workspace\MIDE\firmware\/uart.c:543: UART_TxDecimalNumber(var_num_u16,var_numOfDigitsToTransmit_u8);
   068B 8A 07              1629 	mov	ar7,r2
   068D 8E 03              1630 	mov	ar3,r6
   068F 7C 00              1631 	mov	r4,#0x00
   0691 7D 00              1632 	mov	r5,#0x00
   0693 C0 03              1633 	push	ar3
   0695 C0 04              1634 	push	ar4
   0697 C0 05              1635 	push	ar5
   0699 E5 13              1636 	mov	a,_bp
   069B 24 0B              1637 	add	a,#0x0b
   069D F8                 1638 	mov	r0,a
   069E E6                 1639 	mov	a,@r0
   069F C0 E0              1640 	push	acc
   06A1 8F 82              1641 	mov	dpl,r7
   06A3 8B 83              1642 	mov	dph,r3
   06A5 8C F0              1643 	mov	b,r4
   06A7 ED                 1644 	mov	a,r5
   06A8 12 01 33           1645 	lcall	_UART_TxDecimalNumber
   06AB 15 81              1646 	dec	sp
   06AD D0 05              1647 	pop	ar5
   06AF D0 04              1648 	pop	ar4
   06B1 D0 03              1649 	pop	ar3
                           1650 ;	D:\Workspace\MIDE\firmware\/uart.c:545: break;
   06B3 D0 05              1651 	pop	ar5
   06B5 D0 04              1652 	pop	ar4
   06B7 D0 03              1653 	pop	ar3
   06B9 02 08 26           1654 	ljmp	00134$
                           1655 ;	D:\Workspace\MIDE\firmware\/uart.c:547: case 'U':    /* Argument type is of integer, hence read 32bit unsigend data */
   06BC                    1656 00118$:
                           1657 ;	D:\Workspace\MIDE\firmware\/uart.c:548: var_num_u32 = va_arg(argp, uint32_t);
   06BC A9 13              1658 	mov	r1,_bp
   06BE 09                 1659 	inc	r1
   06BF E7                 1660 	mov	a,@r1
   06C0 24 FC              1661 	add	a,#0xfc
   06C2 F8                 1662 	mov	r0,a
   06C3 A9 13              1663 	mov	r1,_bp
   06C5 09                 1664 	inc	r1
   06C6 A7 00              1665 	mov	@r1,ar0
   06C8 E5 13              1666 	mov	a,_bp
   06CA 24 06              1667 	add	a,#0x06
   06CC F9                 1668 	mov	r1,a
   06CD E6                 1669 	mov	a,@r0
   06CE F7                 1670 	mov	@r1,a
   06CF 08                 1671 	inc	r0
   06D0 E6                 1672 	mov	a,@r0
   06D1 09                 1673 	inc	r1
   06D2 F7                 1674 	mov	@r1,a
   06D3 08                 1675 	inc	r0
   06D4 E6                 1676 	mov	a,@r0
   06D5 09                 1677 	inc	r1
   06D6 F7                 1678 	mov	@r1,a
   06D7 08                 1679 	inc	r0
   06D8 E6                 1680 	mov	a,@r0
   06D9 09                 1681 	inc	r1
   06DA F7                 1682 	mov	@r1,a
   06DB 18                 1683 	dec	r0
   06DC 18                 1684 	dec	r0
   06DD 18                 1685 	dec	r0
   06DE E5 13              1686 	mov	a,_bp
   06E0 24 06              1687 	add	a,#0x06
                           1688 ;	D:\Workspace\MIDE\firmware\/uart.c:550: UART_TxDecimalNumber(var_num_u32,var_numOfDigitsToTransmit_u8);
   06E2 C0 03              1689 	push	ar3
   06E4 C0 04              1690 	push	ar4
   06E6 C0 05              1691 	push	ar5
   06E8 E5 13              1692 	mov	a,_bp
   06EA 24 0B              1693 	add	a,#0x0b
   06EC F8                 1694 	mov	r0,a
   06ED E6                 1695 	mov	a,@r0
   06EE C0 E0              1696 	push	acc
   06F0 E5 13              1697 	mov	a,_bp
   06F2 24 06              1698 	add	a,#0x06
   06F4 F8                 1699 	mov	r0,a
   06F5 86 82              1700 	mov	dpl,@r0
   06F7 08                 1701 	inc	r0
   06F8 86 83              1702 	mov	dph,@r0
   06FA 08                 1703 	inc	r0
   06FB 86 F0              1704 	mov	b,@r0
   06FD 08                 1705 	inc	r0
   06FE E6                 1706 	mov	a,@r0
   06FF 12 01 33           1707 	lcall	_UART_TxDecimalNumber
   0702 15 81              1708 	dec	sp
   0704 D0 05              1709 	pop	ar5
   0706 D0 04              1710 	pop	ar4
   0708 D0 03              1711 	pop	ar3
                           1712 ;	D:\Workspace\MIDE\firmware\/uart.c:552: break;			
   070A 02 08 26           1713 	ljmp	00134$
                           1714 ;	D:\Workspace\MIDE\firmware\/uart.c:554: case 'x':  /* Argument type is of hex, hence hexadecimal data from the argp */
   070D                    1715 00119$:
                           1716 ;	D:\Workspace\MIDE\firmware\/uart.c:555: var_num_u16 = va_arg(argp, uint16_t);
   070D C0 03              1717 	push	ar3
   070F C0 04              1718 	push	ar4
   0711 C0 05              1719 	push	ar5
   0713 A9 13              1720 	mov	r1,_bp
   0715 09                 1721 	inc	r1
   0716 E7                 1722 	mov	a,@r1
   0717 24 FE              1723 	add	a,#0xfe
   0719 F8                 1724 	mov	r0,a
   071A A9 13              1725 	mov	r1,_bp
   071C 09                 1726 	inc	r1
   071D A7 00              1727 	mov	@r1,ar0
   071F 86 07              1728 	mov	ar7,@r0
   0721 08                 1729 	inc	r0
   0722 86 03              1730 	mov	ar3,@r0
   0724 18                 1731 	dec	r0
   0725 8F 02              1732 	mov	ar2,r7
   0727 8B 06              1733 	mov	ar6,r3
                           1734 ;	D:\Workspace\MIDE\firmware\/uart.c:557: UART_TxHexNumber(var_num_u16,var_numOfDigitsToTransmit_u8);
   0729 7B 00              1735 	mov	r3,#0x00
   072B 7C 00              1736 	mov	r4,#0x00
   072D C0 03              1737 	push	ar3
   072F C0 04              1738 	push	ar4
   0731 C0 05              1739 	push	ar5
   0733 E5 13              1740 	mov	a,_bp
   0735 24 0B              1741 	add	a,#0x0b
   0737 F8                 1742 	mov	r0,a
   0738 E6                 1743 	mov	a,@r0
   0739 C0 E0              1744 	push	acc
   073B 8A 82              1745 	mov	dpl,r2
   073D 8E 83              1746 	mov	dph,r6
   073F 8B F0              1747 	mov	b,r3
   0741 EC                 1748 	mov	a,r4
   0742 12 02 8B           1749 	lcall	_UART_TxHexNumber
   0745 15 81              1750 	dec	sp
   0747 D0 05              1751 	pop	ar5
   0749 D0 04              1752 	pop	ar4
   074B D0 03              1753 	pop	ar3
                           1754 ;	D:\Workspace\MIDE\firmware\/uart.c:559: break;
   074D D0 05              1755 	pop	ar5
   074F D0 04              1756 	pop	ar4
   0751 D0 03              1757 	pop	ar3
   0753 02 08 26           1758 	ljmp	00134$
                           1759 ;	D:\Workspace\MIDE\firmware\/uart.c:561: case 'X':  /* Argument type is of hex, hence hexadecimal data from the argp */
   0756                    1760 00120$:
                           1761 ;	D:\Workspace\MIDE\firmware\/uart.c:562: var_num_u32 = va_arg(argp, uint32_t);
   0756 C0 03              1762 	push	ar3
   0758 C0 04              1763 	push	ar4
   075A C0 05              1764 	push	ar5
   075C A9 13              1765 	mov	r1,_bp
   075E 09                 1766 	inc	r1
   075F E7                 1767 	mov	a,@r1
   0760 24 FC              1768 	add	a,#0xfc
   0762 F8                 1769 	mov	r0,a
   0763 A9 13              1770 	mov	r1,_bp
   0765 09                 1771 	inc	r1
   0766 A7 00              1772 	mov	@r1,ar0
   0768 86 02              1773 	mov	ar2,@r0
   076A 08                 1774 	inc	r0
   076B 86 06              1775 	mov	ar6,@r0
   076D 08                 1776 	inc	r0
   076E 86 07              1777 	mov	ar7,@r0
   0770 08                 1778 	inc	r0
   0771 86 03              1779 	mov	ar3,@r0
   0773 18                 1780 	dec	r0
   0774 18                 1781 	dec	r0
   0775 18                 1782 	dec	r0
   0776 E5 13              1783 	mov	a,_bp
   0778 24 06              1784 	add	a,#0x06
   077A F8                 1785 	mov	r0,a
   077B A6 02              1786 	mov	@r0,ar2
   077D 08                 1787 	inc	r0
   077E A6 06              1788 	mov	@r0,ar6
   0780 08                 1789 	inc	r0
   0781 A6 07              1790 	mov	@r0,ar7
   0783 08                 1791 	inc	r0
   0784 A6 03              1792 	mov	@r0,ar3
                           1793 ;	D:\Workspace\MIDE\firmware\/uart.c:564: UART_TxHexNumber(var_num_u32,var_numOfDigitsToTransmit_u8);
   0786 C0 03              1794 	push	ar3
   0788 C0 04              1795 	push	ar4
   078A C0 05              1796 	push	ar5
   078C E5 13              1797 	mov	a,_bp
   078E 24 0B              1798 	add	a,#0x0b
   0790 F8                 1799 	mov	r0,a
   0791 E6                 1800 	mov	a,@r0
   0792 C0 E0              1801 	push	acc
   0794 E5 13              1802 	mov	a,_bp
   0796 24 06              1803 	add	a,#0x06
   0798 F8                 1804 	mov	r0,a
   0799 86 82              1805 	mov	dpl,@r0
   079B 08                 1806 	inc	r0
   079C 86 83              1807 	mov	dph,@r0
   079E 08                 1808 	inc	r0
   079F 86 F0              1809 	mov	b,@r0
   07A1 08                 1810 	inc	r0
   07A2 E6                 1811 	mov	a,@r0
   07A3 12 02 8B           1812 	lcall	_UART_TxHexNumber
   07A6 15 81              1813 	dec	sp
   07A8 D0 05              1814 	pop	ar5
   07AA D0 04              1815 	pop	ar4
   07AC D0 03              1816 	pop	ar3
                           1817 ;	D:\Workspace\MIDE\firmware\/uart.c:566: break;
   07AE D0 05              1818 	pop	ar5
   07B0 D0 04              1819 	pop	ar4
   07B2 D0 03              1820 	pop	ar3
                           1821 ;	D:\Workspace\MIDE\firmware\/uart.c:569: case 'b':  /* Argument type is of binary,Read int and convert to binary */
   07B4 80 70              1822 	sjmp	00134$
   07B6                    1823 00121$:
                           1824 ;	D:\Workspace\MIDE\firmware\/uart.c:570: var_num_u16 = va_arg(argp, uint16_t);
   07B6 A8 13              1825 	mov	r0,_bp
   07B8 08                 1826 	inc	r0
   07B9 16                 1827 	dec	@r0
   07BA 16                 1828 	dec	@r0
                           1829 ;	D:\Workspace\MIDE\firmware\/uart.c:576: break;
                           1830 ;	D:\Workspace\MIDE\firmware\/uart.c:578: case 'B':  /* Argument type is of binary,Read int and convert to binary */
   07BB 80 69              1831 	sjmp	00134$
   07BD                    1832 00122$:
                           1833 ;	D:\Workspace\MIDE\firmware\/uart.c:579: var_num_u32 = va_arg(argp, uint32_t);
   07BD A8 13              1834 	mov	r0,_bp
   07BF 08                 1835 	inc	r0
   07C0 16                 1836 	dec	@r0
   07C1 16                 1837 	dec	@r0
   07C2 16                 1838 	dec	@r0
   07C3 16                 1839 	dec	@r0
                           1840 ;	D:\Workspace\MIDE\firmware\/uart.c:585: break;
                           1841 ;	D:\Workspace\MIDE\firmware\/uart.c:589: case 'f': /* Argument type is of float, hence read double data from the argp */
   07C4 80 60              1842 	sjmp	00134$
   07C6                    1843 00124$:
                           1844 ;	D:\Workspace\MIDE\firmware\/uart.c:590: var_floatNum_f32 = va_arg(argp, double);
   07C6 A8 13              1845 	mov	r0,_bp
   07C8 08                 1846 	inc	r0
   07C9 16                 1847 	dec	@r0
   07CA 16                 1848 	dec	@r0
   07CB 16                 1849 	dec	@r0
   07CC 16                 1850 	dec	@r0
                           1851 ;	D:\Workspace\MIDE\firmware\/uart.c:594: break;
                           1852 ;	D:\Workspace\MIDE\firmware\/uart.c:598: case 's': /* Argument type is of string, hence get the pointer to sting passed */
   07CD 80 57              1853 	sjmp	00134$
   07CF                    1854 00126$:
                           1855 ;	D:\Workspace\MIDE\firmware\/uart.c:599: str = va_arg(argp, char *);
   07CF A9 13              1856 	mov	r1,_bp
   07D1 09                 1857 	inc	r1
   07D2 E7                 1858 	mov	a,@r1
   07D3 24 FD              1859 	add	a,#0xfd
   07D5 F8                 1860 	mov	r0,a
   07D6 A9 13              1861 	mov	r1,_bp
   07D8 09                 1862 	inc	r1
   07D9 A7 00              1863 	mov	@r1,ar0
   07DB 86 02              1864 	mov	ar2,@r0
   07DD 08                 1865 	inc	r0
   07DE 86 06              1866 	mov	ar6,@r0
   07E0 08                 1867 	inc	r0
   07E1 86 07              1868 	mov	ar7,@r0
   07E3 18                 1869 	dec	r0
   07E4 18                 1870 	dec	r0
                           1871 ;	D:\Workspace\MIDE\firmware\/uart.c:601: UART_TxString(str);
   07E5 8A 82              1872 	mov	dpl,r2
   07E7 8E 83              1873 	mov	dph,r6
   07E9 8F F0              1874 	mov	b,r7
   07EB C0 03              1875 	push	ar3
   07ED C0 04              1876 	push	ar4
   07EF C0 05              1877 	push	ar5
   07F1 12 01 08           1878 	lcall	_UART_TxString
   07F4 D0 05              1879 	pop	ar5
   07F6 D0 04              1880 	pop	ar4
   07F8 D0 03              1881 	pop	ar3
                           1882 ;	D:\Workspace\MIDE\firmware\/uart.c:603: break;
                           1883 ;	D:\Workspace\MIDE\firmware\/uart.c:605: case '%':
   07FA 80 2A              1884 	sjmp	00134$
   07FC                    1885 00127$:
                           1886 ;	D:\Workspace\MIDE\firmware\/uart.c:606: UART_TxChar('%');
   07FC 75 82 25           1887 	mov	dpl,#0x25
   07FF C0 03              1888 	push	ar3
   0801 C0 04              1889 	push	ar4
   0803 C0 05              1890 	push	ar5
   0805 12 00 FF           1891 	lcall	_UART_TxChar
   0808 D0 05              1892 	pop	ar5
   080A D0 04              1893 	pop	ar4
   080C D0 03              1894 	pop	ar3
                           1895 ;	D:\Workspace\MIDE\firmware\/uart.c:608: }
   080E 80 16              1896 	sjmp	00134$
   0810                    1897 00130$:
                           1898 ;	D:\Workspace\MIDE\firmware\/uart.c:613: UART_TxChar(ch);
   0810 E5 13              1899 	mov	a,_bp
   0812 24 0A              1900 	add	a,#0x0a
   0814 F8                 1901 	mov	r0,a
   0815 86 82              1902 	mov	dpl,@r0
   0817 C0 03              1903 	push	ar3
   0819 C0 04              1904 	push	ar4
   081B C0 05              1905 	push	ar5
   081D 12 00 FF           1906 	lcall	_UART_TxChar
   0820 D0 05              1907 	pop	ar5
   0822 D0 04              1908 	pop	ar4
   0824 D0 03              1909 	pop	ar3
   0826                    1910 00134$:
                           1911 ;	D:\Workspace\MIDE\firmware\/uart.c:484: for(ptr = argList; *ptr != '\0'; ptr++)
   0826 0B                 1912 	inc	r3
   0827 BB 00 01           1913 	cjne	r3,#0x00,00190$
   082A 0C                 1914 	inc	r4
   082B                    1915 00190$:
   082B 02 03 C8           1916 	ljmp	00132$
                           1917 ;	D:\Workspace\MIDE\firmware\/uart.c:617: va_end(argp);
   082E                    1918 00136$:
   082E 85 13 81           1919 	mov	sp,_bp
   0831 D0 13              1920 	pop	_bp
   0833 22                 1921 	ret
                           1922 ;------------------------------------------------------------
                           1923 ;Allocation info for local variables in function 'RTC_Init'
                           1924 ;------------------------------------------------------------
                           1925 ;------------------------------------------------------------
                           1926 ;	D:\Workspace\MIDE\firmware\/rtc.c:57: void RTC_Init()
                           1927 ;	-----------------------------------------
                           1928 ;	 function RTC_Init
                           1929 ;	-----------------------------------------
   0834                    1930 _RTC_Init:
                           1931 ;	D:\Workspace\MIDE\firmware\/rtc.c:59: I2C_Init();                             // Initialize the I2c module.
   0834 12 09 FD           1932 	lcall	_I2C_Init
                           1933 ;	D:\Workspace\MIDE\firmware\/rtc.c:60: I2C_Start();                            // Start I2C communication
   0837 12 09 FE           1934 	lcall	_I2C_Start
                           1935 ;	D:\Workspace\MIDE\firmware\/rtc.c:62: I2C_Write(C_Ds1307WriteMode_U8);        // Connect to DS1307 by sending its ID on I2c Bus
   083A 75 82 D0           1936 	mov	dpl,#0xD0
   083D 12 0A 3F           1937 	lcall	_I2C_Write
                           1938 ;	D:\Workspace\MIDE\firmware\/rtc.c:63: I2C_Write(C_Ds1307ControlRegAddress_U8);// Select the Ds1307 ControlRegister to configure Ds1307
   0840 75 82 07           1939 	mov	dpl,#0x07
   0843 12 0A 3F           1940 	lcall	_I2C_Write
                           1941 ;	D:\Workspace\MIDE\firmware\/rtc.c:65: I2C_Write(0x00);                        // Write 0x00 to Control register to disable SQW-Out
   0846 75 82 00           1942 	mov	dpl,#0x00
   0849 12 0A 3F           1943 	lcall	_I2C_Write
                           1944 ;	D:\Workspace\MIDE\firmware\/rtc.c:67: I2C_Stop();                             // Stop I2C communication after initializing DS1307
   084C 02 0A 20           1945 	ljmp	_I2C_Stop
                           1946 ;------------------------------------------------------------
                           1947 ;Allocation info for local variables in function 'RTC_SetTime'
                           1948 ;------------------------------------------------------------
                           1949 ;var_min_u8                Allocated to stack - offset -3
                           1950 ;var_sec_u8                Allocated to stack - offset -4
                           1951 ;var_hour_u8               Allocated to registers r2 
                           1952 ;------------------------------------------------------------
                           1953 ;	D:\Workspace\MIDE\firmware\/rtc.c:86: void RTC_SetTime(uint8_t var_hour_u8, uint8_t var_min_u8, uint8_t var_sec_u8)
                           1954 ;	-----------------------------------------
                           1955 ;	 function RTC_SetTime
                           1956 ;	-----------------------------------------
   084F                    1957 _RTC_SetTime:
   084F C0 13              1958 	push	_bp
   0851 85 81 13           1959 	mov	_bp,sp
   0854 AA 82              1960 	mov	r2,dpl
                           1961 ;	D:\Workspace\MIDE\firmware\/rtc.c:88: I2C_Start();                            // Start I2C communication
   0856 C0 02              1962 	push	ar2
   0858 12 09 FE           1963 	lcall	_I2C_Start
                           1964 ;	D:\Workspace\MIDE\firmware\/rtc.c:90: I2C_Write(C_Ds1307WriteMode_U8);        // connect to DS1307 by sending its ID on I2c Bus
   085B 75 82 D0           1965 	mov	dpl,#0xD0
   085E 12 0A 3F           1966 	lcall	_I2C_Write
                           1967 ;	D:\Workspace\MIDE\firmware\/rtc.c:91: I2C_Write(C_Ds1307SecondRegAddress_U8); // Select the SEC RAM address
   0861 75 82 00           1968 	mov	dpl,#0x00
   0864 12 0A 3F           1969 	lcall	_I2C_Write
                           1970 ;	D:\Workspace\MIDE\firmware\/rtc.c:93: I2C_Write(var_sec_u8);			        // Write sec from RAM address 00H
   0867 E5 13              1971 	mov	a,_bp
   0869 24 FC              1972 	add	a,#0xfc
   086B F8                 1973 	mov	r0,a
   086C 86 82              1974 	mov	dpl,@r0
   086E 12 0A 3F           1975 	lcall	_I2C_Write
                           1976 ;	D:\Workspace\MIDE\firmware\/rtc.c:94: I2C_Write(var_min_u8);			        // Write min from RAM address 01H
   0871 E5 13              1977 	mov	a,_bp
   0873 24 FD              1978 	add	a,#0xfd
   0875 F8                 1979 	mov	r0,a
   0876 86 82              1980 	mov	dpl,@r0
   0878 12 0A 3F           1981 	lcall	_I2C_Write
   087B D0 02              1982 	pop	ar2
                           1983 ;	D:\Workspace\MIDE\firmware\/rtc.c:95: I2C_Write(var_hour_u8);			        // Write hour from RAM address 02H
   087D 8A 82              1984 	mov	dpl,r2
   087F 12 0A 3F           1985 	lcall	_I2C_Write
                           1986 ;	D:\Workspace\MIDE\firmware\/rtc.c:97: I2C_Stop();           	                // Stop I2C communication after Setting the Time
   0882 12 0A 20           1987 	lcall	_I2C_Stop
   0885 D0 13              1988 	pop	_bp
   0887 22                 1989 	ret
                           1990 ;------------------------------------------------------------
                           1991 ;Allocation info for local variables in function 'RTC_SetDate'
                           1992 ;------------------------------------------------------------
                           1993 ;var_month_u8              Allocated to stack - offset -3
                           1994 ;var_year_u8               Allocated to stack - offset -4
                           1995 ;var_day_u8                Allocated to registers r2 
                           1996 ;------------------------------------------------------------
                           1997 ;	D:\Workspace\MIDE\firmware\/rtc.c:117: void RTC_SetDate(uint8_t var_day_u8, uint8_t var_month_u8, uint8_t var_year_u8)
                           1998 ;	-----------------------------------------
                           1999 ;	 function RTC_SetDate
                           2000 ;	-----------------------------------------
   0888                    2001 _RTC_SetDate:
   0888 C0 13              2002 	push	_bp
   088A 85 81 13           2003 	mov	_bp,sp
   088D AA 82              2004 	mov	r2,dpl
                           2005 ;	D:\Workspace\MIDE\firmware\/rtc.c:119: I2C_Start();                          // Start I2C communication
   088F C0 02              2006 	push	ar2
   0891 12 09 FE           2007 	lcall	_I2C_Start
                           2008 ;	D:\Workspace\MIDE\firmware\/rtc.c:121: I2C_Write(C_Ds1307WriteMode_U8);	  // connect to DS1307 by sending its ID on I2c Bus
   0894 75 82 D0           2009 	mov	dpl,#0xD0
   0897 12 0A 3F           2010 	lcall	_I2C_Write
                           2011 ;	D:\Workspace\MIDE\firmware\/rtc.c:122: I2C_Write(C_Ds1307DateRegAddress_U8); // Request DAY RAM address at 04H
   089A 75 82 04           2012 	mov	dpl,#0x04
   089D 12 0A 3F           2013 	lcall	_I2C_Write
   08A0 D0 02              2014 	pop	ar2
                           2015 ;	D:\Workspace\MIDE\firmware\/rtc.c:124: I2C_Write(var_day_u8);			      // Write date on RAM address 04H
   08A2 8A 82              2016 	mov	dpl,r2
   08A4 12 0A 3F           2017 	lcall	_I2C_Write
                           2018 ;	D:\Workspace\MIDE\firmware\/rtc.c:125: I2C_Write(var_month_u8);			      // Write month on RAM address 05H
   08A7 E5 13              2019 	mov	a,_bp
   08A9 24 FD              2020 	add	a,#0xfd
   08AB F8                 2021 	mov	r0,a
   08AC 86 82              2022 	mov	dpl,@r0
   08AE 12 0A 3F           2023 	lcall	_I2C_Write
                           2024 ;	D:\Workspace\MIDE\firmware\/rtc.c:126: I2C_Write(var_year_u8);			      // Write year on RAM address 06h
   08B1 E5 13              2025 	mov	a,_bp
   08B3 24 FC              2026 	add	a,#0xfc
   08B5 F8                 2027 	mov	r0,a
   08B6 86 82              2028 	mov	dpl,@r0
   08B8 12 0A 3F           2029 	lcall	_I2C_Write
                           2030 ;	D:\Workspace\MIDE\firmware\/rtc.c:128: I2C_Stop();				              // Stop I2C communication after Setting the Date
   08BB 12 0A 20           2031 	lcall	_I2C_Stop
   08BE D0 13              2032 	pop	_bp
   08C0 22                 2033 	ret
                           2034 ;------------------------------------------------------------
                           2035 ;Allocation info for local variables in function 'RTC_GetTime'
                           2036 ;------------------------------------------------------------
                           2037 ;ptr_min_u8                Allocated to stack - offset -5
                           2038 ;ptr_sec_u8                Allocated to stack - offset -8
                           2039 ;ptr_hour_u8               Allocated to stack - offset 1
                           2040 ;------------------------------------------------------------
                           2041 ;	D:\Workspace\MIDE\firmware\/rtc.c:147: void RTC_GetTime(uint8_t *ptr_hour_u8,uint8_t *ptr_min_u8,uint8_t *ptr_sec_u8)
                           2042 ;	-----------------------------------------
                           2043 ;	 function RTC_GetTime
                           2044 ;	-----------------------------------------
   08C1                    2045 _RTC_GetTime:
   08C1 C0 13              2046 	push	_bp
   08C3 85 81 13           2047 	mov	_bp,sp
   08C6 C0 82              2048 	push	dpl
   08C8 C0 83              2049 	push	dph
   08CA C0 F0              2050 	push	b
                           2051 ;	D:\Workspace\MIDE\firmware\/rtc.c:149: I2C_Start();                            // Start I2C communication
   08CC 12 09 FE           2052 	lcall	_I2C_Start
                           2053 ;	D:\Workspace\MIDE\firmware\/rtc.c:151: I2C_Write(C_Ds1307WriteMode_U8);	    // connect to DS1307 by sending its ID on I2c Bus
   08CF 75 82 D0           2054 	mov	dpl,#0xD0
   08D2 12 0A 3F           2055 	lcall	_I2C_Write
                           2056 ;	D:\Workspace\MIDE\firmware\/rtc.c:152: I2C_Write(C_Ds1307SecondRegAddress_U8); // Request Sec RAM address at 00H
   08D5 75 82 00           2057 	mov	dpl,#0x00
   08D8 12 0A 3F           2058 	lcall	_I2C_Write
                           2059 ;	D:\Workspace\MIDE\firmware\/rtc.c:154: I2C_Stop();			                    // Stop I2C communication after selecting Sec Register
   08DB 12 0A 20           2060 	lcall	_I2C_Stop
                           2061 ;	D:\Workspace\MIDE\firmware\/rtc.c:156: I2C_Start();		                    // Start I2C communication
   08DE 12 09 FE           2062 	lcall	_I2C_Start
                           2063 ;	D:\Workspace\MIDE\firmware\/rtc.c:157: I2C_Write(C_Ds1307ReadMode_U8);	        // connect to DS1307(Read mode) by sending its ID
   08E1 75 82 D1           2064 	mov	dpl,#0xD1
   08E4 12 0A 3F           2065 	lcall	_I2C_Write
                           2066 ;	D:\Workspace\MIDE\firmware\/rtc.c:159: *ptr_sec_u8 = I2C_Read(1);                // read second and return Positive ACK
   08E7 E5 13              2067 	mov	a,_bp
   08E9 24 F8              2068 	add	a,#0xf8
   08EB F8                 2069 	mov	r0,a
   08EC 86 05              2070 	mov	ar5,@r0
   08EE 08                 2071 	inc	r0
   08EF 86 06              2072 	mov	ar6,@r0
   08F1 08                 2073 	inc	r0
   08F2 86 07              2074 	mov	ar7,@r0
   08F4 75 82 01           2075 	mov	dpl,#0x01
   08F7 C0 05              2076 	push	ar5
   08F9 C0 06              2077 	push	ar6
   08FB C0 07              2078 	push	ar7
   08FD 12 0A 6B           2079 	lcall	_I2C_Read
   0900 AA 82              2080 	mov	r2,dpl
   0902 D0 07              2081 	pop	ar7
   0904 D0 06              2082 	pop	ar6
   0906 D0 05              2083 	pop	ar5
   0908 8D 82              2084 	mov	dpl,r5
   090A 8E 83              2085 	mov	dph,r6
   090C 8F F0              2086 	mov	b,r7
   090E EA                 2087 	mov	a,r2
   090F 12 15 3D           2088 	lcall	__gptrput
                           2089 ;	D:\Workspace\MIDE\firmware\/rtc.c:160: *ptr_min_u8 = I2C_Read(1); 	            // read minute and return Positive ACK
   0912 E5 13              2090 	mov	a,_bp
   0914 24 FB              2091 	add	a,#0xfb
   0916 F8                 2092 	mov	r0,a
   0917 86 02              2093 	mov	ar2,@r0
   0919 08                 2094 	inc	r0
   091A 86 03              2095 	mov	ar3,@r0
   091C 08                 2096 	inc	r0
   091D 86 04              2097 	mov	ar4,@r0
   091F 75 82 01           2098 	mov	dpl,#0x01
   0922 C0 02              2099 	push	ar2
   0924 C0 03              2100 	push	ar3
   0926 C0 04              2101 	push	ar4
   0928 12 0A 6B           2102 	lcall	_I2C_Read
   092B AD 82              2103 	mov	r5,dpl
   092D D0 04              2104 	pop	ar4
   092F D0 03              2105 	pop	ar3
   0931 D0 02              2106 	pop	ar2
   0933 8A 82              2107 	mov	dpl,r2
   0935 8B 83              2108 	mov	dph,r3
   0937 8C F0              2109 	mov	b,r4
   0939 ED                 2110 	mov	a,r5
   093A 12 15 3D           2111 	lcall	__gptrput
                           2112 ;	D:\Workspace\MIDE\firmware\/rtc.c:161: *ptr_hour_u8 = I2C_Read(0);               // read hour and return Negative/No ACK
   093D 75 82 00           2113 	mov	dpl,#0x00
   0940 12 0A 6B           2114 	lcall	_I2C_Read
   0943 AA 82              2115 	mov	r2,dpl
   0945 A8 13              2116 	mov	r0,_bp
   0947 08                 2117 	inc	r0
   0948 86 82              2118 	mov	dpl,@r0
   094A 08                 2119 	inc	r0
   094B 86 83              2120 	mov	dph,@r0
   094D 08                 2121 	inc	r0
   094E 86 F0              2122 	mov	b,@r0
   0950 EA                 2123 	mov	a,r2
   0951 12 15 3D           2124 	lcall	__gptrput
                           2125 ;	D:\Workspace\MIDE\firmware\/rtc.c:163: I2C_Stop();		                        // Stop I2C communication after reading the Time
   0954 12 0A 20           2126 	lcall	_I2C_Stop
   0957 85 13 81           2127 	mov	sp,_bp
   095A D0 13              2128 	pop	_bp
   095C 22                 2129 	ret
                           2130 ;------------------------------------------------------------
                           2131 ;Allocation info for local variables in function 'RTC_GetDate'
                           2132 ;------------------------------------------------------------
                           2133 ;ptr_month_u8              Allocated to stack - offset -5
                           2134 ;ptr_year_u8               Allocated to stack - offset -8
                           2135 ;ptr_day_u8                Allocated to registers r2 r3 r4 
                           2136 ;------------------------------------------------------------
                           2137 ;	D:\Workspace\MIDE\firmware\/rtc.c:183: void RTC_GetDate(uint8_t *ptr_day_u8,uint8_t *ptr_month_u8,uint8_t *ptr_year_u8)
                           2138 ;	-----------------------------------------
                           2139 ;	 function RTC_GetDate
                           2140 ;	-----------------------------------------
   095D                    2141 _RTC_GetDate:
   095D C0 13              2142 	push	_bp
   095F 85 81 13           2143 	mov	_bp,sp
   0962 AA 82              2144 	mov	r2,dpl
   0964 AB 83              2145 	mov	r3,dph
   0966 AC F0              2146 	mov	r4,b
                           2147 ;	D:\Workspace\MIDE\firmware\/rtc.c:185: I2C_Start();                          // Start I2C communication
   0968 C0 02              2148 	push	ar2
   096A C0 03              2149 	push	ar3
   096C C0 04              2150 	push	ar4
   096E 12 09 FE           2151 	lcall	_I2C_Start
                           2152 ;	D:\Workspace\MIDE\firmware\/rtc.c:187: I2C_Write(C_Ds1307WriteMode_U8);	      // connect to DS1307 by sending its ID on I2c Bus
   0971 75 82 D0           2153 	mov	dpl,#0xD0
   0974 12 0A 3F           2154 	lcall	_I2C_Write
                           2155 ;	D:\Workspace\MIDE\firmware\/rtc.c:188: I2C_Write(C_Ds1307DateRegAddress_U8); // Request DAY RAM address at 04H
   0977 75 82 04           2156 	mov	dpl,#0x04
   097A 12 0A 3F           2157 	lcall	_I2C_Write
                           2158 ;	D:\Workspace\MIDE\firmware\/rtc.c:190: I2C_Stop();			                  // Stop I2C communication after selecting DAY Register
   097D 12 0A 20           2159 	lcall	_I2C_Stop
                           2160 ;	D:\Workspace\MIDE\firmware\/rtc.c:193: I2C_Start();		                  // Start I2C communication
   0980 12 09 FE           2161 	lcall	_I2C_Start
                           2162 ;	D:\Workspace\MIDE\firmware\/rtc.c:194: I2C_Write(C_Ds1307ReadMode_U8);	      // connect to DS1307(Read mode) by sending its ID
   0983 75 82 D1           2163 	mov	dpl,#0xD1
   0986 12 0A 3F           2164 	lcall	_I2C_Write
                           2165 ;	D:\Workspace\MIDE\firmware\/rtc.c:196: *ptr_day_u8 = I2C_Read(1);              // read Day and return Positive ACK
   0989 75 82 01           2166 	mov	dpl,#0x01
   098C 12 0A 6B           2167 	lcall	_I2C_Read
   098F AD 82              2168 	mov	r5,dpl
   0991 D0 04              2169 	pop	ar4
   0993 D0 03              2170 	pop	ar3
   0995 D0 02              2171 	pop	ar2
   0997 8A 82              2172 	mov	dpl,r2
   0999 8B 83              2173 	mov	dph,r3
   099B 8C F0              2174 	mov	b,r4
   099D ED                 2175 	mov	a,r5
   099E 12 15 3D           2176 	lcall	__gptrput
                           2177 ;	D:\Workspace\MIDE\firmware\/rtc.c:197: *ptr_month_u8 = I2C_Read(1);            // read Month and return Positive ACK
   09A1 E5 13              2178 	mov	a,_bp
   09A3 24 FB              2179 	add	a,#0xfb
   09A5 F8                 2180 	mov	r0,a
   09A6 86 02              2181 	mov	ar2,@r0
   09A8 08                 2182 	inc	r0
   09A9 86 03              2183 	mov	ar3,@r0
   09AB 08                 2184 	inc	r0
   09AC 86 04              2185 	mov	ar4,@r0
   09AE 75 82 01           2186 	mov	dpl,#0x01
   09B1 C0 02              2187 	push	ar2
   09B3 C0 03              2188 	push	ar3
   09B5 C0 04              2189 	push	ar4
   09B7 12 0A 6B           2190 	lcall	_I2C_Read
   09BA AD 82              2191 	mov	r5,dpl
   09BC D0 04              2192 	pop	ar4
   09BE D0 03              2193 	pop	ar3
   09C0 D0 02              2194 	pop	ar2
   09C2 8A 82              2195 	mov	dpl,r2
   09C4 8B 83              2196 	mov	dph,r3
   09C6 8C F0              2197 	mov	b,r4
   09C8 ED                 2198 	mov	a,r5
   09C9 12 15 3D           2199 	lcall	__gptrput
                           2200 ;	D:\Workspace\MIDE\firmware\/rtc.c:198: *ptr_year_u8 = I2C_Read(0);             // read Year and return Negative/No ACK
   09CC E5 13              2201 	mov	a,_bp
   09CE 24 F8              2202 	add	a,#0xf8
   09D0 F8                 2203 	mov	r0,a
   09D1 86 02              2204 	mov	ar2,@r0
   09D3 08                 2205 	inc	r0
   09D4 86 03              2206 	mov	ar3,@r0
   09D6 08                 2207 	inc	r0
   09D7 86 04              2208 	mov	ar4,@r0
   09D9 75 82 00           2209 	mov	dpl,#0x00
   09DC C0 02              2210 	push	ar2
   09DE C0 03              2211 	push	ar3
   09E0 C0 04              2212 	push	ar4
   09E2 12 0A 6B           2213 	lcall	_I2C_Read
   09E5 AD 82              2214 	mov	r5,dpl
   09E7 D0 04              2215 	pop	ar4
   09E9 D0 03              2216 	pop	ar3
   09EB D0 02              2217 	pop	ar2
   09ED 8A 82              2218 	mov	dpl,r2
   09EF 8B 83              2219 	mov	dph,r3
   09F1 8C F0              2220 	mov	b,r4
   09F3 ED                 2221 	mov	a,r5
   09F4 12 15 3D           2222 	lcall	__gptrput
                           2223 ;	D:\Workspace\MIDE\firmware\/rtc.c:200: I2C_Stop();		                      // Stop I2C communication after reading the Date
   09F7 12 0A 20           2224 	lcall	_I2C_Stop
   09FA D0 13              2225 	pop	_bp
   09FC 22                 2226 	ret
                           2227 ;------------------------------------------------------------
                           2228 ;Allocation info for local variables in function 'I2C_Init'
                           2229 ;------------------------------------------------------------
                           2230 ;------------------------------------------------------------
                           2231 ;	D:\Workspace\MIDE\firmware\/i2c.c:16: void I2C_Init()
                           2232 ;	-----------------------------------------
                           2233 ;	 function I2C_Init
                           2234 ;	-----------------------------------------
   09FD                    2235 _I2C_Init:
                           2236 ;	D:\Workspace\MIDE\firmware\/i2c.c:20: }
   09FD 22                 2237 	ret
                           2238 ;------------------------------------------------------------
                           2239 ;Allocation info for local variables in function 'I2C_Start'
                           2240 ;------------------------------------------------------------
                           2241 ;------------------------------------------------------------
                           2242 ;	D:\Workspace\MIDE\firmware\/i2c.c:22: void I2C_Start()
                           2243 ;	-----------------------------------------
                           2244 ;	 function I2C_Start
                           2245 ;	-----------------------------------------
   09FE                    2246 _I2C_Start:
                           2247 ;	D:\Workspace\MIDE\firmware\/i2c.c:26: util_BitClear(I2C_Port, SCL);        // Pull SCL low
   09FE 53 80 BF           2248 	anl	_P0,#0xBF
                           2249 ;	D:\Workspace\MIDE\firmware\/i2c.c:27: util_BitSet(I2C_Port, SDA);       // Pull SDA High
   0A01 43 80 80           2250 	orl	_P0,#0x80
                           2251 ;	D:\Workspace\MIDE\firmware\/i2c.c:28: DELAY_us(1);
   0A04 90 00 01           2252 	mov	dptr,#0x0001
   0A07 12 0D 3C           2253 	lcall	_DELAY_us
                           2254 ;	D:\Workspace\MIDE\firmware\/i2c.c:29: util_BitSet(I2C_Port, SCL);     //Pull SCL high
   0A0A 43 80 40           2255 	orl	_P0,#0x40
                           2256 ;	D:\Workspace\MIDE\firmware\/i2c.c:30: DELAY_us(1);
   0A0D 90 00 01           2257 	mov	dptr,#0x0001
   0A10 12 0D 3C           2258 	lcall	_DELAY_us
                           2259 ;	D:\Workspace\MIDE\firmware\/i2c.c:31: util_BitClear(I2C_Port, SDA);      //Now Pull SDA LOW, to generate the Start Condition
   0A13 53 80 7F           2260 	anl	_P0,#0x7F
                           2261 ;	D:\Workspace\MIDE\firmware\/i2c.c:32: DELAY_us(1);
   0A16 90 00 01           2262 	mov	dptr,#0x0001
   0A19 12 0D 3C           2263 	lcall	_DELAY_us
                           2264 ;	D:\Workspace\MIDE\firmware\/i2c.c:33: util_BitClear(I2C_Port, SCL);        //Finally Clear the SCL to complete the cycle
   0A1C 53 80 BF           2265 	anl	_P0,#0xBF
   0A1F 22                 2266 	ret
                           2267 ;------------------------------------------------------------
                           2268 ;Allocation info for local variables in function 'I2C_Stop'
                           2269 ;------------------------------------------------------------
                           2270 ;------------------------------------------------------------
                           2271 ;	D:\Workspace\MIDE\firmware\/i2c.c:60: void I2C_Stop(void)
                           2272 ;	-----------------------------------------
                           2273 ;	 function I2C_Stop
                           2274 ;	-----------------------------------------
   0A20                    2275 _I2C_Stop:
                           2276 ;	D:\Workspace\MIDE\firmware\/i2c.c:63: util_BitClear(I2C_Port, SCL);            // Pull SCL low
   0A20 53 80 BF           2277 	anl	_P0,#0xBF
                           2278 ;	D:\Workspace\MIDE\firmware\/i2c.c:64: DELAY_us(1);
   0A23 90 00 01           2279 	mov	dptr,#0x0001
   0A26 12 0D 3C           2280 	lcall	_DELAY_us
                           2281 ;	D:\Workspace\MIDE\firmware\/i2c.c:65: util_BitClear(I2C_Port, SDA);          // Pull SDA  low
   0A29 53 80 7F           2282 	anl	_P0,#0x7F
                           2283 ;	D:\Workspace\MIDE\firmware\/i2c.c:66: DELAY_us(1);
   0A2C 90 00 01           2284 	mov	dptr,#0x0001
   0A2F 12 0D 3C           2285 	lcall	_DELAY_us
                           2286 ;	D:\Workspace\MIDE\firmware\/i2c.c:67: util_BitSet(I2C_Port, SCL);         // Pull SCL High
   0A32 43 80 40           2287 	orl	_P0,#0x40
                           2288 ;	D:\Workspace\MIDE\firmware\/i2c.c:68: DELAY_us(1);
   0A35 90 00 01           2289 	mov	dptr,#0x0001
   0A38 12 0D 3C           2290 	lcall	_DELAY_us
                           2291 ;	D:\Workspace\MIDE\firmware\/i2c.c:69: util_BitSet(I2C_Port, SDA);           // Now Pull SDA High, to generate the Stop Condition
   0A3B 43 80 80           2292 	orl	_P0,#0x80
   0A3E 22                 2293 	ret
                           2294 ;------------------------------------------------------------
                           2295 ;Allocation info for local variables in function 'I2C_Write'
                           2296 ;------------------------------------------------------------
                           2297 ;var_i2cData_u8            Allocated to registers r2 
                           2298 ;i                         Allocated to registers r3 
                           2299 ;------------------------------------------------------------
                           2300 ;	D:\Workspace\MIDE\firmware\/i2c.c:98: void I2C_Write(uint8_t var_i2cData_u8)
                           2301 ;	-----------------------------------------
                           2302 ;	 function I2C_Write
                           2303 ;	-----------------------------------------
   0A3F                    2304 _I2C_Write:
   0A3F AA 82              2305 	mov	r2,dpl
                           2306 ;	D:\Workspace\MIDE\firmware\/i2c.c:101: util_BitClear(I2C_Port,SDA); //output
   0A41 53 80 7F           2307 	anl	_P0,#0x7F
                           2308 ;	D:\Workspace\MIDE\firmware\/i2c.c:103: for(i=0;i<8;i++)                   // loop 8 times to send 1-byte of data
   0A44 7B 00              2309 	mov	r3,#0x00
   0A46                    2310 00104$:
   0A46 BB 08 00           2311 	cjne	r3,#0x08,00114$
   0A49                    2312 00114$:
   0A49 50 1D              2313 	jnc	00107$
                           2314 ;	D:\Workspace\MIDE\firmware\/i2c.c:105: if(util_IsBitSet(var_i2cData_u8,7))
   0A4B EA                 2315 	mov	a,r2
   0A4C 30 E7 05           2316 	jnb	acc.7,00102$
                           2317 ;	D:\Workspace\MIDE\firmware\/i2c.c:107: util_BitSet(I2C_Port,SDA);
   0A4F 43 80 80           2318 	orl	_P0,#0x80
   0A52 80 03              2319 	sjmp	00103$
   0A54                    2320 00102$:
                           2321 ;	D:\Workspace\MIDE\firmware\/i2c.c:111: util_BitClear(I2C_Port,SDA);
   0A54 53 80 7F           2322 	anl	_P0,#0x7F
   0A57                    2323 00103$:
                           2324 ;	D:\Workspace\MIDE\firmware\/i2c.c:115: i2c_Clock();                   // Generate Clock at SCL
   0A57 C0 02              2325 	push	ar2
   0A59 C0 03              2326 	push	ar3
   0A5B 12 0A CA           2327 	lcall	_i2c_Clock
   0A5E D0 03              2328 	pop	ar3
   0A60 D0 02              2329 	pop	ar2
                           2330 ;	D:\Workspace\MIDE\firmware\/i2c.c:116: var_i2cData_u8 = var_i2cData_u8<<1;// Bring the next bit to be transmitted to MSB position
   0A62 EA                 2331 	mov	a,r2
   0A63 2A                 2332 	add	a,r2
   0A64 FA                 2333 	mov	r2,a
                           2334 ;	D:\Workspace\MIDE\firmware\/i2c.c:103: for(i=0;i<8;i++)                   // loop 8 times to send 1-byte of data
   0A65 0B                 2335 	inc	r3
   0A66 80 DE              2336 	sjmp	00104$
   0A68                    2337 00107$:
                           2338 ;	D:\Workspace\MIDE\firmware\/i2c.c:119: i2c_Clock();
   0A68 02 0A CA           2339 	ljmp	_i2c_Clock
                           2340 ;------------------------------------------------------------
                           2341 ;Allocation info for local variables in function 'I2C_Read'
                           2342 ;------------------------------------------------------------
                           2343 ;var_ackOption_u8          Allocated to registers r2 
                           2344 ;i                         Allocated to registers r4 
                           2345 ;var_i2cData_u8            Allocated to registers r3 
                           2346 ;------------------------------------------------------------
                           2347 ;	D:\Workspace\MIDE\firmware\/i2c.c:146: uint8_t I2C_Read(uint8_t var_ackOption_u8)
                           2348 ;	-----------------------------------------
                           2349 ;	 function I2C_Read
                           2350 ;	-----------------------------------------
   0A6B                    2351 _I2C_Read:
   0A6B AA 82              2352 	mov	r2,dpl
                           2353 ;	D:\Workspace\MIDE\firmware\/i2c.c:148: uint8_t i, var_i2cData_u8=0x00;
   0A6D 7B 00              2354 	mov	r3,#0x00
                           2355 ;	D:\Workspace\MIDE\firmware\/i2c.c:150: util_BitSet(I2C_Port,SDA);              //Make SDA as I/P
   0A6F 43 80 80           2356 	orl	_P0,#0x80
                           2357 ;	D:\Workspace\MIDE\firmware\/i2c.c:151: for(i=0;i<8;i++)     // loop 8times read 1-byte of data
   0A72 7C 00              2358 	mov	r4,#0x00
   0A74                    2359 00104$:
   0A74 BC 08 00           2360 	cjne	r4,#0x08,00114$
   0A77                    2361 00114$:
   0A77 50 3B              2362 	jnc	00107$
                           2363 ;	D:\Workspace\MIDE\firmware\/i2c.c:153: DELAY_us(1);
   0A79 90 00 01           2364 	mov	dptr,#0x0001
   0A7C C0 02              2365 	push	ar2
   0A7E C0 03              2366 	push	ar3
   0A80 C0 04              2367 	push	ar4
   0A82 12 0D 3C           2368 	lcall	_DELAY_us
                           2369 ;	D:\Workspace\MIDE\firmware\/i2c.c:154: util_BitSet(I2C_Port, SCL);      // Pull SCL High
   0A85 43 80 40           2370 	orl	_P0,#0x40
                           2371 ;	D:\Workspace\MIDE\firmware\/i2c.c:155: DELAY_us(1);
   0A88 90 00 01           2372 	mov	dptr,#0x0001
   0A8B 12 0D 3C           2373 	lcall	_DELAY_us
   0A8E D0 04              2374 	pop	ar4
   0A90 D0 03              2375 	pop	ar3
   0A92 D0 02              2376 	pop	ar2
                           2377 ;	D:\Workspace\MIDE\firmware\/i2c.c:157: var_i2cData_u8 = var_i2cData_u8<<1;    //var_i2cData_u8 is Shifted each time and
   0A94 EB                 2378 	mov	a,r3
   0A95 2B                 2379 	add	a,r3
   0A96 FB                 2380 	mov	r3,a
                           2381 ;	D:\Workspace\MIDE\firmware\/i2c.c:158: var_i2cData_u8 = var_i2cData_u8 | util_GetBitStatus(I2C_Port, SDA); //ORed with the received bit to pack into byte
   0A97 74 80              2382 	mov	a,#0x80
   0A99 55 80              2383 	anl	a,_P0
   0A9B FD                 2384 	mov	r5,a
   0A9C E4                 2385 	clr	a
   0A9D FE                 2386 	mov	r6,a
   0A9E BD 00 04           2387 	cjne	r5,#0x00,00116$
   0AA1 BE 00 01           2388 	cjne	r6,#0x00,00116$
   0AA4 04                 2389 	inc	a
   0AA5                    2390 00116$:
   0AA5 FD                 2391 	mov	r5,a
   0AA6 B4 01 00           2392 	cjne	a,#0x01,00118$
   0AA9                    2393 00118$:
   0AA9 E4                 2394 	clr	a
   0AAA 33                 2395 	rlc	a
   0AAB FD                 2396 	mov	r5,a
   0AAC 42 03              2397 	orl	ar3,a
                           2398 ;	D:\Workspace\MIDE\firmware\/i2c.c:160: util_BitClear(I2C_Port, SCL);         // Clear SCL to complete the Clock
   0AAE 53 80 BF           2399 	anl	_P0,#0xBF
                           2400 ;	D:\Workspace\MIDE\firmware\/i2c.c:151: for(i=0;i<8;i++)     // loop 8times read 1-byte of data
   0AB1 0C                 2401 	inc	r4
   0AB2 80 C0              2402 	sjmp	00104$
   0AB4                    2403 00107$:
                           2404 ;	D:\Workspace\MIDE\firmware\/i2c.c:162: if(var_ackOption_u8==1)  /*Send the Ack/NoAck depending on the user option*/
   0AB4 BA 01 09           2405 	cjne	r2,#0x01,00102$
                           2406 ;	D:\Workspace\MIDE\firmware\/i2c.c:164: i2c_Ack();
   0AB7 C0 03              2407 	push	ar3
   0AB9 12 0A DD           2408 	lcall	_i2c_Ack
   0ABC D0 03              2409 	pop	ar3
   0ABE 80 07              2410 	sjmp	00103$
   0AC0                    2411 00102$:
                           2412 ;	D:\Workspace\MIDE\firmware\/i2c.c:168: i2c_NoAck();
   0AC0 C0 03              2413 	push	ar3
   0AC2 12 0A E7           2414 	lcall	_i2c_NoAck
   0AC5 D0 03              2415 	pop	ar3
   0AC7                    2416 00103$:
                           2417 ;	D:\Workspace\MIDE\firmware\/i2c.c:171: return var_i2cData_u8;           // Finally return the received Byte*
   0AC7 8B 82              2418 	mov	dpl,r3
   0AC9 22                 2419 	ret
                           2420 ;------------------------------------------------------------
                           2421 ;Allocation info for local variables in function 'i2c_Clock'
                           2422 ;------------------------------------------------------------
                           2423 ;------------------------------------------------------------
                           2424 ;	D:\Workspace\MIDE\firmware\/i2c.c:192: static void i2c_Clock(void)
                           2425 ;	-----------------------------------------
                           2426 ;	 function i2c_Clock
                           2427 ;	-----------------------------------------
   0ACA                    2428 _i2c_Clock:
                           2429 ;	D:\Workspace\MIDE\firmware\/i2c.c:194: DELAY_us(1);
   0ACA 90 00 01           2430 	mov	dptr,#0x0001
   0ACD 12 0D 3C           2431 	lcall	_DELAY_us
                           2432 ;	D:\Workspace\MIDE\firmware\/i2c.c:195: util_BitSet(I2C_Port, SCL);         // Wait for Some time and Pull the SCL line High
   0AD0 43 80 40           2433 	orl	_P0,#0x40
                           2434 ;	D:\Workspace\MIDE\firmware\/i2c.c:196: DELAY_us(1);        // Wait for Some time
   0AD3 90 00 01           2435 	mov	dptr,#0x0001
   0AD6 12 0D 3C           2436 	lcall	_DELAY_us
                           2437 ;	D:\Workspace\MIDE\firmware\/i2c.c:197: util_BitClear(I2C_Port, SCL);            // Pull back the SCL line low to Generate a clock pulse
   0AD9 53 80 BF           2438 	anl	_P0,#0xBF
   0ADC 22                 2439 	ret
                           2440 ;------------------------------------------------------------
                           2441 ;Allocation info for local variables in function 'i2c_Ack'
                           2442 ;------------------------------------------------------------
                           2443 ;------------------------------------------------------------
                           2444 ;	D:\Workspace\MIDE\firmware\/i2c.c:213: static void i2c_Ack()
                           2445 ;	-----------------------------------------
                           2446 ;	 function i2c_Ack
                           2447 ;	-----------------------------------------
   0ADD                    2448 _i2c_Ack:
                           2449 ;	D:\Workspace\MIDE\firmware\/i2c.c:215: util_BitClear(I2C_Port, SDA);      //Pull SDA low to indicate Positive ACK
   0ADD 53 80 7F           2450 	anl	_P0,#0x7F
                           2451 ;	D:\Workspace\MIDE\firmware\/i2c.c:216: i2c_Clock();    //Generate the Clock
   0AE0 12 0A CA           2452 	lcall	_i2c_Clock
                           2453 ;	D:\Workspace\MIDE\firmware\/i2c.c:217: util_BitSet(I2C_Port, SDA);       // Pull SDA back to High(IDLE state)
   0AE3 43 80 80           2454 	orl	_P0,#0x80
   0AE6 22                 2455 	ret
                           2456 ;------------------------------------------------------------
                           2457 ;Allocation info for local variables in function 'i2c_NoAck'
                           2458 ;------------------------------------------------------------
                           2459 ;------------------------------------------------------------
                           2460 ;	D:\Workspace\MIDE\firmware\/i2c.c:233: static void i2c_NoAck()
                           2461 ;	-----------------------------------------
                           2462 ;	 function i2c_NoAck
                           2463 ;	-----------------------------------------
   0AE7                    2464 _i2c_NoAck:
                           2465 ;	D:\Workspace\MIDE\firmware\/i2c.c:235: util_BitSet(I2C_Port, SDA);        //Pull SDA high to indicate Negative/NO ACK
   0AE7 43 80 80           2466 	orl	_P0,#0x80
                           2467 ;	D:\Workspace\MIDE\firmware\/i2c.c:236: i2c_Clock();     // Generate the Clock  
   0AEA 12 0A CA           2468 	lcall	_i2c_Clock
                           2469 ;	D:\Workspace\MIDE\firmware\/i2c.c:237: util_BitSet(I2C_Port, SCL);      // Set SCL 
   0AED 43 80 40           2470 	orl	_P0,#0x40
   0AF0 22                 2471 	ret
                           2472 ;------------------------------------------------------------
                           2473 ;Allocation info for local variables in function 'LCD_Init'
                           2474 ;------------------------------------------------------------
                           2475 ;var_lcdNoOfLines_u8       Allocated to stack - offset -3
                           2476 ;var_MaxCharsPerLine_u8    Allocated to stack - offset -4
                           2477 ;var_lcdMode_u8            Allocated to registers r2 
                           2478 ;------------------------------------------------------------
                           2479 ;	D:\Workspace\MIDE\firmware\/lcd.c:112: void LCD_Init(uint8_t var_lcdMode_u8, uint8_t var_lcdNoOfLines_u8, uint8_t var_MaxCharsPerLine_u8)
                           2480 ;	-----------------------------------------
                           2481 ;	 function LCD_Init
                           2482 ;	-----------------------------------------
   0AF1                    2483 _LCD_Init:
   0AF1 C0 13              2484 	push	_bp
   0AF3 85 81 13           2485 	mov	_bp,sp
   0AF6 AA 82              2486 	mov	r2,dpl
                           2487 ;	D:\Workspace\MIDE\firmware\/lcd.c:116: M_LcdDataBusDirection = C_PortOutput_U8;     //Configure the Data Bus as output
   0AF8 75 A0 00           2488 	mov	_P2,#0x00
                           2489 ;	D:\Workspace\MIDE\firmware\/lcd.c:117: M_LcdControlBusDirection = C_PortOutput_U8;  //Configure the Control Bus as output
   0AFB 75 80 00           2490 	mov	_P0,#0x00
                           2491 ;	D:\Workspace\MIDE\firmware\/lcd.c:118: STK_LCDConfig.mvar_LcdMode_U8 = var_lcdMode_u8;      // Keep the track of selected Mode(4/8 bit)
   0AFE 8A 0C              2492 	mov	(_STK_LCDConfig + 0x0002),r2
                           2493 ;	D:\Workspace\MIDE\firmware\/lcd.c:119: STK_LCDConfig.mvar_MaxSupportedChars_U8 = var_MaxCharsPerLine_u8; //Keep the LCD type
   0B00 E5 13              2494 	mov	a,_bp
   0B02 24 FC              2495 	add	a,#0xfc
   0B04 F8                 2496 	mov	r0,a
   0B05 86 0B              2497 	mov	(_STK_LCDConfig + 0x0001),@r0
                           2498 ;	D:\Workspace\MIDE\firmware\/lcd.c:120: STK_LCDConfig.mvar_MaxSupportedLines_U8 = var_lcdNoOfLines_u8;
   0B07 E5 13              2499 	mov	a,_bp
   0B09 24 FD              2500 	add	a,#0xfd
   0B0B F8                 2501 	mov	r0,a
   0B0C 86 0A              2502 	mov	_STK_LCDConfig,@r0
                           2503 ;	D:\Workspace\MIDE\firmware\/lcd.c:121: if(var_lcdNoOfLines_u8 > mENUM_LcdLineTwo)
   0B0E E5 13              2504 	mov	a,_bp
   0B10 24 FD              2505 	add	a,#0xfd
   0B12 F8                 2506 	mov	r0,a
   0B13 E6                 2507 	mov	a,@r0
   0B14 24 FD              2508 	add	a,#0xff - 0x02
   0B16 50 16              2509 	jnc	00102$
                           2510 ;	D:\Workspace\MIDE\firmware\/lcd.c:123: ARR_LcdLineNumAddress_U8[mENUM_LcdLineThree] =  0x90 + (var_MaxCharsPerLine_u8 & 0x0fu);
   0B18 E5 13              2511 	mov	a,_bp
   0B1A 24 FC              2512 	add	a,#0xfc
   0B1C F8                 2513 	mov	r0,a
   0B1D 86 02              2514 	mov	ar2,@r0
   0B1F 53 02 0F           2515 	anl	ar2,#0x0F
   0B22 7B 00              2516 	mov	r3,#0x00
   0B24 74 90              2517 	mov	a,#0x90
   0B26 2A                 2518 	add	a,r2
   0B27 F5 10              2519 	mov	(_ARR_LcdLineNumAddress_U8 + 0x0003),a
                           2520 ;	D:\Workspace\MIDE\firmware\/lcd.c:124: ARR_LcdLineNumAddress_U8[mENUM_LcdLineFour] =  0xd0 + (var_MaxCharsPerLine_u8 & 0x0fu);
   0B29 74 D0              2521 	mov	a,#0xD0
   0B2B 2A                 2522 	add	a,r2
   0B2C F5 11              2523 	mov	(_ARR_LcdLineNumAddress_U8 + 0x0004),a
   0B2E                    2524 00102$:
                           2525 ;	D:\Workspace\MIDE\firmware\/lcd.c:127: DELAY_ms(100);
   0B2E 90 00 64           2526 	mov	dptr,#0x0064
   0B31 12 0D 4C           2527 	lcall	_DELAY_ms
                           2528 ;	D:\Workspace\MIDE\firmware\/lcd.c:129: if(STK_LCDConfig.mvar_LcdMode_U8 == M_EightBitMode)
   0B34 AA 0C              2529 	mov	r2,(_STK_LCDConfig + 0x0002)
   0B36 7B 00              2530 	mov	r3,#0x00
   0B38 BA 08 0B           2531 	cjne	r2,#0x08,00106$
   0B3B BB 00 08           2532 	cjne	r3,#0x00,00106$
                           2533 ;	D:\Workspace\MIDE\firmware\/lcd.c:131: LCD_CmdWrite(CMD_LCD_EIGHT_BIT_MODE); // Initialize the LCD for 8-bit 5x7 matrix type
   0B3E 75 82 38           2534 	mov	dpl,#0x38
   0B41 12 0B 9E           2535 	lcall	_LCD_CmdWrite
   0B44 80 0F              2536 	sjmp	00107$
   0B46                    2537 00106$:
                           2538 ;	D:\Workspace\MIDE\firmware\/lcd.c:133: else if(STK_LCDConfig.mvar_LcdMode_U8 == M_FourBitMode)
   0B46 BA 04 0C           2539 	cjne	r2,#0x04,00107$
   0B49 BB 00 09           2540 	cjne	r3,#0x00,00107$
                           2541 ;	D:\Workspace\MIDE\firmware\/lcd.c:135: lcd_Reset();
   0B4C 12 0C A8           2542 	lcall	_lcd_Reset
                           2543 ;	D:\Workspace\MIDE\firmware\/lcd.c:136: LCD_CmdWrite(CMD_LCD_FOUR_BIT_MODE); // Initialize the LCD for 4-bit 5x7 matrix type 
   0B4F 75 82 28           2544 	mov	dpl,#0x28
   0B52 12 0B 9E           2545 	lcall	_LCD_CmdWrite
   0B55                    2546 00107$:
                           2547 ;	D:\Workspace\MIDE\firmware\/lcd.c:139: LCD_CmdWrite(CMD_DISPLAY_ON_CURSOR_ON);	 // Display ON cursor ON
   0B55 75 82 0E           2548 	mov	dpl,#0x0E
   0B58 12 0B 9E           2549 	lcall	_LCD_CmdWrite
                           2550 ;	D:\Workspace\MIDE\firmware\/lcd.c:140: LCD_Clear();	                         // Clear the LCD and go to First line First Position
   0B5B 12 0B 61           2551 	lcall	_LCD_Clear
   0B5E D0 13              2552 	pop	_bp
   0B60 22                 2553 	ret
                           2554 ;------------------------------------------------------------
                           2555 ;Allocation info for local variables in function 'LCD_Clear'
                           2556 ;------------------------------------------------------------
                           2557 ;------------------------------------------------------------
                           2558 ;	D:\Workspace\MIDE\firmware\/lcd.c:154: void LCD_Clear()
                           2559 ;	-----------------------------------------
                           2560 ;	 function LCD_Clear
                           2561 ;	-----------------------------------------
   0B61                    2562 _LCD_Clear:
                           2563 ;	D:\Workspace\MIDE\firmware\/lcd.c:156: LCD_CmdWrite(CMD_LCD_CLEAR);	// Clear the LCD and go to First line First Position
   0B61 75 82 01           2564 	mov	dpl,#0x01
   0B64 12 0B 9E           2565 	lcall	_LCD_CmdWrite
                           2566 ;	D:\Workspace\MIDE\firmware\/lcd.c:157: LCD_GoToLine(mENUM_LcdLineOne);
   0B67 75 82 01           2567 	mov	dpl,#0x01
   0B6A 02 0B 6D           2568 	ljmp	_LCD_GoToLine
                           2569 ;------------------------------------------------------------
                           2570 ;Allocation info for local variables in function 'LCD_GoToLine'
                           2571 ;------------------------------------------------------------
                           2572 ;var_lineNumber_u8         Allocated to registers r2 
                           2573 ;------------------------------------------------------------
                           2574 ;	D:\Workspace\MIDE\firmware\/lcd.c:181: void LCD_GoToLine(uint8_t var_lineNumber_u8)
                           2575 ;	-----------------------------------------
                           2576 ;	 function LCD_GoToLine
                           2577 ;	-----------------------------------------
   0B6D                    2578 _LCD_GoToLine:
   0B6D AA 82              2579 	mov	r2,dpl
                           2580 ;	D:\Workspace\MIDE\firmware\/lcd.c:183: if(var_lineNumber_u8 <= STK_LCDConfig.mvar_MaxSupportedLines_U8)
   0B6F E5 0A              2581 	mov	a,_STK_LCDConfig
   0B71 B5 02 00           2582 	cjne	a,ar2,00106$
   0B74                    2583 00106$:
   0B74 40 0E              2584 	jc	00103$
                           2585 ;	D:\Workspace\MIDE\firmware\/lcd.c:187: VAR_LcdTrackCursorPos_U8 = 0x00;
   0B76 75 09 00           2586 	mov	_VAR_LcdTrackCursorPos_U8,#0x00
                           2587 ;	D:\Workspace\MIDE\firmware\/lcd.c:188: VAR_LcdTrackLineNum_U8 = var_lineNumber_u8;
   0B79 8A 08              2588 	mov	_VAR_LcdTrackLineNum_U8,r2
                           2589 ;	D:\Workspace\MIDE\firmware\/lcd.c:189: LCD_CmdWrite(ARR_LcdLineNumAddress_U8[var_lineNumber_u8]);
   0B7B EA                 2590 	mov	a,r2
   0B7C 24 0D              2591 	add	a,#_ARR_LcdLineNumAddress_U8
   0B7E F8                 2592 	mov	r0,a
   0B7F 86 82              2593 	mov	dpl,@r0
   0B81 02 0B 9E           2594 	ljmp	_LCD_CmdWrite
   0B84                    2595 00103$:
   0B84 22                 2596 	ret
                           2597 ;------------------------------------------------------------
                           2598 ;Allocation info for local variables in function 'LCD_GoToNextLine'
                           2599 ;------------------------------------------------------------
                           2600 ;------------------------------------------------------------
                           2601 ;	D:\Workspace\MIDE\firmware\/lcd.c:208: void  LCD_GoToNextLine()
                           2602 ;	-----------------------------------------
                           2603 ;	 function LCD_GoToNextLine
                           2604 ;	-----------------------------------------
   0B85                    2605 _LCD_GoToNextLine:
                           2606 ;	D:\Workspace\MIDE\firmware\/lcd.c:212: VAR_LcdTrackLineNum_U8++;
   0B85 05 08              2607 	inc	_VAR_LcdTrackLineNum_U8
                           2608 ;	D:\Workspace\MIDE\firmware\/lcd.c:213: VAR_LcdTrackCursorPos_U8 = 0x00;
   0B87 75 09 00           2609 	mov	_VAR_LcdTrackCursorPos_U8,#0x00
                           2610 ;	D:\Workspace\MIDE\firmware\/lcd.c:214: if(VAR_LcdTrackLineNum_U8 > STK_LCDConfig.mvar_MaxSupportedLines_U8)
   0B8A E5 0A              2611 	mov	a,_STK_LCDConfig
   0B8C B5 08 00           2612 	cjne	a,_VAR_LcdTrackLineNum_U8,00106$
   0B8F                    2613 00106$:
   0B8F 50 03              2614 	jnc	00102$
                           2615 ;	D:\Workspace\MIDE\firmware\/lcd.c:215: VAR_LcdTrackLineNum_U8 = 0x01;
   0B91 75 08 01           2616 	mov	_VAR_LcdTrackLineNum_U8,#0x01
   0B94                    2617 00102$:
                           2618 ;	D:\Workspace\MIDE\firmware\/lcd.c:216: LCD_CmdWrite(ARR_LcdLineNumAddress_U8[VAR_LcdTrackLineNum_U8]);
   0B94 E5 08              2619 	mov	a,_VAR_LcdTrackLineNum_U8
   0B96 24 0D              2620 	add	a,#_ARR_LcdLineNumAddress_U8
   0B98 F8                 2621 	mov	r0,a
   0B99 86 82              2622 	mov	dpl,@r0
   0B9B 02 0B 9E           2623 	ljmp	_LCD_CmdWrite
                           2624 ;------------------------------------------------------------
                           2625 ;Allocation info for local variables in function 'LCD_CmdWrite'
                           2626 ;------------------------------------------------------------
                           2627 ;var_lcdCmd_u8             Allocated to registers r2 
                           2628 ;------------------------------------------------------------
                           2629 ;	D:\Workspace\MIDE\firmware\/lcd.c:274: void LCD_CmdWrite( uint8_t var_lcdCmd_u8)
                           2630 ;	-----------------------------------------
                           2631 ;	 function LCD_CmdWrite
                           2632 ;	-----------------------------------------
   0B9E                    2633 _LCD_CmdWrite:
   0B9E AA 82              2634 	mov	r2,dpl
                           2635 ;	D:\Workspace\MIDE\firmware\/lcd.c:276: lcd_BusyCheck();
   0BA0 C0 02              2636 	push	ar2
   0BA2 12 0C 56           2637 	lcall	_lcd_BusyCheck
   0BA5 D0 02              2638 	pop	ar2
                           2639 ;	D:\Workspace\MIDE\firmware\/lcd.c:277: if(STK_LCDConfig.mvar_LcdMode_U8 == M_EightBitMode)
   0BA7 AB 0C              2640 	mov	r3,(_STK_LCDConfig + 0x0002)
   0BA9 7C 00              2641 	mov	r4,#0x00
   0BAB BB 08 08           2642 	cjne	r3,#0x08,00104$
   0BAE BC 00 05           2643 	cjne	r4,#0x00,00104$
                           2644 ;	D:\Workspace\MIDE\firmware\/lcd.c:280: M_LcdDataBus = var_lcdCmd_u8;     // Send the complete command if the selected mode is 8-bit
   0BB1 8A A0              2645 	mov	_P2,r2
                           2646 ;	D:\Workspace\MIDE\firmware\/lcd.c:281: lcd_SendCmdSignals();  // Signals for command write operation
   0BB3 02 0D 16           2647 	ljmp	_lcd_SendCmdSignals
   0BB6                    2648 00104$:
                           2649 ;	D:\Workspace\MIDE\firmware\/lcd.c:283: else if(STK_LCDConfig.mvar_LcdMode_U8 == M_FourBitMode)
   0BB6 BB 04 1B           2650 	cjne	r3,#0x04,00106$
   0BB9 BC 00 18           2651 	cjne	r4,#0x00,00106$
                           2652 ;	D:\Workspace\MIDE\firmware\/lcd.c:285: lcd_SendNibble(var_lcdCmd_u8);  // Send the command in two nibbles as the selected mode is 4-bit
   0BBC 8A 82              2653 	mov	dpl,r2
   0BBE C0 02              2654 	push	ar2
   0BC0 12 0C E4           2655 	lcall	_lcd_SendNibble
                           2656 ;	D:\Workspace\MIDE\firmware\/lcd.c:286: lcd_SendCmdSignals(); // Signals for command write operation
   0BC3 12 0D 16           2657 	lcall	_lcd_SendCmdSignals
   0BC6 D0 02              2658 	pop	ar2
                           2659 ;	D:\Workspace\MIDE\firmware\/lcd.c:288: lcd_SendNibble(var_lcdCmd_u8 << 4);
   0BC8 EA                 2660 	mov	a,r2
   0BC9 C4                 2661 	swap	a
   0BCA 54 F0              2662 	anl	a,#0xf0
   0BCC F5 82              2663 	mov	dpl,a
   0BCE 12 0C E4           2664 	lcall	_lcd_SendNibble
                           2665 ;	D:\Workspace\MIDE\firmware\/lcd.c:289: lcd_SendCmdSignals();
   0BD1 02 0D 16           2666 	ljmp	_lcd_SendCmdSignals
   0BD4                    2667 00106$:
   0BD4 22                 2668 	ret
                           2669 ;------------------------------------------------------------
                           2670 ;Allocation info for local variables in function 'LCD_DisplayChar'
                           2671 ;------------------------------------------------------------
                           2672 ;var_lcdData_u8            Allocated to registers r2 
                           2673 ;------------------------------------------------------------
                           2674 ;	D:\Workspace\MIDE\firmware\/lcd.c:309: void LCD_DisplayChar(char var_lcdData_u8)
                           2675 ;	-----------------------------------------
                           2676 ;	 function LCD_DisplayChar
                           2677 ;	-----------------------------------------
   0BD5                    2678 _LCD_DisplayChar:
   0BD5 AA 82              2679 	mov	r2,dpl
                           2680 ;	D:\Workspace\MIDE\firmware\/lcd.c:311: if((VAR_LcdTrackCursorPos_U8>=STK_LCDConfig.mvar_MaxSupportedChars_U8) || (var_lcdData_u8=='\n'))
   0BD7 E5 09              2681 	mov	a,_VAR_LcdTrackCursorPos_U8
   0BD9 B5 0B 00           2682 	cjne	a,(_STK_LCDConfig + 0x0001),00110$
   0BDC                    2683 00110$:
   0BDC 50 03              2684 	jnc	00101$
   0BDE BA 0A 07           2685 	cjne	r2,#0x0A,00102$
   0BE1                    2686 00101$:
                           2687 ;	D:\Workspace\MIDE\firmware\/lcd.c:315: LCD_GoToNextLine();
   0BE1 C0 02              2688 	push	ar2
   0BE3 12 0B 85           2689 	lcall	_LCD_GoToNextLine
   0BE6 D0 02              2690 	pop	ar2
   0BE8                    2691 00102$:
                           2692 ;	D:\Workspace\MIDE\firmware\/lcd.c:317: if(var_lcdData_u8!='\n') /* Display the character if its not newLine Char */
   0BE8 BA 0A 01           2693 	cjne	r2,#0x0A,00114$
   0BEB 22                 2694 	ret
   0BEC                    2695 00114$:
                           2696 ;	D:\Workspace\MIDE\firmware\/lcd.c:320: lcd_DataWrite(var_lcdData_u8); /* Display the data and keep track of cursor */
   0BEC 8A 82              2697 	mov	dpl,r2
   0BEE 12 0C 1F           2698 	lcall	_lcd_DataWrite
                           2699 ;	D:\Workspace\MIDE\firmware\/lcd.c:321: VAR_LcdTrackCursorPos_U8++;
   0BF1 05 09              2700 	inc	_VAR_LcdTrackCursorPos_U8
   0BF3 22                 2701 	ret
                           2702 ;------------------------------------------------------------
                           2703 ;Allocation info for local variables in function 'LCD_DisplayString'
                           2704 ;------------------------------------------------------------
                           2705 ;ptr_stringPointer_u8      Allocated to registers r2 r3 r4 
                           2706 ;------------------------------------------------------------
                           2707 ;	D:\Workspace\MIDE\firmware\/lcd.c:344: void LCD_DisplayString(char *ptr_stringPointer_u8)
                           2708 ;	-----------------------------------------
                           2709 ;	 function LCD_DisplayString
                           2710 ;	-----------------------------------------
   0BF4                    2711 _LCD_DisplayString:
   0BF4 AA 82              2712 	mov	r2,dpl
   0BF6 AB 83              2713 	mov	r3,dph
   0BF8 AC F0              2714 	mov	r4,b
                           2715 ;	D:\Workspace\MIDE\firmware\/lcd.c:346: while((*ptr_stringPointer_u8)!=0)
   0BFA                    2716 00101$:
   0BFA 8A 82              2717 	mov	dpl,r2
   0BFC 8B 83              2718 	mov	dph,r3
   0BFE 8C F0              2719 	mov	b,r4
   0C00 12 15 C3           2720 	lcall	__gptrget
   0C03 FD                 2721 	mov	r5,a
   0C04 60 18              2722 	jz	00104$
                           2723 ;	D:\Workspace\MIDE\firmware\/lcd.c:347: LCD_DisplayChar(*ptr_stringPointer_u8++); // Loop through the string and display char by char
   0C06 0A                 2724 	inc	r2
   0C07 BA 00 01           2725 	cjne	r2,#0x00,00110$
   0C0A 0B                 2726 	inc	r3
   0C0B                    2727 00110$:
   0C0B 8D 82              2728 	mov	dpl,r5
   0C0D C0 02              2729 	push	ar2
   0C0F C0 03              2730 	push	ar3
   0C11 C0 04              2731 	push	ar4
   0C13 12 0B D5           2732 	lcall	_LCD_DisplayChar
   0C16 D0 04              2733 	pop	ar4
   0C18 D0 03              2734 	pop	ar3
   0C1A D0 02              2735 	pop	ar2
   0C1C 80 DC              2736 	sjmp	00101$
   0C1E                    2737 00104$:
   0C1E 22                 2738 	ret
                           2739 ;------------------------------------------------------------
                           2740 ;Allocation info for local variables in function 'lcd_DataWrite'
                           2741 ;------------------------------------------------------------
                           2742 ;dat                       Allocated to registers r2 
                           2743 ;------------------------------------------------------------
                           2744 ;	D:\Workspace\MIDE\firmware\/lcd.c:839: static void lcd_DataWrite( uint8_t dat)
                           2745 ;	-----------------------------------------
                           2746 ;	 function lcd_DataWrite
                           2747 ;	-----------------------------------------
   0C1F                    2748 _lcd_DataWrite:
   0C1F AA 82              2749 	mov	r2,dpl
                           2750 ;	D:\Workspace\MIDE\firmware\/lcd.c:841: lcd_BusyCheck();
   0C21 C0 02              2751 	push	ar2
   0C23 12 0C 56           2752 	lcall	_lcd_BusyCheck
   0C26 D0 02              2753 	pop	ar2
                           2754 ;	D:\Workspace\MIDE\firmware\/lcd.c:842: if(STK_LCDConfig.mvar_LcdMode_U8 == M_EightBitMode)
   0C28 AB 0C              2755 	mov	r3,(_STK_LCDConfig + 0x0002)
   0C2A 7C 00              2756 	mov	r4,#0x00
   0C2C BB 08 08           2757 	cjne	r3,#0x08,00104$
   0C2F BC 00 05           2758 	cjne	r4,#0x00,00104$
                           2759 ;	D:\Workspace\MIDE\firmware\/lcd.c:844: M_LcdDataBus = dat;      // Send the complete data byte if the selected mode is 8-bit
   0C32 8A A0              2760 	mov	_P2,r2
                           2761 ;	D:\Workspace\MIDE\firmware\/lcd.c:845: lcd_SendDataSignals();  // Signals for data write operation
   0C34 02 0D 29           2762 	ljmp	_lcd_SendDataSignals
   0C37                    2763 00104$:
                           2764 ;	D:\Workspace\MIDE\firmware\/lcd.c:847: else if(STK_LCDConfig.mvar_LcdMode_U8 == M_FourBitMode)
   0C37 BB 04 1B           2765 	cjne	r3,#0x04,00106$
   0C3A BC 00 18           2766 	cjne	r4,#0x00,00106$
                           2767 ;	D:\Workspace\MIDE\firmware\/lcd.c:849: lcd_SendNibble(dat);    // Send the data in two nibbles as the selected mode is 4-bit
   0C3D 8A 82              2768 	mov	dpl,r2
   0C3F C0 02              2769 	push	ar2
   0C41 12 0C E4           2770 	lcall	_lcd_SendNibble
                           2771 ;	D:\Workspace\MIDE\firmware\/lcd.c:850: lcd_SendDataSignals();  // Signals for data write operation
   0C44 12 0D 29           2772 	lcall	_lcd_SendDataSignals
   0C47 D0 02              2773 	pop	ar2
                           2774 ;	D:\Workspace\MIDE\firmware\/lcd.c:852: lcd_SendNibble(dat << 4);
   0C49 EA                 2775 	mov	a,r2
   0C4A C4                 2776 	swap	a
   0C4B 54 F0              2777 	anl	a,#0xf0
   0C4D F5 82              2778 	mov	dpl,a
   0C4F 12 0C E4           2779 	lcall	_lcd_SendNibble
                           2780 ;	D:\Workspace\MIDE\firmware\/lcd.c:853: lcd_SendDataSignals();
   0C52 02 0D 29           2781 	ljmp	_lcd_SendDataSignals
   0C55                    2782 00106$:
   0C55 22                 2783 	ret
                           2784 ;------------------------------------------------------------
                           2785 ;Allocation info for local variables in function 'lcd_BusyCheck'
                           2786 ;------------------------------------------------------------
                           2787 ;busyflag                  Allocated to registers r2 
                           2788 ;------------------------------------------------------------
                           2789 ;	D:\Workspace\MIDE\firmware\/lcd.c:873: static void lcd_BusyCheck()
                           2790 ;	-----------------------------------------
                           2791 ;	 function lcd_BusyCheck
                           2792 ;	-----------------------------------------
   0C56                    2793 _lcd_BusyCheck:
                           2794 ;	D:\Workspace\MIDE\firmware\/lcd.c:878: util_UpdateBit(M_LcdDataBusDirection,LCD_D7,C_PinInput_U8); // Configure busy pin as input
   0C56 43 A0 80           2795 	orl	_P2,#0x80
                           2796 ;	D:\Workspace\MIDE\firmware\/lcd.c:879: M_LcdClearBit(LCD_RS);           // Select the Command Register by pulling RS LOW
   0C59 53 80 FE           2797 	anl	_P0,#0xFE
                           2798 ;	D:\Workspace\MIDE\firmware\/lcd.c:880: M_LcdSetBit(LCD_RW);             // Select the Read Operation for busy flag by setting RW
   0C5C 43 80 02           2799 	orl	_P0,#0x02
                           2800 ;	D:\Workspace\MIDE\firmware\/lcd.c:881: do
   0C5F                    2801 00103$:
                           2802 ;	D:\Workspace\MIDE\firmware\/lcd.c:884: M_LcdClearBit(LCD_EN);             // Send a High-to-Low Pulse at Enable Pin
   0C5F 53 80 FB           2803 	anl	_P0,#0xFB
                           2804 ;	D:\Workspace\MIDE\firmware\/lcd.c:885: DELAY_us(10);	
   0C62 90 00 0A           2805 	mov	dptr,#0x000A
   0C65 12 0D 3C           2806 	lcall	_DELAY_us
                           2807 ;	D:\Workspace\MIDE\firmware\/lcd.c:886: M_LcdSetBit(LCD_EN); 
   0C68 43 80 04           2808 	orl	_P0,#0x04
                           2809 ;	D:\Workspace\MIDE\firmware\/lcd.c:887: DELAY_us(10);
   0C6B 90 00 0A           2810 	mov	dptr,#0x000A
   0C6E 12 0D 3C           2811 	lcall	_DELAY_us
                           2812 ;	D:\Workspace\MIDE\firmware\/lcd.c:888: busyflag = util_GetBitStatus(M_LcdDataBusInput,LCD_D7);
   0C71 74 80              2813 	mov	a,#0x80
   0C73 55 A0              2814 	anl	a,_P2
   0C75 FA                 2815 	mov	r2,a
   0C76 E4                 2816 	clr	a
   0C77 FB                 2817 	mov	r3,a
   0C78 BA 00 04           2818 	cjne	r2,#0x00,00111$
   0C7B BB 00 01           2819 	cjne	r3,#0x00,00111$
   0C7E 04                 2820 	inc	a
   0C7F                    2821 00111$:
   0C7F FA                 2822 	mov	r2,a
   0C80 B4 01 00           2823 	cjne	a,#0x01,00113$
   0C83                    2824 00113$:
   0C83 E4                 2825 	clr	a
   0C84 33                 2826 	rlc	a
   0C85 FA                 2827 	mov	r2,a
                           2828 ;	D:\Workspace\MIDE\firmware\/lcd.c:891: if(STK_LCDConfig.mvar_LcdMode_U8 == 4)
   0C86 74 04              2829 	mov	a,#0x04
   0C88 B5 0C 16           2830 	cjne	a,(_STK_LCDConfig + 0x0002),00104$
                           2831 ;	D:\Workspace\MIDE\firmware\/lcd.c:894: M_LcdClearBit(LCD_EN);
   0C8B 53 80 FB           2832 	anl	_P0,#0xFB
                           2833 ;	D:\Workspace\MIDE\firmware\/lcd.c:895: DELAY_us(10);
   0C8E 90 00 0A           2834 	mov	dptr,#0x000A
   0C91 C0 02              2835 	push	ar2
   0C93 12 0D 3C           2836 	lcall	_DELAY_us
                           2837 ;	D:\Workspace\MIDE\firmware\/lcd.c:896: M_LcdSetBit(LCD_EN); 
   0C96 43 80 04           2838 	orl	_P0,#0x04
                           2839 ;	D:\Workspace\MIDE\firmware\/lcd.c:897: DELAY_us(10);
   0C99 90 00 0A           2840 	mov	dptr,#0x000A
   0C9C 12 0D 3C           2841 	lcall	_DELAY_us
   0C9F D0 02              2842 	pop	ar2
   0CA1                    2843 00104$:
                           2844 ;	D:\Workspace\MIDE\firmware\/lcd.c:899: }while(busyflag);
   0CA1 EA                 2845 	mov	a,r2
   0CA2 70 BB              2846 	jnz	00103$
                           2847 ;	D:\Workspace\MIDE\firmware\/lcd.c:901: util_UpdateBit(M_LcdDataBusDirection,LCD_D7,C_PinOutput_U8);
   0CA4 53 A0 7F           2848 	anl	_P2,#0x7F
   0CA7 22                 2849 	ret
                           2850 ;------------------------------------------------------------
                           2851 ;Allocation info for local variables in function 'lcd_Reset'
                           2852 ;------------------------------------------------------------
                           2853 ;------------------------------------------------------------
                           2854 ;	D:\Workspace\MIDE\firmware\/lcd.c:923: static void lcd_Reset()
                           2855 ;	-----------------------------------------
                           2856 ;	 function lcd_Reset
                           2857 ;	-----------------------------------------
   0CA8                    2858 _lcd_Reset:
                           2859 ;	D:\Workspace\MIDE\firmware\/lcd.c:926: lcd_SendNibble(0x30);
   0CA8 75 82 30           2860 	mov	dpl,#0x30
   0CAB 12 0C E4           2861 	lcall	_lcd_SendNibble
                           2862 ;	D:\Workspace\MIDE\firmware\/lcd.c:927: lcd_SendCmdSignals();
   0CAE 12 0D 16           2863 	lcall	_lcd_SendCmdSignals
                           2864 ;	D:\Workspace\MIDE\firmware\/lcd.c:928: DELAY_ms(100);
   0CB1 90 00 64           2865 	mov	dptr,#0x0064
   0CB4 12 0D 4C           2866 	lcall	_DELAY_ms
                           2867 ;	D:\Workspace\MIDE\firmware\/lcd.c:929: lcd_SendNibble(0x30);
   0CB7 75 82 30           2868 	mov	dpl,#0x30
   0CBA 12 0C E4           2869 	lcall	_lcd_SendNibble
                           2870 ;	D:\Workspace\MIDE\firmware\/lcd.c:930: lcd_SendCmdSignals();
   0CBD 12 0D 16           2871 	lcall	_lcd_SendCmdSignals
                           2872 ;	D:\Workspace\MIDE\firmware\/lcd.c:931: DELAY_us(200);
   0CC0 90 00 C8           2873 	mov	dptr,#0x00C8
   0CC3 12 0D 3C           2874 	lcall	_DELAY_us
                           2875 ;	D:\Workspace\MIDE\firmware\/lcd.c:932: lcd_SendNibble(0x30);
   0CC6 75 82 30           2876 	mov	dpl,#0x30
   0CC9 12 0C E4           2877 	lcall	_lcd_SendNibble
                           2878 ;	D:\Workspace\MIDE\firmware\/lcd.c:933: lcd_SendCmdSignals();
   0CCC 12 0D 16           2879 	lcall	_lcd_SendCmdSignals
                           2880 ;	D:\Workspace\MIDE\firmware\/lcd.c:934: DELAY_us(200);
   0CCF 90 00 C8           2881 	mov	dptr,#0x00C8
   0CD2 12 0D 3C           2882 	lcall	_DELAY_us
                           2883 ;	D:\Workspace\MIDE\firmware\/lcd.c:935: lcd_SendNibble(0x20);
   0CD5 75 82 20           2884 	mov	dpl,#0x20
   0CD8 12 0C E4           2885 	lcall	_lcd_SendNibble
                           2886 ;	D:\Workspace\MIDE\firmware\/lcd.c:936: lcd_SendCmdSignals();
   0CDB 12 0D 16           2887 	lcall	_lcd_SendCmdSignals
                           2888 ;	D:\Workspace\MIDE\firmware\/lcd.c:937: DELAY_us(200);
   0CDE 90 00 C8           2889 	mov	dptr,#0x00C8
   0CE1 02 0D 3C           2890 	ljmp	_DELAY_us
                           2891 ;------------------------------------------------------------
                           2892 ;Allocation info for local variables in function 'lcd_SendNibble'
                           2893 ;------------------------------------------------------------
                           2894 ;var                       Allocated to registers r2 
                           2895 ;------------------------------------------------------------
                           2896 ;	D:\Workspace\MIDE\firmware\/lcd.c:953: static void lcd_SendNibble(uint8_t var)
                           2897 ;	-----------------------------------------
                           2898 ;	 function lcd_SendNibble
                           2899 ;	-----------------------------------------
   0CE4                    2900 _lcd_SendNibble:
                           2901 ;	D:\Workspace\MIDE\firmware\/lcd.c:955: util_UpdateBit(M_LcdDataBus,LCD_D4,util_GetBitStatus(var,LCD_D4));
   0CE4 E5 82              2902 	mov	a,dpl
   0CE6 FA                 2903 	mov	r2,a
   0CE7 30 E4 05           2904 	jnb	acc.4,00103$
   0CEA 43 A0 10           2905 	orl	_P2,#0x10
   0CED 80 03              2906 	sjmp	00104$
   0CEF                    2907 00103$:
   0CEF 53 A0 EF           2908 	anl	_P2,#0xEF
   0CF2                    2909 00104$:
                           2910 ;	D:\Workspace\MIDE\firmware\/lcd.c:956: util_UpdateBit(M_LcdDataBus,LCD_D5,util_GetBitStatus(var,LCD_D5));
   0CF2 EA                 2911 	mov	a,r2
   0CF3 30 E5 05           2912 	jnb	acc.5,00105$
   0CF6 43 A0 20           2913 	orl	_P2,#0x20
   0CF9 80 03              2914 	sjmp	00106$
   0CFB                    2915 00105$:
   0CFB 53 A0 DF           2916 	anl	_P2,#0xDF
   0CFE                    2917 00106$:
                           2918 ;	D:\Workspace\MIDE\firmware\/lcd.c:957: util_UpdateBit(M_LcdDataBus,LCD_D6,util_GetBitStatus(var,LCD_D6));
   0CFE EA                 2919 	mov	a,r2
   0CFF 30 E6 05           2920 	jnb	acc.6,00107$
   0D02 43 A0 40           2921 	orl	_P2,#0x40
   0D05 80 03              2922 	sjmp	00108$
   0D07                    2923 00107$:
   0D07 53 A0 BF           2924 	anl	_P2,#0xBF
   0D0A                    2925 00108$:
                           2926 ;	D:\Workspace\MIDE\firmware\/lcd.c:958: util_UpdateBit(M_LcdDataBus,LCD_D7,util_GetBitStatus(var,LCD_D7));
   0D0A EA                 2927 	mov	a,r2
   0D0B 30 E7 04           2928 	jnb	acc.7,00109$
   0D0E 43 A0 80           2929 	orl	_P2,#0x80
   0D11 22                 2930 	ret
   0D12                    2931 00109$:
   0D12 53 A0 7F           2932 	anl	_P2,#0x7F
   0D15 22                 2933 	ret
                           2934 ;------------------------------------------------------------
                           2935 ;Allocation info for local variables in function 'lcd_SendCmdSignals'
                           2936 ;------------------------------------------------------------
                           2937 ;------------------------------------------------------------
                           2938 ;	D:\Workspace\MIDE\firmware\/lcd.c:972: static void lcd_SendCmdSignals()
                           2939 ;	-----------------------------------------
                           2940 ;	 function lcd_SendCmdSignals
                           2941 ;	-----------------------------------------
   0D16                    2942 _lcd_SendCmdSignals:
                           2943 ;	D:\Workspace\MIDE\firmware\/lcd.c:974: M_LcdClearBit(LCD_RS);           // Select the Command Register by pulling RS LOW
   0D16 53 80 FE           2944 	anl	_P0,#0xFE
                           2945 ;	D:\Workspace\MIDE\firmware\/lcd.c:976: M_LcdClearBit(LCD_RW);           // Select the Write Operation  by pulling RW LOW
   0D19 53 80 FD           2946 	anl	_P0,#0xFD
                           2947 ;	D:\Workspace\MIDE\firmware\/lcd.c:978: M_LcdSetBit(LCD_EN);             // Send a High-to-Low Pusle at Enable Pin
   0D1C 43 80 04           2948 	orl	_P0,#0x04
                           2949 ;	D:\Workspace\MIDE\firmware\/lcd.c:979: DELAY_us(10);
   0D1F 90 00 0A           2950 	mov	dptr,#0x000A
   0D22 12 0D 3C           2951 	lcall	_DELAY_us
                           2952 ;	D:\Workspace\MIDE\firmware\/lcd.c:980: M_LcdClearBit(LCD_EN);
   0D25 53 80 FB           2953 	anl	_P0,#0xFB
   0D28 22                 2954 	ret
                           2955 ;------------------------------------------------------------
                           2956 ;Allocation info for local variables in function 'lcd_SendDataSignals'
                           2957 ;------------------------------------------------------------
                           2958 ;------------------------------------------------------------
                           2959 ;	D:\Workspace\MIDE\firmware\/lcd.c:994: static void lcd_SendDataSignals()
                           2960 ;	-----------------------------------------
                           2961 ;	 function lcd_SendDataSignals
                           2962 ;	-----------------------------------------
   0D29                    2963 _lcd_SendDataSignals:
                           2964 ;	D:\Workspace\MIDE\firmware\/lcd.c:996: M_LcdSetBit(LCD_RS); 			// Select the Data Register by pulling RS HIGH
   0D29 43 80 01           2965 	orl	_P0,#0x01
                           2966 ;	D:\Workspace\MIDE\firmware\/lcd.c:998: M_LcdClearBit(LCD_RW);          // Select the Write Operation  by pulling RW LOW
   0D2C 53 80 FD           2967 	anl	_P0,#0xFD
                           2968 ;	D:\Workspace\MIDE\firmware\/lcd.c:1000: M_LcdSetBit(LCD_EN);            // Send a High-to-Low Pusle at Enable Pin
   0D2F 43 80 04           2969 	orl	_P0,#0x04
                           2970 ;	D:\Workspace\MIDE\firmware\/lcd.c:1001: DELAY_us(10);
   0D32 90 00 0A           2971 	mov	dptr,#0x000A
   0D35 12 0D 3C           2972 	lcall	_DELAY_us
                           2973 ;	D:\Workspace\MIDE\firmware\/lcd.c:1002: M_LcdClearBit(LCD_EN);
   0D38 53 80 FB           2974 	anl	_P0,#0xFB
   0D3B 22                 2975 	ret
                           2976 ;------------------------------------------------------------
                           2977 ;Allocation info for local variables in function 'DELAY_us'
                           2978 ;------------------------------------------------------------
                           2979 ;us_count                  Allocated to registers r2 r3 
                           2980 ;------------------------------------------------------------
                           2981 ;	D:\Workspace\MIDE\firmware\/delay.c:55: void DELAY_us(uint16_t us_count)
                           2982 ;	-----------------------------------------
                           2983 ;	 function DELAY_us
                           2984 ;	-----------------------------------------
   0D3C                    2985 _DELAY_us:
   0D3C AA 82              2986 	mov	r2,dpl
   0D3E AB 83              2987 	mov	r3,dph
                           2988 ;	D:\Workspace\MIDE\firmware\/delay.c:57: while(us_count!=0)
   0D40                    2989 00101$:
   0D40 EA                 2990 	mov	a,r2
   0D41 4B                 2991 	orl	a,r3
   0D42 60 07              2992 	jz	00104$
                           2993 ;	D:\Workspace\MIDE\firmware\/delay.c:59: us_count--;
   0D44 1A                 2994 	dec	r2
   0D45 BA FF F8           2995 	cjne	r2,#0xff,00101$
   0D48 1B                 2996 	dec	r3
   0D49 80 F5              2997 	sjmp	00101$
   0D4B                    2998 00104$:
   0D4B 22                 2999 	ret
                           3000 ;------------------------------------------------------------
                           3001 ;Allocation info for local variables in function 'DELAY_ms'
                           3002 ;------------------------------------------------------------
                           3003 ;ms_count                  Allocated to registers r2 r3 
                           3004 ;------------------------------------------------------------
                           3005 ;	D:\Workspace\MIDE\firmware\/delay.c:76: void DELAY_ms(uint16_t ms_count)
                           3006 ;	-----------------------------------------
                           3007 ;	 function DELAY_ms
                           3008 ;	-----------------------------------------
   0D4C                    3009 _DELAY_ms:
   0D4C AA 82              3010 	mov	r2,dpl
   0D4E AB 83              3011 	mov	r3,dph
                           3012 ;	D:\Workspace\MIDE\firmware\/delay.c:78: while(ms_count!=0)
   0D50                    3013 00101$:
   0D50 EA                 3014 	mov	a,r2
   0D51 4B                 3015 	orl	a,r3
   0D52 60 15              3016 	jz	00104$
                           3017 ;	D:\Workspace\MIDE\firmware\/delay.c:80: DELAY_us(C_CountForOneMsDelay_U16);	 //DELAY_us is called to generate 1ms delay
   0D54 90 00 70           3018 	mov	dptr,#0x0070
   0D57 C0 02              3019 	push	ar2
   0D59 C0 03              3020 	push	ar3
   0D5B 12 0D 3C           3021 	lcall	_DELAY_us
   0D5E D0 03              3022 	pop	ar3
   0D60 D0 02              3023 	pop	ar2
                           3024 ;	D:\Workspace\MIDE\firmware\/delay.c:81: ms_count--;
   0D62 1A                 3025 	dec	r2
   0D63 BA FF EA           3026 	cjne	r2,#0xff,00101$
   0D66 1B                 3027 	dec	r3
   0D67 80 E7              3028 	sjmp	00101$
   0D69                    3029 00104$:
   0D69 22                 3030 	ret
                           3031 ;------------------------------------------------------------
                           3032 ;Allocation info for local variables in function 'DELAY_sec'
                           3033 ;------------------------------------------------------------
                           3034 ;sec_count                 Allocated to registers r2 r3 
                           3035 ;------------------------------------------------------------
                           3036 ;	D:\Workspace\MIDE\firmware\/delay.c:102: void DELAY_sec(uint16_t sec_count)
                           3037 ;	-----------------------------------------
                           3038 ;	 function DELAY_sec
                           3039 ;	-----------------------------------------
   0D6A                    3040 _DELAY_sec:
   0D6A AA 82              3041 	mov	r2,dpl
   0D6C AB 83              3042 	mov	r3,dph
                           3043 ;	D:\Workspace\MIDE\firmware\/delay.c:106: while(sec_count!=0)
   0D6E                    3044 00101$:
   0D6E EA                 3045 	mov	a,r2
   0D6F 4B                 3046 	orl	a,r3
   0D70 60 15              3047 	jz	00104$
                           3048 ;	D:\Workspace\MIDE\firmware\/delay.c:108: DELAY_ms(1000);	//DELAY_ms is called to generate 1sec delay
   0D72 90 03 E8           3049 	mov	dptr,#0x03E8
   0D75 C0 02              3050 	push	ar2
   0D77 C0 03              3051 	push	ar3
   0D79 12 0D 4C           3052 	lcall	_DELAY_ms
   0D7C D0 03              3053 	pop	ar3
   0D7E D0 02              3054 	pop	ar2
                           3055 ;	D:\Workspace\MIDE\firmware\/delay.c:109: sec_count--;
   0D80 1A                 3056 	dec	r2
   0D81 BA FF EA           3057 	cjne	r2,#0xff,00101$
   0D84 1B                 3058 	dec	r3
   0D85 80 E7              3059 	sjmp	00101$
   0D87                    3060 00104$:
   0D87 22                 3061 	ret
                           3062 ;------------------------------------------------------------
                           3063 ;Allocation info for local variables in function 'ADC_Init'
                           3064 ;------------------------------------------------------------
                           3065 ;------------------------------------------------------------
                           3066 ;	D:\Workspace\MIDE\firmware\/adc.c:58: void ADC_Init()
                           3067 ;	-----------------------------------------
                           3068 ;	 function ADC_Init
                           3069 ;	-----------------------------------------
   0D88                    3070 _ADC_Init:
                           3071 ;	D:\Workspace\MIDE\firmware\/adc.c:60: util_BitClear(adc_controlbus,adc_Start); 
   0D88 53 80 EF           3072 	anl	_P0,#0xEF
                           3073 ;	D:\Workspace\MIDE\firmware\/adc.c:61: util_BitClear(adc_controlbus,adc_ALE); 
   0D8B 53 80 F7           3074 	anl	_P0,#0xF7
                           3075 ;	D:\Workspace\MIDE\firmware\/adc.c:62: util_BitClear(adc_controlbus,adc_OE); 
   0D8E 53 80 BF           3076 	anl	_P0,#0xBF
                           3077 ;	D:\Workspace\MIDE\firmware\/adc.c:63: util_BitSet(adc_controlbus,adc_OE); 
   0D91 43 80 40           3078 	orl	_P0,#0x40
                           3079 ;	D:\Workspace\MIDE\firmware\/adc.c:64: adc_databus=0xff; 
   0D94 75 90 FF           3080 	mov	_P1,#0xFF
   0D97 22                 3081 	ret
                           3082 ;------------------------------------------------------------
                           3083 ;Allocation info for local variables in function 'ADC_GetAdcValue'
                           3084 ;------------------------------------------------------------
                           3085 ;var_adcChannel_u8         Allocated to registers r2 
                           3086 ;adc_result                Allocated to registers r2 r3 
                           3087 ;------------------------------------------------------------
                           3088 ;	D:\Workspace\MIDE\firmware\/adc.c:111: uint16_t ADC_GetAdcValue(uint8_t var_adcChannel_u8)
                           3089 ;	-----------------------------------------
                           3090 ;	 function ADC_GetAdcValue
                           3091 ;	-----------------------------------------
   0D98                    3092 _ADC_GetAdcValue:
                           3093 ;	D:\Workspace\MIDE\firmware\/adc.c:119: util_UpdateBit(adc_controlbus,adc_A,util_GetBitStatus(var_adcChannel_u8,0X00)); 
   0D98 E5 82              3094 	mov	a,dpl
   0D9A FA                 3095 	mov	r2,a
   0D9B 30 E0 05           3096 	jnb	acc.0,00106$
   0D9E 43 80 01           3097 	orl	_P0,#0x01
   0DA1 80 03              3098 	sjmp	00107$
   0DA3                    3099 00106$:
   0DA3 53 80 FE           3100 	anl	_P0,#0xFE
   0DA6                    3101 00107$:
                           3102 ;	D:\Workspace\MIDE\firmware\/adc.c:120: util_UpdateBit(adc_controlbus,adc_B,util_GetBitStatus(var_adcChannel_u8,0X01));	
   0DA6 EA                 3103 	mov	a,r2
   0DA7 30 E1 05           3104 	jnb	acc.1,00108$
   0DAA 43 80 02           3105 	orl	_P0,#0x02
   0DAD 80 03              3106 	sjmp	00109$
   0DAF                    3107 00108$:
   0DAF 53 80 FD           3108 	anl	_P0,#0xFD
   0DB2                    3109 00109$:
                           3110 ;	D:\Workspace\MIDE\firmware\/adc.c:121: util_UpdateBit(adc_controlbus,adc_C,util_GetBitStatus(var_adcChannel_u8,0X02));
   0DB2 EA                 3111 	mov	a,r2
   0DB3 30 E2 05           3112 	jnb	acc.2,00110$
   0DB6 43 80 04           3113 	orl	_P0,#0x04
   0DB9 80 03              3114 	sjmp	00111$
   0DBB                    3115 00110$:
   0DBB 53 80 FB           3116 	anl	_P0,#0xFB
   0DBE                    3117 00111$:
                           3118 ;	D:\Workspace\MIDE\firmware\/adc.c:124: util_BitSet(adc_controlbus,adc_ALE);        // Latch the address by making the ALE high.
   0DBE 43 80 08           3119 	orl	_P0,#0x08
                           3120 ;	D:\Workspace\MIDE\firmware\/adc.c:125: DELAY_us(50);
   0DC1 90 00 32           3121 	mov	dptr,#0x0032
   0DC4 12 0D 3C           3122 	lcall	_DELAY_us
                           3123 ;	D:\Workspace\MIDE\firmware\/adc.c:126: util_BitSet(adc_controlbus,adc_Start);       //Start the conversion after latching the channel address
   0DC7 43 80 10           3124 	orl	_P0,#0x10
                           3125 ;	D:\Workspace\MIDE\firmware\/adc.c:127: DELAY_us(25);
   0DCA 90 00 19           3126 	mov	dptr,#0x0019
   0DCD 12 0D 3C           3127 	lcall	_DELAY_us
                           3128 ;	D:\Workspace\MIDE\firmware\/adc.c:129: util_BitClear(adc_controlbus,adc_ALE);          //Pull ALE line to zero after starting the conversion.
   0DD0 53 80 F7           3129 	anl	_P0,#0xF7
                           3130 ;	D:\Workspace\MIDE\firmware\/adc.c:130: DELAY_us(50);
   0DD3 90 00 32           3131 	mov	dptr,#0x0032
   0DD6 12 0D 3C           3132 	lcall	_DELAY_us
                           3133 ;	D:\Workspace\MIDE\firmware\/adc.c:131: util_BitClear(adc_controlbus,adc_Start);;       //Pull Start line to zero after starting the conversion.
   0DD9 53 80 EF           3134 	anl	_P0,#0xEF
                           3135 ;	D:\Workspace\MIDE\firmware\/adc.c:134: while(util_GetBitStatus(adc_controlbus,adc_EOC)==0);    // Wait till the ADC conversion is completed,
   0DDC                    3136 00101$:
   0DDC 74 20              3137 	mov	a,#0x20
   0DDE 55 80              3138 	anl	a,_P0
   0DE0 FA                 3139 	mov	r2,a
   0DE1 7B 00              3140 	mov	r3,#0x00
   0DE3 BA 00 05           3141 	cjne	r2,#0x00,00120$
   0DE6 BB 00 02           3142 	cjne	r3,#0x00,00120$
   0DE9 80 F1              3143 	sjmp	00101$
   0DEB                    3144 00120$:
                           3145 ;	D:\Workspace\MIDE\firmware\/adc.c:138: util_BitSet(adc_controlbus,adc_OE);          //Make the Output Enable high
   0DEB 43 80 40           3146 	orl	_P0,#0x40
                           3147 ;	D:\Workspace\MIDE\firmware\/adc.c:140: DELAY_us(25);
   0DEE 90 00 19           3148 	mov	dptr,#0x0019
   0DF1 12 0D 3C           3149 	lcall	_DELAY_us
                           3150 ;	D:\Workspace\MIDE\firmware\/adc.c:141: adc_result=adc_databus;  //Read the ADC data from ADC bus
   0DF4 AA 90              3151 	mov	r2,_P1
   0DF6 7B 00              3152 	mov	r3,#0x00
                           3153 ;	D:\Workspace\MIDE\firmware\/adc.c:142: util_BitClear(adc_controlbus,adc_OE); 			  //After reading the data, disable th ADC output line.
   0DF8 53 80 BF           3154 	anl	_P0,#0xBF
                           3155 ;	D:\Workspace\MIDE\firmware\/adc.c:144: return(adc_result) ;
   0DFB 8A 82              3156 	mov	dpl,r2
   0DFD 8B 83              3157 	mov	dph,r3
   0DFF 22                 3158 	ret
                           3159 ;------------------------------------------------------------
                           3160 ;Allocation info for local variables in function 'KEYPAD_Init'
                           3161 ;------------------------------------------------------------
                           3162 ;------------------------------------------------------------
                           3163 ;	D:\Workspace\MIDE\firmware\/keypad.c:101: void KEYPAD_Init()
                           3164 ;	-----------------------------------------
                           3165 ;	 function KEYPAD_Init
                           3166 ;	-----------------------------------------
   0E00                    3167 _KEYPAD_Init:
                           3168 ;	D:\Workspace\MIDE\firmware\/keypad.c:103: M_RowColDirection= C_RowOutputColInput_U8; // Configure Row lines as O/P and Column lines as I/P
   0E00 75 A0 0F           3169 	mov	_P2,#0x0F
   0E03 22                 3170 	ret
                           3171 ;------------------------------------------------------------
                           3172 ;Allocation info for local variables in function 'KEYPAD_WaitForKeyRelease'
                           3173 ;------------------------------------------------------------
                           3174 ;key                       Allocated to registers r2 
                           3175 ;------------------------------------------------------------
                           3176 ;	D:\Workspace\MIDE\firmware\/keypad.c:118: void KEYPAD_WaitForKeyRelease()
                           3177 ;	-----------------------------------------
                           3178 ;	 function KEYPAD_WaitForKeyRelease
                           3179 ;	-----------------------------------------
   0E04                    3180 _KEYPAD_WaitForKeyRelease:
                           3181 ;	D:\Workspace\MIDE\firmware\/keypad.c:123: do
   0E04                    3182 00101$:
                           3183 ;	D:\Workspace\MIDE\firmware\/keypad.c:125: M_ROW=0x0F;           // Pull the ROW lines to low and Column lines high.
                           3184 ;	D:\Workspace\MIDE\firmware\/keypad.c:126: key=M_COL & 0x0F;     // Read the Columns, to check the key press
   0E04 74 0F              3185 	mov	a,#0x0F
   0E06 F5 A0              3186 	mov	_P2,a
   0E08 55 A0              3187 	anl	a,_P2
   0E0A FA                 3188 	mov	r2,a
                           3189 ;	D:\Workspace\MIDE\firmware\/keypad.c:127: }while(key!=0x0F);
   0E0B BA 0F F6           3190 	cjne	r2,#0x0F,00101$
                           3191 ;	D:\Workspace\MIDE\firmware\/keypad.c:129: DELAY_ms(1);
   0E0E 90 00 01           3192 	mov	dptr,#0x0001
   0E11 12 0D 4C           3193 	lcall	_DELAY_ms
                           3194 ;	D:\Workspace\MIDE\firmware\/keypad.c:131: M_ROW=0x0F;           // Pull the ROW lines to low and Column lines high.
                           3195 ;	D:\Workspace\MIDE\firmware\/keypad.c:132: key=M_COL & 0x0F;     // Read the Columns, to check the key press
   0E14 74 0F              3196 	mov	a,#0x0F
   0E16 F5 A0              3197 	mov	_P2,a
   0E18 55 A0              3198 	anl	a,_P2
   0E1A FA                 3199 	mov	r2,a
                           3200 ;	D:\Workspace\MIDE\firmware\/keypad.c:133: }while(key!=0x0F);   // Wait till the Key is released,
   0E1B BA 0F E6           3201 	cjne	r2,#0x0F,00101$
   0E1E 22                 3202 	ret
                           3203 ;------------------------------------------------------------
                           3204 ;Allocation info for local variables in function 'KEYPAD_WaitForKeyPress'
                           3205 ;------------------------------------------------------------
                           3206 ;var_keyPress_u8           Allocated to registers r2 
                           3207 ;------------------------------------------------------------
                           3208 ;	D:\Workspace\MIDE\firmware\/keypad.c:151: void KEYPAD_WaitForKeyPress()
                           3209 ;	-----------------------------------------
                           3210 ;	 function KEYPAD_WaitForKeyPress
                           3211 ;	-----------------------------------------
   0E1F                    3212 _KEYPAD_WaitForKeyPress:
                           3213 ;	D:\Workspace\MIDE\firmware\/keypad.c:156: do
   0E1F                    3214 00101$:
                           3215 ;	D:\Workspace\MIDE\firmware\/keypad.c:158: M_ROW=0x0F;		  // Pull the ROW lines to low and Column lines high.
                           3216 ;	D:\Workspace\MIDE\firmware\/keypad.c:159: var_keyPress_u8=M_COL & 0x0F;	  // Read the Columns, to check the key press
   0E1F 74 0F              3217 	mov	a,#0x0F
   0E21 F5 A0              3218 	mov	_P2,a
   0E23 55 A0              3219 	anl	a,_P2
   0E25 FA                 3220 	mov	r2,a
                           3221 ;	D:\Workspace\MIDE\firmware\/keypad.c:160: }while(var_keyPress_u8==0x0F); // Wait till the Key is pressed,
   0E26 BA 0F 02           3222 	cjne	r2,#0x0F,00111$
   0E29 80 F4              3223 	sjmp	00101$
   0E2B                    3224 00111$:
                           3225 ;	D:\Workspace\MIDE\firmware\/keypad.c:163: DELAY_ms(1);		  // Wait for some time(debounce Time);
   0E2B 90 00 01           3226 	mov	dptr,#0x0001
   0E2E 12 0D 4C           3227 	lcall	_DELAY_ms
                           3228 ;	D:\Workspace\MIDE\firmware\/keypad.c:165: M_ROW=0x0F;		  // After debounce time, perform the above operation
                           3229 ;	D:\Workspace\MIDE\firmware\/keypad.c:166: var_keyPress_u8=M_COL & 0x0F;	  // to ensure the Key press.
   0E31 74 0F              3230 	mov	a,#0x0F
   0E33 F5 A0              3231 	mov	_P2,a
   0E35 55 A0              3232 	anl	a,_P2
   0E37 FA                 3233 	mov	r2,a
                           3234 ;	D:\Workspace\MIDE\firmware\/keypad.c:168: }while(var_keyPress_u8==0x0F);
   0E38 BA 0F 02           3235 	cjne	r2,#0x0F,00112$
   0E3B 80 E2              3236 	sjmp	00101$
   0E3D                    3237 00112$:
   0E3D 22                 3238 	ret
                           3239 ;------------------------------------------------------------
                           3240 ;Allocation info for local variables in function 'KEYPAD_GetKey'
                           3241 ;------------------------------------------------------------
                           3242 ;var_keyPress_u8           Allocated to registers r2 
                           3243 ;------------------------------------------------------------
                           3244 ;	D:\Workspace\MIDE\firmware\/keypad.c:194: uint8_t KEYPAD_GetKey()
                           3245 ;	-----------------------------------------
                           3246 ;	 function KEYPAD_GetKey
                           3247 ;	-----------------------------------------
   0E3E                    3248 _KEYPAD_GetKey:
                           3249 ;	D:\Workspace\MIDE\firmware\/keypad.c:198: KEYPAD_WaitForKeyRelease();    // Wait for the previous key release
   0E3E 12 0E 04           3250 	lcall	_KEYPAD_WaitForKeyRelease
                           3251 ;	D:\Workspace\MIDE\firmware\/keypad.c:199: DELAY_ms(1);
   0E41 90 00 01           3252 	mov	dptr,#0x0001
   0E44 12 0D 4C           3253 	lcall	_DELAY_ms
                           3254 ;	D:\Workspace\MIDE\firmware\/keypad.c:201: KEYPAD_WaitForKeyPress();      // Wait for the new key press
   0E47 12 0E 1F           3255 	lcall	_KEYPAD_WaitForKeyPress
                           3256 ;	D:\Workspace\MIDE\firmware\/keypad.c:202: var_keyPress_u8 = keypad_ScanKey();        // Scan for the key pressed.
   0E4A 12 0E E8           3257 	lcall	_keypad_ScanKey
   0E4D AA 82              3258 	mov	r2,dpl
                           3259 ;	D:\Workspace\MIDE\firmware\/keypad.c:204: switch(var_keyPress_u8)                       // Decode the key
   0E4F BA 77 03           3260 	cjne	r2,#0x77,00137$
   0E52 02 0E D3           3261 	ljmp	00113$
   0E55                    3262 00137$:
   0E55 BA 7B 03           3263 	cjne	r2,#0x7B,00138$
   0E58 02 0E D7           3264 	ljmp	00114$
   0E5B                    3265 00138$:
   0E5B BA 7D 03           3266 	cjne	r2,#0x7D,00139$
   0E5E 02 0E DB           3267 	ljmp	00115$
   0E61                    3268 00139$:
   0E61 BA 7E 03           3269 	cjne	r2,#0x7E,00140$
   0E64 02 0E DF           3270 	ljmp	00116$
   0E67                    3271 00140$:
   0E67 BA B7 02           3272 	cjne	r2,#0xB7,00141$
   0E6A 80 57              3273 	sjmp	00109$
   0E6C                    3274 00141$:
   0E6C BA BB 02           3275 	cjne	r2,#0xBB,00142$
   0E6F 80 56              3276 	sjmp	00110$
   0E71                    3277 00142$:
   0E71 BA BD 02           3278 	cjne	r2,#0xBD,00143$
   0E74 80 55              3279 	sjmp	00111$
   0E76                    3280 00143$:
   0E76 BA BE 02           3281 	cjne	r2,#0xBE,00144$
   0E79 80 54              3282 	sjmp	00112$
   0E7B                    3283 00144$:
   0E7B BA D7 02           3284 	cjne	r2,#0xD7,00145$
   0E7E 80 33              3285 	sjmp	00105$
   0E80                    3286 00145$:
   0E80 BA DB 02           3287 	cjne	r2,#0xDB,00146$
   0E83 80 32              3288 	sjmp	00106$
   0E85                    3289 00146$:
   0E85 BA DD 02           3290 	cjne	r2,#0xDD,00147$
   0E88 80 31              3291 	sjmp	00107$
   0E8A                    3292 00147$:
   0E8A BA DE 02           3293 	cjne	r2,#0xDE,00148$
   0E8D 80 30              3294 	sjmp	00108$
   0E8F                    3295 00148$:
   0E8F BA E7 02           3296 	cjne	r2,#0xE7,00149$
   0E92 80 0F              3297 	sjmp	00101$
   0E94                    3298 00149$:
   0E94 BA EB 02           3299 	cjne	r2,#0xEB,00150$
   0E97 80 0E              3300 	sjmp	00102$
   0E99                    3301 00150$:
   0E99 BA ED 02           3302 	cjne	r2,#0xED,00151$
   0E9C 80 0D              3303 	sjmp	00103$
   0E9E                    3304 00151$:
                           3305 ;	D:\Workspace\MIDE\firmware\/keypad.c:206: case 0xe7: var_keyPress_u8='0'; break;
   0E9E BA EE 42           3306 	cjne	r2,#0xEE,00117$
   0EA1 80 0C              3307 	sjmp	00104$
   0EA3                    3308 00101$:
   0EA3 7A 30              3309 	mov	r2,#0x30
                           3310 ;	D:\Workspace\MIDE\firmware\/keypad.c:207: case 0xeb: var_keyPress_u8='1'; break;
   0EA5 80 3E              3311 	sjmp	00118$
   0EA7                    3312 00102$:
   0EA7 7A 31              3313 	mov	r2,#0x31
                           3314 ;	D:\Workspace\MIDE\firmware\/keypad.c:208: case 0xed: var_keyPress_u8='2'; break;
   0EA9 80 3A              3315 	sjmp	00118$
   0EAB                    3316 00103$:
   0EAB 7A 32              3317 	mov	r2,#0x32
                           3318 ;	D:\Workspace\MIDE\firmware\/keypad.c:209: case 0xee: var_keyPress_u8='3'; break;
   0EAD 80 36              3319 	sjmp	00118$
   0EAF                    3320 00104$:
   0EAF 7A 33              3321 	mov	r2,#0x33
                           3322 ;	D:\Workspace\MIDE\firmware\/keypad.c:210: case 0xd7: var_keyPress_u8='4'; break;
   0EB1 80 32              3323 	sjmp	00118$
   0EB3                    3324 00105$:
   0EB3 7A 34              3325 	mov	r2,#0x34
                           3326 ;	D:\Workspace\MIDE\firmware\/keypad.c:211: case 0xdb: var_keyPress_u8='5'; break;
   0EB5 80 2E              3327 	sjmp	00118$
   0EB7                    3328 00106$:
   0EB7 7A 35              3329 	mov	r2,#0x35
                           3330 ;	D:\Workspace\MIDE\firmware\/keypad.c:212: case 0xdd: var_keyPress_u8='6'; break;
   0EB9 80 2A              3331 	sjmp	00118$
   0EBB                    3332 00107$:
   0EBB 7A 36              3333 	mov	r2,#0x36
                           3334 ;	D:\Workspace\MIDE\firmware\/keypad.c:213: case 0xde: var_keyPress_u8='7'; break;
   0EBD 80 26              3335 	sjmp	00118$
   0EBF                    3336 00108$:
   0EBF 7A 37              3337 	mov	r2,#0x37
                           3338 ;	D:\Workspace\MIDE\firmware\/keypad.c:214: case 0xb7: var_keyPress_u8='8'; break;
   0EC1 80 22              3339 	sjmp	00118$
   0EC3                    3340 00109$:
   0EC3 7A 38              3341 	mov	r2,#0x38
                           3342 ;	D:\Workspace\MIDE\firmware\/keypad.c:215: case 0xbb: var_keyPress_u8='9'; break;
   0EC5 80 1E              3343 	sjmp	00118$
   0EC7                    3344 00110$:
   0EC7 7A 39              3345 	mov	r2,#0x39
                           3346 ;	D:\Workspace\MIDE\firmware\/keypad.c:216: case 0xbd: var_keyPress_u8='A'; break;
   0EC9 80 1A              3347 	sjmp	00118$
   0ECB                    3348 00111$:
   0ECB 7A 41              3349 	mov	r2,#0x41
                           3350 ;	D:\Workspace\MIDE\firmware\/keypad.c:217: case 0xbe: var_keyPress_u8='B'; break;
   0ECD 80 16              3351 	sjmp	00118$
   0ECF                    3352 00112$:
   0ECF 7A 42              3353 	mov	r2,#0x42
                           3354 ;	D:\Workspace\MIDE\firmware\/keypad.c:218: case 0x77: var_keyPress_u8='C'; break;
   0ED1 80 12              3355 	sjmp	00118$
   0ED3                    3356 00113$:
   0ED3 7A 43              3357 	mov	r2,#0x43
                           3358 ;	D:\Workspace\MIDE\firmware\/keypad.c:219: case 0x7b: var_keyPress_u8='D'; break;
   0ED5 80 0E              3359 	sjmp	00118$
   0ED7                    3360 00114$:
   0ED7 7A 44              3361 	mov	r2,#0x44
                           3362 ;	D:\Workspace\MIDE\firmware\/keypad.c:220: case 0x7d: var_keyPress_u8='E'; break;
   0ED9 80 0A              3363 	sjmp	00118$
   0EDB                    3364 00115$:
   0EDB 7A 45              3365 	mov	r2,#0x45
                           3366 ;	D:\Workspace\MIDE\firmware\/keypad.c:221: case 0x7e: var_keyPress_u8='F'; break;
   0EDD 80 06              3367 	sjmp	00118$
   0EDF                    3368 00116$:
   0EDF 7A 46              3369 	mov	r2,#0x46
                           3370 ;	D:\Workspace\MIDE\firmware\/keypad.c:222: default  : var_keyPress_u8='z'; break;
   0EE1 80 02              3371 	sjmp	00118$
   0EE3                    3372 00117$:
   0EE3 7A 7A              3373 	mov	r2,#0x7A
                           3374 ;	D:\Workspace\MIDE\firmware\/keypad.c:223: }
   0EE5                    3375 00118$:
                           3376 ;	D:\Workspace\MIDE\firmware\/keypad.c:224: return(var_keyPress_u8);                      // Return the key
   0EE5 8A 82              3377 	mov	dpl,r2
   0EE7 22                 3378 	ret
                           3379 ;------------------------------------------------------------
                           3380 ;Allocation info for local variables in function 'keypad_ScanKey'
                           3381 ;------------------------------------------------------------
                           3382 ;var_keyScanCode_u8        Allocated to registers r2 
                           3383 ;i                         Allocated to registers r3 
                           3384 ;var_keyPress_u8           Allocated to stack - offset 1
                           3385 ;------------------------------------------------------------
                           3386 ;	D:\Workspace\MIDE\firmware\/keypad.c:246: static uint8_t keypad_ScanKey()
                           3387 ;	-----------------------------------------
                           3388 ;	 function keypad_ScanKey
                           3389 ;	-----------------------------------------
   0EE8                    3390 _keypad_ScanKey:
   0EE8 C0 13              3391 	push	_bp
   0EEA 85 81 13           3392 	mov	_bp,sp
   0EED 05 81              3393 	inc	sp
                           3394 ;	D:\Workspace\MIDE\firmware\/keypad.c:249: uint8_t var_keyScanCode_u8 = 0xEF,i, var_keyPress_u8;
   0EEF 7A EF              3395 	mov	r2,#0xEF
                           3396 ;	D:\Workspace\MIDE\firmware\/keypad.c:251: for(i=0;i<0x04;i++)                // Scan All the 4-Rows for key press
   0EF1 7B 00              3397 	mov	r3,#0x00
   0EF3                    3398 00103$:
   0EF3 BB 04 00           3399 	cjne	r3,#0x04,00113$
   0EF6                    3400 00113$:
   0EF6 50 20              3401 	jnc	00106$
                           3402 ;	D:\Workspace\MIDE\firmware\/keypad.c:253: M_ROW=var_keyScanCode_u8;        // Select 1-Row at a time for Scanning the Key
   0EF8 8A A0              3403 	mov	_P2,r2
                           3404 ;	D:\Workspace\MIDE\firmware\/keypad.c:254: DELAY_ms(1);
   0EFA 90 00 01           3405 	mov	dptr,#0x0001
   0EFD C0 02              3406 	push	ar2
   0EFF C0 03              3407 	push	ar3
   0F01 12 0D 4C           3408 	lcall	_DELAY_ms
   0F04 D0 03              3409 	pop	ar3
   0F06 D0 02              3410 	pop	ar2
                           3411 ;	D:\Workspace\MIDE\firmware\/keypad.c:255: var_keyPress_u8=M_COL & 0x0F;    // Read the Column, for key press
   0F08 74 0F              3412 	mov	a,#0x0F
   0F0A 55 A0              3413 	anl	a,_P2
   0F0C FD                 3414 	mov	r5,a
                           3415 ;	D:\Workspace\MIDE\firmware\/keypad.c:257: if(var_keyPress_u8!=0x0F)        // If the KEY press is detected for the selected
   0F0D BD 0F 08           3416 	cjne	r5,#0x0F,00106$
                           3417 ;	D:\Workspace\MIDE\firmware\/keypad.c:260: var_keyScanCode_u8=((var_keyScanCode_u8<<1)+0x01); // Rotate the ScanKey to SCAN the remaining Rows
   0F10 EA                 3418 	mov	a,r2
   0F11 2A                 3419 	add	a,r2
   0F12 FC                 3420 	mov	r4,a
   0F13 04                 3421 	inc	a
   0F14 FA                 3422 	mov	r2,a
                           3423 ;	D:\Workspace\MIDE\firmware\/keypad.c:251: for(i=0;i<0x04;i++)                // Scan All the 4-Rows for key press
   0F15 0B                 3424 	inc	r3
   0F16 80 DB              3425 	sjmp	00103$
   0F18                    3426 00106$:
                           3427 ;	D:\Workspace\MIDE\firmware\/keypad.c:262: var_keyPress_u8 = var_keyPress_u8 + (var_keyScanCode_u8 & 0xf0); // Return the row and COL status to decode the key
   0F18 53 02 F0           3428 	anl	ar2,#0xF0
   0F1B EA                 3429 	mov	a,r2
   0F1C 2D                 3430 	add	a,r5
                           3431 ;	D:\Workspace\MIDE\firmware\/keypad.c:263: return(var_keyPress_u8);
   0F1D F5 82              3432 	mov	dpl,a
   0F1F 85 13 81           3433 	mov	sp,_bp
   0F22 D0 13              3434 	pop	_bp
   0F24 22                 3435 	ret
                           3436 ;------------------------------------------------------------
                           3437 ;Allocation info for local variables in function 'EEPROM_WriteByte'
                           3438 ;------------------------------------------------------------
                           3439 ;var_eepromData_u8         Allocated to stack - offset -3
                           3440 ;var_eepromAddress_u16     Allocated to registers r2 r3 
                           3441 ;var_eepromLowerAddress_u8 Allocated to registers r4 
                           3442 ;var_eepromHigherAddress_u8 Allocated to registers r2 
                           3443 ;var_eepromPageNumber_u8   Allocated to stack - offset 5
                           3444 ;var_eepromId_u8           Allocated to registers 
                           3445 ;------------------------------------------------------------
                           3446 ;	D:\Workspace\MIDE\firmware\/eeprom.c:94: void EEPROM_WriteByte(uint16_t var_eepromAddress_u16, uint8_t var_eepromData_u8)
                           3447 ;	-----------------------------------------
                           3448 ;	 function EEPROM_WriteByte
                           3449 ;	-----------------------------------------
   0F25                    3450 _EEPROM_WriteByte:
   0F25 C0 13              3451 	push	_bp
   0F27 85 81 13           3452 	mov	_bp,sp
   0F2A AA 82              3453 	mov	r2,dpl
   0F2C AB 83              3454 	mov	r3,dph
                           3455 ;	D:\Workspace\MIDE\firmware\/eeprom.c:102: if(var_eepromAddress_u16 < C_MaxEepromSize_U16)	
   0F2E 74 F0              3456 	mov	a,#0x100 - 0x10
   0F30 2B                 3457 	add	a,r3
   0F31 40 36              3458 	jc	00103$
                           3459 ;	D:\Workspace\MIDE\firmware\/eeprom.c:104: var_eepromLowerAddress_u8 = util_ExtractByte0to8(var_eepromAddress_u16);
   0F33 8A 04              3460 	mov	ar4,r2
                           3461 ;	D:\Workspace\MIDE\firmware\/eeprom.c:110: var_eepromHigherAddress_u8 = util_ExtractByte8to16(var_eepromAddress_u16);
   0F35 8B 02              3462 	mov	ar2,r3
                           3463 ;	D:\Workspace\MIDE\firmware\/eeprom.c:113: I2C_Start();                       // Start i2c communication
   0F37 C0 02              3464 	push	ar2
   0F39 C0 04              3465 	push	ar4
   0F3B 12 09 FE           3466 	lcall	_I2C_Start
                           3467 ;	D:\Workspace\MIDE\firmware\/eeprom.c:115: I2C_Write(var_eepromId_u8); 
   0F3E 75 82 A0           3468 	mov	dpl,#0xA0
   0F41 12 0A 3F           3469 	lcall	_I2C_Write
   0F44 D0 04              3470 	pop	ar4
   0F46 D0 02              3471 	pop	ar2
                           3472 ;	D:\Workspace\MIDE\firmware\/eeprom.c:117: I2C_Write(var_eepromHigherAddress_u8);
   0F48 8A 82              3473 	mov	dpl,r2
   0F4A C0 04              3474 	push	ar4
   0F4C 12 0A 3F           3475 	lcall	_I2C_Write
   0F4F D0 04              3476 	pop	ar4
                           3477 ;	D:\Workspace\MIDE\firmware\/eeprom.c:119: I2C_Write(var_eepromLowerAddress_u8); // Select the Specified EEPROM address of At24xx
   0F51 8C 82              3478 	mov	dpl,r4
   0F53 12 0A 3F           3479 	lcall	_I2C_Write
                           3480 ;	D:\Workspace\MIDE\firmware\/eeprom.c:120: I2C_Write(var_eepromData_u8);         // Write the data at specified address
   0F56 E5 13              3481 	mov	a,_bp
   0F58 24 FD              3482 	add	a,#0xfd
   0F5A F8                 3483 	mov	r0,a
   0F5B 86 82              3484 	mov	dpl,@r0
   0F5D 12 0A 3F           3485 	lcall	_I2C_Write
                           3486 ;	D:\Workspace\MIDE\firmware\/eeprom.c:121: I2C_Stop();                           // Stop i2c communication after Writing the data
   0F60 12 0A 20           3487 	lcall	_I2C_Stop
                           3488 ;	D:\Workspace\MIDE\firmware\/eeprom.c:123: DELAY_ms(10);                         // Write operation takes max 5ms, refer At24xx data sheet 
   0F63 90 00 0A           3489 	mov	dptr,#0x000A
   0F66 12 0D 4C           3490 	lcall	_DELAY_ms
   0F69                    3491 00103$:
   0F69 D0 13              3492 	pop	_bp
   0F6B 22                 3493 	ret
                           3494 ;------------------------------------------------------------
                           3495 ;Allocation info for local variables in function 'EEPROM_ReadByte'
                           3496 ;------------------------------------------------------------
                           3497 ;var_eepromAddress_u16     Allocated to registers r2 r3 
                           3498 ;var_eepromLowerAddress_u8 Allocated to registers r5 
                           3499 ;var_eepromHigherAddress_u8 Allocated to registers r2 
                           3500 ;var_eepromPageNumber_u8   Allocated to stack - offset 5
                           3501 ;var_eepromData_u8         Allocated to registers r4 
                           3502 ;var_eepromId_u8           Allocated to registers 
                           3503 ;------------------------------------------------------------
                           3504 ;	D:\Workspace\MIDE\firmware\/eeprom.c:179: uint8_t EEPROM_ReadByte(uint16_t var_eepromAddress_u16)
                           3505 ;	-----------------------------------------
                           3506 ;	 function EEPROM_ReadByte
                           3507 ;	-----------------------------------------
   0F6C                    3508 _EEPROM_ReadByte:
   0F6C AA 82              3509 	mov	r2,dpl
   0F6E AB 83              3510 	mov	r3,dph
                           3511 ;	D:\Workspace\MIDE\firmware\/eeprom.c:184: uint8_t var_eepromData_u8 = 0x00;
   0F70 7C 00              3512 	mov	r4,#0x00
                           3513 ;	D:\Workspace\MIDE\firmware\/eeprom.c:187: if(var_eepromAddress_u16 < C_MaxEepromSize_U16)	
   0F72 74 F0              3514 	mov	a,#0x100 - 0x10
   0F74 2B                 3515 	add	a,r3
   0F75 40 43              3516 	jc	00102$
                           3517 ;	D:\Workspace\MIDE\firmware\/eeprom.c:189: var_eepromLowerAddress_u8 = util_ExtractByte0to8(var_eepromAddress_u16);
   0F77 8A 05              3518 	mov	ar5,r2
                           3519 ;	D:\Workspace\MIDE\firmware\/eeprom.c:195: var_eepromHigherAddress_u8 = util_ExtractByte8to16(var_eepromAddress_u16);
   0F79 8B 02              3520 	mov	ar2,r3
                           3521 ;	D:\Workspace\MIDE\firmware\/eeprom.c:198: I2C_Start();                       // Start i2c communication
   0F7B C0 02              3522 	push	ar2
   0F7D C0 05              3523 	push	ar5
   0F7F 12 09 FE           3524 	lcall	_I2C_Start
                           3525 ;	D:\Workspace\MIDE\firmware\/eeprom.c:200: I2C_Write(var_eepromId_u8); 
   0F82 75 82 A0           3526 	mov	dpl,#0xA0
   0F85 12 0A 3F           3527 	lcall	_I2C_Write
   0F88 D0 05              3528 	pop	ar5
   0F8A D0 02              3529 	pop	ar2
                           3530 ;	D:\Workspace\MIDE\firmware\/eeprom.c:202: I2C_Write(var_eepromHigherAddress_u8);
   0F8C 8A 82              3531 	mov	dpl,r2
   0F8E C0 05              3532 	push	ar5
   0F90 12 0A 3F           3533 	lcall	_I2C_Write
   0F93 D0 05              3534 	pop	ar5
                           3535 ;	D:\Workspace\MIDE\firmware\/eeprom.c:204: I2C_Write(var_eepromLowerAddress_u8); // Select the Specified EEPROM address of At24xx
   0F95 8D 82              3536 	mov	dpl,r5
   0F97 12 0A 3F           3537 	lcall	_I2C_Write
                           3538 ;	D:\Workspace\MIDE\firmware\/eeprom.c:206: I2C_Start();                          // Start i2c communication after selecting the address
   0F9A 12 09 FE           3539 	lcall	_I2C_Start
                           3540 ;	D:\Workspace\MIDE\firmware\/eeprom.c:207: I2C_Write(var_eepromId_u8 | 0x01);    // connect to At24xx(read) by sending its ID on I2c Bus
   0F9D 75 82 A1           3541 	mov	dpl,#0xA1
   0FA0 12 0A 3F           3542 	lcall	_I2C_Write
                           3543 ;	D:\Workspace\MIDE\firmware\/eeprom.c:208: var_eepromData_u8 = I2C_Read(0);      // Read the data from specified address
   0FA3 75 82 00           3544 	mov	dpl,#0x00
   0FA6 12 0A 6B           3545 	lcall	_I2C_Read
   0FA9 AA 82              3546 	mov	r2,dpl
   0FAB 8A 04              3547 	mov	ar4,r2
                           3548 ;	D:\Workspace\MIDE\firmware\/eeprom.c:209: I2C_Stop();                           // Stop i2c communication after Reading the data
   0FAD C0 04              3549 	push	ar4
   0FAF 12 0A 20           3550 	lcall	_I2C_Stop
                           3551 ;	D:\Workspace\MIDE\firmware\/eeprom.c:210: DELAY_us(10);
   0FB2 90 00 0A           3552 	mov	dptr,#0x000A
   0FB5 12 0D 3C           3553 	lcall	_DELAY_us
   0FB8 D0 04              3554 	pop	ar4
   0FBA                    3555 00102$:
                           3556 ;	D:\Workspace\MIDE\firmware\/eeprom.c:213: return var_eepromData_u8;             // Return the data read from eeprom
   0FBA 8C 82              3557 	mov	dpl,r4
   0FBC 22                 3558 	ret
                           3559 ;------------------------------------------------------------
                           3560 ;Allocation info for local variables in function 'EEPROM_WriteString'
                           3561 ;------------------------------------------------------------
                           3562 ;ptr_stringPointer_u8      Allocated to stack - offset -5
                           3563 ;var_eepromAddress_u16     Allocated to registers r2 r3 
                           3564 ;sloc0                     Allocated to stack - offset 1
                           3565 ;------------------------------------------------------------
                           3566 ;	D:\Workspace\MIDE\firmware\/eeprom.c:297: void EEPROM_WriteString(uint16_t var_eepromAddress_u16, char *ptr_stringPointer_u8)
                           3567 ;	-----------------------------------------
                           3568 ;	 function EEPROM_WriteString
                           3569 ;	-----------------------------------------
   0FBD                    3570 _EEPROM_WriteString:
   0FBD C0 13              3571 	push	_bp
   0FBF 85 81 13           3572 	mov	_bp,sp
   0FC2 05 81              3573 	inc	sp
   0FC4 05 81              3574 	inc	sp
   0FC6 AA 82              3575 	mov	r2,dpl
   0FC8 AB 83              3576 	mov	r3,dph
                           3577 ;	D:\Workspace\MIDE\firmware\/eeprom.c:300: do
   0FCA E5 13              3578 	mov	a,_bp
   0FCC 24 FB              3579 	add	a,#0xfb
   0FCE F8                 3580 	mov	r0,a
   0FCF 86 04              3581 	mov	ar4,@r0
   0FD1 08                 3582 	inc	r0
   0FD2 86 05              3583 	mov	ar5,@r0
   0FD4 08                 3584 	inc	r0
   0FD5 86 06              3585 	mov	ar6,@r0
   0FD7 A8 13              3586 	mov	r0,_bp
   0FD9 08                 3587 	inc	r0
   0FDA A6 02              3588 	mov	@r0,ar2
   0FDC 08                 3589 	inc	r0
   0FDD A6 03              3590 	mov	@r0,ar3
   0FDF                    3591 00101$:
                           3592 ;	D:\Workspace\MIDE\firmware\/eeprom.c:302: EEPROM_WriteByte(var_eepromAddress_u16,*ptr_stringPointer_u8); //Write a byte from RAM to EEPROM
   0FDF 8C 82              3593 	mov	dpl,r4
   0FE1 8D 83              3594 	mov	dph,r5
   0FE3 8E F0              3595 	mov	b,r6
   0FE5 12 15 C3           3596 	lcall	__gptrget
   0FE8 FF                 3597 	mov	r7,a
   0FE9 A3                 3598 	inc	dptr
   0FEA AC 82              3599 	mov	r4,dpl
   0FEC AD 83              3600 	mov	r5,dph
   0FEE C0 04              3601 	push	ar4
   0FF0 C0 05              3602 	push	ar5
   0FF2 C0 06              3603 	push	ar6
   0FF4 C0 07              3604 	push	ar7
   0FF6 A8 13              3605 	mov	r0,_bp
   0FF8 08                 3606 	inc	r0
   0FF9 86 82              3607 	mov	dpl,@r0
   0FFB 08                 3608 	inc	r0
   0FFC 86 83              3609 	mov	dph,@r0
   0FFE 12 0F 25           3610 	lcall	_EEPROM_WriteByte
   1001 15 81              3611 	dec	sp
   1003 D0 06              3612 	pop	ar6
   1005 D0 05              3613 	pop	ar5
   1007 D0 04              3614 	pop	ar4
                           3615 ;	D:\Workspace\MIDE\firmware\/eeprom.c:303: ptr_stringPointer_u8++;								//Increment the RAM Address
                           3616 ;	D:\Workspace\MIDE\firmware\/eeprom.c:304: var_eepromAddress_u16++;								//Increment the Eeprom Address
   1009 A8 13              3617 	mov	r0,_bp
   100B 08                 3618 	inc	r0
   100C 06                 3619 	inc	@r0
   100D B6 00 02           3620 	cjne	@r0,#0x00,00108$
   1010 08                 3621 	inc	r0
   1011 06                 3622 	inc	@r0
   1012                    3623 00108$:
                           3624 ;	D:\Workspace\MIDE\firmware\/eeprom.c:305: }while(*(ptr_stringPointer_u8-1) !=0);
   1012 EC                 3625 	mov	a,r4
   1013 24 FF              3626 	add	a,#0xff
   1015 FF                 3627 	mov	r7,a
   1016 ED                 3628 	mov	a,r5
   1017 34 FF              3629 	addc	a,#0xff
   1019 FA                 3630 	mov	r2,a
   101A 8E 03              3631 	mov	ar3,r6
   101C 8F 82              3632 	mov	dpl,r7
   101E 8A 83              3633 	mov	dph,r2
   1020 8B F0              3634 	mov	b,r3
   1022 12 15 C3           3635 	lcall	__gptrget
   1025 70 B8              3636 	jnz	00101$
   1027 85 13 81           3637 	mov	sp,_bp
   102A D0 13              3638 	pop	_bp
   102C 22                 3639 	ret
                           3640 ;------------------------------------------------------------
                           3641 ;Allocation info for local variables in function 'EEPROM_ReadString'
                           3642 ;------------------------------------------------------------
                           3643 ;ptr_destStringAddress_u8  Allocated to stack - offset -5
                           3644 ;var_eepromAddress_u16     Allocated to registers r2 r3 
                           3645 ;eeprom_data               Allocated to registers r7 
                           3646 ;------------------------------------------------------------
                           3647 ;	D:\Workspace\MIDE\firmware\/eeprom.c:324: void EEPROM_ReadString(uint16_t var_eepromAddress_u16, char *ptr_destStringAddress_u8)
                           3648 ;	-----------------------------------------
                           3649 ;	 function EEPROM_ReadString
                           3650 ;	-----------------------------------------
   102D                    3651 _EEPROM_ReadString:
   102D C0 13              3652 	push	_bp
   102F 85 81 13           3653 	mov	_bp,sp
   1032 AA 82              3654 	mov	r2,dpl
   1034 AB 83              3655 	mov	r3,dph
                           3656 ;	D:\Workspace\MIDE\firmware\/eeprom.c:328: do
   1036 E5 13              3657 	mov	a,_bp
   1038 24 FB              3658 	add	a,#0xfb
   103A F8                 3659 	mov	r0,a
   103B 86 04              3660 	mov	ar4,@r0
   103D 08                 3661 	inc	r0
   103E 86 05              3662 	mov	ar5,@r0
   1040 08                 3663 	inc	r0
   1041 86 06              3664 	mov	ar6,@r0
   1043                    3665 00101$:
                           3666 ;	D:\Workspace\MIDE\firmware\/eeprom.c:330: eeprom_data = EEPROM_ReadByte(var_eepromAddress_u16); //Read a byte from EEPROM to RAM
   1043 8A 82              3667 	mov	dpl,r2
   1045 8B 83              3668 	mov	dph,r3
   1047 C0 02              3669 	push	ar2
   1049 C0 03              3670 	push	ar3
   104B C0 04              3671 	push	ar4
   104D C0 05              3672 	push	ar5
   104F C0 06              3673 	push	ar6
   1051 12 0F 6C           3674 	lcall	_EEPROM_ReadByte
   1054 AF 82              3675 	mov	r7,dpl
   1056 D0 06              3676 	pop	ar6
   1058 D0 05              3677 	pop	ar5
   105A D0 04              3678 	pop	ar4
   105C D0 03              3679 	pop	ar3
   105E D0 02              3680 	pop	ar2
                           3681 ;	D:\Workspace\MIDE\firmware\/eeprom.c:331: *ptr_destStringAddress_u8 = eeprom_data;			 //Copy the data into String Buffer
   1060 8C 82              3682 	mov	dpl,r4
   1062 8D 83              3683 	mov	dph,r5
   1064 8E F0              3684 	mov	b,r6
   1066 EF                 3685 	mov	a,r7
   1067 12 15 3D           3686 	lcall	__gptrput
   106A A3                 3687 	inc	dptr
   106B AC 82              3688 	mov	r4,dpl
   106D AD 83              3689 	mov	r5,dph
                           3690 ;	D:\Workspace\MIDE\firmware\/eeprom.c:332: ptr_destStringAddress_u8++;						 //Increment the RAM Address
                           3691 ;	D:\Workspace\MIDE\firmware\/eeprom.c:333: var_eepromAddress_u16++;							 //Increment the Eeprom Address
   106F 0A                 3692 	inc	r2
   1070 BA 00 01           3693 	cjne	r2,#0x00,00108$
   1073 0B                 3694 	inc	r3
   1074                    3695 00108$:
                           3696 ;	D:\Workspace\MIDE\firmware\/eeprom.c:334: }while(eeprom_data!=0);
   1074 EF                 3697 	mov	a,r7
   1075 70 CC              3698 	jnz	00101$
   1077 D0 13              3699 	pop	_bp
   1079 22                 3700 	ret
                           3701 ;------------------------------------------------------------
                           3702 ;Allocation info for local variables in function 'main'
                           3703 ;------------------------------------------------------------
                           3704 ;------------------------------------------------------------
                           3705 ;	D:\Workspace\MIDE\firmware\main.c:50: void main() 
                           3706 ;	-----------------------------------------
                           3707 ;	 function main
                           3708 ;	-----------------------------------------
   107A                    3709 _main:
                           3710 ;	D:\Workspace\MIDE\firmware\main.c:52: UART_Init(9600);
   107A 90 25 80           3711 	mov	dptr,#0x2580
   107D E4                 3712 	clr	a
   107E F5 F0              3713 	mov	b,a
   1080 12 00 73           3714 	lcall	_UART_Init
                           3715 ;	D:\Workspace\MIDE\firmware\main.c:53: UART_TxString("\n\rTest menu Utra x51 v1.1\r\n 1:GPIO Blink\r\n 2:LCD \n\r 3:7-Segment\n\r 4:RTC\n\r 5:EEPROM\n\r 6:ADC\n\r 7:Keypad \n\r Enter option:");
   1083 90 16 53           3716 	mov	dptr,#__str_0
   1086 75 F0 80           3717 	mov	b,#0x80
   1089 12 01 08           3718 	lcall	_UART_TxString
                           3719 ;	D:\Workspace\MIDE\firmware\main.c:54: UART_TxString("\n\rReset the board after test is done");
   108C 90 16 CA           3720 	mov	dptr,#__str_1
   108F 75 F0 80           3721 	mov	b,#0x80
   1092 12 01 08           3722 	lcall	_UART_TxString
                           3723 ;	D:\Workspace\MIDE\firmware\main.c:55: mm_option = UART_RxChar();
   1095 12 00 F6           3724 	lcall	_UART_RxChar
   1098 85 82 12           3725 	mov	_mm_option,dpl
                           3726 ;	D:\Workspace\MIDE\firmware\main.c:56: while(1)
   109B                    3727 00111$:
                           3728 ;	D:\Workspace\MIDE\firmware\main.c:58: switch(mm_option)
   109B C3                 3729 	clr	c
   109C E5 12              3730 	mov	a,_mm_option
   109E 64 80              3731 	xrl	a,#0x80
   10A0 94 B1              3732 	subb	a,#0xb1
   10A2 40 F7              3733 	jc	00111$
   10A4 74 B7              3734 	mov	a,#(0x37 ^ 0x80)
   10A6 85 12 F0           3735 	mov	b,_mm_option
   10A9 63 F0 80           3736 	xrl	b,#0x80
   10AC 95 F0              3737 	subb	a,b
   10AE 40 EB              3738 	jc	00111$
   10B0 E5 12              3739 	mov	a,_mm_option
   10B2 24 CF              3740 	add	a,#0xcf
   10B4 FA                 3741 	mov	r2,a
   10B5 25 E0              3742 	add	a,acc
   10B7 2A                 3743 	add	a,r2
   10B8 90 10 BC           3744 	mov	dptr,#00120$
   10BB 73                 3745 	jmp	@a+dptr
   10BC                    3746 00120$:
   10BC 02 10 D1           3747 	ljmp	00101$
   10BF 02 10 D6           3748 	ljmp	00102$
   10C2 02 10 DB           3749 	ljmp	00103$
   10C5 02 10 E0           3750 	ljmp	00104$
   10C8 02 10 E5           3751 	ljmp	00105$
   10CB 02 10 EA           3752 	ljmp	00106$
   10CE 02 10 EF           3753 	ljmp	00107$
                           3754 ;	D:\Workspace\MIDE\firmware\main.c:60: case '1': gpio_test(); break;
   10D1                    3755 00101$:
   10D1 12 10 F4           3756 	lcall	_gpio_test
                           3757 ;	D:\Workspace\MIDE\firmware\main.c:62: case '2': LCD_test(); break;
   10D4 80 C5              3758 	sjmp	00111$
   10D6                    3759 00102$:
   10D6 12 11 4C           3760 	lcall	_LCD_test
                           3761 ;	D:\Workspace\MIDE\firmware\main.c:64: case '3': seg_test(); break;
   10D9 80 C0              3762 	sjmp	00111$
   10DB                    3763 00103$:
   10DB 12 11 95           3764 	lcall	_seg_test
                           3765 ;	D:\Workspace\MIDE\firmware\main.c:66: case '4': rtc_test(); break; 
   10DE 80 BB              3766 	sjmp	00111$
   10E0                    3767 00104$:
   10E0 12 12 7C           3768 	lcall	_rtc_test
                           3769 ;	D:\Workspace\MIDE\firmware\main.c:68: case '5': eeprom_test(); break; //eeprom
   10E3 80 B6              3770 	sjmp	00111$
   10E5                    3771 00105$:
   10E5 12 14 01           3772 	lcall	_eeprom_test
                           3773 ;	D:\Workspace\MIDE\firmware\main.c:70: case '6': adc_test(); break;
   10E8 80 B1              3774 	sjmp	00111$
   10EA                    3775 00106$:
   10EA 12 14 60           3776 	lcall	_adc_test
                           3777 ;	D:\Workspace\MIDE\firmware\main.c:72: case '7': keypad_test();break;
   10ED 80 AC              3778 	sjmp	00111$
   10EF                    3779 00107$:
   10EF 12 14 E6           3780 	lcall	_keypad_test
                           3781 ;	D:\Workspace\MIDE\firmware\main.c:77: }
   10F2 80 A7              3782 	sjmp	00111$
                           3783 ;------------------------------------------------------------
                           3784 ;Allocation info for local variables in function 'gpio_test'
                           3785 ;------------------------------------------------------------
                           3786 ;------------------------------------------------------------
                           3787 ;	D:\Workspace\MIDE\firmware\main.c:82: void gpio_test()
                           3788 ;	-----------------------------------------
                           3789 ;	 function gpio_test
                           3790 ;	-----------------------------------------
   10F4                    3791 _gpio_test:
                           3792 ;	D:\Workspace\MIDE\firmware\main.c:84: UART_Printf("\n\rConnect any IO Pins to buzzer, relays, leds ");
   10F4 74 EF              3793 	mov	a,#__str_2
   10F6 C0 E0              3794 	push	acc
   10F8 74 16              3795 	mov	a,#(__str_2 >> 8)
   10FA C0 E0              3796 	push	acc
   10FC 74 80              3797 	mov	a,#0x80
   10FE C0 E0              3798 	push	acc
   1100 12 03 A7           3799 	lcall	_UART_Printf
   1103 15 81              3800 	dec	sp
   1105 15 81              3801 	dec	sp
   1107 15 81              3802 	dec	sp
                           3803 ;	D:\Workspace\MIDE\firmware\main.c:85: UART_Printf("\n\rMake connections and hit 'k' to test ");
   1109 74 1E              3804 	mov	a,#__str_3
   110B C0 E0              3805 	push	acc
   110D 74 17              3806 	mov	a,#(__str_3 >> 8)
   110F C0 E0              3807 	push	acc
   1111 74 80              3808 	mov	a,#0x80
   1113 C0 E0              3809 	push	acc
   1115 12 03 A7           3810 	lcall	_UART_Printf
   1118 15 81              3811 	dec	sp
   111A 15 81              3812 	dec	sp
   111C 15 81              3813 	dec	sp
                           3814 ;	D:\Workspace\MIDE\firmware\main.c:86: while(UART_RxChar()!='k');
   111E                    3815 00101$:
   111E 12 00 F6           3816 	lcall	_UART_RxChar
   1121 AA 82              3817 	mov	r2,dpl
   1123 BA 6B F8           3818 	cjne	r2,#0x6B,00101$
                           3819 ;	D:\Workspace\MIDE\firmware\main.c:87: while(1)
   1126                    3820 00105$:
                           3821 ;	D:\Workspace\MIDE\firmware\main.c:90: P0= P1 = P2 =P3= 0xff;	   
   1126 75 B0 FF           3822 	mov	_P3,#0xFF
   1129 75 A0 FF           3823 	mov	_P2,#0xFF
   112C 75 90 FF           3824 	mov	_P1,#0xFF
   112F 75 80 FF           3825 	mov	_P0,#0xFF
                           3826 ;	D:\Workspace\MIDE\firmware\main.c:91: DELAY_sec(1);
   1132 90 00 01           3827 	mov	dptr,#0x0001
   1135 12 0D 6A           3828 	lcall	_DELAY_sec
                           3829 ;	D:\Workspace\MIDE\firmware\main.c:93: P0= P1 = P2 =P3= 0x00;;
   1138 75 B0 00           3830 	mov	_P3,#0x00
   113B 75 A0 00           3831 	mov	_P2,#0x00
   113E 75 90 00           3832 	mov	_P1,#0x00
   1141 75 80 00           3833 	mov	_P0,#0x00
                           3834 ;	D:\Workspace\MIDE\firmware\main.c:94: DELAY_sec(1);
   1144 90 00 01           3835 	mov	dptr,#0x0001
   1147 12 0D 6A           3836 	lcall	_DELAY_sec
   114A 80 DA              3837 	sjmp	00105$
                           3838 ;------------------------------------------------------------
                           3839 ;Allocation info for local variables in function 'LCD_test'
                           3840 ;------------------------------------------------------------
                           3841 ;------------------------------------------------------------
                           3842 ;	D:\Workspace\MIDE\firmware\main.c:99: void LCD_test()
                           3843 ;	-----------------------------------------
                           3844 ;	 function LCD_test
                           3845 ;	-----------------------------------------
   114C                    3846 _LCD_test:
                           3847 ;	D:\Workspace\MIDE\firmware\main.c:101: UART_TxString("\n\r LCD DataBus: P2 Control: RS-P0.0 RW-P0.1 E-P0.2 ");
   114C 90 17 46           3848 	mov	dptr,#__str_4
   114F 75 F0 80           3849 	mov	b,#0x80
   1152 12 01 08           3850 	lcall	_UART_TxString
                           3851 ;	D:\Workspace\MIDE\firmware\main.c:102: UART_Printf("\n\r Make connections and hit 'k' to test ");
   1155 74 7A              3852 	mov	a,#__str_5
   1157 C0 E0              3853 	push	acc
   1159 74 17              3854 	mov	a,#(__str_5 >> 8)
   115B C0 E0              3855 	push	acc
   115D 74 80              3856 	mov	a,#0x80
   115F C0 E0              3857 	push	acc
   1161 12 03 A7           3858 	lcall	_UART_Printf
   1164 15 81              3859 	dec	sp
   1166 15 81              3860 	dec	sp
   1168 15 81              3861 	dec	sp
                           3862 ;	D:\Workspace\MIDE\firmware\main.c:103: while(UART_RxChar()!='k');
   116A                    3863 00101$:
   116A 12 00 F6           3864 	lcall	_UART_RxChar
   116D AA 82              3865 	mov	r2,dpl
   116F BA 6B F8           3866 	cjne	r2,#0x6B,00101$
                           3867 ;	D:\Workspace\MIDE\firmware\main.c:104: LCD_Init(8,2,16);
   1172 74 10              3868 	mov	a,#0x10
   1174 C0 E0              3869 	push	acc
   1176 74 02              3870 	mov	a,#0x02
   1178 C0 E0              3871 	push	acc
   117A 75 82 08           3872 	mov	dpl,#0x08
   117D 12 0A F1           3873 	lcall	_LCD_Init
   1180 15 81              3874 	dec	sp
   1182 15 81              3875 	dec	sp
                           3876 ;	D:\Workspace\MIDE\firmware\main.c:105: DELAY_ms(100);
   1184 90 00 64           3877 	mov	dptr,#0x0064
   1187 12 0D 4C           3878 	lcall	_DELAY_ms
                           3879 ;	D:\Workspace\MIDE\firmware\main.c:106: LCD_DisplayString("Explore Embedded!");
   118A 90 17 A3           3880 	mov	dptr,#__str_6
   118D 75 F0 80           3881 	mov	b,#0x80
   1190 12 0B F4           3882 	lcall	_LCD_DisplayString
                           3883 ;	D:\Workspace\MIDE\firmware\main.c:107: while(1);
   1193                    3884 00105$:
   1193 80 FE              3885 	sjmp	00105$
                           3886 ;------------------------------------------------------------
                           3887 ;Allocation info for local variables in function 'seg_test'
                           3888 ;------------------------------------------------------------
                           3889 ;seg_code                  Allocated to stack - offset 1
                           3890 ;------------------------------------------------------------
                           3891 ;	D:\Workspace\MIDE\firmware\main.c:109: void seg_test()
                           3892 ;	-----------------------------------------
                           3893 ;	 function seg_test
                           3894 ;	-----------------------------------------
   1195                    3895 _seg_test:
   1195 C0 13              3896 	push	_bp
   1197 E5 81              3897 	mov	a,sp
   1199 F5 13              3898 	mov	_bp,a
   119B 24 04              3899 	add	a,#0x04
   119D F5 81              3900 	mov	sp,a
                           3901 ;	D:\Workspace\MIDE\firmware\main.c:111: unsigned char seg_code[]={0xC0,0xF9,0xA4,0xB0}; 
   119F A8 13              3902 	mov	r0,_bp
   11A1 08                 3903 	inc	r0
   11A2 76 C0              3904 	mov	@r0,#0xC0
   11A4 E8                 3905 	mov	a,r0
   11A5 04                 3906 	inc	a
   11A6 F9                 3907 	mov	r1,a
   11A7 77 F9              3908 	mov	@r1,#0xF9
   11A9 74 02              3909 	mov	a,#0x02
   11AB 28                 3910 	add	a,r0
   11AC FA                 3911 	mov	r2,a
   11AD C0 00              3912 	push	ar0
   11AF A8 02              3913 	mov	r0,ar2
   11B1 76 A4              3914 	mov	@r0,#0xA4
   11B3 D0 00              3915 	pop	ar0
   11B5 74 03              3916 	mov	a,#0x03
   11B7 28                 3917 	add	a,r0
   11B8 FB                 3918 	mov	r3,a
   11B9 C0 00              3919 	push	ar0
   11BB A8 03              3920 	mov	r0,ar3
   11BD 76 B0              3921 	mov	@r0,#0xB0
   11BF D0 00              3922 	pop	ar0
                           3923 ;	D:\Workspace\MIDE\firmware\main.c:112: UART_TxString("\n\r Segment DataBus: P2 Seg select: S1->P0.0 S2->P0.1 S3->P0.2 S4->P0.4  ");
   11C1 90 17 B5           3924 	mov	dptr,#__str_7
   11C4 75 F0 80           3925 	mov	b,#0x80
   11C7 C0 02              3926 	push	ar2
   11C9 C0 03              3927 	push	ar3
   11CB C0 00              3928 	push	ar0
   11CD C0 01              3929 	push	ar1
   11CF 12 01 08           3930 	lcall	_UART_TxString
                           3931 ;	D:\Workspace\MIDE\firmware\main.c:113: UART_Printf("\n\rMake connections and hit 'k' to test! ");
   11D2 74 FE              3932 	mov	a,#__str_8
   11D4 C0 E0              3933 	push	acc
   11D6 74 17              3934 	mov	a,#(__str_8 >> 8)
   11D8 C0 E0              3935 	push	acc
   11DA 74 80              3936 	mov	a,#0x80
   11DC C0 E0              3937 	push	acc
   11DE 12 03 A7           3938 	lcall	_UART_Printf
   11E1 15 81              3939 	dec	sp
   11E3 15 81              3940 	dec	sp
   11E5 15 81              3941 	dec	sp
   11E7 D0 01              3942 	pop	ar1
   11E9 D0 00              3943 	pop	ar0
   11EB D0 03              3944 	pop	ar3
   11ED D0 02              3945 	pop	ar2
                           3946 ;	D:\Workspace\MIDE\firmware\main.c:114: while(UART_RxChar()!='k');
   11EF                    3947 00101$:
   11EF C0 02              3948 	push	ar2
   11F1 C0 03              3949 	push	ar3
   11F3 C0 00              3950 	push	ar0
   11F5 C0 01              3951 	push	ar1
   11F7 12 00 F6           3952 	lcall	_UART_RxChar
   11FA AC 82              3953 	mov	r4,dpl
   11FC D0 01              3954 	pop	ar1
   11FE D0 00              3955 	pop	ar0
   1200 D0 03              3956 	pop	ar3
   1202 D0 02              3957 	pop	ar2
   1204 BC 6B E8           3958 	cjne	r4,#0x6B,00101$
                           3959 ;	D:\Workspace\MIDE\firmware\main.c:115: while(1)
   1207                    3960 00105$:
                           3961 ;	D:\Workspace\MIDE\firmware\main.c:117: SegmentSlection=SegOne;
   1207 75 80 01           3962 	mov	_P0,#0x01
                           3963 ;	D:\Workspace\MIDE\firmware\main.c:118: SegmentValue = seg_code[0];
   120A 86 A0              3964 	mov	_P2,@r0
                           3965 ;	D:\Workspace\MIDE\firmware\main.c:119: DELAY_us(10); 
   120C 90 00 0A           3966 	mov	dptr,#0x000A
   120F C0 02              3967 	push	ar2
   1211 C0 03              3968 	push	ar3
   1213 C0 00              3969 	push	ar0
   1215 C0 01              3970 	push	ar1
   1217 12 0D 3C           3971 	lcall	_DELAY_us
   121A D0 01              3972 	pop	ar1
                           3973 ;	D:\Workspace\MIDE\firmware\main.c:120: SegmentSlection=SegTwo;
   121C 75 80 02           3974 	mov	_P0,#0x02
                           3975 ;	D:\Workspace\MIDE\firmware\main.c:121: SegmentValue = seg_code[1];
   121F 87 A0              3976 	mov	_P2,@r1
                           3977 ;	D:\Workspace\MIDE\firmware\main.c:122: DELAY_us(10);
   1221 90 00 0A           3978 	mov	dptr,#0x000A
   1224 C0 01              3979 	push	ar1
   1226 12 0D 3C           3980 	lcall	_DELAY_us
   1229 D0 01              3981 	pop	ar1
   122B D0 00              3982 	pop	ar0
   122D D0 03              3983 	pop	ar3
   122F D0 02              3984 	pop	ar2
                           3985 ;	D:\Workspace\MIDE\firmware\main.c:123: SegmentSlection=SegThree;
   1231 75 80 04           3986 	mov	_P0,#0x04
                           3987 ;	D:\Workspace\MIDE\firmware\main.c:124: SegmentValue = seg_code[2];
   1234 C0 00              3988 	push	ar0
   1236 A8 02              3989 	mov	r0,ar2
   1238 86 A0              3990 	mov	_P2,@r0
   123A D0 00              3991 	pop	ar0
                           3992 ;	D:\Workspace\MIDE\firmware\main.c:125: DELAY_us(10);	
   123C 90 00 0A           3993 	mov	dptr,#0x000A
   123F C0 02              3994 	push	ar2
   1241 C0 03              3995 	push	ar3
   1243 C0 00              3996 	push	ar0
   1245 C0 01              3997 	push	ar1
   1247 12 0D 3C           3998 	lcall	_DELAY_us
   124A D0 01              3999 	pop	ar1
   124C D0 00              4000 	pop	ar0
   124E D0 03              4001 	pop	ar3
   1250 D0 02              4002 	pop	ar2
                           4003 ;	D:\Workspace\MIDE\firmware\main.c:126: SegmentSlection=SegFour;  
   1252 75 80 08           4004 	mov	_P0,#0x08
                           4005 ;	D:\Workspace\MIDE\firmware\main.c:127: SegmentValue = seg_code[3];
   1255 C0 00              4006 	push	ar0
   1257 A8 03              4007 	mov	r0,ar3
   1259 86 A0              4008 	mov	_P2,@r0
   125B D0 00              4009 	pop	ar0
                           4010 ;	D:\Workspace\MIDE\firmware\main.c:128: DELAY_us(10);
   125D 90 00 0A           4011 	mov	dptr,#0x000A
   1260 C0 02              4012 	push	ar2
   1262 C0 03              4013 	push	ar3
   1264 C0 00              4014 	push	ar0
   1266 C0 01              4015 	push	ar1
   1268 12 0D 3C           4016 	lcall	_DELAY_us
   126B D0 01              4017 	pop	ar1
   126D D0 00              4018 	pop	ar0
   126F D0 03              4019 	pop	ar3
   1271 D0 02              4020 	pop	ar2
   1273 02 12 07           4021 	ljmp	00105$
   1276 85 13 81           4022 	mov	sp,_bp
   1279 D0 13              4023 	pop	_bp
   127B 22                 4024 	ret
                           4025 ;------------------------------------------------------------
                           4026 ;Allocation info for local variables in function 'rtc_test'
                           4027 ;------------------------------------------------------------
                           4028 ;sec                       Allocated to stack - offset 1
                           4029 ;min                       Allocated to stack - offset 2
                           4030 ;hour                      Allocated to stack - offset 3
                           4031 ;day                       Allocated to stack - offset 4
                           4032 ;month                     Allocated to stack - offset 5
                           4033 ;year                      Allocated to stack - offset 6
                           4034 ;sloc0                     Allocated to stack - offset 7
                           4035 ;sloc1                     Allocated to stack - offset 10
                           4036 ;sloc2                     Allocated to stack - offset 12
                           4037 ;------------------------------------------------------------
                           4038 ;	D:\Workspace\MIDE\firmware\main.c:132: void rtc_test()
                           4039 ;	-----------------------------------------
                           4040 ;	 function rtc_test
                           4041 ;	-----------------------------------------
   127C                    4042 _rtc_test:
   127C C0 13              4043 	push	_bp
   127E E5 81              4044 	mov	a,sp
   1280 F5 13              4045 	mov	_bp,a
   1282 24 0D              4046 	add	a,#0x0d
   1284 F5 81              4047 	mov	sp,a
                           4048 ;	D:\Workspace\MIDE\firmware\main.c:135: UART_Printf("\n\rConnections SCL->P0.6 SDA->P0.7");
   1286 74 27              4049 	mov	a,#__str_9
   1288 C0 E0              4050 	push	acc
   128A 74 18              4051 	mov	a,#(__str_9 >> 8)
   128C C0 E0              4052 	push	acc
   128E 74 80              4053 	mov	a,#0x80
   1290 C0 E0              4054 	push	acc
   1292 12 03 A7           4055 	lcall	_UART_Printf
   1295 15 81              4056 	dec	sp
   1297 15 81              4057 	dec	sp
   1299 15 81              4058 	dec	sp
                           4059 ;	D:\Workspace\MIDE\firmware\main.c:136: UART_Printf("\n\r Make connections and hit 'k' to test! ");
   129B 74 49              4060 	mov	a,#__str_10
   129D C0 E0              4061 	push	acc
   129F 74 18              4062 	mov	a,#(__str_10 >> 8)
   12A1 C0 E0              4063 	push	acc
   12A3 74 80              4064 	mov	a,#0x80
   12A5 C0 E0              4065 	push	acc
   12A7 12 03 A7           4066 	lcall	_UART_Printf
   12AA 15 81              4067 	dec	sp
   12AC 15 81              4068 	dec	sp
   12AE 15 81              4069 	dec	sp
                           4070 ;	D:\Workspace\MIDE\firmware\main.c:137: while(UART_RxChar()!='k');   
   12B0                    4071 00101$:
   12B0 12 00 F6           4072 	lcall	_UART_RxChar
   12B3 AA 82              4073 	mov	r2,dpl
   12B5 BA 6B F8           4074 	cjne	r2,#0x6B,00101$
                           4075 ;	D:\Workspace\MIDE\firmware\main.c:139: RTC_Init();
   12B8 12 08 34           4076 	lcall	_RTC_Init
                           4077 ;	D:\Workspace\MIDE\firmware\main.c:144: RTC_SetTime(0x10,0x40,0x00);  //  10:40:20 am
   12BB E4                 4078 	clr	a
   12BC C0 E0              4079 	push	acc
   12BE 74 40              4080 	mov	a,#0x40
   12C0 C0 E0              4081 	push	acc
   12C2 75 82 10           4082 	mov	dpl,#0x10
   12C5 12 08 4F           4083 	lcall	_RTC_SetTime
   12C8 15 81              4084 	dec	sp
   12CA 15 81              4085 	dec	sp
                           4086 ;	D:\Workspace\MIDE\firmware\main.c:145: RTC_SetDate(0x01,0x01,0x15);  //  1st Jan 2015
   12CC 74 15              4087 	mov	a,#0x15
   12CE C0 E0              4088 	push	acc
   12D0 74 01              4089 	mov	a,#0x01
   12D2 C0 E0              4090 	push	acc
   12D4 75 82 01           4091 	mov	dpl,#0x01
   12D7 12 08 88           4092 	lcall	_RTC_SetDate
   12DA 15 81              4093 	dec	sp
   12DC 15 81              4094 	dec	sp
                           4095 ;	D:\Workspace\MIDE\firmware\main.c:150: while(1)
   12DE                    4096 00105$:
                           4097 ;	D:\Workspace\MIDE\firmware\main.c:153: RTC_GetTime(&hour,&min,&sec);      
   12DE AA 13              4098 	mov	r2,_bp
   12E0 0A                 4099 	inc	r2
   12E1 7B 00              4100 	mov	r3,#0x00
   12E3 7C 40              4101 	mov	r4,#0x40
   12E5 E5 13              4102 	mov	a,_bp
   12E7 24 02              4103 	add	a,#0x02
   12E9 FD                 4104 	mov	r5,a
   12EA E5 13              4105 	mov	a,_bp
   12EC 24 07              4106 	add	a,#0x07
   12EE F8                 4107 	mov	r0,a
   12EF A6 05              4108 	mov	@r0,ar5
   12F1 08                 4109 	inc	r0
   12F2 76 00              4110 	mov	@r0,#0x00
   12F4 08                 4111 	inc	r0
   12F5 76 40              4112 	mov	@r0,#0x40
   12F7 E5 13              4113 	mov	a,_bp
   12F9 24 03              4114 	add	a,#0x03
   12FB FD                 4115 	mov	r5,a
   12FC 7E 00              4116 	mov	r6,#0x00
   12FE 7F 40              4117 	mov	r7,#0x40
   1300 C0 02              4118 	push	ar2
   1302 C0 03              4119 	push	ar3
   1304 C0 04              4120 	push	ar4
   1306 E5 13              4121 	mov	a,_bp
   1308 24 07              4122 	add	a,#0x07
   130A F8                 4123 	mov	r0,a
   130B E6                 4124 	mov	a,@r0
   130C C0 E0              4125 	push	acc
   130E 08                 4126 	inc	r0
   130F E6                 4127 	mov	a,@r0
   1310 C0 E0              4128 	push	acc
   1312 08                 4129 	inc	r0
   1313 E6                 4130 	mov	a,@r0
   1314 C0 E0              4131 	push	acc
   1316 8D 82              4132 	mov	dpl,r5
   1318 8E 83              4133 	mov	dph,r6
   131A 8F F0              4134 	mov	b,r7
   131C 12 08 C1           4135 	lcall	_RTC_GetTime
   131F E5 81              4136 	mov	a,sp
   1321 24 FA              4137 	add	a,#0xfa
   1323 F5 81              4138 	mov	sp,a
                           4139 ;	D:\Workspace\MIDE\firmware\main.c:154: RTC_GetDate(&day,&month,&year);        
   1325 E5 13              4140 	mov	a,_bp
   1327 24 06              4141 	add	a,#0x06
   1329 FA                 4142 	mov	r2,a
   132A 7B 00              4143 	mov	r3,#0x00
   132C 7C 40              4144 	mov	r4,#0x40
   132E E5 13              4145 	mov	a,_bp
   1330 24 05              4146 	add	a,#0x05
   1332 FD                 4147 	mov	r5,a
   1333 E5 13              4148 	mov	a,_bp
   1335 24 07              4149 	add	a,#0x07
   1337 F8                 4150 	mov	r0,a
   1338 A6 05              4151 	mov	@r0,ar5
   133A 08                 4152 	inc	r0
   133B 76 00              4153 	mov	@r0,#0x00
   133D 08                 4154 	inc	r0
   133E 76 40              4155 	mov	@r0,#0x40
   1340 E5 13              4156 	mov	a,_bp
   1342 24 04              4157 	add	a,#0x04
   1344 FD                 4158 	mov	r5,a
   1345 7E 00              4159 	mov	r6,#0x00
   1347 7F 40              4160 	mov	r7,#0x40
   1349 C0 02              4161 	push	ar2
   134B C0 03              4162 	push	ar3
   134D C0 04              4163 	push	ar4
   134F E5 13              4164 	mov	a,_bp
   1351 24 07              4165 	add	a,#0x07
   1353 F8                 4166 	mov	r0,a
   1354 E6                 4167 	mov	a,@r0
   1355 C0 E0              4168 	push	acc
   1357 08                 4169 	inc	r0
   1358 E6                 4170 	mov	a,@r0
   1359 C0 E0              4171 	push	acc
   135B 08                 4172 	inc	r0
   135C E6                 4173 	mov	a,@r0
   135D C0 E0              4174 	push	acc
   135F 8D 82              4175 	mov	dpl,r5
   1361 8E 83              4176 	mov	dph,r6
   1363 8F F0              4177 	mov	b,r7
   1365 12 09 5D           4178 	lcall	_RTC_GetDate
   1368 E5 81              4179 	mov	a,sp
   136A 24 FA              4180 	add	a,#0xfa
   136C F5 81              4181 	mov	sp,a
                           4182 ;	D:\Workspace\MIDE\firmware\main.c:156: UART_Printf("\n\rtime:%2x:%2x:%2x  \nDate:%2x/%2x/%2x",(uint16_t)hour,(uint16_t)min,(uint16_t)sec,(uint16_t)day,(uint16_t)month,(uint16_t)year);
   136E E5 13              4183 	mov	a,_bp
   1370 24 06              4184 	add	a,#0x06
   1372 F8                 4185 	mov	r0,a
   1373 86 02              4186 	mov	ar2,@r0
   1375 7B 00              4187 	mov	r3,#0x00
   1377 E5 13              4188 	mov	a,_bp
   1379 24 05              4189 	add	a,#0x05
   137B F8                 4190 	mov	r0,a
   137C 86 04              4191 	mov	ar4,@r0
   137E 7D 00              4192 	mov	r5,#0x00
   1380 E5 13              4193 	mov	a,_bp
   1382 24 04              4194 	add	a,#0x04
   1384 F8                 4195 	mov	r0,a
   1385 E5 13              4196 	mov	a,_bp
   1387 24 07              4197 	add	a,#0x07
   1389 F9                 4198 	mov	r1,a
   138A E6                 4199 	mov	a,@r0
   138B F7                 4200 	mov	@r1,a
   138C 09                 4201 	inc	r1
   138D 77 00              4202 	mov	@r1,#0x00
   138F A8 13              4203 	mov	r0,_bp
   1391 08                 4204 	inc	r0
   1392 E5 13              4205 	mov	a,_bp
   1394 24 0A              4206 	add	a,#0x0a
   1396 F9                 4207 	mov	r1,a
   1397 E6                 4208 	mov	a,@r0
   1398 F7                 4209 	mov	@r1,a
   1399 09                 4210 	inc	r1
   139A 77 00              4211 	mov	@r1,#0x00
   139C A8 13              4212 	mov	r0,_bp
   139E 08                 4213 	inc	r0
   139F 08                 4214 	inc	r0
   13A0 E5 13              4215 	mov	a,_bp
   13A2 24 0C              4216 	add	a,#0x0c
   13A4 F9                 4217 	mov	r1,a
   13A5 E6                 4218 	mov	a,@r0
   13A6 F7                 4219 	mov	@r1,a
   13A7 09                 4220 	inc	r1
   13A8 77 00              4221 	mov	@r1,#0x00
   13AA E5 13              4222 	mov	a,_bp
   13AC 24 03              4223 	add	a,#0x03
   13AE F8                 4224 	mov	r0,a
   13AF 86 06              4225 	mov	ar6,@r0
   13B1 7F 00              4226 	mov	r7,#0x00
   13B3 C0 02              4227 	push	ar2
   13B5 C0 03              4228 	push	ar3
   13B7 C0 04              4229 	push	ar4
   13B9 C0 05              4230 	push	ar5
   13BB E5 13              4231 	mov	a,_bp
   13BD 24 07              4232 	add	a,#0x07
   13BF F8                 4233 	mov	r0,a
   13C0 E6                 4234 	mov	a,@r0
   13C1 C0 E0              4235 	push	acc
   13C3 08                 4236 	inc	r0
   13C4 E6                 4237 	mov	a,@r0
   13C5 C0 E0              4238 	push	acc
   13C7 E5 13              4239 	mov	a,_bp
   13C9 24 0A              4240 	add	a,#0x0a
   13CB F8                 4241 	mov	r0,a
   13CC E6                 4242 	mov	a,@r0
   13CD C0 E0              4243 	push	acc
   13CF 08                 4244 	inc	r0
   13D0 E6                 4245 	mov	a,@r0
   13D1 C0 E0              4246 	push	acc
   13D3 E5 13              4247 	mov	a,_bp
   13D5 24 0C              4248 	add	a,#0x0c
   13D7 F8                 4249 	mov	r0,a
   13D8 E6                 4250 	mov	a,@r0
   13D9 C0 E0              4251 	push	acc
   13DB 08                 4252 	inc	r0
   13DC E6                 4253 	mov	a,@r0
   13DD C0 E0              4254 	push	acc
   13DF C0 06              4255 	push	ar6
   13E1 C0 07              4256 	push	ar7
   13E3 74 73              4257 	mov	a,#__str_11
   13E5 C0 E0              4258 	push	acc
   13E7 74 18              4259 	mov	a,#(__str_11 >> 8)
   13E9 C0 E0              4260 	push	acc
   13EB 74 80              4261 	mov	a,#0x80
   13ED C0 E0              4262 	push	acc
   13EF 12 03 A7           4263 	lcall	_UART_Printf
   13F2 E5 81              4264 	mov	a,sp
   13F4 24 F1              4265 	add	a,#0xf1
   13F6 F5 81              4266 	mov	sp,a
   13F8 02 12 DE           4267 	ljmp	00105$
   13FB 85 13 81           4268 	mov	sp,_bp
   13FE D0 13              4269 	pop	_bp
   1400 22                 4270 	ret
                           4271 ;------------------------------------------------------------
                           4272 ;Allocation info for local variables in function 'eeprom_test'
                           4273 ;------------------------------------------------------------
                           4274 ;eeprom_address            Allocated to registers 
                           4275 ;write_char                Allocated to registers 
                           4276 ;read_char                 Allocated to registers r2 
                           4277 ;------------------------------------------------------------
                           4278 ;	D:\Workspace\MIDE\firmware\main.c:163: void eeprom_test()
                           4279 ;	-----------------------------------------
                           4280 ;	 function eeprom_test
                           4281 ;	-----------------------------------------
   1401                    4282 _eeprom_test:
                           4283 ;	D:\Workspace\MIDE\firmware\main.c:167: UART_Printf("Connections SCL->P0.6 SDA->P0.7");
   1401 74 99              4284 	mov	a,#__str_12
   1403 C0 E0              4285 	push	acc
   1405 74 18              4286 	mov	a,#(__str_12 >> 8)
   1407 C0 E0              4287 	push	acc
   1409 74 80              4288 	mov	a,#0x80
   140B C0 E0              4289 	push	acc
   140D 12 03 A7           4290 	lcall	_UART_Printf
   1410 15 81              4291 	dec	sp
   1412 15 81              4292 	dec	sp
   1414 15 81              4293 	dec	sp
                           4294 ;	D:\Workspace\MIDE\firmware\main.c:168: UART_Printf("Make connections and hit 'k' to test! ");
   1416 74 B9              4295 	mov	a,#__str_13
   1418 C0 E0              4296 	push	acc
   141A 74 18              4297 	mov	a,#(__str_13 >> 8)
   141C C0 E0              4298 	push	acc
   141E 74 80              4299 	mov	a,#0x80
   1420 C0 E0              4300 	push	acc
   1422 12 03 A7           4301 	lcall	_UART_Printf
   1425 15 81              4302 	dec	sp
   1427 15 81              4303 	dec	sp
   1429 15 81              4304 	dec	sp
                           4305 ;	D:\Workspace\MIDE\firmware\main.c:169: while(UART_RxChar()!='k');
   142B                    4306 00101$:
   142B 12 00 F6           4307 	lcall	_UART_RxChar
   142E AA 82              4308 	mov	r2,dpl
   1430 BA 6B F8           4309 	cjne	r2,#0x6B,00101$
                           4310 ;	D:\Workspace\MIDE\firmware\main.c:170: UART_TxString("\n\rEeprom Write: ");      //Print the message on UART
   1433 90 18 E0           4311 	mov	dptr,#__str_14
   1436 75 F0 80           4312 	mov	b,#0x80
   1439 12 01 08           4313 	lcall	_UART_TxString
                           4314 ;	D:\Workspace\MIDE\firmware\main.c:171: UART_TxChar(write_char);			         //Print the char to be written 
   143C 75 82 58           4315 	mov	dpl,#0x58
   143F 12 00 FF           4316 	lcall	_UART_TxChar
                           4317 ;	D:\Workspace\MIDE\firmware\main.c:172: EEPROM_WriteByte(eeprom_address,write_char);	// Write the data at memoryLocation	0x00
   1442 74 58              4318 	mov	a,#0x58
   1444 C0 E0              4319 	push	acc
   1446 90 00 00           4320 	mov	dptr,#0x0000
   1449 12 0F 25           4321 	lcall	_EEPROM_WriteByte
   144C 15 81              4322 	dec	sp
                           4323 ;	D:\Workspace\MIDE\firmware\main.c:174: UART_TxString("  Eeprom Read: ");            //Print the message on UART
   144E 90 18 F1           4324 	mov	dptr,#__str_15
   1451 75 F0 80           4325 	mov	b,#0x80
   1454 12 01 08           4326 	lcall	_UART_TxString
                           4327 ;	D:\Workspace\MIDE\firmware\main.c:175: read_char = EEPROM_ReadByte(eeprom_address);	// Read the data from memoryLocation 0x00
   1457 90 00 00           4328 	mov	dptr,#0x0000
   145A 12 0F 6C           4329 	lcall	_EEPROM_ReadByte
                           4330 ;	D:\Workspace\MIDE\firmware\main.c:176: UART_TxChar(read_char);	
   145D 02 00 FF           4331 	ljmp	_UART_TxChar
                           4332 ;------------------------------------------------------------
                           4333 ;Allocation info for local variables in function 'adc_test'
                           4334 ;------------------------------------------------------------
                           4335 ;temp                      Allocated to registers 
                           4336 ;light                     Allocated to registers 
                           4337 ;pot                       Allocated to registers 
                           4338 ;------------------------------------------------------------
                           4339 ;	D:\Workspace\MIDE\firmware\main.c:180: void adc_test()
                           4340 ;	-----------------------------------------
                           4341 ;	 function adc_test
                           4342 ;	-----------------------------------------
   1460                    4343 _adc_test:
                           4344 ;	D:\Workspace\MIDE\firmware\main.c:183: UART_Printf("\n\rConnections: DataBus P1 Control: adc_A->P0.0 adc_B->P0.1 adc_C->P0.2 adc_ALE->P.3 adc_Start->P.4 adc_EOC->P1.5 adc_OE->P1.6");
   1460 74 01              4345 	mov	a,#__str_16
   1462 C0 E0              4346 	push	acc
   1464 74 19              4347 	mov	a,#(__str_16 >> 8)
   1466 C0 E0              4348 	push	acc
   1468 74 80              4349 	mov	a,#0x80
   146A C0 E0              4350 	push	acc
   146C 12 03 A7           4351 	lcall	_UART_Printf
   146F 15 81              4352 	dec	sp
   1471 15 81              4353 	dec	sp
   1473 15 81              4354 	dec	sp
                           4355 ;	D:\Workspace\MIDE\firmware\main.c:184: UART_Printf("\n\rMake connections and hit 'k' to test!");
   1475 74 7F              4356 	mov	a,#__str_17
   1477 C0 E0              4357 	push	acc
   1479 74 19              4358 	mov	a,#(__str_17 >> 8)
   147B C0 E0              4359 	push	acc
   147D 74 80              4360 	mov	a,#0x80
   147F C0 E0              4361 	push	acc
   1481 12 03 A7           4362 	lcall	_UART_Printf
   1484 15 81              4363 	dec	sp
   1486 15 81              4364 	dec	sp
   1488 15 81              4365 	dec	sp
                           4366 ;	D:\Workspace\MIDE\firmware\main.c:185: while(UART_RxChar()!='k');
   148A                    4367 00101$:
   148A 12 00 F6           4368 	lcall	_UART_RxChar
   148D AA 82              4369 	mov	r2,dpl
   148F BA 6B F8           4370 	cjne	r2,#0x6B,00101$
                           4371 ;	D:\Workspace\MIDE\firmware\main.c:186: ADC_Init();
   1492 12 0D 88           4372 	lcall	_ADC_Init
                           4373 ;	D:\Workspace\MIDE\firmware\main.c:188: while(1)
   1495                    4374 00105$:
                           4375 ;	D:\Workspace\MIDE\firmware\main.c:190: temp = ADC_GetAdcValue(0);
   1495 75 82 00           4376 	mov	dpl,#0x00
   1498 12 0D 98           4377 	lcall	_ADC_GetAdcValue
   149B AA 82              4378 	mov	r2,dpl
   149D AB 83              4379 	mov	r3,dph
                           4380 ;	D:\Workspace\MIDE\firmware\main.c:191: pot = ADC_GetAdcValue(1);
   149F 75 82 01           4381 	mov	dpl,#0x01
   14A2 C0 02              4382 	push	ar2
   14A4 C0 03              4383 	push	ar3
   14A6 12 0D 98           4384 	lcall	_ADC_GetAdcValue
   14A9 AC 82              4385 	mov	r4,dpl
   14AB AD 83              4386 	mov	r5,dph
                           4387 ;	D:\Workspace\MIDE\firmware\main.c:192: light = ADC_GetAdcValue(2);
   14AD 75 82 02           4388 	mov	dpl,#0x02
   14B0 C0 04              4389 	push	ar4
   14B2 C0 05              4390 	push	ar5
   14B4 12 0D 98           4391 	lcall	_ADC_GetAdcValue
   14B7 AE 82              4392 	mov	r6,dpl
   14B9 AF 83              4393 	mov	r7,dph
   14BB D0 05              4394 	pop	ar5
   14BD D0 04              4395 	pop	ar4
   14BF D0 03              4396 	pop	ar3
   14C1 D0 02              4397 	pop	ar2
                           4398 ;	D:\Workspace\MIDE\firmware\main.c:193: UART_Printf("\n\rtemp:%3d pot:%3d light:%3d", temp,pot,light);
   14C3 C0 06              4399 	push	ar6
   14C5 C0 07              4400 	push	ar7
   14C7 C0 04              4401 	push	ar4
   14C9 C0 05              4402 	push	ar5
   14CB C0 02              4403 	push	ar2
   14CD C0 03              4404 	push	ar3
   14CF 74 A7              4405 	mov	a,#__str_18
   14D1 C0 E0              4406 	push	acc
   14D3 74 19              4407 	mov	a,#(__str_18 >> 8)
   14D5 C0 E0              4408 	push	acc
   14D7 74 80              4409 	mov	a,#0x80
   14D9 C0 E0              4410 	push	acc
   14DB 12 03 A7           4411 	lcall	_UART_Printf
   14DE E5 81              4412 	mov	a,sp
   14E0 24 F7              4413 	add	a,#0xf7
   14E2 F5 81              4414 	mov	sp,a
   14E4 80 AF              4415 	sjmp	00105$
                           4416 ;------------------------------------------------------------
                           4417 ;Allocation info for local variables in function 'keypad_test'
                           4418 ;------------------------------------------------------------
                           4419 ;key                       Allocated to registers r2 
                           4420 ;------------------------------------------------------------
                           4421 ;	D:\Workspace\MIDE\firmware\main.c:198: void keypad_test()
                           4422 ;	-----------------------------------------
                           4423 ;	 function keypad_test
                           4424 ;	-----------------------------------------
   14E6                    4425 _keypad_test:
                           4426 ;	D:\Workspace\MIDE\firmware\main.c:201: UART_Printf("\n\rConnections: Port 2");
   14E6 74 C4              4427 	mov	a,#__str_19
   14E8 C0 E0              4428 	push	acc
   14EA 74 19              4429 	mov	a,#(__str_19 >> 8)
   14EC C0 E0              4430 	push	acc
   14EE 74 80              4431 	mov	a,#0x80
   14F0 C0 E0              4432 	push	acc
   14F2 12 03 A7           4433 	lcall	_UART_Printf
   14F5 15 81              4434 	dec	sp
   14F7 15 81              4435 	dec	sp
   14F9 15 81              4436 	dec	sp
                           4437 ;	D:\Workspace\MIDE\firmware\main.c:202: UART_Printf("\n\rMake connections and hit 'k' to test!");
   14FB 74 7F              4438 	mov	a,#__str_17
   14FD C0 E0              4439 	push	acc
   14FF 74 19              4440 	mov	a,#(__str_17 >> 8)
   1501 C0 E0              4441 	push	acc
   1503 74 80              4442 	mov	a,#0x80
   1505 C0 E0              4443 	push	acc
   1507 12 03 A7           4444 	lcall	_UART_Printf
   150A 15 81              4445 	dec	sp
   150C 15 81              4446 	dec	sp
   150E 15 81              4447 	dec	sp
                           4448 ;	D:\Workspace\MIDE\firmware\main.c:203: while(UART_RxChar()!='k');
   1510                    4449 00101$:
   1510 12 00 F6           4450 	lcall	_UART_RxChar
   1513 AA 82              4451 	mov	r2,dpl
   1515 BA 6B F8           4452 	cjne	r2,#0x6B,00101$
                           4453 ;	D:\Workspace\MIDE\firmware\main.c:204: KEYPAD_Init();
   1518 12 0E 00           4454 	lcall	_KEYPAD_Init
                           4455 ;	D:\Workspace\MIDE\firmware\main.c:205: while(1)
   151B                    4456 00105$:
                           4457 ;	D:\Workspace\MIDE\firmware\main.c:207: key = KEYPAD_GetKey();
   151B 12 0E 3E           4458 	lcall	_KEYPAD_GetKey
   151E AA 82              4459 	mov	r2,dpl
                           4460 ;	D:\Workspace\MIDE\firmware\main.c:208: UART_Printf("\n\r Key:%c", key);
   1520 7B 00              4461 	mov	r3,#0x00
   1522 C0 02              4462 	push	ar2
   1524 C0 03              4463 	push	ar3
   1526 74 DA              4464 	mov	a,#__str_20
   1528 C0 E0              4465 	push	acc
   152A 74 19              4466 	mov	a,#(__str_20 >> 8)
   152C C0 E0              4467 	push	acc
   152E 74 80              4468 	mov	a,#0x80
   1530 C0 E0              4469 	push	acc
   1532 12 03 A7           4470 	lcall	_UART_Printf
   1535 E5 81              4471 	mov	a,sp
   1537 24 FB              4472 	add	a,#0xfb
   1539 F5 81              4473 	mov	sp,a
   153B 80 DE              4474 	sjmp	00105$
                           4475 	.area CSEG    (CODE)
                           4476 	.area CONST   (CODE)
   1653                    4477 __str_0:
   1653 0A                 4478 	.db 0x0A
   1654 0D                 4479 	.db 0x0D
   1655 54 65 73 74 20 6D  4480 	.ascii "Test menu Utra x51 v1.1"
        65 6E 75 20 55 74
        72 61 20 78 35 31
        20 76 31 2E 31
   166C 0D                 4481 	.db 0x0D
   166D 0A                 4482 	.db 0x0A
   166E 20 31 3A 47 50 49  4483 	.ascii " 1:GPIO Blink"
        4F 20 42 6C 69 6E
        6B
   167B 0D                 4484 	.db 0x0D
   167C 0A                 4485 	.db 0x0A
   167D 20 32 3A 4C 43 44  4486 	.ascii " 2:LCD "
        20
   1684 0A                 4487 	.db 0x0A
   1685 0D                 4488 	.db 0x0D
   1686 20 33 3A 37 2D 53  4489 	.ascii " 3:7-Segm"
        65 67 6D
   168F 65 6E 74           4490 	.ascii "ent"
   1692 0A                 4491 	.db 0x0A
   1693 0D                 4492 	.db 0x0D
   1694 20 34 3A 52 54 43  4493 	.ascii " 4:RTC"
   169A 0A                 4494 	.db 0x0A
   169B 0D                 4495 	.db 0x0D
   169C 20 35 3A 45 45 50  4496 	.ascii " 5:EEPROM"
        52 4F 4D
   16A5 0A                 4497 	.db 0x0A
   16A6 0D                 4498 	.db 0x0D
   16A7 20 36 3A 41 44 43  4499 	.ascii " 6:ADC"
   16AD 0A                 4500 	.db 0x0A
   16AE 0D                 4501 	.db 0x0D
   16AF 20 37 3A 4B 65 79  4502 	.ascii " 7:Keypad "
        70 61 64 20
   16B9 0A                 4503 	.db 0x0A
   16BA 0D                 4504 	.db 0x0D
   16BB 20 45 6E 74 65 72  4505 	.ascii " Enter option:"
        20 6F 70 74 69 6F
        6E 3A
   16C9 00                 4506 	.db 0x00
   16CA                    4507 __str_1:
   16CA 0A                 4508 	.db 0x0A
   16CB 0D                 4509 	.db 0x0D
   16CC 52 65 73 65 74 20  4510 	.ascii "Reset the board after test is done"
        74 68 65 20 62 6F
        61 72 64 20 61 66
        74 65 72 20 74 65
        73 74 20 69 73 20
        64 6F 6E 65
   16EE 00                 4511 	.db 0x00
   16EF                    4512 __str_2:
   16EF 0A                 4513 	.db 0x0A
   16F0 0D                 4514 	.db 0x0D
   16F1 43 6F 6E 6E 65 63  4515 	.ascii "Connect any IO Pins to buzzer, relays, leds "
        74 20 61 6E 79 20
        49 4F 20 50 69 6E
        73 20 74 6F 20 62
        75 7A 7A 65 72 2C
        20 72 65 6C 61 79
        73 2C 20 6C 65 64
        73 20
   171D 00                 4516 	.db 0x00
   171E                    4517 __str_3:
   171E 0A                 4518 	.db 0x0A
   171F 0D                 4519 	.db 0x0D
   1720 4D 61 6B 65 20 63  4520 	.ascii "Make connections and hit 'k' to test "
        6F 6E 6E 65 63 74
        69 6F 6E 73 20 61
        6E 64 20 68 69 74
        20 27 6B 27 20 74
        6F 20 74 65 73 74
        20
   1745 00                 4521 	.db 0x00
   1746                    4522 __str_4:
   1746 0A                 4523 	.db 0x0A
   1747 0D                 4524 	.db 0x0D
   1748 20 4C 43 44 20 44  4525 	.ascii " LCD DataBus: P2 Control: RS-P0.0 RW-P0.1 E-P0.2 "
        61 74 61 42 75 73
        3A 20 50 32 20 43
        6F 6E 74 72 6F 6C
        3A 20 52 53 2D 50
        30 2E 30 20 52 57
        2D 50 30 2E 31 20
        45 2D 50 30 2E 32
        20
   1779 00                 4526 	.db 0x00
   177A                    4527 __str_5:
   177A 0A                 4528 	.db 0x0A
   177B 0D                 4529 	.db 0x0D
   177C 20 4D 61 6B 65 20  4530 	.ascii " Make connections and hit 'k' to test "
        63 6F 6E 6E 65 63
        74 69 6F 6E 73 20
        61 6E 64 20 68 69
        74 20 27 6B 27 20
        74 6F 20 74 65 73
        74 20
   17A2 00                 4531 	.db 0x00
   17A3                    4532 __str_6:
   17A3 45 78 70 6C 6F 72  4533 	.ascii "Explore Embedded!"
        65 20 45 6D 62 65
        64 64 65 64 21
   17B4 00                 4534 	.db 0x00
   17B5                    4535 __str_7:
   17B5 0A                 4536 	.db 0x0A
   17B6 0D                 4537 	.db 0x0D
   17B7 20 53 65 67 6D 65  4538 	.ascii " Segment DataBus: P2 Seg select: S1->P0.0 S2->P0.1 S3->P0."
        6E 74 20 44 61 74
        61 42 75 73 3A 20
        50 32 20 53 65 67
        20 73 65 6C 65 63
        74 3A 20 53 31 2D
        3E 50 30 2E 30 20
        53 32 2D 3E 50 30
        2E 31 20 53 33 2D
        3E 50 30 2E
   17F1 32 20 53 34 2D 3E  4539 	.ascii "2 S4->P0.4  "
        50 30 2E 34 20 20
   17FD 00                 4540 	.db 0x00
   17FE                    4541 __str_8:
   17FE 0A                 4542 	.db 0x0A
   17FF 0D                 4543 	.db 0x0D
   1800 4D 61 6B 65 20 63  4544 	.ascii "Make connections and hit 'k' to test! "
        6F 6E 6E 65 63 74
        69 6F 6E 73 20 61
        6E 64 20 68 69 74
        20 27 6B 27 20 74
        6F 20 74 65 73 74
        21 20
   1826 00                 4545 	.db 0x00
   1827                    4546 __str_9:
   1827 0A                 4547 	.db 0x0A
   1828 0D                 4548 	.db 0x0D
   1829 43 6F 6E 6E 65 63  4549 	.ascii "Connections SCL->P0.6 SDA->P0.7"
        74 69 6F 6E 73 20
        53 43 4C 2D 3E 50
        30 2E 36 20 53 44
        41 2D 3E 50 30 2E
        37
   1848 00                 4550 	.db 0x00
   1849                    4551 __str_10:
   1849 0A                 4552 	.db 0x0A
   184A 0D                 4553 	.db 0x0D
   184B 20 4D 61 6B 65 20  4554 	.ascii " Make connections and hit 'k' to test! "
        63 6F 6E 6E 65 63
        74 69 6F 6E 73 20
        61 6E 64 20 68 69
        74 20 27 6B 27 20
        74 6F 20 74 65 73
        74 21 20
   1872 00                 4555 	.db 0x00
   1873                    4556 __str_11:
   1873 0A                 4557 	.db 0x0A
   1874 0D                 4558 	.db 0x0D
   1875 74 69 6D 65 3A 25  4559 	.ascii "time:%2x:%2x:%2x  "
        32 78 3A 25 32 78
        3A 25 32 78 20 20
   1887 0A                 4560 	.db 0x0A
   1888 44 61 74 65 3A 25  4561 	.ascii "Date:%2x/%2x/%2x"
        32 78 2F 25 32 78
        2F 25 32 78
   1898 00                 4562 	.db 0x00
   1899                    4563 __str_12:
   1899 43 6F 6E 6E 65 63  4564 	.ascii "Connections SCL->P0.6 SDA->P0.7"
        74 69 6F 6E 73 20
        53 43 4C 2D 3E 50
        30 2E 36 20 53 44
        41 2D 3E 50 30 2E
        37
   18B8 00                 4565 	.db 0x00
   18B9                    4566 __str_13:
   18B9 4D 61 6B 65 20 63  4567 	.ascii "Make connections and hit 'k' to test! "
        6F 6E 6E 65 63 74
        69 6F 6E 73 20 61
        6E 64 20 68 69 74
        20 27 6B 27 20 74
        6F 20 74 65 73 74
        21 20
   18DF 00                 4568 	.db 0x00
   18E0                    4569 __str_14:
   18E0 0A                 4570 	.db 0x0A
   18E1 0D                 4571 	.db 0x0D
   18E2 45 65 70 72 6F 6D  4572 	.ascii "Eeprom Write: "
        20 57 72 69 74 65
        3A 20
   18F0 00                 4573 	.db 0x00
   18F1                    4574 __str_15:
   18F1 20 20 45 65 70 72  4575 	.ascii "  Eeprom Read: "
        6F 6D 20 52 65 61
        64 3A 20
   1900 00                 4576 	.db 0x00
   1901                    4577 __str_16:
   1901 0A                 4578 	.db 0x0A
   1902 0D                 4579 	.db 0x0D
   1903 43 6F 6E 6E 65 63  4580 	.ascii "Connections: DataBus P1 Control: adc_A->P0.0 adc_B->P0.1 a"
        74 69 6F 6E 73 3A
        20 44 61 74 61 42
        75 73 20 50 31 20
        43 6F 6E 74 72 6F
        6C 3A 20 61 64 63
        5F 41 2D 3E 50 30
        2E 30 20 61 64 63
        5F 42 2D 3E 50 30
        2E 31 20 61
   193D 64 63 5F 43 2D 3E  4581 	.ascii "dc_C->P0.2 adc_ALE->P.3 adc_Start->P.4 adc_EOC->P1.5 adc_OE-"
        50 30 2E 32 20 61
        64 63 5F 41 4C 45
        2D 3E 50 2E 33 20
        61 64 63 5F 53 74
        61 72 74 2D 3E 50
        2E 34 20 61 64 63
        5F 45 4F 43 2D 3E
        50 31 2E 35 20 61
        64 63 5F 4F 45 2D
   1979 3E 50 31 2E 36     4582 	.ascii ">P1.6"
   197E 00                 4583 	.db 0x00
   197F                    4584 __str_17:
   197F 0A                 4585 	.db 0x0A
   1980 0D                 4586 	.db 0x0D
   1981 4D 61 6B 65 20 63  4587 	.ascii "Make connections and hit 'k' to test!"
        6F 6E 6E 65 63 74
        69 6F 6E 73 20 61
        6E 64 20 68 69 74
        20 27 6B 27 20 74
        6F 20 74 65 73 74
        21
   19A6 00                 4588 	.db 0x00
   19A7                    4589 __str_18:
   19A7 0A                 4590 	.db 0x0A
   19A8 0D                 4591 	.db 0x0D
   19A9 74 65 6D 70 3A 25  4592 	.ascii "temp:%3d pot:%3d light:%3d"
        33 64 20 70 6F 74
        3A 25 33 64 20 6C
        69 67 68 74 3A 25
        33 64
   19C3 00                 4593 	.db 0x00
   19C4                    4594 __str_19:
   19C4 0A                 4595 	.db 0x0A
   19C5 0D                 4596 	.db 0x0D
   19C6 43 6F 6E 6E 65 63  4597 	.ascii "Connections: Port 2"
        74 69 6F 6E 73 3A
        20 50 6F 72 74 20
        32
   19D9 00                 4598 	.db 0x00
   19DA                    4599 __str_20:
   19DA 0A                 4600 	.db 0x0A
   19DB 0D                 4601 	.db 0x0D
   19DC 20 4B 65 79 3A 25  4602 	.ascii " Key:%c"
        63
   19E3 00                 4603 	.db 0x00
                           4604 	.area XINIT   (CODE)
                           4605 	.area CABS    (ABS,CODE)
