#ifndef KEYPAD4X4_HAL_H
#define KEYPAD4X4_HAL_H

#include "stm32c0xx_hal.h"
#include <stdint.h>

typedef struct {
    GPIO_TypeDef *RowPorts[4];
    uint16_t RowPins[4];

    GPIO_TypeDef *ColPorts[4];
    uint16_t ColPins[4];

    char KeyMap[4][4];
} Keypad_HandleTypeDef;

void Keypad_Init(Keypad_HandleTypeDef *keypad);
char Keypad_GetKey(Keypad_HandleTypeDef *keypad);

#endif
