/*
 * XMLReader.cpp
 *
 *  Created on: Nov 10, 2020
 *      Author: dylan
 */


#include "tinyxml2.h"
#include <iostream>
#include <string>

using namespace tinyxml2;

int main(){
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

			std::cout << pID->Value() << std::endl;                 //Print out id
		  }

		  const XMLAttribute * pDataName = pPath->FindAttribute("data-name");  //Get 'data-name' Attribute
		  if (NULL != pDataName) {

			std::cout << pDataName->Value() << std::endl;        // Print out 'data-name'
		  }

		  const XMLAttribute * pD = pPath->FindAttribute("d");  // Get 'd' Attribute
		  if (NULL != pD) {

			std::cout << pD->Value() << std::endl;    //Print out d
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



