#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Rectangulo.h"
#include "Circulo.h"

using namespace std;

int main(void) { /*******MAIN DE PRUEBA*******/

	////////////INICIAR SDL Y VENTANA
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "Error: " << SDL_GetError() << endl;
		return 1;
	}

	SDL_Window* ventana = NULL;
	ventana = SDL_CreateWindow("Ventana", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	if( ventana == NULL )
	{
		cout << "Error: " << SDL_GetError() << endl;
		return 1;
	}

	/////////INICIAR SDL_IMAGE
	int flag = IMG_INIT_PNG;
	if(!(IMG_Init(IMG_INIT_PNG) & flag))
	{
		cout << "Error: " << IMG_GetError() << endl;
		SDL_DestroyWindow(ventana);
		ventana = NULL;
		return 1;
	}


	///////CREO RENDERER
	//Lo necesito para dibujar
	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);


	///////////////////////////////DIBUJO FIGURAS CON COLOR SOLIDO/////////////////////////////
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);
/*
	Rectangulo rectangulo = Rectangulo(100, 100, 1, "amarillo", "", 100, 100, 1);
	rectangulo.dibujar(renderer);

	Rectangulo rectangulo2 = Rectangulo(100, 100, 1, "verde", "", 0, 0, 1);
	rectangulo2.dibujar(renderer);

	Rectangulo rectangulo3 = Rectangulo(100, 100, 1, "rojo", "", 200, 200, 1);
	rectangulo3.dibujar(renderer);

	Rectangulo rectangulo4 = Rectangulo(100, 100, 1, "azul", "", 300, 300, 1);
	rectangulo4.dibujar(renderer);

	Rectangulo rectanguloFueraDeLimites = Rectangulo(1000, 30, 1, "rojo", "", 0, 0, 1);
	rectanguloFueraDeLimites.dibujar(renderer);
	//TODO: Ver que pasa cuando se desplaza la ventana

	Circulo circulo = Circulo(50, 1, "amarillo", "", 450, 450, 1);
	circulo.dibujar(renderer);


	//////////////////////////////////DIBUJO FIGURAS CON IMAGEN/////////////////////////////////
	Rectangulo rectanguloConImagen = Rectangulo(300, 300, 1, "amarillo", "res/sonic.png", 450, 50, 1);
	rectanguloConImagen.dibujar(renderer);

	Circulo circuloConImagen = Circulo(50, 1, "amarillo", "res/sonic.png", 550, 550, 1);
	circuloConImagen.dibujar(renderer);
*/

	Rectangulo rectanguloGrande = Rectangulo(600, 100, 1, "color erroneo", "res/sonic logo transparente.png", 10, 10, 1);
	rectanguloGrande.dibujar(renderer);

	Rectangulo rectanguloGrande2 = Rectangulo(200, 300, 1, "color erroneo", "res/sonic logo transparente.png", 10, 250, 1);
	rectanguloGrande2.dibujar(renderer);

	Rectangulo rectanguloGrande3 = Rectangulo(550, 250, 1, "color erroneo", "res/sonic logo transparente.png", 220, 120, 1);
	rectanguloGrande3.dibujar(renderer);

	Circulo circuloConImagen2 = Circulo(150, 1, "amarillo", "res/sonic logo transparente.png", 600, 450, 1);
	circuloConImagen2.dibujar(renderer);




	//Actualizar la pantalla
	SDL_RenderPresent(renderer);

	////////////MAIN LOOP
	bool salir = false;
	while (!salir)
	{
		//Para salir al hacer clic en la x
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				salir = true;
				break;
			}
		}
		//Mientras no salgo actualizar la pantalla
		//SDL_RenderPresent(renderer);
	}


	//////////////CERRAR SDL
	SDL_DestroyWindow(ventana);
	ventana = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_Quit();

	return 0;
}
