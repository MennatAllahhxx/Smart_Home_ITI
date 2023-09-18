#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include <avr/io.h>
#include "I2C.h"

void TWI_voidMasterInit       (void){

	/* 1- Set Prescaler Value ==> Prescaler = 1 or No Prescaler */
	CLR_BIT(TWSR,  TWPS0);
	CLR_BIT(TWSR,  TWPS1);

	/* 2- Set Frequency ==> 200 KHz , from equation TWBR = 12 */
	TWBR = 12;

	/* 3- Enable I2C & Acknowledge (ACK) */
	SET_BIT(TWCR,  TWEN);
	SET_BIT(TWCR,  TWEA);
}

void TWI_voidSlaveInit        (u8 Copy_u8Address){

	/* 1- Set Slave Address in Register Address */
	TWAR = (Copy_u8Address<<1);

	/* 2- Enable I2C & Acknowledge (ACK) */
	SET_BIT(TWCR,  TWEN);
	SET_BIT(TWCR,  TWEA);
}

void TWI_voidStartCondition   (void){

	/* 1- Write One to Start Condition or Bit then Clear Flag ==> by writing logic 1*/
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	/* 2- Wait for Flag */
	while(GET_BIT(TWCR, TWINT) == 0 ); //while (!(TWCR & (1<<TWINT)));
}

void TWI_voidStopCondition    (void){

	/* Enable Start or stop?? Bit and Clear Flag*/
	SET_BIT(TWCR, TWSTO); //TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
	SET_BIT(TWCR, TWINT);
}

void TWI_voidSlaveAddressWrite(u8 Copy_u8SlaveAddress){

	TWDR = Copy_u8SlaveAddress<<1;
	CLR_BIT(TWDR, 0);

	//Disable Start Bit or Condition
	CLR_BIT(TWCR, TWSTA);

	//Clear flag then loop OR wait
	SET_BIT(TWCR, TWINT);

	//Wait flag
	while(GET_BIT(TWCR, TWINT) == 0);
}


void TWI_voidSlaveAddressRead (u8 Copy_u8SlaveAddress){

	TWDR = Copy_u8SlaveAddress<<1;
	SET_BIT(TWDR, 0);

	//Disable Start Bit or Condition
	CLR_BIT(TWCR, TWSTA);

	//Clear flag then loop OR wait
	SET_BIT(TWCR, TWINT);

	//Wait flag
	while(GET_BIT(TWCR, TWINT) == 0);
}

void TWI_voidMasterSendData   (u8 Copy_u8Data){

	TWDR = Copy_u8Data;

	//Clear flag then loop OR wait
    SET_BIT(TWCR, TWINT);

	//Wait flag
	while(GET_BIT(TWCR, TWINT) == 0);
}

u8   TWI_u8MasterReceiveData  (void){
	//Clear the flag then wait for data to be sent
	//Clear flag then loop OR wait
	SET_BIT(TWCR, TWINT);

	//Wait flag
	while(GET_BIT(TWCR, TWINT) == 0);

	return TWDR;
}

u8   TWI_u8SlaveReceiveData   (void){

	while((TWSR & 0xF8) != 0x60);

	//Clear flag then loop OR wait
	SET_BIT(TWCR, TWINT);

    //Wait flag
    while(GET_BIT(TWCR, TWINT) == 0);

	return TWDR;
}
