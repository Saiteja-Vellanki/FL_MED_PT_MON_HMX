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
 * Updated on       : Mar 30, 2024
 * File             : temperature.h
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */


#ifndef TEMPERATURE_H_
#define TEMPERATURE_H_

#include "error.h"

#include <stdint.h>

#define ONEWIRE_NOBODY 0xF0
#define ONEWIRE_SEARCH 0xF0
#define ONEWIRE_SKIP_ROM 0xCC
#define ONEWIRE_READ_ROM 0x33
#define ONEWIRE_MATCH_ROM 0x55
#define ONEWIRE_CONVERT_TEMPERATURE 0x44
#define ONEWIRE_READ_SCRATCHPAD 0xBE
#define ONEWIRE_WRITE_SCRATCHPAD 0x4E
#define ONEWIRE_COPY_SCRATCHPAD 0x48
#define ONEWIRE_RECALL_E2 0xB8

#ifndef MAXDEVICES_ON_THE_BUS
#define MAXDEVICES_ON_THE_BUS 1
#endif

#define DS18B20 0x28
#define DS18S20 0x10

#define WIRE_0    0x00
#define WIRE_1    0xff
#define OW_READ   0xff

typedef struct {
  int8_t inCelsus;
  uint8_t frac;
} Temperature;

typedef struct {
  uint8_t family;
  uint8_t code[6];
  uint8_t crc;
} RomCode;

typedef struct {
  uint8_t crc;
  uint8_t reserved[3];
  uint8_t configuration;
  uint8_t tl;
  uint8_t th;
  uint8_t temp_msb;
  uint8_t temp_lsb;
} Scratchpad_DS18B20;

typedef struct {
  uint8_t crc;
  uint8_t count_per;
  uint8_t count_remain;
  uint8_t reserved[2];
  uint8_t tl;
  uint8_t th;
  uint8_t temp_msb;
  uint8_t temp_lsb;
} Scratchpad_DS18S20;

typedef struct {
  RomCode ids[MAXDEVICES_ON_THE_BUS];
  int lastDiscrepancy;
  uint8_t lastROM[8];
} OneWire;

typedef struct {
	int device;
	char info[30];
}DEVInfo;

extern DEVInfo devInfo;

void usart_setup_(uint32_t baud);

uint16_t owResetCmd(void);

int owSearchCmd(OneWire *ow);

void owSkipRomCmd(OneWire *ow);

uint8_t owCRC8(RomCode *rom);

void owMatchRomCmd(RomCode *rom);

void owConvertTemperatureCmd(OneWire *ow, RomCode *rom);

uint8_t* owReadScratchpadCmd(OneWire *ow, RomCode *rom, uint8_t *data);

void owCopyScratchpadCmd(OneWire *ow, RomCode *rom);

void owRecallE2Cmd(OneWire *ow, RomCode *rom);

Temperature readTemperature(OneWire *ow, RomCode *rom, uint8_t reSense);

void owSend(uint16_t data);

void owSendByte(uint8_t data);

uint16_t owEchoRead(void);

void owReadHandler(void);

int get_ROMid (void);

void get_Temperature (void);

#endif /* TEMPERATURE_H_ */
