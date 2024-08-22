/*
 * Author	 : YOUSSEF MARAWAN
 * FileName  : servo.c
 */

#include "servo_cfg.h"
#include "servo.h"
#include "../../MCAL/TIMER1/timer1.h"
#include "../../MCAL/TIMER1/timer1_reg.h"


void SERVO_Init(){
	TIMER1_Init();
	ICR1=19999;
}

void SERVO_Rotate(u8 value){

	if(value == ANGLE_0){
		TIMER1_SetChannel_A_OCR1(700);
	}
	else if(value == ANGLE_90){
		TIMER1_SetChannel_A_OCR1(1750);
	}
	else if(value == ANGLE_180){
		TIMER1_SetChannel_A_OCR1(2575);
	}
}

