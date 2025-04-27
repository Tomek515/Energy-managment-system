/*
 * purgecontrol.c
 *
 *  Created on: Apr 27, 2025
 *      Author: dvixe
 */

#include "purgecontrol.h"

// Definiujemy czasy w milisekundach
#define PULSE_INTERVAL_MS 60000  // 60 sekund
#define PULSE_DURATION_MS 3000   // 3 sekundy

void PulseControl_Init(PulseControl_t *control) {
    control->ms_counter = 0;
    control->pulse_active = false;
    control->pulse_time = 0;
}

void PulseControl_TimerIRQ_Handler(PulseControl_t *control) {
    control->ms_counter++;

    if (!control->pulse_active) {
        if (control->ms_counter >= PULSE_INTERVAL_MS) {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_SET); // Aktywuj pin
            control->pulse_active = true;
            control->pulse_time = 0;
            control->ms_counter = 0;
        }
    } else {
        control->pulse_time++;
        if (control->pulse_time >= PULSE_DURATION_MS) {
            HAL_GPIO_WritePin(GPIOD, GPIO_PIN_1, GPIO_PIN_RESET); // Dezaktywuj pin
            control->pulse_active = false;
        }
    }
}
