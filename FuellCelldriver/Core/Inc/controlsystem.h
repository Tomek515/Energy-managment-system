/*
 * controlsystem.h
 *
 *  Created on: Apr 21, 2025
 *      Author: dvixe
 */

#ifndef INC_CONTROLSYSTEM_H_
#define INC_CONTROLSYSTEM_H_
#include "stm32g0xx_hal.h"
#include <stdbool.h>
#define MOSFET_ON do { \
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_SET); \
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_SET); \
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_SET); \
} while(0)

#define MOSFET_OFF do { \
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_3, GPIO_PIN_RESET); \
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_4, GPIO_PIN_RESET); \
    HAL_GPIO_WritePin(GPIOD, GPIO_PIN_5, GPIO_PIN_RESET); \
} while(0)


#define CHARGE_START_VOLTAGE 19.5f
#define CHARGE_STOP_VOLTAGE  30.0f


typedef enum {
    MODE_AUTO,
    MODE_MANUAL
} ChargeMode_t;


typedef struct {
    ChargeMode_t mode;
    bool is_charging;
} ControlSystem_t;


void ControlSystem_Init(ControlSystem_t *system);
void ControlSystem_Update(ControlSystem_t *system);


#endif /* INC_CONTROLSYSTEM_H_ */
