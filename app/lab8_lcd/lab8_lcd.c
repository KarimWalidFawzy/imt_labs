#include "../../hal/lcd/LCD.h"
#include <util/delay.h>
#include <string.h>

int main(void)
{
    const char name[] = "MY NAME";
    uint8_t length = (uint8_t)strlen(name);
    int8_t pos;
    uint8_t direction = 1;

    LCD_Init();
    LCD_Clear();

    pos = 16 - length;

    while (1)
    {
        LCD_Clear();
        LCD_String_xy(0, pos, name);
        _delay_ms(300);

        if (direction)
        {
            pos--;
            if (pos < 0)
            {
                pos = 0;
                direction = 0;
            }
        }
        else
        {
            pos++;
            if ((uint8_t)pos > 16 - length)
            {
                pos = 16 - length;
                direction = 1;
            }
        }
    }

    return 0;
}
