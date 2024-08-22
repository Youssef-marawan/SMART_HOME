/*
 * File_Name	:	DIO_Reg.h
 * Author		: 	youssef marawan
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

//Port X Data Direction Register
#define DDRA ((volatile pu8)0x3A)
#define DDRB ((volatile pu8)0x37)
#define DDRC ((volatile pu8)0x34)
#define DDRD ((volatile pu8)0x31)


//Port X Data Register
#define PORTA ((volatile pu8)0x3B)
#define PORTB ((volatile pu8)0x38)
#define PORTC ((volatile pu8)0x35)
#define PORTD ((volatile pu8)0x32)


//Port X Input Pins Address
#define PINA ((volatile pu8)0x39)
#define PINB ((volatile pu8)0x36)
#define PINC ((volatile pu8)0x33)
#define PIND ((volatile pu8)0x30)


#endif /* DIO_REG_H_ */
