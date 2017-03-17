#ifndef RECTANGULO
#define RECTANGULO

#include "Entidad.h"

class Rectangulo : Entidad
{
private:
	unsigned int ancho;
	unsigned int alto;

public:
	Rectangulo();
	Rectangulo(unsigned int ancho, unsigned int alto, unsigned int id, std::string color, std::string rutaImagen, Coordenada coordenada, unsigned int indexZ);
	virtual ~Rectangulo();

	void imprimir();
public:

};

#endif
