
#include <avr/io.h>
#include "../../LIB/STD_Types.h"    //Order of include here is important and has a meaning (u8 here is defined in STD_Types before DIO.h)
#include "../../LIB/BIT_Math.h"
#include "DIO.h"

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction){ //DDRA,B,C,D
	if( Copy_u8Pin <8){    	//If user enters a pin number greater than 7 (Range 0 --->7) and assume user won't enter a negative number
		
	    if(Copy_u8Direction == DIO_OUTPUT){
			switch(Copy_u8Port)
			{
				case DIO_PORTA :    SET_BIT(DDRA, Copy_u8Pin); break;
				case DIO_PORTB :    SET_BIT(DDRB, Copy_u8Pin); break;
				case DIO_PORTC :    SET_BIT(DDRC, Copy_u8Pin); break;
				case DIO_PORTD :    SET_BIT(DDRD, Copy_u8Pin); break;
				default        :    /* Do Nothing */           break;
			}
			
		}
		else if(Copy_u8Direction == DIO_INPUT){
			switch(Copy_u8Port)
			{
				case DIO_PORTA :    CLR_BIT(DDRA, Copy_u8Pin); break;
				case DIO_PORTB :    CLR_BIT(DDRB, Copy_u8Pin); break;
				case DIO_PORTC :    CLR_BIT(DDRC, Copy_u8Pin); break;
				case DIO_PORTD :    CLR_BIT(DDRD, Copy_u8Pin); break;
				default        :    /* Do Nothing */           break;
			}
		}
		else{
			/*Do Nothing*/
		}
		
	}
	else{
		/* Do Nothing */
	}


}


void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
	if( Copy_u8Pin <8){    	
		
	    if(Copy_u8Value == DIO_HIGH){
			switch(Copy_u8Port)
			{
				case DIO_PORTA :    SET_BIT(PORTA, Copy_u8Pin); break;
				case DIO_PORTB :    SET_BIT(PORTB, Copy_u8Pin); break;
				case DIO_PORTC :    SET_BIT(PORTC, Copy_u8Pin); break;
				case DIO_PORTD :    SET_BIT(PORTD, Copy_u8Pin); break;
				default        :    /* Do Nothing */            break;
			}
			
		}
		else if(Copy_u8Value == DIO_LOW){
			switch(Copy_u8Port)
			{
				case DIO_PORTA :    CLR_BIT(PORTA, Copy_u8Pin); break;
				case DIO_PORTB :    CLR_BIT(PORTB, Copy_u8Pin); break;
				case DIO_PORTC :    CLR_BIT(PORTC, Copy_u8Pin); break;
				case DIO_PORTD :    CLR_BIT(PORTD, Copy_u8Pin); break;
				default        :    /* Do Nothing */            break;
			}
		}
		else{
			/*Do Nothing*/
		}	
	}
	else{
		/* Do Nothing */	
    }
}	
      
u8   DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin){  //PINA,B,C,D
		if( Copy_u8Pin <8){    	
			switch(Copy_u8Port)
			{
				case DIO_PORTA :    return GET_BIT(PINA, Copy_u8Pin);   //No need for break here because once a value is returned, it's done. 
				case DIO_PORTB :    return GET_BIT(PINB, Copy_u8Pin); 
				case DIO_PORTC :    return GET_BIT(PINC, Copy_u8Pin);
				case DIO_PORTD :    return GET_BIT(PIND, Copy_u8Pin); 
				default        :    return 0xff;                        //we don't use Do nothing comment here because some compilers will return wrong value  (as a wrong entry)        
			}			
	}
	else{
		return 0xff;
    }
			
}


void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8DirectionValue){
	switch (Copy_u8Port)        //To make PORTA all output: DDRA = 0b11111111;
	{
		case DIO_PORTA :    DDRA = Copy_u8DirectionValue; break;
		case DIO_PORTB :    DDRB = Copy_u8DirectionValue; break;
		case DIO_PORTC :    DDRC = Copy_u8DirectionValue; break;
		case DIO_PORTD :    DDRD = Copy_u8DirectionValue; break;
		default        :    /* Do Nothing */              break;     
	}
		
} 

 
void DIO_voidSetPortValue    (u8 Copy_u8Port, u8 Copy_u8Value){
	switch (Copy_u8Port)
	{
		case DIO_PORTA :    PORTA = Copy_u8Value; break;
		case DIO_PORTB :    PORTB = Copy_u8Value; break;
		case DIO_PORTC :    PORTC = Copy_u8Value; break;
		case DIO_PORTD :    PORTD = Copy_u8Value; break;
		default        :    /* Do Nothing */      break;
	}
	
}


void DIO_voidTogglePin       (u8 Copy_u8Port, u8 Copy_u8Pin){
	if( Copy_u8Pin <8){
		switch (Copy_u8Port)
	    {
		case DIO_PORTA :    TGL_BIT(PINA, Copy_u8Pin); break;
		case DIO_PORTB :    TGL_BIT(PINB, Copy_u8Pin); break;
		case DIO_PORTC :    TGL_BIT(PINC, Copy_u8Pin); break;
		case DIO_PORTD :    TGL_BIT(PIND, Copy_u8Pin); break;
		default        :    /* Do Nothing */           break;
	    }
	}
	else {
		/* Do Nothing */
	}

}  
