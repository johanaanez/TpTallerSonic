#include "Entidad.h"

Entidad::Entidad() {
	// TODO Auto-generated constructor stub

}

Entidad::Entidad(unsigned int id, std::string color, std::string rutaImagen, Coordenada coordenada, unsigned int indexZ){
	this->id=id;
	this->color=color;
	this->rutaImagen=rutaImagen;
	this->coordenada=coordenada;
	this->indexZ=indexZ;
}

Entidad::~Entidad() {
	// TODO Auto-generated destructor stub
}

