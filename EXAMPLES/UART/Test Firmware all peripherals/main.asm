;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.0.1 #6083 (Dec 17 2010) (MINGW32)
; This file was generated Sat Mar 14 18:59:42 2015
;--------------------------------------------------------
	.module main
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
	.globl _T2CON_7
	.globl _T2CON_6
	.globl _T2CON_5
	.globl _T2CON_4
	.globl _T2CON_3
	.globl _T2CON_2
	.globl _T2CON_1
	.globl _T2CON_0
	.globl _RI
	.globl _TI
	.globl _RB8
	.globl _TB8
	.globl _REN
	.globl _SM2
	.globl _SM1
	.globl _SM0
	.globl _P1_7
	.globl _P1_6
	.globl _P1_5
	.globl _P1_4
	.globl _P1_3
	.globl _P1_2
	.globl _P1_1
	.globl _P1_0
	.globl _RXD
	.globl _TXD
	.globl _INT0
	.globl _INT1
	.globl _T0
	.globl _T1
	.globl _WR
	.globl _RD
	.globl _PX0
	.globl _PT0
	.globl _PX1
	.globl _PT1
	.globl _PS
	.globl _EX0
	.globl _ET0
	.globl _EX1
	.globl _ET1
	.globl _ES
	.globl _EA
	.globl _IT0
	.globl _IE0
	.globl _IT1
	.globl _IE1
	.globl _TR0
	.globl _TF0
	.globl _TR1
	.globl _TF1
	.globl _P
	.globl _OV
	.globl _RS0
	.globl _RS1
	.globl _F0
	.globl _AC
	.globl _CY
	.globl _FL
	.globl _TF2
	.globl _EXF2
	.globl _RCLK
	.globl _TCLK
	.globl _EXEN2
	.globl _TR2
	.globl _C_T2
	.globl _CP_RL2
	.globl _PT2
	.globl _P3_7
	.globl _P3_6
	.globl _P3_5
	.globl _P3_4
	.globl _P3_3
	.globl _P3_2
	.globl _P3_1
	.globl _P3_0
	.globl _ET2
	.globl _P2_7
	.globl _P2_6
	.globl _P2_5
	.globl _P2_4
	.globl _P2_3
	.globl _P2_2
	.globl _P2_1
	.globl _P2_0
	.globl _T2EX
	.globl _T2
	.globl _P0_7
	.globl _P0_6
	.globl _P0_5
	.globl _P0_4
	.globl _P0_3
	.globl _P0_2
	.globl _P0_1
	.globl _P0_0
	.globl _RCAP2L
	.globl _RCAP2H
	.globl _T2CON
	.globl _SBUF
	.globl _SCON
	.globl _IP
	.globl _IE
	.globl _AUXR
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _B
	.globl _ACC
	.globl _PSW
	.globl _P3
	.globl _P2
	.globl _P1
	.globl _P0
	.globl _A
	.globl _TH2
	.globl _TL2
	.globl _T2MOD
	.globl _mm_option
	.globl _ARR_LcdLineNumAddress_U8
	.globl _STK_LCDConfig
	.globl _VAR_LcdTrackCursorPos_U8
	.globl _VAR_LcdTrackLineNum_U8
	.globl _UART_Init
	.globl _UART_SetBaudRate
	.globl _UART_RxChar
	.globl _UART_TxChar
	.globl _UART_TxString
	.globl _UART_TxDecimalNumber
	.globl _UART_TxHexNumber
	.globl _UART_Printf
	.globl _RTC_Init
	.globl _RTC_SetTime
	.globl _RTC_SetDate
	.globl _RTC_GetTime
	.globl _RTC_GetDate
	.globl _I2C_Init
	.globl _I2C_Start
	.globl _I2C_Stop
	.globl _I2C_Write
	.globl _I2C_Read
	.globl _LCD_Init
	.globl _LCD_Clear
	.globl _LCD_GoToLine
	.globl _LCD_GoToNextLine
	.globl _LCD_CmdWrite
	.globl _LCD_DisplayChar
	.globl _LCD_DisplayString
	.globl _DELAY_us
	.globl _DELAY_ms
	.globl _DELAY_sec
	.globl _ADC_Init
	.globl _ADC_GetAdcValue
	.globl _KEYPAD_Init
	.globl _KEYPAD_WaitForKeyRelease
	.globl _KEYPAD_WaitForKeyPress
	.globl _KEYPAD_GetKey
	.globl _EEPROM_WriteByte
	.globl _EEPROM_ReadByte
	.globl _EEPROM_WriteString
	.globl _EEPROM_ReadString
	.globl _gpio_test
	.globl _LCD_test
	.globl _seg_test
	.globl _rtc_test
	.globl _eeprom_test
	.globl _adc_test
	.globl _keypad_test
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_T2MOD	=	0x00c9
_TL2	=	0x00cc
_TH2	=	0x00cd
_A	=	0x00e0
_P0	=	0x0080
_P1	=	0x0090
_P2	=	0x00a0
_P3	=	0x00b0
_PSW	=	0x00d0
_ACC	=	0x00e0
_B	=	0x00f0
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_AUXR	=	0x008e
_IE	=	0x00a8
_IP	=	0x00b8
_SCON	=	0x0098
_SBUF	=	0x0099
_T2CON	=	0x00c8
_RCAP2H	=	0x00cb
_RCAP2L	=	0x00ca
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0_0	=	0x0080
_P0_1	=	0x0081
_P0_2	=	0x0082
_P0_3	=	0x0083
_P0_4	=	0x0084
_P0_5	=	0x0085
_P0_6	=	0x0086
_P0_7	=	0x0087
_T2	=	0x0090
_T2EX	=	0x0091
_P2_0	=	0x00a0
_P2_1	=	0x00a1
_P2_2	=	0x00a2
_P2_3	=	0x00a3
_P2_4	=	0x00a4
_P2_5	=	0x00a5
_P2_6	=	0x00a6
_P2_7	=	0x00a7
_ET2	=	0x00ad
_P3_0	=	0x00b0
_P3_1	=	0x00b1
_P3_2	=	0x00b2
_P3_3	=	0x00b3
_P3_4	=	0x00b4
_P3_5	=	0x00b5
_P3_6	=	0x00b6
_P3_7	=	0x00b7
_PT2	=	0x00bd
_CP_RL2	=	0x00c8
_C_T2	=	0x00c9
_TR2	=	0x00ca
_EXEN2	=	0x00cb
_TCLK	=	0x00cc
_RCLK	=	0x00cd
_EXF2	=	0x00ce
_TF2	=	0x00cf
_FL	=	0x00d1
_CY	=	0x00d7
_AC	=	0x00d6
_F0	=	0x00d5
_RS1	=	0x00d4
_RS0	=	0x00d3
_OV	=	0x00d2
_P	=	0x00d0
_TF1	=	0x008f
_TR1	=	0x008e
_TF0	=	0x008d
_TR0	=	0x008c
_IE1	=	0x008b
_IT1	=	0x008a
_IE0	=	0x0089
_IT0	=	0x0088
_EA	=	0x00af
_ES	=	0x00ac
_ET1	=	0x00ab
_EX1	=	0x00aa
_ET0	=	0x00a9
_EX0	=	0x00a8
_PS	=	0x00bc
_PT1	=	0x00bb
_PX1	=	0x00ba
_PT0	=	0x00b9
_PX0	=	0x00b8
_RD	=	0x00b7
_WR	=	0x00b6
_T1	=	0x00b5
_T0	=	0x00b4
_INT1	=	0x00b3
_INT0	=	0x00b2
_TXD	=	0x00b1
_RXD	=	0x00b0
_P1_0	=	0x0090
_P1_1	=	0x0091
_P1_2	=	0x0092
_P1_3	=	0x0093
_P1_4	=	0x0094
_P1_5	=	0x0095
_P1_6	=	0x0096
_P1_7	=	0x0097
_SM0	=	0x009f
_SM1	=	0x009e
_SM2	=	0x009d
_REN	=	0x009c
_TB8	=	0x009b
_RB8	=	0x009a
_TI	=	0x0099
_RI	=	0x0098
_T2CON_0	=	0x00c8
_T2CON_1	=	0x00c9
_T2CON_2	=	0x00ca
_T2CON_3	=	0x00cb
_T2CON_4	=	0x00cc
_T2CON_5	=	0x00cd
_T2CON_6	=	0x00ce
_T2CON_7	=	0x00cf
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_VAR_LcdTrackLineNum_U8::
	.ds 1
_VAR_LcdTrackCursorPos_U8::
	.ds 1
_STK_LCDConfig::
	.ds 3
_ARR_LcdLineNumAddress_U8::
	.ds 5
_mm_option::
	.ds 1
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
	.area OSEG    (OVR,DATA)
;--------------------------------------------------------
; Stack segment in internal ram 
;--------------------------------------------------------
	.area	SSEG	(DATA)
__start__stack:
	.ds	1

;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; interrupt vector 
;--------------------------------------------------------
	.area HOME    (CODE)
__interrupt_vect:
	ljmp	__sdcc_gsinit_startup
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
	.globl __sdcc_gsinit_startup
	.globl __sdcc_program_startup
	.globl __start__stack
	.globl __mcs51_genXINIT
	.globl __mcs51_genXRAMCLEAR
	.globl __mcs51_genRAMCLEAR
;	D:\Workspace\MIDE\firmware\/lcd.c:79: uint8_t ARR_LcdLineNumAddress_U8[]={0x80,0x80,0xc0,0x90,0xd0};
	mov	_ARR_LcdLineNumAddress_U8,#0x80
	mov	(_ARR_LcdLineNumAddress_U8 + 0x0001),#0x80
	mov	(_ARR_LcdLineNumAddress_U8 + 0x0002),#0xC0
	mov	(_ARR_LcdLineNumAddress_U8 + 0x0003),#0x90
	mov	(_ARR_LcdLineNumAddress_U8 + 0x0004),#0xD0
	.area GSFINAL (CODE)
	ljmp	__sdcc_program_startup
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
__sdcc_program_startup:
	lcall	_main
;	return from main will lock up
	sjmp .
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_Init'
;------------------------------------------------------------
;var_baudRate_u32          Allocated to registers r2 r3 r4 r5 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/uart.c:59: void UART_Init(uint32_t var_baudRate_u32)
;	-----------------------------------------
;	 function UART_Init
;	-----------------------------------------
_UART_Init:
	ar2 = 0x02
	ar3 = 0x03
	ar4 = 0x04
	ar5 = 0x05
	ar6 = 0x06
	ar7 = 0x07
	ar0 = 0x00
	ar1 = 0x01
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
;	D:\Workspace\MIDE\firmware\/uart.c:61: TMOD |= 0x20; //Timer1 in Mode2.
	orl	_TMOD,#0x20
;	D:\Workspace\MIDE\firmware\/uart.c:62: SCON=0x50;    // Asynchronous mode, 8-bit data and 1-stop bit
	mov	_SCON,#0x50
;	D:\Workspace\MIDE\firmware\/uart.c:63: TR1=1;        //Turn ON the timer for Baud rate generation
	setb	_TR1
;	D:\Workspace\MIDE\firmware\/uart.c:64: UART_SetBaudRate(var_baudRate_u32);
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	ljmp	_UART_SetBaudRate
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_SetBaudRate'
;------------------------------------------------------------
;var_baudRate_u32          Allocated to registers r2 r3 r4 r5 
;RegValue                  Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/uart.c:84: void UART_SetBaudRate(uint32_t var_baudRate_u32)
;	-----------------------------------------
;	 function UART_SetBaudRate
;	-----------------------------------------
_UART_SetBaudRate:
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
;	D:\Workspace\MIDE\firmware\/uart.c:88: if((var_baudRate_u32 >= C_MinBaudRate_U32) && (var_baudRate_u32<=C_MaxBaudRate_U32))
	clr	c
	mov	a,r2
	subb	a,#0x60
	mov	a,r3
	subb	a,#0x09
	mov	a,r4
	subb	a,#0x00
	mov	a,r5
	subb	a,#0x00
	jc	00102$
	clr	a
	subb	a,r2
	mov	a,#0xC2
	subb	a,r3
	mov	a,#0x01
	subb	a,r4
	clr	a
	subb	a,r5
	jc	00102$
;	D:\Workspace\MIDE\firmware\/uart.c:92: RegValue = M_GetBaudRateGeneratorValue(var_baudRate_u32);
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	dptr,#0x0180
	clr	a
	mov	b,a
	lcall	__mullong
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	dptr,#0xC000
	mov	b,#0xA8
	clr	a
	lcall	__divulong
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
	mov	r5,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	clr	c
	clr	a
	subb	a,r2
	mov	r2,a
	sjmp	00103$
00102$:
;	D:\Workspace\MIDE\firmware\/uart.c:97: RegValue = M_GetBaudRateGeneratorValue(9600);
	mov	r2,#0x5D
00103$:
;	D:\Workspace\MIDE\firmware\/uart.c:100: TH1 = RegValue; 
	mov	_TH1,r2
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_RxChar'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/uart.c:116: char UART_RxChar()
;	-----------------------------------------
;	 function UART_RxChar
;	-----------------------------------------
_UART_RxChar:
;	D:\Workspace\MIDE\firmware\/uart.c:118: while(RI==0);	  // Wait till the data is received
00101$:
;	D:\Workspace\MIDE\firmware\/uart.c:119: RI=0;             // Clear Receive Interrupt Flag for next cycle
	jbc	_RI,00108$
	sjmp	00101$
00108$:
;	D:\Workspace\MIDE\firmware\/uart.c:121: return(SBUF);	  // return the received char
	mov	dpl,_SBUF
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_TxChar'
;------------------------------------------------------------
;var_uartData_u8           Allocated to registers 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/uart.c:139: void UART_TxChar(char var_uartData_u8)
;	-----------------------------------------
;	 function UART_TxChar
;	-----------------------------------------
_UART_TxChar:
	mov	_SBUF,dpl
;	D:\Workspace\MIDE\firmware\/uart.c:142: while(TI==0);       // Wait till the data is trasmitted
00101$:
;	D:\Workspace\MIDE\firmware\/uart.c:143: TI=0;		        //Clear the Tx flag for next cycle.
	jbc	_TI,00108$
	sjmp	00101$
00108$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_TxString'
;------------------------------------------------------------
;ptr_stringPointer_u8      Allocated to registers r2 r3 r4 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/uart.c:163: void UART_TxString(char *ptr_stringPointer_u8)
;	-----------------------------------------
;	 function UART_TxString
;	-----------------------------------------
_UART_TxString:
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	D:\Workspace\MIDE\firmware\/uart.c:165: while(*ptr_stringPointer_u8)
00101$:
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	jz	00104$
;	D:\Workspace\MIDE\firmware\/uart.c:166: UART_TxChar(*ptr_stringPointer_u8++);// Loop through the string and transmit char by char
	inc	r2
	cjne	r2,#0x00,00110$
	inc	r3
00110$:
	mov	dpl,r5
	push	ar2
	push	ar3
	push	ar4
	lcall	_UART_TxChar
	pop	ar4
	pop	ar3
	pop	ar2
	sjmp	00101$
00104$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_TxDecimalNumber'
;------------------------------------------------------------
;var_numOfDigitsToTransmit_u8 Allocated to stack - offset -3
;var_decNumber_u32         Allocated to stack - offset 1
;i                         Allocated to registers r2 
;a                         Allocated to stack - offset 5
;sloc0                     Allocated to stack - offset 16
;sloc1                     Allocated to stack - offset 17
;sloc2                     Allocated to stack - offset 15
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/uart.c:231: void UART_TxDecimalNumber(uint32_t var_decNumber_u32, uint8_t var_numOfDigitsToTransmit_u8)
;	-----------------------------------------
;	 function UART_TxDecimalNumber
;	-----------------------------------------
_UART_TxDecimalNumber:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	push	acc
	mov	a,sp
	add	a,#0x12
	mov	sp,a
;	D:\Workspace\MIDE\firmware\/uart.c:235: if(var_decNumber_u32==0)
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	inc	r0
	orl	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00133$
;	D:\Workspace\MIDE\firmware\/uart.c:238: for(i=0;((i<var_numOfDigitsToTransmit_u8) && (i<C_MaxDigitsToTransmit_U8)) ;i++)
	mov	a,_bp
	add	a,#0x05
	mov	r6,a
	mov	r2,#0x00
00119$:
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	clr	c
	mov	a,r2
	subb	a,@r0
	jc	00139$
	ljmp	00136$
00139$:
	push	ar6
	mov	ar6,r2
	mov	r7,#0x00
	clr	c
	mov	a,r6
	subb	a,#0x0A
	mov	a,r7
	subb	a,#0x00
	pop	ar6
	jc	00140$
	ljmp	00136$
00140$:
;	D:\Workspace\MIDE\firmware\/uart.c:239: a[i] = 0x00;
	mov	a,r2
	add	a,r6
	mov	r0,a
	mov	@r0,#0x00
;	D:\Workspace\MIDE\firmware\/uart.c:238: for(i=0;((i<var_numOfDigitsToTransmit_u8) && (i<C_MaxDigitsToTransmit_U8)) ;i++)
	inc	r2
;	D:\Workspace\MIDE\firmware\/uart.c:243: for(i=0;i<var_numOfDigitsToTransmit_u8;i++)
	sjmp	00119$
00133$:
	mov	a,_bp
	add	a,#0x05
	mov	r4,a
	mov	r5,#0x00
00108$:
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	clr	c
	mov	a,r5
	subb	a,@r0
	jc	00141$
	ljmp	00137$
00141$:
;	D:\Workspace\MIDE\firmware\/uart.c:247: if(var_decNumber_u32!=0)
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	inc	r0
	orl	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00142$
	ljmp	00106$
