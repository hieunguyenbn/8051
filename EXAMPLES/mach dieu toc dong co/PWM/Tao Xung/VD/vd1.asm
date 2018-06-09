org 00h
main:
      MOV TMOD, #01H ;Timer 0,mode 1(16-bit timer mode)
      LOOP: MOV TH0, #HIGH(-250); high byte of -50,000
      MOV TL0, #LOW(-250) ; low byte of -50,000
      SETB TR0 ; start timer
      JNB TF0, $; wait for overflow
      CLR TR0 ; stop timer
      CLR TF0 ; clear timer overflow flag
      CPL P1.0 ; toggle port bit
	  MOV TH0, #HIGH(-125); high byte of -50,000
      MOV TL0, #LOW(-125) ; low byte of -50,000
      SETB TR0 ; start timer
      JNB TF0, $; wait for overflow
      CLR TR0 ; stop timer
      CLR TF0 ; clear timer overflow flag
	  CPL P1.1
      SJMP LOOP ; repeat   
end