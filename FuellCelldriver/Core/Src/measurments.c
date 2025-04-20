/*
 * measurments.c
 *
 *  Created on: Apr 20, 2025
 *      Author: dvixe
 */
#include "measurments.h"

extern ADC_HandleTypeDef hadc1;

float Read_ADC_Value(uint8_t channel_number) {
    ADC_ChannelConfTypeDef sConfig = {0};
    uint32_t channel;

    // Mapowanie numeru kanału użytkownika na kanał HAL
    switch (channel_number) {
        case 1: channel = ADC_CHANNEL_1; break;
        case 2: channel = ADC_CHANNEL_2; break;
        case 3: channel = ADC_CHANNEL_3; break;
        case 4: channel = ADC_CHANNEL_4; break;
        default: return -1.0f; // nieprawidłowy kanał
    }

    // Konfiguracja kanału
    sConfig.Channel = channel;
    sConfig.Rank = ADC_REGULAR_RANK_1;
    sConfig.SamplingTime = ADC_SAMPLINGTIME_COMMON_1;

    if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK) {
        return -1.0f;
    }

    HAL_ADC_Start(&hadc1);
    HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
    uint32_t adc_value = HAL_ADC_GetValue(&hadc1);

    return ((float)adc_value / ADC_RESOLUTION) * VREF;
}
