#ifndef EEPROM_H
#define EEPROM_H

#define A2 0

void EEPROM_voidWriteDataByte(u16 Copy_u16ByteAddress,u8 Copy_u8Data);

u8 EEPROM_u8ReadDataByte(u16 Copy_u16ByteAddress);

#endif
