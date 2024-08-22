/*
 *  Author	  : YOUSSEF MARAWAN
 *  FileName   : ADC_cfg.h
 *
 */

#ifndef ADC_CFG_H_
#define ADC_CFG_H_

//SELECT V_REF
#define  AREF	1
#define  AVCC	2
#define  V2_56	3
/**********************/
#define V_REF	AVCC
/**********************/


//SELECT CHANNEL MODE
#define  ADC_MODE_0		0
#define  ADC_MODE_1		1
#define  ADC_MODE_2		2
#define  ADC_MODE_3		3
#define  ADC_MODE_4		4
#define  ADC_MODE_5		5
#define  ADC_MODE_6		6
#define  ADC_MODE_7		7
#define  ADC_MODE_8		8
#define  ADC_MODE_9		9
#define  ADC_MODE_10	10
#define  ADC_MODE_11	11
#define  ADC_MODE_12	12
#define  ADC_MODE_13	13
#define  ADC_MODE_14	14
#define  ADC_MODE_15	15
#define  ADC_MODE_16	16
#define  ADC_MODE_17	17
#define  ADC_MODE_18	18
#define  ADC_MODE_19	19
#define  ADC_MODE_20	20
#define  ADC_MODE_21	21
#define  ADC_MODE_22	22
#define  ADC_MODE_23	23
#define  ADC_MODE_24	24
#define  ADC_MODE_25	25
#define  ADC_MODE_26	26
#define  ADC_MODE_27	27
#define  ADC_MODE_28	28
#define  ADC_MODE_29	29
#define  ADC_MODE_30	30
#define  ADC_MODE_31	31



//SELECT PRESCALER
#define  PRE_2		1
#define  PRE_4		2
#define  PRE_8		3
#define  PRE_16		4
#define  PRE_32		5
#define  PRE_64		6
#define  PRE_128	7
/**********************/
#define ADC_PRESCALER	PRE_2
/**********************/



//SELECT AUTO TRIGGLE SOURCE
#define	 NO_SOURCE				0
#define  FREE_RUNNING			1
#define  ANALOG_COMPARATOR		2
#define  EXT_INT				3
#define  TMR0_CMR				4
#define  TMR0_OVF				5
#define  TMR_CMR_B				6
#define  TMR1_OVF				7
#define  TMR1_CAP				8

//ADC STATE
#define SLEEP 0
#define BUSY  1



//AUTO TRIGGLE ENABLE
#define AUTO_TRIGGLE_EN  	1
#define AUTO_TRIGGLE_DIS  	2

//SELECT ASYNCH MODE
#define SINGLE_MODE_ASYNCH   1
#define CHAIN_MODE_ASYNCH	 2

//SELECT Left Adjust Result
#define LEFT_ADJ  	1
#define RIGHT_ADJ 	2
/************************/
#define LEFT_ADJUST_MODE	       RIGHT_ADJ
/************************/


//SELECT ADC Interrupt Enable
#define ADC_INT_EN  	1
#define ADC_INT_DIS 	2
/************************/
#define INT_MODE	                ADC_INT_EN
/************************/


#endif /* ADC_CFG_H_ */
