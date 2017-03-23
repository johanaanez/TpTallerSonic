#include "Rectangulo.h"

Rectangulo::Rectangulo() : ancho(), alto()
{

}

Rectangulo::Rectangulo(int ancho, int alto, unsigned int id, std::string color, std::string rutaImagen, int x, int y, unsigned int indexZ)
: Entidad(id, color, rutaImagen, x, y, indexZ), ancho(ancho), alto(alto)
{
	this->rectanguloSDL.x = x;
	this->rectanguloSDL.y = y;
	this->rectanguloSDL.w = ancho;
	this->rectanguloSDL.h = alto;
}

Rectangulo::~Rectangulo() {
	// TODO Auto-generated destructor stub
}

void Rectangulo::dibujar(SDL_Renderer *renderer)
{
	if (tieneRutaImagen())
	{
		cargarImagen(renderer);
		mostrarImagen(renderer);
	}
	else
	{
		setearColor(renderer);
		SDL_RenderFillRect(renderer, &rectanguloSDL);
	}
}

void Rectangulo::mostrarImagen(SDL_Renderer *renderer)
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
		//Recorta la imagen
		SDL_Rect recorte = {0, 0, ancho, alto}; //Toma desde la esquina superior izquierda de la imagen
		SDL_RenderCopy(renderer, obtenerImagen(), &recorte, &rectanguloSDL);
		return;
	}
	else
	{
		setearColor(renderer);

		if (ancho > anchoImagen)
		{
			//Rellena a la derecha de la imagen
			SDL_Rect relleno = {obtenerX() + anchoImagen, obtenerY(), ancho - anchoImagen, alto};
			SDL_RenderFillRect(renderer, &relleno);
		}

		if (alto > altoImagen)
		{
			//Rellena abajo de la imagen
			SDL_Rect relleno = {obtenerX(), obtenerY() + altoImagen, ancho, alto - altoImagen};
			SDL_RenderFillRect(renderer, &relleno);
		}

		//Muestra la imagen
		if ((ancho > anchoImagen) && (alto > altoImagen))
		{
			//Muestra toda la imagen
			SDL_Rect recorte = {0, 0, anchoImagen, altoImagen};
			SDL_Rect destino = {obtenerX(), obtenerY(), anchoImagen, altoImagen};
			SDL_RenderCopy(renderer, obtenerImagen(), &recorte, &destino);
		}
		else if (ancho > anchoImagen)
		{
			//Muestra la parte superior de la imagen
			SDL_Rect recorte = {0, 0, anchoImagen, alto};
			SDL_Rect destino = {obtenerX(), obtenerY(), anchoImagen, alto};
			SDL_RenderCopy(renderer, obtenerImagen(), &recorte, &destino);
		}
		else if (alto > altoImagen)
		{
			//Muestra la parte izquierda de la imagen
			SDL_Rect recorte = {0, 0, ancho, altoImagen};
			SDL_Rect destino = {obtenerX(), obtenerY(), ancho, altoImagen};
			SDL_RenderCopy(renderer, obtenerImagen(), &recorte, &destino);
		}

		return;
	}
}

