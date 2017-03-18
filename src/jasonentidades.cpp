/*
 * jasonentidades.cpp
 *
 *  Created on: 17 mar. 2017
 *      Author: pato
 */

#include "jasonentidades.h"
#include <string>

namespace json {


//id
int jasonentidad::getid(){
	return id;
}
void jasonentidad::setid(int ident){
	id = ident;
}

//tipo
std::string jasonentidad::gettipo(){
	return tipo;
}
void jasonentidad::settipo(std::string tipoent){
	tipo = tipoent;
}

//color
std::string jasonentidad::getcolor(){
	return color;
}
void jasonentidad:: setcolor(std::string colorent){
	color = colorent;
}

//dimension ancho
int jasonentidad::getancho(){
	return ancho;
}
void jasonentidad::setancho(int anchoent){
	ancho = anchoent;
}

//dimensionalto
int jasonentidad::getalto(){
	return alto;
}
void jasonentidad::setalto(int altoent){
	alto = altoent;
}

//coordenada x
int jasonentidad::getcoorx(){
	return coorx;
}
void jasonentidad::setcoorx(int coorxent){
	coorx = coorxent;
}

// coordenada y
int jasonentidad::getcoory(){
	return coory;
}
void jasonentidad::setcoory(int cooryent){
	coory = cooryent;
}

//rutaimageb
 std::string jasonentidad::getruta(){
	return ruta;
}
void jasonentidad::setruta(std::string rutaent){
	ruta = rutaent;
}

//index
int jasonentidad::getindex(){
	return index;
}
void jasonentidad::setindex(int indexent){
	index = indexent;
}

} /* namespace json */
