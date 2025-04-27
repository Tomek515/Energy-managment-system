/*
 * controlsystem.c
 *
 *  Created on: Apr 27, 2025
 *      Author: dvixe
 */
#include "controlsystem.h"
#include "measurments.h"



void ControlSystem_Init(ControlSystem_t *system) {
    system->mode = MODE_AUTO;
    system->is_charging = false;
}

void ControlSystem_Update(ControlSystem_t *system) {

    if (HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_0) == GPIO_PIN_RESET) {
        system->mode = MODE_MANUAL;
        MOSFET_ON;
        return;
    } else {
        system->mode = MODE_AUTO;
    }


    Cell_VoltageResult cell_result = Read_Cellvoltage();

    if (!system->is_charging) {
        if (cell_result.CellVoltage < CHARGE_START_VOLTAGE) {
            MOSFET_ON;
            system->is_charging = true;
        }
    } else {
        if (cell_result.CellVoltage >= CHARGE_STOP_VOLTAGE) {
            MOSFET_OFF;
            system->is_charging = false;
        }
    }
}

