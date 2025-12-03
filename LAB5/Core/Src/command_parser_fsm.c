/*
 * command_parser_fsm.c
 *
 *  Created on: Nov 26, 2025
 *      Author: User
 */

#include "command_parser_fsm.h"
#include "global.h"
#include <string.h>

void command_parser_fsm() {
    if (buffer_flag == 1) {
        for (int i = 0; i < MAX_BUFFER_SIZE; i++) {
            if (buffer[i] == '#') {
                if (i >= 4 && buffer[i-3] == 'R' && buffer[i-2] == 'S' && buffer[i-1] == 'T' && buffer[i-4] == '!') {
                    command_flag = 1;
                    command_data = RST_CMD;
                }
                else if (i >= 3 && buffer[i-2] == 'O' && buffer[i-1] == 'K' && buffer[i-3] == '!') {
                    command_flag = 1;
                    command_data = OK_CMD;
                }

                index_buffer = 0;
                memset(buffer, 0, MAX_BUFFER_SIZE);
                break;
            }
        }
        buffer_flag = 0;
    }
}
