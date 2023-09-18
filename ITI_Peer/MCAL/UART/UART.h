#ifndef UART_H
#define UART_H

void UART_voidInit      (void);
void UART_voidSendData  (u8 Copy_u8Data); //Since we will use 8 bits not 9 bits, therefore u8
u8   UART_u8ReceiveData (void);

#endif
