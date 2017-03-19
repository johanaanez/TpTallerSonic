/*
 * rectangulo.h
 *
 *  Created on: 19 mar. 2017
 *      Author: pato
 */

#ifndef RECTANGULO_H_
#define RECTANGULO_H_
#include "dimensiones.h"

namespace std {

class rectangulo : public dimensiones {
private:
    int ancho;
    int alto;
public:
    virtual int getancho();
    virtual void setancho(int);
    virtual int getalto();
    virtual void setalto(int);
	rectangulo();
	virtual ~rectangulo();
};

} /* namespace std */

#endif /* RECTANGULO_H_ */
