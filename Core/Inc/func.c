/*
 * func.c
 *
 *  Created on: Apr 2, 2025
 *      Author: dvixe
 */

#include "func.h"

extern ADC_HandleTypeDef hadc1;



float Read_ADC_Value() {
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);
	uint32_t adc_value = HAL_ADC_GetValue(&hadc1);
    return(adc_value / ADC_RESOLUTION) * VREF;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == GPIO_PIN_1)
    {
    	HAL_Delay(50);

    	if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1) == GPIO_PIN_RESET){
    	 MOSFET_ON();
    }}

    if (GPIO_Pin == GPIO_PIN_2)
    {
    	HAL_Delay(50);
    	if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2) == GPIO_PIN_RESET){

    		MOSFET_OFF();
    	}}
}
}
