/*
 * jasonventana.h
 *
 *  Created on: 17 mar. 2017
 *      Author: pato
 */

#ifndef JASONVENTANA_H_
#define JASONVENTANA_H_

namespace json {

class jasonventana {
public:
	jasonventana();
	virtual ~jasonventana();

	//ancho
	int getancho();
	void setancho(int);

	//alto
	int getalto();
	void setalto(int);

private:
	int alto;
	int ancho;
};

} /* namespace json */

#endif /* JASONVENTANA_H_ */
