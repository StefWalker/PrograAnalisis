/*
 * MergeSort.h
 *
 *      Author: Dylan Torres
 *      		2018135751
 *
 *      		Fernanda Lanza
 *      		201
 */

#ifndef MERGESORT_H_
#define MERGESORT_H_
#include <iostream>

using namespace std;

	struct Country;

	void merge(Country array[],int firstIndex,int lastIndex,int middle, int cantColores, int countColors[]);
	void mergesort(Country array[],int firstIndex,int lastIndex, int cantColores, int countColors[]);

	void mergey(Country array[],int firstIndex,int lastIndex,int middle, int cantColores);
	void mergeSorty(Country array[],int firstIndex,int lastIndex, int cantColores);




#endif /* MERGESORT_H_ */
