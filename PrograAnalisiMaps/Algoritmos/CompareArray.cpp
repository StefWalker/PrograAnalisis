/*
 * CompareArray.cpp
 *
 *      Author: Dylan Torres
 *      		2018135751
 *
 *      		Fernanda Lanza
 *      		201
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
			printCurrent("Divide&Conquer/DiviveAndConquer");
			counter = 0;
		}
	}
}



void subEtapa(Country countriesx [],Country countriesy [], int countColors[], int xBegin, int xEnd, int yBegin, int yEnd, int ci){
	cout << "entra" << endl;
	Country lastPosition[11];
	Country first = countriesx[xBegin];
	int xDistance = 5;
	int limitDistance = 15;
	cout << "entra1" << endl;
	while(first.xPosition == -1 && xBegin < xEnd){ // busca la primera posicion en x valida
		if(countriesx[xBegin].yPosition < yEnd && countriesx[xBegin].yPosition > yBegin){
			first = countriesx[xBegin];
		}
		xBegin++;
	}
	cout << "sale1" << endl;

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
	// ya con el primero con color seteado, se inicia el algoritmo
	Country last = first;
	Country tmp = last;
	for(int i = xBegin; i < xEnd; i++){
		cout << "ciclo" << xBegin << endl;
		if(countriesx[i].yPosition < yEnd && countriesx[i].yPosition > yBegin){
			Country tmp2 = countriesx[i];
			if(tmp.Color != tmp2.Color && tmp2.Color != countriesy[tmp2.yPosition].Color && tmp.Color != countriesy[tmp2.yPosition].Color){
				if(countColors[tmp2.Color] > countColors[countriesy[tmp2.yPosition].Color]){
					countColors[tmp2.Color]--;
					countColors[countriesy[tmp2.yPosition].Color]++;

					tmp2.Color = countriesy[tmp2.yPosition].Color;
				}

			}
			else if(tmp.Color == tmp2.Color && tmp2.Color == countriesy[tmp2.yPosition].Color){
				tmp2.Color = 12;
			}
			else if(tmp.Color == tmp2.Color && tmp2.Color != countriesy[tmp2.yPosition].Color){
				tmp2.Color = countriesy[tmp2.yPosition].Color;
			}

			if(tmp2.Color != 12){
				Country tmp3 = lastPosition[tmp2.Color];
				if(tmp3.xPosition != -1){
					if(abs(tmp3.xPosition - tmp2.xPosition) <= xDistance){
						if(distancePoints(tmp3.xPosition, tmp3.yPosition, tmp2.xPosition,tmp2.yPosition) > limitDistance){
							CountryAdition(tmp2);
							lastPosition[tmp2.Color] = tmp2;
							counter++;
						}
						else{
							tmp2.Color = 12;
							CountryAdition(tmp2);
							counter++;
						}
					}
					else{
						lastPosition[tmp2.Color] = tmp2;
						CountryAdition(tmp2);
						counter++;
					}
				}
				else{
					lastPosition[tmp2.Color] = tmp2;
					CountryAdition(tmp2);
					counter++;
					}
			}
			else{
				CountryAdition(tmp2);
				counter++;
			}
		last = tmp2;
		}
		if(counter >= 5){
			printCurrent("Dinamico/Dinamico");
			counter = 0;
		}
	}
}

void compareDinamico(Country countriesx [],Country countriesy [], int countColors[]){
	counter = 0;

	int xAxys[4] = {211/2,211/2,211,211};
	int yAxys[4] = {211/2,211,211/2,211};
	int xBegin[4] = {0,0,(211/2)+1,(211/2)+1};
	int yBegin[4] = {0,(211/2)+1,0,(211/2)+1};
	for(int i = 0; i < 4; i++){
		subEtapa(countriesx,countriesy,countColors,xBegin[i],xAxys[i],yBegin[i],yAxys[i],i);
	}
	cout << "Dinamico Completado" << endl;
}

