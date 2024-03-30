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
 * File             : error.h
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */

#ifndef __ERROR_H
#define __ERROR_H



typedef enum
{
	SYSTEM_ERR = 0x01,
	LED_ERR    = 0x02,
	TEMP_ERR   = 0x03,
	DISP_ERR   = 0x04,
	MOTOR_ERR  = 0x05,

	SYSTEM_OK = 0x06,
	LED_OK    = 0x07,
	TEMP_OK   = 0x08,
	DISP_OK   = 0x09,
	MOTOR_OK  = 0x0A

}err_code;









#endif
