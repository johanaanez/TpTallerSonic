/*
 * jentidades.h
 *
 *  Created on: 18 mar. 2017
 *      Author: pato
 */

#ifndef JENTIDADES_H_
#define JENTIDADES_H_
#include <string>
#include "dimensiones.h"

namespace std {

class jentidades {
public:
	jentidades();
	virtual ~jentidades();
	// id
	int getid();
	void setid(int);

	//tipo
	std::string gettipo();
	void settipo(std::string);

	// color
	std::string getcolor();
	void setcolor(std::string);

	// dimension ancho
	//int getancho();
	//void setancho(int);

	// dimension alto
	//int getalto();
	//void setalto(int);

	dimensiones* getDim();
	void setDim(dimensiones* dim);

	// coordenada x
	int getcoorx();
	void setcoorx(int);

	// coordenada y
	int getcoory();
	void setcoory(int);

	//rutaimagen
	std::string getruta();
	void setruta(std::string);

	//index
	int getindex();
	void setindex(int);



private:
	int id;
	std::string tipo;
	std::string color;
	int ancho;
	int alto;
	int coorx;
	int coory;
	std::string ruta;
	int index;
	dimensiones* dim;
};

} /* namespace std */

#endif /* JENTIDADES_H_ */
