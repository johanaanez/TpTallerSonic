#ifndef CIRCULO
#define CIRCULO

#include "Entidad.h"

class Circulo : Entidad
{
private:
	unsigned int radio;

public:
	Circulo();
	Circulo(unsigned int radio, unsigned int id, std::string color, std::string rutaImagen, Coordenada coordenada, unsigned int indexZ);
	virtual ~Circulo();

private:

};

#endif
