/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName   : timer1.c
 *
 */

#include "timer1.h"
#include "timer1_cfg.h"
#include "timer1_reg.h"
#include "../../LIB/Bit_Masking.h"
#include "../../LIB/STD_DataType.h"


//FUNCTION TO SET CLK
void static set_clk(){
#if TIMER1_CLK_MODE == TIMER1_NO_CLK
	CLR_BIT( TCCR1B , CS10 );
	CLR_BIT( TCCR1B , CS11 );
	CLR_BIT( TCCR1B , CS12 );
#elif	TIMER1_CLK_MODE == TIMER1_CLK_1
	SET_BIT( TCCR1B , CS10 );
	CLR_BIT( TCCR1B , CS11 );
	CLR_BIT( TCCR1B , CS12 );
#elif	TIMER1_CLK_MODE == TIMER1_CLK_8
	CLR_BIT( TCCR1B , CS10 );
	SET_BIT( TCCR1B , CS11 );
	CLR_BIT( TCCR1B , CS12 );
#elif	TIMER1_CLK_MODE == TIMER1_CLK_64
	SET_BIT( TCCR1B , CS10 );
	SET_BIT( TCCR1B , CS11 );
	CLR_BIT( TCCR1B , CS12 );
#elif	TIMER1_CLK_MODE == TIMER1_CLK_256
	CLR_BIT( TCCR1B , CS10 );
	CLR_BIT( TCCR1B , CS11 );
	SET_BIT( TCCR1B , CS12 );
#elif	TIMER1_CLK_MODE == TIMER1_CLK_1024
	SET_BIT( TCCR1B , CS10 );
	CLR_BIT( TCCR1B , CS11 );
	SET_BIT( TCCR1B , CS12 );
#elif	TIMER1_CLK_MODE == TIMER1_EXT_CLK_FALLING
	CLR_BIT( TCCR1B , CS10 );
	SET_BIT( TCCR1B , CS11 );
	SET_BIT( TCCR1B , CS12 );
#elif	TIMER1_CLK_MODE == TIMER1_EXT_CLK_RISING
	SET_BIT( TCCR1B , CS10 );
	SET_BIT( TCCR1B , CS11 );
	SET_BIT( TCCR1B , CS12 );
#endif

}




//FUNCTION TO SET INTERRUPT OVERFLOW
static void Set_Int_Ovf(){
	//Overflow Interrupt Enable
	#if TIMER1_OVF_Interrupt_MODE == TIMER1_OVF_Interrupt_ENABLE
		SET_BIT( TIMSK , TOIE1 );
	#elif	TIMER1_OVF_Interrupt_MODE == TIMER1_OVF_Interrupt_DISABLE
		CLR_BIT( TIMSK , TOIE1 );
	#endif
}


//FUNCTION TO SET INTERRUPT Output Compare A Match Interrupt Enable
static void Set_CTC_A_Int(){
	//Overflow Interrupt Enable
	#if TIMER1_OC1A_Interrupt_MODE == OC1A_Interrupt_ENABLE
		SET_BIT( TIMSK , OCIE1A );
	#elif	TIMER1_OC1A_Interrupt_MODE == OC1A_Interrupt_DISABLE
		CLR_BIT( TIMSK , OCIE1A );
	#endif
}


//FUNCTION TO SET INTERRUPT Output Compare B Match Interrupt Enable
static void Set_CTC_B_Int(){
	//Overflow Interrupt Enable
	#if TIMER1_OC1B_Interrupt_MODE == OC1B_Interrupt_ENABLE
		SET_BIT( TIMSK , OCIE1B );
	#elif	TIMER1_OC1B_Interrupt_MODE == OC1B_Interrupt_DISABLE
		CLR_BIT( TIMSK , OCIE1B );
	#endif
}


//FUNCTION TO SET OC1A  (NON PWM)
static void Set_OC1A_Non_Pwm(){
#if		TIMER1_OC1A_CTC_MODE	==	OC1A_DISCONNECTED
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
#elif	TIMER1_OC1A_CTC_MODE	==	OC1A_TOGGLE
	SET_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
#elif	TIMER1_OC1A_CTC_MODE	==	OC1A_CLEAR
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#elif	TIMER1_OC1A_CTC_MODE	==	OC1A_SET
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#endif
}


//FUNCTION TO SET OC1B	(NON PWM)
static void Set_OC1B_Non_Pwm(){
#if		TIMER1_OC1B_CTC_MODE	==	OC1B_DISCONNECTED
	CLR_BIT(TCCR1B,COM1B0);
	CLR_BIT(TCCR1B,COM1B1);
#elif	TIMER1_OC1B_CTC_MODE	==	OC1B_TOGGLE
	SET_BIT(TCCR1B,COM1B0);
	CLR_BIT(TCCR1B,COM1B1);
#elif	TIMER1_OC1B_CTC_MODE	==	OC1B_CLEAR
	CLR_BIT(TCCR1B,COM1B0);
	SET_BIT(TCCR1B,COM1B1);
#elif	TIMER1_OC1B_CTC_MODE	==	OC1B_SET
	SET_BIT(TCCR1B,COM1B0);
	SET_BIT(TCCR1B,COM1B1);
#endif
}


