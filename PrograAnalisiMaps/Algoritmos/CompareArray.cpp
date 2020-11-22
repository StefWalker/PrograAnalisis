/*
 * CompareArray.cpp
 *
 *      Author: Dylan Torres
 *      		2018135751
 *
 *      		Fernanda Lanza
 *      		2018133074
 */

#include "C:\Users\dylan\Desktop\GitHub\PrograAnalisis\PrograAnalisiMaps\country.h"
#include "C:\Users\dylan\Desktop\GitHub\PrograAnalisis\PrograAnalisiMaps\SVG\SVG.h"
#include <iostream>
#include <cstdlib>
#include <math.h>

int counter = 0;

int distancePoints (int x1, int y1, int x2 , int y2){
	  int distance = sqrt((x1 - y1)*(x1 - y1 ) + (x2 - y2)*(x2 - y2));
	  return distance;
}

void compare(Country pCountriesX [],Country pCountriesY [],int pCountColors[]){

	Country lastPosition[11];
	int limit = 12;

	for(int first = 1;first < 211;first++){
		if (pCountriesX[first].Color == pCountriesX[first-1].Color){
			int firstPoint = pCountriesX[first].yPosition;
			if (pCountriesY[firstPoint].Color == pCountriesX[first].Color){

				pCountriesX[first].Color = 12;
				CountryAdition(pCountriesX[first]);				//Si son iguales lo deja en blanco
				counter++;
			}
			else{
				pCountriesX[first].Color = pCountriesY[firstPoint].Color;
				if (lastPosition[pCountriesX[first].Color].yPosition != -1){

					int x1 = pCountriesX[first].x;
					int y1 = pCountriesX[first].y;
					int x2 = lastPosition[pCountriesX[first].Color].x;
					int y2 = lastPosition[pCountriesX[first].Color].y;
					int distance = distancePoints(x1,y1,x2,y2);

					if (distance < limit ){
						pCountriesX[first].Color = 12;
						CountryAdition(pCountriesX[first]);				//Si son iguales lo deja en blanco
						counter++;
					}
					else{
						lastPosition[pCountriesX[first].Color] = pCountriesX[first];
						CountryAdition(pCountriesX[first]);				//Si son iguales lo deja en blanco
						counter++;
					}
				}
				else{
					lastPosition[pCountriesX[first].Color] = pCountriesX[first];
					CountryAdition(pCountriesX[first]);				//Si son iguales lo deja en blanco
					counter++;
				}

			}
		}
		else{
			if(pCountriesX[first].Color == pCountriesY[pCountriesX[first].yPosition].Color){
				if (lastPosition[pCountriesX[first].Color].yPosition != -1){
					int x1 = pCountriesX[first].x;
					int y1 = pCountriesX[first].y;		//SI son iguales dejo ese color pero reviso el last
					int x2 = lastPosition[pCountriesX[first].Color].x;
					int y2 = lastPosition[pCountriesX[first].Color].y;
					int distance = distancePoints(x1,y1,x2,y2);

					if (distance < limit ){
						pCountriesX[first].Color = 12;
						CountryAdition(pCountriesX[first]);				//Si son iguales lo deja en blanco
						counter++;
					}
					else{
						lastPosition[pCountriesX[first].Color] = pCountriesX[first];
						CountryAdition(pCountriesX[first]);				//Si son iguales lo deja en blanco
						counter++;
					}
				}
				else{
					lastPosition[pCountriesX[first].Color] = pCountriesX[first];
					CountryAdition(pCountriesX[first]);				//Si son iguales lo deja en blanco
					counter++;
				}

			}
			else{ // si la y y la x no son iguales paso al contador de colores y debo verificar el que elijo en last
				int positiony = pCountriesX[first].yPosition;
				if (pCountColors[pCountriesX[first].Color] < pCountColors[pCountriesY[positiony].Color]){

					if (lastPosition[pCountriesX[first].Color].yPosition != -1){
						int x1 = pCountriesX[first].x;
						int y1 = pCountriesX[first].y;		//SI son iguales dejo ese color pero reviso el last
						int x2 = lastPosition[pCountriesX[first].Color].x;
						int y2 = lastPosition[pCountriesX[first].Color].y;
						int distance = distancePoints(x1,y1,x2,y2);

						if (distance < limit ){
							pCountriesX[first].Color = 12;

							CountryAdition(pCountriesX[first]);				//Si son iguales lo deja en blanco
							counter++;
						}
						else{
							pCountColors[pCountriesX[first].Color] ++;
							pCountColors[pCountriesY[positiony].Color] --;
							lastPosition[pCountriesX[first].Color] = pCountriesY[first];
							CountryAdition(pCountriesX[first]);				//Si son iguales lo deja en blanco
							counter++;
						}
					}
					else{
						if (lastPosition[pCountriesX[first].Color].yPosition != -1){
							int x1 = pCountriesX[first].x;
							int y1 = pCountriesX[first].y;		//SI son iguales dejo ese color pero reviso el last
							int x2 = lastPosition[pCountriesX[first].Color].x;
							int y2 = lastPosition[pCountriesX[first].Color].y;
							int distance = distancePoints(x1,y1,x2,y2);

							if (distance < limit ){
								pCountriesX[first].Color = 12;

								CountryAdition(pCountriesX[first]);				//Si son iguales lo deja en blanco
								counter++;
							}
							else{
								pCountColors[pCountriesX[first].Color] --;
								pCountColors[pCountriesY[positiony].Color] ++;
								pCountriesX[first].Color =pCountriesY[positiony].Color;
								lastPosition[pCountriesX[first].Color] = pCountriesX[first];
								CountryAdition(pCountriesX[first]);				//pedo mental
								counter++;
							}
						}
					}
				}
			}
		}
		if(counter >= 5){
			printCurrent("Divide&Conquer/DiviveAndConquer");
			counter = 0;
		}
	}
	cout << "D&Q Completado" << endl;
}



