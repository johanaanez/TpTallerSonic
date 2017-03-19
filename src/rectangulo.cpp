/*
 * rectangulo.cpp
 *
 *  Created on: 19 mar. 2017
 *      Author: pato
 */

#include "rectangulo.h"
#include "dimensiones.h"

namespace std {

rectangulo::rectangulo() {
	// TODO Auto-generated constructor stub

}
rectangulo::~rectangulo() {
	// TODO Auto-generated destructor stub
}

int rectangulo::getancho(){
	return ancho;
}
void rectangulo::setancho(int anchorect){
	ancho = anchorect;
}
int rectangulo::getalto(){
	return alto;
}
void rectangulo::setalto(int altorect){
	alto = altorect;
}
} /* namespace std */
