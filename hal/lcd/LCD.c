#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <util/delay.h>
#include "LCD.h"

static void LCD_EnablePulse(void)
{
    LCD_EN_HIGH();
    _delay_us(1);
    LCD_EN_LOW();
    _delay_us(100);
}

static void LCD_Write(uint8_t value, uint8_t rs)
{
    if (rs)
        LCD_RS_HIGH();
    else
        LCD_RS_LOW();

    LCD_RW_LOW();
    LCD_DATA_PORT = value;
    _delay_us(1);
    LCD_EnablePulse();
}

void LCD_Init(void)
{
    // Set data and control pins as output
    LCD_DATA_DIR = 0xFF;
    // Set control pins as output
    LCD_CTRL_DIR |= (1 << LCD_RS_PIN) | (1 << LCD_RW_PIN) | (1 << LCD_EN_PIN);
    // Initialization sequence
    _delay_ms(40);// Wait for LCD to power up
    LCD_Write(0x38, 0);  /* Function set: 8-bit, 2 lines, 5x8 dots */
    _delay_ms(1);
    LCD_Write(0x0C, 0);  /* Display ON, cursor OFF, blink OFF */
    _delay_ms(1);
    LCD_Write(0x01, 0);  /* Clear display */
    _delay_ms(2);
    LCD_Write(0x06, 0);  /* Entry mode: increment cursor */
    _delay_ms(1);
}

void LCD_Cmd(uint8_t cmd)
{
    LCD_Write(cmd, 0);
}

void LCD_Data(uint8_t data)
{
    LCD_Write(data, 1);
}

void LCD_Clear(void)
{
    LCD_Cmd(0x01);
    _delay_ms(2);
}

void LCD_GoToXY(uint8_t row, uint8_t col)
{
    uint8_t address;

    if (row == 0)
        address = 0x80 + col;
    else
        address = 0xC0 + col;

    LCD_Cmd(address);
}

void LCD_String(const char *str)
{
    while (*str)
    {
        LCD_Data((uint8_t)*str++);
    }
}

void LCD_String_xy(uint8_t row, uint8_t col, const char *str)
{
    LCD_GoToXY(row, col);
    LCD_String(str);
}
