#ifndef LCD16X2_HAL_H
#define LCD16X2_HAL_H

#include "stm32c0xx_hal.h"
#include <stdint.h>

typedef struct {
    GPIO_TypeDef *rs_port;
    uint16_t rs_pin;

    GPIO_TypeDef *en_port;
    uint16_t en_pin;

    GPIO_TypeDef *d4_port;
    uint16_t d4_pin;

    GPIO_TypeDef *d5_port;
    uint16_t d5_pin;

    GPIO_TypeDef *d6_port;
    uint16_t d6_pin;

    GPIO_TypeDef *d7_port;
    uint16_t d7_pin;
} LCD16x2_HandleTypeDef;

void LCD_Init(LCD16x2_HandleTypeDef *lcd);
void LCD_Clear(LCD16x2_HandleTypeDef *lcd);
void LCD_SetCursor(LCD16x2_HandleTypeDef *lcd, uint8_t row, uint8_t col);
void LCD_SendCommand(LCD16x2_HandleTypeDef *lcd, uint8_t cmd);
void LCD_SendChar(LCD16x2_HandleTypeDef *lcd, char ch);
void LCD_SendString(LCD16x2_HandleTypeDef *lcd, const char *str);

#endif
