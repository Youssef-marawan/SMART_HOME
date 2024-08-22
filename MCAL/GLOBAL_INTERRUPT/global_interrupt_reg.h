/*
 * Author	 : YOUSSEF MARAWAN
 * FileName   : global_interrupt_reg.h
 *
 */

#ifndef MCAL_GLOBAL_INTERRUPT_GLOBAL_INTERRUPT_REG_H_
#define MCAL_GLOBAL_INTERRUPT_GLOBAL_INTERRUPT_REG_H_

#include "../../LIB/STD_DataType.h"

#define SREG 	(*((volatile pu8)0x5f))
#define TCCR2	(*((volatile pu8 )0x45))

#define 	I 		7

#endif /* MCAL_GLOBAL_INTERRUPT_GLOBAL_INTERRUPT_REG_H_ */
