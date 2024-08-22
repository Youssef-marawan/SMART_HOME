/*
 * FileName : LCD.c
 * Author   : youssef
 */
#include "LCD.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/pin_name.h"
#include "util/delay.h"
#include "LCD_cfg.h"
#include "../../LIB/Bit_Masking.h"

//FUNCTION USE TO SEND 4 BITS TO THE HIGHEST PINS IN LCD (PIN4 ~ PIN7)
static void SendHighData(u8 copy_u8_data){
	u8 arr[4]={X4,X5,X6,X7};
	u8 loc_u8Counter;
	for( loc_u8Counter = 0 ; loc_u8Counter < 4 ; loc_u8Counter++ ){
		u8 loc_u8BitValue = GET_BIT( copy_u8_data , loc_u8Counter );
		if( loc_u8BitValue ){
			DIO_vSetPinHigh( arr[ loc_u8Counter ]); }
		else{
			DIO_vSetPinLOW(arr[loc_u8Counter]);
		}
	}
}


//FUNCTION TO GENERATE PULSE
static void Enable(){
	DIO_vSetPinHigh(E);
	_delay_ms(1);
	DIO_vSetPinLOW(E);
}



/*
 *************************************************
 * purpose    :SEND COMMAND TO LCD
 * parameters :COMMAND (u8)
 * ReturnType :VOID
 *************************************************
 */
void LCD_voidSendCommand(u8 loc_u8Command){
	#if LCD_MODE == FOUR_BIT_MODE
			DIO_vSetPinLOW( RS );
			SendHighData(loc_u8Command >> 4);
			Enable();
			SendHighData(loc_u8Command);
			Enable();
	#elif LCD_MODE == EIGHT_BIT_MODE
			DIO_vSetPinLOW( RS );
			DIO_u8SetPort(PORTX,loc_u8Command);
			Enable();
	#endif
}


/*
 *************************************************
 * purpose    :SET MODE OF LCD
 * parameters :VOID
 * ReturnType :VOID
 *************************************************
 */
void LCD_voidInit(){
		_delay_ms(30);
	#if LCD_MODE == FOUR_BIT_MODE
			SendHighData(0b0010);
			Enable();
			SendHighData(0b0010);
			Enable();
			SendHighData(0b1000);
			Enable();
	#elif LCD_MODE == EIGHT_BIT_MODE
			LCD_voidSendCommand(0b00111000);
	#endif
		_delay_ms(1);
		LCD_voidSendCommand(0x0C);
		_delay_ms(1);
		LCD_voidSendCommand(0x01);
		_delay_ms(2);
}



/*
 *************************************************
 * purpose    :SEND CHAR TO LCD
 * parameters :VOID
 * ReturnType :VOID
 *************************************************
 */
void LCD_voidSendChar(u8 loc_u8Char){
	DIO_vSetPinHigh( RS );
	#if LCD_MODE == FOUR_BIT_MODE
			SendHighData( loc_u8Char >> 4);
			Enable();
			SendHighData( loc_u8Char );
			Enable();
	#elif LCD_MODE == EIGHT_BIT_MODE
		DIO_u8SetPort( PORTX , loc_u8Char );
		Enable();
	#endif

}


/*
 *************************************************
 * purpose    :SEND STRING TO LCD
 * parameters :STRING (pu8)
 * ReturnType :VOID
 *************************************************
 */
void LCD_voidSendString(pu8 add_u8String){
	u8 loc_u8In=0;
	while( add_u8String [ loc_u8In ] != '\0' ){
		LCD_voidSendChar( add_u8String[ loc_u8In ] );
		loc_u8In++;
	}
}



/*
 *************************************************
 * purpose    :CURSOR GOTO ROW AND CLOUMN
 * parameters :ROW AND CLOUMN
 * ReturnType :VOID
 *************************************************
 */
void LCD_voidSetCursor(u8 loc_u8Row ,u8 loc_u8Column){
	u8 command;
	if(loc_u8Row > 0){loc_u8Row=1;}
	command = 128 + (64 * loc_u8Row) + loc_u8Column ;
	LCD_voidSendCommand(command);
}



/*
 *************************************************
 * purpose    :PRINT NUMBER ON LCD
 * parameters :VALUE OF THE NUMBER
 * ReturnType :VOID
 *************************************************
 */
void LCD_voidSendNumber(s64 loc_s16Number){
	long long int arr[10];
	u8 i=0;
	s8 j;
	if(loc_s16Number >= 0){
		do{
			arr[ i ] = (loc_s16Number % 10) ;
			loc_s16Number /= 10 ;
			i++;
		}while( loc_s16Number > 0);
		i--;
		for(j=i;j>=0;j--){
			LCD_voidSendChar(arr[j] + 48);
		}
	}

}


/*
 *************************************************
 * purpose    :CLEAR_LCD
 * parameters :VOID
 * ReturnType :VOID
 *************************************************
 */
void LCD_CLEAR(){
	LCD_voidSendCommand(0x01);
}
