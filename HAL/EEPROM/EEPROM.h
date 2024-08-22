/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName  : eeprom.h
 *
 */

#ifndef HAL_EEPROM_EEPROM_H_
#define HAL_EEPROM_EEPROM_H_

#include"../../LIB/STD_DataType.h"

void EEPROM_Send_Data(u8 data,u16 address);

void EEPROM_Read_Data(u16 address,u8 arr[],u8 size);

#endif /* HAL_EEPROM_EEPROM_H_ */
