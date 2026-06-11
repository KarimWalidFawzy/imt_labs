#include "../../lib/STD_TYPES.h"
#include "I²C_interface.h"
void I2C_InitMaster(void)
{
    TWSR = 0; /* no prescaler */
    TWBR = 32; /* bit rate register — adjust for desired SCL */
    TWCR = (1 << TWEN);
}

void I2C_InitSlave(u8 address)
{
    TWAR = (address << 1); /* set own address (7-bit) */
    TWCR = (1 << TWEN);
}

void I2C_Start(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

void I2C_Stop(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void I2C_Write(u8 data)
{
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

u8 I2C_ReadACK(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

u8 I2C_ReadNACK(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

u8 I2C_GetStatus(void)
{
    return (TWSR & 0xF8); /* mask status bits (top 5 bits) */
}
