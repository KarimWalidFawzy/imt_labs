#ifndef I2C_INTERFACE_H
#define I2C_INTERFACE_H
    #include "../../lib/STD_TYPES.h"
    #include "I²C_config.h"
    #include "I²C_private.h"

/* Public API for I2C (TWI) driver */
void I2C_InitMaster(void);
void I2C_InitSlave(u8 address);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(u8 data);
u8   I2C_ReadACK(void);
u8   I2C_ReadNACK(void);
u8   I2C_GetStatus(void);
#endif 