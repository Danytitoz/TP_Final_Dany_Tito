/*
 * MEFtemperatura.h
 * Author: dany
 */

#ifndef MY_PROGRAMS_TP5_DANY_TITO_INC_MEFTEMPERATURA_H_
#define MY_PROGRAMS_TP5_DANY_TITO_INC_MEFTEMPERATURA_H_

#ifdef __cplusplus
extern "C" {
#endif

void MEFtempInit( void );	// La función inicializa la placa, los leds como salida y el estado inicial de la MEF

void MEFtempUpdate( void );	// Se actualiza el estado respecto al valor de temperatura

#ifdef __cplusplus
}
#endif

#endif /* MY_PROGRAMS_TP5_DANY_TITO_INC_MEFTEMPERATURA_H_ */
