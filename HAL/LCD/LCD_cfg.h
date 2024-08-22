/*
 * FileName : LCD_cfg.h
 * Author   : youssef
 *
 */


#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "../../LIB/pin_name.h"
#include "../../LIB/STD_DataType.h"

//SELECT THE MODE OF CONNECTION
#define FOUR_BIT_MODE   0
#define EIGHT_BIT_MODE  1
/**************************************/
#define LCD_MODE        FOUR_BIT_MODE
/**************************************/


//OUTPUT ON PORT [A,B,C,D]
#define X4           C4
#define X5           C5
#define X6           C6
#define X7           C7

//PIN TO RS
#define RS 			 C2

//PIN FOR E
#define E 			 C3



#endif /* LCD_CFG_H_ */
