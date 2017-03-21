/*
 * jcirculo.h
 *
 *  Created on: 21 mar. 2017
 *      Author: pato
 */

#ifndef JCIRCULO_H_
#define JCIRCULO_H_
#include "dimensiones.h"

namespace std {

class jcirculo: public dimensiones {
public:
	jcirculo();
	virtual ~jcirculo();
	void settipo(std::string);
    //radio
    void setradio(int);
    int  getradio();

	private:

	 std::string tipo;
	 int radio;
};

} /* namespace std */

#endif /* JCIRCULO_H_ */
