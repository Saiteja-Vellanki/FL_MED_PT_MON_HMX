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
 * File             : button.h
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */


#ifndef __BUTTON_H
#define __BUTTON_H


#include "error.h"
#include<stdint.h>

#define false 0
#define true  1

typedef void Gpio_state(void);

void Button_switches();
typedef struct buttons
{
	Gpio_state *gpio_st;
	uint8_t button_35 :1;
	uint8_t button_40 :1;
	uint8_t button_45 :1;
	uint8_t button_f_low :1;
	uint8_t button_f_mid :1;
	uint8_t button_f_high :1;
	uint8_t button_standby :1;
	uint8_t button_Ambient :1;

}button_press;

void button_false_init();


void temp_35(button_press *button_pres);


void Set_35T_Button();
void Set_40T_Button();
void Set_43T_Button();







#endif