00142$:
;	D:\Workspace\MIDE\firmware\/uart.c:253: a[i]=util_GetMod32(var_decNumber_u32,10);
	mov	a,r5
	add	a,r4
	mov	r0,a
	push	ar4
	push	ar5
	push	ar0
	mov	a,#0x0A
	push	acc
	clr	a
	push	acc
	push	acc
	push	acc
	mov	r1,_bp
	inc	r1
	mov	dpl,@r1
	inc	r1
	mov	dph,@r1
	inc	r1
	mov	b,@r1
	inc	r1
	mov	a,@r1
	lcall	__divulong
	xch	a,r1
	mov	a,_bp
	add	a,#0x0f
	xch	a,r1
	mov	@r1,dpl
	inc	r1
	mov	@r1,dph
	inc	r1
	mov	@r1,b
	inc	r1
	mov	@r1,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	mov	a,_bp
	add	a,#0x0f
	mov	r1,a
	mov	a,@r1
	push	acc
	inc	r1
	mov	a,@r1
	push	acc
	inc	r1
	mov	a,@r1
	push	acc
	inc	r1
	mov	a,@r1
	push	acc
	mov	dptr,#(0x0A&0x00ff)
	clr	a
	mov	b,a
	lcall	__mullong
	mov	r7,dpl
	mov	r6,dph
	mov	r2,b
	mov	r3,a
	mov	a,sp
	add	a,#0xfc
	mov	sp,a
	pop	ar0
	pop	ar5
	pop	ar4
	mov	r1,_bp
	inc	r1
	mov	a,@r1
	clr	c
	subb	a,r7
	mov	r7,a
	inc	r1
	mov	a,@r1
	subb	a,r6
	mov	r6,a
	inc	r1
	mov	a,@r1
	subb	a,r2
	mov	r2,a
	inc	r1
	mov	a,@r1
	subb	a,r3
	mov	r3,a
	mov	@r0,ar7
;	D:\Workspace\MIDE\firmware\/uart.c:254: var_decNumber_u32=var_decNumber_u32/10;
	mov	a,_bp
	add	a,#0x0f
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	a,@r0
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	inc	r0
	inc	r1
	mov	a,@r0
	mov	@r1,a
	sjmp	00110$
00106$:
;	D:\Workspace\MIDE\firmware\/uart.c:256: else if( (var_numOfDigitsToTransmit_u8 == C_DefaultDigitsToTransmit_U8) ||
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	ar2,@r0
	mov	r3,#0x00
	cjne	r2,#0xFF,00143$
	cjne	r3,#0x00,00143$
	sjmp	00137$
00143$:
;	D:\Workspace\MIDE\firmware\/uart.c:257: (var_numOfDigitsToTransmit_u8 > C_MaxDigitsToTransmit_U8))
	clr	c
	mov	a,#0x0A
	subb	a,r2
	clr	a
	subb	a,r3
	jc	00137$
;	D:\Workspace\MIDE\firmware\/uart.c:268: a[i]=0;
	mov	a,r5
	add	a,r4
	mov	r0,a
	mov	@r0,#0x00
00110$:
;	D:\Workspace\MIDE\firmware\/uart.c:243: for(i=0;i<var_numOfDigitsToTransmit_u8;i++)
	inc	r5
	ljmp	00108$
;	D:\Workspace\MIDE\firmware\/uart.c:273: while(i)
00136$:
;	D:\Workspace\MIDE\firmware\/uart.c:277: i--;
;	D:\Workspace\MIDE\firmware\/uart.c:273: while(i)
	sjmp	00135$
00137$:
	mov	ar2,r5
00135$:
	mov	a,_bp
	add	a,#0x05
	mov	r3,a
00115$:
	mov	a,r2
	jz	00123$
;	D:\Workspace\MIDE\firmware\/uart.c:276: UART_TxChar(util_Dec2Ascii(a[i-1]));
	mov	a,r2
	dec	a
	mov	r4,a
	add	a,r3
	mov	r0,a
	mov	ar5,@r0
	mov	a,#0x30
	add	a,r5
	mov	dpl,a
	push	ar3
	push	ar4
	lcall	_UART_TxChar
	pop	ar4
	pop	ar3
;	D:\Workspace\MIDE\firmware\/uart.c:277: i--;
	mov	ar2,r4
	sjmp	00115$
00123$:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_TxHexNumber'
;------------------------------------------------------------
;var_numOfDigitsToTransmit_u8 Allocated to stack - offset -3
;var_hexNumber_u32         Allocated to stack - offset 1
;i                         Allocated to registers r2 
;a                         Allocated to stack - offset 5
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/uart.c:303: void UART_TxHexNumber(uint32_t var_hexNumber_u32,uint8_t var_numOfDigitsToTransmit_u8)
;	-----------------------------------------
;	 function UART_TxHexNumber
;	-----------------------------------------
_UART_TxHexNumber:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
	push	acc
	mov	a,sp
	add	a,#0x0e
	mov	sp,a
;	D:\Workspace\MIDE\firmware\/uart.c:307: if(var_hexNumber_u32==0)
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	inc	r0
	orl	a,@r0
	inc	r0
	orl	a,@r0
	jnz	00135$
;	D:\Workspace\MIDE\firmware\/uart.c:310: for(i=0;((i<var_numOfDigitsToTransmit_u8) && (i<C_MaxDigitsToTransmit_U8)) ;i++)
	mov	a,_bp
	add	a,#0x05
	mov	r6,a
	mov	r2,#0x00
00119$:
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	clr	c
	mov	a,r2
	subb	a,@r0
	jc	00143$
	ljmp	00139$
00143$:
	push	ar6
	mov	ar6,r2
	mov	r7,#0x00
	clr	c
	mov	a,r6
	subb	a,#0x0A
	mov	a,r7
	subb	a,#0x00
	pop	ar6
	jc	00144$
	ljmp	00139$
00144$:
;	D:\Workspace\MIDE\firmware\/uart.c:311: a[i]=0x00;
	mov	a,r2
	add	a,r6
	mov	r0,a
	mov	@r0,#0x00
;	D:\Workspace\MIDE\firmware\/uart.c:310: for(i=0;((i<var_numOfDigitsToTransmit_u8) && (i<C_MaxDigitsToTransmit_U8)) ;i++)
	inc	r2
;	D:\Workspace\MIDE\firmware\/uart.c:315: for(i=0;i<var_numOfDigitsToTransmit_u8;i++)
	sjmp	00119$
00135$:
	mov	a,_bp
	add	a,#0x05
	mov	r6,a
	mov	r7,#0x00
00108$:
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	clr	c
	mov	a,r7
	subb	a,@r0
	jc	00145$
	ljmp	00140$
00145$:
;	D:\Workspace\MIDE\firmware\/uart.c:318: if(var_hexNumber_u32!=0)
	mov	r0,_bp
	inc	r0
	mov	a,@r0
	inc	r0
	orl	a,@r0
	inc	r0
	orl	a,@r0
	inc	r0
	orl	a,@r0
	jz	00106$
;	D:\Workspace\MIDE\firmware\/uart.c:324: a[i]=(uint8_t)(var_hexNumber_u32 & 0x0f);
	mov	a,r7
	add	a,r6
	mov	r0,a
	push	ar6
	mov	r1,_bp
	inc	r1
	mov	a,#0x0F
	anl	a,@r1
	mov	r6,a
	mov	r2,#0x00
	mov	r3,#0x00
	mov	r4,#0x00
	mov	@r0,ar6
;	D:\Workspace\MIDE\firmware\/uart.c:325: var_hexNumber_u32=var_hexNumber_u32 >> 4;
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,@r0
	dec	r0
	swap	a
	xch	a,@r0
	swap	a
	anl	a,#0x0f
	xrl	a,@r0
	xch	a,@r0
	anl	a,#0x0f
	xch	a,@r0
	xrl	a,@r0
	xch	a,@r0
	inc	r0
	mov	@r0,a
	inc	r0
	mov	a,@r0
	swap	a
	anl	a,#0xf0
	dec	r0
	orl	a,@r0
	mov	@r0,a
	inc	r0
	inc	r0
	mov	a,@r0
	dec	r0
	swap	a
	xch	a,@r0
	swap	a
	anl	a,#0x0f
	xrl	a,@r0
	xch	a,@r0
	anl	a,#0x0f
	xch	a,@r0
	xrl	a,@r0
	xch	a,@r0
	inc	r0
	mov	@r0,a
	pop	ar6
	sjmp	00110$
00106$:
;	D:\Workspace\MIDE\firmware\/uart.c:327: else if( (var_numOfDigitsToTransmit_u8 == C_DefaultDigitsToTransmit_U8) ||
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	ar2,@r0
	mov	r3,#0x00
	cjne	r2,#0xFF,00147$
	cjne	r3,#0x00,00147$
	sjmp	00140$
00147$:
;	D:\Workspace\MIDE\firmware\/uart.c:328: (var_numOfDigitsToTransmit_u8 > C_MaxDigitsToTransmit_U8))
	clr	c
	mov	a,#0x0A
	subb	a,r2
	clr	a
	subb	a,r3
	jc	00140$
;	D:\Workspace\MIDE\firmware\/uart.c:339: a[i]=0x00;
	mov	a,r7
	add	a,r6
	mov	r0,a
	mov	@r0,#0x00
00110$:
;	D:\Workspace\MIDE\firmware\/uart.c:315: for(i=0;i<var_numOfDigitsToTransmit_u8;i++)
	inc	r7
	ljmp	00108$
;	D:\Workspace\MIDE\firmware\/uart.c:344: while(i!=0)
00139$:
;	D:\Workspace\MIDE\firmware\/uart.c:348: i--;
;	D:\Workspace\MIDE\firmware\/uart.c:344: while(i!=0)
	sjmp	00138$
00140$:
	mov	ar2,r7
00138$:
	mov	a,_bp
	add	a,#0x05
	mov	r3,a
00115$:
	mov	a,r2
	jz	00123$
;	D:\Workspace\MIDE\firmware\/uart.c:347: UART_TxChar(util_Hex2Ascii(a[i-1]));
	mov	a,r2
	dec	a
	add	a,r3
	mov	r0,a
	mov	ar4,@r0
	mov	a,#0x09
	cjne	a,ar4,00150$
00150$:
	jnc	00125$
	mov	a,r2
	dec	a
	add	a,r3
	mov	r0,a
	mov	ar4,@r0
	mov	a,#0x37
	add	a,r4
	mov	r4,a
	sjmp	00126$
00125$:
	mov	a,r2
	dec	a
	add	a,r3
	mov	r0,a
	mov	ar5,@r0
	mov	a,#0x30
	add	a,r5
	mov	r4,a
00126$:
	mov	dpl,r4
	push	ar2
	push	ar3
	lcall	_UART_TxChar
	pop	ar3
	pop	ar2
;	D:\Workspace\MIDE\firmware\/uart.c:348: i--;
	dec	r2
	sjmp	00115$
00123$:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'UART_Printf'
;------------------------------------------------------------
;argList                   Allocated to stack - offset -5
;ptr                       Allocated to registers r3 r4 r5 
;var_floatNum_f32          Allocated to registers 
;argp                      Allocated to stack - offset 1
;var_num_s16               Allocated to registers r2 r6 
;var_num_s32               Allocated to stack - offset 2
;var_num_u16               Allocated to registers r2 r6 
;var_num_u32               Allocated to stack - offset 6
;str                       Allocated to registers r2 r6 r7 
;ch                        Allocated to stack - offset 10
;var_numOfDigitsToTransmit_u8 Allocated to stack - offset 11
;sloc0                     Allocated to stack - offset 12
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/uart.c:468: void UART_Printf(const char *argList, ...)
;	-----------------------------------------
;	 function UART_Printf
;	-----------------------------------------
_UART_Printf:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x0e
	mov	sp,a
;	D:\Workspace\MIDE\firmware\/uart.c:481: va_start(argp, argList);
	mov	a,_bp
	add	a,#0xfb
	mov	r2,a
	mov	r0,_bp
	inc	r0
	mov	@r0,ar2
;	D:\Workspace\MIDE\firmware\/uart.c:484: for(ptr = argList; *ptr != '\0'; ptr++)
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
00132$:
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r6,a
	cjne	r6,#0x00,00164$
	ljmp	00136$
00164$:
;	D:\Workspace\MIDE\firmware\/uart.c:487: ch= *ptr;
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	@r0,ar6
;	D:\Workspace\MIDE\firmware\/uart.c:488: if(ch == '%')         /*Check for '%' as there will be format specifier after it */
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x25,00165$
	sjmp	00166$
00165$:
	ljmp	00130$
00166$:
;	D:\Workspace\MIDE\firmware\/uart.c:490: ptr++;
	inc	r3
	cjne	r3,#0x00,00167$
	inc	r4
00167$:
;	D:\Workspace\MIDE\firmware\/uart.c:491: ch = *ptr;
	mov	dpl,r3
	mov	dph,r4
	mov	b,r5
	lcall	__gptrget
	mov	r7,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	@r0,ar7
;	D:\Workspace\MIDE\firmware\/uart.c:492: if((ch>=0x30) && (ch<=0x39))
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	clr	c
	mov	a,@r0
	xrl	a,#0x80
	subb	a,#0xb0
	jnc	00168$
	ljmp	00106$
00168$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	clr	c
	mov	a,#(0x39 ^ 0x80)
	mov	b,@r0
	xrl	b,#0x80
	subb	a,b
	jnc	00169$
	ljmp	00106$
00169$:
;	D:\Workspace\MIDE\firmware\/uart.c:494: var_numOfDigitsToTransmit_u8 = 0;
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	@r0,#0x00
;	D:\Workspace\MIDE\firmware\/uart.c:495: while((ch>=0x30) && (ch<=0x39))
	mov	a,_bp
	add	a,#0x0c
	mov	r0,a
	mov	@r0,ar3
	inc	r0
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
00102$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	clr	c
	mov	a,@r0
	xrl	a,#0x80
	subb	a,#0xb0
	jc	00163$
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	clr	c
	mov	a,#(0x39 ^ 0x80)
	mov	b,@r0
	xrl	b,#0x80
	subb	a,b
	jc	00163$
;	D:\Workspace\MIDE\firmware\/uart.c:497: var_numOfDigitsToTransmit_u8 = (var_numOfDigitsToTransmit_u8 * 10) + (ch-0x30);
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	a,@r0
	mov	b,#0x0A
	mul	ab
	mov	r2,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	a,@r0
	add	a,#0xd0
	add	a,r2
	mov	r2,a
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	@r0,ar2
;	D:\Workspace\MIDE\firmware\/uart.c:498: ptr++;
	mov	a,_bp
	add	a,#0x0c
	mov	r0,a
	inc	@r0
	cjne	@r0,#0x00,00172$
	inc	r0
	inc	@r0
00172$:
;	D:\Workspace\MIDE\firmware\/uart.c:499: ch = *ptr;
	mov	a,_bp
	add	a,#0x0c
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	lcall	__gptrget
	mov	r2,a
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	@r0,ar2
	sjmp	00102$
00106$:
;	D:\Workspace\MIDE\firmware\/uart.c:504: var_numOfDigitsToTransmit_u8 = C_MaxDigitsToTransmitUsingPrintf_U8;
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	@r0,#0xFF
;	D:\Workspace\MIDE\firmware\/uart.c:617: va_end(argp);
;	D:\Workspace\MIDE\firmware\/uart.c:504: var_numOfDigitsToTransmit_u8 = C_MaxDigitsToTransmitUsingPrintf_U8;
	sjmp	00107$
00163$:
	mov	a,_bp
	add	a,#0x0c
	mov	r0,a
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
00107$:
;	D:\Workspace\MIDE\firmware\/uart.c:508: switch(ch)       /* Decode the type of the argument */
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x25,00173$
	ljmp	00127$
00173$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x42,00174$
	ljmp	00122$
00174$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x43,00175$
	ljmp	00110$
00175$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x44,00176$
	ljmp	00114$
00176$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x46,00177$
	ljmp	00124$
00177$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x53,00178$
	ljmp	00126$
00178$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x55,00179$
	ljmp	00118$
00179$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x58,00180$
	ljmp	00120$
00180$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x62,00181$
	ljmp	00121$
00181$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x63,00182$
	sjmp	00110$
00182$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x64,00183$
	sjmp	00111$
00183$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x66,00184$
	ljmp	00124$
00184$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x73,00185$
	ljmp	00126$
00185$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x75,00186$
	ljmp	00117$
00186$:
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	cjne	@r0,#0x78,00187$
	ljmp	00119$
00187$:
	ljmp	00134$
;	D:\Workspace\MIDE\firmware\/uart.c:511: case 'c':     /* Argument type is of char, hence read char data from the argp */
00110$:
;	D:\Workspace\MIDE\firmware\/uart.c:512: ch = va_arg(argp, uint16_t);
	mov	r1,_bp
	inc	r1
	mov	a,@r1
	add	a,#0xfe
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	@r1,ar0
	mov	ar2,@r0
	inc	r0
	mov	ar6,@r0
	dec	r0
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	@r0,ar2
;	D:\Workspace\MIDE\firmware\/uart.c:513: UART_TxChar(ch);
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	push	ar3
	push	ar4
	push	ar5
	lcall	_UART_TxChar
	pop	ar5
	pop	ar4
	pop	ar3
;	D:\Workspace\MIDE\firmware\/uart.c:514: break;
	ljmp	00134$
;	D:\Workspace\MIDE\firmware\/uart.c:516: case 'd':    /* Argument type is of signed integer, hence read 16bit data from the argp */
00111$:
;	D:\Workspace\MIDE\firmware\/uart.c:517: var_num_s16 = va_arg(argp, sint16_t);
	mov	r1,_bp
	inc	r1
	mov	a,@r1
	add	a,#0xfe
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	@r1,ar0
	mov	ar2,@r0
	inc	r0
	mov	ar6,@r0
	dec	r0
;	D:\Workspace\MIDE\firmware\/uart.c:519: if(var_num_s16<0)
	mov	a,r6
	jnb	acc.7,00113$
;	D:\Workspace\MIDE\firmware\/uart.c:521: var_num_s16 = -var_num_s16;
	clr	c
	clr	a
	subb	a,r2
	mov	r2,a
	clr	a
	subb	a,r6
	mov	r6,a
;	D:\Workspace\MIDE\firmware\/uart.c:522: UART_TxChar('-');
	mov	dpl,#0x2D
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	lcall	_UART_TxChar
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
00113$:
;	D:\Workspace\MIDE\firmware\/uart.c:524: UART_TxDecimalNumber(var_num_s16,var_numOfDigitsToTransmit_u8);
	push	ar3
	push	ar4
	push	ar5
	mov	a,r6
	rlc	a
	subb	a,acc
	mov	r7,a
	mov	r3,a
	push	ar3
	push	ar4
	push	ar5
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	dpl,r2
	mov	dph,r6
	mov	b,r7
	mov	a,r3
	lcall	_UART_TxDecimalNumber
	dec	sp
	pop	ar5
	pop	ar4
	pop	ar3
;	D:\Workspace\MIDE\firmware\/uart.c:526: break;
	pop	ar5
	pop	ar4
	pop	ar3
	ljmp	00134$
;	D:\Workspace\MIDE\firmware\/uart.c:528: case 'D':    /* Argument type is of integer, hence read 16bit data from the argp */
00114$:
;	D:\Workspace\MIDE\firmware\/uart.c:529: var_num_s32 = va_arg(argp, sint32_t);
	mov	r1,_bp
	inc	r1
	mov	a,@r1
	add	a,#0xfc
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	@r1,ar0
	mov	r1,_bp
	inc	r1
	inc	r1
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	dec	r0
	dec	r0
	dec	r0
	mov	r0,_bp
	inc	r0
	inc	r0
