/*
Make a system that generates different tones on a buzzer by changing potentiometer value. The potentiometer is connected to ADC Pin, read the potentiometer and change the OCR value accordingly. In the compare match interrupt toggle a pin that connected to the buzzer. Changing the OCR means changing the frequency of buzzer signal which means changing the buzzer tone
*/
#include "../../mcal/adc/adc_interface.h"
#include "../../mcal/timer/timer_interface.h"
#include "../../mcal/dio/dio_interface.h"
#include <avr/interrupt.h>

/* Buzzer on PA0, potentiometer on ADC0 */
static void Buzzer_Toggle(void)
{
	TOG_BIT(PORTA->PORT, PIN0);
}

int main(void)
{
	ADC_Init();
	PortPinDir(DIO_PORTA, OUTPUT, PIN0);

	TIMER0_Init();
	TIMER0_SetCallback(Buzzer_Toggle);
	TIMER0_EnableCompareMatchInterrupt();
	TIMER0_Start(TIMER_PRESCALER_8);

	sei();

	while (1)
	{
		u16 adc = ADC_ReadChannel(0);
		/* Map ADC (0..1023) to OCR0 (10..245) to avoid extremes */
		u8 ocr = (u8)(10 + ((u32)adc * 235UL) / 1023UL);
		TIMER0_SetCompareValue(ocr);
	}

	return 0;
}