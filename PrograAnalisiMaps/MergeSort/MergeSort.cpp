/*
 * MergeSort.cpp
 *
 *      Author: Dylan Torres
 *      		2018135751
 *
 *      		Fernanda Lanza
 *      		2018133074
 */

#include "MergeSort.h"
#include "C:\Users\dylan\Desktop\GitHub\PrograAnalisis\PrograAnalisiMaps\country.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

/*
 * Función que divide el array en subarrays por medio de la recursividad
 * input : array de paises, primer elemento , cantidad de colores, array de cantidad de colores y ultimo elemento.
 * outputs: ---------------
 */
void mergeSortX(Country pArray [],int pFirstIndex,int pLastIndex, int pCantColores,int pCountColors[]){

	if(pFirstIndex < pLastIndex){

		int middle = (pFirstIndex + pLastIndex) /2;

		mergeSortX(pArray,pFirstIndex,middle,pCantColores,pCountColors);
		mergeSortX(pArray,middle+1,pLastIndex,pCantColores,pCountColors);

		mergeX(pArray,pFirstIndex,pLastIndex,middle,pCantColores,pCountColors);
	}
}

/*
 * Función que ordena los subarray y concatenan con el de la par , hasta ordenar el final.Su llave es la coordenanda x del punto.
 * input : array de paises, primer elemento , cantidad de colores, array de cantidad de colores y ultimo elemento.
 * outputs: -----
 */
void mergeX(Country pArray[],int pFirstIndex,int pLastIndex,int pMiddle, int pCantColores,int pCountColors[]){

	int left = pFirstIndex;
	int right = pMiddle+1;
	int counter = 0;

    Country replace [pLastIndex - pFirstIndex+1];

	while ( left <= pMiddle && right <= pLastIndex){
		if(pArray[left].x < pArray[right].x){

			replace[counter++] = pArray[left++];
		}
		else{
			replace[counter++] = pArray[right++];
		}
	}
	while ( left <= pMiddle){
		replace[counter++] = pArray[left++];
	}

	while (right <= pLastIndex) {
		replace[counter++] = pArray[right++];
	}

	for( left = pFirstIndex; left <= pLastIndex; left++){
		pArray[left] = replace[left-pFirstIndex];						//Asigna los colores de manera aleatorea
		if(pArray[left].Color == 12){
			int random = rand() % pCantColores;
			pArray[left].Color = random;							//Suma uno al diigito que se encuentra en el array en la posicion del color .
			pCountColors[random] = pCountColors[random]+1;
		}
	}
}

/*
 * Función que divide el array en subarrays por medio de la recursividad.
 * input : array de paises, primer elemento , cantidad de colores, array de cantidad de colores y ultimo elemento.
 * outputs: ---------------
 */
void mergeSortY(Country pArray [],int pFirstIndex,int pLastIndex, int pCantColores){
	if(pFirstIndex < pLastIndex){

		int middle = (pFirstIndex + pLastIndex) /2;

		mergeSortY(pArray,pFirstIndex,middle,pCantColores);
		mergeSortY(pArray,middle+1,pLastIndex,pCantColores);
		mergeY(pArray,pFirstIndex,pLastIndex,middle,pCantColores);
	}
}

/*
 * Función que ordena los subarray y concatenan con el de la par , hasta ordenar el final.Su llave es la cordenada y del centro
 * input : array de paises, primer elemento , cantidad de colores, array de cantidad de colores y ultimo elemento.
 * outputs: -----
 */
void mergeY(Country pArray[],int pFirstIndex,int pLastIndex,int pMiddle, int pCantColores){ //Función encargada de ordenar el arreglo

	int left = pFirstIndex;
		int right = pMiddle+1;
		int counter = 0;

	    Country temporal [pLastIndex - pFirstIndex+1];

		while ( left <= pMiddle && right <= pLastIndex){
			if(pArray[left].y < pArray[right].y){

				temporal[counter++] = pArray[left++];
			}
			else{
				temporal[counter++] = pArray[right++];
			}
		}
		while ( left <= pMiddle){
			temporal[counter++] = pArray[left++];
		}

		while (right <= pLastIndex) {
			temporal[counter++] = pArray[right++];
		}

		for( left = pFirstIndex; left <= pLastIndex; left++){
			pArray[left] = temporal[left-pFirstIndex];
			if(pArray[left].Color == 12){
				int random = rand() % pCantColores;
				pArray[left].Color = random;

			}
		}

}
