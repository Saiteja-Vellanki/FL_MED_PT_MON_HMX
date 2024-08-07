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
void Led_State(void);
void Display_RTC_clock(void);
void RTC_init(void);
void Stand_by_init();
void Stand_by_Set();
void Ambient_Set();
void Temp_35_Set();
void Temp_40_Set();
void Temp_45_Set();



#endif /* APP_H_ */
