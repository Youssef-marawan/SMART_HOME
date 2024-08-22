/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName   : timer.h
 *
 */

#ifndef TIMER_H_
#define TIMER_H_

#include"../../LIB/std_datatype.h"

//TIMER 0
void TIMER0_init();
void TIMER0_set_prescaler();
void TIMER0_set_preload(u8 value);
void TIMER0_set_OCR0(u8 value);
u8   TIMER0_get_count();
void TIMER0_SetCallBack(void (*CallBack)(void),u16 max_counter);




#endif /* TIMER_H_ */
