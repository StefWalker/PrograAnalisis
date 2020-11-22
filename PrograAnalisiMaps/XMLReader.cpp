/*
 * XMLReader.cpp
 *
 *      Author: Dylan Torres
 *      		2018135751
 *
 *      		Fernanda Lanza
 *      		201
 */

#include <time.h>
#include "country.h"
#include "Tinyxml2/tinyxml2.h"
#include <iostream>
#include <string>
#include "MergeSort/MergeSort.h"
#include "Algoritmos/CompareArray.h"

using namespace tinyxml2;

/* Funcion encargada de la carga de datos provenientes del archivo SVG que previamente se paso a XML
 * input: Un array con objetos tipo Country
 * output: El mismo array con los paises cargados
 * */
void XMLLoader(Country paises[]){
	int counter = 0;
	XMLDocument doc;
	const char * path = "Mapa/mapa.xml";
	doc.LoadFile(path);                             // Carga el archivo XML dentro de la instancia doc
	XMLElement * pRootElement = doc.RootElement();  // Get del elemento root

	if (NULL != pRootElement) {
		XMLElement * pPath = pRootElement->FirstChildElement("path");     //Get del hijo 'Path'
		if (NULL != pPath) {
			while (pPath) {
				const XMLAttribute * pID = pPath->FindAttribute("id");    // Get del atributo 'id'
				if (NULL != pID) {
					paises[counter].ID = pID->Value();					  // Lectura de los datos 'd'
				}
				const XMLAttribute * pDataName = pPath->FindAttribute("data-name");  //Get del atributo 'data-name'
				const XMLAttribute * pCoordenates = pPath->FindAttribute("d"); 		 // Get del atributo 'd'
				if (NULL != pCoordenates) {
					bool first = false;						// Variables utilizadas para el logre de la carga
					bool second = false;				    //   de las variables X y Y en el objeto Country
					int counter = 2;
					string read = pCoordenates->Value();	// Lectura de los datos 'd'
					paises[counter].coordenates = read;
					string valueX;
					string valueY;
					while(second == false){					// Ciclo que acaba al encontrar el valor de Y
						if(first == false){					// Busqueda del valor de X
							valueX += read[counter];		// Se lee caracter por caracter
							if(read[counter+1] == '.'){
								first = true;
								counter += 4;
							}
							if(first == false && read[counter+1] == ','){
								first = true;
								counter += 2;
							}
						}
						if(first == true && second == false){
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
					paises[counter].x = stoi(valueX);
					paises[counter].y = stoi(valueY);
				}
				counter ++;
				pPath = pPath->NextSiblingElement("path");  // Next path (path Sibling)
			}
		}
	}
}


int startProcedure(int pCantColores){
	int arraySize = 211 ;
	int sizeColors = 11;

	Country countriesX[arraySize];
	Country countriesY[arraySize];

	int countColors[sizeColors] = {0};   // contador de colores usados

	XMLLoader(countriesX);				 // carga de paises
	XMLLoader(countriesY);

	srand(time(0));
	mergeSortX(countriesX,0,arraySize-1, pCantColores,countColors);	//ordenamientos

	for(int i = 0; i < 211; i++){
		countriesY[i] = countriesX[i];
	}

	mergeSortY(countriesY, 0 , arraySize-1, pCantColores);

	for(int i = 0;i < 211;i++){
		for(int j = 0;j < 211;j++){
			if(countriesX[i].ID == countriesY[j].ID){
				countriesX[i].yPosition = j;
				countriesX[i].xPosition = i;
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

	compare(countriesX, countriesY,countColors);
	//compareDinamico(countriesx, countriesy,countColors);
	return 0;

}

