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

	void merge(Country array[],int firstIndex,int lastIndex,int middle);
	void mergesort(Country array[],int firstIndex,int lastIndex);

	void mergey(int array[],int firstIndex,int lastIndex,int middle);
	void mergeSorty(int array[],int firstIndex,int lastIndex);




#endif /* MERGESORT_H_ */
