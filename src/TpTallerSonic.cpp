//============================================================================
// Name        : TpTallerSonic.cpp
// Author      : Joha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


//#include </usr/include/SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
using namespace std;
#include <string>
#include "VistaSDL.h"

using namespace std;

int main() {

	VistaSDL *ventana = new VistaSDL();
	ventana->mostrarVentana();
	ventana->cerrar();

	return 0;
}
