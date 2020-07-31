; Dang Manh Truong (MSSV 20134209)
; Chuong trinh truyen thong noi tiep 8051 bang UART va phan mem
; Code ben nhan
PIN_7SEG			EQU		P2
SOFTPIN_7SEG		EQU     P0
SERIAL_DATA_PIN		EQU		P1.2

ORG					0H
LJMP				MAIN  
ORG					0023H
LJMP				ISR_HARDWARE_SERIAL

MAIN:
MOV					IE,#10010001B ; Cho phep ngat 0 va ngat truyen thong noi tiep
SETB				TCON.0 ; Ngat 0 theo xung cao-xuong-thap
MOV					TMOD,#20h ; Timer 1, che do 2 tu nap lai
MOV					TH1, #0F4h ; Baud rate  = 2400
MOV					SCON,#50h ; Khung du lieu 8 bit, 1 Stop, cho phep RI
SETB				TR1
_loop_forever:
; Thuc hien nhan du lieu noi tiep bang phan mem, sau do hien thi ra LED
MOV					R1,#8
MOV					A,#0
_while_idle:
JB					SERIAL_DATA_PIN,_while_idle
; Phat hien bit Start
NOP
_receive_bits:
JB					SERIAL_DATA_PIN,_bit_1
; _bit_0:
CLR					C
JMP					_rotate
_bit_1:
SETB				C
NOP
_rotate:
RRC					A
_continue:
DJNZ				R1,_receive_bits
RR					A
MOV					SOFTPIN_7SEG,A					
JMP					_loop_forever
RET

ISR_HARDWARE_SERIAL:
JB					TI,_trans
; Nhan du lieu tu UART
MOV					A,SBUF
MOV					PIN_7SEG,A	
CLR					RI  
RETI
_trans:
CLR					TI
RETI

END

