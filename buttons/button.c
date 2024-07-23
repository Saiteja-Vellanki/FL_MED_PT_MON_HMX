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
 * Created on       : Mar 8, 2024
 * Updated on       :
 * File             : button.c
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */



#include "button.h"
#include<stdint.h>
#include "gpio.h"
#include "led.h"

extern button_press button_pressed;


void button_false_init()
{


	button_pressed.button_35 = false;
	button_pressed.button_40 = false;
	button_pressed.button_45 = false;
	button_pressed.button_f_low = false;
	button_pressed.button_f_mid = false;
	button_pressed.button_f_high = false;
	button_pressed.button_standby = false;
	button_pressed.button_Ambient = false;


}


//void EXTI2_IRQHandler(void)
//{
///* USER CODE BEGIN EXTI2_IRQn 0 */
//
///* USER CODE END EXTI2_IRQn 0 */
//HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_2);
//	Standbyset_led();
//       		FanReset_low_led();
///* USER CODE BEGIN EXTI2_IRQn 1 */
//
///* USER CODE END EXTI2_IRQn 1 */
//}
//
///**
//* @brief This function handles EXTI line3 interrupt.
//*/
//void EXTI3_IRQHandler(void)
//{
///* USER CODE BEGIN EXTI3_IRQn 0 */
//
///* USER CODE END EXTI3_IRQn 0 */
//HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_3);
//      	StandbyReset_led();
//           		Fanset_low_led();
//
//   //        		FanReset_mid_led();
//   //        		FanReset_high_led();
//           // Handle PC9 interrupt
//
//
////                   	Tempset_35_led();
////                       TempReset_40_led();
////                       TempReset_43_led();
////                   	TempReset_amb_led();
//
//
//      //        		FanReset_low_led();
//      //        		FanReset_mid_led();
//      //        		FanReset_high_led();
//              // Handle PC9 interrupt
//
///* USER CODE BEGIN EXTI3_IRQn 1 */
//
///* USER CODE END EXTI3_IRQn 1 */
//}


/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */


//// Callback function called by HAL_GPIO_EXTI_IRQHandler
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
//    if (GPIO_Pin == GPIO_PIN_9) {
//        // Handle the interrupt
//    	Tempset_35_led();
//        TempReset_40_led();
//        TempReset_43_led();
//    	TempReset_amb_led();
//    	StandbyReset_led();
////		FanReset_low_led();
////		FanReset_mid_led();
////		FanReset_high_led();
//
//
//
//        // This is where you place your code to handle the event
//    }
//
//    if (GPIO_Pin == GPIO_PIN_8) {
//           // Handle the interrupt
//    	Tempset_40_led();
//    	TempReset_35_led();
//        TempReset_43_led();
//    	TempReset_amb_led();
//    	StandbyReset_led();
////		FanReset_low_led();
////		FanReset_mid_led();
////		FanReset_high_led();
//
//
//
//
//
//           // This is where you place your code to handle the event
//       }
//    if (GPIO_Pin == GPIO_PIN_7) {
//            // Handle the interrupt
//        	Tempset_43_led();
//        	TempReset_40_led();
//        	TempReset_35_led();
//        	TempReset_amb_led();
//        	StandbyReset_led();
////			FanReset_low_led();
////			FanReset_mid_led();
////			FanReset_high_led();
//
//
//            // This is where you place your code to handle the event
//        }
//
//    if (GPIO_Pin == GPIO_PIN_6) {
//                // Handle the interrupt
//    	        Tempset_amb_led();
//            	TempReset_43_led();
//            	TempReset_40_led();
//            	TempReset_35_led();
//            	StandbyReset_led();
////				FanReset_low_led();
////				FanReset_mid_led();
////				FanReset_high_led();
//
//
//                // This is where you place your code to handle the event
//            }
//    if (GPIO_Pin == GPIO_PIN_15) {
//            // Handle the interrupt
//        	TempReset_35_led();
//            TempReset_40_led();
//            TempReset_43_led();
//        	TempReset_amb_led();
//        	Standbyset_led();
//        	FanReset_low_led();
//			FanReset_high_led();
//            FanReset_mid_led();
//
//
//            // This is where you place your code to handle the event
//        }
//
//        if (GPIO_Pin == GPIO_PIN_14) {
//               // Handle the interrupt
//        	TempReset_35_led();
//			TempReset_40_led();
//			TempReset_43_led();
//			TempReset_amb_led();
//			StandbyReset_led();
//			FanReset_mid_led();
//			FanReset_high_led();
//			Fanset_low_led();
//
//
//
//
//
//               // This is where you place your code to handle the event
//           }
//        if (GPIO_Pin == GPIO_PIN_13) {
//        	TempReset_35_led();
//			TempReset_40_led();
//			TempReset_43_led();
//			TempReset_amb_led();
//			StandbyReset_led();
//			FanReset_low_led();
//			FanReset_high_led();
//			Fanset_mid_led();
//                // This is where you place your code to handle the event
//            }
//
//        if (GPIO_Pin == GPIO_PIN_12) {
//                    // Handle the interrupt
//        	TempReset_35_led();
//			TempReset_40_led();
//			TempReset_43_led();
//			TempReset_amb_led();
//			StandbyReset_led();
//			FanReset_low_led();
//			FanReset_mid_led();
//			Fanset_high_led();
//                    // This is where you place your code to handle the event
//                }
//}

