/*
 * circulo.cpp
 *
 *  Created on: 19 mar. 2017
 *      Author: pato
 */

#include "circulo.h"
#include "dimensiones.h"

namespace std {

circulo::circulo() {
	// TODO Auto-generated constructor stub

}

circulo::~circulo() {
	// TODO Auto-generated destructor stub
}
int circulo::getradio(){
	return radio;
}
void circulo::setradio(int radiocir){
	radio = radiocir;
}

} /* namespace std */
