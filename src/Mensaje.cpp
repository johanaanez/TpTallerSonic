#include "Mensaje.h"

Mensaje::Mensaje() {
	// TODO Auto-generated constructor stub

}

string Mensaje::getDescripcion() const
{
    return descripcion;
}

int Mensaje::getNivel() const
{
    return nivel;
}

void Mensaje::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}


void Mensaje::setNivel(int nivel)
{
    this->nivel = nivel;
}

time_t Mensaje::getFecha() const
{
    return fecha;
}

void Mensaje::setFecha(time_t fecha)
{
    this->fecha = fecha;
}

void Mensaje::imprimirMensaje(){

}

Mensaje::~Mensaje() {
	// TODO Auto-generated destructor stub
}
