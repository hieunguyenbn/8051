; Dang Manh Truong (MSSV 20134209)
; Chuong trinh truyen thong noi tiep 8051 bang UART va phan mem
; Code ben gui
PIN_7SEG			EQU		P2
SOFTPIN_7SEG		EQU     P0 
COUNTER				EQU		R0
SERIAL_DATA_PIN		EQU		P1.2

ORG					0H
LJMP				MAIN  
ORG					0003H
LJMP				ISR_BUTTON_PRESSED  
ORG					0023H
LJMP				ISR_HARDWARE_SERIAL

MAIN:  
MOV					COUNTER,#0h ; Khoi tao bien dem Counter
MOV					IE,#10000001B
SETB				TCON.0 ; Ngat 0 theo xung cao-xuong-thap
MOV					TMOD,#20h ; Timer 1, che do 2 tu nap lai
MOV					TH1, #0F4h ; Baud rate  = 2400	
MOV					SCON,#50H ; Khung du lieu 8 bit, 1 Stop, cho phep RI
SETB				TR1
_loop_forever:
SJMP				_loop_forever
RET

ISR_BUTTON_PRESSED:
MOV					DPTR,#LED_7SEG
; Gui du lieu qua cong noi tiep UART
MOV					A,COUNTER
MOVC				A,@A+DPTR
MOV					PIN_7SEG,A ; Dua ra LED
;SETB				TR1
MOV					SBUF,A ; Dua ra cong UART
JNB					TI,$
CLR					TI
; Gui du lieu noi tiep bang phan mem
MOV					A,COUNTER
MOVC				A,@A+DPTR
MOV					SOFTPIN_7SEG,A ; Dua ra LED
MOV					R1,#8 
CLR					SERIAL_DATA_PIN ; Bit Start
NOP
_send_bits:
RRC					A
JC					_bit_1
; _bit_0:
CLR					SERIAL_DATA_PIN
NOP
JMP					_continue
_bit_1:
SETB				SERIAL_DATA_PIN
NOP
NOP
_continue:
DJNZ				R1,_send_bits
SETB				SERIAL_DATA_PIN ; Stop 

; Tang bien dem Counter
INC					COUNTER ; Tang bien dem
CJNE				COUNTER,#10,_end_of_interrupt
MOV					COUNTER,#0h ; Reset 
_end_of_interrupt:
RETI

ISR_HARDWARE_SERIAL:
JB					TI,_trans
NOP ; Khong lam gi ca vi day khong phai ben nhan
RETI
_trans:
CLR					TI
RETI

ORG					500h
LED_7SEG:			DB		0C0H,0F9H,0A4H,0B0H,99H,92H,82H,0F8H,80H,90H

END