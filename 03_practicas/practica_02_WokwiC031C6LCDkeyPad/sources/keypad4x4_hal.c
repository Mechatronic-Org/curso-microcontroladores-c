#include "keypad4x4_hal.h"

void Keypad_Init(Keypad_HandleTypeDef *keypad)
{
    for (uint8_t i = 0; i < 4; i++) {
        HAL_GPIO_WritePin(keypad->RowPorts[i], keypad->RowPins[i], GPIO_PIN_SET);
    }
}

char Keypad_GetKey(Keypad_HandleTypeDef *keypad)
{
    for (uint8_t row = 0; row < 4; row++) {

        for (uint8_t i = 0; i < 4; i++) {
            HAL_GPIO_WritePin(keypad->RowPorts[i], keypad->RowPins[i], GPIO_PIN_SET);
        }

        HAL_GPIO_WritePin(keypad->RowPorts[row], keypad->RowPins[row], GPIO_PIN_RESET);

        for (volatile uint32_t d = 0; d < 200; d++) {
            __NOP();
        }

        for (uint8_t col = 0; col < 4; col++) {
            if (HAL_GPIO_ReadPin(keypad->ColPorts[col], keypad->ColPins[col]) == GPIO_PIN_RESET) {

                HAL_Delay(20);

                if (HAL_GPIO_ReadPin(keypad->ColPorts[col], keypad->ColPins[col]) == GPIO_PIN_RESET) {
                    while (HAL_GPIO_ReadPin(keypad->ColPorts[col], keypad->ColPins[col]) == GPIO_PIN_RESET) {
                    }
                    HAL_Delay(20);
                    return keypad->KeyMap[row][col];
                }
            }
        }
    }

    return 0;
}
