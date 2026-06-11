#include "adc_interface.h"
#include "../../lib/BIT_MATH.h"
void ADC_Init(void)
{
    ADC_REG->ADMUX = (ADC_REG->ADMUX & 0x3F) | (ADC_REFERENCE_SELECTION << 6);
    ADC_REG->ADMUX &= ~(1 << ADLAR);
    ADC_REG->ADCSRA = (1 << ADEN) | ADC_PRESCALER_SELECTION;
}

u16 ADC_ReadChannel(u8 channel)
{
    ADC_REG->ADMUX = (ADC_REG->ADMUX & 0xE0) | (channel & 0x1F);
    ADC_REG->ADCSRA |= (1 << 6);
    while (ADC_REG->ADCSRA & (1 << 6));
    return ((u16)ADC_REG->ADCL) | ((u16)ADC_REG->ADCH << 8);
}
