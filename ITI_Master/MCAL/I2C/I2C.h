#ifndef I2C_H
#define I2C_H

void TWI_voidMasterInit       (void);
void TWI_voidSlaveInit        (u8 Copy_u8Address);
void TWI_voidStartCondition   (void);
void TWI_voidStopCondition    (void);
void TWI_voidSlaveAddressWrite(u8 Copy_u8SlaveAddress);
void TWI_voidSlaveAddressRead (u8 Copy_u8SlaveAddress);
void TWI_voidMasterSendData   (u8 Copy_u8Data);
u8   TWI_u8MasterReceiveData  (void);
u8   TWI_u8SlaveReceiveData   (void);

#endif
