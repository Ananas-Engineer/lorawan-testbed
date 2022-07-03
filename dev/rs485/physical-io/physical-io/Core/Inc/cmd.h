/**
  ******************************************************************************
  * @file           : cmd.h
  * @brief          :
  *                   cmd definition.
  ******************************************************************************
*/

#ifndef __CMD_H
#define __CMD_H

#include "main.h"

#define DATA_SIZE		8
#define CMD_BYTE_SIZE	16

typedef struct {
	uint8_t data[CMD_BYTE_SIZE];
	uint8_t size;
} cmd_byte_t;

typedef struct {
	uint8_t data[DATA_SIZE];
	uint8_t size;
} data_t;

typedef struct {
	uint8_t addr;
	uint8_t func;
	data_t data;
	uint8_t crc[2];
} cmd_t;

/* DEFINE CMD */
/*
const cmd_t dfal = {
		.addr = 0x00,
		.func = 0x00,
		.data.data = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
		.data.size = 0x0,
		.crc = {0x00, 0x00}
};

const cmd_t tog_r0 = {
		.addr = 0x01,
		.func = 0x05,
		.data.data = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x55, 0x00},
		.data.size = 0x4,
		.crc = {0xF2, 0x9A}
};

const cmd_t tog_r1 = {
		.addr = 0x01,
		.func = 0x05,
		.data.data = {0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x55, 0x00},
		.data.size = 0x4,
		.crc = {0xA3, 0x5A}
};

const cmd_t tog_r2 = {
		.addr = 0x01,
		.func = 0x05,
		.data.data = {0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x55, 0x00},
		.data.size = 0x4,
		.crc = {0x53, 0x5A}
};

const cmd_t tog_r3 = {
		.addr = 0x01,
		.func = 0x05,
		.data.data = {0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x55, 0x00},
		.data.size = 0x4,
		.crc = {0x02, 0x9A}
};
*/
#endif

