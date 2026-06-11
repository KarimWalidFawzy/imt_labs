#include "../../mcal/dio/dio_interface.h"
#include "../../lib/BIT_MATH.h"
#include <util/delay.h>

int main(void)
{
    PortPinDir(DIO_PORTA, OUTPUT, PIN0);
    PortPinDir(DIO_PORTD, INPUT, PIN0);
    SET_BIT(PORTD->PORT, PIN0);

    while (1)
    {
        if (PortGetPin(DIO_PORTD, PIN0) == LOW)
        {
            PortSetPin(DIO_PORTA, LOW, PIN0);
        }
        else
        {
            PortSetPin(DIO_PORTA, HIGH, PIN0);
        }
    }

    return 0;
}
