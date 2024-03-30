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
 * Created on       : Mar 7, 2024
 * Updated on       :
 * File             : led.c
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */


#include "led.h"



uint8_t led_states(led_state state)
{
  uint8_t led_status = state;

  switch(led_status)
  {
      case LED_OFF:
	      break;
      case LED_ON:
      	  break;
      case LED_BLINK:
           break;

  }
  return LED_OK;
}
