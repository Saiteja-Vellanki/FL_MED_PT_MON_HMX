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
 * File             : io_expansion.h
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */


#ifndef IO_EXPANSION_H_
#define IO_EXPANSION_H_

#include "stm32f4xx_hal.h"
#include <stdint.h>

// Addresses (A0-A2)
#define MCP23017_ADD_20			0x20
#define MCP23017_ADD_21			0x21
#define MCP23017_ADD_22			0x22
#define MCP23017_ADD_23			0x23
#define MCP23017_ADD_24			0x24
#define MCP23017_ADD_25			0x25
#define MCP23017_ADD_26			0x26
#define MCP23017_ADD_27			0x27

/*INPUTS/OUTPUTS */
#define MCP23017_GPA0_Pin		0x00
#define MCP23017_GPA1_Pin		0x01
#define MCP23017_GPA2_Pin		0x02
#define MCP23017_GPA3_Pin		0x03
#define MCP23017_GPA4_Pin		0x04
#define MCP23017_GPA5_Pin		0x05
#define MCP23017_GPA6_Pin		0x06
#define MCP23017_GPA7_Pin		0x07
#define MCP23017_GPB0_Pin		0x08
#define MCP23017_GPB1_Pin		0x09
#define MCP23017_GPB2_Pin		0x0A
#define MCP23017_GPB3_Pin		0x0B
#define MCP23017_GPB4_Pin		0x0C
#define MCP23017_GPB5_Pin		0x0D
#define MCP23017_GPB6_Pin		0x0E
#define MCP23017_GPB7_Pin		0x0F

typedef enum {
	MCP23017Port_A,
	MCP23017Port_B
} MCP23017Port_t;

typedef enum{
	MCP23017_PIN_MODE_INPUT,
	MCP23017_PIN_MODE_INPUT_PULLUP,
	MCP23017_PIN_MODE_OUTPUT
} MCP23017_PinModeIO_t;

typedef enum {
	MCP23017_PIN_POLARITY_NORMAL,
	MCP23017_PIN_POLARITY_INVERTED
} MCP23017_PinPolarity_t;

typedef enum {
	MCP23017_INTERRUPT_MODE_SEPARATED,
	MCP23017_INTERRUPT_MODE_OR,
} MCP23017_InterruptMode_t;

typedef enum {
	MCP23017_IRQ_MODE_CHANGE, 		/* to trigger the interrupt whenever the pin changes value */
	MCP23017_IRQ_MODE_RISING,		/* to trigger when the pin goes from low to high */
	MCP23017_IRQ_MODE_FALLING,		/* for when the pin goes from high to low. */
} MCP23017_InterruptModeState_t;

//typedef struct {
//	I2C_HandleTypeDef*	hi2c;
//	uint16_t			addr;
//} MCP23017_HandleTypeDef;

//HAL_StatusTypeDef mcp23017_init(MCP23017_HandleTypeDef *hdev, I2C_HandleTypeDef *hi2c, uint16_t addr);
//HAL_StatusTypeDef mcp23017_pinMode(MCP23017_HandleTypeDef *hdev, uint8_t pin, MCP23017_PinModeIO_t mode, MCP23017_PinPolarity_t polarity);
//HAL_StatusTypeDef mcp23017_portMode(MCP23017_HandleTypeDef *hdev, MCP23017Port_t port, MCP23017_PinModeIO_t pinmode, uint8_t inverted);
//HAL_StatusTypeDef mcp23017_digitalRead(MCP23017_HandleTypeDef *hdev, uint8_t pin, uint8_t *data);
//HAL_StatusTypeDef mcp23017_digitalWrite(MCP23017_HandleTypeDef *hdev, uint8_t pin, GPIO_PinState pinState);
//HAL_StatusTypeDef mcp23017_setInterruptMode(MCP23017_HandleTypeDef *hdev, MCP23017_InterruptMode_t mode);
//HAL_StatusTypeDef mcp23017_setupInterruptPin(MCP23017_HandleTypeDef *hdev, uint8_t pin, MCP23017_InterruptModeState_t mode);
//HAL_StatusTypeDef mcp23017_getLastInterruptPin(MCP23017_HandleTypeDef *hdev, uint8_t *data);
//HAL_StatusTypeDef mcp23017_getLastInterruptPinValue(MCP23017_HandleTypeDef *hdev, uint16_t *data);


#endif /* IO_EXPANSION_H_ */
