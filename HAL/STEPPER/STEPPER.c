/*
 * Author	 : YOUSSEF MARAWAN
 * FileName  : STEPPER.c
 */
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/STD_DataType.h"
#include "STEPPER_cfg.h"
#include "STEPPER.h"
#include <util/delay.h>


void STEPPER_CW  (u16 Copy_u16Angle){
	u16 Local_u16Stpes =  Copy_u16Angle / 0.7 ;
	u16 Local_u16Counter = 0 ;

	while(Local_u16Counter < Local_u16Stpes)
	{
		/* For First Step -> 0.175 */
		DIO_vSetPinLOW(ULN_0);
		DIO_vSetPinLOW(ULN_1);
		DIO_vSetPinLOW(ULN_2);
		DIO_vSetPinHigh(ULN_3);


		_delay_ms(2);

		/* For Second Step -> 0.175 */
		DIO_vSetPinLOW(ULN_0);
		DIO_vSetPinLOW(ULN_1);
		DIO_vSetPinHigh(ULN_2);
		DIO_vSetPinLOW(ULN_3);


		_delay_ms(2);

		/* For Third Step -> 0.175 */
		DIO_vSetPinLOW(ULN_0);
		DIO_vSetPinHigh(ULN_1);
		DIO_vSetPinLOW(ULN_2);
		DIO_vSetPinLOW(ULN_3);


		_delay_ms(2);



		/* For Fourth Step -> 0.175 */
		DIO_vSetPinHigh(ULN_0);
		DIO_vSetPinLOW(ULN_1);
		DIO_vSetPinLOW(ULN_2);
		DIO_vSetPinLOW(ULN_3);

		_delay_ms(2);


		/* Complete 0.175 * 4 Steps -> 0.7 degree */

		Local_u16Counter ++ ;
	}
}
void STEPPER_ACW (u16 Copy_u16Angle){
	u16 Local_u16Stpes =  Copy_u16Angle / 0.7 ;
	u16 Local_u16Counter = 0 ;

	while(Local_u16Counter < Local_u16Stpes)
	{
		/* For First Step -> 0.175 */
		DIO_vSetPinHigh(ULN_0);
		DIO_vSetPinLOW(ULN_1);
		DIO_vSetPinLOW(ULN_2);
		DIO_vSetPinLOW(ULN_3);

		_delay_ms(2);

		/* For Second Step -> 0.175 */
		DIO_vSetPinLOW(ULN_0);
		DIO_vSetPinHigh(ULN_1);
		DIO_vSetPinLOW(ULN_2);
		DIO_vSetPinLOW(ULN_3);

		_delay_ms(2);

		/* For Third Step -> 0.175 */
		DIO_vSetPinLOW(ULN_0);
		DIO_vSetPinLOW(ULN_1);
		DIO_vSetPinHigh(ULN_2);
		DIO_vSetPinLOW(ULN_3);

		_delay_ms(2);



		/* For Fourth Step -> 0.175 */
		DIO_vSetPinLOW(ULN_0);
		DIO_vSetPinLOW(ULN_1);
		DIO_vSetPinLOW(ULN_2);
		DIO_vSetPinHigh(ULN_3);

		_delay_ms(2);


		/* Complete 0.175 * 4 Steps -> 0.7 degree */

		Local_u16Counter ++ ;
	}

}
void STEPPER_Stop(){
	DIO_vSetPinLOW(ULN_0);
	DIO_vSetPinLOW(ULN_1);
	DIO_vSetPinLOW(ULN_2);
	DIO_vSetPinLOW(ULN_3);
}
