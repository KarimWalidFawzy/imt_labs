#include "../../mcal/dio/dio_interface.h"
#include <util/delay.h>
#include <stdint.h>

static const uint8_t segmentMap[10] = {
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

static uint8_t ScanKeypad(void)
{
    static const uint8_t keyMap[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    uint8_t row;
    uint8_t col;
    uint8_t key = 0;

    for (row = 0; row < 3; row++)
    {
        PORTD->PORT |= 0x07;
        PORTD->PORT &= ~(1 << row);

        for (col = 0; col < 3; col++)
        {
            if (PortGetPin(DIO_PORTD, PIN3 + col) == LOW)
            {
                key = keyMap[row][col];
                break;
            }
        }

        if (key != 0)
        {
            break;
        }
    }

    return key;
}

int main(void)
{
    uint8_t pressed;

    PORTD->DDR = 0x07;
    PORTD->PORT |= 0x38;
    PORTB->DDR = 0x7F;
    PORTB->PORT = 0x00;

    while (1)
    {
        pressed = ScanKeypad();
        if (pressed != 0)
        {
            PORTB->PORT = segmentMap[pressed];
        }
        else
        {
            PORTB->PORT = segmentMap[0];
        }

        _delay_ms(100);
    }

    return 0;
}
