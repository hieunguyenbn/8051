; Dang Manh Truong (MSSV 20134209) 
; Chuong trinh ban phim hien thi 0-Fh tren LED 7 thanh 
; ket hop thanh ghi dich 74HC595 va Encoder de tiet kiem so chan cho 8051
Q0				EQU		P2.4
Q1				EQU		P2.5
INT0_PIN		EQU		P3.2
ST_CP			EQU		P2.2
SH_CP			EQU		P2.1
DS_PIN			EQU		P2.0  

ORG  	0000h
JMP     Start
ORG		0003H
LJMP	INT0_ISR 

ORG     0100h
Start:	

		SETB	EA ; Cho phep su dung ngat
		SETB	EX0 ; Ngat ngoai INT0	  		
		
		MOV		TMOD, #20H
		MOV		TH1, #0B0H 	  
		MOV		P1, #0
		MOV		R1, #0		; COUNT
		CLR		A
		_loop_forever:
		SJMP	_loop_forever
		
;-------------------------------
; Trinh phuc vu xu ly ngat 0 khi co phim an
; Su dung ky thuat quet (scanning technique) dieu khien bang ngat
; Tham khao: Microprocessor Interfacing Techniques - Austin Lesea, Rodnay Zaks
INT0_ISR:
		CALL	DELAY 		
		JNB		INT0_PIN, _after_check_jump
		LJMP	EXIT ; ket thuc ngat
		_after_check_jump:
		; Muc dich la gui 1110 -> 1101 -> 1011 -> 0111
		; Dau tien gui 1110
		SETB 	DS_PIN ; Gui 1
		SETB 	SH_CP
		CLR 	SH_CP ; Xung cao-xuong-thap de gui 1 bit toi 74HC595

		SETB 	DS_PIN ; Gui 1
		SETB 	SH_CP
		CLR 	SH_CP

		SETB 	DS_PIN ; Gui 1
		SETB 	SH_CP
		CLR 	SH_CP

		CLR 	DS_PIN ; Gui 0
		SETB 	SH_CP
		CLR 	SH_CP

		SETB 	ST_CP
		CLR 	ST_CP ; Dua xung cao-xuong-thap toi chan ST_CP de chot dau ra cho 74HC595
		; Su dung 1 mach Encoder de tiet kiem chan cho 8051	
		; Do vay trong code can phai giai ma
		MOV		DPTR, #Decoder 
		MOV		A,#0
		MOV		R1,#0
		; _bit0_row0:
		JNB		Q0,_bit1_row0
		ADD		A,#00000001B
		_bit1_row0:
		JNB		Q1,_after_row0
		ADD		A,#00000010B
		_after_row0:
		MOVC	A,@A+DPTR				
		JB		P3.2, _after_jump0
		LJMP	ROW0
		_after_jump0: 
		SETB 	DS_PIN ; Tu 1110 -> 1101 chi can dich bit va gui 1
		SETB 	SH_CP
		CLR 	SH_CP
		SETB 	ST_CP
		CLR 	ST_CP  
		
		MOV		A,#0  		
		MOV		R1, #4
		MOV		DPTR, #Decoder	
		_bit0_row1:
		JNB		Q0,_bit1_row1
		ADD		A,#00000001B
		_bit1_row1:
		JNB		Q1,_after_row1
		ADD		A,#00000010B
		_after_row1:
		MOVC	A,@A+DPTR  		
		JB		P3.2, _after_jump1
		LJMP	ROW1
		_after_jump1:	
  		SETB 	DS_PIN ; Tu 1101 -> 1011 chi can dich bit va gui 1
		SETB 	SH_CP
		CLR 	SH_CP
		SETB 	ST_CP
		CLR 	ST_CP
		MOV		A,#0
		MOV		R1, #8
		MOV		DPTR,#Decoder 		
		 _bit0_row2:
		JNB		Q0,_bit1_row2
		ADD		A,#00000001B
		_bit1_row2:
		JNB		Q1,_after_row2
		ADD		A,#00000010B
		_after_row2:
		MOVC	A,@A+DPTR  	
		JB		P3.2, _after_jump2
		LJMP	ROW2
		_after_jump2:  
		SETB 	DS_PIN ; Tu 1011 -> 0111 chi can dich bit va gui 1
		SETB 	SH_CP
		CLR 	SH_CP
		SETB 	ST_CP
		CLR 	ST_CP	
	   		
		MOV		A,#0
		MOV		R1, #12
		MOV		DPTR, #Decoder
		 _bit0_row3:
		JNB		Q0,_bit1_row3
		ADD		A,#00000001B
		_bit1_row3:
		JNB		Q1,_after_row3
		ADD		A,#00000010B
		_after_row3:
		MOVC	A,@A+DPTR
		;JNB		P3.2, ROW3
		JB		P3.2,_after_jump3
		LJMP	ROW3
		_after_jump3:	
ROW0:  		
		RLC		A
		JNC		MATCH
		INC		R1
		SJMP	ROW0
ROW1:
		RLC		A
		JNC		MATCH
		INC		R1
		SJMP	ROW1
ROW2:
		RLC		A
		JNC		MATCH
		INC		R1
		SJMP	ROW2	
ROW3:
		RLC		A
		JNC		MATCH
		INC		R1
		SJMP	ROW3
MATCH:
		MOV		A, #0
		MOV		A, R1
		MOV		P1, A
EXIT: 
		MOV		R1, #0 ; Reset COUNT
		MOV		P2, #0F0H
		; Khoi tao lai gia tri ban dau: 0000
		CLR 	DS_PIN ; Gui 0
		SETB 	SH_CP
		CLR 	SH_CP 

		CLR 	DS_PIN ; Gui 0
		SETB 	SH_CP
		CLR 	SH_CP

		CLR 	DS_PIN ; Gui 0
		SETB 	SH_CP
		CLR 	SH_CP

		CLR 	DS_PIN ; Gui 0
		SETB 	SH_CP
		CLR 	SH_CP

		SETB 	ST_CP
		CLR 	ST_CP ; Dua xung cao-xuong-thap toi chan ST_CP de chot dau ra cho 74HC595	
		RETI
;-------------------------------
; DELAY: Tao tre cho chuong trinh
DELAY:
		SETB	TR1
		JNB		TF1, $
		CLR		TF1
		CLR		TR1
		RET

ORG		500h
Decoder:			DB		11101111B,11011111B, 10111111B, 01111111B  
      END