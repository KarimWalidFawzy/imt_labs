#include "../../mcal/dio/dio_interface.h"
#include "../../lib/BIT_MATH.h"
#include "../../mcal/exti/exti_interface.h"
#include <avr/interrupt.h>

static void ToggleLed0(void)
{
    TOG_BIT(PORTA->PORT, PIN0);
}

static void ToggleLed1(void)
{
    TOG_BIT(PORTA->PORT, PIN1);
}

int main(void)
{
    PortPinDir(DIO_PORTA, OUTPUT, PIN0);
    PortPinDir(DIO_PORTA, OUTPUT, PIN1);
    PortPinDir(DIO_PORTD, INPUT, PIN2);
    PortPinDir(DIO_PORTD, INPUT, PIN3);

    SET_BIT(PORTD->PORT, PIN2);
    SET_BIT(PORTD->PORT, PIN3);

    EXTI_SetCallback(EXTI_INT0, ToggleLed0);
    EXTI_SetCallback(EXTI_INT1, ToggleLed1);
    EXTI_Enable(EXTI_INT0, EXTI_ANY_CHANGE);
    EXTI_Enable(EXTI_INT1, EXTI_ANY_CHANGE);

    sei();

    while (1)
    {
        ;
    }

    return 0;
}
