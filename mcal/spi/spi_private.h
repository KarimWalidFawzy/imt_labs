#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H
#include "../../lib/STD_TYPES.h"

#define SPI_DDR   (*((volatile u8*)0x37))
#define SPI_PORT  (*((volatile u8*)0x38))

#define SPCR      (*((volatile u8*)0x2D))
#define SPSR      (*((volatile u8*)0x2E))
#define SPDR      (*((volatile u8*)0x2F))

#define SPIE      7
#define SPE       6
#define DORD      5
#define MSTR      4
#define CPOL      3
#define CPHA      2
#define SPR1      1
#define SPR0      0
#define SPIF      7
#define SPI2X     0

#define SS        2
#define MOSI      3
#define MISO      4
#define SCK       5

#endif