void subEtapa(Country pCountriesX [],Country pCountriesY [], int pCountColors[], int xBegin, int xEnd, int yBegin, int yEnd, int ci){
	Country lastPosition[11];
	Country first = pCountriesX[xBegin];
	int xDistance = 5;
	int limitDistance = 15;
	while(first.xPosition == -1 && xBegin < xEnd){ // busca la primera posicion en x valida
		if(pCountriesX[xBegin].yPosition < yEnd && pCountriesX[xBegin].yPosition > yBegin){
			first = pCountriesX[xBegin];
		}
		xBegin++;
	}

	if(first.Color == pCountriesY[first.yPosition].Color){
			CountryAdition(first);
			lastPosition[first.Color] = first;
			counter++;
	}
	else{
		if(pCountColors[first.Color] < pCountColors[pCountriesY[first.yPosition].Color]){
			CountryAdition(first);
			lastPosition[first.Color] = first;
			counter++;
		}
		else{
			first.Color = pCountriesY[first.yPosition].Color;
			CountryAdition(first);
			lastPosition[first.Color] = first;
			counter++;
		}
	}
	// ya con el primero con color seteado, se inicia el algoritmo
	Country last = first;
	for(int zone = xBegin; zone < xEnd; zone++){

		if(pCountriesX[zone].yPosition < yEnd && pCountriesX[zone].yPosition > yBegin){

			Country nextPosition = pCountriesX[zone];
			if(last.Color != nextPosition.Color && nextPosition.Color != pCountriesY[nextPosition.yPosition].Color && last.Color != pCountriesY[nextPosition.yPosition].Color){
				if(pCountColors[nextPosition.Color] > pCountColors[pCountriesY[nextPosition.yPosition].Color]){
					pCountColors[nextPosition.Color]--;
					pCountColors[pCountriesY[nextPosition.yPosition].Color]++;

					nextPosition.Color = pCountriesY[nextPosition.yPosition].Color;
				}

			}
			else if(last.Color == nextPosition.Color && nextPosition.Color == pCountriesY[nextPosition.yPosition].Color){
				nextPosition.Color = 12;
			}
			else if(last.Color == nextPosition.Color && nextPosition.Color != pCountriesY[nextPosition.yPosition].Color){
				nextPosition.Color = pCountriesY[nextPosition.yPosition].Color;
			}

			if(nextPosition.Color != 12){

				Country colorSearch = lastPosition[nextPosition.Color];

				if(last.xPosition != -1){
					if(abs(colorSearch.xPosition - nextPosition.xPosition) <= xDistance){
						if(distancePoints(colorSearch.xPosition, colorSearch.yPosition, nextPosition.xPosition,nextPosition.yPosition) > limitDistance){
							CountryAdition(nextPosition);
							lastPosition[nextPosition.Color] = nextPosition;
							counter++;
						}
						else{
							nextPosition.Color = 12;
							CountryAdition(nextPosition);
							counter++;
						}
					}
					else{
						lastPosition[nextPosition.Color] = nextPosition;
						CountryAdition(nextPosition);
						counter++;
					}
				}
				else{
					lastPosition[nextPosition.Color] = nextPosition;
					CountryAdition(nextPosition);
					counter++;
					}
			}
			else{
				CountryAdition(nextPosition);
				counter++;
			}
		last = nextPosition;
		}
		if(counter >= 5){
			printCurrent("Dinamico/Dinamico");
			counter = 0;
		}
	}
}

void compareDinamico(Country pCountriesX [],Country pCountriesY [], int pCountColors[]){
	counter = 0;

	int xAxys[4] = {211/2,211/2,211,211};
	int yAxys[4] = {211/2,211,211/2,211};
	int xBegin[4] = {0,0,(211/2)+1,(211/2)+1};
	int yBegin[4] = {0,(211/2)+1,0,(211/2)+1};
	for(int i = 0; i < 4; i++){
		subEtapa(pCountriesX,pCountriesY,pCountColors,xBegin[i],xAxys[i],yBegin[i],yAxys[i],i);
	}
	cout << "Dinamico Completado" << endl;
}

