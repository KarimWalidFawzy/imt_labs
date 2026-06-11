#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H
#include "uart_private.h"
#include "uart_config.h"

void UART_Init(void);
void UART_SendByte(u8 data);
u8 UART_ReceiveByte(void);
void UART_SendString(const char* str);

#endif
