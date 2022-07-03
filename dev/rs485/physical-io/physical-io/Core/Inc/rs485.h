/**
  ******************************************************************************
  * @file           : rs485.h
  * @brief          : Header for rs485.c file.
  *                   RS485 definition.
  ******************************************************************************
*/

#ifndef __RS485_H
#define __RS485_H

#include "cmd.h"
#include "main.h"

void rs485_init(UART_HandleTypeDef *huart_ptr);
cmd_byte_t rs485_compose(cmd_t *cmd);
void rs485_send(cmd_t *cmd);

#endif
