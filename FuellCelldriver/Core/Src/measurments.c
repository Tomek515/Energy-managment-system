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


    switch (channel_number) {
        case 1: channel = ADC_CHANNEL_1; break;
        case 2: channel = ADC_CHANNEL_2; break;
        case 3: channel = ADC_CHANNEL_3; break;
        case 4: channel = ADC_CHANNEL_4; break;
        default: return -1.0f;
    }

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
/*
//TEMPERATURE
#define R_REF 120.0f  //pt100 resistor
#define A 3.9083e-3f  //constant to pt100 calculation
#define B -5.775e-7f

float Read_Temp(){
uint8_t voltage = Read_ADC_Value(1);
float resistance=(voltage * R_REF) / (VREF - voltage);

float R0 = 100.0f;

    float temp = (-A + sqrtf(A*A - 4*B*(1 - resistance/R0))) / (2*B);
    return temp;
}*/



//CURRENT ACS37030 Sensor
CurrentResult Read_Current(void){
	CurrentResult current_result;
	float zero_current_voltage= 1.65f;

	float sesitivity = 0.025f;

	float ACS_voltage=Read_ADC_Value(3);


	if (ACS_voltage < zero_current_voltage){
		current_result.Currenterror = true;
		current_result.Current = 0.0f;
		return current_result;
	}

	current_result.Currenterror = false;
	current_result.Current = (ACS_voltage - zero_current_voltage) / sesitivity;
	return current_result;
}
// voltage from capacitor
CapacitorResult Read_CapacitorVoltage(void){
	CapacitorResult capacitor_result;

	float capacitor_divider= 13.636f;

	float Capacitor_voltage=Read_ADC_Value(4);

	capacitor_result.Voltage = Capacitor_voltage * capacitor_divider;

	return capacitor_result;
}

Cell_VoltageResult Read_CellVoltage(void){
	Cell_VoltageResult cell_result;

	float cell_divider= 9.41f;

	float cell_voltage=Read_ADC_Value(2);

	cell_result.CellVoltage = cell_voltage * cell_divider;

	return cell_result;
}

