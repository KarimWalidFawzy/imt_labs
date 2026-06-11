#include "../../mcal/dio/dio_interface.h"
#include <util/delay.h>

int main(void)
{
    const uint8_t patterns[] = {0x81, 0x42, 0x24, 0x18, 0x3C, 0x66, 0xC3, 0xFF};
    uint8_t index = 0;
    uint8_t dir = 1;

    PORTA->DDR = 0xFF;
    PORTA->PORT = 0x00;

    while (1)
    {
        PORTA->PORT = patterns[index];
        _delay_ms(250);

        if (dir)
        {
            index++;
            if (index == sizeof(patterns) / sizeof(patterns[0]))
            {
                index = sizeof(patterns) / sizeof(patterns[0]) - 1;
                dir = 0;
            }
        }
        else
        {
            if (index == 0)
            {
                dir = 1;
            }
            else
            {
                index--;
            }
        }
    }

    return 0;
}
