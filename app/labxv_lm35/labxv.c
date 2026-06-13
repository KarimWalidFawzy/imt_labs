/*
Implement a system that reads the ambient temperature and do the following:
1- if the temperature is less than 20 degree Celsius, turn on Green LED.
2- if the temperature is more than 20 and less than 40 degree Celsius, turn on Yellow LED.
3- if the temperature is more than 40 degree Celsius, Turn on Red LED and turn on a buzzer for indicating a dangerous
Uses LM35 Sensor 
*/
#include "../../mcal/adc/adc_interface.h"
#include "../../mcal/dio/dio_interface.h"
#include <util/delay.h>

int main(void)
{
	ADC_Init();

	/* LEDs: Green=PA0, Yellow=PA1, Red=PA2, Buzzer=PA3 */
	PortPinDir(DIO_PORTA, OUTPUT, PIN0);
	PortPinDir(DIO_PORTA, OUTPUT, PIN1);
	PortPinDir(DIO_PORTA, OUTPUT, PIN2);
	PortPinDir(DIO_PORTA, OUTPUT, PIN3);

	while (1)
	{
		u16 adc = ADC_ReadChannel(1);
		u32 mv = (u32)adc * 5000UL / 1023UL;
		s16 tempC = (s16)(mv / 10UL); /* LM35: 10mV per °C */

		if (tempC < 20)
		{
			PortSetPin(DIO_PORTA, HIGH, PIN0);
			PortSetPin(DIO_PORTA, LOW, PIN1);
			PortSetPin(DIO_PORTA, LOW, PIN2);
			PortSetPin(DIO_PORTA, LOW, PIN3);
		}
		else if (tempC >= 20 && tempC < 40)
		{
			PortSetPin(DIO_PORTA, LOW, PIN0);
			PortSetPin(DIO_PORTA, HIGH, PIN1);
			PortSetPin(DIO_PORTA, LOW, PIN2);
			PortSetPin(DIO_PORTA, LOW, PIN3);
		}
		else
		{
			PortSetPin(DIO_PORTA, LOW, PIN0);
			PortSetPin(DIO_PORTA, LOW, PIN1);
			PortSetPin(DIO_PORTA, HIGH, PIN2);
			PortSetPin(DIO_PORTA, HIGH, PIN3);
		}

		_delay_ms(500);
	}

	return 0;
}
