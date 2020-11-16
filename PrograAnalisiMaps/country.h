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
	int Color;
	Point *Centro;
	bool visitado;

	Country(string pID, Point *pCentro){
		this->ID = pID;
		this->Color = 12;
		this->Centro = pCentro;
		this->visitado = false;
	}

	Country(string pID, int px, int py){
		this->ID = pID;
		this->Color = 12;
		this->Centro->x = px;
		this->Centro->y = py;
		this->visitado = false;
	}

	Country(){
		this->ID = "";
		this->Color = 12;
		this->Centro.x = 0;
		this->Centro.y = 0;
		this->visitado = false;
	}
};



#endif /* COUNTRY_H_ */
