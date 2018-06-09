; Dang Manh Truong (MSSV 20134209)
; Chuong trinh thuc hien ADC (Analog to Digital Converter) dua tren nguyen ly xap xi lien tiep
; (successive approximation)
; Bo phan SAR (Successive Approximation Register) duoc thuc hien bang phan cung
; Tham khao: 
; [1] Microprocessor Interfacing Techniques - Austin Lesea, Rodnay Zaks
; [2] ADC0808 datasheet

CLOCK					EQU		P2.7
ADC_OUTPUT_PORT			EQU		P1
; Cac che do cua LCD
LCD_CMD_WR				EQU 	0
LCD_DATA_WR				EQU		1
LCD_BUSY_RD				EQU		2
LCD_DATA_RD				EQU		3 

ORG				0h
LJMP			MAIN
ORG				0003h
LJMP			ADC_COMPLETED ; Ket thuc chuyen doi 

MAIN:
MOV				ADC_OUTPUT_PORT,#0FFh
MOV				IE,#10000001b ; Su dung ngat 0
SETB			TCON.0 ; Ngat theo xung cao-xuong-thap
MOV				A,#038h ; Khoi tao LCD 
ACALL			COMNWRT
_loop_forever:
CLR				CLOCK
ACALL			DELAY
SETB			CLOCK
SJMP			_loop_forever

RET

;-------------------------------
; Trinh phuc vu xu ly ngat 0 khi ket thuc qua trinh chuyen doi ADC
; Hien thi ket qua ra LCD	
ADC_COMPLETED:
CPL				P3.0
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
RETI
;-------------------------------

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