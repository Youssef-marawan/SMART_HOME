/*
 * Author	 : YOUSSEF MARAWAN
 * FileName   : ADC.h
 *
 */

#ifndef ADC_H_
#define ADC_H_
#include "../../LIB/STD_DataType.h"

//ADC CHAIN COVERSION (WHEN USING MORE TAN ONE SENSOR)
//WITH ASYNCH
typedef struct ADC_STRUCT{
	u8		size;
	void (*ADC_CB_FUNC_Chain)(void);
	u16		result[4];

}ADC_STRUCT;


void ADC_Init	  	   		  ();
//Synch ( pooling )
void  ADC_Get_Value		 	  ( u8 ADC_Channel, pu16 ADC_Copy_Res );
//Aynch ( INT )
void   ADC_StartConv_INT	  ( u8 ADC_Channel , pu16 ADC_Copy_Res , void(*CallBack_Func)(void) );
//ADC CHAIN COVERSION
void   ADC_StartChainAsynch     ( ADC_STRUCT *Copy_Chain);




#endif /* ADC_H_ */
