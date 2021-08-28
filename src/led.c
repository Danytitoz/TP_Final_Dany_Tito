/*
 * led.h
 * Author: dany
 */

#include "led.h"

//Las funciones de este módulo son Públicas.

void ledsInit( void )	/* Se inicializa como salidas*/
{
   gpioInit(LED_ALARMA, GPIO_OUTPUT );
   gpioInit(LED_NORMAL, GPIO_OUTPUT );
}

void encenderLed(gpioMap_t led)	/* Se modifica el valor del led */
{
   gpioWrite(led, ON );
}

void apagarLeds()	/* apagar los leds */
{
   gpioWrite(LED2, OFF );
   gpioWrite(LED3, OFF );
}


