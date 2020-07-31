; Dang Manh Truong (MSSV 20134209)
; Chuong trinh ban phim su dung ki thuat dao day (line reversal technique)
; Tham khao: 
; [1] Microprocessor Interfacing Techniques - Austin Lesea, Rodnay Zaks
CONTROL			EQU			P3.4

ORG   			0000h
JMP   			Start
ORG				0003H
LJMP			INT0_ISR

ORG 			0100h
Start:	
		SETB	EA			; Enable Interrupt
		SETB	EX0			; Enable INT0	
		SETB	IT0			; INT0 NGAT THEO SUON XUONG  		
		
		MOV		TMOD, #20H
		MOV		TH1, #0B0H
		
		CLR		P2.0
		CLR		P2.1
		CLR		P2.2
		CLR		P2.3
		MOV		P1, #0FFh ; Ban dau den LED hien thi so 0					   
		SJMP	$ 
		
;-------------------------------
INT0_ISR:
		CPL		P3.5
		CALL	DELAY
			
; Thuc hien dao day ban phim (line reversal)
		MOV		A,P2
		CLR		CONTROL ; Dao day
		MOV		P2,A
		SETB	P2.0
		SETB	P2.1
		SETB	P2.2
		SETB	P2.3
		MOV		A,P2 ; Doc thong tin cua phim bam (hang + cot)
; Hien thi ket qua
		;MOV		P1,A
		MOV		R0,#0 ; R0: Chi so hang
		MOV		R1,#0 ; R1: Chi so cot
		CLR		C
		MOV		R2,#0 ; R2: Bien dem
		MOV		R3,A  
_tim_chi_so_hang:
		RRC		A
		JNC		_ket_thuc_tim_chi_so_hang
		INC		R2
		CLR		C
		JMP		_tim_chi_so_hang
_ket_thuc_tim_chi_so_hang:
		MOV		A,R2		
		MOV		R0,A ; R0 luu tru chi so hang
		MOV		A,R3 ; Lay lai ket qua truoc cua A
		SWAP	A ; Chi xet vi tri cot
		MOV		R2,#0
_tim_chi_so_cot:
		RRC		A
		JNC		_ket_thuc_tim_chi_so_cot
		INC		R2
		CLR		C
		JMP		_tim_chi_so_cot
_ket_thuc_tim_chi_so_cot:
		MOV		A,R2
		MOV		R1,A ; R1 luu tru chi so cot
		; Quy doi thong tin ve hang va cot thanh ket qua dau ra
		MOV		A,R0
		MOV		B,#4
		MUL		AB
		ADD		A,R1 			  

		MOV		P1,A ; Xuat ra LED			
; Thiet lap lai trang thai ban dau
		SETB	CONTROL
		MOV		A,#11110000B
		MOV		P2,A 	
EXIT:		
		RETI

DELAY:
		SETB	TR1
		JNB		TF1, $
		CLR		TF1
		CLR		TR1
		RET
END
