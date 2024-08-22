/********************************************************************************
 *
 *
 * FileName    : DIO.h
 * Description : header file for ATMEGA32 MCU's DIO Peripheral
 * Author      : Youssef Marawan
 *
 *
 ********************************************************************************/

#ifndef DIO_H_
#define DIO_H_
#include "../../LIB/STD_DataType.h"


typedef enum {
	DIO_INV_PORT,
	DIO_INV_PIN,
	DIO_INV_DIR,
	DIO_OK,
}DIO_ERROR_STATUS;


/**********************************************************
 *
 *Purpose    :SET DIRECTION OF ALL PIN USING (DIO_cfg.h)
 *Parameter  :VOID
 *ReturnType :VOID
 *
 **********************************************************
 */
void DIO_Set_Dir(void);


/**********************************************************
 *
 *Purpose    :SET PIN HIGH (output -> high)
 *Parameter  :PinNumber [0 ~ 31]
 *ReturnType :ERROR_STATUS
 *
 **********************************************************
 */
DIO_ERROR_STATUS DIO_vSetPinHigh (u8 loc_u8PinNumber);


/**********************************************************
 *
 *Purpose    :SET PIN LOW (output -> low)
 *Parameter  :PinNumber [0 ~ 31]
 *ReturnType :ERROR_STATUS
 *
 **********************************************************
 */
DIO_ERROR_STATUS DIO_vSetPinLOW (u8 loc_u8PinNumber);


/**********************************************************
 *
 *Purpose    :GET VALUE OF PIN
 *Parameter  :PinNumber
 *ReturnType :ERROR_STATUS
 *
 **********************************************************
 */
u8 DIO_u8GetPin(u8 loc_u8PinNumber);


/**********************************************************
 *
 *Purpose    :Set VALUE On Port
 *Parameter  :PortNumber AND VALUE
 *ReturnType :ERROR_STATUS
 *
 **********************************************************
 */
DIO_ERROR_STATUS DIO_u8SetPort(u8 loc_u8PortNumber,u8 loc_u8Value);


/**********************************************************
 *
 *Purpose    :Toggle VALUE Of Pin
 *Parameter  :Pin Number
 *ReturnType :ERROR_STATUS
 *
 **********************************************************
 */
DIO_ERROR_STATUS DIO_u8SetToggle(u8 loc_u8PinNumber);





#endif /* DIO_H_ */
