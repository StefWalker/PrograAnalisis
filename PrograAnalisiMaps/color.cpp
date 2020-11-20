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

    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 11);
    last = addAfter(last, 10, 8);

    traverse(last);


}

