/*
 * CompareArray.cpp
 *
 *      Author: Dylan Torres
 *      		2018135751
 *
 *      		Fernanda Lanza
 *      		2018133074
 */

//#include "C:\Users\ferla\OneDrive\Documents\GitHub\PrograAnalisis\PrograAnalisiMaps\country.h"
//#include "C:\Users\ferla\OneDrive\Documents\GitHub\PrograAnalisis\PrograAnalisiMaps\SVG\SVG.h"
#include "C:\Users\dylan\Desktop\GitHub\PrograAnalisis\PrograAnalisiMaps\country.h"
#include "C:\Users\dylan\Desktop\GitHub\PrograAnalisis\PrograAnalisiMaps\SVG\SVG.h"
#include <iostream>
#include <cstdlib>
#include <math.h>
#include <chrono>

int counter = 0;
int whites;
Country arrayPaises[11][100];

/*
 * Función que calcula la distancia entre dos puntos.
 * input : la unidad de las coordenadas x y y de los puntos
 * outputs: un integer, la distancia entre dos puntos.
 */
int distancePoints (int x1, int y1, int x2 , int y2){
	  int distance = sqrt((x1 - y1)*(x1 - y1 ) + (x2 - y2)*(x2 - y2));
	  return distance;
}

/*
 * Función que realiza la comparación para finalizar el divide y vencerás.
 * input : array de paises en eje x y, cantidad de colores que chiva x objetivo penstado.
 * outputs:no devuelve nada como tal , manda a pintar los paises
 */
