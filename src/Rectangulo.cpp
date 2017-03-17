#include "Rectangulo.h"

Rectangulo::Rectangulo() {
	// TODO Auto-generated constructor stub

}

Rectangulo::Rectangulo(unsigned int ancho, unsigned int alto, unsigned int id, std::string color, std::string rutaImagen, Coordenada coordenada, unsigned int indexZ) : Entidad(id, color, rutaImagen, coordenada, indexZ)
{
	this->ancho=ancho;
	this->alto=alto;
}

Rectangulo::~Rectangulo() {
	// TODO Auto-generated destructor stub
}



