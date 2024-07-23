/*
 * Author           : Saiteja Vellanki.
 * Project          : ICU patient Blanket Temperature Control->Proto
 * Programming Lang : Embedded C
 * Controller       : STM32F410RB
 * client           : TBD
 * code access      : https://github.com/Saiteja-Vellanki/FL_MED_PT_MON_STEM-001
 * Binary Path      : TBD
 * ELF Path         : https://github.com/Saiteja-Vellanki/FL_MED_PT_MON_STEM-001/tree/master/Debug/FL_MED_PT_MON_STEM-001.elf
 *
 *
 * Created on       : Mar 16, 2024
 * Updated on       : Mar 16, 2024
 * File             : gpio.c
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */

#include "gpio.h"

void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

//  __HAL_RCC_SYSCFG_CLK_ENABLE();
  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);

    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
//
//  /*Configure GPIO pin : B1_Pin */
//  GPIO_InitStruct.Pin = B1_Pin;
//  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
//  GPIO_InitStruct.Pull = GPIO_NOPULL;
//  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);
//


  /*Configure GPIO pins : PC4 PC5 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = /*GPIO_PIN_1|*/GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14
                            |GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
//      HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);


    /*Configure GPIO pin : PA11 */
    GPIO_InitStruct.Pin = GPIO_PIN_11;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pin : PC10 */
    GPIO_InitStruct.Pin =  GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7
    		              | GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING_FALLING;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
    /* EXTI interrupt init*/
       HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
       HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

//       HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
//         HAL_NVIC_EnableIRQ(EXTI2_IRQn);
//
//         HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
//         HAL_NVIC_EnableIRQ(EXTI3_IRQn);

//    GPIO_InitStruct.Pin = GPIO_PIN_8;
//       GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
//       GPIO_InitStruct.Pull = GPIO_PULLUP;
//       HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
  GPIO_InitStruct.Pin = GPIO_PIN_4 | GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


//
//  //Configure GPIO pin : PB9 (TIM11 CH1)
//      GPIO_InitStruct.Pin = GPIO_PIN_9;
//      GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//      GPIO_InitStruct.Pull = GPIO_NOPULL;
//      GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
//      GPIO_InitStruct.Alternate = GPIO_AF3_TIM11;
//      HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//
//      //Configure GPIO pins : PC11 (TIM5 CH3) and PB11 (TIM5 CH4)
//      GPIO_InitStruct.Pin = GPIO_PIN_11;
//      GPIO_InitStruct.Alternate = GPIO_AF2_TIM5;
//      HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
//
//      GPIO_InitStruct.Pin = GPIO_PIN_11;
//      HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
//

}



