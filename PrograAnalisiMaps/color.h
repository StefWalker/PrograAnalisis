/*
 * color.h
 *
 *  Created on: 17 nov. 2020
 *      Author: dylan
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>

using namespace std;

struct Color{
	int value;
	string color;
	Color *next;

	Color(){
		this->value = 0;
		this->color = NULL;
		this->next = new Color;
	}
};



#endif /* COLOR_H_ */
