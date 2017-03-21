/*
 * jrectangulo.h
 *
 *  Created on: 20 mar. 2017
 *      Author: pato
 */

#ifndef JRECTANGULO_H_
#define JRECTANGULO_H_
#include <string>
#include "dimensiones.h"


namespace std {

class jrectangulo: public dimensiones{

public:
	jrectangulo();
	virtual ~jrectangulo();
	void settipo(std::string);
	//ancho
	void setancho(int);
	int  getancho();
	//alto
	void setalto(int);
	int  getalto();
private:

 std::string tipo;
 int ancho;
 int alto;

};

} /* namespace std */

#endif /* JRECTANGULO_H_ */
