/*
 * uart.h
 *
 *  Created on: 27 ago. 2021
 *      Author: dany
 */
#include "sapi.h"

#ifndef MY_PROGRAMS_TP5_DANY_TITO_INC_UART_H_
#define MY_PROGRAMS_TP5_DANY_TITO_INC_UART_H_

char* itoa(int value, char* result, int base) ;

void initUART(void);

void tempUART(uint16_t temperatura);


#endif /* MY_PROGRAMS_TP5_DANY_TITO_INC_UART_H_ */
