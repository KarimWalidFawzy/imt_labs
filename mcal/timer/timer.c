#include "timer_interface.h"
#include <avr/interrupt.h>

static TIMER0_Callback_t g_TIMER0_Callback = NULL;
static TIMER1_Callback_t g_TIMER1_CompareA_Callback = NULL;
static TIMER1_Callback_t g_TIMER1_Overflow_Callback = NULL;
static TIMER2_Callback_t g_TIMER2_Callback = NULL;
static TIMER2_Callback_t g_TIMER2_Overflow_Callback = NULL;

void TIMER0_Init(void)
{
    TCCR0 = 0;
    TCCR0 |= ((TIMER0_DEFAULT_MODE & 0x01) << WGM00);
    TCCR0 |= ((TIMER0_DEFAULT_MODE & 0x02) << (WGM01 - 1));
    TCCR0 |= ((TIMER0_DEFAULT_OC0_MODE & 0x03) << COM00);

    TCNT0 = TIMER0_DEFAULT_START_VALUE;
    OCR0 = TIMER0_DEFAULT_COMPARE_VALUE;

    TIMSK &= ~((1 << TOIE0) | (1 << OCIE0));
}

void TIMER0_SetTimerValue(u8 timerValue)
{
    TCNT0 = timerValue;
}

u8 TIMER0_GetTimerValue(void)
{
    return TCNT0;
}

void TIMER0_SetCompareValue(u8 compareValue)
{
    OCR0 = compareValue;
}

void TIMER0_Start(u8 prescaler)
{
    TCCR0 &= 0xF8;
    TCCR0 |= (prescaler & 0x07);
}

void TIMER0_Stop(void)
{
    TCCR0 &= 0xF8;
}

void TIMER0_EnableCompareMatchInterrupt(void)
{
    SET_BIT(TIMSK, OCIE0);
}

void TIMER0_DisableCompareMatchInterrupt(void)
{
    CLR_BIT(TIMSK, OCIE0);
}

void TIMER0_EnableOverflowInterrupt(void)
{
    SET_BIT(TIMSK, TOIE0);
}

void TIMER0_DisableOverflowInterrupt(void)
{
    CLR_BIT(TIMSK, TOIE0);
}

void TIMER0_SetCallback(TIMER0_Callback_t callback)
{
    g_TIMER0_Callback = callback;
}

void TIMER1_Init(void)
{
    TCCR1A = 0;
    TCCR1B = 0;

    TCCR1A |= ((TIMER1_DEFAULT_OC1A_MODE & 0x03) << COM1A0);
    TCCR1A |= (TIMER1_DEFAULT_MODE & 0x03);
    TCCR1B |= (((TIMER1_DEFAULT_MODE >> 2) & 0x03) << WGM12);

    TCNT1H = (u8)(TIMER1_DEFAULT_START_VALUE >> 8);
    TCNT1L = (u8)TIMER1_DEFAULT_START_VALUE;
    OCR1AH = (u8)(TIMER1_DEFAULT_COMPARE_VALUE >> 8);
    OCR1AL = (u8)TIMER1_DEFAULT_COMPARE_VALUE;

    TIMSK &= ~((1 << TOIE1) | (1 << OCIE1A));
}

void TIMER1_SetTimerValue(u16 timerValue)
{
    TCNT1H = (u8)(timerValue >> 8);
    TCNT1L = (u8)timerValue;
}

u16 TIMER1_GetTimerValue(void)
{
    return ((u16)TCNT1H << 8) | TCNT1L;
}

void TIMER1_SetCompareValue(u16 compareValue)
{
    OCR1AH = (u8)(compareValue >> 8);
    OCR1AL = (u8)compareValue;
}

void TIMER1_Start(u8 prescaler)
{
    TCCR1B &= 0xF8;
    TCCR1B |= (prescaler & 0x07);
}

void TIMER1_Stop(void)
{
    TCCR1B &= 0xF8;
}

void TIMER1_EnableCompareMatchAInterrupt(void)
{
    SET_BIT(TIMSK, OCIE1A);
}

void TIMER1_DisableCompareMatchAInterrupt(void)
{
    CLR_BIT(TIMSK, OCIE1A);
}

void TIMER1_EnableOverflowInterrupt(void)
{
    SET_BIT(TIMSK, TOIE1);
}

void TIMER1_DisableOverflowInterrupt(void)
{
    CLR_BIT(TIMSK, TOIE1);
}

void TIMER1_SetCallbackA(TIMER1_Callback_t callback)
{
    g_TIMER1_CompareA_Callback = callback;
}

void TIMER1_SetOverflowCallback(TIMER1_Callback_t callback)
{
    g_TIMER1_Overflow_Callback = callback;
}

void TIMER2_Init(void)
{
    TCCR2 = 0;
    TCCR2 |= ((TIMER2_DEFAULT_MODE & 0x01) << WGM20);
    TCCR2 |= ((TIMER2_DEFAULT_MODE & 0x02) << (WGM21 - 1));
    TCCR2 |= ((TIMER2_DEFAULT_OC2_MODE & 0x03) << COM20);

    TCNT2 = TIMER2_DEFAULT_START_VALUE;
    OCR2 = TIMER2_DEFAULT_COMPARE_VALUE;

    TIMSK &= ~((1 << TOIE2) | (1 << OCIE2));
}

void TIMER2_SetTimerValue(u8 timerValue)
{
    TCNT2 = timerValue;
}

u8 TIMER2_GetTimerValue(void)
{
    return TCNT2;
}

void TIMER2_SetCompareValue(u8 compareValue)
{
    OCR2 = compareValue;
}

void TIMER2_Start(u8 prescaler)
{
    TCCR2 &= 0xF8;
    TCCR2 |= (prescaler & 0x07);
}

void TIMER2_Stop(void)
{
    TCCR2 &= 0xF8;
}

void TIMER2_EnableCompareMatchInterrupt(void)
{
    SET_BIT(TIMSK, OCIE2);
}

void TIMER2_DisableCompareMatchInterrupt(void)
{
    CLR_BIT(TIMSK, OCIE2);
}

void TIMER2_EnableOverflowInterrupt(void)
{
    SET_BIT(TIMSK, TOIE2);
}

void TIMER2_DisableOverflowInterrupt(void)
{
    CLR_BIT(TIMSK, TOIE2);
}

void TIMER2_SetCallback(TIMER2_Callback_t callback)
{
    g_TIMER2_Callback = callback;
}

void TIMER2_SetOverflowCallback(TIMER2_Callback_t callback)
{
    g_TIMER2_Overflow_Callback = callback;
}

ISR(TIMER0_COMP_vect)
{
    if (g_TIMER0_Callback != NULL)
    {
        g_TIMER0_Callback();
    }
}

ISR(TIMER1_COMPA_vect)
{
    if (g_TIMER1_CompareA_Callback != NULL)
    {
        g_TIMER1_CompareA_Callback();
    }
}

ISR(TIMER1_OVF_vect)
{
    if (g_TIMER1_Overflow_Callback != NULL)
    {
        g_TIMER1_Overflow_Callback();
    }
}

ISR(TIMER2_COMP_vect)
{
    if (g_TIMER2_Callback != NULL)
    {
        g_TIMER2_Callback();
    }
}

ISR(TIMER2_OVF_vect)
{
    if (g_TIMER2_Overflow_Callback != NULL)
    {
        g_TIMER2_Overflow_Callback();
    }
}
