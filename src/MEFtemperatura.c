/*
 * MEFtemperatura.c
 * Author: dany
 */

#include "MEFtemperatura.h"
#include "led.h"
#include "sapi.h"
#include "uart.h"

/* Se definen los siguientes estados para la MEF
* INICIAL: 	En el estado INICIAL se configura e inicializa la UART y ADC
* NORMAL:	En este estado enciende o apaga los leds de acuerdo al valor
		 	obtenido del ADC.
* ALARMA:	Se ingresa a este estado cuando se detecta una temperatura elevada
* 			(se considera un valor mayor a 800 en la lectura del ADC) */

typedef enum{
   MODO_INICIAL,
   MODO_NORMAL,
   MODO_ALARMA,
}Estadotemp_t;

static Estadotemp_t Estadotemp; // Variable de estado

/*Se definen las banderas para cada estado dentro de la MEF */
bool_t flagState[]={FALSE, FALSE, FALSE};
/* flagSate[0]-> INICIAL
*  flagSate[1]-> NORMAL
*  flagSate[2]-> ALARMA  */

void MEFtempInit( void ){
// Inicializa la placa
	boardInit();
	ledsInit();
	Estadotemp = MODO_INICIAL; //Se establece el estado inicial del sistema
}

void MEFtempUpdate( void ){	// Se actualiza el estado de la MEF

    /* Variable para almacenar el valor AI0 - ADC0 CH1 */
	uint16_t temperatura = 0;


	switch( Estadotemp ){

		case MODO_INICIAL:

			 if (flagState[0] == FALSE){
				 initUART;	// Inicializar UART_USB a 115200 baudios
				 adcConfig( ADC_ENABLE ); // Se habilita la lectura del ADC
				 uartWriteString( UART_USB, "SISTEMA MEDIDOR DE TEMPERATURA\r\n" );
			 }
			 flagState[0] = TRUE;
			 if (!gpioRead( TEC1 )){
				 Estadotemp = MODO_NORMAL; // TEC1-> Botón de encendido
				 flagState[0] = FALSE;
			 }
			 else
				 Estadotemp = MODO_INICIAL;

		break;

		case MODO_NORMAL:

			    	  	if (!gpioRead( TEC2 )){    //Apaga el sistema
			    	  		Estadotemp = MODO_INICIAL;
			    		  uartWriteString( UART_USB, "SE REINICIA SISTEMA\r\n" );
			    	  	}
			    	  	else{
				    	  	  temperatura = adcRead( CH1 );
				            if( temperatura < 800 ){
				               uartWriteString( UART_USB, "Temperatura Normal\r\n" );
				               /* Conversión de muestra entera a ascii con base decimal */
				               tempUART(temperatura);
				               apagarLeds();
				               gpioWrite( LED3, ON );
				            }
				            else
				            Estadotemp = MODO_ALARMA;
				            }

			      break;

	      case MODO_ALARMA:
	    	  uartWriteString( UART_USB, "ALERTA\r\n" );
	    	  apagarLeds();
	    	  gpioWrite( LED2, ON );
	    	  if (!gpioRead( TEC2 )){    //Apaga el sistema
	    		  Estadotemp = MODO_INICIAL;
	    		  uartWriteString( UART_USB, "SE REINICIA SISTEMA\r\n" );
	    	}
	    	  else{
	    		  temperatura = adcRead( CH1 );

		    	  if(temperatura>800){
		    		  Estadotemp = MODO_ALARMA;
		    	  }
		    	  else
		    		  Estadotemp = MODO_NORMAL;
	    	  }
	      break;

	      default:
	    	  Estadotemp = MODO_INICIAL;
	         uartWriteString( UART_USB, "Error, vuelta a Modo Inicial\r\n" );
	      break;
	   }
}


