 ORG 00H
 LJMP MAIN
 ORG 30H
 MAIN:
 	CLR P2.0
	CLR P2.4
 	CALL THUAN
	CALL DUNG
	CALL NGUOC
	JMP MAIN

	;----------------------------------------------------------------------------------
	THUAN:
		SETB P2.0
		CLR P2.4
		MOV R5, #3
		DELAY3S:
			CALL DELAY
			DJNZ R5, DELAY3S
	RET
	;---------------------------------------------------------------------------------
	DUNG:
	   CLR P2.0
	   CLR P2.4
	   MOV R5, #5
	   DELAY5S:
	   		CALL DELAY
			DJNZ R5, DELAY5S
	   		
	RET
	;----------------------------------------------------------------------------------
	NGUOC:
	  	SETB P2.4
		CLR P2.0
		MOV R5, #4
		DELAY4:
			CALL DELAY
			DJNZ R5, DELAY3S
	RET
	;-----------------------------------------------------------------------------------
	DELAY:
	   MOV TMOD, #01
	   MOV R7, #20
	   TRE1S:
		   MOV TH0, #(-50000)
		   MOV TL0, #(-50000)
		   SETB TR0
		   JNB TF0, $
		   CLR TR0
		   CLR TF0
		   DJNZ R7, TRE1S
	RET
 END