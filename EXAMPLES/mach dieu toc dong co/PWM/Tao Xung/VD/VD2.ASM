ORG 00H
LJMP MAIN
ORG 30H
MAIN:
   MOV TMOD,#01H
   LAP:
      ; TAO XUNG 4K T=1/F=1/4=0,25ms=250us
      ; KHOANG THOI GIAN XUNG CAO(THAP) = T/2 =125us
      ;......=> 65536-125=35411=FF83H
      MOV TL0,#high(-125)
      MOV TH0,#low(-125)
      CALL DELAY
      CPL P1.1
            CALL DELAY
      ;TAO XUNG 2K
      ; TAO XUNG 4K T=1/F=1/2=0,5ms=500us
      ; KHOANG THOI GIAN XUNG CAO(THAP) = T/2 =250us
      ;......=> 65536-250=65280=FF06H
      MOV TL0,#high(-250)
      MOV TH0,#low(-250)
      CALL DELAY
      CLR P1.0
      SJMP LAP
   DELAY:
      SETB TR0
      HERE: JNB TF0,HERE
	    CLR TF0
		CLR TR0
		RET
END