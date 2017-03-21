/*
 * dimensiones.h
 *
 *  Created on: 19 mar. 2017
 *      Author: pato
 */

#ifndef DIMENSIONES_H_
#define DIMENSIONES_H_
#include <string>


namespace std {

class dimensiones  {
public:

 	virtual void settipo(std::string) = 0;

	dimensiones();
	virtual ~dimensiones();


};


} /* namespace std */

#endif /* DIMENSIONES_H_ */