;	D:\Workspace\MIDE\firmware\/uart.c:531: if(var_num_s32<0)
	mov	r0,_bp
	inc	r0
	inc	r0
	inc	r0
	inc	r0
	inc	r0
	mov	a,@r0
	jnb	acc.7,00116$
;	D:\Workspace\MIDE\firmware\/uart.c:533: var_num_s32 = -var_num_s32;
	mov	r0,_bp
	inc	r0
	inc	r0
	clr	c
	clr	a
	subb	a,@r0
	mov	@r0,a
	inc	r0
	clr	a
	subb	a,@r0
	mov	@r0,a
	inc	r0
	clr	a
	subb	a,@r0
	mov	@r0,a
	inc	r0
	clr	a
	subb	a,@r0
	mov	@r0,a
;	D:\Workspace\MIDE\firmware\/uart.c:534: UART_TxChar('-');
	mov	dpl,#0x2D
	push	ar3
	push	ar4
	push	ar5
	lcall	_UART_TxChar
	pop	ar5
	pop	ar4
	pop	ar3
00116$:
;	D:\Workspace\MIDE\firmware\/uart.c:536: UART_TxDecimalNumber(var_num_s32,var_numOfDigitsToTransmit_u8);
	push	ar3
	push	ar4
	push	ar5
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	_UART_TxDecimalNumber
	dec	sp
	pop	ar5
	pop	ar4
	pop	ar3
;	D:\Workspace\MIDE\firmware\/uart.c:538: break;	
	ljmp	00134$
;	D:\Workspace\MIDE\firmware\/uart.c:540: case 'u':    /* Argument type is of unsigned integer, hence read 16bit unsigned data */
00117$:
;	D:\Workspace\MIDE\firmware\/uart.c:541: var_num_u16 = va_arg(argp, uint16_t);
	push	ar3
	push	ar4
	push	ar5
	mov	r1,_bp
	inc	r1
	mov	a,@r1
	add	a,#0xfe
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	@r1,ar0
	mov	ar2,@r0
	inc	r0
	mov	ar6,@r0
	dec	r0
;	D:\Workspace\MIDE\firmware\/uart.c:543: UART_TxDecimalNumber(var_num_u16,var_numOfDigitsToTransmit_u8);
	mov	ar7,r2
	mov	ar3,r6
	mov	r4,#0x00
	mov	r5,#0x00
	push	ar3
	push	ar4
	push	ar5
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	dpl,r7
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	lcall	_UART_TxDecimalNumber
	dec	sp
	pop	ar5
	pop	ar4
	pop	ar3
;	D:\Workspace\MIDE\firmware\/uart.c:545: break;
	pop	ar5
	pop	ar4
	pop	ar3
	ljmp	00134$
;	D:\Workspace\MIDE\firmware\/uart.c:547: case 'U':    /* Argument type is of integer, hence read 32bit unsigend data */
00118$:
;	D:\Workspace\MIDE\firmware\/uart.c:548: var_num_u32 = va_arg(argp, uint32_t);
	mov	r1,_bp
	inc	r1
	mov	a,@r1
	add	a,#0xfc
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	@r1,ar0
	mov	a,_bp
	add	a,#0x06
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	inc	r0
	mov	a,@r0
	inc	r1
	mov	@r1,a
	dec	r0
	dec	r0
	dec	r0
	mov	a,_bp
	add	a,#0x06
;	D:\Workspace\MIDE\firmware\/uart.c:550: UART_TxDecimalNumber(var_num_u32,var_numOfDigitsToTransmit_u8);
	push	ar3
	push	ar4
	push	ar5
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	_UART_TxDecimalNumber
	dec	sp
	pop	ar5
	pop	ar4
	pop	ar3
;	D:\Workspace\MIDE\firmware\/uart.c:552: break;			
	ljmp	00134$
;	D:\Workspace\MIDE\firmware\/uart.c:554: case 'x':  /* Argument type is of hex, hence hexadecimal data from the argp */
00119$:
;	D:\Workspace\MIDE\firmware\/uart.c:555: var_num_u16 = va_arg(argp, uint16_t);
	push	ar3
	push	ar4
	push	ar5
	mov	r1,_bp
	inc	r1
	mov	a,@r1
	add	a,#0xfe
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	@r1,ar0
	mov	ar7,@r0
	inc	r0
	mov	ar3,@r0
	dec	r0
	mov	ar2,r7
	mov	ar6,r3
;	D:\Workspace\MIDE\firmware\/uart.c:557: UART_TxHexNumber(var_num_u16,var_numOfDigitsToTransmit_u8);
	mov	r3,#0x00
	mov	r4,#0x00
	push	ar3
	push	ar4
	push	ar5
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	dpl,r2
	mov	dph,r6
	mov	b,r3
	mov	a,r4
	lcall	_UART_TxHexNumber
	dec	sp
	pop	ar5
	pop	ar4
	pop	ar3
;	D:\Workspace\MIDE\firmware\/uart.c:559: break;
	pop	ar5
	pop	ar4
	pop	ar3
	ljmp	00134$
;	D:\Workspace\MIDE\firmware\/uart.c:561: case 'X':  /* Argument type is of hex, hence hexadecimal data from the argp */
00120$:
;	D:\Workspace\MIDE\firmware\/uart.c:562: var_num_u32 = va_arg(argp, uint32_t);
	push	ar3
	push	ar4
	push	ar5
	mov	r1,_bp
	inc	r1
	mov	a,@r1
	add	a,#0xfc
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	@r1,ar0
	mov	ar2,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	inc	r0
	mov	ar3,@r0
	dec	r0
	dec	r0
	dec	r0
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar6
	inc	r0
	mov	@r0,ar7
	inc	r0
	mov	@r0,ar3
;	D:\Workspace\MIDE\firmware\/uart.c:564: UART_TxHexNumber(var_num_u32,var_numOfDigitsToTransmit_u8);
	push	ar3
	push	ar4
	push	ar5
	mov	a,_bp
	add	a,#0x0b
	mov	r0,a
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	inc	r0
	mov	a,@r0
	lcall	_UART_TxHexNumber
	dec	sp
	pop	ar5
	pop	ar4
	pop	ar3
;	D:\Workspace\MIDE\firmware\/uart.c:566: break;
	pop	ar5
	pop	ar4
	pop	ar3
;	D:\Workspace\MIDE\firmware\/uart.c:569: case 'b':  /* Argument type is of binary,Read int and convert to binary */
	sjmp	00134$
00121$:
;	D:\Workspace\MIDE\firmware\/uart.c:570: var_num_u16 = va_arg(argp, uint16_t);
	mov	r0,_bp
	inc	r0
	dec	@r0
	dec	@r0
;	D:\Workspace\MIDE\firmware\/uart.c:576: break;
;	D:\Workspace\MIDE\firmware\/uart.c:578: case 'B':  /* Argument type is of binary,Read int and convert to binary */
	sjmp	00134$
00122$:
;	D:\Workspace\MIDE\firmware\/uart.c:579: var_num_u32 = va_arg(argp, uint32_t);
	mov	r0,_bp
	inc	r0
	dec	@r0
	dec	@r0
	dec	@r0
	dec	@r0
;	D:\Workspace\MIDE\firmware\/uart.c:585: break;
;	D:\Workspace\MIDE\firmware\/uart.c:589: case 'f': /* Argument type is of float, hence read double data from the argp */
	sjmp	00134$
00124$:
;	D:\Workspace\MIDE\firmware\/uart.c:590: var_floatNum_f32 = va_arg(argp, double);
	mov	r0,_bp
	inc	r0
	dec	@r0
	dec	@r0
	dec	@r0
	dec	@r0
;	D:\Workspace\MIDE\firmware\/uart.c:594: break;
;	D:\Workspace\MIDE\firmware\/uart.c:598: case 's': /* Argument type is of string, hence get the pointer to sting passed */
	sjmp	00134$
00126$:
;	D:\Workspace\MIDE\firmware\/uart.c:599: str = va_arg(argp, char *);
	mov	r1,_bp
	inc	r1
	mov	a,@r1
	add	a,#0xfd
	mov	r0,a
	mov	r1,_bp
	inc	r1
	mov	@r1,ar0
	mov	ar2,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	dec	r0
	dec	r0
;	D:\Workspace\MIDE\firmware\/uart.c:601: UART_TxString(str);
	mov	dpl,r2
	mov	dph,r6
	mov	b,r7
	push	ar3
	push	ar4
	push	ar5
	lcall	_UART_TxString
	pop	ar5
	pop	ar4
	pop	ar3
;	D:\Workspace\MIDE\firmware\/uart.c:603: break;
;	D:\Workspace\MIDE\firmware\/uart.c:605: case '%':
	sjmp	00134$
00127$:
;	D:\Workspace\MIDE\firmware\/uart.c:606: UART_TxChar('%');
	mov	dpl,#0x25
	push	ar3
	push	ar4
	push	ar5
	lcall	_UART_TxChar
	pop	ar5
	pop	ar4
	pop	ar3
;	D:\Workspace\MIDE\firmware\/uart.c:608: }
	sjmp	00134$
00130$:
;	D:\Workspace\MIDE\firmware\/uart.c:613: UART_TxChar(ch);
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	dpl,@r0
	push	ar3
	push	ar4
	push	ar5
	lcall	_UART_TxChar
	pop	ar5
	pop	ar4
	pop	ar3
00134$:
;	D:\Workspace\MIDE\firmware\/uart.c:484: for(ptr = argList; *ptr != '\0'; ptr++)
	inc	r3
	cjne	r3,#0x00,00190$
	inc	r4
00190$:
	ljmp	00132$
;	D:\Workspace\MIDE\firmware\/uart.c:617: va_end(argp);
00136$:
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'RTC_Init'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/rtc.c:57: void RTC_Init()
;	-----------------------------------------
;	 function RTC_Init
;	-----------------------------------------
_RTC_Init:
;	D:\Workspace\MIDE\firmware\/rtc.c:59: I2C_Init();                             // Initialize the I2c module.
	lcall	_I2C_Init
;	D:\Workspace\MIDE\firmware\/rtc.c:60: I2C_Start();                            // Start I2C communication
	lcall	_I2C_Start
;	D:\Workspace\MIDE\firmware\/rtc.c:62: I2C_Write(C_Ds1307WriteMode_U8);        // Connect to DS1307 by sending its ID on I2c Bus
	mov	dpl,#0xD0
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:63: I2C_Write(C_Ds1307ControlRegAddress_U8);// Select the Ds1307 ControlRegister to configure Ds1307
	mov	dpl,#0x07
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:65: I2C_Write(0x00);                        // Write 0x00 to Control register to disable SQW-Out
	mov	dpl,#0x00
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:67: I2C_Stop();                             // Stop I2C communication after initializing DS1307
	ljmp	_I2C_Stop
;------------------------------------------------------------
;Allocation info for local variables in function 'RTC_SetTime'
;------------------------------------------------------------
;var_min_u8                Allocated to stack - offset -3
;var_sec_u8                Allocated to stack - offset -4
;var_hour_u8               Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/rtc.c:86: void RTC_SetTime(uint8_t var_hour_u8, uint8_t var_min_u8, uint8_t var_sec_u8)
;	-----------------------------------------
;	 function RTC_SetTime
;	-----------------------------------------
_RTC_SetTime:
	push	_bp
	mov	_bp,sp
	mov	r2,dpl
;	D:\Workspace\MIDE\firmware\/rtc.c:88: I2C_Start();                            // Start I2C communication
	push	ar2
	lcall	_I2C_Start
;	D:\Workspace\MIDE\firmware\/rtc.c:90: I2C_Write(C_Ds1307WriteMode_U8);        // connect to DS1307 by sending its ID on I2c Bus
	mov	dpl,#0xD0
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:91: I2C_Write(C_Ds1307SecondRegAddress_U8); // Select the SEC RAM address
	mov	dpl,#0x00
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:93: I2C_Write(var_sec_u8);			        // Write sec from RAM address 00H
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	dpl,@r0
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:94: I2C_Write(var_min_u8);			        // Write min from RAM address 01H
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	dpl,@r0
	lcall	_I2C_Write
	pop	ar2
;	D:\Workspace\MIDE\firmware\/rtc.c:95: I2C_Write(var_hour_u8);			        // Write hour from RAM address 02H
	mov	dpl,r2
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:97: I2C_Stop();           	                // Stop I2C communication after Setting the Time
	lcall	_I2C_Stop
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'RTC_SetDate'
;------------------------------------------------------------
;var_month_u8              Allocated to stack - offset -3
;var_year_u8               Allocated to stack - offset -4
;var_day_u8                Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/rtc.c:117: void RTC_SetDate(uint8_t var_day_u8, uint8_t var_month_u8, uint8_t var_year_u8)
;	-----------------------------------------
;	 function RTC_SetDate
;	-----------------------------------------
_RTC_SetDate:
	push	_bp
	mov	_bp,sp
	mov	r2,dpl
;	D:\Workspace\MIDE\firmware\/rtc.c:119: I2C_Start();                          // Start I2C communication
	push	ar2
	lcall	_I2C_Start
;	D:\Workspace\MIDE\firmware\/rtc.c:121: I2C_Write(C_Ds1307WriteMode_U8);	  // connect to DS1307 by sending its ID on I2c Bus
	mov	dpl,#0xD0
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:122: I2C_Write(C_Ds1307DateRegAddress_U8); // Request DAY RAM address at 04H
	mov	dpl,#0x04
	lcall	_I2C_Write
	pop	ar2
;	D:\Workspace\MIDE\firmware\/rtc.c:124: I2C_Write(var_day_u8);			      // Write date on RAM address 04H
	mov	dpl,r2
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:125: I2C_Write(var_month_u8);			      // Write month on RAM address 05H
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	dpl,@r0
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:126: I2C_Write(var_year_u8);			      // Write year on RAM address 06h
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	dpl,@r0
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:128: I2C_Stop();				              // Stop I2C communication after Setting the Date
	lcall	_I2C_Stop
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'RTC_GetTime'
;------------------------------------------------------------
;ptr_min_u8                Allocated to stack - offset -5
;ptr_sec_u8                Allocated to stack - offset -8
;ptr_hour_u8               Allocated to stack - offset 1
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/rtc.c:147: void RTC_GetTime(uint8_t *ptr_hour_u8,uint8_t *ptr_min_u8,uint8_t *ptr_sec_u8)
;	-----------------------------------------
;	 function RTC_GetTime
;	-----------------------------------------
_RTC_GetTime:
	push	_bp
	mov	_bp,sp
	push	dpl
	push	dph
	push	b
;	D:\Workspace\MIDE\firmware\/rtc.c:149: I2C_Start();                            // Start I2C communication
	lcall	_I2C_Start
;	D:\Workspace\MIDE\firmware\/rtc.c:151: I2C_Write(C_Ds1307WriteMode_U8);	    // connect to DS1307 by sending its ID on I2c Bus
	mov	dpl,#0xD0
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:152: I2C_Write(C_Ds1307SecondRegAddress_U8); // Request Sec RAM address at 00H
	mov	dpl,#0x00
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:154: I2C_Stop();			                    // Stop I2C communication after selecting Sec Register
	lcall	_I2C_Stop
;	D:\Workspace\MIDE\firmware\/rtc.c:156: I2C_Start();		                    // Start I2C communication
	lcall	_I2C_Start
;	D:\Workspace\MIDE\firmware\/rtc.c:157: I2C_Write(C_Ds1307ReadMode_U8);	        // connect to DS1307(Read mode) by sending its ID
	mov	dpl,#0xD1
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:159: *ptr_sec_u8 = I2C_Read(1);                // read second and return Positive ACK
	mov	a,_bp
	add	a,#0xf8
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	inc	r0
	mov	ar7,@r0
	mov	dpl,#0x01
	push	ar5
	push	ar6
	push	ar7
	lcall	_I2C_Read
	mov	r2,dpl
	pop	ar7
	pop	ar6
	pop	ar5
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	mov	a,r2
	lcall	__gptrput
;	D:\Workspace\MIDE\firmware\/rtc.c:160: *ptr_min_u8 = I2C_Read(1); 	            // read minute and return Positive ACK
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	mov	dpl,#0x01
	push	ar2
	push	ar3
	push	ar4
	lcall	_I2C_Read
	mov	r5,dpl
	pop	ar4
	pop	ar3
	pop	ar2
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	lcall	__gptrput
;	D:\Workspace\MIDE\firmware\/rtc.c:161: *ptr_hour_u8 = I2C_Read(0);               // read hour and return Negative/No ACK
	mov	dpl,#0x00
	lcall	_I2C_Read
	mov	r2,dpl
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	inc	r0
	mov	b,@r0
	mov	a,r2
	lcall	__gptrput
;	D:\Workspace\MIDE\firmware\/rtc.c:163: I2C_Stop();		                        // Stop I2C communication after reading the Time
	lcall	_I2C_Stop
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'RTC_GetDate'
;------------------------------------------------------------
;ptr_month_u8              Allocated to stack - offset -5
;ptr_year_u8               Allocated to stack - offset -8
;ptr_day_u8                Allocated to registers r2 r3 r4 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/rtc.c:183: void RTC_GetDate(uint8_t *ptr_day_u8,uint8_t *ptr_month_u8,uint8_t *ptr_year_u8)
;	-----------------------------------------
;	 function RTC_GetDate
;	-----------------------------------------
_RTC_GetDate:
	push	_bp
	mov	_bp,sp
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	D:\Workspace\MIDE\firmware\/rtc.c:185: I2C_Start();                          // Start I2C communication
	push	ar2
	push	ar3
	push	ar4
	lcall	_I2C_Start
;	D:\Workspace\MIDE\firmware\/rtc.c:187: I2C_Write(C_Ds1307WriteMode_U8);	      // connect to DS1307 by sending its ID on I2c Bus
	mov	dpl,#0xD0
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:188: I2C_Write(C_Ds1307DateRegAddress_U8); // Request DAY RAM address at 04H
	mov	dpl,#0x04
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:190: I2C_Stop();			                  // Stop I2C communication after selecting DAY Register
	lcall	_I2C_Stop
;	D:\Workspace\MIDE\firmware\/rtc.c:193: I2C_Start();		                  // Start I2C communication
	lcall	_I2C_Start
