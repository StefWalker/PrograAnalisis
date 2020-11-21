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

int counter = 0;
/*
void compare(Country countriesx [],Country countriesy [], int countColors[]){
	int position[11];

	for(int first = 1;first < 211;first++){
		if( countriesx[first].Color == countriesx[first-1].Color){

			int position1 = countriesx[first].yPosition;
			int position2 = countriesx[first-1].yPosition;

			if (abs(position2 - position1) < 30){
				if(countriesy[position2].Color == countriesy[position1].Color){
						countriesx[first].Color = 12;
						CountryAdition(countriesx[first]);
						counter++;
				}
				else{
					countriesx[first].Color = countriesy[position1].Color;
						position[countriesy[position1].Color] = first;
						CountryAdition(countriesx[first]);
						counter++;
					}
			}
			else{
				position[countriesx[first].Color] = first;
				CountryAdition(countriesx[first]);
				counter++;
			}
		}
		else{
			if (abs(position[countriesx[first].Color] - first) < 30){
				int position1 = countriesx[first].yPosition;
				int position2 = countriesx[countriesx[first].Color].yPosition;

				if (abs(position2 - position1) < 15){
					if(countriesy[position2].Color == countriesy[position1].Color){
						countriesx[first].Color = 12;
						CountryAdition(countriesx[first]);
						counter++;
					}
					else{
						countriesx[first].Color = countriesy[position1].Color;
						position[countriesy[position1].Color] = first;
						CountryAdition(countriesx[first]);
						counter++;
					}
				}
				else{
					position[countriesx[first].Color] = first;
					CountryAdition(countriesx[first]);
					counter++;
				}
			}
			else{
				position[countriesx[first].Color] = first;
				CountryAdition(countriesx[first]);
				counter++;
			}
		}
		if(counter >= 5){
			printCurrent("DiviveAndConquer");
			counter = 0;
		}
	}
}*/

int distancePoints (int x1, int y1, int x2 , int y2){
	  int distance = sqrt((x1 - y1)*(x1 - y1 ) + (x2 - y2)*(x2 - y2));
	  return distance;
}

void compare(Country countriesx [],Country countriesy [],int countColors[]){
	Country lastPosition[11];
	int limit = 12;

	for(int first = 1;first < 211;first++){
		if (countriesx[first].Color == countriesx[first-1].Color){
			int firstPoint = countriesx[first].yPosition;
			if (countriesy[firstPoint].Color == countriesx[first].Color){

				countriesx[first].Color = 12;
				CountryAdition(countriesx[first]);				//Si son iguales lo deja en blanco
				counter++;
			}
			else{
				countriesx[first].Color = countriesy[firstPoint].Color;
				if (lastPosition[countriesx[first].Color].yPosition != -1){

					int x1 = countriesx[first].x;
					int y1 = countriesx[first].y;
					int x2 = lastPosition[countriesx[first].Color].x;
					int y2 = lastPosition[countriesx[first].Color].y;
					int distance = distancePoints(x1,y1,x2,y2);

					if (distance < limit ){
						countriesx[first].Color = 12;
						CountryAdition(countriesx[first]);				//Si son iguales lo deja en blanco
						counter++;
					}
					else{
						lastPosition[countriesx[first].Color] = countriesx[first];
						CountryAdition(countriesx[first]);				//Si son iguales lo deja en blanco
						counter++;
					}
				}
				else{
					lastPosition[countriesx[first].Color] = countriesx[first];
					CountryAdition(countriesx[first]);				//Si son iguales lo deja en blanco
					counter++;
				}

			}
		}
		else{
			if(countriesx[first].Color == countriesy[countriesx[first].yPosition].Color){
				if (lastPosition[countriesx[first].Color].yPosition != -1){
					int x1 = countriesx[first].x;
					int y1 = countriesx[first].y;		//SI son iguales dejo ese color pero reviso el last
					int x2 = lastPosition[countriesx[first].Color].x;
					int y2 = lastPosition[countriesx[first].Color].y;
					int distance = distancePoints(x1,y1,x2,y2);

					if (distance < limit ){
						countriesx[first].Color = 12;
						CountryAdition(countriesx[first]);				//Si son iguales lo deja en blanco
						counter++;
					}
					else{
						lastPosition[countriesx[first].Color] = countriesx[first];
						CountryAdition(countriesx[first]);				//Si son iguales lo deja en blanco
						counter++;
					}
				}
				else{
					lastPosition[countriesx[first].Color] = countriesx[first];
					CountryAdition(countriesx[first]);				//Si son iguales lo deja en blanco
					counter++;
				}

			}
			else{ // si la y y la x no son iguales paso al contador de colores y debo verificar el que elijo en last
				int positiony = countriesx[first].yPosition;
				if (countColors[countriesx[first].Color] < countColors[countriesy[positiony].Color]){

					if (lastPosition[countriesx[first].Color].yPosition != -1){
						int x1 = countriesx[first].x;
						int y1 = countriesx[first].y;		//SI son iguales dejo ese color pero reviso el last
						int x2 = lastPosition[countriesx[first].Color].x;
						int y2 = lastPosition[countriesx[first].Color].y;
						int distance = distancePoints(x1,y1,x2,y2);

						if (distance < limit ){
							countriesx[first].Color = 12;

							//countColors[countriesy[positiony].Color] ++;
							//countriesx[first].Color = countriesy[first].Color;
							//lastPosition[countriesx[first].Color] = countriesx[first];
							CountryAdition(countriesx[first]);				//Si son iguales lo deja en blanco
							counter++;
						}
						else{
							countColors[countriesx[first].Color] ++;
							countColors[countriesy[positiony].Color] --;
							lastPosition[countriesx[first].Color] = countriesy[first];
							CountryAdition(countriesx[first]);				//Si son iguales lo deja en blanco
							counter++;
						}
					}
					else{
						if (lastPosition[countriesx[first].Color].yPosition != -1){
							int x1 = countriesx[first].x;
							int y1 = countriesx[first].y;		//SI son iguales dejo ese color pero reviso el last
							int x2 = lastPosition[countriesx[first].Color].x;
							int y2 = lastPosition[countriesx[first].Color].y;
							int distance = distancePoints(x1,y1,x2,y2);

							if (distance < limit ){
								countriesx[first].Color = 12;

								//countColors[countriesy[positiony].Color] ++;
								//countriesx[first].Color = countriesy[first].Color;
								//lastPosition[countriesx[first].Color] = countriesx[first];
								CountryAdition(countriesx[first]);				//Si son iguales lo deja en blanco
								counter++;
							}
							else{
								countColors[countriesx[first].Color] --;
								countColors[countriesy[positiony].Color] ++;
								countriesx[first].Color =countriesy[positiony].Color;
								lastPosition[countriesx[first].Color] = countriesx[first];
								CountryAdition(countriesx[first]);				//pedo mental
								counter++;
							}
						}
					}
				}
			}
		}
		if(counter >= 5){
			printCurrent("DiviveAndConquer");
			counter = 0;
		}
	}
}



