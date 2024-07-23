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
 * Updated on       : Apr 9, 2024
 * File             : led.h
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */

#ifndef __LED_H
#define __LED_H

#include "error.h"
#include<stdint.h>
#include "ioexpansion.h"


typedef enum
{
	LED_OFF   = 0x00,
	LED_ON    = 0x01,
	LED_BLINK = 0x02
}led_state;


void Ex_gpio_write(uint8_t pin, GPIO_PinState pinState);
uint8_t led_states(led_state state);

void Ex_gpio_init(void);

void Tempset_35_led(void);
void Tempset_40_led(void);
void Tempset_43_led(void);

void Fanset_low_led(void);
void Fanset_mid_led(void);
void Fanset_high_led(void);



void Tempset_amb_led(void);
void Standbyset_led(void);


void TempReset_35_led(void);
void TempReset_40_led(void);
void TempReset_43_led(void);

void FanReset_low_led(void);
void FanReset_mid_led(void);
void FanReset_high_led(void);



void TempReset_amb_led(void);
void Standbyset_led(void);
void StandbyReset_led(void);




#endif
