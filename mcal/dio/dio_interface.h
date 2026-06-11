#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
#include "dio_private.h"
#include "dio_config.h"
#define DIO_PORTA       0
#define DIO_PORTB       1
#define DIO_PORTC       2
#define DIO_PORTD       3

#define PIN0            0
#define PIN1            1
#define PIN2            2
#define PIN3            3
#define PIN4            4
#define PIN5            5
#define PIN6            6
#define PIN7            7

#define OUTPUT          1
#define INPUT           0

#define HIGH            1
#define LOW             0

void PortPinDir(u8 PortName, u8 direction, u8 pin);
void PortSetPin(u8 PortName, u8 state, u8 pin);
u8 PortGetPin(u8 PortName, u8 pin);
#endif 