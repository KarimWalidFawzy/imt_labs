#include "../../hal/lcd/LCD.h"

int main(void)
{
    LCD_Init();
    LCD_String("MY NAME");

    while (1)
    {
        ;
    }

    return 0;
}
