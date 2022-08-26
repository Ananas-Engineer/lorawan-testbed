/**
  ******************************************************************************
  * @file           : btn_matrix.c
  * @brief          : button matrix implementation
  ******************************************************************************
*/

#include "main.h"
#include "btn_matrix.h"
#include "cmd.h"

cmd_t cmd_mapper[ROW_LEN][COL_LEN] = {
		{
				{
						.addr = 0x01,
						.func = 0x05,
						.data.data = {0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00},
						.data.size = 0x4,
						.crc = {0xF2, 0x9A}
				},

				{
						.addr = 0x01,
						.func = 0x05,
						.data.data = {0x00, 0x01, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00},
						.data.size = 0x4,
						.crc = {0xA3, 0x5A}
				},

				{
						.addr = 0x01,
						.func = 0x05,
						.data.data = {0x00, 0x02, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00},
						.data.size = 0x4,
						.crc = {0x53, 0x5A}
				},

				{
						.addr = 0x01,
						.func = 0x05,
						.data.data = {0x00, 0x03, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00},
						.data.size = 0x4,
						.crc = {0x02, 0x9A}
				},
		},
		{
				{
						.addr = 0x01,
						.func = 0x05,
						.data.data = {0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00},
						.data.size = 0x4,
						.crc = {0xF2, 0x9A}
				},

				{
						.addr = 0x01,
						.func = 0x05,
						.data.data = {0x00, 0x01, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00},
						.data.size = 0x4,
						.crc = {0xA3, 0x5A}
				},

				{
						.addr = 0x01,
						.func = 0x05,
						.data.data = {0x00, 0x02, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00},
						.data.size = 0x4,
						.crc = {0x53, 0x5A}
				},

				{
						.addr = 0x01,
						.func = 0x05,
						.data.data = {0x00, 0x03, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00},
						.data.size = 0x4,
						.crc = {0x02, 0x9A}
				},
		}
};

uint16_t out_pin_mapper[COL_LEN] = {OUT_PIN_0, OUT_PIN_1, OUT_PIN_2, OUT_PIN_3};
uint16_t in_pin_mapper[ROW_LEN] = {IN_PIN_0, IN_PIN_1};

uint8_t debounce_buffer_1[ROW_LEN][COL_LEN];
uint8_t debounce_buffer_2[ROW_LEN][COL_LEN];
uint8_t valid_buffer[ROW_LEN][COL_LEN];
uint8_t valid_buffer_prev[ROW_LEN][COL_LEN];

static inline void gpio_write_pin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState) {
	HAL_GPIO_WritePin(GPIOx, GPIO_Pin, PinState);
}

static inline GPIO_PinState gpio_read_pin(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin) {
	return HAL_GPIO_ReadPin(GPIOx, GPIO_Pin);
}

void btn_matrix_init(void) {
	for (int i = 0; i < ROW_LEN; i++) {
		for (int j = 0; j < COL_LEN; j++) {
			debounce_buffer_1[i][j] = BUTTON_RELEASED;
			debounce_buffer_2[i][j] = BUTTON_RELEASED;
			valid_buffer[i][j] = BUTTON_RELEASED;
			valid_buffer_prev[i][j] = BUTTON_RELEASED;
		}
	}
}

cmd_t *btn_matrix_read(int row, int col) {
	for (uint8_t i = 0; i < COL_LEN; i++) {
		gpio_write_pin(COL_PORT, out_pin_mapper[i], COL_RESET);
	}
	gpio_write_pin(COL_PORT, out_pin_mapper[col], COL_SET);

	debounce_buffer_2[row][col] = debounce_buffer_1[row][col];
	debounce_buffer_1[row][col] = gpio_read_pin(ROW_PORT, in_pin_mapper[row]);
	if (debounce_buffer_1[row][col] == debounce_buffer_2[row][col]) { //valid
		valid_buffer_prev[row][col] = valid_buffer[row][col];
		valid_buffer[row][col] = debounce_buffer_1[row][col];

		if (valid_buffer[row][col] == BUTTON_RELEASED && valid_buffer_prev[row][col] == BUTTON_PRESSED) {
			return &cmd_mapper[row][col];
		}
 	}

	return NULL;
}
