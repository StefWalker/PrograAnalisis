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

struct Country{
	string ID;
	int xPosition ;
	int yPosition = -1;
	int Color = 12;
	int x;
	int y;
	string d;
	bool visitado;

};

void XMLLoader(Country paises[]);
int tester(int cantColores);

#endif /* COUNTRY_H_ */
