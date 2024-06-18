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
 * Updated on       : Apr 21, 2024
 * File             : app.c
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */

#include "app.h"
#include "display.h"
#include "gfx.h"
#include "FreeMono12pt7b.h"
#include "FreeMonoBold12pt7b.h"
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
#include "fan.h"
#include "temp.h"
#include "FreeMono9pt7b.h"
#include "rtc.h"
#include "clock.h"
#include "p_warm.h"
#include "notify.h"
#include "digit_font.h"
#include "Seven_Segment32pt7b.h"




#include<stdio.h>

UART_HandleTypeDef huart1;

button_press button_pressed;

char date[10];
char time[20];

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
     //HAL_Delay(10);
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
	select_font(&FreeMonoBold12pt7b);
	draw_bitmap_4bpp(tx_buf, matrix, 0, 0, 32, 43);
    draw_text(tx_buf, "HEALOMEX BIO", 32, 20, 15);
    draw_text(tx_buf, "SCIENCES PVT LTD", 32, 45, 15);
    send_buffer_to_OLED(tx_buf, 0, 0);
	HAL_Delay(5000);

}
void Display_contct_num(void)
{
	select_font(&FreeMonoBold12pt7b);
    draw_text(tx_buf, "CONTACT", 10, 20, 15);
	draw_text(tx_buf, "+91 9603966993", 10, 45, 15);
	send_buffer_to_OLED(tx_buf, 0, 0);
    HAL_Delay(2000);
}
void Display_Managmnt_sys(void)
{
	select_font(&FreeMono9pt7b);
	draw_text(tx_buf, "TEMPERATURE", 10, 20, 15);
	draw_bitmap_4bpp(tx_buf, p_warm, 200, 10, 40, 42);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "HMX-V01", 150, 20, 15);
	select_font(&FreeMono9pt7b);
	draw_text(tx_buf, "MANAGEMENT SYSTEM", 10, 45, 15);
	send_buffer_to_OLED(tx_buf, 0, 0);
	HAL_Delay(5000);
}

void Display_curr_temp(void)
{
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
    sprintf(data,"%.1f%.f",Temp[0],Temp[1]);
    draw_text(tx_buf, data, 5, 55, 15);
    select_font(&DSEG7_Classic_Bold_16);
    draw_text(tx_buf, "C", 148, 55, 15);
//	draw_bitmap_4bpp(tx_buf, fan_off, 200, 0, 40, 42);
	draw_bitmap_4bpp(tx_buf, fan_1gif,160,0, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 180, 0, 16, 16);
	send_buffer_to_OLED(tx_buf, 0, 0);
//	HAL_Delay(2000);
	draw_rect_filled(tx_buf,0,0,256,64,0);
//	draw_text(tx_buf, "TEMP:", 10, 20, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&DSEG7_Classic_Bold_16);
	draw_text(tx_buf, "C", 148, 55, 15);
//	draw_bitmap_4bpp(tx_buf, fan_alert, 200, 0, 40, 42);
	draw_bitmap_4bpp(tx_buf, fan_2gif, 160, 0, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 185, 0, 16, 16);
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
//	HAL_Delay(10);
//	Display_refresh();
//	draw_text(tx_buf, "TEMP:", 10, 20, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&DSEG7_Classic_Bold_16);
	draw_text(tx_buf, "C", 148, 55, 15);
//	draw_bitmap_4bpp(tx_buf, fan_low, 200, 0, 40, 42);
	draw_bitmap_4bpp(tx_buf, fan_3gif, 160, 0, 64, 64);
    send_buffer_to_OLED(tx_buf, 0, 0);
    draw_rect_filled(tx_buf,0,0,256,64,0);
//    HAL_Delay(10);
//    Display_refresh();
//    draw_text(tx_buf, "TEMP:", 10, 20, 15);
    select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
    draw_text(tx_buf, data, 5, 55, 15);
    select_font(&DSEG7_Classic_Bold_16);
    draw_text(tx_buf, "C", 148, 55, 15);
//	draw_bitmap_4bpp(tx_buf, fan_mid, 200, 0, 40, 42);
	draw_bitmap_4bpp(tx_buf, fan_4gif, 160, 0, 64, 64);
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
//	HAL_Delay(10);
//	Display_refresh();
//	draw_text(tx_buf, "TEMP:", 10, 20, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&DSEG7_Classic_Bold_16);
	draw_text(tx_buf, "C", 148, 55, 15);
//	draw_bitmap_4bpp(tx_buf, fan_high, 200, 0, 40, 42);
	draw_bitmap_4bpp(tx_buf, fan_5gif, 160, 0, 64, 64);
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
//	HAL_Delay(10);
//	Display_refresh();
//
//	draw_text(tx_buf, "TEMP:", 10, 20, 15);
//	draw_text(tx_buf, data, 80, 20, 15);
//	draw_bitmap_4bpp(tx_buf, notify, 180, 0, 16, 16);
//	send_buffer_to_OLED(tx_buf, 0, 0);
//	HAL_Delay(1000);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&DSEG7_Classic_Bold_16);
	draw_text(tx_buf, "C", 148, 55, 15);
//	draw_bitmap_4bpp(tx_buf, fan_high, 200, 0, 40, 42);
	draw_bitmap_4bpp(tx_buf, fan_6gif, 160, 0, 64, 64);
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);


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

