/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName  : KEY_PAD.c
 *
 */

#include "KEY_PAD.h"
#include"../../MCAL/DIO/DIO.h"
#include "KEY_PAD_cfg.h"
#include <math.h>



/*************************************************
 *
 * purpose     : INIT THE PIN MAKE COLUMN OUTPUT AND ROW INPUT AND ACTIVE PULLUP FOR INPUT
 * parameters  : VOID
 * return type : VOID
 *
 *************************************************
 */
void KeyPad_Init(){
	DIO_vSetPinHigh(COL_0);
	DIO_vSetPinHigh(COL_1);
	DIO_vSetPinHigh(COL_2);
	DIO_vSetPinHigh(COL_3);
	DIO_vSetPinHigh(ROW_0);
	DIO_vSetPinHigh(ROW_1);
	DIO_vSetPinHigh(ROW_2);
	DIO_vSetPinHigh(ROW_3);
}



/*************************************************
 *
 * purpose     : GET THE KEY PRESSED
 * parameters  : pu8 pointer to change the value of variable in main
 * return type : ERROR_STATUS
 *
 *************************************************
 */
s8 KeyPad_GetKey(){

		u8 	arr_row[4]={ROW_0,ROW_1,ROW_2,ROW_3};
		u8 	arr_col[4]={COL_0,COL_1,COL_2,COL_3};
		//u8 key_index[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
		//s8 key_index[4][4]={{7,8,9,10},{4,5,6,11},{1,2,3,12},{13,0,15,16}};
		u8 key_index[4][4]={{0,1,2,3},{4,5,6,7},{8,9,10,11},{12,13,14,15}};

		u8 loc_u8Col;
		u8 loc_u8Row;

		u8 value;

		for( loc_u8Col = 0 ; loc_u8Col < 4 ; loc_u8Col++ ){
			DIO_vSetPinLOW(arr_col[loc_u8Col]);
			for( loc_u8Row = 0 ; loc_u8Row < 4 ; loc_u8Row++ ){
				value = DIO_u8GetPin(arr_row[loc_u8Row]);
				if((value) == 0){
					while((value) == 0){value = DIO_u8GetPin(arr_row[loc_u8Row]);}
					return	key_index[loc_u8Row][loc_u8Col];
				}
			}
			DIO_vSetPinHigh(arr_col[loc_u8Col]);
		}
		return -1;
}

