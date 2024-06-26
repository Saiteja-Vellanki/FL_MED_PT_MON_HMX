/*
 * rtc.c
 *
 *  Created on: Apr 20, 2024
 *      Author: saive
 */


#include<stdio.h>
#include<string.h>
#include<stdint.h>

#include"main.h"
#include"rtc.h"


RTC_HandleTypeDef hrtc;

RTC_TimeTypeDef sTime;
RTC_DateTypeDef sDate;


extern char date[10];
extern char time[20];

void RTC_interface ()
{



		HAL_RTC_GetDate(&hrtc, &sDate, RTC_FORMAT_BIN);
		HAL_RTC_GetTime(&hrtc, &sTime, RTC_FORMAT_BIN);


		//sprintf(date,"Date: %d:%d:%d",sDate.Date,sDate.Month,sDate.Year);
		sprintf(time, "%02d:%02d:%02d",sTime.Hours,sTime.Minutes,sDate.Date);


		//HAL_Delay(500);



}




 /**
   * @brief RTC Initialization Function
   * @param None
   * @retval None
   */
  void MX_RTC_Init(void)
 {

   /* USER CODE BEGIN RTC_Init 0 */

   /* USER CODE END RTC_Init 0 */

   RTC_TimeTypeDef sTime = {0};
   RTC_DateTypeDef sDate = {0};

   /* USER CODE BEGIN RTC_Init 1 */

   /* USER CODE END RTC_Init 1 */

   /** Initialize RTC Only
   */
   hrtc.Instance = RTC;
   hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
   hrtc.Init.AsynchPrediv = 127;
   hrtc.Init.SynchPrediv = 255;
   hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
   hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
   hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
   if (HAL_RTC_Init(&hrtc) != HAL_OK)
   {
     Error_Handler();
   }

   /* USER CODE BEGIN Check_RTC_BKUP */

   /* USER CODE END Check_RTC_BKUP */

   /** Initialize RTC and set the Time and Date
   */
   sTime.Hours = 0x00;
   sTime.Minutes = 0x00;
   sTime.Seconds = 0x00;
   sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
   sTime.StoreOperation = RTC_STOREOPERATION_RESET;
   if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
   {
     Error_Handler();
   }
   sDate.WeekDay = RTC_WEEKDAY_SATURDAY;
   sDate.Month = 0x00;
   sDate.Date = 0x00;
   sDate.Year = 0x0;

   if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
   {
     Error_Handler();
   }
   /* USER CODE BEGIN RTC_Init 2 */

   /* USER CODE END RTC_Init 2 */

 }
