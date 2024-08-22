/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName   : uart_reg.h
 *
 */

#ifndef MCAL_UART_UART_REG_H_
#define MCAL_UART_UART_REG_H_

//USART I/O Data Register
#define UDR (*(volatile pu8)0x2C)

//USART Control and Status Register A
#define UCSRA (*(volatile pu8)0x2B)

//USART Control and Status Register B
#define UCSRB (*(volatile pu8)0x2A)

//USART Control and Status Register C
#define UCSRC (*(volatile pu8)0x40)

//USART Baud Rate Registers
#define UBRRL (*(volatile pu8)0x29)

//USART Baud Rate Registers
#define UBRRH (*(volatile pu8)0x40)


//UCSRA
#define RXC			7
#define TXC			6
#define UDRE		5
#define FE 			4
#define DOR			3
#define PE 			2
#define U2X			1
#define MPCM		0


//UCSRB
#define RXCIE		7
#define TXCIE		6
#define UDRIE		5
#define RXEN		4
#define TXEN		3
#define UCSZ2		2
#define RXB8		1
#define TXB8		0


//UCSRC
#define URSEL		7
#define UMSEL		6
#define UPM1		5
#define UPM0		4
#define USBS		3
#define UCSZ1		2
#define UCSZ0		1
#define UCPOL		0

#endif /* MCAL_UART_UART_REG_H_ */
