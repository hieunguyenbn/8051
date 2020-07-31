; Dang Manh Truong (MSSV 20134209)
; Chuong trinh dieu khien dong co bang nguyen ly dieu che do rong xung (Pulse Width Modulation)
PWM_PIN		EQU			P2.0
FULL_CYCLE	EQU			255
T_ON		EQU			50	; Thoi gian xung cao ban dau
SPEED_INC   EQU			30
ORG			000h
LJMP		MAIN
ORG			0003h
LJMP		ISR_SPEEDUP
ORG			000Bh
LJMP		ISR_FULLTIME
ORG			0013h
LJMP		ISR_SPEEDDOWN
ORG			001Bh
LJMP		ISR_ONTIME
MAIN:
; Timer 0 and 1 (timer 0 dem ca chu ky con timer 1 dem thoi gian xung cao)
; Enable INT0 and INT1
MOV			IE,#10001111b 
SETB		IT0	; Ngat cao-xuong-thap
SETB		IT1
MOV			TMOD,#22H ; Ca 2 Timer deu o che do 2
MOV			TH0,#-FULL_CYCLE
MOV			TH1,#-T_ON
SETB		TR0 ; Dummy start Timer 0 until TF0 = 1 which will call in the interrupt services
_do_nothing:
SJMP		_do_nothing
RET

ISR_SPEEDUP:
MOV			A,TH1
SUBB		A,#SPEED_INC  

MOV			TH1,A
RETI

ISR_SPEEDDOWN:
MOV			A,TH1
ADD			A,#SPEED_INC
MOV			TH1,A
RETI

ISR_FULLTIME: 
SETB		PWM_PIN
SETB		TR1	 
RETI

ISR_ONTIME:	
CLR			PWM_PIN
CLR			TR1
RETI

END