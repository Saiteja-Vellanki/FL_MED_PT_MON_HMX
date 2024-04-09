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
 * File             : temperature.c
 *
 * STEM             : SaiTeja EMbeddedsySTEMs
 *
 */


#include "temperature.h"
#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "string.h"

volatile uint8_t recvFlag;
volatile uint16_t rc_buffer[5];

extern UART_HandleTypeDef huart1;
#define ow_uart huart1
#define OW_USART USART1
#define MAXDEVICES_ON_THE_BUS 1

float Temp[1];

uint8_t devices;
OneWire ow;
uint32_t pDelay = 300, i;
uint8_t sensor;

Temperature t;

DEVInfo devInfo;

char *crcOK;

uint16_t USART_ReceiveData(USART_TypeDef* USARTx)
{

  assert_param(IS_USART_ALL_PERIPH(USARTx));

  return (uint16_t)(USARTx->DR & (uint16_t)0x01FF);
}

void USART_SendData(USART_TypeDef* USARTx, uint16_t Data)
{

  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_DATA(Data));

  USARTx->DR = (Data & (uint16_t)0x01FF);
}

uint8_t getUsartIndex(void);

void usart_setup(uint32_t baud) {

	ow_uart.Instance = OW_USART;
	ow_uart.Init.BaudRate = baud;
	ow_uart.Init.WordLength = UART_WORDLENGTH_8B;
	ow_uart.Init.StopBits = UART_STOPBITS_1;
	ow_uart.Init.Parity = UART_PARITY_NONE;
	ow_uart.Init.Mode = UART_MODE_TX_RX;
	ow_uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	ow_uart.Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_HalfDuplex_Init(&ow_uart) != HAL_OK)
	{

		__asm__("NOP");
	}

	__HAL_UART_ENABLE_IT(&ow_uart, UART_IT_RXNE);
}

void owInit(OneWire *ow) {
  int i=0, k = 0;
  for (; i < MAXDEVICES_ON_THE_BUS; i++) {
   uint8_t *r = (uint8_t *)&ow->ids[i];
    k=0;
    for (; k < 8; k++)
    r[k] = 0;
  }
  k=0;
  for (; k < 8; k++)
    ow->lastROM[k] = 0x00;
  ow->lastDiscrepancy = 64;

}

void owReadHandler() {
  uint8_t index = getUsartIndex();
  if (((OW_USART->CR1 & USART_CR1_RXNEIE) != 0) &&
      ((OW_USART->SR & UART_FLAG_RXNE) != (uint16_t)RESET)) {

		while ((OW_USART->SR & UART_FLAG_RXNE) == (uint16_t)RESET){;}
    rc_buffer[index] = USART_ReceiveData(OW_USART);
    recvFlag &= ~(1 << index);
  }
}

  uint16_t owResetCmd() {
	uint16_t owPresence;

	usart_setup(9600);

  owSend(0xF0);
  owPresence = owEchoRead();
	usart_setup(115200);
  return owPresence;
}

uint8_t getUsartIndex() {

	return 0;
}

void owSend(uint16_t data) {
  recvFlag |= (1 << getUsartIndex());
  USART_SendData(OW_USART, data);
	while(__HAL_UART_GET_FLAG(&ow_uart, UART_FLAG_TC) == RESET);
}

uint8_t owReadSlot(uint16_t data) {
  return (data == OW_READ) ? 1 : 0;
}

uint16_t owEchoRead() {
  uint8_t i = getUsartIndex();
  uint16_t pause = 1000;
  while (recvFlag & (1 << i) && pause--);
  return rc_buffer[i];
}

uint8_t *byteToBits(uint8_t ow_byte, uint8_t *bits) {
  uint8_t i;
  for (i = 0; i < 8; i++) {
    if (ow_byte & 0x01) {
      *bits = WIRE_1;
    } else {
      *bits = WIRE_0;
    }
    bits++;
    ow_byte = ow_byte >> 1;
  }
  return bits;
}

void owSendByte(uint8_t d) {
  uint8_t data[8];
	int i;
  byteToBits(d, data);
  for (i = 0; i < 8; ++i) {
    owSend(data[i]);
  }
}

