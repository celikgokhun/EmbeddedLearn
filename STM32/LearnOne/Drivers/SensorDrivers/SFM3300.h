/*
 * SFM3300.h
 *
 *  Created on: Sep 9, 2022
 *      Author: celikgo
 */

#ifndef SENSORDRIVERS_SFM3300_H_
#define SENSORDRIVERS_SFM3300_H_

#include <stdint.h>
#include "stm32f3xx_hal.h"

// SFM3300 structure
typedef struct
{
    int16_t Flow;
    uint8_t packet_crc;
} SFM3300_t;


void SFM3300_Init(I2C_HandleTypeDef *I2Cx);

void SFM3300_Read_Current(I2C_HandleTypeDef *I2Cx, uint8_t* data);

void SFM3300_Hard_Reset();

uint8_t SMF3300_CheckCrc (uint8_t data[], uint8_t nbrOfBytes, uint8_t checksum);

double SFM3300_ConvertRawData_to_FlowValue(uint8_t data[]);

#endif /* SENSORDRIVERS_SFM3300_H_ */