//FUNCTION TO SET OC1A  (PHASE CORRECT)
static void Set_OC1A_PhaseCorrect(){
#if		TIMER1_OC1A_PHASE_PWM_MODE	==	OC1A_DISCONNECTED
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
#elif	TIMER1_OC1A_PHASE_PWM_MODE	==	OC1A_TOGGLE
	SET_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
#elif	TIMER1_OC1A_PHASE_PWM_MODE	==	CLR_UP_SET_DWN
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#elif	TIMER1_OC1A_PHASE_PWM_MODE	==	SET_UP_CLR_DWN
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#endif
}
//FUNCTION TO SET OC1B	(PHASE CORRECT)
static void Set_OC1B_PhaseCorrect(){
#if		TIMER1_OC1B_PHASE_PWM_MODE	==	OC1B_DISCONNECTED
	CLR_BIT(TCCR1B,COM1B0);
	CLR_BIT(TCCR1B,COM1B1);
#elif	TIMER1_OC1B_PHASE_PWM_MODE	==	CLR_UP_SET_DWN
	CLR_BIT(TCCR1B,COM1B0);
	SET_BIT(TCCR1B,COM1B1);
#elif	TIMER1_OC1B_PHASE_PWM_MODE	==	SET_UP_CLR_DWN
	SET_BIT(TCCR1B,COM1B0);
	SET_BIT(TCCR1B,COM1B1);
#endif
}


//FUNCTION TO SET OC1A 	(FAST PWM)
static void Set_OC1A_FastPwmt(){
#if		TIMER1_OC1A_FAST_PWM_MODE	==	OC1A_DISCONNECTED
	CLR_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
#elif	TIMER1_OC1A_FAST_PWM_MODE	==	OC1A_TOGGLE
	SET_BIT(TCCR1A,COM1A0);
	CLR_BIT(TCCR1A,COM1A1);
#elif	TIMER1_OC1A_FAST_PWM_MODE	==	CLR_CMP_SET_TOP
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#elif	TIMER1_OC1A_FAST_PWM_MODE	==	SET_TOP_CLR_CMP
	SET_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);
#endif
}
//FUNCTION TO SET OC1B	(FAST PWM)
static void Set_OC1AB_FastPwmt(){
#if		TIMER1_OC1B_FAST_PWM_MODE	==	OC1B_DISCONNECTED
	CLR_BIT(TCCR1A,COM1B0);
	CLR_BIT(TCCR1A,COM1B1);
#elif	TIMER1_OC1B_FAST_PWM_MODE	==	CLR_CMP_SET_TOP
	CLR_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
#elif	TIMER1_OC1B_FAST_PWM_MODE	==	SET_TOP_CLR_CMP
	SET_BIT(TCCR1A,COM1B0);
	SET_BIT(TCCR1A,COM1B1);
#endif
}



