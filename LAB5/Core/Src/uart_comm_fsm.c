/*
 * uart_comm_fsm.c
 *
 *  Created on: Nov 27, 2025
 *      Author: User
 */

#include "uart_comm_fsm.h"
#include "global.h"
#include <stdio.h>
#include "software_timer.h"

enum UartState { IDLE, SEND_ADC, WAIT_OK };
enum UartState uartState = IDLE;

char str[50];

void uart_communiation_fsm() {
    switch (uartState) {
        case IDLE:
            if (command_flag == 1 && command_data == RST_CMD) {
                command_flag = 0;
                ADC_Value = HAL_ADC_GetValue(&hadc1);
                uartState = SEND_ADC;
            }
            break;

        case SEND_ADC:
            int len = sprintf(str, "!ADC=%lu#\r\n", ADC_Value);
            HAL_UART_Transmit(&huart2, (uint8_t*)str, len, 1000);
            uartState = WAIT_OK;
            setTimer1(3000);
            break;

        case WAIT_OK:
            if (command_flag == 1 && command_data == OK_CMD) {
                command_flag = 0;
                uartState = IDLE;
            }

            if (timer1_flag == 1) {
                uartState = SEND_ADC;
            }
            break;

        default:
            uartState = IDLE;
            break;
    }
}
