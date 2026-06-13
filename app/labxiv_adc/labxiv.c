/*
Implement a voltmeter system that display a voltage value on LCD in milli volt unit. 
Use a potentiometer to change the input voltage on the system.
 The system shall update the input voltage on the display every 1 second.

*/
#include "../../mcal/adc/adc_interface.h"
#include "../../hal/lcd/LCD.h"
int main()
{
    ADC_Init();
    LCD_Init();

    char buf[17];

    while (1)
    {
        u16 adc = ADC_ReadChannel(0);
        /* Convert to millivolts (AVCC = 5V, 10-bit ADC) */
        u32 mv = (u32)adc * 5000UL / 1023UL;

        /* Format: "Voltage: XXXX mV" (16 chars max) */
        /* simple integer to string conversion */
        int i = 0;
        u32 tmp = mv;
        char num[6] = "00000";
        int pos = 4;
        if (tmp == 0)
            num[pos] = '0';
        while (tmp > 0 && pos >= 0)
        {
            num[pos--] = '0' + (tmp % 10);
            tmp /= 10;
        }

        /* build final string */
        LCD_Clear();
        LCD_String_xy(0, 0, "Voltage:");
        LCD_String_xy(0, 9, num);
        LCD_String_xy(1, 0, "milliVolt:");

        /* display unit on second line */
        LCD_String_xy(1, 10, "mV");

        _delay_ms(1000);
    }
}