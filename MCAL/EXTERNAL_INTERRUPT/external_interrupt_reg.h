/*
 * Author	 : YOUSSEF MARAWAN
 * FileName   : external_interrupt_reg.h
 *
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_REG_H_
#define MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_REG_H_


// MCU Control Register
#define MCUCR	(*((volatile pu8 )0x55))
// MCU Control and Status Register
#define MCUCSR	(*((volatile pu8 )0x54))
// General Interrupt Control Register
#define GICR	(*((volatile pu8 )0x5B))
// General Interrupt Flag Register
#define GIFR	(*((volatile pu8 )0x5A))



//MCUCR
#define SE				7
#define SM2				6
#define SM1				5
#define SM0				4
#define ISC11			3
#define ISC10			2
#define ISC01			1
#define ISC00			0


//MCUCSR
#define JTD				7
#define ISC2			6
#define JTRF			4
#define WDRF			3
#define BORF			2
#define EXTRF			1
#define PORF			0


//GICR
#define INT1			7
#define INT0			6
#define INT2			5
#define IVSEL			1
#define IVCE			0


//GIFR
#define INTF1			7
#define INTF0			6
#define INTF2			5



#endif /* MCAL_EXTERNAL_INTERRUPT_EXTERNAL_INTERRUPT_REG_H_ */
