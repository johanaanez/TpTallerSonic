/*
 * Textura.cpp
 *
 *  Created on: 23 mar. 2017
 *      Author: cristian
 */
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
using namespace std;
#include <string>
#include "VistaSDL.h"
#include "Textura.h"

Textura::Textura(){

	this->textura = NULL;
	this->anchoTextura = 0;
	this->altoTextura = 0;
//	this->renderizador = NULL;
}

void Textura::cargarImagen(std::string path,SDL_Renderer* render){

	this->renderizador = render;
	//en caso que hubiera una textura creada, la libero para podeer crear otra
	this->liberarTextura();
	SDL_Surface* superficie = IMG_Load( path.c_str() );
	if( superficie == NULL )
	{
		printf( "incapaz de crear imagen %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
//		SDL_SetColorKey( superficie, SDL_TRUE, SDL_MapRGB( superficie->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        textura = SDL_CreateTextureFromSurface( renderizador, superficie );
		if( textura == NULL )
		{
			printf( "incapaz de crear textura %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			anchoTextura = superficie->w;
			altoTextura = superficie->h;
		}
		//liberar memoria de superficie creada
		SDL_FreeSurface( superficie );
	}
}

void Textura::renderizar( int ancho, int alto )
{
	//renderiza en la pantalla un bloque con las dimensiones pasadas por pantalla
	SDL_Rect rectanguloRenderizacion = { ancho, alto, this->anchoTextura, this->altoTextura };
	SDL_RenderCopy( renderizador, textura, NULL, &rectanguloRenderizacion );
}


void Textura::liberarTextura(){

	if(textura != NULL){

		SDL_DestroyTexture( this->textura );
		this->textura = NULL;
		this->anchoTextura = 0;
		this->altoTextura = 0;
	}
}

SDL_Texture* Textura::obtenerTextura(){

	return textura;
}

Textura::~Textura(){

	this->liberarTextura();
}


