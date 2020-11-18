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
	Point(){
		this->x = 0;
		this->y = 0;
	}
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

	Country(){
		this->ID = "";
		this->Color = 12;
		this->Centro = new Point();
		this->visitado = false;
	}
};


struct Node{
	int x;
	int y;
	Country *pais;

	Node(){
		this->x = 0;
		this->y = 0;
		pais = new Country();
	}
};


struct DataArray{
	Node *nodo[211];

	DataArray(){
		for(int i = 0; i < 211; i++){
			this->nodo[i] = new Node();
		}
	}
};



#endif /* COUNTRY_H_ */
