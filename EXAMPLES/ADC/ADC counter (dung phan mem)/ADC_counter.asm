; Dang Manh Truong (MSSV 20134209)
; Chuong trinh thuc hien ADC (Analog to Digital Converter) dua tren nguyen ly dem (counter ADC)
; Bo dem duoc cai dat bang phan mem
; Tham khao: 
; [1] Microprocessor Interfacing Techniques - Austin Lesea, Rodnay Zaks
; [2] ADC0808 datasheet
; [3] 74LS590 datasheet
; [4] http://ecetutorials.com/digital-electronics/counter-type-adc-analog-to-digital-converter/
ADC_OUTPUT_PORT			EQU		P1
FEEDBACK_PORT			EQU		P1
EOC						EQU		P2.0 ; End of conversion (ket thuc chuyen doi)
; Cac che do cua LCD
LCD_CMD_WR				EQU 	0
LCD_DATA_WR				EQU		1
LCD_BUSY_RD				EQU		2
LCD_DATA_RD				EQU		3 

ORG				0h
LJMP			MAIN

MAIN:
MOV				A,#038h ; Khoi tao LCD 
ACALL			COMNWRT
_loop_forever:
MOV				A,#0 ; Khoi tao 
_keep_conversion:
MOV				FEEDBACK_PORT,A ; Gui ra DAC
NOP	; Cho 1 khoang thoi gian doi ket qua cua mach so sanh
NOP
NOP
NOP
NOP
NOP
NOP
NOP
NOP
JNB				EOC,_end_of_conversion
CJNE			A,#0FFh,_continue
JMP				_end_of_conversion
_continue: 
INC				A
JMP				_keep_conversion
_end_of_conversion:
; Ket thuc qua trinh chuyen doi: Hien thi ket qua
MOV				A,#1h  ; Xoa man hinh hien thi
ACALL			COMNWRT
MOV				A,#0Eh ; Bat hien thi, nhap nhay con tro
ACALL			COMNWRT
MOV				A,ADC_OUTPUT_PORT ; Doc du lieu tu ADC
CJNE			A,#0,_convert_number_for_display
MOV				R5,#0
MOV				R4,#0
MOV				R3,#0
JMP				_display_on_LCD
_convert_number_for_display:
MOV				B,#10 ; Chia cho 10
DIV				AB
MOV				R5,B  ; Cat so thap
MOV				B,#10
DIV				AB
MOV				R4,B  ; Cat so tiep theo
MOV				B,#10
DIV				AB
MOV				R3,B  ; Cat so cuoi cung   
_display_on_LCD:
MOV				DPTR,#LCD_VAL
MOV				A,R3
MOVC			A,@A+DPTR ; Hien thi chu so hang tram
ACALL			DATAWRT		  

MOV				A,R4
MOVC			A,@A+DPTR ; Hien thi chu so hang chuc
ACALL			DATAWRT
ACALL			DELAY

MOV				A,R5
MOVC			A,@A+DPTR ; Hien thi chu so hang don vi
ACALL			DATAWRT
ACALL			DELAY 
SJMP			_loop_forever
RET
	   
;-------------------------------
; Chuong trinh con gui lenh toi LCD
 COMNWRT:
MOV				R0,#LCD_CMD_WR
MOVX			@R0,A
ACALL			DELAY
RET
;-------------------------------

;-------------------------------
; Chuong trinh con gui 1 byte du lieu toi LCD
DATAWRT:
MOV				R0,#LCD_DATA_WR
MOVX			@R0,A
ACALL			DELAY
RET
;-------------------------------

;-------------------------------
; Chuong trinh con tao tre
DELAY:
MOV 			R6,#255
_NOP:
MOV 			R7,#255
DJNZ 			R7,$
DJNZ 			R6,_NOP
RET
;-------------------------------

ORG			500h
LCD_VAL:	DB		"0","1","2","3","4","5","6","7","8","9"

END