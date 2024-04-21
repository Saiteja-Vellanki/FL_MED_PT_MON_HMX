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



void Set_35T_Button(void)
{
	static uint8_t set_35;
	set_35=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1);
	if(set_35 == 0)
	{
	}


}

void Set_40T_Button()
{
	static uint8_t set_40;
	set_40=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);
	if(set_40 == 0)
	{
			//
	}
}

void Set_43T_Button()
{
	static uint8_t set_43;
	set_43=HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13);
	if(set_43 == 0)
	{
				//
	}
}


