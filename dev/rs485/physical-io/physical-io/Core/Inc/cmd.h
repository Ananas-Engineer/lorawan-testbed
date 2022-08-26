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

#define DATA_SIZE			8
#define BUFFER_BYTE_SIZE	128

typedef struct {
	uint8_t data[BUFFER_BYTE_SIZE];
	uint8_t size;
} buffer_byte_t;

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

/* DEFINE AT CMD */
#define AT_CMD_PSW 		"123456"
#define AT_CMD_PREFIX 	"AT+CFGDEV="

#endif

