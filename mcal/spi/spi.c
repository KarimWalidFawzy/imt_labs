#include "spi_interface.h"
#include "../../lib/BIT_MATH.h"

void SPI_Init(void)
{
    if (SPI_ROLE == SPI_MASTER)
    {
        SET_BIT(SPI_DDR, MOSI);
        SET_BIT(SPI_DDR, SCK);
        SET_BIT(SPI_DDR, SS);
        CLR_BIT(SPI_DDR, MISO);
        SET_BIT(SPI_PORT, SS);
        SET_BIT(SPCR, MSTR);
    }
    else
    {
        CLR_BIT(SPI_DDR, MOSI);
        CLR_BIT(SPI_DDR, SCK);
        CLR_BIT(SPI_DDR, SS);
        SET_BIT(SPI_DDR, MISO);
    }

    if (SPI_DATA_ORDER == SPI_LSB_FIRST) SET_BIT(SPCR, DORD);
    else CLR_BIT(SPCR, DORD);

    if (SPI_POLARITY == SPI_FALLING_EDGE) SET_BIT(SPCR, CPOL);
    else CLR_BIT(SPCR, CPOL);

    if (SPI_PHASE == SPI_SAMPLE_TRAILING_EDGE) SET_BIT(SPCR, CPHA);
    else CLR_BIT(SPCR, CPHA);

    switch (SPI_CLOCK_DIV)
    {
        case SPI_CLK_DIV_4:
            CLR_BIT(SPCR, SPR0);
            CLR_BIT(SPCR, SPR1);
            CLR_BIT(SPSR, SPI2X);
            break;
        case SPI_CLK_DIV_16:
            SET_BIT(SPCR, SPR0);
            CLR_BIT(SPCR, SPR1);
            CLR_BIT(SPSR, SPI2X);
            break;
        case SPI_CLK_DIV_64:
            CLR_BIT(SPCR, SPR0);
            SET_BIT(SPCR, SPR1);
            CLR_BIT(SPSR, SPI2X);
            break;
        case SPI_CLK_DIV_128:
            SET_BIT(SPCR, SPR0);
            SET_BIT(SPCR, SPR1);
            CLR_BIT(SPSR, SPI2X);
            break;
        case SPI_CLK_DIV_2:
            CLR_BIT(SPCR, SPR0);
            CLR_BIT(SPCR, SPR1);
            SET_BIT(SPSR, SPI2X);
            break;
        case SPI_CLK_DIV_8:
            SET_BIT(SPCR, SPR0);
            CLR_BIT(SPCR, SPR1);
            SET_BIT(SPSR, SPI2X);
            break;
        case SPI_CLK_DIV_32:
            CLR_BIT(SPCR, SPR0);
            SET_BIT(SPCR, SPR1);
            SET_BIT(SPSR, SPI2X);
            break;
        default:
            SET_BIT(SPCR, SPR0);
            CLR_BIT(SPCR, SPR1);
            CLR_BIT(SPSR, SPI2X);
            break;
    }

    SET_BIT(SPCR, SPE);
}

u8 SPI_Transceive(u8 data)
{
    SPDR = data;
    while (!GET_BIT(SPSR, SPIF));
    return SPDR;
}

void SPI_Send(u8 data)
{
    SPI_Transceive(data);
}

u8 SPI_Receive(void)
{
    return SPI_Transceive(0xFF);
}
