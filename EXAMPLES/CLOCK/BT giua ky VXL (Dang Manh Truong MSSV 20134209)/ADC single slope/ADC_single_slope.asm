; Dang Manh Truong (MSSV 20134209)
; Chuong trinh thuc hien ADC (Analog to Digital Converter) dua tren nguyen ly "single slope" 
; Tham khao: 
; [1] Microprocessor Interfacing Techniques - Austin Lesea, Rodnay Zaks
; [2] http://www.hardwaresecrets.com/how-analog-to-digital-converter-adc-works/8/
; [3] Single-Slope Analog-to-Digital (A/D) Conversion -  Stephen Ledford, CSIC Product Engineering
SOC			EQU			P3.0
EOC			EQU			P3.1
HEXA_OUTPUT EQU			P0
ORG			0h
LJMP		MAIN

MAIN:
MOV			TMOD,#00000011B
_loop:
MOV			TL0,#0	  
SETB		SOC ; Bat dau chuyen doi
CLR			SOC
SETB		TR0 ; Khoi dong Timer 0
JB			EOC,$
CLR			TR0 ; Ket thuc Timer 0
MOV			HEXA_OUTPUT,TL0

; Quy doi tu hexa ve so thap phan
MOV				A,TL0
MOV				B,#10 ; Chia cho 10
DIV				AB
MOV				R5,B  ; Cat chu so hang don vi
MOV				B,#10
DIV				AB
MOV				R4,B  ; Cat chu so hang chuc
MOV				B,#10
DIV				AB
MOV				R3,B  ; Cat chu so hang tram

; Hien thi tren LED  
MOV				A,R4 
SWAP			A
ADD				A,R5 
MOV				P2,A  ; Hien thi ca chu so hang chuc va don vi bang cong P2
MOV				A,R3 
MOV				P1,A ; Hien thi chu so hang tram   

JMP			_loop
RET	 

END