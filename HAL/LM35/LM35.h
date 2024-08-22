/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName  : LM35.h
 */

#ifndef HAL_LM35_LM35_H_
#define HAL_LM35_LM35_H_

#include "../../LIB/STD_DataType.h"

void LM35_GetValPolling( u8 channel , pu16 Temp_Value );
void LM35_GetVal_INT   ( u8 channel , pu16 Temp_Result , void(* CALLB_FUNCTION ) (void) );


#endif /* HAL_LM35_LM35_H_ */
