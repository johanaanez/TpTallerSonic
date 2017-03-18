#include "Entidad.h"

Entidad::Entidad()
{
	this->id=0;
	SDL_Color colorSDL = {0, 0, 0, 0};
	this->color=colorSDL;
	this->rutaImagen="";
	this->x=0;
	this->y=0;
	this->indexZ=0;
}

Entidad::Entidad(unsigned int id, std::string color, std::string rutaImagen, int x, int y, unsigned int indexZ){
	this->id=id;
	SDL_Color colorSDL = convertirColor(color);
	this->color=colorSDL;
	this->rutaImagen=rutaImagen;
	this->x=x;
	this->y=y;
	this->indexZ=indexZ;
}

Entidad::~Entidad() {
	// TODO Auto-generated destructor stub
}

SDL_Color Entidad::convertirColor(std::string color)
{
	SDL_Color colorSDL = {0, 0, 0, 0};
	if (color == "Amarillo"){
		colorSDL = {255, 255, 0, 255};
	}
	else if (color == "Azul"){
		colorSDL = {0, 0, 255, 255};
	}
	else if (color == "Rojo"){
		colorSDL = {255, 0, 0, 255};
	}
	else if (color == "Verde"){
		colorSDL = {0, 255, 0, 255};
	}
	return colorSDL;
}

void Entidad::setearColor(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
}

int Entidad::obtenerX()
{
	return x;
}

int Entidad::obtenerY()
{
	return y;
}

