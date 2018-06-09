; dung mach cau H dieu khien dong co
ORG 00H
LJMP MAIN
ORG 30H
MAIN:
	 	CLR P3.6
		CLR P3.7
	CALL THUAN
	CALL DUNG
	CALL NGUOC
	JMP MAIN
;---------------------------------------------------------------------------------------------------------------------------------------------
    THUAN:
		SETB P3.6
		CLR P3.7
		MOV R5, #3
	    DELAY3S:
	   		CALL DELAY1S
			DJNZ R5, DELAY3S
	RET
;----------------------------------------------------------------------------------------------------------------------------------------------
	DUNG:
	   SETB P3.6
	   SETB P3.7
	   MOV R5, #2
	   DELAY5S:
	   		CALL DELAY1S
			DJNZ R5, DELAY5S	   		
	RET
;-----------------------------------------------------------------------------------------------------------------------------------------------
	NGUOC:
		SETB P3.7
		CLR P3.6
		MOV R5, #4
		DELAY4S:
			CALL DELAY1S
			DJNZ R5, DELAY4S
	RET
;---------------------------------------------------------------------------------------------------------------------------------------------
	DELAY1S:
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