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
 * File             : fw_release.c
 *
 * STEM             : SaiTeja EMbeddedSYstems
 *
 */

#include "fw_release.h"


void fw_concat(char* fw_data, int data_break)
{

}

void fw_release(release fw_relse)
{
	uint8_t f_rel = fw_relse;
	switch(f_rel)
	{
	case HMX_RELEASE_ALPHA:
		break;
	case HMX_RELEASE_BETA:
			break;
	case HMX_RELEASE_STABLE:
			break;
	case HMX_RELEASE_FINAL:
			break;
	}
}

void fw_release_mode(release_mode fw_rels_md)
{
	uint8_t f_mode = fw_rels_md;
	switch(f_mode)
	{
	case HMX_DEBUG:
		break;
	case HMX_RELEASE:
			break;

	}
}

