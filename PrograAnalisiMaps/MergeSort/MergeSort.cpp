/*
 * MergeSort.cpp
 *
 *      Author: Dylan Torres
 *      		2018135751
 *
 *      		Fernanda Lanza
 *      		201
 */

#include "MergeSort.h"
#include "C:\Users\dylan\Desktop\GitHub\PrograAnalisis\PrograAnalisiMaps\country.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

void mergeSortX(Country pArray [],int pFirstIndex,int pLastIndex, int pCantColores,int pCountColors[]){

	if(pFirstIndex < pLastIndex){

		int middle = (pFirstIndex + pLastIndex) /2;

		mergeSortX(pArray,pFirstIndex,middle,pCantColores,pCountColors);
		mergeSortX(pArray,middle+1,pLastIndex,pCantColores,pCountColors);

		mergeX(pArray,pFirstIndex,pLastIndex,middle,pCantColores,pCountColors);
	}
}

void mergeX(Country pArray[],int pFirstIndex,int pLastIndex,int pMiddle, int pCantColores,int pCountColors[]){ //Función encargada de ordenar el arreglo

	int left = pFirstIndex;
	int right = pMiddle+1;
	int counter = 0;

    Country temp [pLastIndex - pFirstIndex+1];

	while ( left <= pMiddle && right <= pLastIndex){
		if(pArray[left].x < pArray[right].x){

			temp[counter++] = pArray[left++];
		}
		else{
			temp[counter++] = pArray[right++];
		}
	}
	while ( left <= pMiddle){
		temp[counter++] = pArray[left++];
	}

	while (right <= pLastIndex) {
		temp[counter++] = pArray[right++];
	}

	for( left = pFirstIndex; left <= pLastIndex; left++){
		pArray[left] = temp[left-pFirstIndex];
		if(pArray[left].Color == 12){
			int random = rand() % pCantColores;
			pArray[left].Color = random;
			pCountColors[random] = pCountColors[random]+1;
		}
	}

	//delete temp;
}

void mergeSortY(Country pArray [],int pFirstIndex,int pLastIndex, int pCantColores){
	if(pFirstIndex < pLastIndex){

		int middle = (pFirstIndex + pLastIndex) /2;

		mergeSortY(pArray,pFirstIndex,middle,pCantColores);
		mergeSortY(pArray,middle+1,pLastIndex,pCantColores);
		mergeY(pArray,pFirstIndex,pLastIndex,middle,pCantColores);
	}
}

void mergeY(Country pArray[],int pFirstIndex,int pLastIndex,int pMiddle, int pCantColores){ //Función encargada de ordenar el arreglo

	int left = pFirstIndex;
		int right = pMiddle+1;
		int counter = 0;

	    Country temp [pLastIndex - pFirstIndex+1];

		while ( left <= pMiddle && right <= pLastIndex){
			if(pArray[left].y < pArray[right].y){

				temp[counter++] = pArray[left++];
			}
			else{
				temp[counter++] = pArray[right++];
			}
		}
		while ( left <= pMiddle){
			temp[counter++] = pArray[left++];
		}

		while (right <= pLastIndex) {
			temp[counter++] = pArray[right++];
		}

		for( left = pFirstIndex; left <= pLastIndex; left++){
			pArray[left] = temp[left-pFirstIndex];
			if(pArray[left].Color == 12){
				int random = rand() % pCantColores;
				pArray[left].Color = random;

			}
		}

		//delete temp;
}
