/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName  : LDR.h
 */

#ifndef HAL_LDR_LDR_H_
#define HAL_LDR_LDR_H_

#include "../../LIB/STD_DataType.h"

void LDR_GetValPolling( u8 channel , pu16 LDR_Value );
void LDR_GetVal_INT   ( u8 channel , double* Temp_Result , void(* CALLB_FUNCTION ) (void) );

#endif /* HAL_LDR_LDR_H_ */
