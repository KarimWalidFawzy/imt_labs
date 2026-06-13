/*
Simple SPI demo: transmit a byte continuously (master) or echo received byte (slave).
Master/Slave mode controlled by SPI_ROLE in mcal/spi/spi_config.h
MOSI/MISO/SCK are hardware pins; user must wire two boards for full test.
*/

#include "../../mcal/spi/spi_interface.h"
#include "../../mcal/dio/dio_interface.h"
#include <util/delay.h>

int main(void)
{
	SPI_Init();

	if (SPI_ROLE == SPI_MASTER)
	{
		u8 counter = 0;
		while (1)
		{
			SPI_Send(counter);
			counter++;
			_delay_ms(500);
		}
	}
	else
	{
		while (1)
		{
			u8 received = SPI_Receive();
			/* Optionally toggle an LED upon reception */
			(void)received;
		}
	}

	return 0;
}