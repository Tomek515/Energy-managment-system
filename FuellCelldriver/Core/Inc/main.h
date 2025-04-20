/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define CELL_TEMPERATURE_Pin GPIO_PIN_1
#define CELL_TEMPERATURE_GPIO_Port GPIOA
#define VCELL_MEASURE_Pin GPIO_PIN_2
#define VCELL_MEASURE_GPIO_Port GPIOA
#define ICELL_MEASURE_Pin GPIO_PIN_3
#define ICELL_MEASURE_GPIO_Port GPIOA
#define BLOWER_Pin GPIO_PIN_0
#define BLOWER_GPIO_Port GPIOB
#define BLOWER_PWM_Pin GPIO_PIN_1
#define BLOWER_PWM_GPIO_Port GPIOB
#define PURGE_Pin GPIO_PIN_6
#define PURGE_GPIO_Port GPIOC
#define HUMIDIFIER_Pin GPIO_PIN_7
#define HUMIDIFIER_GPIO_Port GPIOC
#define H_VALVE_Pin GPIO_PIN_8
#define H_VALVE_GPIO_Port GPIOD
#define MOSFET_1_Pin GPIO_PIN_3
#define MOSFET_1_GPIO_Port GPIOD
#define MOSFET_2_Pin GPIO_PIN_4
#define MOSFET_2_GPIO_Port GPIOD
#define MOSFET_3_Pin GPIO_PIN_5
#define MOSFET_3_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
