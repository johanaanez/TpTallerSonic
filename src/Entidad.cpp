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
	this->imagen=NULL;
}

Entidad::Entidad(unsigned int id, std::string color, std::string rutaImagen, int x, int y, unsigned int indexZ){
	this->id=id;
	SDL_Color colorSDL = convertirColor(color);
	this->color=colorSDL;
	this->rutaImagen=rutaImagen;
	this->x=x;
	this->y=y;
	this->indexZ=indexZ;
	this->imagen=NULL;
}

Entidad::~Entidad()
{
	destruirImagen();
}

SDL_Color Entidad::convertirColor(std::string color)
{
	SDL_Color colorSDL = {0, 0, 0, 0};
	if (color == "Amarillo"){
		colorSDL.r = 255; colorSDL.g = 255; colorSDL.b = 0; colorSDL.a = 255;
	}
	else if (color == "Azul"){
		colorSDL.r = 0; colorSDL.g = 0; colorSDL.b = 255; colorSDL.a = 255;
	}
	else if (color == "Rojo"){
		colorSDL.r = 255; colorSDL.g = 0; colorSDL.b = 0; colorSDL.a = 255;
	}
	else if (color == "Verde"){
		colorSDL.r = 0; colorSDL.g = 255; colorSDL.b = 0; colorSDL.a = 255;
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

SDL_Texture* Entidad::obtenerImagen()
{
	return imagen;
}

bool Entidad::tieneImagen()
{
	if (rutaImagen == "")
		return false;
	else
		return true;
}

int Entidad::cargarImagen(SDL_Renderer *renderer)
{
	SDL_Surface *imagenTemp = NULL;
	const char *ruta = rutaImagen.c_str();
	imagenTemp=SDL_LoadBMP(ruta);

	if(imagenTemp == NULL)
	{
		std::cout << "Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	imagen = SDL_CreateTextureFromSurface(renderer, imagenTemp);
	SDL_FreeSurface(imagenTemp);

	return 0;
}

void Entidad::destruirImagen()
{
	if (imagen != NULL)
	{
		SDL_DestroyTexture(imagen);
	}
}


