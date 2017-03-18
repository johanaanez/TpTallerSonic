#ifndef ENTIDAD
#define ENTIDAD

#include <string>
#include <iostream>
#include <SDL2/SDL.h>

class Entidad {

private:
	unsigned int id;
	int x;
	int y;
	SDL_Color color;
	std::string rutaImagen;
	unsigned int indexZ;

public:
	Entidad();
	Entidad(unsigned int id, std::string color, std::string rutaImagen, int x, int y, unsigned int indexZ);
	virtual void dibujar(SDL_Renderer *renderer) = 0;
	void setearColor(SDL_Renderer *renderer);
	virtual ~Entidad();
	int obtenerX();
	int obtenerY();

private:
	SDL_Color convertirColor(std::string color);

};

#endif
