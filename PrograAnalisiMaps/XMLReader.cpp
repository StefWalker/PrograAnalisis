/*
 * XMLReader.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: dylan
 */

#include <time.h>
#include "country.h"
#include "Tinyxml2/tinyxml2.h"
#include <iostream>
#include <string>
#include "MergeSort.h"

using namespace tinyxml2;

const string array[11] = {"fill:#0000FF;fill-rule:evenodd","fill:#FF0000;fill-rule:evenodd","fill:#FFFF00;fill-rule:evenodd",
		"fill:#00FF00;fill-rule:evenodd","fill:#E47833;fill-rule:evenodd","fill:#4F2F4F;fill-rule:evenodd","fill:#BC8F8F;fill-rule:evenodd"
		,"fill:#A62A2A;fill-rule:evenodd","fill:#4E2F2F;fill-rule:evenodd","fill:#770000;fill-rule:evenodd","fill:#ADEAEA;fill-rule:evenodd"};


void XMLLoader(Country paises[]){
	int contador = 0;
	XMLDocument doc;
	const char * path = "mapa.xml";
	doc.LoadFile(path);                             // Load the XML file into the Doc instance
	XMLElement * pRootElement = doc.RootElement();  // Get root Element

	if (NULL != pRootElement) {

	XMLElement * pPath = pRootElement->FirstChildElement("path");  //Get 'Path' Child
	if (NULL != pPath) {
		while (pPath) {

			const XMLAttribute * pID = pPath->FindAttribute("id");    // Get 'id' Attribute
			if (NULL != pID) {
				//paises[contador] = new Country();
				paises[contador].ID = pID->Value();
				//std::cout << pID->Value() << std::endl;                 //Print out id
			}
			const XMLAttribute * pDataName = pPath->FindAttribute("data-name");  //Get 'data-name' Attribute
			//if (NULL != pDataName) {

				//std::cout << pDataName->Value() << std::endl;        // Print out 'data-name'
			//}
			const XMLAttribute * pD = pPath->FindAttribute("d");  // Get 'd' Attribute
			if (NULL != pD) {
				bool first = false;
				bool second = false;
				int counter = 2;
				string read = pD->Value();
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
				//std::cout << stoi(valueX) << std::endl;
			//	std::cout << stoi(valueY) << std::endl;    //Print out d
			}

			const XMLAttribute * pStyle = pPath->FindAttribute("style");

			//pStyle->SetAttribute(&sender);

			//pStyle->SetAttribute(sender);
			contador ++;
			//std::cout << std::endl;
			//std::cout << "------------------------------------------------------------" << contador;
			//	std::cout << std::endl;

			pPath = pPath->NextSiblingElement("path");  // Next path (path Sibling)
		}

		//std::cout << "\n";
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
	mergeSorty(countriesy, 0 , size-1, cantColores);

	for(int i = 0; i<211; i++)
		std::cout << countriesx[i].x << " " << countriesx[i].Color << endl;;
	std:: cout << endl;

	for(int i = 0; i<sizeColors; i++)
			std::cout << countColors[i] << endl;;
		std:: cout << endl;

	for(int i = 0; i<211; i++)
		std::cout << countriesy[i].y << " " << countriesy[i].Color << endl;;
		std:: cout << endl;

	return 0;

}

