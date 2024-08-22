/*
 * FileName  : LED_vSetLedOn.h
 * Author    : youssef marawan
 *
 */

#ifndef LED_H_
#define LED_H_
#include "../../LIB/STD_DataType.h"
/*
 *******************************************************
 * purpose    :MAKE LED ON (PIN -> HIGH)
 * parameters :PinNumber [0 ~ 31]
 * ReturnType :ERROR_STATUS
 *******************************************************
 */
ERROR_STATUS LED_vSetLedOn(u8 pin);


/*
 *******************************************************
 * purpose    :MAKE LED OFF (PIN -> LOW)
 * parameters :PinNumber [0 ~ 31]
 * ReturnType :ERROR_STATUS
 *******************************************************
 */
ERROR_STATUS LED_vSetLedOff(u8 pin);


/*
 *******************************************************
 * purpose    :MAKE LED TOGGLE
 * parameters :PinNumber [0 ~ 31]
 * ReturnType :ERROR_STATUS
 *******************************************************
 */
ERROR_STATUS LED_vSetLedToggle(u8 pin);


#endif /* LED_H_ */
