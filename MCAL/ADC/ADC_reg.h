/*
 * Author	 : YOUSSEF MARAWAN
 * FileName   : ADC_reg.h
 */

#ifndef ADC_REG_H_
#define ADC_REG_H_

//ADC Multiplexer Selection Register
#define ADMUX		(*((volatile pu8)0x27))
//ADC Control and Status Register A
#define ADCSRA		(*((volatile pu8)0x26))
//ADC Data Register
#define ADCL		(*((volatile pu8)0x24))
#define ADCH		(*((volatile pu8)0x25))
#define ADC			(*((volatile pu16)0x24))
//Special Function IO Register
#define SFIOR		(*((volatile pu8)0x50))


//ADMUX reg
#define REFS1	7
#define REFS0	6
#define ADLAR 	5
#define MUX4 	4
#define MUX3 	3
#define MUX2 	2
#define MUX1 	1
#define MUX0	0


// ADCSRA reg
#define ADEN	7
#define ADSC	6
#define ADATE	5
#define ADIF	4
#define ADIE	3
#define ADPS2	2
#define ADPS1	1
#define ADPS0	0


//SFIOR reg
#define ADTS2	7
#define ADTS1	6
#define ADTS0 	5
#define ACME	3
#define PUD 	2
#define PSR2	1
#define PSR10	0

#endif /* ADC_REG_H_ */
