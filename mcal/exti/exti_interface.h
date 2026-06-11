#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H
#include "exti_private.h"
#include "exti_config.h"

typedef void (*EXTI_Callback_t)(void);

void EXTI_Enable(u8 interruptNum, u8 senseControl);
void EXTI_Disable(u8 interruptNum);
void EXTI_SetCallback(u8 interruptNum, EXTI_Callback_t callback);

#endif
