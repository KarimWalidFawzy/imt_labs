#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H
#include "adc_private.h"
#include "adc_config.h"

void ADC_Init(void);
u16 ADC_ReadChannel(u8 channel);

#endif