void subEtapa(Country countriesx [],Country countriesy [], int countColors[], int xBegin, int xEnd, int yEnd){


	for(int i = xBegin; i < xEnd; i++){
		if(countriesx[i].yPosition < yEnd){
			Country tmp = countriesx[i];
			Country tmp2;
			int j = i+1;
			while(tmp2.xPosition == -1){
				if(countriesy[j].yPosition < yEnd){
					tmp = countriesy[j];
				}
				j++;
			}



		}
	}
}

void compareDinamico(Country countriesx [],Country countriesy [], int countColors[]){
	counter = 0;
	Country lastPosition[11];

	Country first = countriesx[0];

	if(first.Color == countriesy[first.yPosition].Color){
		CountryAdition(first);
		lastPosition[first.Color] = first;
		counter++;
	}
	else{
		if(countColors[first.Color] < countColors[countriesy[first.yPosition].Color]){
			CountryAdition(first);
			lastPosition[first.Color] = first;
			counter++;
		}
		else{
			first.Color = countriesy[first.yPosition].Color;
			CountryAdition(first);
			lastPosition[first.Color] = first;
			counter++;
		}
	}
	int xAxys[4] = {211/2,211/2,211,211};
	int yAxys[4] = {211/2,211,211/2,211};
	int xBegin[4] = {1,1,(211/2)+1,(211/2)+1};
	for(int i = 0; i < 4; i++){
		subEtapa(countriesx,countriesy,countColors,xBegin[i],xAxys[i],yAxys[i]);
	}

}


/*
float distance(int x1, int y1, int x2, int y2) {

	float distance =sqrt(pow(x2 - x1, 2) +  pow(y2 - y1, 2) * 1.0);
	return distance;
}
*/




/*
Country tmp = countriesx[i];

if(tmp.Color == countriesy[tmp.y].Color){

	CountryAdition(countriesx[tmp]);
	lastPosition[first.Color] = tmp;
	counter++;
}
else{
	if(countColors[first.Color] > countColors[countriesy[tmp.y].Color]){

		CountryAdition(countriesx[tmp]);
		lastPosition[first.Color] = tmp;
		counter++;
	}
	else{
		first.Color = countriesy[tmp.y].Color;

		CountryAdition(countriesx[tmp]);
		lastPosition[first.Color] = tmp;
		counter++;
	}
}
*/
