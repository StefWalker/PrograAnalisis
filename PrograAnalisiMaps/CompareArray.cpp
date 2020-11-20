/*
 * CompareArray.cpp
 *
 *  Created on: 18 nov. 2020
 *      Author: ferla
 */
#include "country.h"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "SVG.h"

int counter = 0;\

void compare(Country countriesx [],Country countriesy [], int countColors[]){
	int position[11];

	for(int first = 1;first < 211;first++){
		if( countriesx[first].Color == countriesx[first-1].Color){

			int position1 = countriesx[first].yPosition;
			int position2 = countriesx[first-1].yPosition;

			if (abs(position2 - position1) < 5){
				if(countriesy[position2].Color == countriesy[position1].Color){
						// tirar blanco
				}
				else{
					countriesx[first].Color = countriesy[position1].Color;
						position[countriesy[position1].Color] = first;
					}
			}
			else{
				position[countriesx[position1].Color] = first;
			}
		}
		else{
			if (abs(position[countriesx[first].Color] - first) < 5){
				int position1 = countriesx[first].yPosition;
				int position2 = countriesx[countriesx[first].Color].yPosition;

				if (abs(position2 - position1) < 5){
					if(countriesy[position2].Color == countriesy[position1].Color){
										// tirar blanco
						}
					else{
						countriesx[first].Color = countriesy[position1].Color;
						position[countriesy[position1].Color] = first;
					}
				}
				else{
					position[countriesx[position1].Color] = first;
				}
			}
			else{
				position[countriesx[first].Color] = first;
			}
		}
	}
}


/*
float distance(int x1, int y1, int x2, int y2) {

	float distance =sqrt(pow(x2 - x1, 2) +  pow(y2 - y1, 2) * 1.0);
	return distance;
}
*/
