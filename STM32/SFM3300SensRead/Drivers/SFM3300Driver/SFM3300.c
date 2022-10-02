/*
 * SFM3300.c
 *
 *  Created on: Sep 20, 2022
 *      Author: celikgo
 */

#include "SFM3300.h"

// Setup SFM3300
#define SFM3300_ADDR 0x80
#define SFM3300_offSet       32768.00
#define SFM3300_scaleFactor  120.00

#define POLYNOMIAL 0x131   //P(x)=x^8+x^5+x^4+1 = 100110001

typedef enum {
  CHECKSUM_ERROR = 0X04
} etError;

const uint16_t i2c_timeout = 100;

void SFM3300_Init(I2C_HandleTypeDef *I2Cx)
{
    uint8_t Data;

    Data = 0x00;
    HAL_I2C_Mem_Write(I2Cx, SFM3300_ADDR, 0x20, 1, &Data, 1, i2c_timeout);
    HAL_Delay (100);

    Data = 0x00;
    HAL_I2C_Mem_Write(I2Cx, SFM3300_ADDR, 0x10, 1, &Data, 1, i2c_timeout);

    HAL_Delay (100);
}

void SFM3300_Read_Current(I2C_HandleTypeDef *I2Cx, uint8_t* data)
{
    HAL_I2C_Mem_Read(I2Cx, SFM3300_ADDR, 0x1000, 2, data, 3, i2c_timeout);
}

void SFM3300_Hard_Reset()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
	HAL_Delay (50);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
	HAL_Delay (50);
}


uint8_t SMF3300_CheckCrc (uint8_t data[], uint8_t nbrOfBytes, uint8_t checksum)
//=============================================================================
// calculates checksum for n bytes of data
// and compares it with expected checksum
// Input:       data[]      checksum is built based on this data
//              nbrOfBytes  checksum is built for n bytes of data
//              checksum    expected checksum
// Return:      error:      CHECKSUM_ERROR = checksum does not match
//                          0 = checksum matches
//=============================================================================
{
  uint8_t crc = 0;
  uint8_t byteCtr;
  // Calculates 8-Bit checksum with given polynomial
  for (byteCtr = 0; byteCtr < nbrOfBytes; ++byteCtr) {
    crc ^= (data[byteCtr]);
    for (uint8_t bit = 8; bit > 0; --bit) {
      if (crc & 0x80) crc = (crc << 1) ^ POLYNOMIAL;
      else crc = (crc << 1);
    }
  }
  if (crc != checksum)
    return CHECKSUM_ERROR;
  else
    return 0;
}

double SFM3300_ConvertRawData_to_FlowValue(uint8_t data[])
{
	double airFlow;

	uint16_t rawData = (uint16_t)(data[0] << 8) | (uint16_t)data[1];

	airFlow = ((double)rawData - SFM3300_offSet) / SFM3300_scaleFactor;

    return airFlow;
}
