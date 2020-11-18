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

using namespace tinyxml2;


void XMLLoader(Country *paises[]){
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
				paises[contador] = new Country();
				paises[contador]->ID = pID->Value();
				std::cout << pID->Value() << std::endl;                 //Print out id
			}
			const XMLAttribute * pDataName = pPath->FindAttribute("data-name");  //Get 'data-name' Attribute
			if (NULL != pDataName) {

				std::cout << pDataName->Value() << std::endl;        // Print out 'data-name'
			}
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
				paises[contador]->Centro->x = stoi(valueX);
				paises[contador]->Centro->y = stoi(valueY);
				std::cout << stoi(valueX) << std::endl;
				std::cout << stoi(valueY) << std::endl;    //Print out d
			}
			contador ++;
			std::cout << std::endl;
			std::cout << "------------------------------------------------------------" << contador;
			std::cout << std::endl;

			pPath = pPath->NextSiblingElement("path");  // Next path (path Sibling)
		}
		std::cout << "\n";
		}
	}
}

/*
int main(){
	Country *paises[211];
	XMLLoader(paises);
}
*/