;	D:\Workspace\MIDE\firmware\/rtc.c:194: I2C_Write(C_Ds1307ReadMode_U8);	      // connect to DS1307(Read mode) by sending its ID
	mov	dpl,#0xD1
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/rtc.c:196: *ptr_day_u8 = I2C_Read(1);              // read Day and return Positive ACK
	mov	dpl,#0x01
	lcall	_I2C_Read
	mov	r5,dpl
	pop	ar4
	pop	ar3
	pop	ar2
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	lcall	__gptrput
;	D:\Workspace\MIDE\firmware\/rtc.c:197: *ptr_month_u8 = I2C_Read(1);            // read Month and return Positive ACK
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	mov	dpl,#0x01
	push	ar2
	push	ar3
	push	ar4
	lcall	_I2C_Read
	mov	r5,dpl
	pop	ar4
	pop	ar3
	pop	ar2
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	lcall	__gptrput
;	D:\Workspace\MIDE\firmware\/rtc.c:198: *ptr_year_u8 = I2C_Read(0);             // read Year and return Negative/No ACK
	mov	a,_bp
	add	a,#0xf8
	mov	r0,a
	mov	ar2,@r0
	inc	r0
	mov	ar3,@r0
	inc	r0
	mov	ar4,@r0
	mov	dpl,#0x00
	push	ar2
	push	ar3
	push	ar4
	lcall	_I2C_Read
	mov	r5,dpl
	pop	ar4
	pop	ar3
	pop	ar2
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r5
	lcall	__gptrput
;	D:\Workspace\MIDE\firmware\/rtc.c:200: I2C_Stop();		                      // Stop I2C communication after reading the Date
	lcall	_I2C_Stop
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'I2C_Init'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/i2c.c:16: void I2C_Init()
;	-----------------------------------------
;	 function I2C_Init
;	-----------------------------------------
_I2C_Init:
;	D:\Workspace\MIDE\firmware\/i2c.c:20: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'I2C_Start'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/i2c.c:22: void I2C_Start()
;	-----------------------------------------
;	 function I2C_Start
;	-----------------------------------------
_I2C_Start:
;	D:\Workspace\MIDE\firmware\/i2c.c:26: util_BitClear(I2C_Port, SCL);        // Pull SCL low
	anl	_P0,#0xBF
;	D:\Workspace\MIDE\firmware\/i2c.c:27: util_BitSet(I2C_Port, SDA);       // Pull SDA High
	orl	_P0,#0x80
;	D:\Workspace\MIDE\firmware\/i2c.c:28: DELAY_us(1);
	mov	dptr,#0x0001
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/i2c.c:29: util_BitSet(I2C_Port, SCL);     //Pull SCL high
	orl	_P0,#0x40
;	D:\Workspace\MIDE\firmware\/i2c.c:30: DELAY_us(1);
	mov	dptr,#0x0001
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/i2c.c:31: util_BitClear(I2C_Port, SDA);      //Now Pull SDA LOW, to generate the Start Condition
	anl	_P0,#0x7F
;	D:\Workspace\MIDE\firmware\/i2c.c:32: DELAY_us(1);
	mov	dptr,#0x0001
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/i2c.c:33: util_BitClear(I2C_Port, SCL);        //Finally Clear the SCL to complete the cycle
	anl	_P0,#0xBF
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'I2C_Stop'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/i2c.c:60: void I2C_Stop(void)
;	-----------------------------------------
;	 function I2C_Stop
;	-----------------------------------------
_I2C_Stop:
;	D:\Workspace\MIDE\firmware\/i2c.c:63: util_BitClear(I2C_Port, SCL);            // Pull SCL low
	anl	_P0,#0xBF
;	D:\Workspace\MIDE\firmware\/i2c.c:64: DELAY_us(1);
	mov	dptr,#0x0001
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/i2c.c:65: util_BitClear(I2C_Port, SDA);          // Pull SDA  low
	anl	_P0,#0x7F
;	D:\Workspace\MIDE\firmware\/i2c.c:66: DELAY_us(1);
	mov	dptr,#0x0001
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/i2c.c:67: util_BitSet(I2C_Port, SCL);         // Pull SCL High
	orl	_P0,#0x40
;	D:\Workspace\MIDE\firmware\/i2c.c:68: DELAY_us(1);
	mov	dptr,#0x0001
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/i2c.c:69: util_BitSet(I2C_Port, SDA);           // Now Pull SDA High, to generate the Stop Condition
	orl	_P0,#0x80
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'I2C_Write'
;------------------------------------------------------------
;var_i2cData_u8            Allocated to registers r2 
;i                         Allocated to registers r3 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/i2c.c:98: void I2C_Write(uint8_t var_i2cData_u8)
;	-----------------------------------------
;	 function I2C_Write
;	-----------------------------------------
_I2C_Write:
	mov	r2,dpl
;	D:\Workspace\MIDE\firmware\/i2c.c:101: util_BitClear(I2C_Port,SDA); //output
	anl	_P0,#0x7F
;	D:\Workspace\MIDE\firmware\/i2c.c:103: for(i=0;i<8;i++)                   // loop 8 times to send 1-byte of data
	mov	r3,#0x00
00104$:
	cjne	r3,#0x08,00114$
00114$:
	jnc	00107$
;	D:\Workspace\MIDE\firmware\/i2c.c:105: if(util_IsBitSet(var_i2cData_u8,7))
	mov	a,r2
	jnb	acc.7,00102$
;	D:\Workspace\MIDE\firmware\/i2c.c:107: util_BitSet(I2C_Port,SDA);
	orl	_P0,#0x80
	sjmp	00103$
00102$:
;	D:\Workspace\MIDE\firmware\/i2c.c:111: util_BitClear(I2C_Port,SDA);
	anl	_P0,#0x7F
00103$:
;	D:\Workspace\MIDE\firmware\/i2c.c:115: i2c_Clock();                   // Generate Clock at SCL
	push	ar2
	push	ar3
	lcall	_i2c_Clock
	pop	ar3
	pop	ar2
;	D:\Workspace\MIDE\firmware\/i2c.c:116: var_i2cData_u8 = var_i2cData_u8<<1;// Bring the next bit to be transmitted to MSB position
	mov	a,r2
	add	a,r2
	mov	r2,a
;	D:\Workspace\MIDE\firmware\/i2c.c:103: for(i=0;i<8;i++)                   // loop 8 times to send 1-byte of data
	inc	r3
	sjmp	00104$
00107$:
;	D:\Workspace\MIDE\firmware\/i2c.c:119: i2c_Clock();
	ljmp	_i2c_Clock
;------------------------------------------------------------
;Allocation info for local variables in function 'I2C_Read'
;------------------------------------------------------------
;var_ackOption_u8          Allocated to registers r2 
;i                         Allocated to registers r4 
;var_i2cData_u8            Allocated to registers r3 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/i2c.c:146: uint8_t I2C_Read(uint8_t var_ackOption_u8)
;	-----------------------------------------
;	 function I2C_Read
;	-----------------------------------------
_I2C_Read:
	mov	r2,dpl
;	D:\Workspace\MIDE\firmware\/i2c.c:148: uint8_t i, var_i2cData_u8=0x00;
	mov	r3,#0x00
;	D:\Workspace\MIDE\firmware\/i2c.c:150: util_BitSet(I2C_Port,SDA);              //Make SDA as I/P
	orl	_P0,#0x80
;	D:\Workspace\MIDE\firmware\/i2c.c:151: for(i=0;i<8;i++)     // loop 8times read 1-byte of data
	mov	r4,#0x00
00104$:
	cjne	r4,#0x08,00114$
00114$:
	jnc	00107$
;	D:\Workspace\MIDE\firmware\/i2c.c:153: DELAY_us(1);
	mov	dptr,#0x0001
	push	ar2
	push	ar3
	push	ar4
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/i2c.c:154: util_BitSet(I2C_Port, SCL);      // Pull SCL High
	orl	_P0,#0x40
;	D:\Workspace\MIDE\firmware\/i2c.c:155: DELAY_us(1);
	mov	dptr,#0x0001
	lcall	_DELAY_us
	pop	ar4
	pop	ar3
	pop	ar2
;	D:\Workspace\MIDE\firmware\/i2c.c:157: var_i2cData_u8 = var_i2cData_u8<<1;    //var_i2cData_u8 is Shifted each time and
	mov	a,r3
	add	a,r3
	mov	r3,a
;	D:\Workspace\MIDE\firmware\/i2c.c:158: var_i2cData_u8 = var_i2cData_u8 | util_GetBitStatus(I2C_Port, SDA); //ORed with the received bit to pack into byte
	mov	a,#0x80
	anl	a,_P0
	mov	r5,a
	clr	a
	mov	r6,a
	cjne	r5,#0x00,00116$
	cjne	r6,#0x00,00116$
	inc	a
00116$:
	mov	r5,a
	cjne	a,#0x01,00118$
00118$:
	clr	a
	rlc	a
	mov	r5,a
	orl	ar3,a
;	D:\Workspace\MIDE\firmware\/i2c.c:160: util_BitClear(I2C_Port, SCL);         // Clear SCL to complete the Clock
	anl	_P0,#0xBF
;	D:\Workspace\MIDE\firmware\/i2c.c:151: for(i=0;i<8;i++)     // loop 8times read 1-byte of data
	inc	r4
	sjmp	00104$
00107$:
;	D:\Workspace\MIDE\firmware\/i2c.c:162: if(var_ackOption_u8==1)  /*Send the Ack/NoAck depending on the user option*/
	cjne	r2,#0x01,00102$
;	D:\Workspace\MIDE\firmware\/i2c.c:164: i2c_Ack();
	push	ar3
	lcall	_i2c_Ack
	pop	ar3
	sjmp	00103$
00102$:
;	D:\Workspace\MIDE\firmware\/i2c.c:168: i2c_NoAck();
	push	ar3
	lcall	_i2c_NoAck
	pop	ar3
00103$:
;	D:\Workspace\MIDE\firmware\/i2c.c:171: return var_i2cData_u8;           // Finally return the received Byte*
	mov	dpl,r3
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'i2c_Clock'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/i2c.c:192: static void i2c_Clock(void)
;	-----------------------------------------
;	 function i2c_Clock
;	-----------------------------------------
_i2c_Clock:
;	D:\Workspace\MIDE\firmware\/i2c.c:194: DELAY_us(1);
	mov	dptr,#0x0001
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/i2c.c:195: util_BitSet(I2C_Port, SCL);         // Wait for Some time and Pull the SCL line High
	orl	_P0,#0x40
;	D:\Workspace\MIDE\firmware\/i2c.c:196: DELAY_us(1);        // Wait for Some time
	mov	dptr,#0x0001
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/i2c.c:197: util_BitClear(I2C_Port, SCL);            // Pull back the SCL line low to Generate a clock pulse
	anl	_P0,#0xBF
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'i2c_Ack'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/i2c.c:213: static void i2c_Ack()
;	-----------------------------------------
;	 function i2c_Ack
;	-----------------------------------------
_i2c_Ack:
;	D:\Workspace\MIDE\firmware\/i2c.c:215: util_BitClear(I2C_Port, SDA);      //Pull SDA low to indicate Positive ACK
	anl	_P0,#0x7F
;	D:\Workspace\MIDE\firmware\/i2c.c:216: i2c_Clock();    //Generate the Clock
	lcall	_i2c_Clock
;	D:\Workspace\MIDE\firmware\/i2c.c:217: util_BitSet(I2C_Port, SDA);       // Pull SDA back to High(IDLE state)
	orl	_P0,#0x80
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'i2c_NoAck'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/i2c.c:233: static void i2c_NoAck()
;	-----------------------------------------
;	 function i2c_NoAck
;	-----------------------------------------
_i2c_NoAck:
;	D:\Workspace\MIDE\firmware\/i2c.c:235: util_BitSet(I2C_Port, SDA);        //Pull SDA high to indicate Negative/NO ACK
	orl	_P0,#0x80
;	D:\Workspace\MIDE\firmware\/i2c.c:236: i2c_Clock();     // Generate the Clock  
	lcall	_i2c_Clock
;	D:\Workspace\MIDE\firmware\/i2c.c:237: util_BitSet(I2C_Port, SCL);      // Set SCL 
	orl	_P0,#0x40
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'LCD_Init'
;------------------------------------------------------------
;var_lcdNoOfLines_u8       Allocated to stack - offset -3
;var_MaxCharsPerLine_u8    Allocated to stack - offset -4
;var_lcdMode_u8            Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:112: void LCD_Init(uint8_t var_lcdMode_u8, uint8_t var_lcdNoOfLines_u8, uint8_t var_MaxCharsPerLine_u8)
;	-----------------------------------------
;	 function LCD_Init
;	-----------------------------------------
_LCD_Init:
	push	_bp
	mov	_bp,sp
	mov	r2,dpl
;	D:\Workspace\MIDE\firmware\/lcd.c:116: M_LcdDataBusDirection = C_PortOutput_U8;     //Configure the Data Bus as output
	mov	_P2,#0x00
;	D:\Workspace\MIDE\firmware\/lcd.c:117: M_LcdControlBusDirection = C_PortOutput_U8;  //Configure the Control Bus as output
	mov	_P0,#0x00
;	D:\Workspace\MIDE\firmware\/lcd.c:118: STK_LCDConfig.mvar_LcdMode_U8 = var_lcdMode_u8;      // Keep the track of selected Mode(4/8 bit)
	mov	(_STK_LCDConfig + 0x0002),r2
;	D:\Workspace\MIDE\firmware\/lcd.c:119: STK_LCDConfig.mvar_MaxSupportedChars_U8 = var_MaxCharsPerLine_u8; //Keep the LCD type
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	(_STK_LCDConfig + 0x0001),@r0
;	D:\Workspace\MIDE\firmware\/lcd.c:120: STK_LCDConfig.mvar_MaxSupportedLines_U8 = var_lcdNoOfLines_u8;
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	_STK_LCDConfig,@r0
;	D:\Workspace\MIDE\firmware\/lcd.c:121: if(var_lcdNoOfLines_u8 > mENUM_LcdLineTwo)
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	a,@r0
	add	a,#0xff - 0x02
	jnc	00102$
;	D:\Workspace\MIDE\firmware\/lcd.c:123: ARR_LcdLineNumAddress_U8[mENUM_LcdLineThree] =  0x90 + (var_MaxCharsPerLine_u8 & 0x0fu);
	mov	a,_bp
	add	a,#0xfc
	mov	r0,a
	mov	ar2,@r0
	anl	ar2,#0x0F
	mov	r3,#0x00
	mov	a,#0x90
	add	a,r2
	mov	(_ARR_LcdLineNumAddress_U8 + 0x0003),a
;	D:\Workspace\MIDE\firmware\/lcd.c:124: ARR_LcdLineNumAddress_U8[mENUM_LcdLineFour] =  0xd0 + (var_MaxCharsPerLine_u8 & 0x0fu);
	mov	a,#0xD0
	add	a,r2
	mov	(_ARR_LcdLineNumAddress_U8 + 0x0004),a
00102$:
;	D:\Workspace\MIDE\firmware\/lcd.c:127: DELAY_ms(100);
	mov	dptr,#0x0064
	lcall	_DELAY_ms
;	D:\Workspace\MIDE\firmware\/lcd.c:129: if(STK_LCDConfig.mvar_LcdMode_U8 == M_EightBitMode)
	mov	r2,(_STK_LCDConfig + 0x0002)
	mov	r3,#0x00
	cjne	r2,#0x08,00106$
	cjne	r3,#0x00,00106$
;	D:\Workspace\MIDE\firmware\/lcd.c:131: LCD_CmdWrite(CMD_LCD_EIGHT_BIT_MODE); // Initialize the LCD for 8-bit 5x7 matrix type
	mov	dpl,#0x38
	lcall	_LCD_CmdWrite
	sjmp	00107$
00106$:
;	D:\Workspace\MIDE\firmware\/lcd.c:133: else if(STK_LCDConfig.mvar_LcdMode_U8 == M_FourBitMode)
	cjne	r2,#0x04,00107$
	cjne	r3,#0x00,00107$
;	D:\Workspace\MIDE\firmware\/lcd.c:135: lcd_Reset();
	lcall	_lcd_Reset
;	D:\Workspace\MIDE\firmware\/lcd.c:136: LCD_CmdWrite(CMD_LCD_FOUR_BIT_MODE); // Initialize the LCD for 4-bit 5x7 matrix type 
	mov	dpl,#0x28
	lcall	_LCD_CmdWrite
00107$:
;	D:\Workspace\MIDE\firmware\/lcd.c:139: LCD_CmdWrite(CMD_DISPLAY_ON_CURSOR_ON);	 // Display ON cursor ON
	mov	dpl,#0x0E
	lcall	_LCD_CmdWrite
;	D:\Workspace\MIDE\firmware\/lcd.c:140: LCD_Clear();	                         // Clear the LCD and go to First line First Position
	lcall	_LCD_Clear
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'LCD_Clear'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:154: void LCD_Clear()
;	-----------------------------------------
;	 function LCD_Clear
;	-----------------------------------------
_LCD_Clear:
;	D:\Workspace\MIDE\firmware\/lcd.c:156: LCD_CmdWrite(CMD_LCD_CLEAR);	// Clear the LCD and go to First line First Position
	mov	dpl,#0x01
	lcall	_LCD_CmdWrite
;	D:\Workspace\MIDE\firmware\/lcd.c:157: LCD_GoToLine(mENUM_LcdLineOne);
	mov	dpl,#0x01
	ljmp	_LCD_GoToLine
;------------------------------------------------------------
;Allocation info for local variables in function 'LCD_GoToLine'
;------------------------------------------------------------
;var_lineNumber_u8         Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:181: void LCD_GoToLine(uint8_t var_lineNumber_u8)
;	-----------------------------------------
;	 function LCD_GoToLine
;	-----------------------------------------
_LCD_GoToLine:
	mov	r2,dpl
;	D:\Workspace\MIDE\firmware\/lcd.c:183: if(var_lineNumber_u8 <= STK_LCDConfig.mvar_MaxSupportedLines_U8)
	mov	a,_STK_LCDConfig
	cjne	a,ar2,00106$
00106$:
	jc	00103$
;	D:\Workspace\MIDE\firmware\/lcd.c:187: VAR_LcdTrackCursorPos_U8 = 0x00;
	mov	_VAR_LcdTrackCursorPos_U8,#0x00
;	D:\Workspace\MIDE\firmware\/lcd.c:188: VAR_LcdTrackLineNum_U8 = var_lineNumber_u8;
	mov	_VAR_LcdTrackLineNum_U8,r2
