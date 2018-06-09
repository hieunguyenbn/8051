; Dang Manh Truong (MSSV 20134209)
; Chuong trinh thuc hien ADC (Analog to Digital Converter) dua tren nguyen ly xap xi lien tiep
; (successive approximation)
; Bo phan SAR (Successive Approximation Register) duoc thuc hien bang phan mem
; Tham khao: 
; [1] Microprocessor Interfacing Techniques - Austin Lesea, Rodnay Zaks
; [2] ADC0808 datasheet

EOC						EQU		P3.4 ; End of conversion (ket thuc chuyen doi)
COMP					EQU		P3.5 ; Dau ra cua mach so sanh
ADC_OUTPUT_PORT			EQU		P1
FEEDBACK_PORT			EQU		P2
; Cac che do cua LCD
LCD_CMD_WR				EQU 	0
LCD_DATA_WR				EQU		1
LCD_BUSY_RD				EQU		2
LCD_DATA_RD				EQU		3 

ORG				0h
LJMP			MAIN

MAIN:
MOV				ADC_OUTPUT_PORT,#0FFh	  
MOV				A,#038h ; Khoi tao LCD 
ACALL			COMNWRT
_loop:
; Bat dau chuyen doi 
SETB			EOC
MOV				FEEDBACK_PORT,#0h
MOV				R0,#8 ; So lan lap
MOV				R1,#0h ; Ket qua
MOV				DPTR,#SAR_LIST
_next_bit:	
MOV				A,R0
MOVC			A,@A+DPTR
MOV				R2,A ; Temp
ADD				A,R1
MOV				FEEDBACK_PORT,A 
; Tao tre de doi mach so sanh
MOV				R7,#25
_short_delay:
DJNZ			R7,_short_delay
; Kiem tra ket qua cua mach so sanh
JB				COMP,_continue 
XRL				A,R2 ; Hieu chinh 
MOV				FEEDBACK_PORT,A
_continue:
MOV				R1,A
DJNZ			R0,_next_bit

; Ket thuc chuyen doi
CLR				EOC
; Thuc hien hien thi
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
		
JMP				_loop 
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
SAR_LIST: DB 00000000B,00000001B,00000010B,00000100B,00001000B,00010000B,00100000B,01000000B,10000000B
END