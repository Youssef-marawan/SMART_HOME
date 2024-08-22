/*
 *  Created on: 10/08/2024
 *  Author	  : YOUSSEF MARAWAN
 *  Project	  : SMART HOME
 *
 */

#ifndef HEADER_FILES_H_
#define HEADER_FILES_H_


/*********************** LIB  ***************************/
#include "LIB/STD_DataType.h"
#include "LIB/Pin_Name.h"
#include "LIB/Bit_Masking.h"
#include <util/delay.h>
/*********************** MCAL ***************************/
#include "MCAL/DIO/DIO.h"
#include "MCAL/UART/UART.h"
#include "MCAL/I2C/TWI.h"
#include "MCAL/ADC/ADC.h"
#include "MCAL/TIMER0/timer.h"
#include "MCAL/GLOBAL_INTERRUPT/global_interrupt.h"
#include "MCAL/ADC/ADC.h"
#include "MCAL/ADC/ADC_cfg.h"
#include "MCAL/EXTERNAL_INTERRUPT/external_interrupt.h"
/*********************** HAL  ***************************/
#include "HAL/LCD/LCD.h"
#include "HAL/KEYPAD/KEY_PAD.h"
#include "HAL/EEPROM/EEPROM.h"
#include "HAL/LED/LED.h"
#include "HAL/SERVO/servo_cfg.h"
#include "HAL/SERVO/servo.h"
#include "HAL/BUZZ/BUZZ.h"
#include "HAL/LM35/LM35.h"
#include "HAL/DC_MOTOR/dc_motor.h"
#include "HAL/DC_MOTOR/dc_motor_cfg.h"
#include "HAL/LDR/LDR.h"
#include "HAL/STEPPER/STEPPER.h"
/*********************** Configurations ***************************/
#define ENTER   			13
#define PROGRAM_WORKED 		'X'
#define RESET				0
#define TEST_ADDRESS		10
#define DATA_ADDRESS		0
#define OPENED				1
#define CLOSED				0
#define ON					1
#define OFF					0
#define RIGHT				1
#define LEFT				2
#define MORNING				0
#define NIGHT				1
#define UNPRESSED		   -1
#define SECOND				3907
#define PRELOAD_VALUE		192
#define TWI_MASTER_ADDRESS	1
#define ONE_CHAR			1
#define SIX_CHAR			6
#define WAKEUP				'W'
/*********************** VARIABLES ***************************/
u8 user_data[7]			;
u8 test_word[2]			;
u8 door 		= CLOSED;
u8 window		= CLOSED;
u8 light_in		= ON	;
u8 light_out			;
u16 temp				;
u16 LDR					;
u8 	fan			= OFF	;
u8 sleep				;
/*********************** FUNCTIONS ***************************/
//this function called every one second the get the variables of sensors
void check_function(){
	LM35_GetValPolling(ADC_MODE_0,(pu16)&temp);
	LDR_GetValPolling(ADC_MODE_1,(pu16)&LDR);
	if(LDR < 25){
		light_out =NIGHT;
		LED_vSetLedOn(D1);
	}
	else{
		light_out =MORNING;
		LED_vSetLedOff(D1);
	}
}


//this function called when use the button to clear the user
void reset(){

	EEPROM_Send_Data(RESET,TEST_ADDRESS);

	//turn on red led
	LED_vSetLedOn(D6);
	_delay_ms(500);
	//turn off red led
	LED_vSetLedOff(D6);


}



#endif /* HEADER_FILES_H_ */
