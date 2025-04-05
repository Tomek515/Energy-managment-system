/*
 * func.h
 *
 *  Created on: Apr 2, 2025
 *      Author: dvixe
 */

#ifndef INC_FUNC_H_
#define INC_FUNC_H_

#define ADC_RESOLUTION 4095.0f
#define VREF 3.3f
#define MINV (20.0f /13.63f)
#define MAXV (29.0f / 13.63f)


#define MOSFET_ON()  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET)
#define MOSFET_OFF() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET)

#define HUMIDIFIER_ON()  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET)
#define HUMIDIFIER_OFF() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET)


#include "main.h"
float Read_ADC_Value(void);


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);


#endif /* INC_FUNC_H_ */
