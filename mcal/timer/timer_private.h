#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#include "../../lib/STD_TYPES.h"

#define TCCR0   (*((volatile u8*)0x53))
#define TCNT0   (*((volatile u8*)0x52))
#define OCR0    (*((volatile u8*)0x5C))

#define TCCR1A  (*((volatile u8*)0x4F))
#define TCCR1B  (*((volatile u8*)0x4E))
#define TCNT1H  (*((volatile u8*)0x4D))
#define TCNT1L  (*((volatile u8*)0x4C))
#define OCR1AH  (*((volatile u8*)0x4B))
#define OCR1AL  (*((volatile u8*)0x4A))
#define OCR1BH  (*((volatile u8*)0x49))
#define OCR1BL  (*((volatile u8*)0x48))

#define TCCR2   (*((volatile u8*)0x45))
#define TCNT2   (*((volatile u8*)0x44))
#define OCR2    (*((volatile u8*)0x43))
#define ASSR    (*((volatile u8*)0x42))

#define TIMSK   (*((volatile u8*)0x59))
#define TIFR    (*((volatile u8*)0x58))

/* Timer0 bit positions */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

/* Timer1 bit positions */
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

#define ICNC1   7
#define ICES1   6
#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

/* Timer2 bit positions */
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0

/* Interrupt mask bits */
#define TOIE0   0
#define OCIE0   1
#define TOIE1   2
#define OCIE1B  3
#define OCIE1A  4
#define TICIE1  5
#define TOIE2   6
#define OCIE2   7

#endif 