/*
 * INT.c
 *
 *  Created on: Aug 21, 2023
 *      Author: lenovo
 */

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h"
#include <avr/interrupt.h>
#include "INT.h"

void INT_voidEnable(u8 Copy_u8INTIndex, u8 Copy_u8INTSense){

	switch (Copy_u8INTIndex){
	    case INT_INT0:
		    switch (Copy_u8INTSense){   //Control Sense
		        case INT_FALLING_EDGE :
		        	CLR_BIT(MCUCR, ISC00);  //ISC00 is already defined in a library with value 0 as a macro
                    SET_BIT(MCUCR, ISC01);
		            break;

		        case INT_RISING_EDGE :
		        	SET_BIT(MCUCR, ISC00);  //ISC00 is already defined in a library with value 0 as a macro
                    SET_BIT(MCUCR, ISC01);
		            break;

		        case INT_ANY_CHANGE :
		        	CLR_BIT(MCUCR, ISC01);  //ISC00 is already defined in a library with value 0 as a macro
                    SET_BIT(MCUCR, ISC00);
		            break;

		        case INT_LOW_LEVEL :
		    	    CLR_BIT(MCUCR, ISC00);  //ISC00 is already defined in a library with value 0 as a macro
                    CLR_BIT(MCUCR, ISC01);
	                break;

		    }
		    /*Enable Interrupt0*/
		    SET_BIT(GICR, INT0);
		    break;

	    case INT_INT1:
	        switch (Copy_u8INTSense){ //Control Sense
	            case INT_FALLING_EDGE :
	            	CLR_BIT(MCUCR, ISC10); //ISC00 is already defined in a library with value 0 as a macro
                    SET_BIT(MCUCR, ISC11);
	                break;

	            case INT_RISING_EDGE :
	        	    SET_BIT(MCUCR, ISC10);  //ISC00 is already defined in a library with value 0 as a macro
                    SET_BIT(MCUCR, ISC11);
	                break;

	            case INT_ANY_CHANGE :
	        	    CLR_BIT(MCUCR, ISC11);  //ISC00 is already defined in a library with value 0 as a macro
                    SET_BIT(MCUCR, ISC10);
	                break;

	            case INT_LOW_LEVEL :
	    	        CLR_BIT(MCUCR, ISC10);  //ISC00 is already defined in a library with value 0 as a macro
                    CLR_BIT(MCUCR, ISC11);
                    break;

	        }
	        /*Enable Interrupt1*/
	        SET_BIT(GICR, INT1);
		    break;

	    case INT_INT2:
	        switch (Copy_u8INTSense){ //Control Sense
	            case INT_FALLING_EDGE :
	        	    CLR_BIT(MCUCSR, ISC2);  //ISC00 is already defined in a library with value 0 as a macro
	                break;

	            case INT_RISING_EDGE :
	        	    SET_BIT(MCUCSR, ISC2);  //ISC00 is already defined in a library with value 0 as a macro                SET_BIT(MCUCSR, ISC11);
	                break;

	        }
	        /*Enable Interrupt2*/
	        SET_BIT(GICR, INT2);
		    break;
	}

}



void INT_voidDisable(u8 Copy_u8INTIndex){

	switch (Copy_u8INTIndex){
	    case INT_INT0:
	    	CLR_BIT(GICR, INT0);
	    	break;
	    case INT_INT1:
	    	CLR_BIT(GICR, INT1);
	    	break;
	    case INT_INT2:
	    	CLR_BIT(GICR, INT2);
	    	break;
	}

}
