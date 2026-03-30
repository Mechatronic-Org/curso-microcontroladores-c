#include "lcd16x2_hal.h"

static void LCD_Write4Bits(LCD16x2_HandleTypeDef *lcd, uint8_t data);
static void LCD_EnablePulse(LCD16x2_HandleTypeDef *lcd);
static void LCD_SendInternal(LCD16x2_HandleTypeDef *lcd, uint8_t data, uint8_t rs);

static void LCD_Write4Bits(LCD16x2_HandleTypeDef *lcd, uint8_t data)
{
    HAL_GPIO_WritePin(lcd->d4_port, lcd->d4_pin, (data & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(lcd->d5_port, lcd->d5_pin, (data & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(lcd->d6_port, lcd->d6_pin, (data & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
    HAL_GPIO_WritePin(lcd->d7_port, lcd->d7_pin, (data & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

static void LCD_EnablePulse(LCD16x2_HandleTypeDef *lcd)
{
    HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);
    HAL_Delay(1);
}

static void LCD_SendInternal(LCD16x2_HandleTypeDef *lcd, uint8_t data, uint8_t rs)
{
    HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, rs ? GPIO_PIN_SET : GPIO_PIN_RESET);

    LCD_Write4Bits(lcd, (data >> 4) & 0x0F);
    LCD_EnablePulse(lcd);

    LCD_Write4Bits(lcd, data & 0x0F);
    LCD_EnablePulse(lcd);
}

void LCD_SendCommand(LCD16x2_HandleTypeDef *lcd, uint8_t cmd)
{
    LCD_SendInternal(lcd, cmd, 0);

    if (cmd == 0x01 || cmd == 0x02) {
        HAL_Delay(2);
    }
}

void LCD_SendChar(LCD16x2_HandleTypeDef *lcd, char ch)
{
    LCD_SendInternal(lcd, (uint8_t)ch, 1);
}

void LCD_SendString(LCD16x2_HandleTypeDef *lcd, const char *str)
{
    while (*str) {
        LCD_SendChar(lcd, *str++);
    }
}

void LCD_SetCursor(LCD16x2_HandleTypeDef *lcd, uint8_t row, uint8_t col)
{
    uint8_t address;

    switch (row) {
        case 0:
            address = 0x00 + col;
            break;
        case 1:
            address = 0x40 + col;
            break;
        default:
            address = 0x00 + col;
            break;
    }

    LCD_SendCommand(lcd, 0x80 | address);
}

void LCD_Clear(LCD16x2_HandleTypeDef *lcd)
{
    LCD_SendCommand(lcd, 0x01);
    HAL_Delay(2);
}

void LCD_Init(LCD16x2_HandleTypeDef *lcd)
{
    HAL_Delay(50);

    HAL_GPIO_WritePin(lcd->rs_port, lcd->rs_pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(lcd->en_port, lcd->en_pin, GPIO_PIN_RESET);

    LCD_Write4Bits(lcd, 0x03);
    LCD_EnablePulse(lcd);
    HAL_Delay(5);

    LCD_Write4Bits(lcd, 0x03);
    LCD_EnablePulse(lcd);
    HAL_Delay(1);

    LCD_Write4Bits(lcd, 0x03);
    LCD_EnablePulse(lcd);
    HAL_Delay(1);

    LCD_Write4Bits(lcd, 0x02);
    LCD_EnablePulse(lcd);
    HAL_Delay(1);

    LCD_SendCommand(lcd, 0x28);
    LCD_SendCommand(lcd, 0x0C);
    LCD_SendCommand(lcd, 0x06);
    LCD_Clear(lcd);
}
