#ifndef DIO_H
#define DIO_H

//In order not to use magic numbers

#define DIO_HIGH        1
#define DIO_LOW         0


#define DIO_OUTPUT      1     //To set PinDirection to be output without using magic numbers (0b00000001)
#define DIO_INPUT       0     //To set PinDirection to be input without using magic numbers  (0b00000000)


#define DIO_PORTA       0     
#define DIO_PORTB       1
#define DIO_PORTC       2
#define DIO_PORTD       3


#define DIO_PIN0        0
#define DIO_PIN1        1
#define DIO_PIN2        2
#define DIO_PIN3        3
#define DIO_PIN4        4
#define DIO_PIN5        5
#define DIO_PIN6        6
#define DIO_PIN7        7

//Those are our APIs or functions we're gonna use
void DIO_voidSetPinDirection (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);  //An equivalent function to register: DDRA |= (1<<PA0); requirements: 1-port, 2-pin ,3-input or output(direction)
void DIO_voidSetPinValue     (u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);      //An equivalent function to register PORTA  = 0XFF;
u8   DIO_u8GetPinValue       (u8 Copy_u8Port, u8 Copy_u8Pin);                       //An equivalent function to PIN register
void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8DirectionValue);   
void DIO_voidSetPortValue    (u8 Copy_u8Port, u8 Copy_u8Value);                     //0b11110000 to get 5V on 4 pins and 0V on the other 4 pins for example
void DIO_voidTogglePin       (u8 Copy_u8Port, u8 Copy_u8Pin);                       //To toggle pin 0->1 and vice versa


#endif
