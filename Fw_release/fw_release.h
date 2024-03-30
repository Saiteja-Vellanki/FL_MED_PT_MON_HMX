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
 * Created on       : Mar 17, 2024
 * Updated on       : Mar 17, 2024
 * File             : fw_release.h
 *
 * STEM             : SaiTeja EMbeddedSYstems
 *
 */

#include<stdint.h>

#ifndef FW_RELEASE_H_
#define FW_RELEASE_H_

#define FW_RELEASE      "HMX-ABSF"
#define FW_RELEASE_MODE "HMX-DR"


typedef enum
{
	HMX_RELEASE_ALPHA,
	HMX_RELEASE_BETA,
	HMX_RELEASE_STABLE,
	HMX_RELEASE_FINAL
}release;

typedef enum
{
	HMX_DEBUG,
	HMX_RELEASE
}release_mode;


void fw_release(release fw_relse);
void fw_release_mode(release_mode fw_rels_md);
void fw_concat(char* fw_data, int data_break);



#endif /* FW_RELEASE_H_ */
