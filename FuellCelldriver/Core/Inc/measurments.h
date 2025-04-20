/*
 * measurments.h
 *
 *  Created on: Apr 20, 2025
 *      Author: dvixe
 */

#ifndef INC_MEASURMENTS_H_
#define INC_MEASURMENTS_H_
#include "stm32g0xx_hal.h"
#include <stdint.h>
// Capacitor voltage measurment
#define ADC_RESOLUTION 4095.0f
#define VREF 3.3f
#define MINV (20.0f /13.63f)
#define MAXV (29.0f / 13.63f)

float Read_ADC_Value(uint8_t channel_number);

float Read_Temp();
// Cell Temperature


#endif /* INC_MEASURMENTS_H_ */