uint8_t bitsToByte(uint8_t *bits) {
  uint8_t target_byte, i;
  target_byte = 0;
  for (i = 0; i < 8; i++) {
    target_byte = target_byte >> 1;
    if (*bits == WIRE_1) {
      target_byte |= 0x80;
    }
    bits++;
  }
  return target_byte;
}

uint8_t owCRC(uint8_t *mas, uint8_t Len) {
  uint8_t i, dat, crc, fb, st_byt;
  st_byt = 0;
  crc = 0;
  do {
    dat = mas[st_byt];
    for (i = 0; i < 8; i++) {
      fb = crc ^ dat;
      fb &= 1;
      crc >>= 1;
      dat >>= 1;
      if (fb == 1) crc ^= 0x8c;
    }
    st_byt++;
  } while (st_byt < Len);
  return crc;
}

uint8_t owCRC8(RomCode *rom){
  return owCRC((uint8_t*)rom, 7);
}

int hasNextRom(OneWire *ow, uint8_t *ROM) {
	uint8_t ui32BitNumber = 0;
  int zeroFork = -1;
	uint8_t i = 0;
  if (owResetCmd() == ONEWIRE_NOBODY) {
    return 0;
  }
  owSendByte(ONEWIRE_SEARCH);
  do {
		uint8_t answerBit =0;
    int byteNum = ui32BitNumber / 8;
    uint8_t *current = (ROM) + byteNum;
    uint8_t cB, cmp_cB, searchDirection = 0;
    owSend(OW_READ);
    cB = owReadSlot(owEchoRead());
    owSend(OW_READ);
    cmp_cB = owReadSlot(owEchoRead());
    if (cB == cmp_cB && cB == 1)
      return -1;
    if (cB != cmp_cB) {
      searchDirection = cB;
			} else {
				if (ui32BitNumber == ow->lastDiscrepancy)
        searchDirection = 1;
      else {
        if (ui32BitNumber > ow->lastDiscrepancy) {
          searchDirection = 0;
        } else {
          searchDirection = (uint8_t) ((ow->lastROM[byteNum] >> ui32BitNumber % 8) & 0x01);
        }
        if (searchDirection == 0)
          zeroFork = ui32BitNumber;
      }
    }

    if (searchDirection)
      *(current) |= 1 << ui32BitNumber % 8;
    answerBit = (uint8_t) ((searchDirection == 0) ? WIRE_0 : WIRE_1);
    owSend(answerBit);
    ui32BitNumber++;
		} while (ui32BitNumber < 64);
  ow->lastDiscrepancy = zeroFork;
  for (; i < 7; i++)
    ow->lastROM[i] = ROM[i];
  return ow->lastDiscrepancy > 0;
}

int owSearchCmd(OneWire *ow) {
  int device = 0, nextROM;
  owInit(ow);
  do {
    nextROM = hasNextRom(ow, (uint8_t*)(&ow->ids[device]));
    if (nextROM<0)
      return -1;
    device++;
		} while (nextROM && device < MAXDEVICES_ON_THE_BUS);
		return device;
}

void owSkipRomCmd(OneWire *ow) {
  owResetCmd();
  owSendByte(ONEWIRE_SKIP_ROM);
}

void owMatchRomCmd(RomCode *rom) {
	int i = 0;
  owResetCmd();
  owSendByte(ONEWIRE_MATCH_ROM);
  for (; i < 8; i++)
	owSendByte(*(((uint8_t *) rom) + i));
}

void owConvertTemperatureCmd(OneWire *ow, RomCode *rom) {
  owMatchRomCmd(rom);
  owSendByte(ONEWIRE_CONVERT_TEMPERATURE);
}

