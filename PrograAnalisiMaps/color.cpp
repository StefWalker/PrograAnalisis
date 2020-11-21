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

void colorMaker()
{
    struct Color *last = NULL;

    last = addToEmpty(last, 1);
    last = addEnd(last, 2);
    last = addEnd(last, 3);
    last = addEnd(last, 4);
    last = addEnd(last, 5);
    last = addEnd(last, 6);
    last = addEnd(last, 7);
    last = addEnd(last, 8);
    last = addEnd(last, 9);
    last = addEnd(last, 10);
    last = addEnd(last, 11);

    traverse(last);


}

