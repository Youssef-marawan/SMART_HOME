/*
 * Author	 : YOUSSEF MARAWAN
 * FileName   : ADC.c
 *
 */

#include "ADC_reg.h"
#include <avr/interrupt.h>
#include "ADC.h"
#include "ADC_cfg.h"
#include	"../../LIB/Bit_Masking.h"
#include "../../LIB/STD_DataType.h"


#define ADC_CH_MASK		244

//GLOBAL POINTER TO CARRY THE RESULT
static pu16 ADC_AsynchConverResult = NULL ;
//GLOBAL POINTER TO FUNCTION TO USE CALL BACK
static void (* ADC_CallBack_Asynch)(void)= NULL;
//TO SELECT SINGLE MODE OR CHAIN MODE
static u8 ADC_AsynchMode ;
//VAR. TO INDEX OF CHANNEL IN CHAIN
static u8 ADC_ChainIndex ;
//VAR. TO NUMBER OF CHANNELS IN CHAIN
static u8 ADC_ChainSize  ;
//GLOBAL POINTER TO FUNCTION TO USE CALL BACK FUNCTION IN CHAIN
static void (* ADC_CB_FuncChain)(void)= NULL ;
//GLOBAL POINTER TO CARRY THE RESULT
static pu16 ADC_Result;
//Global flag for the ADC Busy State
static u8 ADC_State= SLEEP ;


//FUNCTION TO Initialization ADC
void ADC_Init(){
	//SELECT V_REF MODE
	#if V_REF==AREF
		CLR_BIT(ADMUX, REFS1);
		CLR_BIT(ADMUX, REFS0);
	#elif V_REF==AVCC
		CLR_BIT(ADMUX, REFS1);
		SET_BIT(ADMUX, REFS0);
	#elif V_REF==V2_56
		SET_BIT(ADMUX, REFS1);
		SET_BIT(ADMUX, REFS0);
	#endif


	//SELECT Left Adjust Result
	#if LEFT_ADJUST_MODE==LEFT_ADJ
		SET_BIT(ADMUX,ADLAR);
	#elif LEFT_ADJUST_MODE==RIGHT_ADJ
		CLR_BIT(ADMUX,ADLAR);
	#endif


	//SELECT PRESCALER
	#if ADC_PRESCALER   ==	PRE_2
		CLR_BIT(ADCSRA,ADPS2);
		CLR_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS0);
	#elif ADC_PRESCALER == 	PRE_4
		CLR_BIT(ADCSRA,ADPS2);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS0);
	#elif ADC_PRESCALER == 	PRE_8
		CLR_BIT(ADCSRA,ADPS2);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS0);
	#elif ADC_PRESCALER == 	PRE_16
		SET_BIT(ADCSRA,ADPS2);
		CLR_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS0);
	#elif ADC_PRESCALER == 	PRE_32
		SET_BIT(ADCSRA,ADPS2);
		CLR_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS0);
	#elif ADC_PRESCALER == 	PRE_64
		SET_BIT(ADCSRA,ADPS2);
		SET_BIT(ADCSRA,ADPS1);
		CLR_BIT(ADCSRA,ADPS0);
	#elif ADC_PRESCALER == 	PRE_128
		SET_BIT(ADCSRA,ADPS2);
		SET_BIT(ADCSRA,ADPS1);
		SET_BIT(ADCSRA,ADPS0);
	#endif



	//SELECT ADC Interrupt Enable
	#if INT_MODE == ADC_INT_EN
		SET_BIT(ADCSRA, ADIE);
	#elif INT_MODE == ADC_INT_DIS
		CLR_BIT(ADCSRA,ADIE);
	#endif

	//ADC ENABLE
	SET_BIT(ADCSRA,ADEN);

}

//FUNCTION TO READ THE VALUE (POLLING)
void  ADC_Get_Value( u8 ADC_Channel ,pu16 ADC_Copy_Res ){

	if ( ADC_Copy_Res != NULL)
		{
			if(ADC_State==SLEEP){
				//MAKE ADC BUSY TO AVOID OVERWRITE IF ANY INTERRUPT HAPPENED TO ADC BEFOR COMPLETE CONVERSTIO
				ADC_State=BUSY;

				//to clear first five bits
				ADMUX &=ADC_CH_MASK;
				//to select channel
				ADMUX |= ADC_Channel;

				//Start Conversion
				SET_BIT(ADCSRA,ADSC);

				while((GET_BIT(ADCSRA , ADIF)) == 0);

				//Clear the interrupt flag
				SET_BIT(ADCSRA , ADIF);

				//RETURN ADC MODE
				ADC_State=SLEEP;

				//RETURN VALUE
				*ADC_Copy_Res = (ADCL|(ADCH << 8));
			}
		}
}


