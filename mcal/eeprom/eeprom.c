#include "eeprom_interface.h"
#include "../../lib/BIT_MATH.h"

void EEPROM_WriteByte(u16 address, u8 data)
{
    while (GET_BIT(EECR, EEWE));
    EEARL = (u8)(address & 0xFF);
    EEARH = (u8)((address >> 8) & 0xFF);
    EEDR  = data;
    SET_BIT(EECR, EEMWE);
    SET_BIT(EECR, EEWE);
    while (GET_BIT(EECR, EEWE));
}

u8 EEPROM_ReadByte(u16 address)
{
    while (GET_BIT(EECR, EEWE));
    EEARL = (u8)(address & 0xFF);
    EEARH = (u8)((address >> 8) & 0xFF);
    SET_BIT(EECR, EERE);
    return EEDR;
}
