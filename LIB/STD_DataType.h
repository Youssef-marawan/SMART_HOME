/*
 * FileName : std_datatype.h
 * Author   : youssef marawan
 *
 */

#ifndef STD_DATATYPE_H_
#define STD_DATATYPE_H_

typedef unsigned char 				u8;
typedef signed char 				s8;
typedef char* 						pu8;

typedef unsigned int 				u16;
typedef signed int 					s16;
typedef int* 						pu16;

typedef unsigned long	      		u32;
typedef signed long     	    	s32;
typedef signed long*        	    ps32;

typedef signed long long int 		s64 ;
typedef unsigned long long int 		u64 ;
typedef long long*					pu64;

typedef float 						f32 ;
typedef double 						d64 ;


#define NULL 						0


typedef enum {
	KEY_PAD_GET_KEY,
	KEY_PAD_NO_KEY,
	BUTTON_PUSHED,
	BUTTON_STABLE
}ERROR_STATUS;
#endif /* STD_DATATYPE_H_ */
