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
 * File             : app.c
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */

#include "app.h"
#include "display.h"
#include "gfx.h"
#include "FreeMono12pt7b.h"
#include "stm32f4xx_hal.h"
#include<stdio.h>

extern float Temp[1];

char data[10];

uint8_t tx_buf[256 * 64 / 2];

void Display_app_init(void)
{
	 Display_init();
}

void Set_Display_buffsize(void)
{
	 set_buffer_size(256, 64);
}

void Display_refresh(void)
{
	 Set_Display_buffsize();
	 fill_buffer(tx_buf, 0);
	 send_buffer_to_OLED(tx_buf, 0, 0);
     HAL_Delay(2000);
     fill_buffer(tx_buf, 0);
}

void Display_company_name(void)
{
	select_font(&FreeMono12pt7b);
    draw_text(tx_buf, "HEALOMEX BIO", 10, 20, 15);
    draw_text(tx_buf, "SCIENCES PVT LTD", 10, 45, 15);
    send_buffer_to_OLED(tx_buf, 0, 0);
	HAL_Delay(2000);

}
void Display_contct_num(void)
{
	draw_text(tx_buf, "Contact :", 10, 20, 15);
	draw_text(tx_buf, "+91 9603966993", 10, 45, 15);
	send_buffer_to_OLED(tx_buf, 0, 0);
    HAL_Delay(2000);
}
void Display_curr_temp(void)
{
	draw_text(tx_buf, "Temp:", 10, 20, 15);
	sprintf(data,"%.2f%.f C",Temp[0],Temp[1]);
    draw_text(tx_buf, data, 80, 20, 15);
	send_buffer_to_OLED(tx_buf, 0, 0);
	HAL_Delay(2000);
}
