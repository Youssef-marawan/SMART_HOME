/*
 * Author	 : YOUSSEF MARAWAN
 * FileName   : TWI_reg.h
 *
 */

#ifndef MCAL_I2C_TWI_REG_H_
#define MCAL_I2C_TWI_REG_H_

#include "../../LIB/STD_DataType.h"

//TWI Bit Rate Register
#define TWBR (*(volatile pu8)0x20)
// TWI Control Register
#define TWCR (*(volatile pu8)0x56)
// TWI Status Register
#define TWSR (*(volatile pu8)0x21)
//TWI Data Register
#define TWDR (*(volatile pu8)0x23)
// TWI (Slave) Address Register
#define TWAR (*(volatile pu8)0x22)



//TWCR
#define TWINT		7
#define TWEA 		6
#define TWSTA		5
#define TWSTO		4
#define TWWC 		3
#define TWEN		2
#define TWIE		0


//TWSR
#define TWS7		7
#define TWS6		6
#define TWS5		5
#define TWS4		4
#define TWS3		3
#define TWPS1		1
#define TWPS0		0


//TWAR
#define TWGCE		0




#endif /* MCAL_I2C_TWI_REG_H_ */
