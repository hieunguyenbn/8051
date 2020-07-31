; Dang Manh Truong (MSSV 20134209, STT 22 = 16h)
; Chuong trinh thuc hien cong song song co doi thoai (handshaking)
; Code cho 8051 thu nhat
; Thuc hien: Gui du lieu cho 8051 thu hai khi bam phim
SRAM				EQU				0000h
ADC					EQU				4000h
PortData			EQU				8016h
PortStatus			EQU				0C016h
Counter				EQU				R3
PIN_7SEG			EQU				P1 ; tu P1.4 den P1.7
ACK_NOT				EQU				P3.5

ORG					0H
LJMP				MAIN
ORG					0003H
LJMP				ISR_BUTTON_PRESSED

MAIN:
MOV					IE,#10000101B ; Cho phep ngat ngoai 0 va 1
SETB				TCON.0 ; Ngat ngoai 0 theo suon cao-xuong-thap
;SETB				TCON.2 ; Ngat ngoai 1 theo suon cao-xuong-thap
MOV					Counter,#0h
MOV					A,#00001111B
MOV					PIN_7SEG,A
MOV					A,#0
MOV					P0,#0FFh
_loop_forever:
SJMP				_loop_forever
RET

ISR_BUTTON_PRESSED:	
MOV					A,Counter
MOV					R4,A ; Luu tru gia tri cua Accumulator
; Xuat ra den LED
CLR					PIN_7SEG.4
CLR					PIN_7SEG.5
CLR					PIN_7SEG.6
CLR					PIN_7SEG.7
;_bit0
CLR					C
RRC					A
JNC					_bit1
SETB				PIN_7SEG.4
_bit1:
CLR					C
RRC					A
JNC					_bit2
SETB				PIN_7SEG.5
_bit2:
CLR					C
RRC					A
JNC					_bit3
SETB				PIN_7SEG.6
_bit3:
CLR					C
RRC					A
JNC					_perform_handshaking
SETB				PIN_7SEG.7
_perform_handshaking:
; Xuat ra cong song song
MOV					A,R4 ; Khoi phuc gia tri cua Accumulator
MOV					DPTR,#PortData
MOV					R0,DPL
MOV					P2,DPH
MOVX				@R0,A
MOV					P0,#0FFh
INC					Counter
CJNE				Counter,#10,_ket_thuc
MOV					Counter,#0 ; Reset Counter
_ket_thuc:
RETI

; Tao thoi gian tre cho chuong trinh
DELAY:
MOV 				R6,#255
_NOP:
MOV 				R7,#255
DJNZ 				R7,$
DJNZ 				R6,_NOP
RET

END