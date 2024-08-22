/*
 * File_Name  : DIO.C
 * Author     : Youssef Marawan
 *
 */

#include	"DIO.h"
#include	"DIO_Reg.h"
#include	"DIO_cfg.h"
#include	"../../LIB/Bit_Masking.h"
#include 	"../../LIB/pin_name.h"


/*
 ***************************************************************
 * MACRO LIKE FUN TO SET DIRECTION OF ALL PIN USING (DIO_cfg.h)
 ***************************************************************
 */
#define SET_DIR_(p7,p6,p5,p4,p3,p2,p1,p0) SET_DIR(p7,p6,p5,p4,p3,p2,p1,p0)
#define SET_DIR(p7,p6,p5,p4,p3,p2,p1,p0) 0b##p7##p6##p5##p4##p3##p2##p1##p0



/*
 ***************************************************************
 * Object Like MACROS
 ***************************************************************
 */
#define HIGH 			1
#define LOW 			0
#define MAX_PIN_NUM 	8
#define STEP_OF_REG 	3




//FUNCTION TO GET PORT NUMBER [0 ~ 3]
static u8 Decode_port(u8 loc_u8PinNumber){
	return loc_u8PinNumber / MAX_PIN_NUM ;
}



//FUNCTION TO GET PIN NUMBER [0 ~ 7]
static u8 Decode_pin(u8 loc_u8PinNumber){
	return loc_u8PinNumber % MAX_PIN_NUM ;
}



//FUNCTION TO GET DIRECTION OF PIN [OUTPUT , INPUT]
static u8 get_pin_dir(u8 loc_u8ActualPort,u8 loc_u8ActualPin){
	pu8 DDRx = (pu8)(DDRA - (loc_u8ActualPort * STEP_OF_REG));
	return (*DDRx & (1<<loc_u8ActualPin)) ;
}



//FUNCTION TO SET PIN [ HIGH , LOW ]
static void Execute_SetPin(pu8 loc_u8ActualREGPort,u8 loc_u8ActualPin,u8 status){
	if(status == HIGH){
		*(loc_u8ActualREGPort) |= (1<<loc_u8ActualPin);
	}
	else{
		*(loc_u8ActualREGPort) &= (~(1<<loc_u8ActualPin));
	}
}



//FUNCTION TO TOGGLE PIN
static void Execute_TogglePin(pu8 loc_u8ActualREGPort ,u8 loc_u8ActualPin){
	TOGGLE_BIT(*loc_u8ActualREGPort,loc_u8ActualPin);
}



//FUNCTION TO GET ADDRESS OF PORTX REG
static pu8 Get_PORT_REG(u8 loc_u8ActualPort){
	return (pu8)(PORTA - (loc_u8ActualPort * STEP_OF_REG));
}



//FUNCTION TO GET ADDRESS OF PINX REGISTER
static pu8 Get_PIN_REG(u8 loc_u8ActualPort){
	return (pu8)(PINA - (loc_u8ActualPort * STEP_OF_REG));
}



//FUNCTION TO GET VALUE IN PINX REGISTER
static u8 Read_value(pu8 loc_u8ActualREGPin ,u8 loc_u8ActualPin ){
	return GET_BIT(*loc_u8ActualREGPin,loc_u8ActualPin) ;
}




/*
 ***************************************************************
 *Purpose    :SET DIRECTION OF ALL PIN USING (DIO_cfg.h)
 *Parameter  :void
 *ReturnType :void
 ***************************************************************
 */
void DIO_Set_Dir(void){
	*DDRA = SET_DIR_(PORTA7,PORTA6,PORTA5,PORTA4,PORTA3,PORTA2,PORTA1,PORTA0);
	*DDRB = SET_DIR_(PORTB7,PORTB6,PORTB5,PORTB4,PORTB3,PORTB2,PORTB1,PORTB0);
	*DDRC = SET_DIR_(PORTC7,PORTC6,PORTC5,PORTC4,PORTC3,PORTC2,PORTC1,PORTC0);
	*DDRD = SET_DIR_(PORTD7,PORTD6,PORTD5,PORTD4,PORTD3,PORTD2,PORTD1,PORTD0);
}



/*
 ******************************************************************
 *Purpose    :SET PIN HIGH USING PIN_NUMBER(output -> high)
 *Parameter  :PinNumber [0 ~ 31]
 *ReturnType :ERROR_STATUS
 ******************************************************************
 */
