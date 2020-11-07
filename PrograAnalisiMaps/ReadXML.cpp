/*
 * ReadXML.cpp
 *
 *  Created on: 6 nov. 2020
 *      Author: ferla
 */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

	string line;
    ifstream in("mapa.xml");

    bool begin_tag = false;
    while (getline(in,line))
    {
        std::string tmp; // strip whitespaces from the beginning
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == ' ' && tmp.size() == 0)
            {
            }
            else
            {
                tmp += line[i];
            }
        }

        //cout << "-->" << tmp << "<--" << endl;

        if (tmp == "<path")
        {
            //cout << "Found <Package>" << endl;
            begin_tag = true;
            continue;
        }
        else if (tmp == "/>")
        {
            begin_tag = false;
            //cout << "Found </Package>" << endl;
        }

        if (begin_tag)
        {
            cout << tmp << endl;
        }
    }
}
