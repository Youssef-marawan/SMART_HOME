/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName  : LM35.c
 */

#include "../../MCAL/ADC/ADC.h"
#include "LM35.h"

//GLOBAL VALUE TO CARRY ANALOG VALUE WHEN USE Asynchronous FUNCTIONS
static u16 AnalogValue_INT;
//GLOBAL POINTER TO FUNCTION TO CARRY POINTER OF RETURN FUNCTION WHEN USE Asynchronous FUNCTIONS
static void (*ReturnFunc)(void);
//GLOBAL VALUE TO CARRY Temperature VALUE WHEN USE Asynchronous FUNCTIONS
static pu16 TempRes_INT;


//FUNCTION TO READ ANALOG VALUE AND CALCULATE VALUE OF Temperature
void LM35_GetValPolling( u8 channel , pu16 Temp_Value ){

		u16 DigitalValue;
		ADC_Get_Value( channel  , (pu16)&DigitalValue) ;


		 u16 AnalogValue = (u16) ((((u32) DigitalValue * 5000ul)/1024ul))  ;

		 *Temp_Value = AnalogValue / 10;

}


//FUNCTION TO CALCULATE TEMPERATURE VALUE AND CALL RETURN FUNCTION
static void CalcTempValue_INT(){
	*TempRes_INT = (u16) ((((u32) AnalogValue_INT * 5000ul)/1024ul) / 10)  ;
	ReturnFunc();
}



//FUNCTION TO GET ANALOG VALUE AND CALL CalcTempValue_INT
void LM35_GetVal_INT   ( u8 channel , pu16 AnalogResult , void(* CALLB_FUNCTION ) (void) )
{
	//Initialization global pointer for analog value
	TempRes_INT = AnalogResult;
	//Initialization global pointer for call back function
	ReturnFunc = CALLB_FUNCTION;


	if( (AnalogResult != NULL) && (CALLB_FUNCTION != NULL) )
	{

		ADC_StartConv_INT(channel,(pu16)&AnalogValue_INT,CalcTempValue_INT);

	}
}

