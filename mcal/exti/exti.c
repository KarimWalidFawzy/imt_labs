#include "exti_interface.h"
#include "../../lib/BIT_MATH.h"
#include <avr/interrupt.h>

static EXTI_Callback_t g_EXTI_Callbacks[3] = {0, 0, 0};

void EXTI_Enable(u8 interruptNum, u8 senseControl)
{
    switch (interruptNum)
    {
        case EXTI_INT0:
            MCUCR = (MCUCR & 0xFC) | (senseControl & 0x03);
            SET_BIT(GICR, INT0_BIT);
            break;

        case EXTI_INT1:
            MCUCR = (MCUCR & 0xF3) | ((senseControl & 0x03) << 2);
            SET_BIT(GICR, INT1_BIT);
            break;

        case EXTI_INT2:
            if (senseControl == EXTI_FALLING_EDGE) CLR_BIT(MCUCSR, 6);
            else if (senseControl == EXTI_RISING_EDGE) SET_BIT(MCUCSR, 6);
            SET_BIT(GICR, INT2_BIT);
            break;
    }
}

void EXTI_Disable(u8 interruptNum)
{
    switch (interruptNum)
    {
        case EXTI_INT0: CLR_BIT(GICR, INT0_BIT); break;
        case EXTI_INT1: CLR_BIT(GICR, INT1_BIT); break;
        case EXTI_INT2: CLR_BIT(GICR, INT2_BIT); break;
    }
}

void EXTI_SetCallback(u8 interruptNum, EXTI_Callback_t callback)
{
    if (interruptNum < 3)
    {
        g_EXTI_Callbacks[interruptNum] = callback;
    }
}

ISR(INT0_vect)
{
    if (g_EXTI_Callbacks[EXTI_INT0])
    {
        g_EXTI_Callbacks[EXTI_INT0]();
    }
}

ISR(INT1_vect)
{
    if (g_EXTI_Callbacks[EXTI_INT1])
    {
        g_EXTI_Callbacks[EXTI_INT1]();
    }
}

ISR(INT2_vect)
{
    if (g_EXTI_Callbacks[EXTI_INT2])
    {
        g_EXTI_Callbacks[EXTI_INT2]();
    }
}
