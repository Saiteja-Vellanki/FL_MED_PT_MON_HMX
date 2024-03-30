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
 * Created on       : Mar 16, 2024
 * Updated on       : Mar 16, 2024
 * File             : spi.h
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */

#ifndef INC_SPI_H_
#define INC_SPI_H_

#include "main.h"

extern SPI_HandleTypeDef hspi1;

void MX_SPI1_Init(void);


#endif /* INC_SPI_H_ */
