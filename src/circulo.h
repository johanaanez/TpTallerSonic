/*
 * circulo.h
 *
 *  Created on: 19 mar. 2017
 *      Author: pato
 */

#ifndef CIRCULO_H_
#define CIRCULO_H_
#include "dimensiones.h"

namespace std {

class circulo : public dimensiones {
private:
	int radio;
public:
	virtual int getradio();
	virtual void setradio(int);
	circulo();
	virtual ~circulo();
};

} /* namespace std */

#endif /* CIRCULO_H_ */
