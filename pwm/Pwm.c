/*
 * Pwm.c
 *
 *  Created on: Jul 7, 2024
 *      Author: saive
 */

#include "pwm.h"


TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim11;
extern TIM_HandleTypeDef htim5;


/**
  * @brief TIM5 Initialization Function
  * @param None
  * @retval None
  */
void MX_TIM5_Init(void)
{

  /* USER CODE BEGIN TIM5_Init 0 */

  /* USER CODE END TIM5_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM5_Init 1 */

  /* USER CODE END TIM5_Init 1 */
  htim5.Instance = TIM5;
  htim5.Init.Prescaler = 50-1;
  htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim5.Init.Period = 200-1;
  htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim5) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim5, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM2;
  if (HAL_TIM_PWM_ConfigChannel(&htim5, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM5_Init 2 */

  /* USER CODE END TIM5_Init 2 */
  HAL_TIM_MspPostInit(&htim5);

}

/**
  * @brief TIM11 Initialization Function
  * @param None
  * @retval None
  */
void MX_TIM11_Init(void)
{

  /* USER CODE BEGIN TIM11_Init 0 */

  /* USER CODE END TIM11_Init 0 */

  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM11_Init 1 */

  /* USER CODE END TIM11_Init 1 */
  htim11.Instance = TIM11;
  htim11.Init.Prescaler = 50-1;
  htim11.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim11.Init.Period = 200-1;
  htim11.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim11.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim11) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim11) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim11, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM11_Init 2 */

  /* USER CODE END TIM11_Init 2 */
  HAL_TIM_MspPostInit(&htim11);

}

void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 50-1;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 200-1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

//
////For 25% duty-cycle
//void Motor_25_duty ()
//{
//	TIM1->CCR1 = 50;
//	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//	HAL_Delay(500);
//}
//
//
////For 35% duty-cycle
//void Motor_35_duty ()
//{
//	TIM1->CCR1 = 70;
//	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//	HAL_Delay(500);
//}
//
//
////For 45% duty-cycle
//void Motor_45_duty ()
//{
//	TIM1->CCR1 = 90;
//	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//	HAL_Delay(500);
//}
//
//
//
////For 55% duty-cycle
//void Motor_55_duty ()
//{
//	TIM1->CCR1 = 110;
//	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//	HAL_Delay(500);
//}
//
////For 65% duty-cycle
//void Motor_65_duty ()
//{
//	TIM1->CCR1 = 130;
//	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//	HAL_Delay(500);
//}
//
////For 75% duty-cycle
//void Motor_75_duty ()
//{
//	TIM1->CCR1 = 150;
//	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//	HAL_Delay(500);
//}
//
////For 85% duty-cycle
//void Motor_85_duty ()
//{
//	TIM1->CCR1 = 170;
//	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//	HAL_Delay(500);
//}
//
////For 95% duty-cycle
//void Motor_95_duty ()
//{
//	TIM1->CCR1 = 190;
//	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
//	HAL_Delay(500);
//}


void Motor_25_duty ()
{
	TIM1->CCR1 = 50;


	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

}


//For 35% duty-cycle
void Motor_35_duty ()
{
	TIM1->CCR1 = 70;

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

}


//For 45% duty-cycle
void Motor_45_duty ()
{
	TIM1->CCR1 = 90;

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

}



//For 55% duty-cycle
void Motor_55_duty ()
{
	TIM1->CCR1 = 110;

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

}

//For 65% duty-cycle
void Motor_65_duty ()
{
	TIM1->CCR1 = 130;

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

}

//For 75% duty-cycle
void Motor_75_duty ()
{
	TIM1->CCR1 = 150;

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

}

//For 85% duty-cycle
void Motor_85_duty ()
{
	TIM1->CCR1 = 170;

	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

}

//For 95% duty-cycle
void Motor_95_duty ()
{
	TIM1->CCR1 = 190;
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);

}

