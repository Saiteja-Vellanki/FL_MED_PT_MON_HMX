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
 * Created on       : Mar 7, 2024
 * Updated on       :
 * File             : led.c
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */


#include "led.h"


MCP23017_HandleTypeDef hmcp;


void Ex_gpio_init(void)
{
	mcp23017_init(&hmcp, &hi2c1, MCP23017_ADD_27);
	mcp23017_portMode(&hmcp, MCP23017Port_A, MCP23017_PIN_MODE_OUTPUT,MCP23017_PIN_POLARITY_NORMAL);
	mcp23017_portMode(&hmcp, MCP23017Port_B, MCP23017_PIN_MODE_OUTPUT,MCP23017_PIN_POLARITY_NORMAL);
	mcp23017_pinMode(&hmcp,MCP23017_GPB0_Pin | MCP23017_GPB1_Pin | MCP23017_GPB2_Pin,MCP23017_PIN_MODE_OUTPUT,MCP23017_PIN_POLARITY_NORMAL);
    mcp23017_pinMode(&hmcp,MCP23017_GPB3_Pin,MCP23017_PIN_MODE_OUTPUT,MCP23017_PIN_POLARITY_NORMAL);
	mcp23017_pinMode(&hmcp,MCP23017_GPA0_Pin | MCP23017_GPA1_Pin | MCP23017_GPA2_Pin,MCP23017_PIN_MODE_OUTPUT,MCP23017_PIN_POLARITY_NORMAL);
	mcp23017_pinMode(&hmcp,MCP23017_GPA3_Pin | MCP23017_GPA4_Pin | MCP23017_GPA5_Pin,MCP23017_PIN_MODE_OUTPUT,MCP23017_PIN_POLARITY_NORMAL);
	mcp23017_pinMode(&hmcp,MCP23017_GPA6_Pin | MCP23017_GPA7_Pin ,MCP23017_PIN_MODE_OUTPUT,MCP23017_PIN_POLARITY_NORMAL);

}
void Ex_gpio_write(uint8_t pin, GPIO_PinState pinState)
{
    mcp23017_digitalWrite(&hmcp,pin,pinState);

}

void Tempset_35_led(void)
{
	Ex_gpio_write(MCP23017_GPA0_Pin,GPIO_PIN_SET);
}
void Tempset_40_led(void)
{
	Ex_gpio_write(MCP23017_GPA1_Pin,GPIO_PIN_SET);
}
void Tempset_43_led(void)
{
	Ex_gpio_write(MCP23017_GPA2_Pin,GPIO_PIN_SET);
}


void Fanset_low_led()
{
    Ex_gpio_write(MCP23017_GPA3_Pin,GPIO_PIN_SET);

}

void Fanset_mid_led()
{
    Ex_gpio_write(MCP23017_GPA4_Pin,GPIO_PIN_SET);

}

void Fanset_high_led()
{
    Ex_gpio_write(MCP23017_GPA5_Pin,GPIO_PIN_SET);

}
void Tempset_amb_led(void)
{
  Ex_gpio_write(MCP23017_GPA6_Pin,GPIO_PIN_SET);

}
void Standbyset_led(void)
{
   Ex_gpio_write(MCP23017_GPA7_Pin,GPIO_PIN_SET);

}
void TempReset_35_led(void)
{
	Ex_gpio_write(MCP23017_GPA0_Pin,GPIO_PIN_RESET);
}
void TempReset_40_led(void)
{
	Ex_gpio_write(MCP23017_GPA1_Pin,GPIO_PIN_RESET);
}
void TempReset_43_led(void)
{
	Ex_gpio_write(MCP23017_GPA2_Pin,GPIO_PIN_RESET);
}


void FanReset_low_led()
{
    Ex_gpio_write(MCP23017_GPA3_Pin,GPIO_PIN_RESET);

}

void FanReset_mid_led()
{
    Ex_gpio_write(MCP23017_GPA4_Pin,GPIO_PIN_RESET);

}

void FanReset_high_led()
{
    Ex_gpio_write(MCP23017_GPA5_Pin,GPIO_PIN_RESET);

}
void TempReset_amb_led(void)
{
  Ex_gpio_write(MCP23017_GPA6_Pin,GPIO_PIN_RESET);

}
void StandbyReset_led(void)
{
Ex_gpio_write(MCP23017_GPA7_Pin,GPIO_PIN_RESET);

}

uint8_t led_states(led_state state)
{
  uint8_t led_status = state;

  switch(led_status)
  {
      case LED_OFF:
    	  TempReset_35_led();
    	  TempReset_40_led();
    	  TempReset_43_led();

    	  FanReset_low_led();
    	  FanReset_mid_led();
    	  FanReset_high_led();

          TempReset_amb_led();
    	  StandbyReset_led();

	      break;
      case LED_ON:
    	  Tempset_35_led();
    	  Tempset_40_led();
    	  Tempset_43_led();

    	  Fanset_low_led();
    	  Fanset_mid_led();
    	  Fanset_high_led();



    	  Tempset_amb_led();
    	  Standbyset_led();

      	  break;
      case LED_BLINK:
           break;

  }
  return LED_OK;
}
