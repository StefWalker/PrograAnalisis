/*
 * color.h
 *
 *      Author: Dylan Torres
 *      		2018135751
 *
 *      		Fernanda Lanza
 *      		2018133074
 */

#ifndef COLOR_H_
#define COLOR_H_

#include <iostream>

using namespace std;

//string array[11] = {"azul","rojo","amarillo","verde","naranja","morado","rosado","cafe","vino","celeste","verdeOscuro"};
string arrayColor[11] = {"fill:#0000FF;fill-rule:evenodd","fill:#FF0000;fill-rule:evenodd","fill:#FFFF00;fill-rule:evenodd",
		"fill:#00FF00;fill-rule:evenodd","fill:#F76D10;fill-rule:evenodd","fill:#9933ff;fill-rule:evenodd","fill:#FF007E;fill-rule:evenodd"
		,"fill:#A62A2A;fill-rule:evenodd","fill:#00FFFF;fill-rule:evenodd","fill:#770000;fill-rule:evenodd","fill:#007800;fill-rule:evenodd"};

struct Color{
	int value;
	string color;
	Color *next;

};

struct Color *addToEmpty(struct Color *last, int value)
{
    // This function is only for empty list
    if (last != NULL)
      return last;

    // Creating a node dynamically.
    struct Color *temp =
           (struct Color*)malloc(sizeof(struct Color));

    // Assigning the data.
    temp -> value = value;
    temp -> color = arrayColor[value];
    last = temp;

    // Creating the link.
    last -> next = last;

    return last;
}

struct Color *addBegin(struct Color *last, int value)
{
    if (last == NULL)
        return addToEmpty(last, value);

    struct Color *temp =
            (struct Color *)malloc(sizeof(struct Color));

    temp -> value = value;
    temp -> color = arrayColor[value];
    temp -> next = last -> next;
    last -> next = temp;

    return last;
}

struct Color *addEnd(struct Color *last, int value)
{
    if (last == NULL)
        return addToEmpty(last, value);

    struct Color *temp =
        (struct Color *)malloc(sizeof(struct Color));

    temp -> value = value;
    temp -> color = arrayColor[value];
    temp -> next = last -> next;
    last -> next = temp;
    last = temp;

    return last;
}

struct Color *addAfter(struct Color *last, int data, int item)
{
    if (last == NULL)
        return NULL;

    struct Color *temp, *p;
    p = last -> next;
    do
    {
        if (p ->value == item)
        {
            temp = (struct Color *)malloc(sizeof(struct Color));
            temp -> value = data;
            temp -> color = arrayColor[data];
            temp -> next = p -> next;
            p -> next = temp;

            if (p == last)
                last = temp;
            return last;
        }
        p = p -> next;
    }  while(p != last -> next);

    cout << item << " not present in the list." << endl;
    return last;

}

void traverse(struct Color *last)
{
    struct Color *p;

    // If list is empty, return.
    if (last == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    // Pointing to first Node of the list.
    p = last -> next;

    // Traversing the list.
    do
    {
        cout << p -> value << " ";
        p = p -> next;

    }
    while(p != last->next);

}


void colorMaker();

#endif /* COLOR_H_ */
