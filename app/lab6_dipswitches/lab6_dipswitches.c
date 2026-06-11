#include "../../mcal/dio/dio_interface.h"
#include "../../lib/BIT_MATH.h"
#include <util/delay.h>

int main(void)
{
    uint8_t i;

    PORTC->DDR = 0xFF;
    PORTC->PORT = 0x00;

    PortPinDir(DIO_PORTD, INPUT, PIN0);
    SET_BIT(PORTD->PORT, PIN0);

    while (1)
    {
        if (PortGetPin(DIO_PORTD, PIN0) == LOW)
        {
            for (i = 0; i < 8; ++i)
            {
                PortSetPin(DIO_PORTC, HIGH, i);
            }
            _delay_ms(500);
            for (i = 0; i < 8; ++i)
            {
                PortSetPin(DIO_PORTC, LOW, i);
            }
            _delay_ms(500);
        }
        else
        {
            PORTC->PORT = 0x00;
        }
    }

    return 0;
}
