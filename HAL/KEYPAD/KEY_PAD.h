/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName  : KEY_PAD.h
 *
 */

#ifndef KEY_PAD_H_
#define KEY_PAD_H_

#include "../../LIB/STD_DataType.h"



/*************************************************
 *
 * purpose     : INIT THE PIN MAKE COLUMN OUTPUT AND ROW INPUT AND ACTIVE PULLUP FOR INPUT
 * parameters  : VOID
 * return type : VOID
 *
 *************************************************
 */
void KeyPad_Init();


/*************************************************
 *
 * purpose     : GET THE KEY PRESSED
 * parameters  : pu8 pointer to change the value of variable in main
 * return type : ERROR_STATUS
 *
 *************************************************
 */
s8 KeyPad_GetKey();




#endif /* KEY_PAD_H_ */
