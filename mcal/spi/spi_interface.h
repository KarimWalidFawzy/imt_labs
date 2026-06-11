#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
#include "spi_private.h"
#include "spi_config.h"

void SPI_Init(void);
u8 SPI_Transceive(u8 data);
void SPI_Send(u8 data);
u8 SPI_Receive(void);

#endif
