/*
 * Author	 : YOUSSEF MARAWAN
 * FileName   : TWI.c
 *
 */
#include "TWI.h"
#include "TWI_private.h"
#include "TWI_reg.h"

#include "../../LIB/STD_DataType.h"
#include "../../LIB/Bit_Masking.h"

#define TWSR_MASK 0b11111000

void TWI_Master_Init(u8 Copy_u8Address){
	//set SCL
	//TWPS in TWSR PRSCALER = 1
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);

	//TWBR
	TWBR = 12;

	//set TWI Enable Acknowledge
	SET_BIT(TWCR , TWEA);

	//set TWI Interrupt Enable
	//SET_BIT(TWCR , TWIE);

	//set address of the master
	if (Copy_u8Address != 0){
		TWAR = (Copy_u8Address<<1u);
	}

	//set TWI Enable
	SET_BIT(TWCR , TWEN);
}


void TWI_Slave_Init(u8 Copy_u8Address){
	//set TWI Enable Acknowledge
	SET_BIT(TWCR , TWEA);

	//set TWI Interrupt Enable
	SET_BIT(TWCR , TWIE);

	//set address of the master
	if (Copy_u8Address != 0){
		TWAR = (Copy_u8Address<<1u);
	}

	//set TWI Enable
	SET_BIT(TWCR , TWEN);
}


TWI_ErrorStatus TWI_Start_Condition(){

	TWI_ErrorStatus local_Error = NO_ERROR;

	//set bit of start condition
	SET_BIT(TWCR , TWSTA);

	//clear the flag because it rise from the previous operation
	SET_BIT(TWCR , TWINT);

	//waiting until flag rise
	while( GET_BIT( TWCR , TWINT ) == 0);

	//check the status
	//get only 5 bits from and make the prescaler bits zeros
	if((TWSR & TWSR_MASK) != START_ACK){
		local_Error = START_CONDITIONS_ERROR;
	}

	return local_Error;

}


TWI_ErrorStatus TWI_Repeated_Start_Condition(){

	TWI_ErrorStatus local_Error = NO_ERROR;

	//set bit of start condition
	SET_BIT(TWCR , TWSTA);

	//clear the flag because it rise from the previous operation
	SET_BIT(TWCR , TWINT);

	//waiting until flag rise
	while( GET_BIT( TWCR , TWINT ) == 0);

	//check the status
	//get only 5 bits from and make the prescaler bits zeros
	if((TWSR & TWSR_MASK) != REP_START_ACK){
		local_Error = REPEATESTED_START_CONDITIONS_ERROR;
	}

	return local_Error;

}


void TWI_Stop_Condition(){

	//set stop condition bit
	SET_BIT( TWCR , TWSTO );

	//clear the flag to start next operation
	SET_BIT( TWCR , TWINT );

}


TWI_ErrorStatus TWI_Master_Send_SlvAddress_W(u8 Copy_u8Address){

	TWI_ErrorStatus local_Error = NO_ERROR;

	//write the address in the 7 bits from MSB and the 0 bit equal zero because we want to write
	TWDR = (Copy_u8Address << 1u);

	//clear bit of start condition
	CLR_BIT(TWCR , TWSTA);

	//clear the flag because it rise from the previous operation
	SET_BIT(TWCR , TWINT);

	//waiting until flag rise
	while( GET_BIT( TWCR , TWINT ) == 0);

	//check the status
	//get only 5 bits from and make the prescaler bits zeros
	if((TWSR & TWSR_MASK) != SLAVE_ADD_AND_W_ACK){
		local_Error = SLAVE_ADDRESS_W_ERROR;
	}

	return local_Error;

}


TWI_ErrorStatus TWI_Master_Send_SlvAddress_R(u8 Copy_u8Address){

	TWI_ErrorStatus local_Error = NO_ERROR;

	//write the address in the 7 bits from MSB and the 0 bit equal 1 because we want to READ
	TWDR = (Copy_u8Address << 1u)|(1);

	//clear bit of start condition
	CLR_BIT(TWCR , TWSTA);

	//clear the flag because it rise from the previous operation
	SET_BIT(TWCR , TWINT);

	//waiting until flag rise
	while( GET_BIT( TWCR , TWINT ) == 0);

	//check the status
	//get only 5 bits from and make the prescaler bits zeros
	if((TWSR & TWSR_MASK) != SLAVE_ADD_AND_R_ACK){
		local_Error = SLAVE_ADDRESS_R_ERROR;
	}

	return local_Error;


}


TWI_ErrorStatus TWI_Master_Send_Data(u8 Copy_u8Value){

	TWI_ErrorStatus local_Error = NO_ERROR;

	//write data in TWDR reg
	TWDR = Copy_u8Value;
	//clear the flag because it rise from the previous operation
	SET_BIT(TWCR , TWINT);

	//waiting until flag rise
	while( GET_BIT( TWCR , TWINT ) == 0);

	//check the status
	//get only 5 bits from and make the prescaler bits zeros
	if((TWSR & TWSR_MASK) != MSTR_WR_BYTE_ACK){
		local_Error = MASTER_W_BYTE_ERROR;
	}

	return local_Error;


}


TWI_ErrorStatus TWI_Master_Receive(pu8 add_pu8Value){

	TWI_ErrorStatus local_Error = NO_ERROR;

	if(add_pu8Value != NULL){

		//clear the flag to allow the slave to put data on bus
		SET_BIT( TWCR , TWINT );

		//waiting until flag rise
		while( GET_BIT( TWCR , TWINT ) == 0);

		//check the status
		//get only 5 bits from and make the prescaler bits zeros
		if((TWSR & TWSR_MASK) != MSTR_RD_BYTE_WITH_ACK){
			local_Error = MASTER_R_BYTE_ERROR;
		}
		else{
			*add_pu8Value = TWDR;
		}

	}
	else{
		local_Error = TWI_NULL_PTR;
	}

	return local_Error;
}




TWI_ErrorStatus TWI_Slave_Send_Data(u8 Copy_u8Value){

	TWI_ErrorStatus local_Error = NO_ERROR;

	TWDR = Copy_u8Value;

	//clear the flag to allow the slave to put data on bus
	SET_BIT( TWCR , TWINT );

	//waiting until flag rise
	while( GET_BIT( TWCR , TWINT ) == 0);

	//check the status
	//get only 5 bits from and make the prescaler bits zeros
	if((TWSR & TWSR_MASK) != SLAVE_BYTE_TRANSMITTED){
		local_Error = SLAVE_W_BYTE_ERROR;
	}


	return local_Error;
}



TWI_ErrorStatus TWI_Slave_Receive(pu8 add_u8Value){

	TWI_ErrorStatus local_Error = NO_ERROR;

	//clear the flag to allow the master to put data on bus
	SET_BIT( TWCR , TWINT );

	//waiting until flag rise
	while( GET_BIT( TWCR , TWINT ) == 0);

	//check the status
	//get only 5 bits from and make the prescaler bits zeros
	if((TWSR & TWSR_MASK) != SLAVE_DATA_RECEIVED){
		local_Error = SLAVE_R_BYTE_ERROR;
	}
	else{
		*add_u8Value = TWDR;
	}

	return local_Error;

}



void 			TWI_STOP(){

	CLR_BIT(TWCR , TWIE);
	//set TWI Enable
	CLR_BIT(TWCR , TWEN);
}
