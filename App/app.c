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
#include "Picopixel.h"
#include "FreeSerifItalic24pt7b.h"
#include "FreeSerifItalic12pt7b.h"
#include "Font3x7FixedNum.h"
#include "Font4x5Fixed.h"
#include "segment_font.h"
#include "stm32f4xx_hal.h"
#include "log.h"
#include "led.h"
#include "gif.h"
#include "button.h"



#include<stdio.h>

UART_HandleTypeDef huart1;


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

void company_logo(void)
{
	draw_bitmap_4bpp(tx_buf, matrix, 0, 0, 32, 64);
	send_buffer_to_OLED(tx_buf, 0, 0);
	HAL_Delay(5000);

}
void gif_logo(void)
{
	draw_bitmap_4bpp(tx_buf, icon, 0, 0, 64, 64);
    send_buffer_to_OLED(tx_buf, 0, 0);
	HAL_Delay(5000);

}
void gif_logo1(void)
{
	draw_bitmap_4bpp(tx_buf, icon2, 0, 0, 32, 43);
	send_buffer_to_OLED(tx_buf, 0, 0);
	HAL_Delay(5000);

}
void Display_company_name(void)
{
	select_font(&FreeMono12pt7b);
	draw_bitmap_4bpp(tx_buf, matrix, 0, 0, 32, 43);
    draw_text(tx_buf, "HEALOMEX BIO", 32, 20, 15);
    draw_text(tx_buf, "SCIENCES PVT LTD", 32, 45, 15);
    send_buffer_to_OLED(tx_buf, 0, 0);
	HAL_Delay(5000);

}
void Display_contct_num(void)
{
	select_font(&FreeMono12pt7b);
    draw_text(tx_buf, "CONTACT :", 10, 20, 15);
	draw_text(tx_buf, "+91 9603966993", 10, 45, 15);
	send_buffer_to_OLED(tx_buf, 0, 0);
    HAL_Delay(2000);
}
void Display_Managmnt_sys(void)
{
	select_font(&FreeSans12pt7b);
	draw_text(tx_buf, "Temperature", 10, 20, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "HMX-V01", 180, 20, 15);
	select_font(&FreeSans12pt7b);
	draw_text(tx_buf, "Management System", 10, 45, 15);
	send_buffer_to_OLED(tx_buf, 0, 0);
	HAL_Delay(2000);
}

void Display_curr_temp(void)
{
	select_font(&FreeSerifItalic12pt7b);
	draw_text(tx_buf, "TEMP:", 10, 20, 15);
    sprintf(data,"%.2f%.f C",Temp[0],Temp[1]);
    draw_text(tx_buf, data, 80, 20, 15);
	send_buffer_to_OLED(tx_buf, 0, 0);
	HAL_Delay(2000);
}

void Gpio_Ex_init()
{
	Ex_gpio_init();
}

void Led_State()
{
	led_states(LED_ON);
	HAL_Delay(5000);
	led_states(LED_OFF);
	HAL_Delay(5000);

}

void Tempset_35()
{
	Set_35T_Button();
}

