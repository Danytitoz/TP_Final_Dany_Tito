/*
 * uart.c
 *
 *  Created on: 27 ago. 2021
 *      Author: dany
 */

#include "uart.h"

/*=============================================================================
 * Function: *itoa
 * Description: Esta función transforma de dato numérico a un char de caracteres
 * 		ASCII. Lo carga en el vector de char del puntero que recibe. También se
 * 		especifica la base en la que está el número.
 * Input: recibe el valor a convertir, el puntero del vector de char en donde se
 * 		debe escribir el valor convertido y la base en la que se desea decodificar
 * 		el número.
 *===========================================================================*/

char* itoa(int value, char* result, int base) {
   // check that the base if valid
   if (base < 2 || base > 36) { *result = '\0'; return result; }

   char* ptr = result, *ptr1 = result, tmp_char;
   int tmp_value;

   do {
      tmp_value = value;
      value /= base;
      *ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
   } while ( value );

   // Apply negative sign
   if (tmp_value < 0) *ptr++ = '-';
   *ptr-- = '\0';
   while(ptr1 < ptr) {
      tmp_char = *ptr;
      *ptr--= *ptr1;
      *ptr1++ = tmp_char;
   }
   return result;
}

static char uartBuff[10];

/*=============================================================================
 * Function: initUART
 * Description: Se inicializa la UART en configuración 115200 baudios.
 * 		Se utiliza la configuración standard: 8bits, sin paridad, 1 bit de parada
 *===========================================================================*/
void initUART(void){
	uartConfig( UART_USB, 115200 );
}

/*=============================================================================
 * Function: tempUART
 * Description: Se pasa el valor numérico por parametro, luego se transforma a
 * 		ASCII y se muestra por el puerto serie.
 * Input: se ingresa el valor de la lectura en el ADC CH1
 * Output: se muestra la temperatura por el puerto serie
 *===========================================================================*/

void tempUART(uint16_t temperatura){
	itoa( temperatura, uartBuff, 10 ); /* 10 significa decimal */
	uartWriteString( UART_USB, uartBuff );
	uartWriteString( UART_USB, "\r\n" );
}


