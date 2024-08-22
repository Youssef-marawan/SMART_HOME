/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName   : timer.cfg.h
 *
 */

#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_

/****************************************
 *
 *
***************TIMER0********************
*
*
*****************************************/


//TIMER0 MODE
#define NORMAL  		1
#define PWM 			2
#define CTC 			3
#define FAST_PWM		4
/*************************************/
#define TIMER0_MODE 	NORMAL
/*************************************/




//Compare Output Mode non-PWM Mode (OC0 pin)
#define OC0_DISCONNECTED 		1
#define OC0_TOGGLE				2
#define OC0_CLEAR 				3
#define OC0_SET					4
/*************************************/
#define TIMER0_CTC_MODE 	OC0_DISCONNECTED
/*************************************/



//Compare Output Mode PWM Mode(FAST OR PHASE CORRECT) (OC0 pin)
#define OC0_DISCONNECTED 			1
#define CLR_CMP_SET_TOP 			3
#define SET_TOP_CLR_CMP				4
/*************************************/
#define TIMER0_PWM_MODE 	OC0_DISCONNECTED
/*************************************/



//PRESCALER SELECT
#define NO_CLK 				1
#define PRE_1				2
#define PRE_8 				3
#define PRE_64				4
#define PRE_256 			5
#define PRE_1024			6
#define EXT_CLK_FALL		7
#define EXT_CLK_RISE		8

/*************************************/
#define TIMER0_PRESCALER 	PRE_8
/*************************************/




#endif /* TIMER_CFG_H_ */