void compare(Country pCountriesX [],Country pCountriesY [],int pCountColors[]){
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

	Country lastPosition[11];															//Array que guarda las ultimas posiciones de los paises pintados en un determinado color
	int limit = 11;																		//Limite de distancia entre los paises
	whites=0;																			//Contador de blancos

	for(int first = 1;first < 211;first++){
		if (pCountriesX[first].Color == pCountriesX[first-1].Color){					//Saco el color de la posicion actual , actual -1
			int firstPoint = pCountriesX[first].yPosition;								//Si los colores en X son iguales paso a verificar con "y".
			if (pCountriesY[firstPoint].Color == pCountriesX[first].Color){				//Si el color de "y" y "x" son iguales pinto blanco

				pCountriesX[first].Color = 12;
				CountryAdition(pCountriesX[first]);										//Mando a escribir el color
				counter++;
				whites++;
			}
			else{
				pCountriesX[first].Color = pCountriesY[firstPoint].Color;	    		//Si son diferentes se lo asigno pero paso a verificar con el ultimo que se pintó
				if (lastPosition[pCountriesX[first].Color].yPosition != -1){ 			//Verifica que sea diferente que menos -1 eso nos dice que si hay un ultimo

					int x1 = pCountriesX[first].x;
					int y1 = pCountriesX[first].y;										// Saco los puntos en (x,y)
					int x2 = lastPosition[pCountriesX[first].Color].x;
					int y2 = lastPosition[pCountriesX[first].Color].y;
					int distance = distancePoints(x1,y1,x2,y2);							// Sacamos la distancia para ver si no son cercanos y pintarlo

					if (distance < limit ){
						pCountriesX[first].Color = 12;
						CountryAdition(pCountriesX[first]);								//Si el limite es mayor pasa a ser blanco
						counter++;
						whites++;
					}
					else{
						lastPosition[pCountriesX[first].Color] =pCountriesX[first];		//Si pasa la prueba de la distancia se asigna como la ultima posicion
						CountryAdition(pCountriesX[first]);
						counter++;
					}
				}
				else{
					lastPosition[pCountriesX[first].Color] = pCountriesX[first];
					CountryAdition(pCountriesX[first]);									//Si en el array lastPosition está vacio solo se coloca en la posicion del color que corresponde
					counter++;
				}

				}
			}
		else{																			//Si los colores de first y first -1 son diferentes , se hará lo siguiente.
			if(pCountriesX[first].Color == pCountriesY[pCountriesX[first].yPosition].Color){
				if (lastPosition[pCountriesX[first].Color].yPosition != -1){
					int x1 = pCountriesX[first].x;
					int y1 = pCountriesX[first].y;										//SI son iguales dejo ese color pero reviso la ultima posicion
					int x2 = lastPosition[pCountriesX[first].Color].x;
					int y2 = lastPosition[pCountriesX[first].Color].y;
					int distance = distancePoints(x1,y1,x2,y2);

					if (distance < limit ){
						pCountriesX[first].Color = 12;
						CountryAdition(pCountriesX[first]);								//Si la distancia es menor , dejo en blanco
						counter++;
						whites ++;
					}
					else{
						lastPosition[pCountriesX[first].Color] = pCountriesX[first];
						CountryAdition(pCountriesX[first]);								//Si la distancia es mayor que el limite lo dejo y coloco el last
						counter++;
					}
				}
				else{
					lastPosition[pCountriesX[first].Color] = pCountriesX[first];
					CountryAdition(pCountriesX[first]);									//Si el ultimo esta vacio  solo lo coloco
					counter++;
				}

			}
			else{																		 // Si la "y" y la "x" no son iguales paso al contador de colores y debo verificar el que elijo en last
				int positiony = pCountriesX[first].yPosition;
				if (pCountColors[pCountriesX[first].Color] < pCountColors[pCountriesY[positiony].Color]){	//Si hay menos del color x, paso a verificar segun el last

					if (lastPosition[pCountriesX[first].Color].yPosition != -1){
						int x1 = pCountriesX[first].x;
						int y1 = pCountriesX[first].y;
						int x2 = lastPosition[pCountriesX[first].Color].x;
						int y2 = lastPosition[pCountriesX[first].Color].y;
						int distance = distancePoints(x1,y1,x2,y2);

						if (distance < limit ){
							pCountriesX[first].Color = 12;
							CountryAdition(pCountriesX[first]);							//Si la distancia es menor se queda en blanco
							counter++;
							whites ++;
						}
						else{
							lastPosition[pCountriesX[first].Color] = pCountriesY[first];
							CountryAdition(pCountriesX[first]);							//Si la distancia es mayor se queda el color
							counter++;
						}
					}
					else{																//En caso de que hay menos cantidad del color "y" verifico en el last con este
						if (lastPosition[pCountriesX[first].Color].yPosition != -1){
							int x1 = pCountriesX[first].x;
							int y1 = pCountriesX[first].y;
							int x2 = lastPosition[pCountriesX[first].Color].x;
							int y2 = lastPosition[pCountriesX[first].Color].y;
							int distance = distancePoints(x1,y1,x2,y2);

							if (distance < limit ){
								pCountriesX[first].Color = 12;
								CountryAdition(pCountriesX[first]);
								counter++;
								whites ++;
							}
							else{
								pCountColors[pCountriesX[first].Color] --;					//Si hay más en el color x,se disminuye el contador y se suma en y.
								pCountColors[pCountriesY[positiony].Color] ++;
								pCountriesX[first].Color =pCountriesY[positiony].Color;
								lastPosition[pCountriesX[first].Color] = pCountriesX[first];	//Lo cambio en el array last
								CountryAdition(pCountriesX[first]);
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
	cout <<"Cantidad blancos:" << whites << endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
}


void subEtapaDinamico(Country pCountriesX [],Country pCountriesY [], int pCountColors[], int xBegin, int xEnd, int yBegin, int yEnd, int ci){
	Country lastPosition[11];												//Guarda el pais que uso x color
	Country first = pCountriesX[xBegin];									//Primero de cada sección
	int xDistance = 8;														//Para manter el rango de la etapa en x
	int limitDistance = 12;													//Limite de distancia

	while(first.xPosition == -1 && xBegin < xEnd){ 							// Recorre el array x , para descartar todo pais que esta fuera de rango y elegir el primero
		if(pCountriesX[xBegin].yPosition < yEnd && pCountriesX[xBegin].yPosition > yBegin){
			first = pCountriesX[xBegin];
		}
		xBegin++;
	}

	if(first.Color == pCountriesY[first.yPosition].Color){					//Empieza a comparar el primero y ver que hace con su color
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
	Country last = first;													//Guarda la posicion que acaba de pintar
	for(int zone = xBegin; zone < xEnd; zone++){							//Busca que este dentro de la zona de x

		if(pCountriesX[zone].yPosition < yEnd && pCountriesX[zone].yPosition > yBegin){				//Busca que este dentro de la zona y

			Country nextPosition = pCountriesX[zone];						//La siguiente posicion contra el anterior seteado se comparan en este caso last
			if(last.Color != nextPosition.Color && nextPosition.Color != pCountriesY[nextPosition.yPosition].Color && last.Color != pCountriesY[nextPosition.yPosition].Color){
				if(pCountColors[nextPosition.Color] > pCountColors[pCountriesY[nextPosition.yPosition].Color]){
					pCountColors[nextPosition.Color]--;
					pCountColors[pCountriesY[nextPosition.yPosition].Color]++;

					nextPosition.Color = pCountriesY[nextPosition.yPosition].Color;
				}

			}
			else if(last.Color == nextPosition.Color && nextPosition.Color == pCountriesY[nextPosition.yPosition].Color){		//Si las tres posiciones tienen el mismo color
				nextPosition.Color = 12;																						//Y de la actual , x de la actual y x anterior
				whites ++;
			}
			else if(last.Color == nextPosition.Color && nextPosition.Color != pCountriesY[nextPosition.yPosition].Color){
				pCountColors[nextPosition.Color]--;
				pCountColors[pCountriesY[nextPosition.yPosition].Color]++;
				nextPosition.Color = pCountriesY[nextPosition.yPosition].Color;
			}

			if(nextPosition.Color != 12){									//Por si el primer else if es diferente de  12

				Country colorSearch = lastPosition[nextPosition.Color];		//Saca el ultimo pais pintado con el mismo color seleccionado

				if(last.xPosition != -1){									//Si no esta vacio
					if(abs(colorSearch.xPosition - nextPosition.xPosition) <= xDistance){  				//Saco la distancia para saber si esta cerca o no
						if(distancePoints(colorSearch.x, colorSearch.y, nextPosition.x, nextPosition.y) > limitDistance){  //Distancia de punto a punto
							CountryAdition(nextPosition);
							lastPosition[nextPosition.Color] = nextPosition;
							counter++;
						}
						else{
							nextPosition.Color = 12;										//Sino cumple con los limites queda blanco
							CountryAdition(nextPosition);
							counter++;
							whites ++;
						}
					}
					else{
						lastPosition[nextPosition.Color] = nextPosition;
						CountryAdition(nextPosition);
						counter++;
					}
				}
				else{																	//Si el last esta vacio de una lo pinta
					lastPosition[nextPosition.Color] = nextPosition;
					CountryAdition(nextPosition);
					counter++;
					}
			}
			else{																		//Si es blanco de una vez lo pinta
				CountryAdition(nextPosition);
				counter++;
			}
		last = nextPosition;															//Mi last pasa a ser la posicion actual
		}
		if(counter >= 5){
			printCurrent("Dinamico/Dinamico");
			counter = 0;
		}
	}
	cout << whites << endl;
}

void compareDinamico(Country pCountriesX [],Country pCountriesY [], int pCountColors[]){
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	counter = 0;
	whites = 0;
	int xAxys[4] = {211/2,211/2,211,211};					//Paises en el eje x
	int yAxys[4] = {211/2,211,211/2,211};					//Paises en el eje y
	int xBegin[4] = {0,0,(211/2)+1,(211/2)+1};				//Inicio para el eje x
	int yBegin[4] = {0,(211/2)+1,0,(211/2)+1};				//Inicio para el eje y
	for(int i = 0; i < 4; i++){
		subEtapaDinamico(pCountriesX,pCountriesY,pCountColors,xBegin[i],xAxys[i],yBegin[i],yAxys[i],i);   		//Proceso optimo de cada etapa
	}
	cout << "Dinamico Completado" << endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
}



int distanceCheck(Country pCountry){

	int blancosGenerados = 0;						//Blancos generados
	int limitDistance = 50;							//Limite de distancia

	Country tmp = arrayPaises[pCountry.Color][0];	//tmp se acomoda en el primer valor de la lista que tenga el mismo color de entrada

	//cout << pCountry.Color << endl;
	if(tmp.Color != 12){							//En caso de ser igual no hay valor asiganado 12= blanco
		for(int color = 0; color < 50; color++){
			tmp = arrayPaises[pCountry.Color][color];
			if(tmp.Color == 12){
				cout << "no distance" << tmp.x << "   " << tmp. y << "   " << pCountry.x << "   " << pCountry.y << endl;
				break;
			}
			else if(distancePoints(tmp.x, tmp.y, pCountry.x, pCountry.y) < limitDistance){			//Si es menor al limite sumo un blanco
				cout << tmp.x << "   " << tmp. y << "   " << pCountry.x << "   " << pCountry.y << endl;
				cout << "Distancia "<< distancePoints(tmp.x, tmp.y, pCountry.x, pCountry.y) << endl;
				blancosGenerados++;
				break;
			}
		}
	}
	return blancosGenerados;
}

void subEtapaBacktracking(Country pCountriesX [],Country pCountriesY [], int pCountColors[], int xBegin, int xEnd, int yBegin, int yEnd, int ci){
	int whiteX = 0;																					//Blancos en y y x
	int whiteY = 0;

	for(int zone = xBegin; zone < xEnd; zone++){													//Inicio buscando cual es primero de la zona en posicion x

		if(pCountriesX[zone].yPosition < yEnd && pCountriesX[zone].yPosition > yBegin){				//En posicion y , busco el pais que este en la zona

			Country nextPosition = pCountriesX[zone];												//NextPosition =primer pais encontrado en la zona
			cout << nextPosition.x << "   " << nextPosition.y << "   " << nextPosition.Color<< endl;
			//cout << pCountriesY[nextPosition.yPosition].x << "   " << pCountriesY[nextPosition.yPosition].y << endl;
			//whiteX = distanceCheck(nextPosition);
			//whiteY = distanceCheck(pCountriesY[nextPosition.yPosition]);
			//cout << blancosX << blancosY << endl;

			int limitDistance = 100;							//Limite de distancia

			Country tmp = arrayPaises[nextPosition.Color][0];	//tmp se acomoda en el primer valor de la lista que tenga el mismo color de entrada

			if(tmp.Color < 12){							//En caso de ser igual no hay valor asiganado 12= blanco
				for(int color = 0; color < 50; color++){
					tmp = arrayPaises[nextPosition.Color][color];
					if(tmp.Color >= 12){
							//cout << "no distance" << tmp.x << "   " << tmp. y << "   " << pCountry.x << "   " << pCountry.y << endl;
						break;
					}
					else if(distancePoints(tmp.x, tmp.y, nextPosition.x, nextPosition.y) < limitDistance){			//Si es menor al limite sumo un blanco
						//cout << tmp.x << "   " << tmp. y << "   " << nextPosition.x << "   " << nextPosition.y << endl;
						cout << "DistanciaX "<< distancePoints(tmp.x, tmp.y, nextPosition.x, nextPosition.y) << endl;
						whiteX++;
						break;
					}
				}
			}

			tmp = arrayPaises[pCountriesY[nextPosition.xPosition].Color][0];	//tmp se acomoda en el primer valor de la lista que tenga el mismo color de entrada

							//cout << pCountry.Color << endl;
			if(tmp.Color < 12){							//En caso de ser igual no hay valor asiganado 12= blanco
				for(int color = 0; color < 50; color++){
					tmp = arrayPaises[nextPosition.Color][color];
					if(tmp.Color >= 12){
										//cout << "no distance" << tmp.x << "   " << tmp. y << "   " << pCountry.x << "   " << pCountry.y << endl;
						break;
					}
					else if(distancePoints(tmp.x, tmp.y, pCountriesY[nextPosition.xPosition].x, pCountriesY[nextPosition.xPosition].y) < limitDistance){			//Si es menor al limite sumo un blanco
						//cout << tmp.x << "   " << tmp. y << "   " << pCountriesY[nextPosition.xPosition].x << "   " << pCountriesY[nextPosition.xPosition].y << endl;
						cout << "DistanciaY "<< distancePoints(tmp.x, tmp.y, pCountriesY[nextPosition.xPosition].x, pCountriesY[nextPosition.xPosition].y) << endl;
						whiteY++;
						break;
					}
				}
			}





			if(whiteX == 0 && whiteY == 0){																				// Con ambos colores no hay choques
				if(pCountColors[nextPosition.Color] > pCountColors[pCountriesY[nextPosition.yPosition].Color]){			//Comparo cual color hay mas y asigno el menor
					pCountColors[nextPosition.Color]--;
					pCountColors[pCountriesY[nextPosition.yPosition].Color]++;

					nextPosition.Color = pCountriesY[nextPosition.yPosition].Color;
				}
			}
			else if(whiteY == 0){																	//Si el valor en y no tuvo choques
				pCountColors[nextPosition.Color]--;
				pCountColors[pCountriesY[nextPosition.yPosition].Color]++;							//Se asigna el colore de y en x
				nextPosition.Color = pCountriesY[nextPosition.yPosition].Color;
			}
			else if(whiteX == 0){

			}
			else{
				nextPosition.Color = 12;															//Sino pasa a ser pais en blanco
			}
			whiteX = 0;
			whiteY = 0;
			if(nextPosition.Color != 12){
			//	pArrayPaises[nextPosition.Color]->insertar(pArrayPaises[nextPosition.Color], pCountriesX[zone]);


				for(int color = 0; color < 50; color++){											//Recorro la matriz , revisa su fila para ver donde colocare el pais actual
					//cout << arrayPaises[nextPosition.Color][color].Color << endl;
					if(arrayPaises[nextPosition.Color][color].Color == 12){
						arrayPaises[nextPosition.Color][color] = nextPosition;
						break;
					}
				}
				//cout << "adicion 1" << endl;
				CountryAdition(nextPosition);													//Lo manda a pintar
				counter++;
			}
			else{
				//cout << "adicion 2" << endl;
				CountryAdition(nextPosition);
				counter++;
				whites++;
			}

		}
		if(counter >= 20){
			printCurrent("Backtracking/Backtracking");
			counter = 0;
		}
	//	cout << 0 << endl;
	}

	cout << whites << endl;
}

void compareBacktracking(Country pCountriesX [],Country pCountriesY [], int pCountColors[]){
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	counter = 0;
	whites = 0;

	//Country *arrayPaises[11];
	//for(int i = 0; i < 11; i++){
	//	arrayPaises[i] = NULL;
	//}
	int xAxys[4] = {211/2,211/2,211,211};
	int yAxys[4] = {211/2,211,211/2,211};
	int xBegin[4] = {0,0,(211/2)+1,(211/2)+1};
	int yBegin[4] = {0,(211/2)+1,0,(211/2)+1};
	for(int i = 0; i < 4; i++){
		subEtapaBacktracking(pCountriesX,pCountriesY,pCountColors,xBegin[i],xAxys[i],yBegin[i],yAxys[i],i);
	}
	cout << "Backtracking Completado" << endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;
}
