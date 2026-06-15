/*
Control the LEDs on your kit by your computer ! Sending a number by the computer shall toggle the corresponding LED. i.e sending '1' toggles LED 1 , sending 2 toggles LED 2 and so on …
*/

#include "../../mcal/uart/uart_interface.h" 
#include "../../mcal/dio/dio_interface.h"
#include <util/delay.h>

int main(void)
{
	UART_Init();

	/* Use PORTA pins 0..3 as LEDs */
	PortPinDir(DIO_PORTA, OUTPUT, PIN0);
	PortPinDir(DIO_PORTA, OUTPUT, PIN1);
	PortPinDir(DIO_PORTA, OUTPUT, PIN2);
	PortPinDir(DIO_PORTA, OUTPUT, PIN3);

	while (1)
	{
		u8 b = UART_ReceiveByte();
		if (b >= '1' && b <= '4')
		{
			u8 idx = (u8)(b - '1');
			TOG_BIT(PORTA->PORT, idx);
			UART_SendByte('O');
		}
		else
		{
			UART_SendByte('N');
		}
	}

	return 0;
}