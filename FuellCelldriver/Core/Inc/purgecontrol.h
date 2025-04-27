/*
 * purgecontrol.h
 *
 *  Created on: Apr 27, 2025
 *      Author: dvixe
 */

#ifndef INC_PURGECONTROL_H_
#define INC_PURGECONTROL_H_



#include "stm32g0xx_hal.h"
#include <stdbool.h>
typedef struct {
    uint32_t ms_counter;
    bool pulse_active;
    uint32_t pulse_time;
} PulseControl_t;

void PulseControl_Init(PulseControl_t *control);
void PulseControl_TimerIRQ_Handler(PulseControl_t *control);


#endif /* INC_PURGECONTROL_H_ */
