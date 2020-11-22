/*
 * country.h
 *
 *      Author: Dylan Torres
 *      		2018135751
 *
 *      		Fernanda Lanza
 *      		201
 */

#ifndef COUNTRY_H_
#define COUNTRY_H_

#include <iostream>

using namespace std;

/* Estructura principal del algoritmo
 * Basada en los puntos clave de la lectura de paises
 * y en variables para su uso dinamico
 * */
struct Country{
	string ID;				// ID del pais (CR,US)
	int xPosition ;			// Posicion en el array futuro en X
	int yPosition = -1;     // Posicion en el array futuro en X
	int Color = 12;			// Valor del color asignado (12 = Blanco)
	int x;					// Valor en X de la lectura del mapa
	int y;					// Valor en Y de la lectura del mapa
	string coordenates;		// Valor d de la lectura
};

void XMLLoader(Country pCountries[]);	// Funcion encargada de la carga de datos provenientes
int startProcedure(int cantColores);    // Funcion principal del algoritmo encargada de crear toda la
										//    estructura principal para la aplicacion de los algoritmos

#endif /* COUNTRY_H_ */
