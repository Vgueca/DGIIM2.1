/**
 * @file    funciones.h
 * @brief   Fichero de cabecera para las funciones que modifican imagenes
 * 
 */

#include "imagen.h"
#include "imagenES.h"
#include <iostream>

#ifndef FUNCIONES
#define FUNCIONES

// EJER 1.
/**
  * @brief Umbraliza una imagen (pixeles fuera de un rango de valores = 255)
  * @param fichE nombre del fichero que contiene la imagen de entrada
  * @param fichS nombre del fichero para guardar la imagen de salida
  * @param t1 valor del inicio del intervalo (umbral inicio)
  * @param t2 valor del final del intervalo (umbral fin)
  * @pre t1 && t2 deben estar comprendidos en el intervalo [0, 255];
  * @return un codigo de error indicando si no falla o el tipo de fallo
  */
int UmbralizarEsc(const char* fichE, const char* fichS, int t1, int t2);

// EJER 3.
/**
  * @brief Aumenta una seccion de la imagen (zoom)
  * @param fichE nombre del fichero que contiene la imagen de entrada
  * @param fichS nombre del fichero para guardar la imagen de salida
  * @param x1 indice de la fila de la esquina superior de la seccion
  * @param y1 indice de la columna de la esquina superior de la seccion
  * @param x2 indice de la fila de la esquina inferior de la seccion
  * @param y2 indice de la columna de la esquina inferior de la seccion
  * @return un codigo de error indicando si no falla o el tipo de fallo
  */
int Zoom(const char* fichE, const char* fichS, int x1, int y1, int x2, int y2);

// EJER 5.
/**
  * @brief Aumenta el contraste de una imagen segun un nuevo rango valores (min && max)
  * @param fichE nombre del fichero que contiene la imagen de entrada
  * @param fichS nombre del fichero para guardar la imagen de salida
  * @param min  extremo inf. del intervalo de niveles de gris para la imagen resultante.
  * @param max  extremo sup. del intervalo de niveles de gris para la imagen resultante.
  * @pre min && man deben estar comprendidos en el intervalo [0, 255];
  * @pre max>=min
  * @return un codigo de error indicando si no falla o el tipo de fallo
  */
int Contraste(const char* fichE, const char* fichS, int min, int max);

// EJER 6.
/**
  * @brief Crea una transicion de imagenes mediante la creacion de ficheros (imagenes) intermedios
  * @param fichE1 nombre del fichero que contiene la imagen inicial u origen
  * @param fichE2 nombre del fichero que contiene la imagen final o resultado
  * @param pasos numero de pasos (ficheros) intermedios a realizar.
  * @pre pasos debe estar comprendido en el intervalo [0, 256];
  * @pre las caracteristicas y dimension de ambas imagenes fichE1 y fichE2 deben ser iguales
  * @return un codigo de error indicando si no falla o el tipo de fallo
  */
int Morphing(const char* fichE1, const char* fichE2, int pasos);

#endif