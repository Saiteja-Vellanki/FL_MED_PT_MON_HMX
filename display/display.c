/*
 * Author           : Saiteja Vellanki.
 * Project          : ICU patient Blanket Temperature Control->Proto
 * Programming Lang : Embedded C
 * Controller       : STM32F410RB
 * client           : TBD
 * code access      : https://github.com/Saiteja-Vellanki/FL_MED_PT_MON_HMX
 * Binary Path      : https://github.com/Saiteja-Vellanki/FL_MED_PT_MON_HMX/blob/master/Debug/FL_MED_PT_MON_HMX.bin
 * ELF Path         : https://github.com/Saiteja-Vellanki/FL_MED_PT_MON_HMX/blob/master/Debug/FL_MED_PT_MON_HMX.elf
 *
 *
 * Created on       : Mar 7, 2024
 * Updated on       : Mar 13, 2024
 * File             : display.c
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */


#include "display.h"
#include "main.h"
#include "spi.h"
#include "stm32f4xx_hal.h"




void Drive_CS_low()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
}


void Drive_CS_high()
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
}


void Drive_DC_low()
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 0);
}


void Drive_DC_high()
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_4, 1);
}


void Drive_RESET_low()
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 0);
}


void Drive_RESET_high()
{
	HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, 1);
}


void SPI_send_byte(uint8_t byte_to_transmit)
{
	HAL_SPI_Transmit(&hspi1, &byte_to_transmit, 1, 10);
}


void SPI_send_array(uint8_t *array_to_transmit, uint32_t array_size)
{
	HAL_SPI_Transmit(&hspi1, array_to_transmit, array_size, 100);
}


void msDelay(uint32_t milliseconds)
{
	HAL_Delay(milliseconds);
}


void Display_command(uint8_t command)
{
	Drive_CS_low();
	Drive_DC_low();
	SPI_send_byte(command);
	Drive_CS_high();
}

void Display_data(uint8_t data)
{
	Drive_CS_low();
	Drive_DC_high();
	SPI_send_byte(data);
	Drive_CS_high();
}

//====================== initialization sequence ========================//
/**
 *  @brief Initializes SSD1322 OLED display.
 */
void Display_init()
{
	Drive_RESET_low();
	msDelay(1);
	Drive_RESET_high();
	msDelay(50);
	Display_command(0xFD);
	Display_data(0x12);
	Display_command(0xAE);
	Display_command(0xB3);
	Display_data(0x91);
	Display_command(0xCA);
	Display_data(0x3F);
	Display_command(0xA2);
	Display_data(0x00);
	Display_command(0xA1);
	Display_data(0x00);
	Display_command(0xA0);
	Display_data(0x14);
	Display_data(0x11);
	Display_command(0xB5);
	Display_data(0x00);
	Display_command(0xAB);
	Display_data(0x01);
	Display_command(0xB4);
	Display_data(0xA0);
	Display_data(0xFD);
	Display_command(0xC1);
	Display_data(0xFF);
	Display_command(0xC7);
	Display_data(0x0F);
	Display_command(0xB9);
	Display_command(0xB1);
	Display_data(0xE2);
	Display_command(0xD1);
	Display_data(0x82);
	Display_data(0x20);
	Display_command(0xBB);
	Display_data(0x1F);
	Display_command(0xB6);
	Display_data(0x08);
	Display_command(0xBE);
	Display_data(0x07);
	Display_command(0xA6);
	Display_command(0xA9);
	msDelay(10);
	Display_command(0xAF);
	msDelay(50);
}



void Set_display_mode(enum SSD1322_mode_e mode)
{
	switch (mode)
	{
	case SSD1322_MODE_NORMAL:
		Display_command(SET_DISP_MODE_NORMAL);
		break;
	case SSD1322_MODE_INVERTED:
		Display_command(SET_DISP_MODE_INVERTED);
		break;
	case SSD1322_MODE_ON:
		Display_command(SET_DISP_MODE_ON);
		break;
	case SSD1322_MODE_OFF:
		Display_command(SET_DISP_MODE_OFF);
		break;
	}
}


void Display_sleep_on()
{
	Display_command(SLEEP_MODE_ON);
}


void Display_sleep_off()
{
	Display_command(SLEEP_MODE_OFF);
}


void Display_set_contrast(uint8_t contrast)
{
	Display_command(SET_CONTRAST_CURRENT);
	Display_data(contrast);
}


void Display_set_brightness(uint8_t brightness)
{
	Display_command(MASTER_CONTRAST_CURRENT);
	Display_data(0x0F & brightness);            //first 4 bits have to be 0
}


uint8_t Display_custom_grayscale(uint8_t *grayscale_tab)
{
	Display_command(SET_GRAYSCALE_TABLE);
	for(int i = 0; i < 16; i++)
	{
		if(grayscale_tab[i] > 180)
			return 0;
		Display_data(grayscale_tab[i]);
	}
	Display_command(ENABLE_GRAYSCALE_TABLE);
	return 1;
}


void Display_default_grayscale()
{
	Display_command(SET_DEFAULT_GRAYSCALE_TAB);
}


void Display_set_window(uint8_t start_column, uint8_t end_column, uint8_t start_row, uint8_t end_row)
{
	Display_command(SET_COLUMN_ADDR);  //set columns range
	Display_data(28+start_column);
	Display_data(28+end_column);
	Display_command(SET_ROW_ADDR);  //set rows range
	Display_data(start_row);
	Display_data(end_row);
}


void Send_buffer(uint8_t* buffer, uint32_t buffer_size)
{
	Display_command(ENABLE_RAM_WRITE);  //enable write of pixels
	Drive_CS_low();
	Drive_DC_high();
	SPI_send_array(buffer, buffer_size);
	Drive_CS_high();
}
