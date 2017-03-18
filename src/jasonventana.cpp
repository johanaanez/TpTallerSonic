/*
 * jasonventana.cpp
 *
 *  Created on: 17 mar. 2017
 *      Author: pato
 */

#include "jasonventana.h"

namespace json {

jasonventana::jasonventana() {
	// TODO Auto-generated constructor stub

}

jasonventana::~jasonventana() {
	// TODO Auto-generated destructor stub
}
//ancho
int jasonventana::getancho(){
	return ancho;
}
void jasonventana::setancho(int anchovent){
	ancho = anchovent;
}

//alto
int jasonventana::getalto(){
	return alto;
 }

void jasonventana::setalto(int altoventana){
  alto = altoventana;
 }
}
//void jasonventana::setalto(int altoventana){
//}
//} /* namespace json */
