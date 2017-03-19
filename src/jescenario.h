/*
 * jescenario.h
 *
 *  Created on: 18 mar. 2017
 *      Author: pato
 */

#ifndef JESCENARIO_H_
#define JESCENARIO_H_
#include "capas.h"
#include <list>

namespace std {

class jescenario {
public:

	jescenario();
	virtual ~jescenario();
    //ancho
	int  getancho();
	void setancho(int);

	//alto
	int  getalto();
	void setalto(int);

	//capas
    list<capas> getcapas();
    void setcapas(list<capas>);

private:
	int ancho;
    int alto;
    capas c;

};

} /* namespace std */

#endif /* JESCENARIO_H_ */
