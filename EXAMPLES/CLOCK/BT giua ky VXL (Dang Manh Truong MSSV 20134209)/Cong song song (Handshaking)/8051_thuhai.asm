; Dang Manh Truong (MSSV 20134209, STT 22 = 16h)
; Chuong trinh thuc hien cong song song co doi thoai (handshaking)
; Code cho 8051 thu hai
; Thuc hien: Nhan du lieu tu 8051 thu nhat theo nguyen ly handshaking; nhan du lieu tu ADC khi co tin hieu ket thuc chuyen doi
; (End of Conversion) va gui du lieu vao SRAM
SRAM				EQU				0000h
ADC					EQU				4000h
PortData			EQU				8016h
PortStatus			EQU				0C016h
Counter				EQU				R3
PIN_7SEG			EQU				P1 ; tu P1.4 den P1.7		  
DataX				EQU				P1 ; tu P1.0 den P1.3
ACK_NOT				EQU				P3.5
ADC_READ			EQU				P3.0

ORG					0H
LJMP				MAIN
ORG					0003H
LJMP				ISR_END_OF_CONVERSION
ORG					0013H
LJMP				ISR_OUTPUT_BUFFER_FULL

MAIN:
MOV					IE,#10000101B ; Cho phep ngat ngoai 0 va 1
SETB				TCON.0 ; Ngat ngoai 0 theo suon cao-xuong-thap
SETB				TCON.2 ; Ngat ngoai 1 theo suon cao-xuong-thap
MOV					Counter,#0h
MOV					A,#00001111B
MOV					PIN_7SEG,A
MOV					A,#0
MOV					P0,#0FFh
CLR					ADC_READ
_loop_forever:
SJMP				_loop_forever
RET

ISR_END_OF_CONVERSION:
MOV					P2,#0FFh
; Doc du lieu tu ADC 
MOV					DPTR,#ADC
MOV					R0,DPL
MOV					P2,DPH
MOVX				A,@R0 

; Ghi ra SRAM
MOV					DPTR,#SRAM
MOV					R0,DPL
MOV					P2,DPH
MOVX				@R0,A
RETI 

ISR_OUTPUT_BUFFER_FULL:  
CLR					ACK_NOT	; Bat dau nhan du lieu
; Nap du lieu tu XData vao LED 	
CLR					PIN_7SEG.4
CLR					PIN_7SEG.5
CLR					PIN_7SEG.6
CLR					PIN_7SEG.7
;XData_bit0
JNB					DataX.0,_XData_bit1
SETB				PIN_7SEG.4 
_XData_bit1:
JNB					DataX.1,_XData_bit2 
SETB				PIN_7SEG.5
_XData_bit2:
JNB					DataX.2,_XData_bit3
SETB				PIN_7SEG.6
_XData_bit3:			
JNB					DataX.3,_output_to_LED  
SETB				PIN_7SEG.7 
_output_to_LED:	  			
SETB				ACK_NOT	; Ket thuc nhan du lieu 
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