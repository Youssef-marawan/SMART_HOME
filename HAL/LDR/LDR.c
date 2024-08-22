/*
 * Author	 : YOUSSEF MARAWAN
 * FileName  : LDR.c
 */

#include "../../MCAL/ADC/ADC.h"
#include "LDR.h"

//FUNCTION TO READ ANALOG VALUE AND CALCULATE VALUE OF Temperature
void LDR_GetValPolling( u8 channel , pu16 LDR_Value ){
		u16 DigitalValue;
		ADC_Get_Value( channel  , (pu16)&DigitalValue ) ;
		*LDR_Value = DigitalValue;
}



//FUNCTION TO GET ANALOG VALUE AND CALL CalcValue_INT
void LDR_GetVal_INT   ( u8 channel , double* AnalogResult , void(* CALLB_FUNCTION ) (void) )
{

	if( (AnalogResult != NULL) && (CALLB_FUNCTION != NULL) )
	{

		ADC_StartConv_INT(channel,(pu16)&AnalogResult,CALLB_FUNCTION);

	}
}


