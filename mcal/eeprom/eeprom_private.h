#ifndef EEPROM_PRIVATE_H
#define EEPROM_PRIVATE_H
#include "../../lib/STD_TYPES.h"

#define EEARL (*((volatile u8*)0x21))
#define EEARH (*((volatile u8*)0x22))
#define EEDR  (*((volatile u8*)0x20))
#define EECR  (*((volatile u8*)0x1C))

#define EEMWE 2
#define EEWE  1
#define EERE  0

#endif
