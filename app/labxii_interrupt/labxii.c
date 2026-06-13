#include "../../mcal/dio/dio_interface.h"
#include "../../lib/BIT_MATH.h"
#include "../../mcal/exti/exti_interface.h"
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>

static volatile uint8_t animationMode = 0;

static const uint8_t patterns[2][8] = {
    {0x81, 0x42, 0x24, 0x18, 0x3C, 0x66, 0xC3, 0xFF},
    {0x18, 0x3C, 0x66, 0xC3, 0x81, 0x42, 0x24, 0x18}
};

static void ChangeAnimation(void)
{
    animationMode ^= 1;
}

int main(void)
{
    uint8_t index = 0;

    PORTA->DDR = 0xFF;
    PORTA->PORT = 0x00;

    PortPinDir(DIO_PORTD, INPUT, PIN2);
    SET_BIT(PORTD->PORT, PIN2);

    EXTI_SetCallback(EXTI_INT0, ChangeAnimation);
    EXTI_Enable(EXTI_INT0, EXTI_FALLING_EDGE);
    sei();

    while (1)
    {
        PORTA->PORT = patterns[animationMode][index];
        _delay_ms(200);
        index = (index + 1) & 0x07;
    }

    return 0;
}
