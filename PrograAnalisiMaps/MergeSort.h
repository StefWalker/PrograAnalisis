/*
 * MergeSort.h
 *
 *  Created on: 15 nov. 2020
 *      Author: Dylan Torres Walker
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_
#include <iostream>
#include "Country.h"


using namespace std;

	void merge(Country array[],int firstIndex,int lastIndex,int middle, int cantColores, int countColors[]);
	void mergesort(Country array[],int firstIndex,int lastIndex, int cantColores, int countColors[]);

	void mergey(Country array[],int firstIndex,int lastIndex,int middle, int cantColores);
	void mergeSorty(Country array[],int firstIndex,int lastIndex, int cantColores);




#endif /* MERGESORT_H_ */