;	D:\Workspace\MIDE\firmware\/lcd.c:189: LCD_CmdWrite(ARR_LcdLineNumAddress_U8[var_lineNumber_u8]);
	mov	a,r2
	add	a,#_ARR_LcdLineNumAddress_U8
	mov	r0,a
	mov	dpl,@r0
	ljmp	_LCD_CmdWrite
00103$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'LCD_GoToNextLine'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:208: void  LCD_GoToNextLine()
;	-----------------------------------------
;	 function LCD_GoToNextLine
;	-----------------------------------------
_LCD_GoToNextLine:
;	D:\Workspace\MIDE\firmware\/lcd.c:212: VAR_LcdTrackLineNum_U8++;
	inc	_VAR_LcdTrackLineNum_U8
;	D:\Workspace\MIDE\firmware\/lcd.c:213: VAR_LcdTrackCursorPos_U8 = 0x00;
	mov	_VAR_LcdTrackCursorPos_U8,#0x00
;	D:\Workspace\MIDE\firmware\/lcd.c:214: if(VAR_LcdTrackLineNum_U8 > STK_LCDConfig.mvar_MaxSupportedLines_U8)
	mov	a,_STK_LCDConfig
	cjne	a,_VAR_LcdTrackLineNum_U8,00106$
00106$:
	jnc	00102$
;	D:\Workspace\MIDE\firmware\/lcd.c:215: VAR_LcdTrackLineNum_U8 = 0x01;
	mov	_VAR_LcdTrackLineNum_U8,#0x01
00102$:
;	D:\Workspace\MIDE\firmware\/lcd.c:216: LCD_CmdWrite(ARR_LcdLineNumAddress_U8[VAR_LcdTrackLineNum_U8]);
	mov	a,_VAR_LcdTrackLineNum_U8
	add	a,#_ARR_LcdLineNumAddress_U8
	mov	r0,a
	mov	dpl,@r0
	ljmp	_LCD_CmdWrite
;------------------------------------------------------------
;Allocation info for local variables in function 'LCD_CmdWrite'
;------------------------------------------------------------
;var_lcdCmd_u8             Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:274: void LCD_CmdWrite( uint8_t var_lcdCmd_u8)
;	-----------------------------------------
;	 function LCD_CmdWrite
;	-----------------------------------------
_LCD_CmdWrite:
	mov	r2,dpl
;	D:\Workspace\MIDE\firmware\/lcd.c:276: lcd_BusyCheck();
	push	ar2
	lcall	_lcd_BusyCheck
	pop	ar2
;	D:\Workspace\MIDE\firmware\/lcd.c:277: if(STK_LCDConfig.mvar_LcdMode_U8 == M_EightBitMode)
	mov	r3,(_STK_LCDConfig + 0x0002)
	mov	r4,#0x00
	cjne	r3,#0x08,00104$
	cjne	r4,#0x00,00104$
;	D:\Workspace\MIDE\firmware\/lcd.c:280: M_LcdDataBus = var_lcdCmd_u8;     // Send the complete command if the selected mode is 8-bit
	mov	_P2,r2
;	D:\Workspace\MIDE\firmware\/lcd.c:281: lcd_SendCmdSignals();  // Signals for command write operation
	ljmp	_lcd_SendCmdSignals
00104$:
;	D:\Workspace\MIDE\firmware\/lcd.c:283: else if(STK_LCDConfig.mvar_LcdMode_U8 == M_FourBitMode)
	cjne	r3,#0x04,00106$
	cjne	r4,#0x00,00106$
;	D:\Workspace\MIDE\firmware\/lcd.c:285: lcd_SendNibble(var_lcdCmd_u8);  // Send the command in two nibbles as the selected mode is 4-bit
	mov	dpl,r2
	push	ar2
	lcall	_lcd_SendNibble
;	D:\Workspace\MIDE\firmware\/lcd.c:286: lcd_SendCmdSignals(); // Signals for command write operation
	lcall	_lcd_SendCmdSignals
	pop	ar2
;	D:\Workspace\MIDE\firmware\/lcd.c:288: lcd_SendNibble(var_lcdCmd_u8 << 4);
	mov	a,r2
	swap	a
	anl	a,#0xf0
	mov	dpl,a
	lcall	_lcd_SendNibble
;	D:\Workspace\MIDE\firmware\/lcd.c:289: lcd_SendCmdSignals();
	ljmp	_lcd_SendCmdSignals
00106$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'LCD_DisplayChar'
;------------------------------------------------------------
;var_lcdData_u8            Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:309: void LCD_DisplayChar(char var_lcdData_u8)
;	-----------------------------------------
;	 function LCD_DisplayChar
;	-----------------------------------------
_LCD_DisplayChar:
	mov	r2,dpl
;	D:\Workspace\MIDE\firmware\/lcd.c:311: if((VAR_LcdTrackCursorPos_U8>=STK_LCDConfig.mvar_MaxSupportedChars_U8) || (var_lcdData_u8=='\n'))
	mov	a,_VAR_LcdTrackCursorPos_U8
	cjne	a,(_STK_LCDConfig + 0x0001),00110$
00110$:
	jnc	00101$
	cjne	r2,#0x0A,00102$
00101$:
;	D:\Workspace\MIDE\firmware\/lcd.c:315: LCD_GoToNextLine();
	push	ar2
	lcall	_LCD_GoToNextLine
	pop	ar2
00102$:
;	D:\Workspace\MIDE\firmware\/lcd.c:317: if(var_lcdData_u8!='\n') /* Display the character if its not newLine Char */
	cjne	r2,#0x0A,00114$
	ret
00114$:
;	D:\Workspace\MIDE\firmware\/lcd.c:320: lcd_DataWrite(var_lcdData_u8); /* Display the data and keep track of cursor */
	mov	dpl,r2
	lcall	_lcd_DataWrite
;	D:\Workspace\MIDE\firmware\/lcd.c:321: VAR_LcdTrackCursorPos_U8++;
	inc	_VAR_LcdTrackCursorPos_U8
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'LCD_DisplayString'
;------------------------------------------------------------
;ptr_stringPointer_u8      Allocated to registers r2 r3 r4 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:344: void LCD_DisplayString(char *ptr_stringPointer_u8)
;	-----------------------------------------
;	 function LCD_DisplayString
;	-----------------------------------------
_LCD_DisplayString:
	mov	r2,dpl
	mov	r3,dph
	mov	r4,b
;	D:\Workspace\MIDE\firmware\/lcd.c:346: while((*ptr_stringPointer_u8)!=0)
00101$:
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	r5,a
	jz	00104$
;	D:\Workspace\MIDE\firmware\/lcd.c:347: LCD_DisplayChar(*ptr_stringPointer_u8++); // Loop through the string and display char by char
	inc	r2
	cjne	r2,#0x00,00110$
	inc	r3
00110$:
	mov	dpl,r5
	push	ar2
	push	ar3
	push	ar4
	lcall	_LCD_DisplayChar
	pop	ar4
	pop	ar3
	pop	ar2
	sjmp	00101$
00104$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'lcd_DataWrite'
;------------------------------------------------------------
;dat                       Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:839: static void lcd_DataWrite( uint8_t dat)
;	-----------------------------------------
;	 function lcd_DataWrite
;	-----------------------------------------
_lcd_DataWrite:
	mov	r2,dpl
;	D:\Workspace\MIDE\firmware\/lcd.c:841: lcd_BusyCheck();
	push	ar2
	lcall	_lcd_BusyCheck
	pop	ar2
;	D:\Workspace\MIDE\firmware\/lcd.c:842: if(STK_LCDConfig.mvar_LcdMode_U8 == M_EightBitMode)
	mov	r3,(_STK_LCDConfig + 0x0002)
	mov	r4,#0x00
	cjne	r3,#0x08,00104$
	cjne	r4,#0x00,00104$
;	D:\Workspace\MIDE\firmware\/lcd.c:844: M_LcdDataBus = dat;      // Send the complete data byte if the selected mode is 8-bit
	mov	_P2,r2
;	D:\Workspace\MIDE\firmware\/lcd.c:845: lcd_SendDataSignals();  // Signals for data write operation
	ljmp	_lcd_SendDataSignals
00104$:
;	D:\Workspace\MIDE\firmware\/lcd.c:847: else if(STK_LCDConfig.mvar_LcdMode_U8 == M_FourBitMode)
	cjne	r3,#0x04,00106$
	cjne	r4,#0x00,00106$
;	D:\Workspace\MIDE\firmware\/lcd.c:849: lcd_SendNibble(dat);    // Send the data in two nibbles as the selected mode is 4-bit
	mov	dpl,r2
	push	ar2
	lcall	_lcd_SendNibble
;	D:\Workspace\MIDE\firmware\/lcd.c:850: lcd_SendDataSignals();  // Signals for data write operation
	lcall	_lcd_SendDataSignals
	pop	ar2
;	D:\Workspace\MIDE\firmware\/lcd.c:852: lcd_SendNibble(dat << 4);
	mov	a,r2
	swap	a
	anl	a,#0xf0
	mov	dpl,a
	lcall	_lcd_SendNibble
;	D:\Workspace\MIDE\firmware\/lcd.c:853: lcd_SendDataSignals();
	ljmp	_lcd_SendDataSignals
00106$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'lcd_BusyCheck'
;------------------------------------------------------------
;busyflag                  Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:873: static void lcd_BusyCheck()
;	-----------------------------------------
;	 function lcd_BusyCheck
;	-----------------------------------------
_lcd_BusyCheck:
;	D:\Workspace\MIDE\firmware\/lcd.c:878: util_UpdateBit(M_LcdDataBusDirection,LCD_D7,C_PinInput_U8); // Configure busy pin as input
	orl	_P2,#0x80
;	D:\Workspace\MIDE\firmware\/lcd.c:879: M_LcdClearBit(LCD_RS);           // Select the Command Register by pulling RS LOW
	anl	_P0,#0xFE
;	D:\Workspace\MIDE\firmware\/lcd.c:880: M_LcdSetBit(LCD_RW);             // Select the Read Operation for busy flag by setting RW
	orl	_P0,#0x02
;	D:\Workspace\MIDE\firmware\/lcd.c:881: do
00103$:
;	D:\Workspace\MIDE\firmware\/lcd.c:884: M_LcdClearBit(LCD_EN);             // Send a High-to-Low Pulse at Enable Pin
	anl	_P0,#0xFB
;	D:\Workspace\MIDE\firmware\/lcd.c:885: DELAY_us(10);	
	mov	dptr,#0x000A
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/lcd.c:886: M_LcdSetBit(LCD_EN); 
	orl	_P0,#0x04
;	D:\Workspace\MIDE\firmware\/lcd.c:887: DELAY_us(10);
	mov	dptr,#0x000A
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/lcd.c:888: busyflag = util_GetBitStatus(M_LcdDataBusInput,LCD_D7);
	mov	a,#0x80
	anl	a,_P2
	mov	r2,a
	clr	a
	mov	r3,a
	cjne	r2,#0x00,00111$
	cjne	r3,#0x00,00111$
	inc	a
00111$:
	mov	r2,a
	cjne	a,#0x01,00113$
00113$:
	clr	a
	rlc	a
	mov	r2,a
;	D:\Workspace\MIDE\firmware\/lcd.c:891: if(STK_LCDConfig.mvar_LcdMode_U8 == 4)
	mov	a,#0x04
	cjne	a,(_STK_LCDConfig + 0x0002),00104$
;	D:\Workspace\MIDE\firmware\/lcd.c:894: M_LcdClearBit(LCD_EN);
	anl	_P0,#0xFB
;	D:\Workspace\MIDE\firmware\/lcd.c:895: DELAY_us(10);
	mov	dptr,#0x000A
	push	ar2
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/lcd.c:896: M_LcdSetBit(LCD_EN); 
	orl	_P0,#0x04
;	D:\Workspace\MIDE\firmware\/lcd.c:897: DELAY_us(10);
	mov	dptr,#0x000A
	lcall	_DELAY_us
	pop	ar2
00104$:
;	D:\Workspace\MIDE\firmware\/lcd.c:899: }while(busyflag);
	mov	a,r2
	jnz	00103$
;	D:\Workspace\MIDE\firmware\/lcd.c:901: util_UpdateBit(M_LcdDataBusDirection,LCD_D7,C_PinOutput_U8);
	anl	_P2,#0x7F
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'lcd_Reset'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:923: static void lcd_Reset()
;	-----------------------------------------
;	 function lcd_Reset
;	-----------------------------------------
_lcd_Reset:
;	D:\Workspace\MIDE\firmware\/lcd.c:926: lcd_SendNibble(0x30);
	mov	dpl,#0x30
	lcall	_lcd_SendNibble
;	D:\Workspace\MIDE\firmware\/lcd.c:927: lcd_SendCmdSignals();
	lcall	_lcd_SendCmdSignals
;	D:\Workspace\MIDE\firmware\/lcd.c:928: DELAY_ms(100);
	mov	dptr,#0x0064
	lcall	_DELAY_ms
;	D:\Workspace\MIDE\firmware\/lcd.c:929: lcd_SendNibble(0x30);
	mov	dpl,#0x30
	lcall	_lcd_SendNibble
;	D:\Workspace\MIDE\firmware\/lcd.c:930: lcd_SendCmdSignals();
	lcall	_lcd_SendCmdSignals
;	D:\Workspace\MIDE\firmware\/lcd.c:931: DELAY_us(200);
	mov	dptr,#0x00C8
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/lcd.c:932: lcd_SendNibble(0x30);
	mov	dpl,#0x30
	lcall	_lcd_SendNibble
;	D:\Workspace\MIDE\firmware\/lcd.c:933: lcd_SendCmdSignals();
	lcall	_lcd_SendCmdSignals
;	D:\Workspace\MIDE\firmware\/lcd.c:934: DELAY_us(200);
	mov	dptr,#0x00C8
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/lcd.c:935: lcd_SendNibble(0x20);
	mov	dpl,#0x20
	lcall	_lcd_SendNibble
;	D:\Workspace\MIDE\firmware\/lcd.c:936: lcd_SendCmdSignals();
	lcall	_lcd_SendCmdSignals
;	D:\Workspace\MIDE\firmware\/lcd.c:937: DELAY_us(200);
	mov	dptr,#0x00C8
	ljmp	_DELAY_us
;------------------------------------------------------------
;Allocation info for local variables in function 'lcd_SendNibble'
;------------------------------------------------------------
;var                       Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:953: static void lcd_SendNibble(uint8_t var)
;	-----------------------------------------
;	 function lcd_SendNibble
;	-----------------------------------------
_lcd_SendNibble:
;	D:\Workspace\MIDE\firmware\/lcd.c:955: util_UpdateBit(M_LcdDataBus,LCD_D4,util_GetBitStatus(var,LCD_D4));
	mov	a,dpl
	mov	r2,a
	jnb	acc.4,00103$
	orl	_P2,#0x10
	sjmp	00104$
00103$:
	anl	_P2,#0xEF
00104$:
;	D:\Workspace\MIDE\firmware\/lcd.c:956: util_UpdateBit(M_LcdDataBus,LCD_D5,util_GetBitStatus(var,LCD_D5));
	mov	a,r2
	jnb	acc.5,00105$
	orl	_P2,#0x20
	sjmp	00106$
00105$:
	anl	_P2,#0xDF
00106$:
;	D:\Workspace\MIDE\firmware\/lcd.c:957: util_UpdateBit(M_LcdDataBus,LCD_D6,util_GetBitStatus(var,LCD_D6));
	mov	a,r2
	jnb	acc.6,00107$
	orl	_P2,#0x40
	sjmp	00108$
00107$:
	anl	_P2,#0xBF
00108$:
;	D:\Workspace\MIDE\firmware\/lcd.c:958: util_UpdateBit(M_LcdDataBus,LCD_D7,util_GetBitStatus(var,LCD_D7));
	mov	a,r2
	jnb	acc.7,00109$
	orl	_P2,#0x80
	ret
00109$:
	anl	_P2,#0x7F
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'lcd_SendCmdSignals'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:972: static void lcd_SendCmdSignals()
;	-----------------------------------------
;	 function lcd_SendCmdSignals
;	-----------------------------------------
_lcd_SendCmdSignals:
;	D:\Workspace\MIDE\firmware\/lcd.c:974: M_LcdClearBit(LCD_RS);           // Select the Command Register by pulling RS LOW
	anl	_P0,#0xFE
;	D:\Workspace\MIDE\firmware\/lcd.c:976: M_LcdClearBit(LCD_RW);           // Select the Write Operation  by pulling RW LOW
	anl	_P0,#0xFD
;	D:\Workspace\MIDE\firmware\/lcd.c:978: M_LcdSetBit(LCD_EN);             // Send a High-to-Low Pusle at Enable Pin
	orl	_P0,#0x04
;	D:\Workspace\MIDE\firmware\/lcd.c:979: DELAY_us(10);
	mov	dptr,#0x000A
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/lcd.c:980: M_LcdClearBit(LCD_EN);
	anl	_P0,#0xFB
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'lcd_SendDataSignals'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/lcd.c:994: static void lcd_SendDataSignals()
;	-----------------------------------------
;	 function lcd_SendDataSignals
;	-----------------------------------------
_lcd_SendDataSignals:
;	D:\Workspace\MIDE\firmware\/lcd.c:996: M_LcdSetBit(LCD_RS); 			// Select the Data Register by pulling RS HIGH
	orl	_P0,#0x01
;	D:\Workspace\MIDE\firmware\/lcd.c:998: M_LcdClearBit(LCD_RW);          // Select the Write Operation  by pulling RW LOW
	anl	_P0,#0xFD
;	D:\Workspace\MIDE\firmware\/lcd.c:1000: M_LcdSetBit(LCD_EN);            // Send a High-to-Low Pusle at Enable Pin
	orl	_P0,#0x04
;	D:\Workspace\MIDE\firmware\/lcd.c:1001: DELAY_us(10);
	mov	dptr,#0x000A
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/lcd.c:1002: M_LcdClearBit(LCD_EN);
	anl	_P0,#0xFB
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'DELAY_us'
;------------------------------------------------------------
;us_count                  Allocated to registers r2 r3 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/delay.c:55: void DELAY_us(uint16_t us_count)
;	-----------------------------------------
;	 function DELAY_us
;	-----------------------------------------
_DELAY_us:
	mov	r2,dpl
	mov	r3,dph
;	D:\Workspace\MIDE\firmware\/delay.c:57: while(us_count!=0)
00101$:
	mov	a,r2
	orl	a,r3
	jz	00104$
;	D:\Workspace\MIDE\firmware\/delay.c:59: us_count--;
	dec	r2
	cjne	r2,#0xff,00101$
	dec	r3
	sjmp	00101$
