/*
 * i2c.h
 *
 *  Created on: Apr 4, 2024
 *      Author: saive
 */

#ifndef INC_I2C_H_
#define INC_I2C_H_

#include "main.h"

void MX_I2C1_Init(void);
void HAL_I2C_MspInit(I2C_HandleTypeDef* hi2c);
void HAL_I2C_MspDeInit(I2C_HandleTypeDef* hi2c);


#endif /* INC_I2C_H_ */
