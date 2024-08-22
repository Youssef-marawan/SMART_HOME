/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName   : timer1_cfg.h
 *
 */

#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_

//Waveform Generation Mode
#define 	TIMER1_NORMAL					0
#define 	TIMER1_PWM_PHASE_8_BIT			1
#define 	TIMER1_PWM_PHASE_9_BIT			2
#define 	TIMER1_PWM_PHASE_10_BIT			3
#define 	TIMER1_CTC						4
#define 	TIMER1_FAST_PWM_8_BIT			5
#define 	TIMER1_FAST_PWM_9_BIT			6
#define 	TIMER1_FAST_PWM_10_BIT			7
#define 	TIMER1_PWM_PHASE_FREQ_ICR1		8
#define 	TIMER1_PWM_PHASE_FREQ_OCR1		9
#define 	TIMER1_PWM_PHASE_ICR1			10
#define 	TIMER1_PWM_PHASE_OCR1			11
#define 	TIMER1_CTC_ICR1					12
#define 	TIMER1_FAST_PWM_ICR1			14
#define 	TIMER1_FAST_PWM_OCR1			15
/***********************************/
#define  TIMER1_WAVE_GENERATION_MODE		TIMER1_FAST_PWM_ICR1
/***********************************/



//Overflow Interrupt Enable
#define  TIMER1_OVF_Interrupt_ENABLE			0
#define  TIMER1_OVF_Interrupt_DISABLE			1
/***********************************/
#define  TIMER1_OVF_Interrupt_MODE		TIMER1_OVF_Interrupt_DISABLE
/***********************************/


//Output Compare A Match Interrupt Enable
#define  OC1A_Interrupt_ENABLE			0
#define  OC1A_Interrupt_DISABLE			1
/***********************************/
#define  TIMER1_OC1A_Interrupt_MODE		OC1A_Interrupt_DISABLE
/***********************************/


//Output Compare A Match Interrupt Enable
#define  OC1B_Interrupt_ENABLE			0
#define  OC1B_Interrupt_DISABLE			1
/***********************************/
#define  TIMER1_OC1B_Interrupt_MODE		OC1B_Interrupt_DISABLE
/***********************************/


// Compare Output Mode for Channel A (non_PWM)
#define  OC1A_DISCONNECTED		0
#define  OC1A_TOGGLE			1
#define  OC1A_CLEAR				2
#define  OC1A_SET				3
/***********************************/
#define  TIMER1_OC1A_CTC_MODE		OC1A_disconnected
/***********************************/




//Compare Output Mode for Channel B  ( non_PWM )
#define  OC1B_DISCONNECTED		0
#define  OC1B_TOGGLE			1
#define  OC1B_CLEAR				2
#define  OC1B_SET				3
/***********************************/
#define  TIMER1_OC1B_CTC_BMODE		OC1B_disconnected
/***********************************/



//Compare Output Mode for Channel A  ( FAST_PWM )
#define OC1A_DISCONNECTED 			0
#define OC1A_TOGGLE					1
#define CLR_CMP_SET_TOP 			2
#define SET_TOP_CLR_CMP				3
/*************************************/
#define TIMER1_OC1A_FAST_PWM_MODE 	CLR_CMP_SET_TOP
/*************************************/



//Compare Output Mode for Channel B  ( FAST_PWM )
#define OC1B_DISCONNECTED 			0
#define CLR_CMP_SET_TOP 			2
#define SET_TOP_CLR_CMP				3
/*************************************/
#define TIMER1_OC1B_FAST_PWM_MODE 	OC1B_DISCONNECTED
/*************************************/



//Compare Output Mode for Channel A  ( PHASE_PWM )
#define OC1A_DISCONNECTED 			0
#define OC1A_TOGGLE					1
#define CLR_UP_SET_DWN	 			2
#define SET_UP_CLR_DWN				3
/*************************************/
#define TIMER1_OC1A_PHASE_PWM_MODE 	OC1A_DISCONNECTED
/*************************************/



//Compare Output Mode for Channel B  ( PHASE_PWM )
#define OC1B_DISCONNECTED 			0
#define CLR_UP_SET_DWN 				2
#define SET_UP_CLR_DWN				3
/*************************************/
#define TIMER1_OC1B_PHASE_PWM_MODE 	OC1B_DISCONNECTED
/*************************************/



//SELECT CLK
#define 	TIMER1_NO_CLK				0
#define 	TIMER1_CLK_1				1
#define 	TIMER1_CLK_8				2
#define 	TIMER1_CLK_64				3
#define 	TIMER1_CLK_256				4
#define 	TIMER1_CLK_1024				5
#define 	TIMER1_EXT_CLK_FALLING		6
#define 	TIMER1_EXT_CLK_RISING		7
/*************************************/
#define TIMER1_CLK_MODE 	TIMER1_CLK_8
/*************************************/




//ICU SELECT EDGE
#define ICU_falling   1
#define ICU_RISING    2
/***********************************/
#define ICU_EDGE      ICU_falling
/***********************************/


//WDT PRESCALE
#define 	WDT_16_3	0
#define 	WDT_32_5	1
#define 	WDT_65_0	2
#define 	WDT_0_13	3
#define 	WDT_0_26	4
#define 	WDT_0_52	5
#define 	WDT_1_0		6
#define 	WDT_2_1		7
/***********************************/
#define WDT_PRESCALE	WDT_0_52
/***********************************/


#endif /* TIMER1_CFG_H_ */
