/*
 * Author	 : YOUSSEF MARAWAN
 * FileName   : timer.c
 *
 */
#include "timer.h"
#include "timer_reg.h"
#include "timer.cfg.h"
#include "../../LIB/Bit_Masking.h"


//global static pointer to function to set callback
static void (*TIMER0_CallBack)(void) = NULL;
//global static variable for max counter
static u16	TIMER0_MaxCounter		 = NULL;
//global static variable for counter
static u16  TIMER0_Counter 			 = NULL;

static void PWM_OC0(){
	/*******Compare Output Mode PWM Mode********/
#if TIMER0_PWM_MODE == OC0_DISCONNECTED
	CLR_BIT(TCCR0, COM01);
	CLR_BIT(TCCR0, COM00);
#elif TIMER0_PWM_MODE == CLR_CMP_SET_TOP
	SET_BIT(TCCR0, COM01);
	CLEAR_BIT(TCCR0, COM00);
#elif TIMER0_PWM_MODE == SET_TOP_CLR_CMP
	SET_BIT(TCCR0, COM01);
	SET_BIT(TCCR0, COM00);
#endif

}

static void CTC_OC0(){
	/*******Compare Output Mode non-PWM Mode********/
#if TIMER0_CTC_MODE == OC0_DISCONNECTED
	CLR_BIT(TCCR0, COM01);
	CLR_BIT(TCCR0, COM00);
#elif TIMER0_CTC_MODE==OC0_TOGGLE
	CLR_BIT(TCCR0, COM01);
	SET_BIT(TCCR0, COM00);
#elif TIMER0_CTC_MODE == OC0_CLEAR
	SET_BIT(TCCR0, COM01);
	CLEAR_BIT(TCCR0, COM00);
#elif TIMER0_CTC_MODE == OC0_SET
	SET_BIT(TCCR0, COM01);
	SET_BIT(TCCR0, COM00);
#endif

}

void TIMER0_init(){
	TIMER0_set_prescaler();
	/*******TIMER0 MODE********/
#if TIMER0_MODE == NORMAL
	CLR_BIT(TCCR0, WGM01);
	CLR_BIT(TCCR0, WGM00);
	/* Interrupt Enable*/
	SET_BIT(TIMSK,TOIE0);

#elif TIMER0_MODE == PWM
	CLEAR_BIT(TCCR0, WGM01);
	SET_BIT(TCCR0, WGM00);
	/*******Compare Output Mode PWM Mode********/
	PWM_OC0();
#elif TIMER0_MODE == CTC
	SET_BIT(TCCR0, WGM01);
	CLEAR_BIT(TCCR0, WGM00);
	/* Interrupt Enable*/
	SET_BIT(TIMSK, OCIE0);
	/*******Compare Output Mode non-PWM Mode********/
	CTC_OC0();
#elif TIMER0_MODE == FAST_PWM
	SET_BIT(TCCR0, WGM01);
	SET_BIT(TCCR0, WGM00);
	/*******Compare Output Mode PWM Mode********/
	PWM_OC0();
#endif
}



 void TIMER0_set_prescaler(){
#if TIMER0_PRESCALER == NO_CLK
	CLEAR_BIT(TCCR0,CS02);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS00);

#elif TIMER0_PRESCALER == PRE_1
	CLEAR_BIT(TCCR0,CS02);
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);

#elif TIMER0_PRESCALER == PRE_8
	CLR_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS00);

#elif TIMER0_PRESCALER == PRE_64
	CLEAR_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);

#elif TIMER0_PRESCALER == PRE_256
	SET_BIT(TCCR0,CS02);
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS00);

#elif TIMER0_PRESCALER == PRE_1024
	SET_BIT(TCCR0,CS02);
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);

#elif TIMER0_PRESCALER == EXT_CLK_FALL
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS00);

#elif TIMER0_PRESCALER == EXT_CLK_RISE
	SET_BIT(TCCR0,CS02);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS00);

#endif
}


void TIMER0_set_preload(u8 value){
	TCNT0 = value;
}

void TIMER0_set_OCR0(u8 value){
	OCR0 = value;
}

u8   TIMER0_get_count(){
	return TCNT0;
}


void TIMER0_SetCallBack(void (*CallBack)(void),u16 max_counter){
	if(CallBack != NULL){
		TIMER0_CallBack 	= CallBack;
		TIMER0_MaxCounter	= max_counter;
		TIMER0_Counter		= 0;
	}
}

//ISR FUNCTION FOR TIMER 0 FOR OVERFLOW MODE
void __vector_11 (void) __attribute__((signal));
void __vector_11 (void){
	TIMER0_Counter++;
	if(TIMER0_Counter == TIMER0_MaxCounter){

		TIMER0_CallBack();

		TIMER0_Counter=0;
	}
}

