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
#include "TomThumb.h"
#include <stdlib.h>
#include "Pwm.h"


#include<stdio.h>

UART_HandleTypeDef huart1;
button_press button_pressed;
TIM_HandleTypeDef htim5;
TIM_HandleTypeDef htim11;

void Display_RTC_clock();

char date[10];
char time[20];

extern float Temp[1];
char data[10];
char temp_data[20];
char day_data[20];

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
	HAL_Delay(3000);

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

void fan_Hspeed()
{
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	sprintf(data,"%.1f%.f",Temp[0],Temp[1]);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&DSEG7_Classic_Bold_16);
	draw_text(tx_buf, "C", 148, 55, 15);
	select_font(&Font5x7FixedMono);
    draw_text(tx_buf, "H",  170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_1gif,145,8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
    draw_rect_filled(tx_buf,0,0,256,64,0);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "H",  170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_2gif, 145, 8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "H",  170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_3gif, 145, 8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&DSEG7_Classic_Bold_16);
	draw_text(tx_buf, "C", 148, 55, 15);
	select_font(&Font5x7FixedMono);
    draw_text(tx_buf, "H",  170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_4gif, 145, 8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "H", 170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_5gif, 145, 8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&DSEG7_Classic_Bold_16);
	draw_text(tx_buf, "C", 148, 55, 15);
	select_font(&Font5x7FixedMono);
    draw_text(tx_buf, "H",  170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_6gif, 145, 8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);



}

void fan_Mspeed()
{
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	sprintf(data,"%.1f%.f",Temp[0],Temp[1]);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&DSEG7_Classic_Bold_16);
	draw_text(tx_buf, "C", 148, 55, 15);
	select_font(&Font5x7FixedMono);
    draw_text(tx_buf, "M", 170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_1gif,145,8, 64, 64);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
    draw_rect_filled(tx_buf,0,0,256,64,0);
	HAL_Delay(50);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "M", 170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_2gif, 145, 8, 64, 64);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	HAL_Delay(50);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "M", 170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_3gif, 145, 8, 64, 64);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
    HAL_Delay(50);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "M", 170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_4gif, 145, 8, 64, 64);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	HAL_Delay(50);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "M", 170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_5gif, 145, 8, 64, 64);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	HAL_Delay(50);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "M", 170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_6gif, 145, 8, 64, 64);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	HAL_Delay(50);


}

void fan_Lspeed()
{
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	sprintf(data,"%.1f%.f",Temp[0],Temp[1]);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "L", 170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_1gif,145,8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
    draw_rect_filled(tx_buf,0,0,256,64,0);
	HAL_Delay(100);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "L", 170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_2gif, 145, 8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	HAL_Delay(100);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "L",  170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_3gif, 145, 8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
    HAL_Delay(100);
    select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "L",  170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_4gif, 145, 8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	HAL_Delay(100);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "L",  170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_5gif, 145, 8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	HAL_Delay(100);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "C", 148, 55, 15);
    draw_text(tx_buf, "L",  170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_6gif, 145, 8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	HAL_Delay(100);


}


void Gpio_Ex_init()
{
	Ex_gpio_init();
}

void Led_State()
{
	led_states(LED_ON);
	HAL_Delay(2000);
	led_states(LED_OFF);
	HAL_Delay(2000);

}

void Tempset_35()
{
	Set_35T_Button();
}


void Tempset_40()
{
	Set_40T_Button();
}
void Tempset_43()
{
	Set_43T_Button();
}



void RTC_init(void)
{

MX_RTC_Init();
}

void Display_RTC_clock()
{
	RTC_interface();
	select_font(&Font5x7FixedMono);
    draw_text(tx_buf, "HH : MM", 210, 43, 15);
    select_font(&DSEG7_Classic_Bold_16);
    sprintf(temp_data,"%c%c%c%c%c",time[0],time[1],time[2],time[3],time[4]);
	draw_text(tx_buf, temp_data, 200, 63, 15);
    sprintf(day_data,"%c%c",time[6],time[7]);
    select_font(&Font5x7FixedMono);
    draw_text(tx_buf, "d",  243, 10, 15);
    draw_text(tx_buf, day_data,  230, 10, 15);
}

