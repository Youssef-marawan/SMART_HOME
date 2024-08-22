/*
 * Author	 : YOUSSEF MARAWAN
 * FileName   : external_interrupt.c
 *
 */

#include "external_interrupt.h"
#include "external_interrupt_reg.h"
#include "external_interrupt_cfg.h"
#include "../../LIB/Bit_Masking.h"
#include "../../LIB/STD_DataType.h"
#include "../../MCAL/DIO/DIO_reg.h"


//GLOBAL POINTER FOR CALL BACK FUNCTION
static void (* EXT_0)(void)= NULL ;
static void (* EXT_1)(void)= NULL ;
static void (* EXT_2)(void)= NULL ;


void EXT_INT_0_Init(){
	//SELECT Interrupt 0 Sense Control
	MCUCR &= 252;
	MCUCR |= EXT_INT_MODE_0;

	//SET INTERRUPT ENABLE
	SET_BIT(GICR,INT0);

	SET_BIT(*PORTD,2);
}

void EXT_INT_1_Init(){
	//SELECT Interrupt 1 Sense Control
	MCUCR &= 243;
	MCUCR |= (EXT_INT_MODE_1 << 2);

	//SET INTERRUPT ENABLE
	SET_BIT(GICR,INT1);
}

void EXT_INT_2_Init(){
	//SELECT Interrupt 2 Sense Control
	MCUCSR &= 191;
	MCUCSR |= (EXT_INT_MODE_2 << 6);

	//SET INTERRUPT ENABLE
	SET_BIT(GICR,INT2);
}


void EXT_INT_0_CallBack(void (*cb0_Fun)(void)){
	EXT_0 = cb0_Fun;
}
void EXT_INT_1_CallBack(void (*cb1_Fun)(void)){
	EXT_1 = cb1_Fun;
}
void EXT_INT_2_CallBack(void (*cb2_Fun)(void)){
	EXT_2 = cb2_Fun;
}


//ISR FUNCTION FOR EXTERNAL INTERRUPT 0
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void){
	EXT_0();
}

//ISR FUNCTION FOR EXTERNAL INTERRUPT 1
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void){
	EXT_1();
}

//ISR FUNCTION FOR EXTERNAL INTERRUPT 2
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void){
	EXT_2();
}


