/*
 * ADC.h
 *
 *  Created on: Aug 22, 2023
 *      Author: lenovo
 */

#ifndef ADC_H_
#define ADC_H_

//Configurations

#define ADC_REF_VOLT           ADC_AVCC
//ADC_AVCC     or    ADC_AREF       OR   ADC_2.56_V

//This is the pre-scaler
#define ADC_DIV_2              1
#define ADC_DIV_4              2
#define ADC_DIV_8              3
#define ADC_DIV_16             4
#define ADC_DIV_32             5
#define ADC_DIV_64             6
#define ADC_DIV_128            7

//8 Channels: Single-Ended Not Differential, Therefore starting from ADC0 to ADC7
#define ADC_Channel_0          0
#define ADC_Channel_1          1
#define ADC_Channel_2          2
#define ADC_Channel_3          3
#define ADC_Channel_4          4
#define ADC_Channel_5          5
#define ADC_Channel_6          6
#define ADC_Channel_7          7

//Our APIs
//Make sure that your channel bit is input bin even it's by default because of the differences between microcontrollers
void ADC_voidInit(u8 Copy_u8Prescaler);
u16 ADC_u16GetDigitalValue(u8 Copy_u8Channel); //Data Register from 0 to 15
void ADC_voidDisable(void);


#endif /* MCAL_ADC_ADC_H_ */