void button_false_init()
{


	button_pressed.button_35 = false;
	button_pressed.button_40 = false;
	button_pressed.button_43 = false;
	button_pressed.button_f_low = false;
	button_pressed.button_f_mid = false;
	button_pressed.button_f_high = false;
	button_pressed.button_standby = false;
	button_pressed.button_Ambient = false;


}


void RTC_init(void)
{

MX_RTC_Init();
}

void Display_RTC_clock()
{
	RTC_interface();
	select_font(&FreeMono9pt7b);
	draw_text(tx_buf, "Device Run Time", 10, 20, 15);
	select_font(&Font5x7FixedMono);
    draw_text(tx_buf, "hh : mm", 190, 20, 15);
    select_font(&DSEG7_Classic_Bold_16);
	draw_text(tx_buf, time, 180, 45, 15);
	send_buffer_to_OLED(tx_buf, 0, 0);
	HAL_Delay(5000);


}

void display_clock_gif()
{
	Display_refresh();
	draw_bitmap_4bpp(tx_buf, clock1, 180, 0, 50, 50);
	send_buffer_to_OLED(tx_buf, 0, 0);
	//Display_refresh();
	draw_bitmap_4bpp(tx_buf, clock2, 180, 0, 50, 50);
	send_buffer_to_OLED(tx_buf, 0, 0);
	//Display_refresh();
	draw_bitmap_4bpp(tx_buf, clock3, 180, 0, 50, 50);
	send_buffer_to_OLED(tx_buf, 0, 0);
	//Display_refresh();
	draw_bitmap_4bpp(tx_buf, clock4, 180, 0, 50, 50);
	send_buffer_to_OLED(tx_buf, 0, 0);
	//Display_refresh();
	draw_bitmap_4bpp(tx_buf, clock5, 180, 0, 50, 50);
	send_buffer_to_OLED(tx_buf, 0, 0);
	//Display_refresh();
	draw_bitmap_4bpp(tx_buf, clock6, 180, 0, 50, 50);
	send_buffer_to_OLED(tx_buf, 0, 0);
	//Display_refresh();
	draw_bitmap_4bpp(tx_buf, clock7, 180, 0, 50, 50);
	send_buffer_to_OLED(tx_buf, 0, 0);
	//Display_refresh();
	draw_bitmap_4bpp(tx_buf, clock8, 180, 0, 50, 50);
	send_buffer_to_OLED(tx_buf, 0, 0);
	//Display_refresh();
	draw_bitmap_4bpp(tx_buf, clock9, 180, 0, 50, 50);
	send_buffer_to_OLED(tx_buf, 0, 0);
	//Display_refresh();
	draw_bitmap_4bpp(tx_buf, clock10, 180, 0, 50, 50);
	send_buffer_to_OLED(tx_buf, 0, 0);
	//Display_refresh();
}