00104$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'DELAY_ms'
;------------------------------------------------------------
;ms_count                  Allocated to registers r2 r3 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/delay.c:76: void DELAY_ms(uint16_t ms_count)
;	-----------------------------------------
;	 function DELAY_ms
;	-----------------------------------------
_DELAY_ms:
	mov	r2,dpl
	mov	r3,dph
;	D:\Workspace\MIDE\firmware\/delay.c:78: while(ms_count!=0)
00101$:
	mov	a,r2
	orl	a,r3
	jz	00104$
;	D:\Workspace\MIDE\firmware\/delay.c:80: DELAY_us(C_CountForOneMsDelay_U16);	 //DELAY_us is called to generate 1ms delay
	mov	dptr,#0x0070
	push	ar2
	push	ar3
	lcall	_DELAY_us
	pop	ar3
	pop	ar2
;	D:\Workspace\MIDE\firmware\/delay.c:81: ms_count--;
	dec	r2
	cjne	r2,#0xff,00101$
	dec	r3
	sjmp	00101$
00104$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'DELAY_sec'
;------------------------------------------------------------
;sec_count                 Allocated to registers r2 r3 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/delay.c:102: void DELAY_sec(uint16_t sec_count)
;	-----------------------------------------
;	 function DELAY_sec
;	-----------------------------------------
_DELAY_sec:
	mov	r2,dpl
	mov	r3,dph
;	D:\Workspace\MIDE\firmware\/delay.c:106: while(sec_count!=0)
00101$:
	mov	a,r2
	orl	a,r3
	jz	00104$
;	D:\Workspace\MIDE\firmware\/delay.c:108: DELAY_ms(1000);	//DELAY_ms is called to generate 1sec delay
	mov	dptr,#0x03E8
	push	ar2
	push	ar3
	lcall	_DELAY_ms
	pop	ar3
	pop	ar2
;	D:\Workspace\MIDE\firmware\/delay.c:109: sec_count--;
	dec	r2
	cjne	r2,#0xff,00101$
	dec	r3
	sjmp	00101$
00104$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ADC_Init'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/adc.c:58: void ADC_Init()
;	-----------------------------------------
;	 function ADC_Init
;	-----------------------------------------
_ADC_Init:
;	D:\Workspace\MIDE\firmware\/adc.c:60: util_BitClear(adc_controlbus,adc_Start); 
	anl	_P0,#0xEF
;	D:\Workspace\MIDE\firmware\/adc.c:61: util_BitClear(adc_controlbus,adc_ALE); 
	anl	_P0,#0xF7
;	D:\Workspace\MIDE\firmware\/adc.c:62: util_BitClear(adc_controlbus,adc_OE); 
	anl	_P0,#0xBF
;	D:\Workspace\MIDE\firmware\/adc.c:63: util_BitSet(adc_controlbus,adc_OE); 
	orl	_P0,#0x40
;	D:\Workspace\MIDE\firmware\/adc.c:64: adc_databus=0xff; 
	mov	_P1,#0xFF
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ADC_GetAdcValue'
;------------------------------------------------------------
;var_adcChannel_u8         Allocated to registers r2 
;adc_result                Allocated to registers r2 r3 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/adc.c:111: uint16_t ADC_GetAdcValue(uint8_t var_adcChannel_u8)
;	-----------------------------------------
;	 function ADC_GetAdcValue
;	-----------------------------------------
_ADC_GetAdcValue:
;	D:\Workspace\MIDE\firmware\/adc.c:119: util_UpdateBit(adc_controlbus,adc_A,util_GetBitStatus(var_adcChannel_u8,0X00)); 
	mov	a,dpl
	mov	r2,a
	jnb	acc.0,00106$
	orl	_P0,#0x01
	sjmp	00107$
00106$:
	anl	_P0,#0xFE
00107$:
;	D:\Workspace\MIDE\firmware\/adc.c:120: util_UpdateBit(adc_controlbus,adc_B,util_GetBitStatus(var_adcChannel_u8,0X01));	
	mov	a,r2
	jnb	acc.1,00108$
	orl	_P0,#0x02
	sjmp	00109$
00108$:
	anl	_P0,#0xFD
00109$:
;	D:\Workspace\MIDE\firmware\/adc.c:121: util_UpdateBit(adc_controlbus,adc_C,util_GetBitStatus(var_adcChannel_u8,0X02));
	mov	a,r2
	jnb	acc.2,00110$
	orl	_P0,#0x04
	sjmp	00111$
00110$:
	anl	_P0,#0xFB
00111$:
;	D:\Workspace\MIDE\firmware\/adc.c:124: util_BitSet(adc_controlbus,adc_ALE);        // Latch the address by making the ALE high.
	orl	_P0,#0x08
;	D:\Workspace\MIDE\firmware\/adc.c:125: DELAY_us(50);
	mov	dptr,#0x0032
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/adc.c:126: util_BitSet(adc_controlbus,adc_Start);       //Start the conversion after latching the channel address
	orl	_P0,#0x10
;	D:\Workspace\MIDE\firmware\/adc.c:127: DELAY_us(25);
	mov	dptr,#0x0019
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/adc.c:129: util_BitClear(adc_controlbus,adc_ALE);          //Pull ALE line to zero after starting the conversion.
	anl	_P0,#0xF7
;	D:\Workspace\MIDE\firmware\/adc.c:130: DELAY_us(50);
	mov	dptr,#0x0032
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/adc.c:131: util_BitClear(adc_controlbus,adc_Start);;       //Pull Start line to zero after starting the conversion.
	anl	_P0,#0xEF
;	D:\Workspace\MIDE\firmware\/adc.c:134: while(util_GetBitStatus(adc_controlbus,adc_EOC)==0);    // Wait till the ADC conversion is completed,
00101$:
	mov	a,#0x20
	anl	a,_P0
	mov	r2,a
	mov	r3,#0x00
	cjne	r2,#0x00,00120$
	cjne	r3,#0x00,00120$
	sjmp	00101$
00120$:
;	D:\Workspace\MIDE\firmware\/adc.c:138: util_BitSet(adc_controlbus,adc_OE);          //Make the Output Enable high
	orl	_P0,#0x40
;	D:\Workspace\MIDE\firmware\/adc.c:140: DELAY_us(25);
	mov	dptr,#0x0019
	lcall	_DELAY_us
;	D:\Workspace\MIDE\firmware\/adc.c:141: adc_result=adc_databus;  //Read the ADC data from ADC bus
	mov	r2,_P1
	mov	r3,#0x00
;	D:\Workspace\MIDE\firmware\/adc.c:142: util_BitClear(adc_controlbus,adc_OE); 			  //After reading the data, disable th ADC output line.
	anl	_P0,#0xBF
;	D:\Workspace\MIDE\firmware\/adc.c:144: return(adc_result) ;
	mov	dpl,r2
	mov	dph,r3
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'KEYPAD_Init'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/keypad.c:101: void KEYPAD_Init()
;	-----------------------------------------
;	 function KEYPAD_Init
;	-----------------------------------------
_KEYPAD_Init:
;	D:\Workspace\MIDE\firmware\/keypad.c:103: M_RowColDirection= C_RowOutputColInput_U8; // Configure Row lines as O/P and Column lines as I/P
	mov	_P2,#0x0F
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'KEYPAD_WaitForKeyRelease'
;------------------------------------------------------------
;key                       Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/keypad.c:118: void KEYPAD_WaitForKeyRelease()
;	-----------------------------------------
;	 function KEYPAD_WaitForKeyRelease
;	-----------------------------------------
_KEYPAD_WaitForKeyRelease:
;	D:\Workspace\MIDE\firmware\/keypad.c:123: do
00101$:
;	D:\Workspace\MIDE\firmware\/keypad.c:125: M_ROW=0x0F;           // Pull the ROW lines to low and Column lines high.
;	D:\Workspace\MIDE\firmware\/keypad.c:126: key=M_COL & 0x0F;     // Read the Columns, to check the key press
	mov	a,#0x0F
	mov	_P2,a
	anl	a,_P2
	mov	r2,a
;	D:\Workspace\MIDE\firmware\/keypad.c:127: }while(key!=0x0F);
	cjne	r2,#0x0F,00101$
;	D:\Workspace\MIDE\firmware\/keypad.c:129: DELAY_ms(1);
	mov	dptr,#0x0001
	lcall	_DELAY_ms
;	D:\Workspace\MIDE\firmware\/keypad.c:131: M_ROW=0x0F;           // Pull the ROW lines to low and Column lines high.
;	D:\Workspace\MIDE\firmware\/keypad.c:132: key=M_COL & 0x0F;     // Read the Columns, to check the key press
	mov	a,#0x0F
	mov	_P2,a
	anl	a,_P2
	mov	r2,a
;	D:\Workspace\MIDE\firmware\/keypad.c:133: }while(key!=0x0F);   // Wait till the Key is released,
	cjne	r2,#0x0F,00101$
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'KEYPAD_WaitForKeyPress'
;------------------------------------------------------------
;var_keyPress_u8           Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/keypad.c:151: void KEYPAD_WaitForKeyPress()
;	-----------------------------------------
;	 function KEYPAD_WaitForKeyPress
;	-----------------------------------------
_KEYPAD_WaitForKeyPress:
;	D:\Workspace\MIDE\firmware\/keypad.c:156: do
00101$:
;	D:\Workspace\MIDE\firmware\/keypad.c:158: M_ROW=0x0F;		  // Pull the ROW lines to low and Column lines high.
;	D:\Workspace\MIDE\firmware\/keypad.c:159: var_keyPress_u8=M_COL & 0x0F;	  // Read the Columns, to check the key press
	mov	a,#0x0F
	mov	_P2,a
	anl	a,_P2
	mov	r2,a
;	D:\Workspace\MIDE\firmware\/keypad.c:160: }while(var_keyPress_u8==0x0F); // Wait till the Key is pressed,
	cjne	r2,#0x0F,00111$
	sjmp	00101$
00111$:
;	D:\Workspace\MIDE\firmware\/keypad.c:163: DELAY_ms(1);		  // Wait for some time(debounce Time);
	mov	dptr,#0x0001
	lcall	_DELAY_ms
;	D:\Workspace\MIDE\firmware\/keypad.c:165: M_ROW=0x0F;		  // After debounce time, perform the above operation
;	D:\Workspace\MIDE\firmware\/keypad.c:166: var_keyPress_u8=M_COL & 0x0F;	  // to ensure the Key press.
	mov	a,#0x0F
	mov	_P2,a
	anl	a,_P2
	mov	r2,a
;	D:\Workspace\MIDE\firmware\/keypad.c:168: }while(var_keyPress_u8==0x0F);
	cjne	r2,#0x0F,00112$
	sjmp	00101$
00112$:
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'KEYPAD_GetKey'
;------------------------------------------------------------
;var_keyPress_u8           Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/keypad.c:194: uint8_t KEYPAD_GetKey()
;	-----------------------------------------
;	 function KEYPAD_GetKey
;	-----------------------------------------
_KEYPAD_GetKey:
;	D:\Workspace\MIDE\firmware\/keypad.c:198: KEYPAD_WaitForKeyRelease();    // Wait for the previous key release
	lcall	_KEYPAD_WaitForKeyRelease
;	D:\Workspace\MIDE\firmware\/keypad.c:199: DELAY_ms(1);
	mov	dptr,#0x0001
	lcall	_DELAY_ms
;	D:\Workspace\MIDE\firmware\/keypad.c:201: KEYPAD_WaitForKeyPress();      // Wait for the new key press
	lcall	_KEYPAD_WaitForKeyPress
;	D:\Workspace\MIDE\firmware\/keypad.c:202: var_keyPress_u8 = keypad_ScanKey();        // Scan for the key pressed.
	lcall	_keypad_ScanKey
	mov	r2,dpl
;	D:\Workspace\MIDE\firmware\/keypad.c:204: switch(var_keyPress_u8)                       // Decode the key
	cjne	r2,#0x77,00137$
	ljmp	00113$
00137$:
	cjne	r2,#0x7B,00138$
	ljmp	00114$
00138$:
	cjne	r2,#0x7D,00139$
	ljmp	00115$
00139$:
	cjne	r2,#0x7E,00140$
	ljmp	00116$
00140$:
	cjne	r2,#0xB7,00141$
	sjmp	00109$
00141$:
	cjne	r2,#0xBB,00142$
	sjmp	00110$
00142$:
	cjne	r2,#0xBD,00143$
	sjmp	00111$
00143$:
	cjne	r2,#0xBE,00144$
	sjmp	00112$
00144$:
	cjne	r2,#0xD7,00145$
	sjmp	00105$
00145$:
	cjne	r2,#0xDB,00146$
	sjmp	00106$
00146$:
	cjne	r2,#0xDD,00147$
	sjmp	00107$
00147$:
	cjne	r2,#0xDE,00148$
	sjmp	00108$
00148$:
	cjne	r2,#0xE7,00149$
	sjmp	00101$
00149$:
	cjne	r2,#0xEB,00150$
	sjmp	00102$
00150$:
	cjne	r2,#0xED,00151$
	sjmp	00103$
00151$:
;	D:\Workspace\MIDE\firmware\/keypad.c:206: case 0xe7: var_keyPress_u8='0'; break;
	cjne	r2,#0xEE,00117$
	sjmp	00104$
00101$:
	mov	r2,#0x30
;	D:\Workspace\MIDE\firmware\/keypad.c:207: case 0xeb: var_keyPress_u8='1'; break;
	sjmp	00118$
00102$:
	mov	r2,#0x31
;	D:\Workspace\MIDE\firmware\/keypad.c:208: case 0xed: var_keyPress_u8='2'; break;
	sjmp	00118$
00103$:
	mov	r2,#0x32
;	D:\Workspace\MIDE\firmware\/keypad.c:209: case 0xee: var_keyPress_u8='3'; break;
	sjmp	00118$
00104$:
	mov	r2,#0x33
;	D:\Workspace\MIDE\firmware\/keypad.c:210: case 0xd7: var_keyPress_u8='4'; break;
	sjmp	00118$
00105$:
	mov	r2,#0x34
;	D:\Workspace\MIDE\firmware\/keypad.c:211: case 0xdb: var_keyPress_u8='5'; break;
	sjmp	00118$
00106$:
	mov	r2,#0x35
;	D:\Workspace\MIDE\firmware\/keypad.c:212: case 0xdd: var_keyPress_u8='6'; break;
	sjmp	00118$
00107$:
	mov	r2,#0x36
;	D:\Workspace\MIDE\firmware\/keypad.c:213: case 0xde: var_keyPress_u8='7'; break;
	sjmp	00118$
00108$:
	mov	r2,#0x37
;	D:\Workspace\MIDE\firmware\/keypad.c:214: case 0xb7: var_keyPress_u8='8'; break;
	sjmp	00118$
00109$:
	mov	r2,#0x38
;	D:\Workspace\MIDE\firmware\/keypad.c:215: case 0xbb: var_keyPress_u8='9'; break;
	sjmp	00118$
00110$:
	mov	r2,#0x39
;	D:\Workspace\MIDE\firmware\/keypad.c:216: case 0xbd: var_keyPress_u8='A'; break;
	sjmp	00118$
00111$:
	mov	r2,#0x41
;	D:\Workspace\MIDE\firmware\/keypad.c:217: case 0xbe: var_keyPress_u8='B'; break;
	sjmp	00118$
00112$:
	mov	r2,#0x42
;	D:\Workspace\MIDE\firmware\/keypad.c:218: case 0x77: var_keyPress_u8='C'; break;
	sjmp	00118$
00113$:
	mov	r2,#0x43
;	D:\Workspace\MIDE\firmware\/keypad.c:219: case 0x7b: var_keyPress_u8='D'; break;
	sjmp	00118$
00114$:
	mov	r2,#0x44
;	D:\Workspace\MIDE\firmware\/keypad.c:220: case 0x7d: var_keyPress_u8='E'; break;
	sjmp	00118$
00115$:
	mov	r2,#0x45
;	D:\Workspace\MIDE\firmware\/keypad.c:221: case 0x7e: var_keyPress_u8='F'; break;
	sjmp	00118$
00116$:
	mov	r2,#0x46
;	D:\Workspace\MIDE\firmware\/keypad.c:222: default  : var_keyPress_u8='z'; break;
	sjmp	00118$
00117$:
	mov	r2,#0x7A
;	D:\Workspace\MIDE\firmware\/keypad.c:223: }
00118$:
;	D:\Workspace\MIDE\firmware\/keypad.c:224: return(var_keyPress_u8);                      // Return the key
	mov	dpl,r2
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'keypad_ScanKey'
;------------------------------------------------------------
;var_keyScanCode_u8        Allocated to registers r2 
;i                         Allocated to registers r3 
;var_keyPress_u8           Allocated to stack - offset 1
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/keypad.c:246: static uint8_t keypad_ScanKey()
;	-----------------------------------------
;	 function keypad_ScanKey
;	-----------------------------------------
_keypad_ScanKey:
	push	_bp
	mov	_bp,sp
	inc	sp
;	D:\Workspace\MIDE\firmware\/keypad.c:249: uint8_t var_keyScanCode_u8 = 0xEF,i, var_keyPress_u8;
	mov	r2,#0xEF
;	D:\Workspace\MIDE\firmware\/keypad.c:251: for(i=0;i<0x04;i++)                // Scan All the 4-Rows for key press
	mov	r3,#0x00
00103$:
	cjne	r3,#0x04,00113$
00113$:
	jnc	00106$
;	D:\Workspace\MIDE\firmware\/keypad.c:253: M_ROW=var_keyScanCode_u8;        // Select 1-Row at a time for Scanning the Key
	mov	_P2,r2
;	D:\Workspace\MIDE\firmware\/keypad.c:254: DELAY_ms(1);
	mov	dptr,#0x0001
	push	ar2
	push	ar3
	lcall	_DELAY_ms
	pop	ar3
	pop	ar2
;	D:\Workspace\MIDE\firmware\/keypad.c:255: var_keyPress_u8=M_COL & 0x0F;    // Read the Column, for key press
	mov	a,#0x0F
	anl	a,_P2
	mov	r5,a
;	D:\Workspace\MIDE\firmware\/keypad.c:257: if(var_keyPress_u8!=0x0F)        // If the KEY press is detected for the selected
	cjne	r5,#0x0F,00106$
;	D:\Workspace\MIDE\firmware\/keypad.c:260: var_keyScanCode_u8=((var_keyScanCode_u8<<1)+0x01); // Rotate the ScanKey to SCAN the remaining Rows
	mov	a,r2
	add	a,r2
	mov	r4,a
	inc	a
	mov	r2,a
