/*
 * color.cpp
 *
 *      Author: Dylan Torres
 *      		2018135751
 *
 *      		Fernanda Lanza
 *      		201
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

