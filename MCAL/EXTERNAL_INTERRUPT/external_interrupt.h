/*
 * Author	 : YOUSSEF MARAWAN
 * FileName   : external_interrupt.h
 *
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_

#include "../../LIB/STD_DataType.h"

void EXT_INT_0_Init();
void EXT_INT_1_Init();
void EXT_INT_2_Init();


void EXT_INT_0_CallBack(void (*cb0_Fun)(void));
void EXT_INT_1_CallBack(void (*cb1_Fun)(void));
void EXT_INT_2_CallBack(void (*cb2_Fun)(void));




#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_H_ */
