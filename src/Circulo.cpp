#include "Circulo.h"

Circulo::Circulo() {
	// TODO Auto-generated constructor stub
}

Circulo::Circulo(unsigned int radio, unsigned int id, std::string color, std::string rutaImagen, Coordenada coordenada, unsigned int indexZ) : Entidad(id, color, rutaImagen, coordenada, indexZ)
{
	this->radio=radio;
}

Circulo::~Circulo() {
	// TODO Auto-generated destructor stub
}

