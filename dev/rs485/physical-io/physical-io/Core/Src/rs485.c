/**
  ******************************************************************************
  * @file           : rs485.c
  * @brief          : RS485 implementation
  ******************************************************************************
*/

#include "main.h"
#include "rs485.h"
#include "crc.h"
#include "cmd.h"

static UART_HandleTypeDef *huart;

void rs485_init(UART_HandleTypeDef *huart_ptr) {
	huart = huart_ptr;
	huart->Instance = USART2;
	huart->Init.BaudRate = 9600;
	huart->Init.WordLength = UART_WORDLENGTH_8B;
	huart->Init.StopBits = UART_STOPBITS_1;
	huart->Init.Parity = UART_PARITY_NONE;
	huart->Init.Mode = UART_MODE_TX_RX;
	huart->Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart->Init.OverSampling = UART_OVERSAMPLING_16;
	if (HAL_UART_Init(huart) != HAL_OK)
	{
		Error_Handler();
	}
}

cmd_byte_t rs485_compose(cmd_t *cmd) {
	cmd_byte_t buffer;
	buffer.size = 4 + cmd->data.size;
	int i = 0;
	buffer.data[i++] = cmd->addr;
	buffer.data[i++] = cmd->func;
	for (uint8_t k = 0; k < cmd->data.size; k++) {
		buffer.data[i++] = cmd->data.data[k];
	}
	buffer.data[i++] = cmd->crc[0];
	buffer.data[i] = cmd->crc[1];

	return buffer;
}

void rs485_send(cmd_byte_t *buffer) {
	HAL_UART_Transmit(huart, buffer->data, buffer->size, 10);
}

