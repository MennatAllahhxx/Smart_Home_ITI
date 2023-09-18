/*
 * ADC.c
 *
 *  Created on: Aug 22, 2023
 *      Author: lenovo
 */
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include <avr/io.h>

#define ADC_AVCC             0   //We wrote it in ADC.c not ADC.h because it's supposed to be written in private file but we don't use private files here
#define ADC_AREF             1
#define ADC_2_56_V           2

#include "ADC.h"

void ADC_voidInit(u8 Copy_u8Prescaler){

	//Enable ADC module of AVR --> (Bit 7 ADEN: Set)
	SET_BIT(ADCSRA, ADEN);    //SET_BIT(ADCSRA, 7);
	//Select conversion speed, voltage reference and Left or Right Adjust
	//Select Reference Voltage
    #if ADC_REF_VOLT == ADC_AVCC  //This is a pre-build configuration
	    SET_BIT(ADMUX, REFS0);
	    CLR_BIT(ADMUX, REFS1);
    #elif ADC_REF_VOLT == ADC_AREF
	    CLR_BIT(ADMUX, REFS0);
	    CLR_BIT(ADMUX, REFS1);
    #else
	    SET_BIT(ADMUX, REFS0);
	    SET_BIT(ADMUX, REFS1);
    #endif

    //Select Right Adjust in order to read all the 10 or 16 bits (the 2 registers)
    CLR_BIT(ADMUX, ADLAR);

    //Select Conversion Speed or Prescaler (a faster step than switch case )
    ADCSRA &= 0b11111000;   //to clear the last 3 bits (ADPS0,1,2) and make sure that these 3 bits are zeros
    ADCSRA |= Copy_u8Prescaler; //ORing to get the values of the prescaler 0|0 = 0 , 0|1 = 1 .... 0b00000110

}


u16 ADC_u16GetDigitalValue(u8 Copy_u8Channel){

	//Select Channel
	ADMUX &= 0b11100000;  //same as previous done with ADCSRA register
	ADMUX |= Copy_u8Channel;

	//Start Conversion <Step 5>
	SET_BIT(ADCSRA, ADSC);

	// wait flag = 1
	while(GET_BIT(ADCSRA, ADIF) == 0);
	// Clear the flag
	CLR_BIT(ADCSRA, ADIF);   	//It's cleared by hardware but we clear it to make sure it's cleared

	//read ADC Value

	return ADC;

}


void ADC_voidDisable(void){

	//Disale ADC
	CLR_BIT(ADCSRA, ADEN);

}

//Methods: 1-Input --> we will do it in the main.c file not in ADC.c
//Step2: TURN ON ADC Module
//for voltage reference selection ---> REFS0 and REFS1 page214Datasheet
//#if ---> grey and white colors on what's selected on header file, the grey colored part will be deleted by preprocessor and the white one will be executed
//ADCSRA is the control and status register
