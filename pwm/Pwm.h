/*
 * Pwm.h
 *
 *  Created on: Jul 7, 2024
 *      Author: saive
 */

#ifndef PWM_H_
#define PWM_H_

#include "main.h"


void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

void MX_TIM1_Init(void);

void Motor_25_duty ();

void Motor_35_duty ();

void Motor_45_duty ();

void Motor_55_duty ();

void Motor_65_duty ();

void Motor_75_duty ();

void Motor_85_duty ();

void Motor_95_duty ();


#endif /* PWM_H_ */
