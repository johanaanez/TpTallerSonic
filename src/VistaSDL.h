/*
 * VistaSDL.h
 *
 *  Created on: 22 mar. 2017
 *      Author: cristian
 */

#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
using namespace std;
#include <string>


#ifndef VISTASDL_H_
#define VISTASDL_H_

class VistaSDL{

private:
	SDL_Window* ventana;
	SDL_Renderer* renderizador;
	SDL_Surface* superficiePantalla;
	SDL_Surface* superficieACargar;

	int anchoVentana;
	int altoVentana;
	int imgFlags;

public:
	VistaSDL();
	void mostrarVentana();
	void cerrar();
	~VistaSDL();
};




#endif /* VISTASDL_H_ */
