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
buffer_byte_t rs485_compose(cmd_t *cmd);
buffer_byte_t rs485_compose_at_cmd(cmd_t *cmd);
buffer_byte_t rs485_compose_at_pwd(void);
void rs485_send(buffer_byte_t *buffer);
void rs485_recv(buffer_byte_t *buffer);

#endif
