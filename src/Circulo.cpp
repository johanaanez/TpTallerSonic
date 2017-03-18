#include "Circulo.h"

Circulo::Circulo()
{
	this->radio=0;
}

Circulo::Circulo(int radio, unsigned int id, std::string color, std::string rutaImagen, int x, int y, unsigned int indexZ) : Entidad(id, color, rutaImagen, x, y, indexZ)
{
	this->radio=radio;
}

Circulo::~Circulo() {
	// TODO Auto-generated destructor stub
}

void Circulo::dibujar(SDL_Renderer *renderer)
{
	setearColor(renderer);
	int diametro=radio*2;
	int difX, difY=0;

	//Para cada punto dentro del cuadrado que encierra al circulo
	for (int xPunto=0; xPunto<diametro; xPunto++)
	{
		for (int yPunto=0; yPunto<diametro; yPunto++)
		{
			difX=radio-xPunto;
			difY=radio-yPunto;
			if ((difX*difX + difY*difY) <= (radio*radio)) //Si el punto esta dentro del circulo
			{
				SDL_RenderDrawPoint(renderer, obtenerX()+difX, obtenerY()+difY);
			}
		}
	}


}
