/*
 * Author	 : YOUSSEF MARAWAN
 * FileName   : TWI.h
 *
 */

#ifndef MCAL_I2C_TWI_H_
#define MCAL_I2C_TWI_H_

#include "../../LIB/STD_DataType.h"

/*Error Status for TWI*/
typedef enum
{
	NO_ERROR,
	START_CONDITIONS_ERROR,
	REPEATESTED_START_CONDITIONS_ERROR,
	SLAVE_ADDRESS_W_ERROR,
	SLAVE_ADDRESS_R_ERROR,
	MASTER_W_BYTE_ERROR,
	MASTER_R_BYTE_ERROR,
	SLAVE_W_BYTE_ERROR,
	SLAVE_R_BYTE_ERROR,
	TWI_NULL_PTR,
}TWI_ErrorStatus;


void			TWI_Master_Init(u8 Copy_u8Address);
void			TWI_Slave_Init (u8 Copy_u8Address);

TWI_ErrorStatus TWI_Start_Condition();
TWI_ErrorStatus TWI_Repeated_Start_Condition();
void			TWI_Stop_Condition();

TWI_ErrorStatus TWI_Master_Send_Data(u8 Copy_u8Value);
TWI_ErrorStatus TWI_Master_Receive(pu8 add_u8Value);

TWI_ErrorStatus TWI_Slave_Send_Data(u8 Copy_u8Value);
TWI_ErrorStatus TWI_Slave_Receive(pu8 add_u8Value);

TWI_ErrorStatus TWI_Master_Send_SlvAddress_W(u8 Copy_u8Value);
TWI_ErrorStatus TWI_Master_Send_SlvAddress_R(u8 Copy_u8Value);

void 			TWI_STOP();




#endif /* MCAL_I2C_TWI_H_ */
