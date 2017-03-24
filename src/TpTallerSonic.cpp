//============================================================================
// Name        : TpTallerSonic.cpp
// Author      : Joha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include </usr/include/SDL2/SDL.h>
#include <jansson.h>
#include "jventana.h"
#include "jconfiguracion.h"
#include "jescenario.h"
#include "capas.h"
#include "jentidades.h"
#include "jescenarioJuego.h"
#include <list>
#include "dimensiones.h"
#include "parseadorJson.h"

#include "jpruebas.h"

using namespace std;

int main() {

	json_t *json;



    parseadorJson* parseador = new parseadorJson();
	jescenarioJuego* jparseador = parseador->parsearArchivo("./configuracion/f.json");


	jpruebas* prueba = new jpruebas();
	prueba->prueba(jparseador);







}

