#include "../../mcal/dio/dio_interface.h"

int main(void)
{
    PortPinDir(DIO_PORTA, OUTPUT, PIN0);
    PortSetPin(DIO_PORTA, HIGH, PIN0);

    while (1)
    {
        ;
    }

    return 0;
}
