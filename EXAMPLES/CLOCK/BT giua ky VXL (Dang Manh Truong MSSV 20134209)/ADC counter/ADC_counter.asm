; Dang Manh Truong (MSSV 20134209)
; Chuong trinh thuc hien ADC (Analog to Digital Converter) dua tren nguyen ly dem (counter ADC)
; Tham khao: 
; [1] Microprocessor Interfacing Techniques - Austin Lesea, Rodnay Zaks
; [2] ADC0808 datasheet
; [3] 74LS590 datasheet
; [4] http://ecetutorials.com/digital-electronics/counter-type-adc-analog-to-digital-converter/
; Chu y: Trong TH dau vao la 5V, mach so sanh luon o muc tich cuc cao do 5V luon lon hon hoac bang
; gia tri dau ra cua DAC
; => Lap vo han
; => Can xu ly truong hop dac biet nay bang cach dem so lan dau ra Q0-Q7 cua 74LS590 deu dat gia tri 1
; bang cach su dung cac D flip-flop (khi bo dem chay tu 0h den FFh co 8 lan Q0-Q7 dat trang thai 0FFh) 
; Ngoai ra TH dau vao 0V cung can xu ly (nhung khong can xet den so lan xuat hien nhu tren)
CLOCK					EQU		P2.0
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
CLR				CLOCK
MOV				ADC_OUTPUT_PORT,#0FFh
MOV				IE,#10000001b ; Su dung ngat 0
SETB			TCON.0 ; Ngat theo xung cao-xuong-thap
MOV				A,#038h ; Khoi tao LCD 
ACALL			COMNWRT
_loop_forever:
SETB			CLOCK
CLR				CLOCK
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