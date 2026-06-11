#ifndef LCD_H_
#define LCD_H_

#include "../../mcal/dio/dio_interface.h"
#include <stdint.h>

/*
 * LCD interface pins for ATmega32
 * Data bus: PORTD (PD0-PD7)
 * Control bus: PORTC (PC0-PC2)
 * RS: PC0, RW: PC1, EN: PC2
 */

#define LCD_DATA_PORT PORTD->PORT
#define LCD_DATA_DIR  PORTD->DDR
#define LCD_CTRL_PORT PORTC->PORT
#define LCD_CTRL_DIR  PORTC->DDR

#define LCD_RS_PIN    0
#define LCD_RW_PIN    1
#define LCD_EN_PIN    2

#define LCD_RS_HIGH() (LCD_CTRL_PORT |=  (1 << LCD_RS_PIN))
#define LCD_RS_LOW()  (LCD_CTRL_PORT &= ~(1 << LCD_RS_PIN))
#define LCD_RW_HIGH() (LCD_CTRL_PORT |=  (1 << LCD_RW_PIN))
#define LCD_RW_LOW()  (LCD_CTRL_PORT &= ~(1 << LCD_RW_PIN))
#define LCD_EN_HIGH() (LCD_CTRL_PORT |=  (1 << LCD_EN_PIN))
#define LCD_EN_LOW()  (LCD_CTRL_PORT &= ~(1 << LCD_EN_PIN))

void LCD_Init(void);
void LCD_Cmd(uint8_t cmd);
void LCD_Data(uint8_t data);
void LCD_Clear(void);
void LCD_String(const char *str);
void LCD_String_xy(uint8_t row, uint8_t col, const char *str);
void LCD_GoToXY(uint8_t row, uint8_t col);

#endif /* LCD_H_ */
