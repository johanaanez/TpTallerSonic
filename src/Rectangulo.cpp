#include "Rectangulo.h"

Rectangulo::Rectangulo()
{
	this->ancho=0;
	this->alto=0;
	SDL_Rect rectanguloSDL = {0,0,0,0};
	this->rectanguloSDL=rectanguloSDL;
}

Rectangulo::Rectangulo(int ancho, int alto, unsigned int id, std::string color, std::string rutaImagen, int x, int y, unsigned int indexZ) : Entidad(id, color, rutaImagen, x, y, indexZ)
{
	this->ancho=ancho;
	this->alto=alto;
	SDL_Rect rectanguloSDL = {x, y, ancho, alto};
	this->rectanguloSDL=rectanguloSDL;
}

Rectangulo::~Rectangulo() {
	// TODO Auto-generated destructor stub
}

void Rectangulo::dibujar(SDL_Renderer *renderer)
{
	if (tieneImagen())
	{
		cargarImagen(renderer);
		SDL_Rect recorte = {0, 0, ancho, alto}; //Toma la esquina superior izquierda de la imagen
		SDL_RenderCopy(renderer, obtenerImagen(), &recorte, &rectanguloSDL);
	}
	else
	{
		this->setearColor(renderer);
		SDL_RenderFillRect(renderer, &rectanguloSDL); //SDL_RenderDrawRect lo crea sin relleno
	}
}


