/*
 * color.cpp
 *
 *  Created on: 18 nov. 2020
 *      Author: dylan
 */

#include "color.h"

#include<iostream>
using namespace std;


// Driven Program

void colorMaker(int cantColores)
{
    struct Color *last = NULL;

    last = addToEmpty(last, 1);

    for(int i = 0; i < cantColores; i++){
    	last = addEnd(last, i);
    }

}

