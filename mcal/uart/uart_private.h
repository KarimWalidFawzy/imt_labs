#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H
#include "essential_drivers/STD_TYPES.h"

#define UDR     (*((volatile u8*)0x2C))
#define UCSRA   (*((volatile u8*)0x2B))
#define UCSRB   (*((volatile u8*)0x2A))
#define UCSRC   (*((volatile u8*)0x40))
#define UBRRL   (*((volatile u8*)0x29))
#define UBRRH   (*((volatile u8*)0x40))

#define RXC     7
#define TXC     6
#define UDRE    5
#define U2X     1
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define UCSZ1   2
#define UCSZ0   1
#define URSEL   7
#define USBS    3
#define UPM1    5
#define UPM0    4

#endif