;	D:\Workspace\MIDE\firmware\/keypad.c:251: for(i=0;i<0x04;i++)                // Scan All the 4-Rows for key press
	inc	r3
	sjmp	00103$
00106$:
;	D:\Workspace\MIDE\firmware\/keypad.c:262: var_keyPress_u8 = var_keyPress_u8 + (var_keyScanCode_u8 & 0xf0); // Return the row and COL status to decode the key
	anl	ar2,#0xF0
	mov	a,r2
	add	a,r5
;	D:\Workspace\MIDE\firmware\/keypad.c:263: return(var_keyPress_u8);
	mov	dpl,a
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'EEPROM_WriteByte'
;------------------------------------------------------------
;var_eepromData_u8         Allocated to stack - offset -3
;var_eepromAddress_u16     Allocated to registers r2 r3 
;var_eepromLowerAddress_u8 Allocated to registers r4 
;var_eepromHigherAddress_u8 Allocated to registers r2 
;var_eepromPageNumber_u8   Allocated to stack - offset 5
;var_eepromId_u8           Allocated to registers 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/eeprom.c:94: void EEPROM_WriteByte(uint16_t var_eepromAddress_u16, uint8_t var_eepromData_u8)
;	-----------------------------------------
;	 function EEPROM_WriteByte
;	-----------------------------------------
_EEPROM_WriteByte:
	push	_bp
	mov	_bp,sp
	mov	r2,dpl
	mov	r3,dph
;	D:\Workspace\MIDE\firmware\/eeprom.c:102: if(var_eepromAddress_u16 < C_MaxEepromSize_U16)	
	mov	a,#0x100 - 0x10
	add	a,r3
	jc	00103$
;	D:\Workspace\MIDE\firmware\/eeprom.c:104: var_eepromLowerAddress_u8 = util_ExtractByte0to8(var_eepromAddress_u16);
	mov	ar4,r2
;	D:\Workspace\MIDE\firmware\/eeprom.c:110: var_eepromHigherAddress_u8 = util_ExtractByte8to16(var_eepromAddress_u16);
	mov	ar2,r3
;	D:\Workspace\MIDE\firmware\/eeprom.c:113: I2C_Start();                       // Start i2c communication
	push	ar2
	push	ar4
	lcall	_I2C_Start
;	D:\Workspace\MIDE\firmware\/eeprom.c:115: I2C_Write(var_eepromId_u8); 
	mov	dpl,#0xA0
	lcall	_I2C_Write
	pop	ar4
	pop	ar2
;	D:\Workspace\MIDE\firmware\/eeprom.c:117: I2C_Write(var_eepromHigherAddress_u8);
	mov	dpl,r2
	push	ar4
	lcall	_I2C_Write
	pop	ar4
;	D:\Workspace\MIDE\firmware\/eeprom.c:119: I2C_Write(var_eepromLowerAddress_u8); // Select the Specified EEPROM address of At24xx
	mov	dpl,r4
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/eeprom.c:120: I2C_Write(var_eepromData_u8);         // Write the data at specified address
	mov	a,_bp
	add	a,#0xfd
	mov	r0,a
	mov	dpl,@r0
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/eeprom.c:121: I2C_Stop();                           // Stop i2c communication after Writing the data
	lcall	_I2C_Stop
;	D:\Workspace\MIDE\firmware\/eeprom.c:123: DELAY_ms(10);                         // Write operation takes max 5ms, refer At24xx data sheet 
	mov	dptr,#0x000A
	lcall	_DELAY_ms
00103$:
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'EEPROM_ReadByte'
;------------------------------------------------------------
;var_eepromAddress_u16     Allocated to registers r2 r3 
;var_eepromLowerAddress_u8 Allocated to registers r5 
;var_eepromHigherAddress_u8 Allocated to registers r2 
;var_eepromPageNumber_u8   Allocated to stack - offset 5
;var_eepromData_u8         Allocated to registers r4 
;var_eepromId_u8           Allocated to registers 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/eeprom.c:179: uint8_t EEPROM_ReadByte(uint16_t var_eepromAddress_u16)
;	-----------------------------------------
;	 function EEPROM_ReadByte
;	-----------------------------------------
_EEPROM_ReadByte:
	mov	r2,dpl
	mov	r3,dph
;	D:\Workspace\MIDE\firmware\/eeprom.c:184: uint8_t var_eepromData_u8 = 0x00;
	mov	r4,#0x00
;	D:\Workspace\MIDE\firmware\/eeprom.c:187: if(var_eepromAddress_u16 < C_MaxEepromSize_U16)	
	mov	a,#0x100 - 0x10
	add	a,r3
	jc	00102$
;	D:\Workspace\MIDE\firmware\/eeprom.c:189: var_eepromLowerAddress_u8 = util_ExtractByte0to8(var_eepromAddress_u16);
	mov	ar5,r2
;	D:\Workspace\MIDE\firmware\/eeprom.c:195: var_eepromHigherAddress_u8 = util_ExtractByte8to16(var_eepromAddress_u16);
	mov	ar2,r3
;	D:\Workspace\MIDE\firmware\/eeprom.c:198: I2C_Start();                       // Start i2c communication
	push	ar2
	push	ar5
	lcall	_I2C_Start
;	D:\Workspace\MIDE\firmware\/eeprom.c:200: I2C_Write(var_eepromId_u8); 
	mov	dpl,#0xA0
	lcall	_I2C_Write
	pop	ar5
	pop	ar2
;	D:\Workspace\MIDE\firmware\/eeprom.c:202: I2C_Write(var_eepromHigherAddress_u8);
	mov	dpl,r2
	push	ar5
	lcall	_I2C_Write
	pop	ar5
;	D:\Workspace\MIDE\firmware\/eeprom.c:204: I2C_Write(var_eepromLowerAddress_u8); // Select the Specified EEPROM address of At24xx
	mov	dpl,r5
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/eeprom.c:206: I2C_Start();                          // Start i2c communication after selecting the address
	lcall	_I2C_Start
;	D:\Workspace\MIDE\firmware\/eeprom.c:207: I2C_Write(var_eepromId_u8 | 0x01);    // connect to At24xx(read) by sending its ID on I2c Bus
	mov	dpl,#0xA1
	lcall	_I2C_Write
;	D:\Workspace\MIDE\firmware\/eeprom.c:208: var_eepromData_u8 = I2C_Read(0);      // Read the data from specified address
	mov	dpl,#0x00
	lcall	_I2C_Read
	mov	r2,dpl
	mov	ar4,r2
;	D:\Workspace\MIDE\firmware\/eeprom.c:209: I2C_Stop();                           // Stop i2c communication after Reading the data
	push	ar4
	lcall	_I2C_Stop
;	D:\Workspace\MIDE\firmware\/eeprom.c:210: DELAY_us(10);
	mov	dptr,#0x000A
	lcall	_DELAY_us
	pop	ar4
00102$:
;	D:\Workspace\MIDE\firmware\/eeprom.c:213: return var_eepromData_u8;             // Return the data read from eeprom
	mov	dpl,r4
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'EEPROM_WriteString'
;------------------------------------------------------------
;ptr_stringPointer_u8      Allocated to stack - offset -5
;var_eepromAddress_u16     Allocated to registers r2 r3 
;sloc0                     Allocated to stack - offset 1
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/eeprom.c:297: void EEPROM_WriteString(uint16_t var_eepromAddress_u16, char *ptr_stringPointer_u8)
;	-----------------------------------------
;	 function EEPROM_WriteString
;	-----------------------------------------
_EEPROM_WriteString:
	push	_bp
	mov	_bp,sp
	inc	sp
	inc	sp
	mov	r2,dpl
	mov	r3,dph
;	D:\Workspace\MIDE\firmware\/eeprom.c:300: do
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
	mov	r0,_bp
	inc	r0
	mov	@r0,ar2
	inc	r0
	mov	@r0,ar3
00101$:
;	D:\Workspace\MIDE\firmware\/eeprom.c:302: EEPROM_WriteByte(var_eepromAddress_u16,*ptr_stringPointer_u8); //Write a byte from RAM to EEPROM
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	lcall	__gptrget
	mov	r7,a
	inc	dptr
	mov	r4,dpl
	mov	r5,dph
	push	ar4
	push	ar5
	push	ar6
	push	ar7
	mov	r0,_bp
	inc	r0
	mov	dpl,@r0
	inc	r0
	mov	dph,@r0
	lcall	_EEPROM_WriteByte
	dec	sp
	pop	ar6
	pop	ar5
	pop	ar4
;	D:\Workspace\MIDE\firmware\/eeprom.c:303: ptr_stringPointer_u8++;								//Increment the RAM Address
;	D:\Workspace\MIDE\firmware\/eeprom.c:304: var_eepromAddress_u16++;								//Increment the Eeprom Address
	mov	r0,_bp
	inc	r0
	inc	@r0
	cjne	@r0,#0x00,00108$
	inc	r0
	inc	@r0
00108$:
;	D:\Workspace\MIDE\firmware\/eeprom.c:305: }while(*(ptr_stringPointer_u8-1) !=0);
	mov	a,r4
	add	a,#0xff
	mov	r7,a
	mov	a,r5
	addc	a,#0xff
	mov	r2,a
	mov	ar3,r6
	mov	dpl,r7
	mov	dph,r2
	mov	b,r3
	lcall	__gptrget
	jnz	00101$
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'EEPROM_ReadString'
;------------------------------------------------------------
;ptr_destStringAddress_u8  Allocated to stack - offset -5
;var_eepromAddress_u16     Allocated to registers r2 r3 
;eeprom_data               Allocated to registers r7 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\/eeprom.c:324: void EEPROM_ReadString(uint16_t var_eepromAddress_u16, char *ptr_destStringAddress_u8)
;	-----------------------------------------
;	 function EEPROM_ReadString
;	-----------------------------------------
_EEPROM_ReadString:
	push	_bp
	mov	_bp,sp
	mov	r2,dpl
	mov	r3,dph
;	D:\Workspace\MIDE\firmware\/eeprom.c:328: do
	mov	a,_bp
	add	a,#0xfb
	mov	r0,a
	mov	ar4,@r0
	inc	r0
	mov	ar5,@r0
	inc	r0
	mov	ar6,@r0
00101$:
;	D:\Workspace\MIDE\firmware\/eeprom.c:330: eeprom_data = EEPROM_ReadByte(var_eepromAddress_u16); //Read a byte from EEPROM to RAM
	mov	dpl,r2
	mov	dph,r3
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	push	ar6
	lcall	_EEPROM_ReadByte
	mov	r7,dpl
	pop	ar6
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	D:\Workspace\MIDE\firmware\/eeprom.c:331: *ptr_destStringAddress_u8 = eeprom_data;			 //Copy the data into String Buffer
	mov	dpl,r4
	mov	dph,r5
	mov	b,r6
	mov	a,r7
	lcall	__gptrput
	inc	dptr
	mov	r4,dpl
	mov	r5,dph
;	D:\Workspace\MIDE\firmware\/eeprom.c:332: ptr_destStringAddress_u8++;						 //Increment the RAM Address
;	D:\Workspace\MIDE\firmware\/eeprom.c:333: var_eepromAddress_u16++;							 //Increment the Eeprom Address
	inc	r2
	cjne	r2,#0x00,00108$
	inc	r3
00108$:
;	D:\Workspace\MIDE\firmware\/eeprom.c:334: }while(eeprom_data!=0);
	mov	a,r7
	jnz	00101$
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\main.c:50: void main() 
;	-----------------------------------------
;	 function main
;	-----------------------------------------
_main:
;	D:\Workspace\MIDE\firmware\main.c:52: UART_Init(9600);
	mov	dptr,#0x2580
	clr	a
	mov	b,a
	lcall	_UART_Init
;	D:\Workspace\MIDE\firmware\main.c:53: UART_TxString("\n\rTest menu Utra x51 v1.1\r\n 1:GPIO Blink\r\n 2:LCD \n\r 3:7-Segment\n\r 4:RTC\n\r 5:EEPROM\n\r 6:ADC\n\r 7:Keypad \n\r Enter option:");
	mov	dptr,#__str_0
	mov	b,#0x80
	lcall	_UART_TxString
;	D:\Workspace\MIDE\firmware\main.c:54: UART_TxString("\n\rReset the board after test is done");
	mov	dptr,#__str_1
	mov	b,#0x80
	lcall	_UART_TxString
;	D:\Workspace\MIDE\firmware\main.c:55: mm_option = UART_RxChar();
	lcall	_UART_RxChar
	mov	_mm_option,dpl
;	D:\Workspace\MIDE\firmware\main.c:56: while(1)
00111$:
;	D:\Workspace\MIDE\firmware\main.c:58: switch(mm_option)
	clr	c
	mov	a,_mm_option
	xrl	a,#0x80
	subb	a,#0xb1
	jc	00111$
	mov	a,#(0x37 ^ 0x80)
	mov	b,_mm_option
	xrl	b,#0x80
	subb	a,b
	jc	00111$
	mov	a,_mm_option
	add	a,#0xcf
	mov	r2,a
	add	a,acc
	add	a,r2
	mov	dptr,#00120$
	jmp	@a+dptr
00120$:
	ljmp	00101$
	ljmp	00102$
	ljmp	00103$
	ljmp	00104$
	ljmp	00105$
	ljmp	00106$
	ljmp	00107$
;	D:\Workspace\MIDE\firmware\main.c:60: case '1': gpio_test(); break;
00101$:
	lcall	_gpio_test
;	D:\Workspace\MIDE\firmware\main.c:62: case '2': LCD_test(); break;
	sjmp	00111$
00102$:
	lcall	_LCD_test
;	D:\Workspace\MIDE\firmware\main.c:64: case '3': seg_test(); break;
	sjmp	00111$
00103$:
	lcall	_seg_test
;	D:\Workspace\MIDE\firmware\main.c:66: case '4': rtc_test(); break; 
	sjmp	00111$
00104$:
	lcall	_rtc_test
;	D:\Workspace\MIDE\firmware\main.c:68: case '5': eeprom_test(); break; //eeprom
	sjmp	00111$
00105$:
	lcall	_eeprom_test
;	D:\Workspace\MIDE\firmware\main.c:70: case '6': adc_test(); break;
	sjmp	00111$
00106$:
	lcall	_adc_test
;	D:\Workspace\MIDE\firmware\main.c:72: case '7': keypad_test();break;
	sjmp	00111$
00107$:
	lcall	_keypad_test
;	D:\Workspace\MIDE\firmware\main.c:77: }
	sjmp	00111$
;------------------------------------------------------------
;Allocation info for local variables in function 'gpio_test'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\main.c:82: void gpio_test()
;	-----------------------------------------
;	 function gpio_test
;	-----------------------------------------
_gpio_test:
;	D:\Workspace\MIDE\firmware\main.c:84: UART_Printf("\n\rConnect any IO Pins to buzzer, relays, leds ");
	mov	a,#__str_2
	push	acc
	mov	a,#(__str_2 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	dec	sp
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:85: UART_Printf("\n\rMake connections and hit 'k' to test ");
	mov	a,#__str_3
	push	acc
	mov	a,#(__str_3 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	dec	sp
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:86: while(UART_RxChar()!='k');
00101$:
	lcall	_UART_RxChar
	mov	r2,dpl
	cjne	r2,#0x6B,00101$
;	D:\Workspace\MIDE\firmware\main.c:87: while(1)
00105$:
;	D:\Workspace\MIDE\firmware\main.c:90: P0= P1 = P2 =P3= 0xff;	   
	mov	_P3,#0xFF
	mov	_P2,#0xFF
	mov	_P1,#0xFF
	mov	_P0,#0xFF
;	D:\Workspace\MIDE\firmware\main.c:91: DELAY_sec(1);
	mov	dptr,#0x0001
	lcall	_DELAY_sec
;	D:\Workspace\MIDE\firmware\main.c:93: P0= P1 = P2 =P3= 0x00;;
	mov	_P3,#0x00
	mov	_P2,#0x00
	mov	_P1,#0x00
	mov	_P0,#0x00
;	D:\Workspace\MIDE\firmware\main.c:94: DELAY_sec(1);
	mov	dptr,#0x0001
	lcall	_DELAY_sec
	sjmp	00105$
;------------------------------------------------------------
;Allocation info for local variables in function 'LCD_test'
;------------------------------------------------------------
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\main.c:99: void LCD_test()
;	-----------------------------------------
;	 function LCD_test
;	-----------------------------------------
_LCD_test:
;	D:\Workspace\MIDE\firmware\main.c:101: UART_TxString("\n\r LCD DataBus: P2 Control: RS-P0.0 RW-P0.1 E-P0.2 ");
	mov	dptr,#__str_4
	mov	b,#0x80
	lcall	_UART_TxString
;	D:\Workspace\MIDE\firmware\main.c:102: UART_Printf("\n\r Make connections and hit 'k' to test ");
	mov	a,#__str_5
	push	acc
	mov	a,#(__str_5 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	dec	sp
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:103: while(UART_RxChar()!='k');
00101$:
	lcall	_UART_RxChar
	mov	r2,dpl
	cjne	r2,#0x6B,00101$
;	D:\Workspace\MIDE\firmware\main.c:104: LCD_Init(8,2,16);
	mov	a,#0x10
	push	acc
	mov	a,#0x02
	push	acc
	mov	dpl,#0x08
	lcall	_LCD_Init
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:105: DELAY_ms(100);
	mov	dptr,#0x0064
	lcall	_DELAY_ms
;	D:\Workspace\MIDE\firmware\main.c:106: LCD_DisplayString("Explore Embedded!");
	mov	dptr,#__str_6
	mov	b,#0x80
	lcall	_LCD_DisplayString
;	D:\Workspace\MIDE\firmware\main.c:107: while(1);
00105$:
	sjmp	00105$
;------------------------------------------------------------
;Allocation info for local variables in function 'seg_test'
;------------------------------------------------------------
;seg_code                  Allocated to stack - offset 1
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\main.c:109: void seg_test()
;	-----------------------------------------
;	 function seg_test
;	-----------------------------------------
_seg_test:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x04
	mov	sp,a
;	D:\Workspace\MIDE\firmware\main.c:111: unsigned char seg_code[]={0xC0,0xF9,0xA4,0xB0}; 
	mov	r0,_bp
	inc	r0
	mov	@r0,#0xC0
	mov	a,r0
	inc	a
	mov	r1,a
	mov	@r1,#0xF9
	mov	a,#0x02
	add	a,r0
	mov	r2,a
	push	ar0
	mov	r0,ar2
	mov	@r0,#0xA4
	pop	ar0
	mov	a,#0x03
	add	a,r0
	mov	r3,a
	push	ar0
	mov	r0,ar3
	mov	@r0,#0xB0
	pop	ar0
