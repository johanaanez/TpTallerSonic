/*
 * jventana.cpp
 *
 *  Created on: 18 mar. 2017
 *      Author: pato
 */

#include "jventana.h"

namespace std {

jventana::jventana() {
	// TODO Auto-generated constructor stub

}

jventana::~jventana() {
	// TODO Auto-generated destructor stub
}
//ancho
int jventana::getancho(){
	return ancho;
}
void jventana::setancho(int anchovent){
	ancho = anchovent;
}

//alto
int jventana::getalto(){
	return alto;
}
void jventana::setalto(int altovent){
	alto = altovent;
}
} /* namespace std */
