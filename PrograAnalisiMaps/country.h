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

struct Country{
	string ID;
	int xPosition;
	int yPosition;
	int Color = 12;
	int x;
	int y;
	string d;
	bool visitado;
/*
	Country(string pID, int pX, int pY){
		this->ID = pID;
		this->Color = 12;
		this->x = pX;
		this->y = pY;
		this->visitado = false;
	}

	Country(){
		this->ID = "";
		this->Color = 12;
		this->x = 0;
		this->y = 0;
		this->visitado = false;
	}*/
};

/*
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
*/
void XMLLoader(Country paises[]);
int tester(int cantColores);

#endif /* COUNTRY_H_ */
