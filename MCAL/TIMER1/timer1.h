/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName   : timer1.h
 *
 */

#ifndef TIMER1_H_
#define TIMER1_H_

#include "../../LIB/STD_DataType.h"

//TIMER 1
void TIMER1_Init();
void TIMER1_SetPreload( u16 Copy_preload_value );
void TIMER1_SetChannel_A_OCR1( u16 Copy_OCRA_Value);
void TIMER1_SetChannel_B_OCR1( u16 Copy_OCRB_Value);
u16  TIMER1_GetTCNT1();


//ICU
void TIMER_ICU_Init();
u16  TIMER_ICU_GetICR();
void TIMER_ICU_ToggleEdge(u8 Copy_Edge_Value);


//WDT
void TIMER_WDT_Init();
void TIMER_WDT_READY();
void TIMER_WDT_DISABLE();




#endif /* TIMER1_H_ */
