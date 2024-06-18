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
 * Created on       : Mar 30, 2024
 * Updated on       : Mar 30, 2024
 * File             : app.h
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */

#ifndef APP_H_
#define APP_H_
#include<stdint.h>

#define false 0
#define true  1

typedef void Gpio_state(void);


typedef struct buttons
{
	Gpio_state *gpio_st;
	uint8_t button_35 :1;
	uint8_t button_40 :1;
	uint8_t button_43 :1;
	uint8_t button_f_low :1;
	uint8_t button_f_mid :1;
	uint8_t button_f_high :1;
	uint8_t button_standby :1;
	uint8_t button_Ambient :1;

}button_press;

void temp_35(button_press *button_pres);

void button_false_init();

void Gpio_Ex_init();
void Display_app_init(void);
void Set_Display_buffsize(void);
void Display_refresh(void);
void Display_company_name(void);
void Display_contct_num(void);
void Display_curr_temp(void);
void gif_logo(void);
void gif_logo1(void);
void company_logo(void);
void Display_Managmnt_sys(void);
void Tempset_35(void);
void Tempset_40(void);
void Tempset_43(void);
void Led_State(void);
void Display_RTC_clock(void);
void RTC_init(void);
void display_clock_gif(void);



#endif /* APP_H_ */
