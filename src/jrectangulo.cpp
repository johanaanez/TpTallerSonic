/*
 * jrectangulo.cpp
 *
 *  Created on: 20 mar. 2017
 *      Author: pato
 */

#include "jrectangulo.h"


namespace std {

jrectangulo::jrectangulo() {
	// TODO Auto-generated constructor stub

}

jrectangulo::~jrectangulo() {
	// TODO Auto-generated destructor stub
}

void jrectangulo::settipo(std::string rect){
	tipo = rect;
}

//ancho
void jrectangulo::setancho(int anchorect){
	ancho = anchorect;
}
int jrectangulo::getancho(){
	return ancho;
}

//alto
void jrectangulo::setalto(int altorect){
	alto = altorect;
}
int jrectangulo::getalto(){
	return alto;
}

} /* namespace std */