void TIMER1_Init(){


#if  TIMER1_WAVE_GENERATION_MODE == TIMER1_NORMAL

		//set mode
		CLR_BIT( TCCR1A , WGM10 );
		CLR_BIT( TCCR1A , WGM11 );
		CLR_BIT( TCCR1B , WGM12 );
		CLR_BIT( TCCR1B , WGM13 );

		//Overflow Interrupt Enable
		Set_Int_Ovf();


#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_PWM_PHASE_8_BIT

		//set mode
		SET_BIT( TCCR1A , WGM10 );
		CLR_BIT( TCCR1A , WGM11 );
		CLR_BIT( TCCR1B , WGM12 );
		CLR_BIT( TCCR1B , WGM13 );

		//Overflow Interrupt Enable
		Set_Int_Ovf();

		//CTC A Interrupt Enable
		Set_CTC_A_Int();

		//CTC B Interrupt Enable
		Set_CTC_B_Int();

		//OCA1
		Set_OC1A_PhaseCorrect();

		//OCB1
		Set_OC1B_PhaseCorrect();




#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_PWM_PHASE_9_BIT

	//set mode
	CLR_BIT( TCCR1A , WGM10 );
	SET_BIT( TCCR1A , WGM11 );
	CLR_BIT( TCCR1B , WGM12 );
	CLR_BIT( TCCR1B , WGM13 );

	//Overflow Interrupt Enable
	Set_Int_Ovf();

	//CTC A Interrupt Enable
	Set_CTC_A_Int();

	//CTC B Interrupt Enable
	Set_CTC_B_Int();

	//OCA1
	Set_OC1A_PhaseCorrect();

	//OCB1
	Set_OC1B_PhaseCorrect();



#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_PWM_PHASE_10_BIT

	//set mode
	SET_BIT( TCCR1A , WGM10 );
	SET_BIT( TCCR1A , WGM11 );
	CLR_BIT( TCCR1B , WGM12 );
	CLR_BIT( TCCR1B , WGM13 );

	//Overflow Interrupt Enable
	Set_Int_Ovf();

	//CTC A Interrupt Enable
	Set_CTC_A_Int();

	//CTC B Interrupt Enable
	Set_CTC_B_Int();

	//OCA1
	Set_OC1A_PhaseCorrect();

	//OCB1
	Set_OC1B_PhaseCorrect();



#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_CTC

	//set mode
	CLR_BIT( TCCR1A , WGM10 );
	CLR_BIT( TCCR1A , WGM11 );
	SET_BIT( TCCR1B , WGM12 );
	CLR_BIT( TCCR1B , WGM13 );


	//CTC A Interrupt Enable
	Set_CTC_A_Int();

	//CTC B Interrupt Enable
	Set_CTC_B_Int();

	//OCA1
	Set_OC1A_Non_Pwm();

	//OCB1
	Set_OC1B_Non_Pwm();




#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_FAST_PWM_8_BIT

		//set mode
		SET_BIT( TCCR1A , WGM10 );
		CLR_BIT( TCCR1A , WGM11 );
		SET_BIT( TCCR1B , WGM12 );
		CLR_BIT( TCCR1B , WGM13 );


		//Overflow Interrupt Enable
		Set_Int_Ovf();

		//CTC A Interrupt Enable
		Set_CTC_A_Int();

		//CTC B Interrupt Enable
		Set_CTC_B_Int();

		//OCA1
		Set_OC1A_FastPwmt();

		//OCB1
		Set_OC1AB_FastPwmt();

#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_FAST_PWM_9_BIT
			//set mode
			CLR_BIT( TCCR1A , WGM10 );
			SET_BIT( TCCR1A , WGM11 );
			SER_BIT( TCCR1B , WGM12 );
			CLR_BIT( TCCR1B , WGM13 );

			//Overflow Interrupt Enable
			Set_Int_Ovf();

			//CTC A Interrupt Enable
			Set_CTC_A_Int();

			//CTC B Interrupt Enable
			Set_CTC_B_Int();

			//OCA1
			Set_OC1A_FastPwmt();

			//OCB1
			Set_OC1AB_FastPwmt();

#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_FAST_PWM_10_BIT
			//set mode
			SET_BIT( TCCR1A , WGM10 );
			SET_BIT( TCCR1A , WGM11 );
			SET_BIT( TCCR1B , WGM12 );
			CLR_BIT( TCCR1B , WGM13 );


			//Overflow Interrupt Enable
			Set_Int_Ovf();

			//CTC A Interrupt Enable
			Set_CTC_A_Int();

			//CTC B Interrupt Enable
			Set_CTC_B_Int();

			//OCA1
			Set_OC1A_FastPwmt();

			//OCB1
			Set_OC1AB_FastPwmt();


#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_PWM_PHASE_FREQ_ICR1
	//set mode
	CLR_BIT( TCCR1A , WGM10 );
	CLR_BIT( TCCR1A , WGM11 );
	CLR_BIT( TCCR1B , WGM12 );
	SET_BIT( TCCR1B , WGM13 );

	//Overflow Interrupt Enable
	Set_Int_Ovf();

	//CTC A Interrupt Enable
	Set_CTC_A_Int();

	//CTC B Interrupt Enable
	Set_CTC_B_Int();

	//OCA1
	Set_OC1A_PhaseCorrect();

	//OCB1
	Set_OC1B_PhaseCorrect();


#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_PWM_PHASE_FREQ_OCR1
	//set mode
	SET_BIT( TCCR1A , WGM10 );
	CLR_BIT( TCCR1A , WGM11 );
	CLR_BIT( TCCR1B , WGM12 );
	SET_BIT( TCCR1B , WGM13 );

	//Overflow Interrupt Enable
	Set_Int_Ovf();

	//CTC A Interrupt Enable
	Set_CTC_A_Int();

	//CTC B Interrupt Enable
	Set_CTC_B_Int();

	//OCA1
	Set_OC1A_PhaseCorrect();

	//OCB1
	Set_OC1B_PhaseCorrect();


#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_PWM_PHASE_ICR1
	//set mode
	CLR_BIT( TCCR1A , WGM10 );
	SET_BIT( TCCR1A , WGM11 );
	CLR_BIT( TCCR1B , WGM12 );
	SET_BIT( TCCR1B , WGM13 );

	//Overflow Interrupt Enable
	Set_Int_Ovf();

	//CTC A Interrupt Enable
	Set_CTC_A_Int();

	//CTC B Interrupt Enable
	Set_CTC_B_Int();

	//OCA1
	Set_OC1A_PhaseCorrect();

	//OCB1
	Set_OC1B_PhaseCorrect();


#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_PWM_PHASE_OCR1
	//set mode
	SET_BIT( TCCR1A , WGM10 );
	SET_BIT( TCCR1A , WGM11 );
	CLR_BIT( TCCR1B , WGM12 );
	SET_BIT( TCCR1B , WGM13 );
	//Overflow Interrupt Enable
	Set_Int_Ovf();

	//CTC A Interrupt Enable
	Set_CTC_A_Int();

	//CTC B Interrupt Enable
	Set_CTC_B_Int();

	//OCA1
	Set_OC1A_PhaseCorrect();

	//OCB1
	Set_OC1B_PhaseCorrect();


#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_CTC_ICR1
		//set mode
		CLR_BIT( TCCR1A , WGM10 );
		CLR_BIT( TCCR1A , WGM11 );
		SET_BIT( TCCR1B , WGM12 );
		SET_BIT( TCCR1B , WGM13 );

		//CTC A Interrupt Enable
		Set_CTC_A_Int();

		//CTC B Interrupt Enable
		Set_CTC_B_Int();

		//OCA1
		Set_OC1A_Non_Pwm();

		//OCB1
		Set_OC1B_Non_Pwm();



#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_FAST_PWM_ICR1
	//set mode
	CLR_BIT( TCCR1A , WGM10 );
	SET_BIT( TCCR1A , WGM11 );
	SET_BIT( TCCR1B , WGM12 );
	SET_BIT( TCCR1B , WGM13 );

	//Overflow Interrupt Enable
	Set_Int_Ovf();

	//CTC A Interrupt Enable
	Set_CTC_A_Int();

	//CTC B Interrupt Enable
	Set_CTC_B_Int();

	//OCA1
	Set_OC1A_FastPwmt();

	//OCB1
	Set_OC1AB_FastPwmt();

#elif TIMER1_WAVE_GENERATION_MODE == TIMER1_FAST_PWM_OCR1
	//set mode
	CLR_BIT( TCCR1A , WGM10 );
	CLR_BIT( TCCR1A , WGM11 );
	CLR_BIT( TCCR1B , WGM12 );
	CLR_BIT( TCCR1B , WGM13 );

	//Overflow Interrupt Enable
	Set_Int_Ovf();

	//CTC A Interrupt Enable
	Set_CTC_A_Int();

	//CTC B Interrupt Enable
	Set_CTC_B_Int();

	//OCA1
	Set_OC1A_FastPwmt();

	//OCB1
	Set_OC1AB_FastPwmt();

#endif

	//SET CLK
	set_clk();

}