void Stand_by_init()
{
	button_pressed.button_standby = true;
}
void Stand_by_Set()
{
	if(button_pressed.button_standby)
	{
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "TEMP", 10, 10, 15);
	select_font(&Seven_Segment32pt7b);
	sprintf(data,"%.1f%.f",Temp[0],Temp[1]);
	draw_text(tx_buf, data, 5, 55, 15);
	select_font(&DSEG7_Classic_Bold_16);
	draw_text(tx_buf, "C", 148, 55, 15);
	select_font(&Font5x7FixedMono);
	draw_text(tx_buf, "X",  170, 8, 15);
	draw_bitmap_4bpp(tx_buf, fan_1gif,145,8, 64, 64);
//	draw_bitmap_4bpp(tx_buf, notify, 142, 0, 16, 16);
	Display_RTC_clock();
	send_buffer_to_OLED(tx_buf, 0, 0);
	draw_rect_filled(tx_buf,0,0,256,64,0);
	}

}

void Ambient_Set()
{
	if(button_pressed.button_Ambient)
	{
		if(button_pressed.button_f_mid)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
            fan_Mspeed();
			Motor_55_duty();
		}
		else if(button_pressed.button_f_low)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			fan_Lspeed();
			Motor_95_duty();
		}
		else if(button_pressed.button_f_high)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			fan_Hspeed();
			Motor_25_duty();
		}
		else
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
			HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 0);
			HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 0);
			HAL_TIM_PWM_Stop(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 0);
		}
	}
}

void Temp_35_Set()
{
	if(button_pressed.button_35)
	{
		if(button_pressed.button_f_mid)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
			fan_Mspeed();
			Motor_55_duty();
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 20);
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 20);
			HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 20);
		}
		else if(button_pressed.button_f_low)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
			fan_Lspeed();
			Motor_95_duty();
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 20);
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 20);
			HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 20);
		}
		else if(button_pressed.button_f_high)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
			fan_Hspeed();
			Motor_25_duty();
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 20);
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 20);
			HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 20);
		}
		else
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
			HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 0);
			HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 0);
			HAL_TIM_PWM_Stop(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 0);
		}
	}
}


void Temp_40_Set()
{
	if(button_pressed.button_40)
	{
		if(button_pressed.button_f_mid)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
			fan_Mspeed();
			Motor_55_duty();
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 40);
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 40);
			HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 40);
		}
		else if(button_pressed.button_f_low)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
			fan_Lspeed();
			Motor_95_duty();
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 40);
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 40);
			HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 40);
		}
		else if(button_pressed.button_f_high)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
			fan_Hspeed();
			Motor_25_duty();
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 40);
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 40);
			HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 40);
		}
		else
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
			HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 0);
			HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 0);
			HAL_TIM_PWM_Stop(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 0);
		}
	}
}

void Temp_45_Set()
{
	if(button_pressed.button_45)
	{
		if(button_pressed.button_f_mid)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
            fan_Mspeed();
			Motor_55_duty();
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 60);
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 60);
			HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 60);
		}
		else if(button_pressed.button_f_low)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
            fan_Lspeed();
			Motor_95_duty();
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 60);
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 60);
			HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 60);
		}
		else if(button_pressed.button_f_high)
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
			fan_Hspeed();
			Motor_25_duty();
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 60);
			HAL_TIM_PWM_Start(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 60);
			HAL_TIM_PWM_Start(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 60);
		}
		else
		{
			HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0, 0);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
			HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_3);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_3, 0);
			HAL_TIM_PWM_Stop(&htim5, TIM_CHANNEL_4);
			__HAL_TIM_SET_COMPARE(&htim5, TIM_CHANNEL_4, 0);
			HAL_TIM_PWM_Stop(&htim11, TIM_CHANNEL_1);
			__HAL_TIM_SET_COMPARE(&htim11, TIM_CHANNEL_1, 0);
		}
	}
}



