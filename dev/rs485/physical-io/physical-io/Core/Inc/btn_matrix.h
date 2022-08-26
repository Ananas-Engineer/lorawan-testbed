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

#define OUT_PIN_0	GPIO_PIN_0
#define OUT_PIN_1	GPIO_PIN_1
#define OUT_PIN_2	GPIO_PIN_2
#define OUT_PIN_3	GPIO_PIN_3

#define IN_PIN_0	GPIO_PIN_4
#define IN_PIN_1	GPIO_PIN_5

#define COL_PORT	GPIOA
#define ROW_PORT	GPIOA

#define DEBOUNCE_INTERVAL   10 //ms
#define ROW_ACTIVE			1
#if (ROW_ACTIVE == 1)
#define BUTTON_PRESSED      1   //value when reading
#define BUTTON_RELEASED     0   //value when reading
#else
#define BUTTON_PRESSED      0   //value when reading
#define BUTTON_RELEASED     1   //value when reading
#endif

#define COL_ACTIVE			0
#if (COL_ACTIVE == 1)
#define COL_SET				GPIO_PIN_SET
#define COL_RESET			GPIO_PIN_RESET
#else
#define COL_SET				GPIO_PIN_RESET
#define COL_RESET			GPIO_PIN_SET
#endif

void btn_matrix_init(void);
cmd_t *btn_matrix_read(int row, int col);

#endif