//FUNCTION TO READ VALUE  (Asynchronous) INTERRUPT
void ADC_StartConv_INT( u8 ADC_Channel , pu16 ADC_Copy_Res , void(*CallBack_Func)(void) ){

	if((ADC_Copy_Res != NULL ) && (CallBack_Func != NULL )){
		//CHECK THE ADC STATE
		if(ADC_State == SLEEP){
			//TO AVOID IF RECALL FUNCTION HAPPENED
			ADC_State=BUSY;

			//select Asynchronous mode
			ADC_AsynchMode = SINGLE_MODE_ASYNCH;

			//Initialization global pointer of result
			ADC_AsynchConverResult = ADC_Copy_Res ;

			//Initialization global pointer of call back function
			ADC_CallBack_Asynch = CallBack_Func ;

			//to clear first five bits
			ADMUX &=ADC_CH_MASK;

			//to select channel
			ADMUX |= ADC_Channel;

			//Start Conversion
			SET_BIT(ADCSRA,ADSC);

			//ADC Interrupt Enable
			SET_BIT(ADCSRA, ADIE);
		}
	}
}


//FUNCTION TO GET VALUE OF CHAIN OF CHANNELS
void ADC_StartChainAsynch  ( ADC_STRUCT *Copy_Chain){
	if ((Copy_Chain != NULL))
		{
		if(ADC_State == SLEEP){

			ADC_State=BUSY;

			//select Asynchronous mode
			ADC_AsynchMode = CHAIN_MODE_ASYNCH;

			//Set Index to first element
			ADC_ChainIndex = 0 ;

			//Assign the ADC data globally
			ADC_Result 			= Copy_Chain->result ;
			ADC_ChainSize 		= Copy_Chain->size ;
			ADC_CB_FuncChain 	= Copy_Chain->ADC_CB_FUNC_Chain ;

			//Set required channel
			//to clear first five bits
			ADMUX &= ADC_CH_MASK ;
			//to select channel
			ADMUX |= ADC_ChainIndex ;

			//Start Conversion
			SET_BIT(ADCSRA,ADSC);

			//ADC Interrupt Enable
			SET_BIT(ADCSRA, ADIE);

			}
		}
}


//ISR FUNCTION FOR ADC FOR TWO MODE SINGLE Asynchronous AND CHAIN Asynchronous
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void){
	//FOR SINGLE MODE
	if(ADC_AsynchMode == SINGLE_MODE_ASYNCH){
		//READ Result
		#if LEFT_ADJUST_MODE == RIGHT_ADJ
			*ADC_AsynchConverResult = (ADCL|(ADCH << 8))  ;
		#elif LEFT_ADJUST_MODE == LEFT_ADJ
			*ADC_AsynchConverResult = ADCH ;
		#endif

		//ADC STATE
		ADC_State=SLEEP;

		//call back function
		ADC_CallBack_Asynch();

		//ADC Interrupt Disable
		CLR_BIT(ADCSRA, ADIE);
	}

	else{
		//FOR CHAIN MODE


		//READ Result
		#if LEFT_ADJUST_MODE == RIGHT_ADJ
			ADC_Result[ADC_ChainIndex] = (ADCL|(ADCH << 8))  ;
		#elif LEFT_ADJUST_MODE == LEFT_ADJ
			ADC_Result[ADC_ChainIndex] = ADCH ;
		#endif

		//increment ChainIndex
		ADC_ChainIndex++;


		if(ADC_ChainIndex == ADC_ChainSize ){
			//ADC STATE
			ADC_State=SLEEP;

			//CALL BACK FINCTION
			ADC_CB_FuncChain();

			//ADC Interrupt Disable
			CLR_BIT(ADCSRA, ADIE);

		}
		else{
			//TO USE NESTED INTERRUPT
			sei();
			//Set required channel
			ADMUX &= ADC_CH_MASK ;
			ADMUX |= ADC_ChainIndex ;

			//Start Conversion
			SET_BIT(ADCSRA , ADSC) ;
		}
}
}







