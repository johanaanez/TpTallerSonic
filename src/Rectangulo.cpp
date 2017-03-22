#include "Rectangulo.h"

Rectangulo::Rectangulo() : ancho(), alto()
{

}

Rectangulo::Rectangulo(int ancho, int alto, unsigned int id, std::string color, std::string rutaImagen, int x, int y, unsigned int indexZ)
: Entidad(id, color, rutaImagen, x, y, indexZ), ancho(ancho), alto(alto)
{
	this->rectanguloSDL.x = x; this->rectanguloSDL.y = y; this->rectanguloSDL.w = ancho; this->rectanguloSDL.h = alto;
}

Rectangulo::~Rectangulo() {
	// TODO Auto-generated destructor stub
}

void Rectangulo::dibujar(SDL_Renderer *renderer)
{
	if (tieneRutaImagen())
	{
		cargarImagen(renderer);
		repetirImagen(renderer);
	}
	else
	{
		this->setearColor(renderer);
		SDL_RenderFillRect(renderer, &rectanguloSDL); //SDL_RenderDrawRect lo crea sin relleno
	}
}

void Rectangulo::repetirImagen(SDL_Renderer *renderer)
{
	if (obtenerImagen() == NULL)
	{
		std::cout << "No se cargo la imagen" << std::endl;
		return;
	}

	int  anchoImagen, altoImagen;
	SDL_QueryTexture(obtenerImagen(), NULL, NULL, &anchoImagen, &altoImagen);

	if ((anchoImagen >= ancho) && (altoImagen >= alto))
	{
		SDL_Rect recorte = {0, 0, ancho, alto}; //Toma la esquina superior izquierda de la imagen
		SDL_RenderCopy(renderer, obtenerImagen(), &recorte, &rectanguloSDL);
		return;
	}

	if ((anchoImagen < ancho) || (altoImagen < alto))
	{
		//Rellenar con imagen hacia la derecha y hacia abajo
		int vecesARepetirEnX = 0, vecesARepetirEnY = 0;
		int origenX = 0, origenY = 0;

		vecesARepetirEnX = (ancho / anchoImagen); //division entera entre int

		if ((ancho % anchoImagen) > 0)
		{
			vecesARepetirEnX++;
		}

		vecesARepetirEnY = (alto / altoImagen); //division entera entre int

		if ((alto % altoImagen) > 0)
		{
			vecesARepetirEnY++;
		}


		int destinoY = obtenerY();

		for (int i = 0; i < vecesARepetirEnY; i++) //Hacia abajo
		{
			int destinoX = obtenerX();
			for (int j = 0; j < vecesARepetirEnX ; j++) //Hacia la derecha
			{
				SDL_Rect origenImagen = {origenX, origenY, anchoImagen, altoImagen};
				SDL_Rect destino = {destinoX, destinoY, anchoImagen, altoImagen};
				SDL_RenderCopy(renderer, obtenerImagen(), &origenImagen, &destino);

				destinoX = destinoX + anchoImagen;
			}
			destinoY = destinoY + altoImagen;
		}

	}

}

