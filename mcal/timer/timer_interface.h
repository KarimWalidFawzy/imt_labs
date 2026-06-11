#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "timer_private.h"
#include "../../lib/STD_TYPES.h"
#include "../../lib/BIT_MATH.h"

/* Timer0 modes */
#define TIMER0_NORMAL_MODE              0
#define TIMER0_PWM_PHASE_CORRECT_MODE   1
#define TIMER0_CTC_MODE                 2
#define TIMER0_FAST_PWM_MODE            3

/* Timer0 output compare pin behavior */
#define TIMER0_OC0_DISCONNECTED         0
#define TIMER0_OC0_TOGGLE               1
#define TIMER0_OC0_CLEAR                2
#define TIMER0_OC0_SET                  3

/* Timer1 modes */
#define TIMER1_NORMAL_MODE              0
#define TIMER1_PWM_PHASE_CORRECT_MODE   1
#define TIMER1_CTC_OCR1A_MODE           4
#define TIMER1_FAST_PWM_MODE            5

/* Timer1 output compare A behavior */
#define TIMER1_OC1A_DISCONNECTED        0
#define TIMER1_OC1A_TOGGLE              1
#define TIMER1_OC1A_CLEAR               2
#define TIMER1_OC1A_SET                 3

/* Timer2 modes */
#define TIMER2_NORMAL_MODE              0
#define TIMER2_PWM_PHASE_CORRECT_MODE   1
#define TIMER2_CTC_MODE                 2
#define TIMER2_FAST_PWM_MODE            3

/* Timer2 output compare pin behavior */
#define TIMER2_OC2_DISCONNECTED         0
#define TIMER2_OC2_TOGGLE               1
#define TIMER2_OC2_CLEAR                2
#define TIMER2_OC2_SET                  3

/* Prescaler selections for all timers */
#define TIMER_NO_CLOCK                  0
#define TIMER_NO_PRESCALER              1
#define TIMER_PRESCALER_8               2
#define TIMER_PRESCALER_64              3
#define TIMER_PRESCALER_256             4
#define TIMER_PRESCALER_1024            5
#define TIMER_EXTERNAL_FALLING          6
#define TIMER_EXTERNAL_RISING           7

#include "timer_config.h"

typedef void (*TIMER0_Callback_t)(void);
typedef void (*TIMER1_Callback_t)(void);
typedef void (*TIMER2_Callback_t)(void);

/* Timer0 public API */
void TIMER0_Init(void);
void TIMER0_SetTimerValue(u8 timerValue);
u8   TIMER0_GetTimerValue(void);
void TIMER0_SetCompareValue(u8 compareValue);
void TIMER0_Start(u8 prescaler);
void TIMER0_Stop(void);
void TIMER0_EnableCompareMatchInterrupt(void);
void TIMER0_DisableCompareMatchInterrupt(void);
void TIMER0_EnableOverflowInterrupt(void);
void TIMER0_DisableOverflowInterrupt(void);
void TIMER0_SetCallback(TIMER0_Callback_t callback);

/* Timer1 public API */
void TIMER1_Init(void);
void TIMER1_SetTimerValue(u16 timerValue);
u16  TIMER1_GetTimerValue(void);
void TIMER1_SetCompareValue(u16 compareValue);
void TIMER1_Start(u8 prescaler);
void TIMER1_Stop(void);
void TIMER1_EnableCompareMatchAInterrupt(void);
void TIMER1_DisableCompareMatchAInterrupt(void);
void TIMER1_EnableOverflowInterrupt(void);
void TIMER1_DisableOverflowInterrupt(void);
void TIMER1_SetCallbackA(TIMER1_Callback_t callback);
void TIMER1_SetOverflowCallback(TIMER1_Callback_t callback);

/* Timer2 public API */
void TIMER2_Init(void);
void TIMER2_SetTimerValue(u8 timerValue);
u8   TIMER2_GetTimerValue(void);
void TIMER2_SetCompareValue(u8 compareValue);
void TIMER2_Start(u8 prescaler);
void TIMER2_Stop(void);
void TIMER2_EnableCompareMatchInterrupt(void);
void TIMER2_DisableCompareMatchInterrupt(void);
void TIMER2_EnableOverflowInterrupt(void);
void TIMER2_DisableOverflowInterrupt(void);
void TIMER2_SetCallback(TIMER2_Callback_t callback);
void TIMER2_SetOverflowCallback(TIMER2_Callback_t callback);

#endif 