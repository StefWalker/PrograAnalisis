/*
 * MergeSort.cpp
 *
 *  Created on: 15 nov. 2020
 *      Author: ferla
 */

#include "MergeSort.h"
#include "country.h"
#include <iostream>


using namespace std;

void mergesort(Country array [],int firstIndex,int lastIndex){

	if(firstIndex < lastIndex){

		int middle = (firstIndex + lastIndex) /2;

		mergesort(array,firstIndex,middle);
		mergesort(array,middle+1,lastIndex);

		merge(array,firstIndex,lastIndex,middle);
	}
}

void merge(Country array[],int firstIndex,int lastIndex,int middle){ //Función encargada de ordenar el arreglo

	int left=firstIndex;
	int right = middle+1;
	int counter=0;

    Country temp [lastIndex - firstIndex+1];

	while ( left <= middle && right <= lastIndex){
		if(array[left].x < array[right].x){

			temp[counter++] = array[left++];
		}
		else{
			temp[counter++] = array[right++];
		}
	}
	while ( left <= middle){
		temp[counter++] = array[left++];
	}

	while (right <= lastIndex) {
		temp[counter++] = array[right++];
	}
	for( left = firstIndex; left <= lastIndex; left++){
		array[left] = temp[left-firstIndex];
	}

	delete temp;
}

void mergeSorty(int array [],int firstIndex,int lastIndex){

	if(firstIndex < lastIndex){

		int middle = (firstIndex + lastIndex) /2;

		mergeSorty(array,firstIndex,middle);
		mergeSorty(array,middle+1,lastIndex);

		mergey(array,firstIndex,lastIndex,middle);
	}
}

void mergey(int array[],int firstIndex,int lastIndex,int middle){ //Función encargada de ordenar el arreglo

	int left=firstIndex;
	int right = middle+1;
	int counter=0;

    int temp [lastIndex - firstIndex+1];

	while ( left <= middle && right <= lastIndex){
		if(array[left] < array[right]){

			temp[counter++] = array[left++];
		}
		else{
			temp[counter++] = array[right++];
		}
	}
	while ( left <= middle){
		temp[counter++] = array[left++];
	}

	while (right <= lastIndex) {
		temp[counter++] = array[right++];
	}
	for( left = firstIndex; left <= lastIndex; left++){
		array[left] = temp[left-firstIndex];
	}

	delete temp;
}
