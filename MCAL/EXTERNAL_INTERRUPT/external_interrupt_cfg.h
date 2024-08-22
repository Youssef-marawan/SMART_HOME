/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName   : external_interrupt_cfg.h
 *
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_CFG_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_CFG_H_

//EXTERNAL INTERRUPT 0
#define 	EXT0_LOW_LEVEL		0
#define 	EXT0_ANY_CHANGE		1
#define 	EXT0_FALL_EDGE		2
#define 	EXT0_RISE_EDGE		3
/*******************************/
#define EXT_INT_MODE_0		EXT0_FALL_EDGE
/*******************************/


//EXTERNAL INTERRUPT 1
#define 	EXT1_LOW_LEVEL		0
#define 	EXT1_ANY_CHANGE		1
#define 	EXT1_FALL_EDGE		2
#define 	EXT1_RISE_EDGE		3
/*******************************/
#define EXT_INT_MODE_1		EXT1_FALL_EDGE
/*******************************/




//EXTERNAL INTERRUPT 2
#define 	EXT2_FALL_EDGE		0
#define 	EXT2_RISE_EDGE		1
/*******************************/
#define EXT_INT_MODE_2		EXT2_FALL_EDGE
/*******************************/


#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_CFG_H_ */
