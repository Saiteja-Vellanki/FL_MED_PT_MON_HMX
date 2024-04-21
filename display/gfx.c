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
 * Created on       : Mar 14, 2024
 * Updated on       : Mar 14, 2024
 * File             : gfx.c
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */

#include "gfx.h"
#include "display.h"


#include <stdlib.h>
#include <math.h>

const GFXfont *gfx_font = NULL;     //pointer to Adafruit font that is currently selected

uint16_t _buffer_height = 64;       //buffer dimensions used to determine if pixel is within array bounds
uint16_t _buffer_width = 256;      //by default buffer size is equal to OLED size

void set_buffer_size(uint16_t _buffer_width, uint16_t buffer_height)
{
	_buffer_height = buffer_height;
	_buffer_width = _buffer_width;
}

void fill_buffer(uint8_t *frame_buffer, uint8_t brightness)
{
	uint8_t byte_value = (brightness << 4) | brightness;
	uint32_t buffer_size = _buffer_height * _buffer_width / 2;
	while (buffer_size--)
	{
		*frame_buffer++ = byte_value;
	}
}

void draw_pixel(uint8_t *frame_buffer, uint16_t x, uint16_t y, uint8_t brightness)
{
	if(x > (_buffer_width-1) || y > (_buffer_height-1))
		return;

	if ((y * _buffer_width + x) % 2 == 1)
	{
		frame_buffer[((y * _buffer_width) + x) / 2] = (frame_buffer[((y * _buffer_width) + x) / 2] & 0xF0) | brightness;
	}
	else
	{
		frame_buffer[((y * _buffer_width) + x) / 2] = (frame_buffer[((y * _buffer_width) + x) / 2] & 0x0F) | (brightness << 4);
	}
}

void select_font(const GFXfont *new_gfx_font)
{
	gfx_font = new_gfx_font;
}

void draw_char(uint8_t *frame_buffer, uint8_t c, uint16_t x, uint16_t y, uint8_t brightness)
{
	if(gfx_font == NULL)
		return;

	c -= (uint8_t)gfx_font->first;          //convert input char to corresponding byte from font array
    GFXglyph *glyph = gfx_font->glyph + c;  //get pointer of glyph corresponding to char
    uint8_t *bitmap = gfx_font->bitmap;     //get pointer of char bitmap

    uint16_t bo = glyph->bitmapOffset;
    uint8_t width = glyph->width;
    uint8_t height = glyph->height;

    int8_t x_offset = glyph->xOffset;
    int8_t y_offset = glyph->yOffset;

    //decide for background brightness or font brightness
    uint8_t bit = 0;
    uint8_t bits = 0;
    uint8_t y_pos = 0;
    uint8_t x_pos = 0;

	for (y_pos = 0; y_pos < height; y_pos++)
	{
		for (x_pos = 0; x_pos < width; x_pos++)
		{
			if (!(bit++ & 7))
			{
				bits = (*(const unsigned char *)(&bitmap[bo++]));
			}
			if (bits & 0x80)
			{
				draw_pixel(frame_buffer, x + x_offset + x_pos, y + y_offset+y_pos, brightness);
			}
			else
			{

			}
			bits <<= 1;
		}
	}
}

void draw_text(uint8_t *frame_buffer, const char* text, uint16_t x, uint16_t y, uint8_t brightness)
{
    while (*text)
    {
        draw_char(frame_buffer, *text, x, y, brightness);
        x = x + gfx_font->glyph[*text-32].xAdvance;
        text++;
    }
}

//void DrawBitmap(int16_t x, int16_t y, const unsigned char* bitmap, int16_t w, int16_t h, uint16_t brightness)
//{
//
//    int16_t byteWidth = (w + 7) / 8; // Bitmap scanline pad = whole byte
//    uint8_t byte = 0;
//
//    for(int16_t j=0; j<h; j++, y++)
//    {
//        for(int16_t i=0; i<w; i++)
//        {
//            if(i & 7)
//            {
//               byte <<= 1;
//            }
//            else
//            {
//               byte = (*(const unsigned char *)(&bitmap[j * byteWidth + i / 8]));
//            }
//            if(byte & 0x80) draw_pixel(bitmap,x+i, y, brightness);
//        }
//    }
//}
//


void draw_bitmap_8bpp(uint8_t *frame_buffer, const uint8_t *bitmap, uint16_t x0, uint16_t y0, uint16_t x_size, uint16_t y_size)
{
	uint16_t bitmap_pos = 0;

	for (uint16_t i = y0; i < y0 + y_size; i++)
	{
		for (uint16_t j = x0; j < x0 + x_size; j++)
		{
			draw_pixel(frame_buffer, j, i, bitmap[bitmap_pos] >> 4);
			bitmap_pos++;
		}
	}
}

void draw_bitmap_4bpp(uint8_t *frame_buffer, const uint8_t *bitmap, uint16_t x0, uint16_t y0, uint16_t x_size, uint16_t y_size)
{
	uint16_t bitmap_pos = 0;       //byte index in bitmap array
	uint16_t processed_pixels = 0;
	uint8_t pixel_parity = 0;      //if pixel is even = 0; odd = 1

	for (uint16_t i = y0; i < y0 + y_size; i++)
	{
		for (uint16_t j = x0; j < x0 + x_size; j++)
		{
			pixel_parity = processed_pixels % 2;

			if(pixel_parity == 0)
			{
				draw_pixel(frame_buffer, j, i, bitmap[bitmap_pos] >> 4);
				processed_pixels++;
			}
			else
			{
				draw_pixel(frame_buffer, j, i, bitmap[bitmap_pos]);
				processed_pixels++;
				bitmap_pos++;
			}
		}
	}
}

void send_buffer_to_OLED(uint8_t *frame_buffer, uint16_t start_x, uint16_t start_y)
{
	Display_set_window(0, 63, 0, 127);
	Send_buffer(frame_buffer + (start_y * OLED_WIDTH / 2) + start_x, 8192);
}
