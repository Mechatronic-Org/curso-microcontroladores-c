# Práctica 02: LCD 16x2 y Keypad 4x4 con STM32 NUCLEO-C031C6 en Wokwi (https://wokwi.com/stm32)

## Descripción
En esta práctica se implementa la interfaz de un **LCD 16x2 en modo 4 bits** y un **teclado matricial 4x4** usando la tarjeta **STM32 NUCLEO-C031C6** en el simulador **Wokwi**.

El objetivo es detectar la tecla presionada en el keypad y mostrar en el LCD **únicamente la última tecla pulsada**.

## Archivos de la práctica
- `README.md`
- `practica_02_WokwiC031C6LCDkeyPad.ipynb`

## Requisitos
- Cuenta en Wokwi (Preferentemente)
- STM32CubeMXy STM32IDE (Por si deseas generar tu propio código)
- Binder o Jupyter para abrir el notebook.

## Contenido del notebook
El notebook incluye:
- En qué consiste la práctica
- Librerías usadas y su propósito
- Explicación de las funciones implementadas
- Conexiones del circuito
- I/O map
- Flujo general de funcionamiento

## Temas y subtemas de la práctica

1. **Acceso al material de la práctica**  
   1.1 Ingreso a la plataforma Binder.  
   1.2 Carga del enlace del repositorio en GitHub.  
   1.3 Ejecución del entorno mediante la opción Launch.  
   1.4 Apertura de Jupyter Notebook.  
   1.5 Exploración del contenido disponible.  

2. **Introducción a la práctica**  
   2.1 Objetivo de la práctica.  
   2.2 Descripción general del sistema a implementar.  

3. **Integración de componentes en Wokwi**  
   3.1 Uso de la tarjeta STM32 Nucleo-C031C6.  
   3.2 Integración de la pantalla LCD 16x2.  
   3.3 Integración del teclado matricial 4x4.  
   3.4 Explicación general del circuito implementado.  

4. **Asignación de pines y mapa de entradas/salidas**  
   4.1 Definición de pines para la pantalla LCD.  
   4.2 Definición de pines para el teclado matricial.  
   4.3 Elaboración del mapa de entradas y salidas.  

5. **Configuración del proyecto en STM32CubeMX**  
   5.1 Configuración de pines GPIO.  
   5.2 Definición de entradas y salidas digitales.  
   5.3 Generación del código base del proyecto.  

6. **Uso de librerías (Pantalla LCD y Teclado Hexadecimal 4x4) en C con HAL**  
   6.1 Identificación de las librerías utilizadas.  
   6.2 Explicación general de su funcionamiento.  
   6.3 Integración de librerías en el programa principal.  

7. **Pruebas de funcionamiento del sistema**  
   7.1 Lectura de teclas presionadas.  
   7.2 Visualización de la tecla en la pantalla LCD.  
   7.3 Validación del sistema en simulación.  
