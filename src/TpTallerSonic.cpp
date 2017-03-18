#include <iostream>
#include <SDL2/SDL.h>
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


	///////CREO RENDERER
	//Lo necesito para dibujar las formas solidas
	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED);


	///////////////////////////////DIBUJO FIGURAS CON COLOR SOLIDO/////////////////////////////
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	Rectangulo rectangulo = Rectangulo(100, 100, 1, "Amarillo", "", 100, 100, 1);
	rectangulo.dibujar(renderer);

	Rectangulo rectangulo2 = Rectangulo(100, 100, 1, "Verde", "", 0, 0, 1);
	rectangulo2.dibujar(renderer);

	Rectangulo rectangulo3 = Rectangulo(100, 100, 1, "Rojo", "", 200, 200, 1);
	rectangulo3.dibujar(renderer);

	Rectangulo rectangulo4 = Rectangulo(100, 100, 1, "Azul", "", 300, 300, 1);
	rectangulo4.dibujar(renderer);

	Rectangulo rectanguloFueraDeLimites = Rectangulo(1000, 30, 1, "Rojo", "", 0, 0, 1);
	rectanguloFueraDeLimites.dibujar(renderer);
	//TODO: Ver que pasa cuando se desplaza la ventana

	Circulo circulo = Circulo(50, 1, "Amarillo", "", 450, 450, 1);
	circulo.dibujar(renderer);


	//////////////////////////////////DIBUJO FIGURAS CON IMAGEN/////////////////////////////////
	Rectangulo rectanguloConImagen = Rectangulo(300, 300, 1, "Amarillo", "res/sonic.bmp", 450, 50, 1);
	rectanguloConImagen.dibujar(renderer);

	Circulo circuloConImagen = Circulo(50, 1, "Amarillo", "res/sonic.bmp", 550, 550, 1);
	circuloConImagen.dibujar(renderer);



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
		SDL_RenderPresent(renderer);
	}


	//////////////CERRAR SDL
	SDL_DestroyWindow(ventana);
	ventana = NULL;
	SDL_DestroyRenderer(renderer);
	renderer = NULL;
	SDL_Quit();

	return 0;
}
