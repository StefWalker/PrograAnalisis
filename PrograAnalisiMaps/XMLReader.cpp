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

void XMLLoader(Country paises[]){
	int contador = 0;
	XMLDocument doc;
	const char * path = "Mapa/mapa.xml";
	doc.LoadFile(path);                             // Load the XML file into the Doc instance
	XMLElement * pRootElement = doc.RootElement();  // Get root Element

	if (NULL != pRootElement) {

	XMLElement * pPath = pRootElement->FirstChildElement("path");  //Get 'Path' Child
	if (NULL != pPath) {
		while (pPath) {

			const XMLAttribute * pID = pPath->FindAttribute("id");    // Get 'id' Attribute
			if (NULL != pID) {
				paises[contador].ID = pID->Value();
			}
			const XMLAttribute * pDataName = pPath->FindAttribute("data-name");  //Get 'data-name' Attribute

			const XMLAttribute * pD = pPath->FindAttribute("d");  // Get 'd' Attribute
			if (NULL != pD) {
				bool first = false;
				bool second = false;
				int counter = 2;
				string read = pD->Value();
				paises[contador].d = read;
				string valueX;
				string valueY;
				while(second == false){
					if(first == false){
						valueX += read[counter];
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
				paises[contador].x = stoi(valueX);
				paises[contador].y = stoi(valueY);
			}

			contador ++;
			pPath = pPath->NextSiblingElement("path");  // Next path (path Sibling)
			}
		}
	}
}


int tester(int cantColores){
	int size = 211 ;
	int sizeColors = 11;

	Country countriesx[size];
	Country countriesy[size];

	int countColors[sizeColors] = {0}; // contador de colores usados

	XMLLoader(countriesx);			 //carga de paises
	XMLLoader(countriesy);



	srand(time(0));
	mergesort(countriesx,0,size-1, cantColores,countColors);						//ordenamientos
	for(int i= 0; i < 211; i++){
		countriesy[i] = countriesx[i];
	}
	mergeSorty(countriesy, 0 , size-1, cantColores);

	for(int i = 0;i < 211;i++){
		for(int j = 0;j < 211;j++){
			if(countriesx[i].ID == countriesy[j].ID){
				countriesx[i].yPosition = j;
				countriesx[i].xPosition = i;
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

	compare(countriesx, countriesy,countColors);
	//compareDinamico(countriesx, countriesy,countColors);
	return 0;

}

