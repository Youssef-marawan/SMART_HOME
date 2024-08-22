/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName  : uart.h
 *
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "../../LIB/STD_DataType.h"

void UART_Init			(				 );
void UART_SendData		(u8 loc_u8value  );
u8	 UART_ReceiveData	(                );
void UART_SendString	(pu8 loc_u8String);

#endif /* MCAL_UART_UART_H_ */
