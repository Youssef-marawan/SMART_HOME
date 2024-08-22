/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName  : eeprom.c
 *
 */
#include<util/delay.h>


#include "../../MCAL/I2C/TWI.h"
#include "eeprom.h"



void EEPROM_Send_Data(u8 data,u16 address){

	u8 local_address = (0b10100 << 2) | (address >> 8) ;

	TWI_Start_Condition();
	TWI_Master_Send_SlvAddress_W(local_address);
	TWI_Master_Send_Data(address);
	TWI_Master_Send_Data(data);
	TWI_Stop_Condition();
	_delay_ms(10);
}

void EEPROM_Read_Data(u16 address,u8 arr[],u8 size){

	u8 local_address = (0b10100 << 2) | (address >> 8) ;
	u8 local_data;


	TWI_Start_Condition();
	TWI_Master_Send_SlvAddress_W(local_address);
	TWI_Master_Send_Data(address);
	TWI_Repeated_Start_Condition();
	TWI_Master_Send_SlvAddress_R(local_address);
	for(int i=0;i<size;i++){

	TWI_Master_Receive(&local_data);
	arr[i]=local_data;

	}

	arr[size]='\0';

	//TWI_Stop_Condition();



}

