#ifndef RECTANGULO
#define RECTANGULO

#include "Entidad.h"

class Rectangulo : Entidad
{
private:
	unsigned int ancho;
	unsigned int alto;
	SDL_Rect rectanguloSDL;

public:
	Rectangulo();
	Rectangulo(int ancho, int alto, unsigned int id, std::string color, std::string rutaImagen, int x, int y, unsigned int indexZ);
	virtual ~Rectangulo();
	void dibujar(SDL_Renderer *renderer);

public:

};

#endif
