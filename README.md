# TP_Final_Dany_Tito
Proyecto del trabajo final para el curso Programación de microprocesadores 

Alumno: Dany Tito Zuñiga

Plataforma embebida: EDU-CIAA-NXP

APLICACIÓN:
El proyecto se resuelve sobre la plataforma EDU-CIAA, se usa 3 periféricos de entrada: 2
teclas para el manejo de los estados y un canal del conversor analógico digital para simular la
lectura de la temperatura, 2 leds como salidas para mostrar en qué estado se encuentra el
sistema y una interfaz UART para la comunicación con el terminal serial de la PC.

Periféricos (1 ó 2):
UART, GPIO, ADC

DIAGRAMA DE ESTADO MEF

![imagen](https://user-images.githubusercontent.com/86753053/131221307-b0820269-e642-4322-aadf-aafa2d3db6e5.png)

DESCRIPCIÓN DE ESTADOS

Se definen los siguientes estados para la MEF.

ESTADO INICIAL: En el estado INICIAL se configura e inicializa la UART y ADC

ESTADO NORMAL: En este estado enciende el led correspondiente de acuerdo al
valor obtenido del ADC (LED3).

ESTADO ALARMA: Se ingresa a este estado cuando se detecta una temperatura
elevada (se considera un valor mayor a 800 en la lectura del ADC), mientras se
mantenga en este estado permanecerá encendido el LED2.

MÓDULOS DE SOFTWARE IMPLEMENTADOS PARA CADA PERIFÉRICO

MEFtemperatura.c y MEFtemperatura.h: contiene las funciones para inicializar el
sistema, los estados de la MEF, la función de inicialización para esta y su
actualización.

uart.c y uart.h: incluye funciones para configurar e inicializar el canal del UART así
como también la función para hacer conversión y visualización de la lectura del ADC a
decimal en el monitor serial.

led.c y lec.h: contiene las funciones para inicializar y modificar el valor de los leds en
la placa
