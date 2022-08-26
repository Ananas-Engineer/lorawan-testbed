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
static buffer_byte_t rx_buffer; //recv buffer for uart RX DMA

static inline void uart_send(buffer_byte_t *buffer) {
	HAL_UART_Transmit(huart, buffer->data, buffer->size, 10);
}

static inline buffer_byte_t uart_recv(void) {
	return rx_buffer;
}

static inline void uart_rx_buffer_clear(void) {
	memset(rx_buffer.data, '\0', rx_buffer.size);
}

void rs485_init(UART_HandleTypeDef *huart_ptr) {
	huart = huart_ptr;
	rx_buffer.size = 20;
	memset(rx_buffer.data, '\0', rx_buffer.size);
	HAL_UART_Receive_DMA(huart, rx_buffer.data, rx_buffer.size);
}

buffer_byte_t rs485_compose(cmd_t *cmd) {
	buffer_byte_t buffer;
	buffer.size = 0;

	buffer.data[buffer.size++] = cmd->addr;
	buffer.data[buffer.size++] = cmd->func;
	for (uint8_t k = 0; k < cmd->data.size; k++) {
		buffer.data[buffer.size++] = cmd->data.data[k];
	}
	buffer.data[buffer.size++] = cmd->crc[0];
	buffer.data[buffer.size++] = cmd->crc[1];

	return buffer;
}

buffer_byte_t rs485_compose_at_cmd(cmd_t *cmd) {
	buffer_byte_t buffer;
	buffer.size = 0;

	char *p = AT_CMD_PREFIX;
	while (*p != '\0') {
		buffer.data[buffer.size++] = *p;
		p++;
	}

	buffer.data[buffer.size++] = (cmd->addr / 16) + '0';
	buffer.data[buffer.size++] = (cmd->addr % 16) + '0';

	buffer.data[buffer.size++] = ' ';
	buffer.data[buffer.size++] = (cmd->func / 16) + '0';
	buffer.data[buffer.size++] = (cmd->func % 16) + '0';

	for (uint8_t k = 0; k < cmd->data.size; k++) {
		buffer.data[buffer.size++] = ' ';
		buffer.data[buffer.size++] = (cmd->data.data[k] / 16) + '0';
		buffer.data[buffer.size++] = (cmd->data.data[k] % 16) + '0';
	}

	buffer.data[buffer.size++] = ',';
	buffer.data[buffer.size++] = '1';
	buffer.data[buffer.size++] = '\n';

	return buffer;
}

buffer_byte_t rs485_compose_at_pwd(void) {
	buffer_byte_t buffer;
	buffer.size = 0;

	char *p = AT_CMD_PSW;
	while (*p != '\0') {
		buffer.data[buffer.size++] = *p;
		p++;
	}
	buffer.data[buffer.size++] = '\n';

	return buffer;
}

void rs485_send(buffer_byte_t *buffer) {
	uart_send(buffer);
}

buffer_byte_t rs485_recv(void) {
	return uart_recv();
}

void rs485_recv_buffer_clear(void) {
	uart_rx_buffer_clear();
}

uint8_t rs485_recv_buffer_compare(void) {
	for (uint8_t i = 0; i < rx_buffer.size; i++) {
		if (rx_buffer.data[i] != '\0') {
			return 0;
		}
	}
	return 1;
}

