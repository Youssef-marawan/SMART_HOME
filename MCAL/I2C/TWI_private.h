/*
 *
 * Author	 : YOUSSEF MARAWAN
 * FileName   : TWI_private.h
 *
 */

#ifndef MCAL_I2C_TWI_PRIVATE_H_
#define MCAL_I2C_TWI_PRIVATE_H_

#define START_ACK					0x08	/*start cond. send*/
#define REP_START_ACK				0x10	/*repeated start*/
#define SLAVE_ADD_AND_W_ACK			0x18	/*master transmit slave add and W ACK*/
#define SLAVE_ADD_AND_R_ACK			0x40	/*master transmit slave add and R ACK*/
#define MSTR_WR_BYTE_ACK			0x28	/*Master transmit data ACK*/
#define MSTR_RD_BYTE_WITH_ACK		0x50	/*Master transmit data with ACK*/
#define MSTR_RD_BYTE_WITH_NACK		0x58	/*Master transmit data with not ack*/
#define SLAVE_ADD_RCVD_R_REQ		0xA8	/*slave address is received with read request*/
#define SLAVE_ADD_RCVD_W_REQ		0x60	/*slave address is received with write request*/
#define SLAVE_DATA_RECEIVED			0x80	/*slave received data */
#define SLAVE_BYTE_TRANSMITTED		0xB8	/*slave write data */


#endif /* MCAL_I2C_TWI_PRIVATE_H_ */
