/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName  : BUZZ.c
 *
 */

#include <util/delay.h>
#include "../../MCAL/DIO/DIO.h"
#include "BUZZ.h"

void BUZZ_vPlay(u8 pin_num){
	u8 x=3;
	while(x--){
		DIO_vSetPinHigh(pin_num);
		_delay_ms(100);
		DIO_vSetPinLOW(pin_num);
		_delay_ms(100);
	}
}

