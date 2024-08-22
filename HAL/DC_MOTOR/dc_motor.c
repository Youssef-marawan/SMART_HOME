/*
 * Author	 : YOUSSEF MARAWAN
 * FileName  : dc_motor.c
 *
 */

#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/Pin_Name.h"
#include "dc_motor.h"
#include "dc_motor_cfg.h"


static u8  DC_MOTOR_STATE = DC_MOTOR_STOP;

void DC_MOTOR_Move(u8 value){
	if(DC_MOTOR_STATE != value){

		DIO_vSetPinLOW(DC_MOTOR_PIN_1);
		DIO_vSetPinLOW(DC_MOTOR_PIN_2);

		DC_MOTOR_STATE = DC_MOTOR_STOP;


		if(value == DC_MOTOR_CLK){
			DIO_vSetPinHigh(DC_MOTOR_PIN_1);
			DC_MOTOR_STATE = DC_MOTOR_CLK;
		}
		else if(value == DC_MOTOR_ANTI_CLK){
			DIO_vSetPinHigh(DC_MOTOR_PIN_2);
			DC_MOTOR_STATE = DC_MOTOR_ANTI_CLK;
		}

	}
	else{

	}
}


