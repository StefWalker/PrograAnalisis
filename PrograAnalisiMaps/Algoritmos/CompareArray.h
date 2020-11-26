/*
 * CompareArray.h
 *
 *      Author: Dylan Torres
 *      		2018135751
 *
 *      		Fernanda Lanza
 *      		2018133074
 */

#ifndef COMPAREARRAY_H_
#define COMPAREARRAY_H_

#include <iostream>
using namespace std;

struct Country;

void compare(Country pCountriesX [],Country pCountriesY [], int pCountColors []);
void compareDinamico(Country pCountriesX [],Country pCountriesY [], int pCountColors[]);
void compareBacktracking(Country pCountriesX [],Country pCountriesY [], int pCountColors[]);


#endif /* COMPAREARRAY_H_ */