;	D:\Workspace\MIDE\firmware\main.c:112: UART_TxString("\n\r Segment DataBus: P2 Seg select: S1->P0.0 S2->P0.1 S3->P0.2 S4->P0.4  ");
	mov	dptr,#__str_7
	mov	b,#0x80
	push	ar2
	push	ar3
	push	ar0
	push	ar1
	lcall	_UART_TxString
;	D:\Workspace\MIDE\firmware\main.c:113: UART_Printf("\n\rMake connections and hit 'k' to test! ");
	mov	a,#__str_8
	push	acc
	mov	a,#(__str_8 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	dec	sp
	dec	sp
	dec	sp
	pop	ar1
	pop	ar0
	pop	ar3
	pop	ar2
;	D:\Workspace\MIDE\firmware\main.c:114: while(UART_RxChar()!='k');
00101$:
	push	ar2
	push	ar3
	push	ar0
	push	ar1
	lcall	_UART_RxChar
	mov	r4,dpl
	pop	ar1
	pop	ar0
	pop	ar3
	pop	ar2
	cjne	r4,#0x6B,00101$
;	D:\Workspace\MIDE\firmware\main.c:115: while(1)
00105$:
;	D:\Workspace\MIDE\firmware\main.c:117: SegmentSlection=SegOne;
	mov	_P0,#0x01
;	D:\Workspace\MIDE\firmware\main.c:118: SegmentValue = seg_code[0];
	mov	_P2,@r0
;	D:\Workspace\MIDE\firmware\main.c:119: DELAY_us(10); 
	mov	dptr,#0x000A
	push	ar2
	push	ar3
	push	ar0
	push	ar1
	lcall	_DELAY_us
	pop	ar1
;	D:\Workspace\MIDE\firmware\main.c:120: SegmentSlection=SegTwo;
	mov	_P0,#0x02
;	D:\Workspace\MIDE\firmware\main.c:121: SegmentValue = seg_code[1];
	mov	_P2,@r1
;	D:\Workspace\MIDE\firmware\main.c:122: DELAY_us(10);
	mov	dptr,#0x000A
	push	ar1
	lcall	_DELAY_us
	pop	ar1
	pop	ar0
	pop	ar3
	pop	ar2
;	D:\Workspace\MIDE\firmware\main.c:123: SegmentSlection=SegThree;
	mov	_P0,#0x04
;	D:\Workspace\MIDE\firmware\main.c:124: SegmentValue = seg_code[2];
	push	ar0
	mov	r0,ar2
	mov	_P2,@r0
	pop	ar0
;	D:\Workspace\MIDE\firmware\main.c:125: DELAY_us(10);	
	mov	dptr,#0x000A
	push	ar2
	push	ar3
	push	ar0
	push	ar1
	lcall	_DELAY_us
	pop	ar1
	pop	ar0
	pop	ar3
	pop	ar2
;	D:\Workspace\MIDE\firmware\main.c:126: SegmentSlection=SegFour;  
	mov	_P0,#0x08
;	D:\Workspace\MIDE\firmware\main.c:127: SegmentValue = seg_code[3];
	push	ar0
	mov	r0,ar3
	mov	_P2,@r0
	pop	ar0
;	D:\Workspace\MIDE\firmware\main.c:128: DELAY_us(10);
	mov	dptr,#0x000A
	push	ar2
	push	ar3
	push	ar0
	push	ar1
	lcall	_DELAY_us
	pop	ar1
	pop	ar0
	pop	ar3
	pop	ar2
	ljmp	00105$
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'rtc_test'
;------------------------------------------------------------
;sec                       Allocated to stack - offset 1
;min                       Allocated to stack - offset 2
;hour                      Allocated to stack - offset 3
;day                       Allocated to stack - offset 4
;month                     Allocated to stack - offset 5
;year                      Allocated to stack - offset 6
;sloc0                     Allocated to stack - offset 7
;sloc1                     Allocated to stack - offset 10
;sloc2                     Allocated to stack - offset 12
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\main.c:132: void rtc_test()
;	-----------------------------------------
;	 function rtc_test
;	-----------------------------------------
_rtc_test:
	push	_bp
	mov	a,sp
	mov	_bp,a
	add	a,#0x0d
	mov	sp,a
;	D:\Workspace\MIDE\firmware\main.c:135: UART_Printf("\n\rConnections SCL->P0.6 SDA->P0.7");
	mov	a,#__str_9
	push	acc
	mov	a,#(__str_9 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	dec	sp
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:136: UART_Printf("\n\r Make connections and hit 'k' to test! ");
	mov	a,#__str_10
	push	acc
	mov	a,#(__str_10 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	dec	sp
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:137: while(UART_RxChar()!='k');   
00101$:
	lcall	_UART_RxChar
	mov	r2,dpl
	cjne	r2,#0x6B,00101$
;	D:\Workspace\MIDE\firmware\main.c:139: RTC_Init();
	lcall	_RTC_Init
;	D:\Workspace\MIDE\firmware\main.c:144: RTC_SetTime(0x10,0x40,0x00);  //  10:40:20 am
	clr	a
	push	acc
	mov	a,#0x40
	push	acc
	mov	dpl,#0x10
	lcall	_RTC_SetTime
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:145: RTC_SetDate(0x01,0x01,0x15);  //  1st Jan 2015
	mov	a,#0x15
	push	acc
	mov	a,#0x01
	push	acc
	mov	dpl,#0x01
	lcall	_RTC_SetDate
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:150: while(1)
00105$:
;	D:\Workspace\MIDE\firmware\main.c:153: RTC_GetTime(&hour,&min,&sec);      
	mov	r2,_bp
	inc	r2
	mov	r3,#0x00
	mov	r4,#0x40
	mov	a,_bp
	add	a,#0x02
	mov	r5,a
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	@r0,ar5
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x40
	mov	a,_bp
	add	a,#0x03
	mov	r5,a
	mov	r6,#0x00
	mov	r7,#0x40
	push	ar2
	push	ar3
	push	ar4
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	_RTC_GetTime
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
;	D:\Workspace\MIDE\firmware\main.c:154: RTC_GetDate(&day,&month,&year);        
	mov	a,_bp
	add	a,#0x06
	mov	r2,a
	mov	r3,#0x00
	mov	r4,#0x40
	mov	a,_bp
	add	a,#0x05
	mov	r5,a
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	@r0,ar5
	inc	r0
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x40
	mov	a,_bp
	add	a,#0x04
	mov	r5,a
	mov	r6,#0x00
	mov	r7,#0x40
	push	ar2
	push	ar3
	push	ar4
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	_RTC_GetDate
	mov	a,sp
	add	a,#0xfa
	mov	sp,a
;	D:\Workspace\MIDE\firmware\main.c:156: UART_Printf("\n\rtime:%2x:%2x:%2x  \nDate:%2x/%2x/%2x",(uint16_t)hour,(uint16_t)min,(uint16_t)sec,(uint16_t)day,(uint16_t)month,(uint16_t)year);
	mov	a,_bp
	add	a,#0x06
	mov	r0,a
	mov	ar2,@r0
	mov	r3,#0x00
	mov	a,_bp
	add	a,#0x05
	mov	r0,a
	mov	ar4,@r0
	mov	r5,#0x00
	mov	a,_bp
	add	a,#0x04
	mov	r0,a
	mov	a,_bp
	add	a,#0x07
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r1
	mov	@r1,#0x00
	mov	r0,_bp
	inc	r0
	mov	a,_bp
	add	a,#0x0a
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r1
	mov	@r1,#0x00
	mov	r0,_bp
	inc	r0
	inc	r0
	mov	a,_bp
	add	a,#0x0c
	mov	r1,a
	mov	a,@r0
	mov	@r1,a
	inc	r1
	mov	@r1,#0x00
	mov	a,_bp
	add	a,#0x03
	mov	r0,a
	mov	ar6,@r0
	mov	r7,#0x00
	push	ar2
	push	ar3
	push	ar4
	push	ar5
	mov	a,_bp
	add	a,#0x07
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x0a
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	mov	a,_bp
	add	a,#0x0c
	mov	r0,a
	mov	a,@r0
	push	acc
	inc	r0
	mov	a,@r0
	push	acc
	push	ar6
	push	ar7
	mov	a,#__str_11
	push	acc
	mov	a,#(__str_11 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	mov	a,sp
	add	a,#0xf1
	mov	sp,a
	ljmp	00105$
	mov	sp,_bp
	pop	_bp
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'eeprom_test'
;------------------------------------------------------------
;eeprom_address            Allocated to registers 
;write_char                Allocated to registers 
;read_char                 Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\main.c:163: void eeprom_test()
;	-----------------------------------------
;	 function eeprom_test
;	-----------------------------------------
_eeprom_test:
;	D:\Workspace\MIDE\firmware\main.c:167: UART_Printf("Connections SCL->P0.6 SDA->P0.7");
	mov	a,#__str_12
	push	acc
	mov	a,#(__str_12 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	dec	sp
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:168: UART_Printf("Make connections and hit 'k' to test! ");
	mov	a,#__str_13
	push	acc
	mov	a,#(__str_13 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	dec	sp
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:169: while(UART_RxChar()!='k');
00101$:
	lcall	_UART_RxChar
	mov	r2,dpl
	cjne	r2,#0x6B,00101$
;	D:\Workspace\MIDE\firmware\main.c:170: UART_TxString("\n\rEeprom Write: ");      //Print the message on UART
	mov	dptr,#__str_14
	mov	b,#0x80
	lcall	_UART_TxString
;	D:\Workspace\MIDE\firmware\main.c:171: UART_TxChar(write_char);			         //Print the char to be written 
	mov	dpl,#0x58
	lcall	_UART_TxChar
;	D:\Workspace\MIDE\firmware\main.c:172: EEPROM_WriteByte(eeprom_address,write_char);	// Write the data at memoryLocation	0x00
	mov	a,#0x58
	push	acc
	mov	dptr,#0x0000
	lcall	_EEPROM_WriteByte
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:174: UART_TxString("  Eeprom Read: ");            //Print the message on UART
	mov	dptr,#__str_15
	mov	b,#0x80
	lcall	_UART_TxString
;	D:\Workspace\MIDE\firmware\main.c:175: read_char = EEPROM_ReadByte(eeprom_address);	// Read the data from memoryLocation 0x00
	mov	dptr,#0x0000
	lcall	_EEPROM_ReadByte
;	D:\Workspace\MIDE\firmware\main.c:176: UART_TxChar(read_char);	
	ljmp	_UART_TxChar
;------------------------------------------------------------
;Allocation info for local variables in function 'adc_test'
;------------------------------------------------------------
;temp                      Allocated to registers 
;light                     Allocated to registers 
;pot                       Allocated to registers 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\main.c:180: void adc_test()
;	-----------------------------------------
;	 function adc_test
;	-----------------------------------------
_adc_test:
;	D:\Workspace\MIDE\firmware\main.c:183: UART_Printf("\n\rConnections: DataBus P1 Control: adc_A->P0.0 adc_B->P0.1 adc_C->P0.2 adc_ALE->P.3 adc_Start->P.4 adc_EOC->P1.5 adc_OE->P1.6");
	mov	a,#__str_16
	push	acc
	mov	a,#(__str_16 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	dec	sp
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:184: UART_Printf("\n\rMake connections and hit 'k' to test!");
	mov	a,#__str_17
	push	acc
	mov	a,#(__str_17 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	dec	sp
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:185: while(UART_RxChar()!='k');
00101$:
	lcall	_UART_RxChar
	mov	r2,dpl
	cjne	r2,#0x6B,00101$
;	D:\Workspace\MIDE\firmware\main.c:186: ADC_Init();
	lcall	_ADC_Init
;	D:\Workspace\MIDE\firmware\main.c:188: while(1)
00105$:
;	D:\Workspace\MIDE\firmware\main.c:190: temp = ADC_GetAdcValue(0);
	mov	dpl,#0x00
	lcall	_ADC_GetAdcValue
	mov	r2,dpl
	mov	r3,dph
;	D:\Workspace\MIDE\firmware\main.c:191: pot = ADC_GetAdcValue(1);
	mov	dpl,#0x01
	push	ar2
	push	ar3
	lcall	_ADC_GetAdcValue
	mov	r4,dpl
	mov	r5,dph
;	D:\Workspace\MIDE\firmware\main.c:192: light = ADC_GetAdcValue(2);
	mov	dpl,#0x02
	push	ar4
	push	ar5
	lcall	_ADC_GetAdcValue
	mov	r6,dpl
	mov	r7,dph
	pop	ar5
	pop	ar4
	pop	ar3
	pop	ar2
;	D:\Workspace\MIDE\firmware\main.c:193: UART_Printf("\n\rtemp:%3d pot:%3d light:%3d", temp,pot,light);
	push	ar6
	push	ar7
	push	ar4
	push	ar5
	push	ar2
	push	ar3
	mov	a,#__str_18
	push	acc
	mov	a,#(__str_18 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	mov	a,sp
	add	a,#0xf7
	mov	sp,a
	sjmp	00105$
;------------------------------------------------------------
;Allocation info for local variables in function 'keypad_test'
;------------------------------------------------------------
;key                       Allocated to registers r2 
;------------------------------------------------------------
;	D:\Workspace\MIDE\firmware\main.c:198: void keypad_test()
;	-----------------------------------------
;	 function keypad_test
;	-----------------------------------------
_keypad_test:
;	D:\Workspace\MIDE\firmware\main.c:201: UART_Printf("\n\rConnections: Port 2");
	mov	a,#__str_19
	push	acc
	mov	a,#(__str_19 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	dec	sp
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:202: UART_Printf("\n\rMake connections and hit 'k' to test!");
	mov	a,#__str_17
	push	acc
	mov	a,#(__str_17 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	dec	sp
	dec	sp
	dec	sp
;	D:\Workspace\MIDE\firmware\main.c:203: while(UART_RxChar()!='k');
00101$:
	lcall	_UART_RxChar
	mov	r2,dpl
	cjne	r2,#0x6B,00101$
;	D:\Workspace\MIDE\firmware\main.c:204: KEYPAD_Init();
	lcall	_KEYPAD_Init
;	D:\Workspace\MIDE\firmware\main.c:205: while(1)
00105$:
;	D:\Workspace\MIDE\firmware\main.c:207: key = KEYPAD_GetKey();
	lcall	_KEYPAD_GetKey
	mov	r2,dpl
;	D:\Workspace\MIDE\firmware\main.c:208: UART_Printf("\n\r Key:%c", key);
	mov	r3,#0x00
	push	ar2
	push	ar3
	mov	a,#__str_20
	push	acc
	mov	a,#(__str_20 >> 8)
	push	acc
	mov	a,#0x80
	push	acc
	lcall	_UART_Printf
	mov	a,sp
	add	a,#0xfb
	mov	sp,a
	sjmp	00105$
	.area CSEG    (CODE)
	.area CONST   (CODE)
__str_0:
	.db 0x0A
	.db 0x0D
	.ascii "Test menu Utra x51 v1.1"
	.db 0x0D
	.db 0x0A
	.ascii " 1:GPIO Blink"
	.db 0x0D
	.db 0x0A
	.ascii " 2:LCD "
	.db 0x0A
	.db 0x0D
	.ascii " 3:7-Segm"
	.ascii "ent"
	.db 0x0A
	.db 0x0D
	.ascii " 4:RTC"
	.db 0x0A
	.db 0x0D
	.ascii " 5:EEPROM"
	.db 0x0A
	.db 0x0D
	.ascii " 6:ADC"
	.db 0x0A
	.db 0x0D
	.ascii " 7:Keypad "
	.db 0x0A
	.db 0x0D
	.ascii " Enter option:"
	.db 0x00
__str_1:
	.db 0x0A
	.db 0x0D
	.ascii "Reset the board after test is done"
	.db 0x00
__str_2:
	.db 0x0A
	.db 0x0D
	.ascii "Connect any IO Pins to buzzer, relays, leds "
	.db 0x00
__str_3:
	.db 0x0A
	.db 0x0D
	.ascii "Make connections and hit 'k' to test "
	.db 0x00
__str_4:
	.db 0x0A
	.db 0x0D
	.ascii " LCD DataBus: P2 Control: RS-P0.0 RW-P0.1 E-P0.2 "
	.db 0x00
__str_5:
	.db 0x0A
	.db 0x0D
	.ascii " Make connections and hit 'k' to test "
	.db 0x00
__str_6:
	.ascii "Explore Embedded!"
	.db 0x00
__str_7:
	.db 0x0A
	.db 0x0D
	.ascii " Segment DataBus: P2 Seg select: S1->P0.0 S2->P0.1 S3->P0."
	.ascii "2 S4->P0.4  "
	.db 0x00
__str_8:
	.db 0x0A
	.db 0x0D
	.ascii "Make connections and hit 'k' to test! "
	.db 0x00
__str_9:
	.db 0x0A
	.db 0x0D
	.ascii "Connections SCL->P0.6 SDA->P0.7"
	.db 0x00
__str_10:
	.db 0x0A
	.db 0x0D
	.ascii " Make connections and hit 'k' to test! "
	.db 0x00
__str_11:
	.db 0x0A
	.db 0x0D
	.ascii "time:%2x:%2x:%2x  "
	.db 0x0A
	.ascii "Date:%2x/%2x/%2x"
	.db 0x00
__str_12:
	.ascii "Connections SCL->P0.6 SDA->P0.7"
	.db 0x00
__str_13:
	.ascii "Make connections and hit 'k' to test! "
	.db 0x00
__str_14:
	.db 0x0A
	.db 0x0D
	.ascii "Eeprom Write: "
	.db 0x00
__str_15:
	.ascii "  Eeprom Read: "
	.db 0x00
__str_16:
	.db 0x0A
	.db 0x0D
	.ascii "Connections: DataBus P1 Control: adc_A->P0.0 adc_B->P0.1 a"
	.ascii "dc_C->P0.2 adc_ALE->P.3 adc_Start->P.4 adc_EOC->P1.5 adc_OE-"
	.ascii ">P1.6"
	.db 0x00
__str_17:
	.db 0x0A
	.db 0x0D
	.ascii "Make connections and hit 'k' to test!"
	.db 0x00
__str_18:
	.db 0x0A
	.db 0x0D
	.ascii "temp:%3d pot:%3d light:%3d"
	.db 0x00
__str_19:
	.db 0x0A
	.db 0x0D
	.ascii "Connections: Port 2"
	.db 0x00
__str_20:
	.db 0x0A
	.db 0x0D
	.ascii " Key:%c"
	.db 0x00
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
