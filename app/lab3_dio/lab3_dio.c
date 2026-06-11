#include "../../mcal/dio/dio_interface.h"
#include <util/delay.h>

int main(void)
{
    PortPinDir(DIO_PORTA, OUTPUT, PIN0);

    while (1)
    {
        PortSetPin(DIO_PORTA, HIGH, PIN0);
        _delay_ms(1000);
        PortSetPin(DIO_PORTA, LOW, PIN0);
        _delay_ms(1000);
    }

    return 0;
}
