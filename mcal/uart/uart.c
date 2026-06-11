#include "uart_interface.h"
#include "essential_drivers/BIT_MATH.h"

#define UART_UBRR_VALUE ((UART_F_CPU / (16UL * UART_BAUD_RATE)) - 1)

void UART_Init(void)
{
    UBRRL = (u8)(UART_UBRR_VALUE & 0xFF);
    UBRRH = (u8)((UART_UBRR_VALUE >> 8) & 0xFF);

    SET_BIT(UCSRB, RXEN);
    SET_BIT(UCSRB, TXEN);
    CLR_BIT(UCSRB, UCSZ2);

    UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

void UART_SendByte(u8 data)
{
    while (!GET_BIT(UCSRA, UDRE));
    UDR = data;
}

u8 UART_ReceiveByte(void)
{
    while (!GET_BIT(UCSRA, RXC));
    return UDR;
}

void UART_SendString(const char* str)
{
    while (*str)
    {
        UART_SendByte((u8)*str);
        str++;
    }
}
