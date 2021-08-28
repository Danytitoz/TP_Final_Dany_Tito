/*=============================================================================
 * Copyright (c) 2021, Dany Tito <danyxxxivgmail.com>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE.txt)
 * Date: 2021/08/27
 *===========================================================================*/

/*=====[Inclusions of function dependencies]=================================*/

#include "TP5_Dany_Tito.h"
#include "MEFtemperatura.h"
#include "sapi.h"

int main( void )
{
   // ----- Setup -----------------------------------

	/* Declaración de delay no bloqueante */
	delay_t delay1;
	delayConfig( &delay1, 500 );

	/* INICIALIZACIONES */
	MEFtempInit();


   // ----- Repeat for ever -------------------------
   while( true ) {

	   if (delayRead(&delay1)){
		   MEFtempUpdate();
	   }
   }

   return 0;
}