void TIMER1_SetPreload( u16 preload_value ){
	TCNT1 = preload_value;
}

void TIMER1_SetChannel_A_OCR1( u16 OCRA_Value){
	OCR1A = OCRA_Value;
}

void TIMER1_SetChannel_B_OCR1( u16 OCRB_Value){
	OCR1B = OCRB_Value;
}

u16 TIMER1_GetTCNT1(){
	return TCNT1 ;
}


//ICU
void TIMER1_ICR1_Init(){
	// Input Capture Noise Canceler
	SET_BIT(TCCR1B , ICNC1 );

#if ICU_EDGE == ICU_falling
	CLR_BIT(TCCR1B , ICES1 );
#elif ICU_EDGE == ICU_RISING
	SET_BIT(TCCR1B , ICES1 );
#endif

	//ICU INTERRUPT ENABLE
	SET_BIT(TIMSK,TICIE1);
}

u16 TIMER1_GetICR1(){
	return ICR1;
}

void TIMER_ICU_ToggleEdge(u8 Copy_Edge_Value){
	if(Copy_Edge_Value == ICU_falling){
		CLR_BIT(TCCR1B , ICES1 );
	}
	else if(Copy_Edge_Value == ICU_RISING){
		SET_BIT(TCCR1B , ICES1 );
	}
}



//WDT
void TIMER_WDT_Init(){
	SET_BIT(WDTCR,WDE);
}
void TIMER_WDT_READY(){
	//TO CLEAR FIRST THREE BIT
	WDTCR &=011000;
	//TO WRITE ON FIRST THREE BIT
	WDTCR |=WDT_PRESCALE;
}
void TIMER_WDT_DISABLE(){
	//SET TWO BIT IN SAME CLK
	WDTCR |= 0b11000;
	//CLEAR BIT WDE
	WDTCR  =  0;
}
