/*
 * led.c
 * Author: dany
 */

#ifndef MY_PROGRAMS_TP5_DANY_TITO_INC_LED_H_
#define MY_PROGRAMS_TP5_DANY_TITO_INC_LED_H_

// Se incluye biblioteca
#include "sapi.h"

/*============================================================
 * Macros públicas para mostrar el estado correspondiente al valor de la temperatura.
 * Se mostraran 02 estados representads a travès de 02 leds.
 *	LED_ALARMA -> LED2
 *	LED_NORMAL -> LED3
 * ==========================================================*/

#define LED_ALARMA  LED2
#define LED_NORMAL  LED3

// Declaraciones de funciones publicas

/*============================================================
 * Función: ledsInit
 * Descripción: Define como salidas
 *	LED_ALARMA -> Salida
 *	LED_NORMAL -> Salida
 * ==========================================================*/
void ledsInit( void );

/*=============================================================================
 * Function: encenderLed
 * Description: Enciende un led en particular
 * Input: Led que se busca encender
 * Output: No se devuelve nada
 *===========================================================================*/
void encenderLed(gpioMap_t led);

/*=============================================================================
 * Function: apagarLeds
 * Description: Apaga los leds
 * Input: No recibe input
 * Output: Si se lograron apagar todos los leds devuelve 1 y si no 0
 *===========================================================================*/
void apagarLeds();


#endif /* MY_PROGRAMS_TP5_DANY_TITO_INC_LED_H_ */
