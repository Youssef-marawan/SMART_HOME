/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName  : uart.c
 *
 */
#include "../../LIB/Bit_Masking.h"
#include "../../LIB/STD_DataType.h"
#include <util/delay.h>
#include "uart.h"
#include "UART_reg.h"

void UART_Init(){
	//Baud Rate	 = 9600
	UBRRL = 51;

	//Receiver Enable
	SET_BIT(UCSRB,RXEN);

	//Transmitter Enable
	//SET_BIT(UCSRB,TXEN);

	//NORMAL SPEED
	CLR_BIT(UCSRA,U2X);

	//USART Mode Select Asynchronous
	CLR_BIT(UCSRC,UMSEL);

	//Parity Mode Disable
	CLR_BIT(UCSRC,UPM0);
	CLR_BIT(UCSRC,UPM1);

	//Stop Bit Select One Bit
	CLR_BIT(UCSRC,USBS);

	//Character Size Select 8 Bit
	CLR_BIT(UCSRB,UCSZ2);
	UCSRC=(1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);


}


void UART_SendData(u8 loc_u8value){

	//wait to see the flag of UDR is empty
	while(GET_BIT(UCSRA,UDRE)==0);
	//put the data in UDR to transmit
	UDR = loc_u8value;

}


u8	 UART_ReceiveData(){

	//wait to see the flag of received data
	while(GET_BIT(UCSRA,RXC)==0);
	//read UDR
	return UDR;

}
void UART_SendString(pu8 loc_u8String){
	while(*loc_u8String != NULL){
		UART_SendData(*loc_u8String);
		loc_u8String++;
		_delay_ms(100);
	}
}

