/*
 * File_Name		:	Bit_Masking.h
 * Author			: 	youssef marawan
 */

#ifndef BIT_MASKING_H_
#define BIT_MASKING_H_

#define GET_BIT(X,Y)    	(X&(1<<Y)?1:0)
#define SET_BIT(X,Y)    	(X|=(1<<Y))
#define CLR_BIT(X,Y)  		(X&=(~(1<<Y)))
#define TOGGLE_BIT(X,Y) 	(X^=(1<<Y))

#endif /* BIT_MASKING_H_ */
