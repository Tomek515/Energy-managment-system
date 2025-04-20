/*
 * measurments.c
 *
 *  Created on: Apr 20, 2025
 *      Author: dvixe
 */
#include "measurments.h"

extern ADC_HandleTypeDef hadc1;

float Read_ADC_Value() {
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	uint32_t adc_value = HAL_ADC_GetValue(&hadc1);
    return (adc_value / ADC_RESOLUTION) * VREF;
}
