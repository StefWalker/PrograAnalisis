/*
 * SVG.cpp
 *
 *  Created on: 18 nov. 2020
 *      Author: dylan
 */

#include <fstream>
#include <iostream>
#include <string>
#include "country.h"
#include "SVG.h"

using namespace std;

string SVG;
string svgBody;
//string end = "</svg>";
string array[11] = {"fill:#0000FF;fill-rule:evenodd","fill:#FF0000;fill-rule:evenodd","fill:#FFFF00;fill-rule:evenodd",
		"fill:#00FF00;fill-rule:evenodd","fill:#E47833;fill-rule:evenodd","fill:#4F2F4F;fill-rule:evenodd","fill:#BC8F8F;fill-rule:evenodd"
		,"fill:#A62A2A;fill-rule:evenodd","fill:#4E2F2F;fill-rule:evenodd","fill:#770000;fill-rule:evenodd","fill:#ADEAEA;fill-rule:evenodd"};

void SVGGenerator(){

	SVG = "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"no\"?>\n";
	SVG += " <svg\n";
	SVG += "   xmlns:dc=\"http://purl.org/dc/elements/1.1/\"\n";
	SVG += "   xmlns:cc=\"http://creativecommons.org/ns#\"\n";
	SVG += "   xmlns:rdf=\"http://www.w3.org/1999/02/22-rdf-syntax-ns#\"\n";
	SVG += "   xmlns:svg=\"http://www.w3.org/2000/svg\"\n";
	SVG += "   xmlns=\"http://www.w3.org/2000/svg\"\n";
	SVG += "   xmlns:sodipodi=\"http://sodipodi.sourceforge.net/DTD/sodipodi-0.dtd\"\n";
	SVG += "   xmlns:inkscape=\"http://www.inkscape.org/namespaces/inkscape\"\n";
	SVG += "   enable_background=\"new 0 0 2000 1001\"\n";
	SVG += "   height=\"1001px\"\n";
	SVG += "   pretty_print=\"False\"\n";
	SVG += "   style=\"stroke-linejoin: round; stroke:#000; fill: none;\"\n";
	SVG += "   version=\"1.1\"\n";
	SVG += "   viewBox=\"0 0 2000 1001\"\n";
	SVG += "   width=\"2000px\"\n";
	SVG += "   id=\"svg2\"\n";
	SVG += "   inkscape:version=\"0.48.4 r9939\"\n";
	SVG += "   sodipodi:docname=\"world.svg\">\n";
	SVG += "  <sodipodi:namedview\n";
	SVG += " 	 pagecolor=\"#ffffff\"\n";
	SVG += "	 bordercolor=\"#666666\"\n";
	SVG += "	 borderopacity=\"1\"\n";
	SVG += "	 objecttolerance=\"10\"\n";
	SVG += "	 gridtolerance=\"10\"\n";
	SVG += "	 guidetolerance=\"10\"\n";
	SVG += "	 inkscape:pageopacity=\"0\"\n";
	SVG += "	 inkscape:pageshadow=\"2\"\n";
	SVG += "	 inkscape:window-width=\"1920\"\n";
	SVG += "	 inkscape:window-height=\"1137\"\n";
	SVG += "     id=\"namedview231\"\n";
	SVG += "     showgrid=\"false\"\n";
	SVG += "     inkscape:zoom=\"1.144\"\n";
	SVG += "     inkscape:cx=\"593.00732\"\n";
	SVG += "     inkscape:cy=\"460.46398\"\n";
	SVG += "     inkscape:window-x=\"1192\"\n";
	SVG += "     inkscape:window-y=\"118\"\n";
	SVG += "     inkscape:window-maximized=\"1\"\n";
	SVG += "     inkscape:current-layer=\"svg2\" />\n";
	SVG += "  <defs\n";
	SVG += "     id=\"defs4\">\n";
	SVG += "    <style\n";
	SVG += "       type=\"text/css\"\n";
	SVG += "       id=\"style6\">path { fill-rule: evenodd; }</style>\n";
	SVG += "  </defs>\n";
	SVG += "  <metadata\n";
	SVG += "     id=\"metadata8\">\n";
	SVG += "    <views\n";
	SVG += "       id=\"views10\">\n";
	SVG += "      <view\n";
	SVG += "         h=\"1001\"\n";
	SVG += "         padding=\"0\"\n";
	SVG += "         w=\"2000\"\n";
	SVG += "         id=\"view12\">\n";
	SVG += "        <proj\n";
	SVG += "           flip=\"auto\"\n";
	SVG += "           id=\"robinson\"\n";
	SVG += "           lon0=\"100.0\" />\n";
	SVG += "        <bbox\n";
	SVG += "           h=\"2233.1\"\n";
	SVG += "           w=\"5271.17\"\n";
	SVG += "           x=\"-2635.59\"\n";
	SVG += "           y=\"-1308.06\"\n";
	SVG += "           id=\"bbox15\" />\n";
	SVG += "      </view>\n";
	SVG += "    </views>\n";
	SVG += "    <rdf:RDF>\n";
	SVG += "      <cc:Work\n";
	SVG += "         rdf:about=\"\">\n";
	SVG += "        <dc:format>image/svg+xml</dc:format>\n";
	SVG += "        <dc:type\n";
	SVG += "           rdf:resource=\"http://purl.org/dc/dcmitype/StillImage\" />\n";
	SVG += "        <dc:title />\n";
	SVG += "      </cc:Work>\n";
	SVG += "    </rdf:RDF>\n";
	SVG += "  </metadata>\n";
	SVG += "  <path \n";

}

void CountryAdition(Country pais){
	if (pais.Color < 12 ){
		svgBody += "d=\"" + pais.d + "\" />\n";
		svgBody += array[pais.Color] + "\n";
	}
	else{
		string blanco= "fill:#C0C0C0;fill-rule:evenodd";
		svgBody += "d=\"" + pais.d + "\" />\n";
		svgBody += blanco + "\n";
	}
}

void printCurrent(string algoritmo){
	ofstream out(algoritmo + ".svg");
	out << SVG + svgBody + "</svg>";
	out.close();
}
