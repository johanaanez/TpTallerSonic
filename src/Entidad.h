#ifndef ENTIDAD
#define ENTIDAD

#include <string>
#include <iostream>
#include "Coordenada.h"

class Entidad {

private:
	unsigned int id;
	std::string color;
	std::string rutaImagen;
	Coordenada coordenada;
	unsigned int indexZ;

public:
	Entidad();
	Entidad(unsigned int id, std::string color, std::string rutaImagen, Coordenada coordenada, unsigned int indexZ);
	//virtual void dibujar() = 0;
	virtual ~Entidad();


private:


};

#endif
