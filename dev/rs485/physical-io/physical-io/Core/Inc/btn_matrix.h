/**
  ******************************************************************************
  * @file           : btn_matrix.h
  * @brief          : Header for btn_matrix.c file.
  *                   Button matrix definition.
  ******************************************************************************
*/

#ifndef __BTN_MATRIX_H
#define __BTN_MATRIX_H

#include "cmd.h"
#include "main.h"

#define COL_LEN		4
#define ROW_LEN		2

#define OUT_PIN_0	GPIO_PIN_4
#define OUT_PIN_1	GPIO_PIN_5
#define OUT_PIN_2	GPIO_PIN_6
#define OUT_PIN_3	GPIO_PIN_7

#define IN_PIN_0	GPIO_PIN_4
#define IN_PIN_1	GPIO_PIN_5

#define COL_PORT	GPIOA
#define ROW_PORT	GPIOB

#define DEBOUNCE_INTERVAL   1
#define BUTTON_PRESSED      1   //value when reading
#define BUTTON_RELEASED     0   //value when reading

void btn_matrix_init(void);
cmd_t *btn_matrix_read(int row, int col);

#endif
