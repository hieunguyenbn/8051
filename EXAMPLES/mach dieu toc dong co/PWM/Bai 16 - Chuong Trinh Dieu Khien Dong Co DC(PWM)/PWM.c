
#include "MAIN.H"


// CCP1 module is used here to generate the required PWM
// Timer2 module is used to generate the PWM
// This PWM has 10bit resolution
/***********************************************************/
void _SetDutyPWM1(unsigned int DutyCycle) // Give a value in between 0 and 1024 for DutyCycle
{
	PR2   = 99;           // Configure the Timer2 period
	//356=0101100100
	//sau khi dich 2 bit => 0001011001
	//sau khi dich trai 4 bit => 10010000
	CCPR1L   = DutyCycle>>2;        	// Put MSB 8 bits in CCPR1L
	CCP1CON &= 0xCF;                	// Make bit4 and 5 zero-11001111
	CCP1CON |= (0x30&(DutyCycle<<4));   // Assign Last 2 LSBs to CCP1CON -00110000
	//PWM Duty Cycle = (CCPR1L:CCP1CON<5:4>)*Tosc*(TMR2 Prescale Value)

}
/***********************************************************/
void _SetUpPWM1(void)
{
	TRISC2  = 0;            // Make CCP1 pin as output
	CCP1CON = 0x0C;         // Configure CCP1 module in PWM mode-00001100

	T2CON = 0x00;           // Set Prescaler to be 1, hence PWM frequency is set to 10khz

	_SetDutyPWM1(0);     // Intialize the PWM to 0 duty cycle

	T2CON |= 0x04;          // Enable the Timer2, hence enable the PWM.-00000100
/*
	ap dung cong thuc chu ky PWM ta co: 
	T(pwm)=[PR2+1]*4*(Tosc)*(TMR2 Prescale Value)
		  =[PR2+1]*4*(1/Fosc)*(TMR2 Prescale Value)
	hay T(pwm)=[99+1]*4*(1/4)*1
				=100*10^(-6)=10^(-4)=10khz
	vay tan so de dieu khien dong co la 10(khz)

*/
}
/***********************************************************/
void _SetDutyPWM2(unsigned int DutyCycle) // Give a value in between 0 and 1024 for DutyCycle
{
	PR2   = 99;           // Configure the Timer2 period
	CCPR2L   = DutyCycle>>2;        	// Put MSB 8 bits in CCPR1L
	CCP2CON &= 0xCF;                	// Make bit4 and 5 zero
	CCP2CON |= (0x30&(DutyCycle<<4));   // Assign Last 2 LSBs to CCP1CON
/*
	ap dung cong thuc chu ky PWM ta co: 
	T(pwm)=[PR2+1]*4*(Tosc)*(TMR2 Prescale Value)
		  =[PR2+1]*4*(1/Fosc)*(TMR2 Prescale Value)
	hay T(pwm)=[99+1]*4*(1/4)*1
				=100*10^(-6)=10^(-4)=10khz
	vay tan so de dieu khien dong co la 10(khz)
*/
}
/***********************************************************/
void _SetUpPWM2(void)
{
	TRISC1  = 0;            // Make CCP1 pin as output
	CCP2CON = 0x0C;         // Configure CCP1 module in PWM mode

	T2CON = 0x00;           // Set Prescaler to be 4, hence PWM frequency is set to 4.88KHz.

	_SetDutyPWM2(0);     // Intialize the PWM to 0 duty cycle

	T2CON |= 0x04;          // Enable the Timer2, hence enable the PWM.
	//PWM Duty Cycle = (CCPR1L:CCP1CON<5:4>)*Tosc*(TMR2 Prescale Value)
} 