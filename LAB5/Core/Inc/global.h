/*
 * global.h
 *
 *  Created on: Nov 27, 2025
 *      Author: User
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

// Kích thước bộ đệm
#define MAX_BUFFER_SIZE 30

// Định nghĩa các lệnh (Command ID)
#define NO_CMD   0
#define RST_CMD  1
#define OK_CMD   2

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart2;
// Biến chia sẻ
extern uint8_t temp;
extern uint8_t buffer[MAX_BUFFER_SIZE];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

// Biến trạng thái sau khi phân tích lệnh
extern uint8_t command_flag;
extern uint8_t command_data;

// Biến ADC
extern uint32_t ADC_Value;

#endif /* INC_GLOBAL_H_ */
