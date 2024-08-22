/*
 * Author	 : YOUSSEF MARAWAN
 * FileName   : global_interrupt.c
 *
 */


#include "global_interrupt_reg.h"
#include "global_interrupt.h"
#include "../../LIB/Bit_Masking.h"


void GLOBAL_INTERRUPT_Init(){
	SET_BIT(SREG,I);
}


