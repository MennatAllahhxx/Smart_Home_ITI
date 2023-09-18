#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include <avr/io.h>
#include "UART.h"

void UART_voidInit      (void){

	u16 Local_u16BaudRate = 51; //define a variable Baud rate and assign to 51 to UBRRH AND UBRRL
    u8 Local_u8UCSRCValue = 0b10000000;

    //Beause UCSZ0 AND 1 are found in 2 registers while UCSZ2
    //1- Set Baud Rate
    UBRRL = (u8) Local_u16BaudRate;
	UBRRH = (u8) (Local_u16BaudRate >> 8);

	//2- Select Normal Speed or disable Double Speed
	CLR_BIT(UCSRA, U2X);

	//3- Disable Multi-Processor Mode
	CLR_BIT(UCSRA, MPCM);

	//4- Enable Receive and Transmit
	SET_BIT(UCSRB, RXEN); //UCSRB = (1<<RXEN)|(1<<TXEN);
	SET_BIT(UCSRB, TXEN);

	//5- Select 8 bit data
	CLR_BIT(UCSRB, UCSZ2); //UCSRC = (1<<URSEL)|(1<<USBS)|(3<<UCSZ0);
	SET_BIT(Local_u8UCSRCValue, UCSZ1);
	SET_BIT(Local_u8UCSRCValue, UCSZ0);

	//6- Select Asynchronous Mode
	 CLR_BIT(Local_u8UCSRCValue, UMSEL);

	//7- Disable Parity
	CLR_BIT(Local_u8UCSRCValue, UPM0);
	CLR_BIT(Local_u8UCSRCValue, UPM1);

	//8- Set 2 Stop Bits
	SET_BIT(Local_u8UCSRCValue, USBS);

	//9- Disable Clock Polarity
    CLR_BIT(Local_u8UCSRCValue ,UCPOL);

    //10- Assign Local_u8UCSRCValue to UCSRC
    UCSRC = Local_u8UCSRCValue;
}

void UART_voidSendData  (u8 Copy_u8Data){

	/* Wait for empty transmit buffer */
	while ( GET_BIT(UCSRA, UDRE) == 0 );  //Waiting for the flag to be =1

	/* Put data into buffer, sends the data */
	UDR = Copy_u8Data;
}

u8   UART_u8ReceiveData (void){

	/* Wait for data to be received */
	while ( GET_BIT(UCSRA, RXC) == 0 );

	/* Get and return received data from buffer */
	return UDR;
}
