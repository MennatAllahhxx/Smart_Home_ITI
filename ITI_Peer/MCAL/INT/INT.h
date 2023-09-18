/*
 * INT.h
 *
 *  Created on: Aug 21, 2023
 *      Author: lenovo
 */

#ifndef INT_H_
#define INT_H_

//Configurations
#define INT_INT0      0
#define INT_INT1      1
#define INT_INT2      2

//Sense
#define INT_FALLING_EDGE      0
#define INT_RISING_EDGE       1
#define INT_ANY_CHANGE        2
#define INT_LOW_LEVEL         3

//Our APIs
void INT_voidEnable(u8 Copy_u8INTIndex, u8 Copy_u8INTSense); // to access 2 registers, but the flag is not accessed because it's done directly through ISR
void INT_voidDisable(u8 Copy_u8INTIndex);


#endif /* MCA_INT_LINT_H_ */



//first GIE enable the "global interrupt enable" when dealing with interrupt
//then choose the sense whether rising or falling edge
//flag by hardware then execute interrupt and  then flag will be cleared by hardware
//IOC means any logical change
