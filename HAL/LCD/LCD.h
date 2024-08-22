/*
 * FileName : LCD.h
 * Author   : youssef
 *
 */


#ifndef LCD_H_
#define LCD_H_

#include "../../LIB/STD_DataType.h"



/*
 *************************************************
 * purpose    :SET MODE OF LCD
 * parameters :VOID
 * ReturnType :VOID
 *************************************************
 */
void LCD_voidInit();


/*
 *************************************************
 * purpose    :SEND COMMAND TO LCD
 * parameters :COMMAND (u8)
 * ReturnType :VOID
 *************************************************
 */
void LCD_voidSendCommand(u8 loc_u8Command);


/*
 *************************************************
 * purpose    :SEND CHAR TO LCD
 * parameters :VOID
 * ReturnType :VOID
 *************************************************
 */
void LCD_voidSendChar(u8 loc_u8Char);


/*
 *************************************************
 * purpose    :SEND STRING TO LCD
 * parameters :STRING (pu8)
 * ReturnType :VOID
 *************************************************
 */
void LCD_voidSendString(pu8 loc_u8String);


/*
 *************************************************
 * purpose    :CURSOR GOTO ROW AND CLOUMN
 * parameters :ROW AND CLOUMN
 * ReturnType :VOID
 *************************************************
 */
void LCD_voidSetCursor(u8 loc_u8Row ,u8 loc_u8Column);

/*
 *************************************************
 * purpose    :PRINT NUMBER ON LCD
 * parameters :VALUE OF THE NUMBER
 * ReturnType :VOID
 *************************************************
 */
void LCD_voidSendNumber(s64 loc_s16Number);


/*
 *************************************************
 * purpose    :CLEAR_LCD
 * parameters :VOID
 * ReturnType :VOID
 *************************************************
 */
void LCD_CLEAR();

#endif /* LCD_H_ */
