/*
 * FileName : LED.c
 * Author   : youssef
 */

#include"../../MCAL/DIO/DIO.h"
#include"LED.h"

/*
 *************************************************
 * purpose    :MAKE LED ON (PIN -> HIGH)
 * parameters :PinNumber [0 ~ 31]
 * ReturnType :ERROR_STATUS
 *************************************************
 */
ERROR_STATUS LED_vSetLedOn(u8 pin){
	return DIO_vSetPinHigh(pin);

}



/*
 *************************************************
 * purpose    :MAKE LED OFF (PIN -> LOW)
 * parameters :PinNumber [0 ~ 31]
 * ReturnType :ERROR_STATUS
 *************************************************
 */
ERROR_STATUS LED_vSetLedOff(u8 pin){
	return DIO_vSetPinLOW(pin);

}


/*
 *******************************************************
 * purpose    :MAKE LED TOGGLE
 * parameters :PinNumber [0 ~ 31]
 * ReturnType :ERROR_STATUS
 *******************************************************
 */
ERROR_STATUS LED_vSetLedToggle(u8 pin){
	return DIO_u8SetToggle(pin);
}


