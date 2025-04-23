/*
 * controlsystem.h
 *
 *  Created on: Apr 21, 2025
 *      Author: dvixe
 */

#ifndef INC_CONTROLSYSTEM_H_
#define INC_CONTROLSYSTEM_H_
#include "stm32g0xx_hal.h"

#define MOSFET_ON do { \
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET); \
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET); \
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET); \
} while(0)

#define MOSFET_OFF do { \
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET); \
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET); \
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET); \
} while(0)


#endif /* INC_CONTROLSYSTEM_H_ */
