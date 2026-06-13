/*Implement a system that uses a potentiometer to switch LEDs on and off following these conditoins:
1- If the input voltage is more than 0 and less than 1.5 v, turn Red LED on.
2- If the input voltage is more than 1.5 and less than 3 v, turn Yellow LED on. 
3- If the input voltage is more than 3v turn Geen LED on.
*/
#include "../../mcal/adc/adc_interface.h"
#include "../../mcal/dio/dio_interface.h"
#include <util/delay.h>

int main()
{
    ADC_Init();

    /* LEDs mapping: Red -> PORTA PIN0, Yellow -> PORTA PIN1, Green -> PORTA PIN2 */
    PortPinDir(DIO_PORTA, OUTPUT, PIN0);
    PortPinDir(DIO_PORTA, OUTPUT, PIN1);
    PortPinDir(DIO_PORTA, OUTPUT, PIN2);

    while (1)
    {
        u16 adc = ADC_ReadChannel(0);
        /* Convert ADC (10-bit) to millivolts assuming AVCC = 5V */
        u32 mv = (u32)adc * 5000UL / 1023UL;

        if (mv > 0 && mv < 1500)
        {
            PortSetPin(DIO_PORTA, HIGH, PIN0);
            PortSetPin(DIO_PORTA, LOW, PIN1);
            PortSetPin(DIO_PORTA, LOW, PIN2);
        }
        else if (mv >= 1500 && mv < 3000)
        {
            PortSetPin(DIO_PORTA, LOW, PIN0);
            PortSetPin(DIO_PORTA, HIGH, PIN1);
            PortSetPin(DIO_PORTA, LOW, PIN2);
        }
        else if (mv >= 3000)
        {
            PortSetPin(DIO_PORTA, LOW, PIN0);
            PortSetPin(DIO_PORTA, LOW, PIN1);
            PortSetPin(DIO_PORTA, HIGH, PIN2);
        }

        _delay_ms(200);
    }

    return 0;
}