uint8_t *owReadScratchpadCmd(OneWire *ow, RomCode *rom, uint8_t *data) {
  uint16_t b = 0, p;
  switch (rom->family) {
    case DS18B20:
    case DS18S20:
      p = 72;
      break;
    default:
      return data;

  }
  owMatchRomCmd(rom);
  owSendByte(ONEWIRE_READ_SCRATCHPAD);
  while (b < p) {
    uint8_t pos = (uint8_t) ((p - 8) / 8 - (b / 8));
    uint8_t bt;
		owSend(OW_READ);
    bt = owReadSlot(owEchoRead());
    if (bt == 1)
      data[pos] |= 1 << b % 8;
    else
      data[pos] &= ~(1 << b % 8);
    b++;
  }
  return data;
}

void owWriteDS18B20Scratchpad(OneWire *ow, RomCode *rom, uint8_t th, uint8_t tl, uint8_t conf) {
  if (rom->family != DS18B20)
    return;
  owMatchRomCmd(rom);
  owSendByte(ONEWIRE_WRITE_SCRATCHPAD);
  owSendByte(th);
  owSendByte(tl);
  owSendByte(conf);
}

Temperature readTemperature(OneWire *ow, RomCode *rom, uint8_t reSense) {
	Scratchpad_DS18B20 *sp;
	Scratchpad_DS18S20 *spP;
  Temperature t;
	uint8_t pad[9];
  t.inCelsus = 0x00;
  t.frac = 0x00;
  sp = (Scratchpad_DS18B20 *) &pad;
  spP = (Scratchpad_DS18S20 *) &pad;
  switch (rom->family) {
    case DS18B20:
      owReadScratchpadCmd(ow, rom, pad);
      t.inCelsus = (int8_t) (sp->temp_msb << 4) | (sp->temp_lsb >> 4);
      t.frac = (uint8_t) ((((sp->temp_lsb & 0x0F)) * 10) >> 4);
      break;
    case DS18S20:
      owReadScratchpadCmd(ow, rom, pad);
      t.inCelsus = spP->temp_lsb >> 1;
      t.frac = (uint8_t) 5 * (spP->temp_lsb & 0x01);
      break;
    default:
      return t;
  }
  if (reSense) {
    owConvertTemperatureCmd(ow, rom);
  }
  return t;
}

void owCopyScratchpadCmd(OneWire *ow, RomCode *rom) {
  owMatchRomCmd(rom);
  owSendByte(ONEWIRE_COPY_SCRATCHPAD);
}

void owRecallE2Cmd(OneWire *ow, RomCode *rom) {
  owMatchRomCmd(rom);
  owSendByte(ONEWIRE_RECALL_E2);
}

int get_ROMid (void){
	if (owResetCmd() != ONEWIRE_NOBODY) {
		devices = owSearchCmd(&ow);
		if (devices <= 0) {
			while (1){
				pDelay = 1000000;
				for (i = 0; i < pDelay * 1; i++)
					__asm__("nop");
			}

		}
		i = 0;
		for (; i < devices; i++) {
			RomCode *r = &ow.ids[i];
			uint8_t crc = owCRC8(r);
			crcOK = (crc == r->crc)?"CRC OK":"CRC ERROR!";
			devInfo.device = i;

			sprintf(devInfo.info, "SN: %02X/%02X%02X%02X%02X%02X%02X/%02X", r->family, r->code[5], r->code[4], r->code[3],
					r->code[2], r->code[1], r->code[0], r->crc);

			if (crc != r->crc) {
				devInfo.device = i;
				sprintf (devInfo.info,"\n can't read cause CNC error");
			}
		}

	}
	pDelay = 1000000;
	for (i = 0; i < pDelay * 1; i++)
		__asm__("nop");

	if (strcmp(crcOK,"CRC OK") == 0) return 0;
	else return -1;
}

void get_Temperature (void)
{
	i=0;
	for (; i < devices; i++) {
		switch ((ow.ids[i]).family) {
		case DS18B20:

			t = readTemperature(&ow, &ow.ids[i], 1);
			Temp[i] = (float)(t.inCelsus*10+t.frac)/10.0;
			break;
		case DS18S20:
			t = readTemperature(&ow, &ow.ids[i], 1);
			Temp[i] = (float)(t.inCelsus*10+t.frac)/10.0;
			break;
		case 0x00:
			break;
		default:

			break;
		}
	}

}