DIO_ERROR_STATUS DIO_vSetPinHigh(u8 loc_u8PinNumber){

	//GET ACTUAL PORT
	u8 loc_u8ActualPort = Decode_port(loc_u8PinNumber);
	//GET ACTUAL PIN
	u8 loc_u8ActualPin  = Decode_pin(loc_u8PinNumber);


	if(loc_u8ActualPort > 3){
		return DIO_INV_PORT;
	}
	else if(loc_u8ActualPin > 7){
		return DIO_INV_PIN;
	}
	else if(!(get_pin_dir(loc_u8ActualPort ,loc_u8ActualPin))){

		//GET PORTX
		pu8 loc_u8ActualREGPort = Get_PORT_REG(loc_u8ActualPort);
		//SET PIN
		Execute_SetPin(loc_u8ActualREGPort ,loc_u8ActualPin ,HIGH);
		//USE INPUT PIN
		return DIO_INV_DIR;

	}
	else{

		//GET PORTX
		pu8 loc_u8ActualREGPort = Get_PORT_REG(loc_u8ActualPort);
		//SET PIN
		Execute_SetPin(loc_u8ActualREGPort ,loc_u8ActualPin ,HIGH);
		return DIO_OK;

	}

}




/*
 *********************************************************************
 *Purpose    :SET PIN LOW (output -> low)
 *Parameter  :PinNumber [0 ~ 31]
 *ReturnType :ERROR_STATUS
 *********************************************************************
 */
DIO_ERROR_STATUS DIO_vSetPinLOW (u8 loc_u8PinNumber){

	//GET ACTUAL PORT
	u8 loc_u8ActualPort = Decode_port(loc_u8PinNumber);
	//GET ACTUAL PIN
	u8 loc_u8ActualPin  = Decode_pin(loc_u8PinNumber);

	if(loc_u8ActualPort > 3){
		return DIO_INV_PORT;

	}
	else if(loc_u8ActualPin > 7){
		return DIO_INV_PIN;

	}
	else if(!(get_pin_dir(loc_u8ActualPort ,loc_u8ActualPin))){

		//GET PORTX
		pu8 loc_u8ActualREGPort = Get_PORT_REG(loc_u8ActualPort);
		//CLEAR PIN
		Execute_SetPin(loc_u8ActualREGPort ,loc_u8ActualPin ,LOW);
		//ERROR FOR DETECT USE INPUT PIN
		return DIO_INV_DIR;

	}
	else{

		//GET PORTX
		pu8 loc_u8ActualREGPort = Get_PORT_REG(loc_u8ActualPort);
		//CLEAR PIN
		Execute_SetPin(loc_u8ActualREGPort ,loc_u8ActualPin ,LOW);
		return DIO_OK;

	}

}





/*
 *******************************************************************
 *Purpose    :GET VALUE OF PIN
 *Parameter  :PinNumber [0 ~ 31] AND POINTER TO THE VALUE
 *ReturnType :ERROR_STATUS
 *******************************************************************
 */
u8 DIO_u8GetPin (u8 loc_u8PinNumber){

	//GET ACTUAL PORT
	u8 loc_u8ActualPort = Decode_port(loc_u8PinNumber);
	//GET ACTUAL PIN
	u8 loc_u8ActualPin  = Decode_pin(loc_u8PinNumber);
	//GET PINX ADDRESS
	pu8 loc_u8ActualREGPin = Get_PIN_REG(loc_u8ActualPort);

	return Read_value(loc_u8ActualREGPin ,loc_u8ActualPin );
}




/**********************************************************
 *
 *Purpose    :Set VALUE On Port
 *Parameter  :PortNumber AND VALUE
 *ReturnType :ERROR_STATUS
 *
 **********************************************************
 */
DIO_ERROR_STATUS DIO_u8SetPort(u8 loc_u8PortNumber,u8 loc_u8Value){

	if(loc_u8PortNumber > 3){
		return DIO_INV_PORT;
	}
	else{
		pu8 port;
		//GET THE ADDRESS OF PORT X REG
		port = Get_PORT_REG(loc_u8PortNumber);
		*port = loc_u8Value;

		return DIO_OK;
	}

}




/**********************************************************
 *
 *Purpose    :Toggle VALUE Of Pin
 *Parameter  :Pin Number
 *ReturnType :ERROR_STATUS
 *
 **********************************************************
 */
DIO_ERROR_STATUS DIO_u8SetToggle(u8 loc_u8PinNumber){

	//GET ACTUAL PORT
	u8 loc_u8ActualPort = Decode_port(loc_u8PinNumber);
	//GET ACTUAL PIN
	u8 loc_u8ActualPin  = Decode_pin(loc_u8PinNumber);

	if(loc_u8ActualPort > 3){
		return DIO_INV_PORT;

	}
	else if(loc_u8ActualPin > 7){
		return DIO_INV_PIN;

	}
	else if(!(get_pin_dir(loc_u8ActualPort ,loc_u8ActualPin))){

		//GET PORTX ADDRESS
		pu8 loc_u8ActualREGPort = Get_PORT_REG(loc_u8ActualPort);
		//TOGGLE PIN
		Execute_TogglePin(loc_u8ActualREGPort ,loc_u8ActualPin);
		//ERROR FOR DETECT USE INPUT PIN
		return DIO_INV_DIR;

	}
	else{

		//GET PORTX ADDRESS
		pu8 loc_u8ActualREGPort = Get_PORT_REG(loc_u8ActualPort);
		//TOGGLE PIN
		Execute_TogglePin(loc_u8ActualREGPort ,loc_u8ActualPin);
		return DIO_OK;

	}

}

