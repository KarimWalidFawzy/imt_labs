/*
Using LDR, implement a system that turns on a LED when it gets dark, and turns the LED off when it gets bright.
LDR connected to ADC channel 2. LED on PA0.
*/
#include "../../mcal/adc/adc_interface.h"
#include "../../mcal/dio/dio_interface.h"
#include <util/delay.h>

int main(void)
{
	ADC_Init();

	PortPinDir(DIO_PORTA, OUTPUT, PIN0);

	while (1)
	{
		u16 adc = ADC_ReadChannel(2);
		/* higher ADC means brighter (depends on circuit), choose threshold */
		if (adc < 300) /* dark */
		{
			PortSetPin(DIO_PORTA, HIGH, PIN0);
		}
		else
		{
			PortSetPin(DIO_PORTA, LOW, PIN0);
		}

		_delay_ms(200);
	}

	return 0;
}