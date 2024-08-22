/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName   : timer_reg.h
 *
 */

#ifndef TIMER_REG_H_
#define TIMER_REG_H_



//GENERAL
#define TIMSK (*((volatile pu8)0x59))
#define TIFR  (*((volatile pu8)0x58))

//TIMER 0
#define TCCR0 (*((volatile pu8)0x53))
#define TCNT0 (*((volatile pu8)0x52))
#define OCR0  (*((volatile pu8)0x5C))


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


//TCCR0 REG
#define FOC0		7
#define WGM00		6
#define COM01 		5
#define COM00		4
#define WGM01		3
#define CS02 		2
#define CS01  		1
#define CS00		0



#endif /* TIMER_REG_H_ */
