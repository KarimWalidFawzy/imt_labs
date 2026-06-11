#include "../../mcal/dio/dio_interface.h"
#include <util/delay.h>
#include <stdint.h>

int main(void)
{
    const uint8_t segmentMap[10] = {
        0x3F, // 0
        0x06, // 1
        0x5B, // 2
        0x4F, // 3
        0x66, // 4
        0x6D, // 5
        0x7D, // 6
        0x07, // 7
        0x7F, // 8
        0x6F  // 9
    };
    uint8_t digit = 0;

    PORTB->DDR = 0x7F;
    PORTB->PORT = 0x00;

    while (1)
    {
        PORTB->PORT = segmentMap[digit];
        _delay_ms(1000);
        digit++;
        if (digit >= 10)
        {
            digit = 0;
        }
    }

    return 0;
}
