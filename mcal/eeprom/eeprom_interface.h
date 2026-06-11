#ifndef EEPROM_INTERFACE_H
#define EEPROM_INTERFACE_H
#include "eeprom_private.h"
#include "eeprom_config.h"

void EEPROM_WriteByte(u16 address, u8 data);
u8 EEPROM_ReadByte(u16 address);

#endif
