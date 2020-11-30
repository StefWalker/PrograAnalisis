/*
 * XMLReader.cpp
 *
 *      Author: Dylan Torres
 *      		2018135751
 *
 *      		Fernanda Lanza
 *      		2018133074
 */


#include "country.h"
#include "Tinyxml2/tinyxml2.h"
#include <iostream>
#include <string>
#include <chrono>
#include <time.h>
#include "MergeSort/MergeSort.h"
#include "Algoritmos/CompareArray.h"

using namespace tinyxml2;

/* Funcion encargada de la carga de datos provenientes del archivo SVG que previamente se paso a XML
 * input: Un array con objetos tipo Country
 * output: El mismo array con los paises cargados
 * */
void XMLLoader(Country paises[]){
	int contador = 0;
	XMLDocument doc;
	const char * path = "Mapa/mapa.xml";
	doc.LoadFile(path);                             // Carga el archivo XML dentro de la instancia doc
	XMLElement * pRootElement = doc.RootElement();  // Get del elemento root

	if (NULL != pRootElement) {

	XMLElement * pPath = pRootElement->FirstChildElement("path");  	     //Get del hijo 'Path'
	if (NULL != pPath) {
		while (pPath) {

			const XMLAttribute * pID = pPath->FindAttribute("id");      // Get del atributo 'id'
			if (NULL != pID) {
				paises[contador].ID = pID->Value();					    // Lectura de los datos 'ID'
			}
			const XMLAttribute * pDataName = pPath->FindAttribute("data-name");     //Get del atributo 'data-name'

			const XMLAttribute * pD = pPath->FindAttribute("d");                    // Get del atributo 'd
			if (NULL != pD) {
				bool first = false;										// Variables utilizadas para el logre de la carga
				bool second = false;									//   de las variables X y Y en el objeto Country
				int counter = 2;
				string read = pD->Value();								// Lectura de los datos 'd'
				paises[contador].d = read;
				string valueX;
				string valueY;
				while(second == false){									// Ciclo que acaba al encontrar el valor de Y
					if(first == false){									// Busqueda del valor de X
						valueX += read[counter];						// Se lee caracter por caracter
						if(read[counter+1] == '.'){						// Una vez completado el numero se buscara el chr '.'
							first = true;
							counter += 4;
						}
						if(first == false && read[counter+1] == ','){   // o el char ','
							first = true;
							counter += 2;
						}
					}
					if(first == true && second == false){				// Se ejecuta de la misma forma para el eje Y
						valueY += read[counter];
						if(read[counter+1] == '.'){
							second = true;
						}
						if(read[counter+1] == ' '){
							second = true;
						}
					}
					counter ++;
				}
				paises[contador].x = stoi(valueX);		// Se asignan los valores a los objetos
				paises[contador].y = stoi(valueY);
			}

			contador ++;
			pPath = pPath->NextSiblingElement("path");  // Busca en el sibling de Path (el siguiente pais en el XML)
			}
		}
	}
}

/* Encargado de crear y manejar los arrays principales del algorimo asi como declarar los indices al array en X y al array en Y
 * inputs: la cantidad de colores seleccionados
 * outputs: ninguno
 * */
void startProcedure(int pCantColores){
	int arraySize = 211;
	int sizeColors = 11;

	Country countriesX[arraySize];
	Country countriesY[arraySize];

	int countColors[sizeColors] = {0};				 // contador de colores usados

	XMLLoader(countriesX);			   				 // carga de paises

	srand(time(0));
	mergeSortX(countriesX, 0, arraySize-1, pCantColores, countColors);		// Ordenamientos Merge Sort X
	for(int pais = 0; pais < 211; pais++){			 // carga los valores dentro del array en eje Y
		countriesY[pais] = countriesX[pais];
	}
	mergeSortY(countriesY, 0, arraySize-1, pCantColores);					// Ordenamientos Merge Sort Y

	for(int paisX = 0; paisX < 211; paisX++){						// ciclos encargados de asignar los valores finales de Y a el array en X
		for(int paisY = 0; paisY < 211;paisY++){
			if(countriesX[paisX].ID == countriesY[paisY].ID){
				countriesX[paisX].yPosition = paisY;
				countriesX[paisX].xPosition = paisX;
				break;
			}
		}
	}
/*
	for(int i = 0; i<211; i++)
		std::cout << countriesx[i].x << " " << countriesx[i].Color << endl;;
	std:: cout << endl;

	for(int i = 0; i<sizeColors; i++)
			std::cout << countColors[i] << endl;;
		std:: cout << endl;

	for(int i = 0; i<211; i++)
		std::cout << countriesy[i].y << " " << countriesy[i].Color << endl;;
		std:: cout << endl;
*/

	//compare(countriesX, countriesY,countColors);
	//compareDinamico(countriesX, countriesY, countColors);
	compareBacktracking(countriesX, countriesY, countColors);

}