void EXTI9_5_IRQHandler(void) {
    // Check which pin triggered the interrupt and handle accordingly
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_6) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_6);
                    Tempset_amb_led();
                   	TempReset_43_led();
                   	TempReset_40_led();
                   	TempReset_35_led();
                   	StandbyReset_led();
                   	button_pressed.button_Ambient = true;
                 	button_pressed.button_35 = false;
                 	button_pressed.button_40 = false;
                 	button_pressed.button_45 = false;
                 	button_pressed.button_standby = false;




    }
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_7) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_7);
    	        Tempset_43_led();
            	TempReset_40_led();
            	TempReset_35_led();
            	TempReset_amb_led();
            	StandbyReset_led();
            	button_pressed.button_Ambient = false;
				button_pressed.button_35 = false;
				button_pressed.button_40 = false;
				button_pressed.button_45 = true;
				button_pressed.button_standby = false;
        // Handle PC7 interrupt
    }
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_8) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_8);
            	Tempset_40_led();
            	TempReset_35_led();
                TempReset_43_led();
            	TempReset_amb_led();
            	StandbyReset_led();
            	button_pressed.button_Ambient = false;
				button_pressed.button_35 = false;
				button_pressed.button_40 = true;
				button_pressed.button_45 = false;
				button_pressed.button_standby = false;
    }
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_9) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_9);
            	Tempset_35_led();
                TempReset_40_led();
                TempReset_43_led();
            	TempReset_amb_led();
            	StandbyReset_led();
            	button_pressed.button_Ambient = false;
				button_pressed.button_35 = true;
				button_pressed.button_40 = false;
				button_pressed.button_45 = false;
				button_pressed.button_standby = false;
    }

}

////// EXTI line[15:10] interrupt handler
void EXTI15_10_IRQHandler(void) {
    // Check which pin triggered the interrupt and handle accordingly
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_12) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_12);
        			StandbyReset_led();
        			FanReset_low_led();
        			FanReset_mid_led();
        			Fanset_high_led();
        			button_pressed.button_f_high = true;
					button_pressed.button_f_low = false;
					button_pressed.button_f_mid = false;
					button_pressed.button_standby = false;
        // Handle PB12 interrupt
    }
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_13) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_13);
    			StandbyReset_led();
    			FanReset_low_led();
    			FanReset_high_led();
    			Fanset_mid_led();
    			button_pressed.button_f_high = false;
				button_pressed.button_f_low = false;
				button_pressed.button_f_mid = true;
				button_pressed.button_standby = false;
        // Handle PB13 interrupt
    }
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_14) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_14);
        			StandbyReset_led();
        			FanReset_mid_led();
        			FanReset_high_led();
        			Fanset_low_led();
        			button_pressed.button_f_high = false;
					button_pressed.button_f_low = true;
					button_pressed.button_f_mid = false;
					button_pressed.button_standby = false;

        // Handle PB14 interrupt
    }
    if (__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_15) != RESET) {
        __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_15);
                	Standbyset_led();
                	FanReset_low_led();
        			FanReset_high_led();
                    FanReset_mid_led();
                    button_pressed.button_f_high = false;
					button_pressed.button_f_low = false;
					button_pressed.button_f_mid = false;
					button_pressed.button_standby = true;
        // Handle PB15 interrupt
    }
}
//
//

