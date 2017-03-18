/*
 * jasonentidades.h
 *
 *  Created on: 17 mar. 2017
 *      Author: pato
 */

#ifndef JASONENTIDADES_H_
#define JASONENTIDADES_H_
#include <string>

namespace json {

class jasonentidad {
public:

// id
	int getid();
	void setid(int);

//tipo
	std::string gettipo();
	void settipo(std::string);

// color
	std::string getcolor();
	void   setcolor(std::string);

// dimension ancho
	int getancho();
	void setancho(int);

// dimension alto
	int getalto();
	void setalto(int);

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

public:
	jasonentidad();
	virtual ~jasonentidad();
};

} /* namespace json */

#endif /* JASONENTIDADES_H_ */
