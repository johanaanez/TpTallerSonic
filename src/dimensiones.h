/*
 * dimensiones.h
 *
 *  Created on: 19 mar. 2017
 *      Author: pato
 */

#ifndef DIMENSIONES_H_
#define DIMENSIONES_H_

namespace std {

class dimensiones  {
public:
	virtual int getancho() = 0;
	virtual void setancho(int) = 0;
	virtual int getalto() = 0;
	virtual void setalto(int) = 0;
	virtual int getradio() = 0;
	virtual void setradio(int) = 0;
	dimensiones();
	virtual ~dimensiones();
};

} /* namespace std */

#endif /* DIMENSIONES_H_ */
