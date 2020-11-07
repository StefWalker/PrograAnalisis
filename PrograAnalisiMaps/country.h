/*
 * country.h
 *
 *  Created on: Nov 6, 2020
 *      Author: dylan
 */

#ifndef COUNTRY_H_
#define COUNTRY_H_

#include <iostream>

using namespace std;

struct Point{
	int x;
	int y;
	Point(int px, int py){
		this->x = px;
		this->y = py;
	}
};



struct Country{
	string ID;
	string Color;
	Point Centro;
	bool visitado;
	Country adjacentes [10];

	Country(string pID, string pColor, Point pCentro){
		this->ID = pID;
		this->Color = pColor;
		this->Centro = pCentro;
		this->visitado = false;
	}

	Country(string pID, string pColor, int px, int py){
		this->ID = pID;
		this->Color = pColor;
		this->Centro.x = px;
		this->Centro.y = py;
		this->visitado = false;
	}
};



#endif /* COUNTRY_H_ */
