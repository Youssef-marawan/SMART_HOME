/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName   : timer1_reg.h
 *
 */

#ifndef TIMER1_REG_H_
#define TIMER1_REG_H_

#include "../../LIB/STD_DataType.h"

//Register for timer 1


//Timer/Counter1 Control Register A
#define TCCR1A	(*((volatile pu8 )0x4F))
//Timer/Counter1 Control Register B
#define TCCR1B	(*((volatile pu8 )0x4E))
//Timer/Counter Interrupt Mask Register
#define TIMSK	(*((volatile pu8)0x59))
//Timer/Counter Interrupt Flag Register
#define TIFR	(*((volatile pu8)0x58))
//Timer/Counter1
#define TCNT1L	(*((volatile pu8 )0x4C))
#define TCNT1H	(*((volatile pu8 )0x4D))
#define TCNT1	(*((volatile pu16)0x4C))
//Output Compare Register 1 A
#define OCR1AH	(*((volatile pu8 )0x4B))
#define OCR1AL	(*((volatile pu8 )0x4A))
#define OCR1A	(*((volatile pu16)0x4A))
//Output Compare Register 1 B
#define OCR1BH	(*((volatile pu8 )0x49))
#define OCR1BL	(*((volatile pu8 )0x48))
#define OCR1B	(*((volatile pu16)0x48))
//Input Capture Register 1
#define ICR1H	(*((volatile pu8 )0x47))
#define ICR1L	(*((volatile pu8 )0x46))
#define ICR1	(*((volatile pu16)0x46))
//Watch dog Timer Control Register
#define WDTCR	(*((volatile pu16)0x41))


//TCCR1A REG
#define COM1A1		7
#define COM1A0		6
#define COM1B1		5
#define COM1B0		4
#define FOC1A		3
#define FOC1B		2
#define WGM11		1
#define WGM10		0


//TCCR1B REG
#define ICNC1		7
#define ICES1		6

#define WGM13		4
#define WGM12		3
#define CS12		2
#define CS11		1
#define CS10		0

//TIMSK REG
#define OCIE2       7
#define TOIE2		6
#define TICIE1		5
#define OCIE1A 		4
#define OCIE1B 		3
#define TOIE1		2
#define OCIE0 		1
#define TOIE0		0


//TIFR REG
#define OCF2		7
#define TOV2		6
#define ICF1 		5
#define OCF1A		4
#define OCF1B		3
#define TOV1		2
#define OCF0		1
#define TOV0		0


//WDTCR REG
#define WDTOE		4
#define WDE			3
#define WDP2		2
#define WDP1		1
#define WDP0		0

#endif /* TIMER1_REG_H_ */
